/*
 * IntroductionExperiment.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "IntroductionExperiment".
 *
 * Model version              : 7.28
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Wed Apr 16 11:38:56 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "IntroductionExperiment.h"
#include "IntroductionExperiment_private.h"
#include "IntroductionExperiment_dt.h"

/* Block signals (default storage) */
B_IntroductionExperiment_T IntroductionExperiment_B;

/* Block states (default storage) */
DW_IntroductionExperiment_T IntroductionExperiment_DW;

/* Real-time model */
static RT_MODEL_IntroductionExperiment_T IntroductionExperiment_M_;
RT_MODEL_IntroductionExperiment_T *const IntroductionExperiment_M =
  &IntroductionExperiment_M_;

/* Forward declaration for local functions */
static void IntroductionExpe_emxInit_char_T(emxArray_char_T_IntroductionE_T
  **pEmxArray, int32_T numDimensions);
static void Introd_emxEnsureCapacity_char_T(emxArray_char_T_IntroductionE_T
  *emxArray, int32_T oldNumel);
static void IntroductionExpe_emxFree_char_T(emxArray_char_T_IntroductionE_T
  **pEmxArray);
static int8_T IntroductionExperiment_filedata(void);
static int8_T IntroductionExperiment_cfopen(const
  emxArray_char_T_IntroductionE_T *cfilename, const char_T *cpermission);
static int32_T IntroductionExperiment_cfclose(real_T fid);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void IntroductionExperiment_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(IntroductionExperiment_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (IntroductionExperiment_M->Timing.TaskCounters.TID[1] == 0) {
    IntroductionExperiment_M->Timing.RateInteraction.TID1_2 =
      (IntroductionExperiment_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    IntroductionExperiment_M->Timing.perTaskSampleHits[5] =
      IntroductionExperiment_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (IntroductionExperiment_M->Timing.TaskCounters.TID[2])++;
  if ((IntroductionExperiment_M->Timing.TaskCounters.TID[2]) > 7) {/* Sample time: [0.002s, 0.0s] */
    IntroductionExperiment_M->Timing.TaskCounters.TID[2] = 0;
  }
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void IntroductionExpe_emxInit_char_T(emxArray_char_T_IntroductionE_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_char_T_IntroductionE_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_IntroductionE_T *)malloc(sizeof
    (emxArray_char_T_IntroductionE_T));
  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void Introd_emxEnsureCapacity_char_T(emxArray_char_T_IntroductionE_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(char_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(char_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (char_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void IntroductionExpe_emxFree_char_T(emxArray_char_T_IntroductionE_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T_IntroductionE_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T_IntroductionE_T *)NULL;
  }
}

/* Function for MATLAB Function: '<S4>/SPERTE_measurement_function' */
static int8_T IntroductionExperiment_filedata(void)
{
  int32_T k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (IntroductionExperiment_DW.eml_openfiles[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<S4>/SPERTE_measurement_function' */
static int8_T IntroductionExperiment_cfopen(const
  emxArray_char_T_IntroductionE_T *cfilename, const char_T *cpermission)
{
  emxArray_char_T_IntroductionE_T *ccfilename;
  int32_T i;
  int32_T loop_ub;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = IntroductionExperiment_filedata();
  if (j >= 1) {
    IntroductionExpe_emxInit_char_T(&ccfilename, 2);
    i = ccfilename->size[0] * ccfilename->size[1];
    ccfilename->size[0] = 1;
    ccfilename->size[1] = cfilename->size[1] + 1;
    Introd_emxEnsureCapacity_char_T(ccfilename, i);
    loop_ub = cfilename->size[1];
    for (i = 0; i < loop_ub; i++) {
      ccfilename->data[i] = cfilename->data[i];
    }

    ccfilename->data[cfilename->size[1]] = '\x00';
    IntroductionExperiment_B.filestar_m = fopen(&ccfilename->data[0],
      cpermission);
    IntroductionExpe_emxFree_char_T(&ccfilename);
    if (IntroductionExperiment_B.filestar_m != NULL) {
      IntroductionExperiment_DW.eml_openfiles[j - 1] =
        IntroductionExperiment_B.filestar_m;
      IntroductionExperiment_DW.eml_autoflush[j - 1] = true;
      i = j + 2;
      if (j + 2 > 127) {
        i = 127;
      }

      fileid = (int8_T)i;
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<S4>/SPERTE_measurement_function' */
static int32_T IntroductionExperiment_cfclose(real_T fid)
{
  FILE* filestar;
  int32_T cst;
  int32_T st;
  int8_T b_fileid;
  int8_T fileid;
  st = -1;
  fileid = (int8_T)rt_roundd_snf(fid);
  if ((fileid < 0) || (fid != fileid)) {
    fileid = -1;
  }

  b_fileid = fileid;
  if (fileid < 0) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    filestar = IntroductionExperiment_DW.eml_openfiles[b_fileid - 3];
  } else if (b_fileid == 0) {
    filestar = stdin;
  } else if (b_fileid == 1) {
    filestar = stdout;
  } else if (b_fileid == 2) {
    filestar = stderr;
  } else {
    filestar = NULL;
  }

  if ((filestar != NULL) && (fileid >= 3)) {
    cst = fclose(filestar);
    if (cst == 0) {
      st = 0;
      IntroductionExperiment_DW.eml_openfiles[fileid - 3] = NULL;
      IntroductionExperiment_DW.eml_autoflush[fileid - 3] = true;
    }
  }

  return st;
}

/* Model step function for TID0 */
void IntroductionExperiment_step0(void) /* Sample time: [0.0s, 0.0s] */
{
  emxArray_char_T_IntroductionE_T *charStr;
  emxArray_char_T_IntroductionE_T *charStr_0;
  int32_T i;
  int8_T b_fileid;
  boolean_T autoflush;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (ec_Supervisor): '<S9>/S-Function' */

  /* Level2 S-Function Block: '<S9>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = IntroductionExperiment_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ec_Ebox): '<S8>/ec_Ebox' */

  /* Level2 S-Function Block: '<S8>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts = IntroductionExperiment_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Gain: '<S3>/count2rad'
   */
  IntroductionExperiment_B.Kfv = IntroductionExperiment_P.count2rad_Gain *
    IntroductionExperiment_B.ec_Ebox_o2[1] * IntroductionExperiment_P.Gain_Gain;

  /* Constant: '<S6>/Start setpoint' */
  IntroductionExperiment_B.Startsetpoint =
    IntroductionExperiment_P.Refpower_stat;

  /* S-Function (ref3b): '<S7>/S-Function' */

  /* Level2 S-Function Block: '<S7>/S-Function' (ref3b) */
  {
    SimStruct *rts = IntroductionExperiment_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* Quantizer: '<Root>/Quantizer1' */
  IntroductionExperiment_B.Sum4 = rt_roundd_snf
    (IntroductionExperiment_B.SFunction_c[2] /
     IntroductionExperiment_P.Quantizer1_Interval) *
    IntroductionExperiment_P.Quantizer1_Interval;

  /* ManualSwitch: '<Root>/Select encoder' incorporates:
   *  Gain: '<S3>/count2rad'
   */
  if (IntroductionExperiment_P.Selectencoder_CurrentSetting == 1) {
    IntroductionExperiment_B.Sum = IntroductionExperiment_P.count2rad_Gain *
      IntroductionExperiment_B.ec_Ebox_o2[0];
  } else {
    IntroductionExperiment_B.Sum = IntroductionExperiment_B.Kfv;
  }

  /* End of ManualSwitch: '<Root>/Select encoder' */

  /* Sum: '<Root>/Sum' */
  IntroductionExperiment_B.Sum = IntroductionExperiment_B.Sum4 -
    IntroductionExperiment_B.Sum;

  /* MATLAB Function: '<S4>/SPERTE_measurement_function' incorporates:
   *  Constant: '<S4>/SPERTE_measurement_samples'
   *  Constant: '<S4>/SPERTE_measurement_trigger_command'
   *  SignalConversion generated from: '<S10>/ SFunction '
   *  Sum: '<Root>/Sum5'
   */
  if ((((IntroductionExperiment_P.MeasurementBlock_triggertype == 1) &&
        (IntroductionExperiment_P.MeasurementBlock_trigger_comman == 1)) ||
       ((IntroductionExperiment_P.MeasurementBlock_triggertype == 2) &&
        (IntroductionExperiment_P.MeasurementBlock_trigger_comman == 1))) &&
      (IntroductionExperiment_DW.busy != 1)) {
    IntroductionExpe_emxInit_char_T(&charStr, 2);
    IntroductionExperiment_B.nbytes = (int32_T)snprintf(NULL, 0,
      "measurement_%d.bin", IntroductionExperiment_DW.NF) + 1;
    i = charStr->size[0] * charStr->size[1];
    charStr->size[0] = 1;
    charStr->size[1] = IntroductionExperiment_B.nbytes;
    Introd_emxEnsureCapacity_char_T(charStr, i);
    snprintf(&charStr->data[0], (size_t)IntroductionExperiment_B.nbytes,
             "measurement_%d.bin", IntroductionExperiment_DW.NF);
    if (1 > IntroductionExperiment_B.nbytes - 1) {
      IntroductionExperiment_B.nbytes = -1;
    } else {
      IntroductionExperiment_B.nbytes -= 2;
    }

    IntroductionExpe_emxInit_char_T(&charStr_0, 2);
    i = charStr_0->size[0] * charStr_0->size[1];
    charStr_0->size[0] = 1;
    charStr_0->size[1] = IntroductionExperiment_B.nbytes + 1;
    Introd_emxEnsureCapacity_char_T(charStr_0, i);
    for (i = 0; i <= IntroductionExperiment_B.nbytes; i++) {
      charStr_0->data[i] = charStr->data[i];
    }

    IntroductionExpe_emxFree_char_T(&charStr);
    b_fileid = IntroductionExperiment_cfopen(charStr_0, "wb");
    IntroductionExperiment_DW.fileID = b_fileid;
    i = IntroductionExperiment_DW.NF + 1;
    IntroductionExpe_emxFree_char_T(&charStr_0);
    if (IntroductionExperiment_DW.NF + 1 > 32767) {
      i = 32767;
    }

    IntroductionExperiment_DW.NF = (int16_T)i;
    IntroductionExperiment_DW.busy = 1U;
    IntroductionExperiment_DW.NS = 0U;
  }

  if (IntroductionExperiment_DW.busy == 1) {
    if (IntroductionExperiment_DW.NS <
        IntroductionExperiment_P.MeasurementBlock_N_samples) {
      b_fileid = (int8_T)rt_roundd_snf(IntroductionExperiment_DW.fileID);
      if ((b_fileid < 0) || (IntroductionExperiment_DW.fileID != b_fileid)) {
        b_fileid = -1;
      }

      if (b_fileid >= 3) {
        IntroductionExperiment_B.filestar =
          IntroductionExperiment_DW.eml_openfiles[b_fileid - 3];
        autoflush = IntroductionExperiment_DW.eml_autoflush[b_fileid - 3];
      } else if (b_fileid == 0) {
        IntroductionExperiment_B.filestar = stdin;
        autoflush = true;
      } else if (b_fileid == 1) {
        IntroductionExperiment_B.filestar = stdout;
        autoflush = true;
      } else if (b_fileid == 2) {
        IntroductionExperiment_B.filestar = stderr;
        autoflush = true;
      } else {
        IntroductionExperiment_B.filestar = NULL;
        autoflush = true;
      }

      if (!(IntroductionExperiment_DW.fileID != 0.0)) {
        IntroductionExperiment_B.filestar = NULL;
      }

      if (!(IntroductionExperiment_B.filestar == NULL)) {
        IntroductionExperiment_B.xout[0] = (real32_T)
          (IntroductionExperiment_B.Sum4 - IntroductionExperiment_B.Kfv);
        IntroductionExperiment_B.xout[1] = (real32_T)
          IntroductionExperiment_B.Sum;
        IntroductionExperiment_B.bytesOutSizet = fwrite
          (&IntroductionExperiment_B.xout[0], sizeof(real32_T), (size_t)2,
           IntroductionExperiment_B.filestar);
        if (((real_T)IntroductionExperiment_B.bytesOutSizet > 0.0) && autoflush)
        {
          fflush(IntroductionExperiment_B.filestar);
        }
      }

      IntroductionExperiment_B.qY = IntroductionExperiment_DW.NS + 1U;
      if (IntroductionExperiment_DW.NS + 1U < IntroductionExperiment_DW.NS) {
        IntroductionExperiment_B.qY = MAX_uint32_T;
      }

      IntroductionExperiment_DW.NS = IntroductionExperiment_B.qY;
    } else {
      IntroductionExperiment_cfclose(IntroductionExperiment_DW.fileID);
      IntroductionExperiment_DW.busy = 0U;
      IntroductionExperiment_DW.NS = 0U;
    }
  }

  /* End of MATLAB Function: '<S4>/SPERTE_measurement_function' */

  /* SignalConversion: '<S5>/Buffer' */
  IntroductionExperiment_B.Buffer[0] = IntroductionExperiment_B.Sum;
  IntroductionExperiment_B.Buffer[1] = 0.0;
  IntroductionExperiment_B.Buffer[2] = 0.0;

  /* RateTransition: '<S5>/Downsample' */
  if (IntroductionExperiment_M->Timing.RateInteraction.TID1_2) {
    IntroductionExperiment_DW.Downsample_Buffer[0] =
      IntroductionExperiment_B.Buffer[0];
    IntroductionExperiment_DW.Downsample_Buffer[1] =
      IntroductionExperiment_B.Buffer[1];
    IntroductionExperiment_DW.Downsample_Buffer[2] =
      IntroductionExperiment_B.Buffer[2];
  }

  /* End of RateTransition: '<S5>/Downsample' */

  /* Gain: '<S1>/Gain2' */
  IntroductionExperiment_B.Gain2 = IntroductionExperiment_P.Gain2_Gain *
    IntroductionExperiment_B.Sum;

  /* S-Function (dleadlag): '<S1>/Dctleadlag2' */

  /* Level2 S-Function Block: '<S1>/Dctleadlag2' (dleadlag) */
  {
    SimStruct *rts = IntroductionExperiment_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass1): '<S1>/Dct1lowpass3' */

  /* Level2 S-Function Block: '<S1>/Dct1lowpass3' (dlowpass1) */
  {
    SimStruct *rts = IntroductionExperiment_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dnotch): '<S1>/Dctnotch4' */

  /* Level2 S-Function Block: '<S1>/Dctnotch4' (dnotch) */
  {
    SimStruct *rts = IntroductionExperiment_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S3>/Constant1' */
  memcpy(&IntroductionExperiment_B.Constant1[0],
         &IntroductionExperiment_P.Constant1_Value[0], sizeof(real_T) << 3U);

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S3>/Constant'
   */
  IntroductionExperiment_B.Gain[0] = IntroductionExperiment_P.Gain_Gain_g *
    IntroductionExperiment_P.Constant_Value[0];
  IntroductionExperiment_B.Gain[1] = IntroductionExperiment_P.Gain_Gain_g *
    IntroductionExperiment_P.Constant_Value[1];

  /* Sum: '<Root>/Sum1' incorporates:
   *  RandomNumber: '<Root>/Noise'
   */
  IntroductionExperiment_B.Sum1 = IntroductionExperiment_B.Dctnotch4 +
    IntroductionExperiment_DW.NextOutput;

  /* Signum: '<S2>/Sign' */
  if (IntroductionExperiment_B.SFunction_c[1] < 0.0) {
    IntroductionExperiment_B.Sum = -1.0;
  } else if (IntroductionExperiment_B.SFunction_c[1] > 0.0) {
    IntroductionExperiment_B.Sum = 1.0;
  } else if (IntroductionExperiment_B.SFunction_c[1] == 0.0) {
    IntroductionExperiment_B.Sum = 0.0;
  } else {
    IntroductionExperiment_B.Sum = (rtNaN);
  }

  /* End of Signum: '<S2>/Sign' */

  /* Sum: '<Root>/Sum4' incorporates:
   *  Gain: '<S2>/Kfa'
   *  Gain: '<S2>/Kfc'
   *  Gain: '<S2>/Kfv'
   *  Sum: '<Root>/Sum2'
   *  Sum: '<Root>/Sum3'
   */
  IntroductionExperiment_B.Sum = ((IntroductionExperiment_P.Kfa_Gain *
    IntroductionExperiment_B.SFunction_c[0] + IntroductionExperiment_P.Kfv_Gain *
    IntroductionExperiment_B.SFunction_c[1]) + IntroductionExperiment_P.Kfc_Gain
    * IntroductionExperiment_B.Sum) + IntroductionExperiment_B.Sum1;

  /* Saturate: '<S3>/Saturation' */
  if (IntroductionExperiment_B.Sum >
      IntroductionExperiment_P.Saturation_UpperSat) {
    IntroductionExperiment_B.Sum = IntroductionExperiment_P.Saturation_UpperSat;
  } else if (IntroductionExperiment_B.Sum <
             IntroductionExperiment_P.Saturation_LowerSat) {
    IntroductionExperiment_B.Sum = IntroductionExperiment_P.Saturation_LowerSat;
  }

  /* Saturate: '<S8>/Saturation' */
  if (IntroductionExperiment_B.Sum >
      IntroductionExperiment_P.Saturation_UpperSat_d) {
    /* Saturate: '<S8>/Saturation' */
    IntroductionExperiment_B.Saturation[0] =
      IntroductionExperiment_P.Saturation_UpperSat_d;
  } else if (IntroductionExperiment_B.Sum <
             IntroductionExperiment_P.Saturation_LowerSat_e) {
    /* Saturate: '<S8>/Saturation' */
    IntroductionExperiment_B.Saturation[0] =
      IntroductionExperiment_P.Saturation_LowerSat_e;
  } else {
    /* Saturate: '<S8>/Saturation' */
    IntroductionExperiment_B.Saturation[0] = IntroductionExperiment_B.Sum;
  }

  /* Saturate: '<S3>/Saturation' incorporates:
   *  Constant: '<S3>/Constant2'
   */
  if (IntroductionExperiment_P.Constant2_Value >
      IntroductionExperiment_P.Saturation_UpperSat) {
    IntroductionExperiment_B.Sum = IntroductionExperiment_P.Saturation_UpperSat;
  } else if (IntroductionExperiment_P.Constant2_Value <
             IntroductionExperiment_P.Saturation_LowerSat) {
    IntroductionExperiment_B.Sum = IntroductionExperiment_P.Saturation_LowerSat;
  } else {
    IntroductionExperiment_B.Sum = IntroductionExperiment_P.Constant2_Value;
  }

  /* Saturate: '<S8>/Saturation' */
  if (IntroductionExperiment_B.Sum >
      IntroductionExperiment_P.Saturation_UpperSat_d) {
    /* Saturate: '<S8>/Saturation' */
    IntroductionExperiment_B.Saturation[1] =
      IntroductionExperiment_P.Saturation_UpperSat_d;
  } else if (IntroductionExperiment_B.Sum <
             IntroductionExperiment_P.Saturation_LowerSat_e) {
    /* Saturate: '<S8>/Saturation' */
    IntroductionExperiment_B.Saturation[1] =
      IntroductionExperiment_P.Saturation_LowerSat_e;
  } else {
    /* Saturate: '<S8>/Saturation' */
    IntroductionExperiment_B.Saturation[1] = IntroductionExperiment_B.Sum;
  }

  /* Update for RandomNumber: '<Root>/Noise' */
  IntroductionExperiment_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
    (&IntroductionExperiment_DW.RandSeed) *
    IntroductionExperiment_P.Noise_StdDev + IntroductionExperiment_P.Noise_Mean;

  /* External mode */
  rtExtModeUploadCheckTrigger(3);
  rtExtModeUpload(1, (real_T)IntroductionExperiment_M->Timing.t[0]);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(IntroductionExperiment_M)!=-1) &&
        !((rtmGetTFinal(IntroductionExperiment_M)-
           IntroductionExperiment_M->Timing.t[0]) >
          IntroductionExperiment_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(IntroductionExperiment_M, "Simulation finished");
    }

    if (rtmGetStopRequested(IntroductionExperiment_M)) {
      rtmSetErrorStatus(IntroductionExperiment_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++IntroductionExperiment_M->Timing.clockTick0)) {
    ++IntroductionExperiment_M->Timing.clockTickH0;
  }

  IntroductionExperiment_M->Timing.t[0] =
    IntroductionExperiment_M->Timing.clockTick0 *
    IntroductionExperiment_M->Timing.stepSize0 +
    IntroductionExperiment_M->Timing.clockTickH0 *
    IntroductionExperiment_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++IntroductionExperiment_M->Timing.clockTick1)) {
    ++IntroductionExperiment_M->Timing.clockTickH1;
  }

  IntroductionExperiment_M->Timing.t[1] =
    IntroductionExperiment_M->Timing.clockTick1 *
    IntroductionExperiment_M->Timing.stepSize1 +
    IntroductionExperiment_M->Timing.clockTickH1 *
    IntroductionExperiment_M->Timing.stepSize1 * 4294967296.0;
}

/* Model step function for TID2 */
void IntroductionExperiment_step2(void) /* Sample time: [0.002s, 0.0s] */
{
  /* RateTransition: '<S5>/Downsample' */
  IntroductionExperiment_B.Downsample[0] =
    IntroductionExperiment_DW.Downsample_Buffer[0];
  IntroductionExperiment_B.Downsample[1] =
    IntroductionExperiment_DW.Downsample_Buffer[1];
  IntroductionExperiment_B.Downsample[2] =
    IntroductionExperiment_DW.Downsample_Buffer[2];
  rtExtModeUpload(2, (real_T)(((IntroductionExperiment_M->Timing.clockTick2+
    IntroductionExperiment_M->Timing.clockTickH2* 4294967296.0)) * 0.002));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.002, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  IntroductionExperiment_M->Timing.clockTick2++;
  if (!IntroductionExperiment_M->Timing.clockTick2) {
    IntroductionExperiment_M->Timing.clockTickH2++;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void IntroductionExperiment_step(int_T tid)
{
  switch (tid) {
   case 0 :
    IntroductionExperiment_step0();
    break;

   case 2 :
    IntroductionExperiment_step2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void IntroductionExperiment_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)IntroductionExperiment_M, 0,
                sizeof(RT_MODEL_IntroductionExperiment_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&IntroductionExperiment_M->solverInfo,
                          &IntroductionExperiment_M->Timing.simTimeStep);
    rtsiSetTPtr(&IntroductionExperiment_M->solverInfo, &rtmGetTPtr
                (IntroductionExperiment_M));
    rtsiSetStepSizePtr(&IntroductionExperiment_M->solverInfo,
                       &IntroductionExperiment_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&IntroductionExperiment_M->solverInfo,
                          (&rtmGetErrorStatus(IntroductionExperiment_M)));
    rtsiSetRTModelPtr(&IntroductionExperiment_M->solverInfo,
                      IntroductionExperiment_M);
  }

  rtsiSetSimTimeStep(&IntroductionExperiment_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&IntroductionExperiment_M->solverInfo,"FixedStepDiscrete");
  IntroductionExperiment_M->solverInfoPtr =
    (&IntroductionExperiment_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = IntroductionExperiment_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "IntroductionExperiment_M points to
       static memory which is guaranteed to be non-NULL" */
    IntroductionExperiment_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    IntroductionExperiment_M->Timing.sampleTimes =
      (&IntroductionExperiment_M->Timing.sampleTimesArray[0]);
    IntroductionExperiment_M->Timing.offsetTimes =
      (&IntroductionExperiment_M->Timing.offsetTimesArray[0]);

    /* task periods */
    IntroductionExperiment_M->Timing.sampleTimes[0] = (0.0);
    IntroductionExperiment_M->Timing.sampleTimes[1] = (0.00025);
    IntroductionExperiment_M->Timing.sampleTimes[2] = (0.002);

    /* task offsets */
    IntroductionExperiment_M->Timing.offsetTimes[0] = (0.0);
    IntroductionExperiment_M->Timing.offsetTimes[1] = (0.0);
    IntroductionExperiment_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(IntroductionExperiment_M, &IntroductionExperiment_M->Timing.tArray
             [0]);

  {
    int_T *mdlSampleHits = IntroductionExperiment_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      IntroductionExperiment_M->Timing.perTaskSampleHitsArray;
    IntroductionExperiment_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits
      [0]);
    mdlSampleHits[0] = 1;
    IntroductionExperiment_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(IntroductionExperiment_M, -1);
  IntroductionExperiment_M->Timing.stepSize0 = 0.00025;
  IntroductionExperiment_M->Timing.stepSize1 = 0.00025;

  /* External mode info */
  IntroductionExperiment_M->Sizes.checksums[0] = (257292962U);
  IntroductionExperiment_M->Sizes.checksums[1] = (1079310480U);
  IntroductionExperiment_M->Sizes.checksums[2] = (1037825315U);
  IntroductionExperiment_M->Sizes.checksums[3] = (3349255053U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    IntroductionExperiment_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(IntroductionExperiment_M->extModeInfo,
      &IntroductionExperiment_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(IntroductionExperiment_M->extModeInfo,
                        IntroductionExperiment_M->Sizes.checksums);
    rteiSetTPtr(IntroductionExperiment_M->extModeInfo, rtmGetTPtr
                (IntroductionExperiment_M));
  }

  IntroductionExperiment_M->solverInfoPtr =
    (&IntroductionExperiment_M->solverInfo);
  IntroductionExperiment_M->Timing.stepSize = (0.00025);
  rtsiSetFixedStepSize(&IntroductionExperiment_M->solverInfo, 0.00025);
  rtsiSetSolverMode(&IntroductionExperiment_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  (void) memset(((void *) &IntroductionExperiment_B), 0,
                sizeof(B_IntroductionExperiment_T));

  /* states (dwork) */
  (void) memset((void *)&IntroductionExperiment_DW, 0,
                sizeof(DW_IntroductionExperiment_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    IntroductionExperiment_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &IntroductionExperiment_M->NonInlinedSFcns.sfcnInfo;
    IntroductionExperiment_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(IntroductionExperiment_M)));
    IntroductionExperiment_M->Sizes.numSampTimes = (3);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &IntroductionExperiment_M->Sizes.numSampTimes);
    IntroductionExperiment_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (IntroductionExperiment_M)[0]);
    IntroductionExperiment_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (IntroductionExperiment_M)[1]);
    IntroductionExperiment_M->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr
      (IntroductionExperiment_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,
                   IntroductionExperiment_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(IntroductionExperiment_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(IntroductionExperiment_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (IntroductionExperiment_M));
    rtssSetStepSizePtr(sfcnInfo, &IntroductionExperiment_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (IntroductionExperiment_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &IntroductionExperiment_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &IntroductionExperiment_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &IntroductionExperiment_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &IntroductionExperiment_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &IntroductionExperiment_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &IntroductionExperiment_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &IntroductionExperiment_M->solverInfoPtr);
  }

  IntroductionExperiment_M->Sizes.numSFcns = (6);

  /* register each child */
  {
    (void) memset((void *)
                  &IntroductionExperiment_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  6*sizeof(SimStruct));
    IntroductionExperiment_M->childSfunctions =
      (&IntroductionExperiment_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 6; i++) {
        IntroductionExperiment_M->childSfunctions[i] =
          (&IntroductionExperiment_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: IntroductionExperiment/<S9>/S-Function (ec_Supervisor) */
    {
      SimStruct *rts = IntroductionExperiment_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &IntroductionExperiment_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &IntroductionExperiment_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, IntroductionExperiment_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IntroductionExperiment_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &IntroductionExperiment_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "IntroductionExperiment/Fourth Order Motion System/Ethercat Supervisor/S-Function");
      ssSetRTModel(rts,IntroductionExperiment_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IntroductionExperiment_P.SFunction_P1_Size_k);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       IntroductionExperiment_P.SFunction_P2_Size);
      }

      /* registration */
      ec_Supervisor(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: IntroductionExperiment/<S8>/ec_Ebox (ec_Ebox) */
    {
      SimStruct *rts = IntroductionExperiment_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &IntroductionExperiment_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &IntroductionExperiment_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, IntroductionExperiment_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IntroductionExperiment_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &IntroductionExperiment_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = IntroductionExperiment_B.Saturation;
          sfcnUPtrs[1] = &IntroductionExperiment_B.Saturation[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &IntroductionExperiment_M->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = IntroductionExperiment_B.Gain;
          sfcnUPtrs[1] = &IntroductionExperiment_B.Gain[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &IntroductionExperiment_M->NonInlinedSFcns.Sfcn1.UPtrs2;

          {
            int_T i1;
            const real_T *u2 = IntroductionExperiment_B.Constant1;
            for (i1=0; i1 < 8; i1++) {
              sfcnUPtrs[i1] = &u2[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 8);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 3);
        _ssSetPortInfo2ForOutputUnits(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            IntroductionExperiment_B.ec_Ebox_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 2);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            IntroductionExperiment_B.ec_Ebox_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 8);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            IntroductionExperiment_B.ec_Ebox_o3));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_Ebox");
      ssSetPath(rts,
                "IntroductionExperiment/Fourth Order Motion System/Ethercat E-box/ec_Ebox");
      ssSetRTModel(rts,IntroductionExperiment_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IntroductionExperiment_P.ec_Ebox_P1_Size);
      }

      /* registration */
      ec_Ebox(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
    }

    /* Level2 S-Function Block: IntroductionExperiment/<S7>/S-Function (ref3b) */
    {
      SimStruct *rts = IntroductionExperiment_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &IntroductionExperiment_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &IntroductionExperiment_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, IntroductionExperiment_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IntroductionExperiment_M->NonInlinedSFcns.statesInfo2
                         [2]);
        ssSetPeriodicStatesInfo(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &IntroductionExperiment_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &IntroductionExperiment_B.Startsetpoint;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            IntroductionExperiment_B.SFunction_c));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "IntroductionExperiment/Subsystem/S-Function");
      ssSetRTModel(rts,IntroductionExperiment_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IntroductionExperiment_P.SFunction_P1_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &IntroductionExperiment_DW.SFunction_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 50);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &IntroductionExperiment_DW.SFunction_RWORK[0]);
      }

      /* registration */
      ref3b(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: IntroductionExperiment/<S1>/Dctleadlag2 (dleadlag) */
    {
      SimStruct *rts = IntroductionExperiment_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &IntroductionExperiment_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &IntroductionExperiment_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, IntroductionExperiment_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IntroductionExperiment_M->NonInlinedSFcns.statesInfo2
                         [3]);
        ssSetPeriodicStatesInfo(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &IntroductionExperiment_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &IntroductionExperiment_B.Gain2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn3.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &IntroductionExperiment_B.Dctleadlag2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctleadlag2");
      ssSetPath(rts,
                "IntroductionExperiment/Controller (motor side)/Dctleadlag2");
      ssSetRTModel(rts,IntroductionExperiment_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IntroductionExperiment_P.Dctleadlag2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       IntroductionExperiment_P.Dctleadlag2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       IntroductionExperiment_P.Dctleadlag2_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &IntroductionExperiment_DW.Dctleadlag2_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &IntroductionExperiment_DW.Dctleadlag2_RWORK[0]);
      }

      /* registration */
      dleadlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: IntroductionExperiment/<S1>/Dct1lowpass3 (dlowpass1) */
    {
      SimStruct *rts = IntroductionExperiment_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &IntroductionExperiment_M->NonInlinedSFcns.blkInfo2[4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &IntroductionExperiment_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, IntroductionExperiment_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IntroductionExperiment_M->NonInlinedSFcns.statesInfo2
                         [4]);
        ssSetPeriodicStatesInfo(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn4.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn4.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &IntroductionExperiment_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &IntroductionExperiment_B.Dctleadlag2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn4.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &IntroductionExperiment_B.Dct1lowpass3));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct1lowpass3");
      ssSetPath(rts,
                "IntroductionExperiment/Controller (motor side)/Dct1lowpass3");
      ssSetRTModel(rts,IntroductionExperiment_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IntroductionExperiment_P.Dct1lowpass3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       IntroductionExperiment_P.Dct1lowpass3_P2_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &IntroductionExperiment_DW.Dct1lowpass3_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &IntroductionExperiment_DW.Dct1lowpass3_RWORK[0]);
      }

      /* registration */
      dlowpass1(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: IntroductionExperiment/<S1>/Dctnotch4 (dnotch) */
    {
      SimStruct *rts = IntroductionExperiment_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap =
        IntroductionExperiment_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &IntroductionExperiment_M->NonInlinedSFcns.blkInfo2[5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &IntroductionExperiment_M->NonInlinedSFcns.inputOutputPortInfo2[5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, IntroductionExperiment_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &IntroductionExperiment_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IntroductionExperiment_M->NonInlinedSFcns.statesInfo2
                         [5]);
        ssSetPeriodicStatesInfo(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn5.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn5.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &IntroductionExperiment_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &IntroductionExperiment_B.Dct1lowpass3;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn5.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &IntroductionExperiment_B.Dctnotch4));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch4");
      ssSetPath(rts, "IntroductionExperiment/Controller (motor side)/Dctnotch4");
      ssSetRTModel(rts,IntroductionExperiment_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IntroductionExperiment_P.Dctnotch4_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       IntroductionExperiment_P.Dctnotch4_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       IntroductionExperiment_P.Dctnotch4_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       IntroductionExperiment_P.Dctnotch4_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       IntroductionExperiment_P.Dctnotch4_P5_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &IntroductionExperiment_DW.Dctnotch4_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &IntroductionExperiment_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &IntroductionExperiment_DW.Dctnotch4_RWORK[0]);
      }

      /* registration */
      dnotch(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Start for S-Function (ec_Supervisor): '<S9>/S-Function' */
  /* Level2 S-Function Block: '<S9>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = IntroductionExperiment_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S6>/Start setpoint' */
  IntroductionExperiment_B.Startsetpoint =
    IntroductionExperiment_P.Refpower_stat;

  /* Start for S-Function (dleadlag): '<S1>/Dctleadlag2' */
  /* Level2 S-Function Block: '<S1>/Dctleadlag2' (dleadlag) */
  {
    SimStruct *rts = IntroductionExperiment_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass1): '<S1>/Dct1lowpass3' */
  /* Level2 S-Function Block: '<S1>/Dct1lowpass3' (dlowpass1) */
  {
    SimStruct *rts = IntroductionExperiment_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S1>/Dctnotch4' */
  /* Level2 S-Function Block: '<S1>/Dctnotch4' (dnotch) */
  {
    SimStruct *rts = IntroductionExperiment_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S3>/Constant1' */
  memcpy(&IntroductionExperiment_B.Constant1[0],
         &IntroductionExperiment_P.Constant1_Value[0], sizeof(real_T) << 3U);

  {
    FILE* a;
    real_T tmp;
    int32_T i;
    int32_T t;
    uint32_T tseed;

    /* InitializeConditions for S-Function (ref3b): '<S7>/S-Function' */
    /* Level2 S-Function Block: '<S7>/S-Function' (ref3b) */
    {
      SimStruct *rts = IntroductionExperiment_M->childSfunctions[2];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* InitializeConditions for RandomNumber: '<Root>/Noise' */
    tmp = floor(IntroductionExperiment_P.Noise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    IntroductionExperiment_DW.RandSeed = ((((tseed - ((uint32_T)i << 16U)) + t) <<
      16U) + t) + i;
    if (IntroductionExperiment_DW.RandSeed < 1U) {
      IntroductionExperiment_DW.RandSeed = 1144108930U;
    } else if (IntroductionExperiment_DW.RandSeed > 2147483646U) {
      IntroductionExperiment_DW.RandSeed = 2147483646U;
    }

    IntroductionExperiment_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&IntroductionExperiment_DW.RandSeed) *
      IntroductionExperiment_P.Noise_StdDev +
      IntroductionExperiment_P.Noise_Mean;

    /* End of InitializeConditions for RandomNumber: '<Root>/Noise' */

    /* SystemInitialize for MATLAB Function: '<S4>/SPERTE_measurement_function' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      IntroductionExperiment_DW.eml_autoflush[i] = false;
      IntroductionExperiment_DW.eml_openfiles[i] = a;
    }

    IntroductionExperiment_DW.NF = 0;
    IntroductionExperiment_DW.NS = 0U;
    IntroductionExperiment_DW.fileID = 0.0;
    IntroductionExperiment_DW.busy = 0U;

    /* End of SystemInitialize for MATLAB Function: '<S4>/SPERTE_measurement_function' */
  }
}

/* Model terminate function */
void IntroductionExperiment_terminate(void)
{
  /* Terminate for S-Function (ec_Supervisor): '<S9>/S-Function' */
  /* Level2 S-Function Block: '<S9>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = IntroductionExperiment_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ec_Ebox): '<S8>/ec_Ebox' */
  /* Level2 S-Function Block: '<S8>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts = IntroductionExperiment_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ref3b): '<S7>/S-Function' */
  /* Level2 S-Function Block: '<S7>/S-Function' (ref3b) */
  {
    SimStruct *rts = IntroductionExperiment_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dleadlag): '<S1>/Dctleadlag2' */
  /* Level2 S-Function Block: '<S1>/Dctleadlag2' (dleadlag) */
  {
    SimStruct *rts = IntroductionExperiment_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass1): '<S1>/Dct1lowpass3' */
  /* Level2 S-Function Block: '<S1>/Dct1lowpass3' (dlowpass1) */
  {
    SimStruct *rts = IntroductionExperiment_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S1>/Dctnotch4' */
  /* Level2 S-Function Block: '<S1>/Dctnotch4' (dnotch) */
  {
    SimStruct *rts = IntroductionExperiment_M->childSfunctions[5];
    sfcnTerminate(rts);
  }
}
