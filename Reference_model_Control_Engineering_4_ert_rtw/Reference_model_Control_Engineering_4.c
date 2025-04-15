/*
 * Reference_model_Control_Engineering_4.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Reference_model_Control_Engineering_4".
 *
 * Model version              : 7.37
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Apr 15 11:22:03 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Reference_model_Control_Engineering_4.h"
#include "Reference_model_Control_Engineering_4_private.h"
#include "Reference_model_Control_Engineering_4_dt.h"

/* Block signals (default storage) */
B_Reference_model_Control_Engineering_4_T
  Reference_model_Control_Engineering_4_B;

/* Block states (default storage) */
DW_Reference_model_Control_Engineering_4_T
  Reference_model_Control_Engineering_4_DW;

/* Real-time model */
static RT_MODEL_Reference_model_Control_Engineering_4_T
  Reference_model_Control_Engineering_4_M_;
RT_MODEL_Reference_model_Control_Engineering_4_T *const
  Reference_model_Control_Engineering_4_M =
  &Reference_model_Control_Engineering_4_M_;

/* Forward declaration for local functions */
static void Reference_model__emxInit_char_T(emxArray_char_T_Reference_mod_T
  **pEmxArray, int32_T numDimensions);
static void Refere_emxEnsureCapacity_char_T(emxArray_char_T_Reference_mod_T
  *emxArray, int32_T oldNumel);
static void Reference_model__emxFree_char_T(emxArray_char_T_Reference_mod_T
  **pEmxArray);
static int8_T Reference_model_Contro_filedata(void);
static int8_T Reference_model_Control__cfopen(const
  emxArray_char_T_Reference_mod_T *cfilename, const char_T *cpermission);
static int32_T Reference_model_Control_cfclose(real_T fid);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Reference_model_Control_Engineering_4_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask
                   (Reference_model_Control_Engineering_4_M, 2));
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
  if (Reference_model_Control_Engineering_4_M->Timing.TaskCounters.TID[1] == 0)
  {
    Reference_model_Control_Engineering_4_M->Timing.RateInteraction.TID1_2 =
      (Reference_model_Control_Engineering_4_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    Reference_model_Control_Engineering_4_M->Timing.perTaskSampleHits[5] =
      Reference_model_Control_Engineering_4_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Reference_model_Control_Engineering_4_M->Timing.TaskCounters.TID[2])++;
  if ((Reference_model_Control_Engineering_4_M->Timing.TaskCounters.TID[2]) > 7)
  {                                    /* Sample time: [0.002s, 0.0s] */
    Reference_model_Control_Engineering_4_M->Timing.TaskCounters.TID[2] = 0;
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

static void Reference_model__emxInit_char_T(emxArray_char_T_Reference_mod_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_char_T_Reference_mod_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_Reference_mod_T *)malloc(sizeof
    (emxArray_char_T_Reference_mod_T));
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

static void Refere_emxEnsureCapacity_char_T(emxArray_char_T_Reference_mod_T
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

static void Reference_model__emxFree_char_T(emxArray_char_T_Reference_mod_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T_Reference_mod_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T_Reference_mod_T *)NULL;
  }
}

/* Function for MATLAB Function: '<S3>/SPERTE_measurement_function' */
static int8_T Reference_model_Contro_filedata(void)
{
  int32_T k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Reference_model_Control_Engineering_4_DW.eml_openfiles[(int8_T)k - 1] ==
        NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<S3>/SPERTE_measurement_function' */
static int8_T Reference_model_Control__cfopen(const
  emxArray_char_T_Reference_mod_T *cfilename, const char_T *cpermission)
{
  emxArray_char_T_Reference_mod_T *ccfilename;
  int32_T i;
  int32_T loop_ub;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = Reference_model_Contro_filedata();
  if (j >= 1) {
    Reference_model__emxInit_char_T(&ccfilename, 2);
    i = ccfilename->size[0] * ccfilename->size[1];
    ccfilename->size[0] = 1;
    ccfilename->size[1] = cfilename->size[1] + 1;
    Refere_emxEnsureCapacity_char_T(ccfilename, i);
    loop_ub = cfilename->size[1];
    for (i = 0; i < loop_ub; i++) {
      ccfilename->data[i] = cfilename->data[i];
    }

    ccfilename->data[cfilename->size[1]] = '\x00';
    Reference_model_Control_Engineering_4_B.filestar_m = fopen(&ccfilename->
      data[0], cpermission);
    Reference_model__emxFree_char_T(&ccfilename);
    if (Reference_model_Control_Engineering_4_B.filestar_m != NULL) {
      Reference_model_Control_Engineering_4_DW.eml_openfiles[j - 1] =
        Reference_model_Control_Engineering_4_B.filestar_m;
      Reference_model_Control_Engineering_4_DW.eml_autoflush[j - 1] = true;
      i = j + 2;
      if (j + 2 > 127) {
        i = 127;
      }

      fileid = (int8_T)i;
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<S3>/SPERTE_measurement_function' */
static int32_T Reference_model_Control_cfclose(real_T fid)
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
    filestar = Reference_model_Control_Engineering_4_DW.eml_openfiles[b_fileid -
      3];
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
      Reference_model_Control_Engineering_4_DW.eml_openfiles[fileid - 3] = NULL;
      Reference_model_Control_Engineering_4_DW.eml_autoflush[fileid - 3] = true;
    }
  }

  return st;
}

/* Model step function for TID0 */
void Reference_model_Control_Engineering_4_step0(void) /* Sample time: [0.0s, 0.0s] */
{
  emxArray_char_T_Reference_mod_T *charStr;
  emxArray_char_T_Reference_mod_T *charStr_0;
  int32_T tmp;
  uint32_T qY;
  int8_T b_fileid;
  boolean_T autoflush;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Constant: '<S5>/Start setpoint' */
  Reference_model_Control_Engineering_4_B.Startsetpoint =
    Reference_model_Control_Engineering_4_P.Refpower_stat;

  /* S-Function (ref3b): '<S6>/S-Function' */

  /* Level2 S-Function Block: '<S6>/S-Function' (ref3b) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Quantizer: '<Root>/Quantizer1' */
  Reference_model_Control_Engineering_4_B.Quantizer1 = rt_roundd_snf
    (Reference_model_Control_Engineering_4_B.SFunction[2] /
     Reference_model_Control_Engineering_4_P.Quantizer1_Interval) *
    Reference_model_Control_Engineering_4_P.Quantizer1_Interval;

  /* S-Function (ec_Supervisor): '<S14>/S-Function' */

  /* Level2 S-Function Block: '<S14>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ec_Ebox): '<S13>/ec_Ebox' */

  /* Level2 S-Function Block: '<S13>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* ManualSwitch: '<Root>/Select encoder' incorporates:
   *  Gain: '<S2>/count2rad'
   */
  if (Reference_model_Control_Engineering_4_P.Selectencoder_CurrentSetting == 1)
  {
    Reference_model_Control_Engineering_4_B.u0 = 0.0;
  } else {
    Reference_model_Control_Engineering_4_B.u0 =
      Reference_model_Control_Engineering_4_P.count2rad_Gain *
      Reference_model_Control_Engineering_4_B.ec_Ebox_o2[1];
  }

  /* End of ManualSwitch: '<Root>/Select encoder' */

  /* Sum: '<Root>/Sum' */
  Reference_model_Control_Engineering_4_B.Sum =
    Reference_model_Control_Engineering_4_B.Quantizer1 -
    Reference_model_Control_Engineering_4_B.u0;

  /* MATLAB Function: '<S3>/SPERTE_measurement_function' incorporates:
   *  Constant: '<S3>/SPERTE_measurement_samples'
   *  Constant: '<S3>/SPERTE_measurement_trigger_command'
   *  SignalConversion generated from: '<S15>/ SFunction '
   */
  if ((((Reference_model_Control_Engineering_4_P.MeasurementBlock_triggertype ==
         1) &&
        (Reference_model_Control_Engineering_4_P.MeasurementBlock_trigger_comman
         == 1)) ||
       ((Reference_model_Control_Engineering_4_P.MeasurementBlock_triggertype ==
         2) &&
        (Reference_model_Control_Engineering_4_P.MeasurementBlock_trigger_comman
         == 1))) && (Reference_model_Control_Engineering_4_DW.busy != 1)) {
    Reference_model__emxInit_char_T(&charStr, 2);
    Reference_model_Control_Engineering_4_B.nbytes = (int32_T)snprintf(NULL, 0,
      "measurement_%d.bin", Reference_model_Control_Engineering_4_DW.NF) + 1;
    tmp = charStr->size[0] * charStr->size[1];
    charStr->size[0] = 1;
    charStr->size[1] = Reference_model_Control_Engineering_4_B.nbytes;
    Refere_emxEnsureCapacity_char_T(charStr, tmp);
    snprintf(&charStr->data[0], (size_t)
             Reference_model_Control_Engineering_4_B.nbytes,
             "measurement_%d.bin", Reference_model_Control_Engineering_4_DW.NF);
    if (1 > Reference_model_Control_Engineering_4_B.nbytes - 1) {
      Reference_model_Control_Engineering_4_B.loop_ub = -1;
    } else {
      Reference_model_Control_Engineering_4_B.loop_ub =
        Reference_model_Control_Engineering_4_B.nbytes - 2;
    }

    Reference_model__emxInit_char_T(&charStr_0, 2);
    tmp = charStr_0->size[0] * charStr_0->size[1];
    charStr_0->size[0] = 1;
    charStr_0->size[1] = Reference_model_Control_Engineering_4_B.loop_ub + 1;
    Refere_emxEnsureCapacity_char_T(charStr_0, tmp);
    for (Reference_model_Control_Engineering_4_B.nbytes = 0;
         Reference_model_Control_Engineering_4_B.nbytes <=
         Reference_model_Control_Engineering_4_B.loop_ub;
         Reference_model_Control_Engineering_4_B.nbytes++) {
      charStr_0->data[Reference_model_Control_Engineering_4_B.nbytes] =
        charStr->data[Reference_model_Control_Engineering_4_B.nbytes];
    }

    Reference_model__emxFree_char_T(&charStr);
    b_fileid = Reference_model_Control__cfopen(charStr_0, "wb");
    Reference_model_Control_Engineering_4_DW.fileID = b_fileid;
    Reference_model_Control_Engineering_4_B.nbytes =
      Reference_model_Control_Engineering_4_DW.NF + 1;
    Reference_model__emxFree_char_T(&charStr_0);
    if (Reference_model_Control_Engineering_4_DW.NF + 1 > 32767) {
      Reference_model_Control_Engineering_4_B.nbytes = 32767;
    }

    Reference_model_Control_Engineering_4_DW.NF = (int16_T)
      Reference_model_Control_Engineering_4_B.nbytes;
    Reference_model_Control_Engineering_4_DW.busy = 1U;
    Reference_model_Control_Engineering_4_DW.NS = 0U;
  }

  if (Reference_model_Control_Engineering_4_DW.busy == 1) {
    if (Reference_model_Control_Engineering_4_DW.NS <
        Reference_model_Control_Engineering_4_P.MeasurementBlock_N_samples) {
      b_fileid = (int8_T)rt_roundd_snf
        (Reference_model_Control_Engineering_4_DW.fileID);
      if ((b_fileid < 0) || (Reference_model_Control_Engineering_4_DW.fileID !=
                             b_fileid)) {
        b_fileid = -1;
      }

      if (b_fileid >= 3) {
        Reference_model_Control_Engineering_4_B.filestar =
          Reference_model_Control_Engineering_4_DW.eml_openfiles[b_fileid - 3];
        autoflush =
          Reference_model_Control_Engineering_4_DW.eml_autoflush[b_fileid - 3];
      } else if (b_fileid == 0) {
        Reference_model_Control_Engineering_4_B.filestar = stdin;
        autoflush = true;
      } else if (b_fileid == 1) {
        Reference_model_Control_Engineering_4_B.filestar = stdout;
        autoflush = true;
      } else if (b_fileid == 2) {
        Reference_model_Control_Engineering_4_B.filestar = stderr;
        autoflush = true;
      } else {
        Reference_model_Control_Engineering_4_B.filestar = NULL;
        autoflush = true;
      }

      if (!(Reference_model_Control_Engineering_4_DW.fileID != 0.0)) {
        Reference_model_Control_Engineering_4_B.filestar = NULL;
      }

      if (!(Reference_model_Control_Engineering_4_B.filestar == NULL)) {
        Reference_model_Control_Engineering_4_B.xout[0] = (real32_T)
          Reference_model_Control_Engineering_4_B.Quantizer1;
        Reference_model_Control_Engineering_4_B.xout[1] = (real32_T)
          Reference_model_Control_Engineering_4_B.Sum;
        Reference_model_Control_Engineering_4_B.bytesOutSizet = fwrite
          (&Reference_model_Control_Engineering_4_B.xout[0], sizeof(real32_T),
           (size_t)2, Reference_model_Control_Engineering_4_B.filestar);
        if (((real_T)Reference_model_Control_Engineering_4_B.bytesOutSizet > 0.0)
            && autoflush) {
          fflush(Reference_model_Control_Engineering_4_B.filestar);
        }
      }

      qY = Reference_model_Control_Engineering_4_DW.NS + 1U;
      if (Reference_model_Control_Engineering_4_DW.NS + 1U <
          Reference_model_Control_Engineering_4_DW.NS) {
        qY = MAX_uint32_T;
      }

      Reference_model_Control_Engineering_4_DW.NS = qY;
    } else {
      Reference_model_Control_cfclose
        (Reference_model_Control_Engineering_4_DW.fileID);
      Reference_model_Control_Engineering_4_DW.busy = 0U;
      Reference_model_Control_Engineering_4_DW.NS = 0U;
    }
  }

  /* End of MATLAB Function: '<S3>/SPERTE_measurement_function' */

  /* SignalConversion: '<S4>/Buffer' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  Reference_model_Control_Engineering_4_B.Buffer[0] =
    Reference_model_Control_Engineering_4_B.Sum;
  Reference_model_Control_Engineering_4_B.Buffer[1] =
    Reference_model_Control_Engineering_4_P.Gain1_Gain *
    Reference_model_Control_Engineering_4_B.SFunction[2];
  Reference_model_Control_Engineering_4_B.Buffer[2] = 0.0;

  /* RateTransition: '<S4>/Downsample' */
  if (Reference_model_Control_Engineering_4_M->Timing.RateInteraction.TID1_2) {
    Reference_model_Control_Engineering_4_DW.Downsample_Buffer[0] =
      Reference_model_Control_Engineering_4_B.Buffer[0];
    Reference_model_Control_Engineering_4_DW.Downsample_Buffer[1] =
      Reference_model_Control_Engineering_4_B.Buffer[1];
    Reference_model_Control_Engineering_4_DW.Downsample_Buffer[2] =
      Reference_model_Control_Engineering_4_B.Buffer[2];
  }

  /* End of RateTransition: '<S4>/Downsample' */

  /* SignalConversion generated from: '<Root>/To Workspace' */
  Reference_model_Control_Engineering_4_B.TmpSignalConversionAtToWorkspac[0] =
    Reference_model_Control_Engineering_4_B.Quantizer1;
  Reference_model_Control_Engineering_4_B.TmpSignalConversionAtToWorkspac[1] =
    Reference_model_Control_Engineering_4_B.Sum;

  /* Constant: '<S2>/Constant1' */
  memcpy(&Reference_model_Control_Engineering_4_B.Constant1[0],
         &Reference_model_Control_Engineering_4_P.Constant1_Value[0], sizeof
         (real_T) << 3U);

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S2>/Constant'
   */
  Reference_model_Control_Engineering_4_B.Gain[0] =
    Reference_model_Control_Engineering_4_P.Gain_Gain *
    Reference_model_Control_Engineering_4_P.Constant_Value[0];
  Reference_model_Control_Engineering_4_B.Gain[1] =
    Reference_model_Control_Engineering_4_P.Gain_Gain *
    Reference_model_Control_Engineering_4_P.Constant_Value[1];

  /* Gain: '<S11>/Gain5' */
  Reference_model_Control_Engineering_4_B.Gain5 =
    Reference_model_Control_Engineering_4_P.Gain5_Gain *
    Reference_model_Control_Engineering_4_B.Sum;

  /* S-Function (dnotch): '<S11>/Dctnotch8' */

  /* Level2 S-Function Block: '<S11>/Dctnotch8' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dleadlag): '<S11>/Dctleadlag4' */

  /* Level2 S-Function Block: '<S11>/Dctleadlag4' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dnotch): '<S11>/Dctnotch9' */

  /* Level2 S-Function Block: '<S11>/Dctnotch9' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ddoubleint): '<S11>/Dctdoubleintegrator4' */

  /* Level2 S-Function Block: '<S11>/Dctdoubleintegrator4' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass2): '<S11>/Dct2lowpass4' */

  /* Level2 S-Function Block: '<S11>/Dct2lowpass4' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[7];
    sfcnOutputs(rts,0);
  }

  /* RandomNumber: '<Root>/Noise' */
  Reference_model_Control_Engineering_4_B.Noise =
    Reference_model_Control_Engineering_4_DW.NextOutput;

  /* Signum: '<S1>/Sign' */
  if (Reference_model_Control_Engineering_4_B.SFunction[1] < 0.0) {
    Reference_model_Control_Engineering_4_B.u0 = -1.0;
  } else if (Reference_model_Control_Engineering_4_B.SFunction[1] > 0.0) {
    Reference_model_Control_Engineering_4_B.u0 = 1.0;
  } else if (Reference_model_Control_Engineering_4_B.SFunction[1] == 0.0) {
    Reference_model_Control_Engineering_4_B.u0 = 0.0;
  } else {
    Reference_model_Control_Engineering_4_B.u0 = (rtNaN);
  }

  /* End of Signum: '<S1>/Sign' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<S1>/Ka'
   *  Gain: '<S1>/Kfc'
   *  Gain: '<S1>/Kv'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S1>/Sum1'
   */
  Reference_model_Control_Engineering_4_B.u0 =
    (((Reference_model_Control_Engineering_4_P.Ka_Gain *
       Reference_model_Control_Engineering_4_B.SFunction[0] +
       Reference_model_Control_Engineering_4_P.Kv_Gain *
       Reference_model_Control_Engineering_4_B.SFunction[1]) +
      Reference_model_Control_Engineering_4_P.Kfc_Gain *
      Reference_model_Control_Engineering_4_B.u0) +
     Reference_model_Control_Engineering_4_B.Dct2lowpass4) +
    Reference_model_Control_Engineering_4_B.Noise;

  /* Saturate: '<S2>/Saturation' */
  if (Reference_model_Control_Engineering_4_B.u0 >
      Reference_model_Control_Engineering_4_P.Saturation_UpperSat) {
    Reference_model_Control_Engineering_4_B.u0 =
      Reference_model_Control_Engineering_4_P.Saturation_UpperSat;
  } else if (Reference_model_Control_Engineering_4_B.u0 <
             Reference_model_Control_Engineering_4_P.Saturation_LowerSat) {
    Reference_model_Control_Engineering_4_B.u0 =
      Reference_model_Control_Engineering_4_P.Saturation_LowerSat;
  }

  /* Saturate: '<S13>/Saturation' */
  if (Reference_model_Control_Engineering_4_B.u0 >
      Reference_model_Control_Engineering_4_P.Saturation_UpperSat_d) {
    /* Saturate: '<S13>/Saturation' */
    Reference_model_Control_Engineering_4_B.Saturation[0] =
      Reference_model_Control_Engineering_4_P.Saturation_UpperSat_d;
  } else if (Reference_model_Control_Engineering_4_B.u0 <
             Reference_model_Control_Engineering_4_P.Saturation_LowerSat_e) {
    /* Saturate: '<S13>/Saturation' */
    Reference_model_Control_Engineering_4_B.Saturation[0] =
      Reference_model_Control_Engineering_4_P.Saturation_LowerSat_e;
  } else {
    /* Saturate: '<S13>/Saturation' */
    Reference_model_Control_Engineering_4_B.Saturation[0] =
      Reference_model_Control_Engineering_4_B.u0;
  }

  /* Saturate: '<S2>/Saturation' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  if (Reference_model_Control_Engineering_4_P.Constant2_Value >
      Reference_model_Control_Engineering_4_P.Saturation_UpperSat) {
    Reference_model_Control_Engineering_4_B.u0 =
      Reference_model_Control_Engineering_4_P.Saturation_UpperSat;
  } else if (Reference_model_Control_Engineering_4_P.Constant2_Value <
             Reference_model_Control_Engineering_4_P.Saturation_LowerSat) {
    Reference_model_Control_Engineering_4_B.u0 =
      Reference_model_Control_Engineering_4_P.Saturation_LowerSat;
  } else {
    Reference_model_Control_Engineering_4_B.u0 =
      Reference_model_Control_Engineering_4_P.Constant2_Value;
  }

  /* Saturate: '<S13>/Saturation' */
  if (Reference_model_Control_Engineering_4_B.u0 >
      Reference_model_Control_Engineering_4_P.Saturation_UpperSat_d) {
    /* Saturate: '<S13>/Saturation' */
    Reference_model_Control_Engineering_4_B.Saturation[1] =
      Reference_model_Control_Engineering_4_P.Saturation_UpperSat_d;
  } else if (Reference_model_Control_Engineering_4_B.u0 <
             Reference_model_Control_Engineering_4_P.Saturation_LowerSat_e) {
    /* Saturate: '<S13>/Saturation' */
    Reference_model_Control_Engineering_4_B.Saturation[1] =
      Reference_model_Control_Engineering_4_P.Saturation_LowerSat_e;
  } else {
    /* Saturate: '<S13>/Saturation' */
    Reference_model_Control_Engineering_4_B.Saturation[1] =
      Reference_model_Control_Engineering_4_B.u0;
  }

  /* Gain: '<S7>/Gain2' */
  Reference_model_Control_Engineering_4_B.Gain2 =
    Reference_model_Control_Engineering_4_P.Gain2_Gain * 0.0;

  /* S-Function (dnotch): '<S7>/Dctnotch' */

  /* Level2 S-Function Block: '<S7>/Dctnotch' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[8];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dleadlag): '<S7>/Dctleadlag' */

  /* Level2 S-Function Block: '<S7>/Dctleadlag' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[9];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dnotch): '<S7>/Dctnotch2' */

  /* Level2 S-Function Block: '<S7>/Dctnotch2' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[10];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ddoubleint): '<S7>/Dctdoubleintegrator6' */

  /* Level2 S-Function Block: '<S7>/Dctdoubleintegrator6' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[11];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass2): '<S7>/Dct2lowpass' */

  /* Level2 S-Function Block: '<S7>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[12];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S8>/Gain2' */
  Reference_model_Control_Engineering_4_B.Gain2_d =
    Reference_model_Control_Engineering_4_P.Gain2_Gain_f * 0.0;

  /* S-Function (dnotch): '<S8>/Dctnotch' */

  /* Level2 S-Function Block: '<S8>/Dctnotch' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[13];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dleadlag): '<S8>/Dctleadlag' */

  /* Level2 S-Function Block: '<S8>/Dctleadlag' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[14];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dnotch): '<S8>/Dctnotch2' */

  /* Level2 S-Function Block: '<S8>/Dctnotch2' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[15];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ddoubleint): '<S8>/Dctdoubleintegrator6' */

  /* Level2 S-Function Block: '<S8>/Dctdoubleintegrator6' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[16];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass2): '<S8>/Dct2lowpass' */

  /* Level2 S-Function Block: '<S8>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[17];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S9>/Gain2' */
  Reference_model_Control_Engineering_4_B.Gain2_k =
    Reference_model_Control_Engineering_4_P.Gain2_Gain_a * 0.0;

  /* S-Function (dnotch): '<S9>/Dctnotch' */

  /* Level2 S-Function Block: '<S9>/Dctnotch' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[18];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dleadlag): '<S9>/Dctleadlag' */

  /* Level2 S-Function Block: '<S9>/Dctleadlag' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[19];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dnotch): '<S9>/Dctnotch2' */

  /* Level2 S-Function Block: '<S9>/Dctnotch2' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[20];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ddoubleint): '<S9>/Dctdoubleintegrator6' */

  /* Level2 S-Function Block: '<S9>/Dctdoubleintegrator6' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[21];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass2): '<S9>/Dct2lowpass' */

  /* Level2 S-Function Block: '<S9>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[22];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S10>/Gain2' */
  Reference_model_Control_Engineering_4_B.Gain2_m =
    Reference_model_Control_Engineering_4_P.Gain2_Gain_d * 0.0;

  /* S-Function (dnotch): '<S10>/Dctnotch' */

  /* Level2 S-Function Block: '<S10>/Dctnotch' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[23];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dleadlag): '<S10>/Dctleadlag' */

  /* Level2 S-Function Block: '<S10>/Dctleadlag' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[24];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dnotch): '<S10>/Dctnotch2' */

  /* Level2 S-Function Block: '<S10>/Dctnotch2' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[25];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ddoubleint): '<S10>/Dctdoubleintegrator6' */

  /* Level2 S-Function Block: '<S10>/Dctdoubleintegrator6' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[26];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass2): '<S10>/Dct2lowpass' */

  /* Level2 S-Function Block: '<S10>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[27];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S12>/Gain2' */
  Reference_model_Control_Engineering_4_B.Gain2_kd =
    Reference_model_Control_Engineering_4_P.Gain2_Gain_b * 0.0;

  /* S-Function (dnotch): '<S12>/Dctnotch' */

  /* Level2 S-Function Block: '<S12>/Dctnotch' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[28];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dleadlag): '<S12>/Dctleadlag' */

  /* Level2 S-Function Block: '<S12>/Dctleadlag' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[29];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dnotch): '<S12>/Dctnotch2' */

  /* Level2 S-Function Block: '<S12>/Dctnotch2' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[30];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ddoubleint): '<S12>/Dctdoubleintegrator6' */

  /* Level2 S-Function Block: '<S12>/Dctdoubleintegrator6' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[31];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass2): '<S12>/Dct2lowpass' */

  /* Level2 S-Function Block: '<S12>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[32];
    sfcnOutputs(rts,0);
  }

  /* Update for RandomNumber: '<Root>/Noise' */
  Reference_model_Control_Engineering_4_DW.NextOutput =
    rt_nrand_Upu32_Yd_f_pw_snf
    (&Reference_model_Control_Engineering_4_DW.RandSeed) *
    Reference_model_Control_Engineering_4_P.Noise_StdDev +
    Reference_model_Control_Engineering_4_P.Noise_Mean;

  /* External mode */
  rtExtModeUploadCheckTrigger(3);
  rtExtModeUpload(1, (real_T)Reference_model_Control_Engineering_4_M->Timing.t[0]);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Reference_model_Control_Engineering_4_M)!=-1) &&
        !((rtmGetTFinal(Reference_model_Control_Engineering_4_M)-
           Reference_model_Control_Engineering_4_M->Timing.t[0]) >
          Reference_model_Control_Engineering_4_M->Timing.t[0] * (DBL_EPSILON)))
    {
      rtmSetErrorStatus(Reference_model_Control_Engineering_4_M,
                        "Simulation finished");
    }

    if (rtmGetStopRequested(Reference_model_Control_Engineering_4_M)) {
      rtmSetErrorStatus(Reference_model_Control_Engineering_4_M,
                        "Simulation finished");
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
  if (!(++Reference_model_Control_Engineering_4_M->Timing.clockTick0)) {
    ++Reference_model_Control_Engineering_4_M->Timing.clockTickH0;
  }

  Reference_model_Control_Engineering_4_M->Timing.t[0] =
    Reference_model_Control_Engineering_4_M->Timing.clockTick0 *
    Reference_model_Control_Engineering_4_M->Timing.stepSize0 +
    Reference_model_Control_Engineering_4_M->Timing.clockTickH0 *
    Reference_model_Control_Engineering_4_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Reference_model_Control_Engineering_4_M->Timing.clockTick1)) {
    ++Reference_model_Control_Engineering_4_M->Timing.clockTickH1;
  }

  Reference_model_Control_Engineering_4_M->Timing.t[1] =
    Reference_model_Control_Engineering_4_M->Timing.clockTick1 *
    Reference_model_Control_Engineering_4_M->Timing.stepSize1 +
    Reference_model_Control_Engineering_4_M->Timing.clockTickH1 *
    Reference_model_Control_Engineering_4_M->Timing.stepSize1 * 4294967296.0;
}

/* Model step function for TID2 */
void Reference_model_Control_Engineering_4_step2(void) /* Sample time: [0.002s, 0.0s] */
{
  /* RateTransition: '<S4>/Downsample' */
  Reference_model_Control_Engineering_4_B.Downsample[0] =
    Reference_model_Control_Engineering_4_DW.Downsample_Buffer[0];
  Reference_model_Control_Engineering_4_B.Downsample[1] =
    Reference_model_Control_Engineering_4_DW.Downsample_Buffer[1];
  Reference_model_Control_Engineering_4_B.Downsample[2] =
    Reference_model_Control_Engineering_4_DW.Downsample_Buffer[2];
  rtExtModeUpload(2, (real_T)
                  (((Reference_model_Control_Engineering_4_M->Timing.clockTick2+
                     Reference_model_Control_Engineering_4_M->Timing.clockTickH2*
                     4294967296.0)) * 0.002));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.002, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  Reference_model_Control_Engineering_4_M->Timing.clockTick2++;
  if (!Reference_model_Control_Engineering_4_M->Timing.clockTick2) {
    Reference_model_Control_Engineering_4_M->Timing.clockTickH2++;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Reference_model_Control_Engineering_4_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Reference_model_Control_Engineering_4_step0();
    break;

   case 2 :
    Reference_model_Control_Engineering_4_step2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Reference_model_Control_Engineering_4_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Reference_model_Control_Engineering_4_M, 0,
                sizeof(RT_MODEL_Reference_model_Control_Engineering_4_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Reference_model_Control_Engineering_4_M->solverInfo,
                          &Reference_model_Control_Engineering_4_M->Timing.simTimeStep);
    rtsiSetTPtr(&Reference_model_Control_Engineering_4_M->solverInfo,
                &rtmGetTPtr(Reference_model_Control_Engineering_4_M));
    rtsiSetStepSizePtr(&Reference_model_Control_Engineering_4_M->solverInfo,
                       &Reference_model_Control_Engineering_4_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Reference_model_Control_Engineering_4_M->solverInfo,
                          (&rtmGetErrorStatus
      (Reference_model_Control_Engineering_4_M)));
    rtsiSetRTModelPtr(&Reference_model_Control_Engineering_4_M->solverInfo,
                      Reference_model_Control_Engineering_4_M);
  }

  rtsiSetSimTimeStep(&Reference_model_Control_Engineering_4_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&Reference_model_Control_Engineering_4_M->solverInfo,
                    "FixedStepDiscrete");
  Reference_model_Control_Engineering_4_M->solverInfoPtr =
    (&Reference_model_Control_Engineering_4_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      Reference_model_Control_Engineering_4_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Reference_model_Control_Engineering_4_M points to
       static memory which is guaranteed to be non-NULL" */
    Reference_model_Control_Engineering_4_M->Timing.sampleTimeTaskIDPtr =
      (&mdlTsMap[0]);
    Reference_model_Control_Engineering_4_M->Timing.sampleTimes =
      (&Reference_model_Control_Engineering_4_M->Timing.sampleTimesArray[0]);
    Reference_model_Control_Engineering_4_M->Timing.offsetTimes =
      (&Reference_model_Control_Engineering_4_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Reference_model_Control_Engineering_4_M->Timing.sampleTimes[0] = (0.0);
    Reference_model_Control_Engineering_4_M->Timing.sampleTimes[1] = (0.00025);
    Reference_model_Control_Engineering_4_M->Timing.sampleTimes[2] = (0.002);

    /* task offsets */
    Reference_model_Control_Engineering_4_M->Timing.offsetTimes[0] = (0.0);
    Reference_model_Control_Engineering_4_M->Timing.offsetTimes[1] = (0.0);
    Reference_model_Control_Engineering_4_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Reference_model_Control_Engineering_4_M,
             &Reference_model_Control_Engineering_4_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      Reference_model_Control_Engineering_4_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      Reference_model_Control_Engineering_4_M->Timing.perTaskSampleHitsArray;
    Reference_model_Control_Engineering_4_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Reference_model_Control_Engineering_4_M->Timing.sampleHits =
      (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Reference_model_Control_Engineering_4_M, -1);
  Reference_model_Control_Engineering_4_M->Timing.stepSize0 = 0.00025;
  Reference_model_Control_Engineering_4_M->Timing.stepSize1 = 0.00025;

  /* External mode info */
  Reference_model_Control_Engineering_4_M->Sizes.checksums[0] = (3874783671U);
  Reference_model_Control_Engineering_4_M->Sizes.checksums[1] = (1827489172U);
  Reference_model_Control_Engineering_4_M->Sizes.checksums[2] = (3509571209U);
  Reference_model_Control_Engineering_4_M->Sizes.checksums[3] = (89873337U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Reference_model_Control_Engineering_4_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr
      (Reference_model_Control_Engineering_4_M->extModeInfo,
       &Reference_model_Control_Engineering_4_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Reference_model_Control_Engineering_4_M->extModeInfo,
                        Reference_model_Control_Engineering_4_M->Sizes.checksums);
    rteiSetTPtr(Reference_model_Control_Engineering_4_M->extModeInfo, rtmGetTPtr
                (Reference_model_Control_Engineering_4_M));
  }

  Reference_model_Control_Engineering_4_M->solverInfoPtr =
    (&Reference_model_Control_Engineering_4_M->solverInfo);
  Reference_model_Control_Engineering_4_M->Timing.stepSize = (0.00025);
  rtsiSetFixedStepSize(&Reference_model_Control_Engineering_4_M->solverInfo,
                       0.00025);
  rtsiSetSolverMode(&Reference_model_Control_Engineering_4_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  (void) memset(((void *) &Reference_model_Control_Engineering_4_B), 0,
                sizeof(B_Reference_model_Control_Engineering_4_T));

  /* states (dwork) */
  (void) memset((void *)&Reference_model_Control_Engineering_4_DW, 0,
                sizeof(DW_Reference_model_Control_Engineering_4_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Reference_model_Control_Engineering_4_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo =
      &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.sfcnInfo;
    Reference_model_Control_Engineering_4_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (Reference_model_Control_Engineering_4_M)));
    Reference_model_Control_Engineering_4_M->Sizes.numSampTimes = (3);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &Reference_model_Control_Engineering_4_M->Sizes.numSampTimes);
    Reference_model_Control_Engineering_4_M->NonInlinedSFcns.taskTimePtrs[0] =
      &(rtmGetTPtr(Reference_model_Control_Engineering_4_M)[0]);
    Reference_model_Control_Engineering_4_M->NonInlinedSFcns.taskTimePtrs[1] =
      &(rtmGetTPtr(Reference_model_Control_Engineering_4_M)[1]);
    Reference_model_Control_Engineering_4_M->NonInlinedSFcns.taskTimePtrs[2] =
      &(rtmGetTPtr(Reference_model_Control_Engineering_4_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,
                   Reference_model_Control_Engineering_4_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart
                     (Reference_model_Control_Engineering_4_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal
                     (Reference_model_Control_Engineering_4_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (Reference_model_Control_Engineering_4_M));
    rtssSetStepSizePtr(sfcnInfo,
                       &Reference_model_Control_Engineering_4_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (Reference_model_Control_Engineering_4_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Reference_model_Control_Engineering_4_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Reference_model_Control_Engineering_4_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &Reference_model_Control_Engineering_4_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &Reference_model_Control_Engineering_4_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Reference_model_Control_Engineering_4_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo,
                      &Reference_model_Control_Engineering_4_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo,
                         &Reference_model_Control_Engineering_4_M->solverInfoPtr);
  }

  Reference_model_Control_Engineering_4_M->Sizes.numSFcns = (33);

  /* register each child */
  {
    (void) memset((void *)
                  &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  33*sizeof(SimStruct));
    Reference_model_Control_Engineering_4_M->childSfunctions =
      (&Reference_model_Control_Engineering_4_M->NonInlinedSFcns.childSFunctionPtrs
       [0]);

    {
      int_T i;
      for (i = 0; i < 33; i++) {
        Reference_model_Control_Engineering_4_M->childSfunctions[i] =
          (&Reference_model_Control_Engineering_4_M->NonInlinedSFcns.childSFunctions
           [i]);
      }
    }

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S6>/S-Function (ref3b) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [0];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn0.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn0.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Startsetpoint;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn0.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Reference_model_Control_Engineering_4_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/Subsystem/S-Function");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.SFunction_P1_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.SFunction_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 50);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.SFunction_RWORK[0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S14>/S-Function (ec_Supervisor) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [1];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn1.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn1.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.SFunction_b));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/Fourth Order Motion System/Ethercat Supervisor/S-Function");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.SFunction_P1_Size_k);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.SFunction_P2_Size);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S13>/ec_Ebox (ec_Ebox) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [2];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [2]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn2.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn2.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = Reference_model_Control_Engineering_4_B.Saturation;
          sfcnUPtrs[1] = &Reference_model_Control_Engineering_4_B.Saturation[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn2.UPtrs1;
          sfcnUPtrs[0] = Reference_model_Control_Engineering_4_B.Gain;
          sfcnUPtrs[1] = &Reference_model_Control_Engineering_4_B.Gain[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn2.UPtrs2;

          {
            int_T i1;
            const real_T *u2 = Reference_model_Control_Engineering_4_B.Constant1;
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
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn2.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 3);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn2.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Reference_model_Control_Engineering_4_B.ec_Ebox_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 2);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            Reference_model_Control_Engineering_4_B.ec_Ebox_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 8);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            Reference_model_Control_Engineering_4_B.ec_Ebox_o3));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_Ebox");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/Fourth Order Motion System/Ethercat E-box/ec_Ebox");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.ec_Ebox_P1_Size);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S11>/Dctnotch8 (dnotch) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [3];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [3]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn3.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn3.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Gain5;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn3.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn3.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctnotch8));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch8");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-2 High gain - similar 3 Hz notch + 60 Notch wide (second order)_ 53.68 dB gain1/Dctnotch8");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch8_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch8_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch8_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch8_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch8_P5_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctnotch8_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctnotch8_RWORK[0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S11>/Dctleadlag4 (dleadlag) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [4];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [4]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn4.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn4.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn4.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctnotch8;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn4.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn4.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctleadlag4));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctleadlag4");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-2 High gain - similar 3 Hz notch + 60 Notch wide (second order)_ 53.68 dB gain1/Dctleadlag4");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag4_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag4_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag4_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctleadlag4_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctleadlag4_RWORK[0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S11>/Dctnotch9 (dnotch) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [5];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [5]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn5.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn5.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn5.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctleadlag4;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn5.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn5.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctnotch9));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch9");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-2 High gain - similar 3 Hz notch + 60 Notch wide (second order)_ 53.68 dB gain1/Dctnotch9");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch9_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch9_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch9_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch9_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch9_P5_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctnotch9_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctnotch9_RWORK[0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S11>/Dctdoubleintegrator4 (ddoubleint) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [6];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [6]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [6]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [6]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn6.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn6.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn6.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctnotch9;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn6.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn6.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn6.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctdoubleintegrator4));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctdoubleintegrator4");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-2 High gain - similar 3 Hz notch + 60 Notch wide (second order)_ 53.68 dB gain1/Dctdoubleintegrator4");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator4_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator4_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator4_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator4_RWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator4_RWORK
                   [0]);
      }

      /* registration */
      ddoubleint(rts);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S11>/Dct2lowpass4 (dlowpass2) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [7];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [7]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [7]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [7]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn7.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn7.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn7.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] =
            &Reference_model_Control_Engineering_4_B.Dctdoubleintegrator4;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn7.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn7.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn7.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dct2lowpass4));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass4");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-2 High gain - similar 3 Hz notch + 60 Notch wide (second order)_ 53.68 dB gain1/Dct2lowpass4");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass4_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass4_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass4_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dct2lowpass4_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dct2lowpass4_RWORK
                   [0]);
      }

      /* registration */
      dlowpass2(rts);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S7>/Dctnotch (dnotch) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [8];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [8]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [8]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [8]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [8]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn8.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn8.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn8.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Gain2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn8.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn8.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn8.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctnotch));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T-II High gain - similar 3 Hz notch + 60 Notch_Lowpass 140 (High)_ 51.04 dB gain/Dctnotch");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P5_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctnotch_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn8.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn8.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctnotch_RWORK[0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S7>/Dctleadlag (dleadlag) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [9];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [9]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [9]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [9]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [9]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [9]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [9]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn9.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn9.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn9.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn9.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctnotch;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn9.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn9.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn9.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctleadlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctleadlag");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T-II High gain - similar 3 Hz notch + 60 Notch_Lowpass 140 (High)_ 51.04 dB gain/Dctleadlag");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctleadlag_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn9.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn9.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctleadlag_RWORK[0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S7>/Dctnotch2 (dnotch) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [10];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [10]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [10]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [10]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [10]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [10]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [10]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [10]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn10.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn10.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn10.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn10.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctleadlag;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn10.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn10.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn10.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctnotch2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch2");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T-II High gain - similar 3 Hz notch + 60 Notch_Lowpass 140 (High)_ 51.04 dB gain/Dctnotch2");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P5_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctnotch2_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn10.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn10.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctnotch2_RWORK[0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S7>/Dctdoubleintegrator6 (ddoubleint) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [11];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [11]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [11]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [11]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [11]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [11]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [11]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [11]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn11.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn11.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn11.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn11.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctnotch2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn11.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn11.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn11.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctdoubleintegrator6));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctdoubleintegrator6");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T-II High gain - similar 3 Hz notch + 60 Notch_Lowpass 140 (High)_ 51.04 dB gain/Dctdoubleintegrator6");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator6_RWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn11.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn11.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator6_RWORK
                   [0]);
      }

      /* registration */
      ddoubleint(rts);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S7>/Dct2lowpass (dlowpass2) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [12];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [12]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [12]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [12]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [12]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [12]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [12]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [12]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn12.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn12.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn12.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn12.UPtrs0;
          sfcnUPtrs[0] =
            &Reference_model_Control_Engineering_4_B.Dctdoubleintegrator6;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn12.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn12.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn12.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dct2lowpass));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T-II High gain - similar 3 Hz notch + 60 Notch_Lowpass 140 (High)_ 51.04 dB gain/Dct2lowpass");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dct2lowpass_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn12.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn12.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dct2lowpass_RWORK[0]);
      }

      /* registration */
      dlowpass2(rts);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S8>/Dctnotch (dnotch) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [13];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn13.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn13.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn13.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [13]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [13]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [13]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [13]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [13]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [13]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [13]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn13.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn13.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn13.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn13.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Gain2_d;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn13.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn13.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn13.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctnotch_c));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10 Gain_Notch_60(Low second order)+3_LeadLag_Integrator_Lowpass_50 Hz1/Dctnotch");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn13.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P1_Size_f);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P2_Size_k);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P3_Size_e);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P4_Size_o);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P5_Size_e);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctnotch_RWORK_e[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn13.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn13.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctnotch_RWORK_e[0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S8>/Dctleadlag (dleadlag) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [14];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn14.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn14.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn14.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [14]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [14]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [14]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [14]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [14]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [14]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [14]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn14.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn14.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn14.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn14.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctnotch_c;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn14.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn14.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn14.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctleadlag_g));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctleadlag");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10 Gain_Notch_60(Low second order)+3_LeadLag_Integrator_Lowpass_50 Hz1/Dctleadlag");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn14.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag_P1_Size_d);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag_P2_Size_c);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag_P3_Size_m);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctleadlag_RWORK_c[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn14.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn14.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctleadlag_RWORK_c
                   [0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S8>/Dctnotch2 (dnotch) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [15];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn15.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn15.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn15.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [15]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [15]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [15]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [15]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [15]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [15]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [15]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn15.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn15.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn15.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn15.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctleadlag_g;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn15.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn15.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn15.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctnotch2_n));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch2");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10 Gain_Notch_60(Low second order)+3_LeadLag_Integrator_Lowpass_50 Hz1/Dctnotch2");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn15.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P1_Size_f);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P2_Size_e);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P3_Size_f);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P4_Size_p);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P5_Size_p);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctnotch2_RWORK_g[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn15.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn15.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctnotch2_RWORK_g[0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S8>/Dctdoubleintegrator6 (ddoubleint) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [16];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn16.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn16.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn16.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [16]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [16]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [16]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [16]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [16]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [16]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [16]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn16.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn16.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn16.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn16.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctnotch2_n;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn16.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn16.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn16.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctdoubleintegrator6_j));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctdoubleintegrator6");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10 Gain_Notch_60(Low second order)+3_LeadLag_Integrator_Lowpass_50 Hz1/Dctdoubleintegrator6");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn16.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P1_Size_l);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P2_Size_i);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P3_Size_i);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator6_RWORK_n
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn16.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn16.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator6_RWORK_n
                   [0]);
      }

      /* registration */
      ddoubleint(rts);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S8>/Dct2lowpass (dlowpass2) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [17];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn17.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn17.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn17.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [17]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [17]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [17]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [17]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [17]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [17]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [17]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn17.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn17.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn17.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn17.UPtrs0;
          sfcnUPtrs[0] =
            &Reference_model_Control_Engineering_4_B.Dctdoubleintegrator6_j;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn17.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn17.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn17.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dct2lowpass_a));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10 Gain_Notch_60(Low second order)+3_LeadLag_Integrator_Lowpass_50 Hz1/Dct2lowpass");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn17.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass_P1_Size_g);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass_P2_Size_a);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass_P3_Size_a);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dct2lowpass_RWORK_g[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn17.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn17.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dct2lowpass_RWORK_g[
                   0]);
      }

      /* registration */
      dlowpass2(rts);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S9>/Dctnotch (dnotch) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [18];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn18.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn18.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn18.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [18]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [18]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [18]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [18]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [18]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [18]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [18]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn18.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn18.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn18.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn18.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Gain2_k;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn18.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn18.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn18.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctnotch_p));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-1 Low gain - large 3 Hz notch wide (second order) + 60 Notch wider _ 24.44 dB gain/Dctnotch");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn18.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P1_Size_j);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P2_Size_km);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P3_Size_h);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P4_Size_j);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P5_Size_c);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctnotch_RWORK_c[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn18.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn18.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctnotch_RWORK_c[0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S9>/Dctleadlag (dleadlag) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [19];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn19.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn19.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn19.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [19]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [19]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [19]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [19]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [19]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [19]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [19]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn19.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn19.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn19.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn19.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctnotch_p;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn19.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn19.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn19.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctleadlag_a));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctleadlag");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-1 Low gain - large 3 Hz notch wide (second order) + 60 Notch wider _ 24.44 dB gain/Dctleadlag");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn19.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag_P1_Size_f);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag_P2_Size_h);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag_P3_Size_g);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctleadlag_RWORK_g[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn19.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn19.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctleadlag_RWORK_g
                   [0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S9>/Dctnotch2 (dnotch) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [20];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn20.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn20.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn20.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [20]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [20]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [20]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [20]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [20]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [20]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [20]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn20.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn20.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn20.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn20.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctleadlag_a;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn20.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn20.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn20.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctnotch2_m));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch2");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-1 Low gain - large 3 Hz notch wide (second order) + 60 Notch wider _ 24.44 dB gain/Dctnotch2");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn20.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P1_Size_o);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P2_Size_m);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P3_Size_l);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P4_Size_o);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P5_Size_o);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctnotch2_RWORK_o[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn20.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn20.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctnotch2_RWORK_o[0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S9>/Dctdoubleintegrator6 (ddoubleint) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [21];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn21.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn21.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn21.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [21]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [21]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [21]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [21]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [21]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [21]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [21]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn21.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn21.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn21.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn21.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctnotch2_m;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn21.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn21.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn21.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctdoubleintegrator6_g));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctdoubleintegrator6");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-1 Low gain - large 3 Hz notch wide (second order) + 60 Notch wider _ 24.44 dB gain/Dctdoubleintegrator6");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn21.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P1_Size_j);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P2_Size_h);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P3_Size_p);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator6_RWORK_f
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn21.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn21.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator6_RWORK_f
                   [0]);
      }

      /* registration */
      ddoubleint(rts);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S9>/Dct2lowpass (dlowpass2) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [22];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn22.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn22.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn22.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [22]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [22]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [22]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [22]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [22]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [22]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [22]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn22.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn22.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn22.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn22.UPtrs0;
          sfcnUPtrs[0] =
            &Reference_model_Control_Engineering_4_B.Dctdoubleintegrator6_g;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn22.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn22.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn22.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dct2lowpass_b));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-1 Low gain - large 3 Hz notch wide (second order) + 60 Notch wider _ 24.44 dB gain/Dct2lowpass");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn22.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass_P1_Size_m);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass_P2_Size_e);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass_P3_Size_j);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dct2lowpass_RWORK_m[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn22.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn22.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dct2lowpass_RWORK_m[
                   0]);
      }

      /* registration */
      dlowpass2(rts);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S10>/Dctnotch (dnotch) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [23];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn23.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn23.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn23.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [23]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [23]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [23]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [23]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [23]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [23]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [23]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn23.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn23.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn23.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn23.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Gain2_m;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn23.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn23.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn23.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctnotch_m));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-2 High gain - similar 3 Hz notch + 60 Notch wide (second order)_ 53.68 dB gain/Dctnotch");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn23.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P1_Size_c);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P2_Size_ku);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P3_Size_f);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P4_Size_i);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P5_Size_o);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctnotch_RWORK_o[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn23.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn23.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctnotch_RWORK_o[0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S10>/Dctleadlag (dleadlag) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [24];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn24.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn24.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn24.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [24]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [24]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [24]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [24]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [24]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [24]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [24]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn24.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn24.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn24.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn24.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctnotch_m;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn24.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn24.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn24.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctleadlag_n));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctleadlag");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-2 High gain - similar 3 Hz notch + 60 Notch wide (second order)_ 53.68 dB gain/Dctleadlag");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn24.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag_P1_Size_e);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag_P2_Size_l);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag_P3_Size_k);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctleadlag_RWORK_b[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn24.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn24.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctleadlag_RWORK_b
                   [0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S10>/Dctnotch2 (dnotch) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [25];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn25.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn25.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn25.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [25]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [25]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [25]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [25]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [25]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [25]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [25]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn25.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn25.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn25.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn25.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctleadlag_n;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn25.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn25.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn25.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctnotch2_c));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch2");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-2 High gain - similar 3 Hz notch + 60 Notch wide (second order)_ 53.68 dB gain/Dctnotch2");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn25.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P1_Size_ob);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P2_Size_c);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P3_Size_k);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P4_Size_i);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P5_Size_pa);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctnotch2_RWORK_i[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn25.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn25.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctnotch2_RWORK_i[0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S10>/Dctdoubleintegrator6 (ddoubleint) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [26];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn26.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn26.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn26.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [26]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [26]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [26]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [26]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [26]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [26]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [26]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn26.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn26.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn26.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn26.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctnotch2_c;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn26.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn26.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn26.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctdoubleintegrator6_l));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctdoubleintegrator6");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-2 High gain - similar 3 Hz notch + 60 Notch wide (second order)_ 53.68 dB gain/Dctdoubleintegrator6");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn26.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P1_Size_o);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P2_Size_f);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P3_Size_f);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator6_RWORK_k
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn26.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn26.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator6_RWORK_k
                   [0]);
      }

      /* registration */
      ddoubleint(rts);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S10>/Dct2lowpass (dlowpass2) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [27];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn27.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn27.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn27.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [27]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [27]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [27]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [27]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [27]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [27]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [27]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn27.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn27.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn27.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn27.UPtrs0;
          sfcnUPtrs[0] =
            &Reference_model_Control_Engineering_4_B.Dctdoubleintegrator6_l;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn27.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn27.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn27.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dct2lowpass_a4));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-2 High gain - similar 3 Hz notch + 60 Notch wide (second order)_ 53.68 dB gain/Dct2lowpass");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn27.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass_P1_Size_k);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass_P2_Size_j);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass_P3_Size_m);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dct2lowpass_RWORK_f[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn27.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn27.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dct2lowpass_RWORK_f[
                   0]);
      }

      /* registration */
      dlowpass2(rts);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S12>/Dctnotch (dnotch) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [28];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn28.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn28.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn28.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [28]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [28]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [28]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [28]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [28]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [28]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [28]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn28.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn28.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn28.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn28.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Gain2_kd;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn28.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn28.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn28.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctnotch_d));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-3 Low gain - large 3 Hz notch wide (second order) + 60 Notch + LP even wider_ 40 dB dB gain/Dctnotch");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn28.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P1_Size_g);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P2_Size_l);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P3_Size_i);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P4_Size_n);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch_P5_Size_ov);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctnotch_RWORK_p[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn28.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn28.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctnotch_RWORK_p[0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S12>/Dctleadlag (dleadlag) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [29];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn29.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn29.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn29.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [29]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [29]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [29]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [29]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [29]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [29]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [29]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn29.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn29.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn29.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn29.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctnotch_d;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn29.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn29.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn29.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctleadlag_i));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctleadlag");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-3 Low gain - large 3 Hz notch wide (second order) + 60 Notch + LP even wider_ 40 dB dB gain/Dctleadlag");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn29.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag_P1_Size_o);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag_P2_Size_i);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctleadlag_P3_Size_mn);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctleadlag_RWORK_m[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn29.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn29.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctleadlag_RWORK_m
                   [0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S12>/Dctnotch2 (dnotch) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [30];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn30.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn30.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn30.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [30]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [30]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [30]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [30]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [30]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [30]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [30]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn30.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn30.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn30.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn30.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctleadlag_i;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn30.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn30.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn30.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctnotch2_k));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch2");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-3 Low gain - large 3 Hz notch wide (second order) + 60 Notch + LP even wider_ 40 dB dB gain/Dctnotch2");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn30.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P1_Size_a);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P2_Size_c2);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P3_Size_o);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P4_Size_d);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctnotch2_P5_Size_ol);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctnotch2_RWORK_f[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn30.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn30.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctnotch2_RWORK_f[0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S12>/Dctdoubleintegrator6 (ddoubleint) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [31];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn31.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn31.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn31.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [31]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [31]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [31]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [31]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [31]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [31]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [31]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn31.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn31.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn31.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn31.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_4_B.Dctnotch2_k;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn31.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn31.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn31.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dctdoubleintegrator6_n));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctdoubleintegrator6");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-3 Low gain - large 3 Hz notch wide (second order) + 60 Notch + LP even wider_ 40 dB dB gain/Dctdoubleintegrator6");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn31.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P1_Size_b);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P2_Size_c);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dctdoubleintegrator6_P3_Size_pk);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator6_RWORK_m
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn31.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn31.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dctdoubleintegrator6_RWORK_m
                   [0]);
      }

      /* registration */
      ddoubleint(rts);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering_4/<S12>/Dct2lowpass (dlowpass2) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [32];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn32.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn32.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn32.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.blkInfo2
                         [32]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.inputOutputPortInfo2
        [32]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods2
                           [32]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods3
                           [32]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.methods4
                           [32]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.statesInfo2
                         [32]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.periodicStatesInfo
          [32]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn32.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn32.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn32.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn32.UPtrs0;
          sfcnUPtrs[0] =
            &Reference_model_Control_Engineering_4_B.Dctdoubleintegrator6_n;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn32.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn32.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn32.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_4_B.Dct2lowpass_j));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass");
      ssSetPath(rts,
                "Reference_model_Control_Engineering_4/T10-3 Low gain - large 3 Hz notch wide (second order) + 60 Notch + LP even wider_ 40 dB dB gain/Dct2lowpass");
      ssSetRTModel(rts,Reference_model_Control_Engineering_4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn32.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass_P1_Size_j);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass_P2_Size_d);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_4_P.Dct2lowpass_P3_Size_p);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_4_DW.Dct2lowpass_RWORK_i[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn32.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_4_M->NonInlinedSFcns.Sfcn32.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_4_DW.Dct2lowpass_RWORK_i[
                   0]);
      }

      /* registration */
      dlowpass2(rts);
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

  /* Start for Constant: '<S5>/Start setpoint' */
  Reference_model_Control_Engineering_4_B.Startsetpoint =
    Reference_model_Control_Engineering_4_P.Refpower_stat;

  /* Start for S-Function (ec_Supervisor): '<S14>/S-Function' */
  /* Level2 S-Function Block: '<S14>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S2>/Constant1' */
  memcpy(&Reference_model_Control_Engineering_4_B.Constant1[0],
         &Reference_model_Control_Engineering_4_P.Constant1_Value[0], sizeof
         (real_T) << 3U);

  /* Start for S-Function (dnotch): '<S11>/Dctnotch8' */
  /* Level2 S-Function Block: '<S11>/Dctnotch8' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dleadlag): '<S11>/Dctleadlag4' */
  /* Level2 S-Function Block: '<S11>/Dctleadlag4' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S11>/Dctnotch9' */
  /* Level2 S-Function Block: '<S11>/Dctnotch9' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (ddoubleint): '<S11>/Dctdoubleintegrator4' */
  /* Level2 S-Function Block: '<S11>/Dctdoubleintegrator4' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass2): '<S11>/Dct2lowpass4' */
  /* Level2 S-Function Block: '<S11>/Dct2lowpass4' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S7>/Dctnotch' */
  /* Level2 S-Function Block: '<S7>/Dctnotch' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dleadlag): '<S7>/Dctleadlag' */
  /* Level2 S-Function Block: '<S7>/Dctleadlag' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S7>/Dctnotch2' */
  /* Level2 S-Function Block: '<S7>/Dctnotch2' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (ddoubleint): '<S7>/Dctdoubleintegrator6' */
  /* Level2 S-Function Block: '<S7>/Dctdoubleintegrator6' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[11];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass2): '<S7>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S7>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[12];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S8>/Dctnotch' */
  /* Level2 S-Function Block: '<S8>/Dctnotch' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[13];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dleadlag): '<S8>/Dctleadlag' */
  /* Level2 S-Function Block: '<S8>/Dctleadlag' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[14];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S8>/Dctnotch2' */
  /* Level2 S-Function Block: '<S8>/Dctnotch2' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[15];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (ddoubleint): '<S8>/Dctdoubleintegrator6' */
  /* Level2 S-Function Block: '<S8>/Dctdoubleintegrator6' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[16];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass2): '<S8>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S8>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[17];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S9>/Dctnotch' */
  /* Level2 S-Function Block: '<S9>/Dctnotch' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[18];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dleadlag): '<S9>/Dctleadlag' */
  /* Level2 S-Function Block: '<S9>/Dctleadlag' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[19];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S9>/Dctnotch2' */
  /* Level2 S-Function Block: '<S9>/Dctnotch2' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[20];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (ddoubleint): '<S9>/Dctdoubleintegrator6' */
  /* Level2 S-Function Block: '<S9>/Dctdoubleintegrator6' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[21];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass2): '<S9>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S9>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[22];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S10>/Dctnotch' */
  /* Level2 S-Function Block: '<S10>/Dctnotch' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[23];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dleadlag): '<S10>/Dctleadlag' */
  /* Level2 S-Function Block: '<S10>/Dctleadlag' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[24];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S10>/Dctnotch2' */
  /* Level2 S-Function Block: '<S10>/Dctnotch2' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[25];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (ddoubleint): '<S10>/Dctdoubleintegrator6' */
  /* Level2 S-Function Block: '<S10>/Dctdoubleintegrator6' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[26];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass2): '<S10>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S10>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[27];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S12>/Dctnotch' */
  /* Level2 S-Function Block: '<S12>/Dctnotch' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[28];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dleadlag): '<S12>/Dctleadlag' */
  /* Level2 S-Function Block: '<S12>/Dctleadlag' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[29];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S12>/Dctnotch2' */
  /* Level2 S-Function Block: '<S12>/Dctnotch2' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[30];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (ddoubleint): '<S12>/Dctdoubleintegrator6' */
  /* Level2 S-Function Block: '<S12>/Dctdoubleintegrator6' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[31];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass2): '<S12>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S12>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[32];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  {
    FILE* a;
    real_T tmp;
    int32_T i;
    int32_T t;
    uint32_T tseed;

    /* InitializeConditions for S-Function (ref3b): '<S6>/S-Function' */
    /* Level2 S-Function Block: '<S6>/S-Function' (ref3b) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions
        [0];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* InitializeConditions for RandomNumber: '<Root>/Noise' */
    tmp = floor(Reference_model_Control_Engineering_4_P.Noise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    Reference_model_Control_Engineering_4_DW.RandSeed = ((((tseed - ((uint32_T)i
      << 16U)) + t) << 16U) + t) + i;
    if (Reference_model_Control_Engineering_4_DW.RandSeed < 1U) {
      Reference_model_Control_Engineering_4_DW.RandSeed = 1144108930U;
    } else if (Reference_model_Control_Engineering_4_DW.RandSeed > 2147483646U)
    {
      Reference_model_Control_Engineering_4_DW.RandSeed = 2147483646U;
    }

    Reference_model_Control_Engineering_4_DW.NextOutput =
      rt_nrand_Upu32_Yd_f_pw_snf
      (&Reference_model_Control_Engineering_4_DW.RandSeed) *
      Reference_model_Control_Engineering_4_P.Noise_StdDev +
      Reference_model_Control_Engineering_4_P.Noise_Mean;

    /* End of InitializeConditions for RandomNumber: '<Root>/Noise' */

    /* SystemInitialize for MATLAB Function: '<S3>/SPERTE_measurement_function' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Reference_model_Control_Engineering_4_DW.eml_autoflush[i] = false;
      Reference_model_Control_Engineering_4_DW.eml_openfiles[i] = a;
    }

    Reference_model_Control_Engineering_4_DW.NF = 0;
    Reference_model_Control_Engineering_4_DW.NS = 0U;
    Reference_model_Control_Engineering_4_DW.fileID = 0.0;
    Reference_model_Control_Engineering_4_DW.busy = 0U;

    /* End of SystemInitialize for MATLAB Function: '<S3>/SPERTE_measurement_function' */
  }
}

/* Model terminate function */
void Reference_model_Control_Engineering_4_terminate(void)
{
  /* Terminate for S-Function (ref3b): '<S6>/S-Function' */
  /* Level2 S-Function Block: '<S6>/S-Function' (ref3b) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ec_Supervisor): '<S14>/S-Function' */
  /* Level2 S-Function Block: '<S14>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ec_Ebox): '<S13>/ec_Ebox' */
  /* Level2 S-Function Block: '<S13>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S11>/Dctnotch8' */
  /* Level2 S-Function Block: '<S11>/Dctnotch8' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dleadlag): '<S11>/Dctleadlag4' */
  /* Level2 S-Function Block: '<S11>/Dctleadlag4' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S11>/Dctnotch9' */
  /* Level2 S-Function Block: '<S11>/Dctnotch9' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ddoubleint): '<S11>/Dctdoubleintegrator4' */
  /* Level2 S-Function Block: '<S11>/Dctdoubleintegrator4' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S11>/Dct2lowpass4' */
  /* Level2 S-Function Block: '<S11>/Dct2lowpass4' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S7>/Dctnotch' */
  /* Level2 S-Function Block: '<S7>/Dctnotch' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dleadlag): '<S7>/Dctleadlag' */
  /* Level2 S-Function Block: '<S7>/Dctleadlag' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S7>/Dctnotch2' */
  /* Level2 S-Function Block: '<S7>/Dctnotch2' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ddoubleint): '<S7>/Dctdoubleintegrator6' */
  /* Level2 S-Function Block: '<S7>/Dctdoubleintegrator6' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S7>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S7>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S8>/Dctnotch' */
  /* Level2 S-Function Block: '<S8>/Dctnotch' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dleadlag): '<S8>/Dctleadlag' */
  /* Level2 S-Function Block: '<S8>/Dctleadlag' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[14];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S8>/Dctnotch2' */
  /* Level2 S-Function Block: '<S8>/Dctnotch2' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[15];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ddoubleint): '<S8>/Dctdoubleintegrator6' */
  /* Level2 S-Function Block: '<S8>/Dctdoubleintegrator6' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[16];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S8>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S8>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[17];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S9>/Dctnotch' */
  /* Level2 S-Function Block: '<S9>/Dctnotch' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[18];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dleadlag): '<S9>/Dctleadlag' */
  /* Level2 S-Function Block: '<S9>/Dctleadlag' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[19];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S9>/Dctnotch2' */
  /* Level2 S-Function Block: '<S9>/Dctnotch2' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[20];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ddoubleint): '<S9>/Dctdoubleintegrator6' */
  /* Level2 S-Function Block: '<S9>/Dctdoubleintegrator6' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[21];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S9>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S9>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[22];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S10>/Dctnotch' */
  /* Level2 S-Function Block: '<S10>/Dctnotch' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[23];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dleadlag): '<S10>/Dctleadlag' */
  /* Level2 S-Function Block: '<S10>/Dctleadlag' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[24];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S10>/Dctnotch2' */
  /* Level2 S-Function Block: '<S10>/Dctnotch2' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[25];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ddoubleint): '<S10>/Dctdoubleintegrator6' */
  /* Level2 S-Function Block: '<S10>/Dctdoubleintegrator6' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[26];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S10>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S10>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[27];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S12>/Dctnotch' */
  /* Level2 S-Function Block: '<S12>/Dctnotch' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[28];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dleadlag): '<S12>/Dctleadlag' */
  /* Level2 S-Function Block: '<S12>/Dctleadlag' (dleadlag) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[29];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S12>/Dctnotch2' */
  /* Level2 S-Function Block: '<S12>/Dctnotch2' (dnotch) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[30];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ddoubleint): '<S12>/Dctdoubleintegrator6' */
  /* Level2 S-Function Block: '<S12>/Dctdoubleintegrator6' (ddoubleint) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[31];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S12>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S12>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_4_M->childSfunctions[32];
    sfcnTerminate(rts);
  }
}
