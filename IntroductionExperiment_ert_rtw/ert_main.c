#include <stdio.h>
#include <stdlib.h>
#include "IntroductionExperiment.h"
#include "IntroductionExperiment_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"
#include "linuxinitialize.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
sem_t subrateTaskSem[1];
int taskId[1];
pthread_t schedulerThread;
pthread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
pthread_t subRateThread[1];
pthread_mutex_t rateTaskFcnRunningMutex[2];
int subratePriority[1];
int testForRateOverrun(int rateID);
void *subrateTask(void *arg)
{
  int tid = *((int *) arg);
  int subRateId;
  subRateId = tid + 2;
  while (runModel) {
    sem_wait(&subrateTaskSem[tid]);
    if (terminatingmodel)
      break;

#ifdef MW_RTOS_DEBUG

    printf(" -subrate task %d semaphore received\n", subRateId);

#endif

    pthread_mutex_lock(&rateTaskFcnRunningMutex[tid+1]);
    IntroductionExperiment_step(subRateId);

    /* Get model outputs here */
    pthread_mutex_unlock(&rateTaskFcnRunningMutex[tid+1]);
  }

  pthread_exit((void *)0);
  return NULL;
}

void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(IntroductionExperiment_M) == (NULL)) &&
    !rtmGetStopRequested(IntroductionExperiment_M);
  while (runModel) {
    sem_wait(&baserateTaskSem);
    pthread_mutex_lock(&rateTaskFcnRunningMutex[0]);

#ifdef MW_RTOS_DEBUG

    printf("*base rate task semaphore received\n");
    fflush(stdout);

#endif

    if (rtmStepTask(IntroductionExperiment_M, 2)
        ) {
      testForRateOverrun(1);
      sem_post(&subrateTaskSem[0]);
    }

    IntroductionExperiment_step(0);

    /* Get model outputs here */
    pthread_mutex_unlock(&rateTaskFcnRunningMutex[0]);
    stopRequested = !((rtmGetErrorStatus(IntroductionExperiment_M) == (NULL)) &&
                      !rtmGetStopRequested(IntroductionExperiment_M));
  }

  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(IntroductionExperiment_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    int i;

    /* Signal all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(sem_post(&subrateTaskSem[i]), 0, "sem_post");
      CHECK_STATUS(sem_destroy(&subrateTaskSem[i]), 0, "sem_destroy");
    }

    /* Wait for all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(pthread_join(subRateThread[i], &threadJoinStatus), 0,
                   "pthread_join");
    }

    runModel = 0;
  }

  MW_killPyserver();
  mwRaspiTerminate();

  /* Terminate model */
  IntroductionExperiment_terminate();
  sem_post(&stopSem);
  return NULL;
}

int testForRateOverrun(int rateID)
{
  if (pthread_mutex_trylock(&rateTaskFcnRunningMutex[rateID]) == 0) {
    pthread_mutex_unlock(&rateTaskFcnRunningMutex[rateID]);
    return 0;                          /* Not overruning this rate */
  } else {
    reportOverrun(rateID);
    return 1;                          /* Overruning this rate */
  }
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  subratePriority[0] = 39;
  mwRaspiInit();
  MW_launchPyserver();
  rtmSetErrorStatus(IntroductionExperiment_M, 0);

  /* Initialize model */
  IntroductionExperiment_initialize();

  /* Call RTOS Initialization function */
  myRTOSInit(0.00025, 1);

  /* Wait for stop semaphore */
  sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(sem_destroy(&timerTaskSem[i]), 0, "sem_destroy");
    }
  }

#endif

  {
    int idxMutex;
    for (idxMutex=0; idxMutex<2; idxMutex++)
      pthread_mutex_destroy(&rateTaskFcnRunningMutex[idxMutex]);
  }

  return 0;
}
