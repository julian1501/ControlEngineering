/*
 * Reference_model_Control_Engineering.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Reference_model_Control_Engineering".
 *
 * Model version              : 7.0
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Mar 13 11:48:57 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Reference_model_Control_Engineering.h"
#include "Reference_model_Control_Engineering_private.h"
#include "Reference_model_Control_Engineering_dt.h"

/* Block signals (default storage) */
B_Reference_model_Control_Engineering_T Reference_model_Control_Engineering_B;

/* Block states (default storage) */
DW_Reference_model_Control_Engineering_T Reference_model_Control_Engineering_DW;

/* Real-time model */
static RT_MODEL_Reference_model_Control_Engineering_T
  Reference_model_Control_Engineering_M_;
RT_MODEL_Reference_model_Control_Engineering_T *const
  Reference_model_Control_Engineering_M =
  &Reference_model_Control_Engineering_M_;

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
void Reference_model_Control_Engineering_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(Reference_model_Control_Engineering_M,
    2));
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
  if (Reference_model_Control_Engineering_M->Timing.TaskCounters.TID[1] == 0) {
    Reference_model_Control_Engineering_M->Timing.RateInteraction.TID1_2 =
      (Reference_model_Control_Engineering_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    Reference_model_Control_Engineering_M->Timing.perTaskSampleHits[5] =
      Reference_model_Control_Engineering_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Reference_model_Control_Engineering_M->Timing.TaskCounters.TID[2])++;
  if ((Reference_model_Control_Engineering_M->Timing.TaskCounters.TID[2]) > 7) {/* Sample time: [0.002s, 0.0s] */
    Reference_model_Control_Engineering_M->Timing.TaskCounters.TID[2] = 0;
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
    if (Reference_model_Control_Engineering_DW.eml_openfiles[(int8_T)k - 1] ==
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
    Reference_model_Control_Engineering_B.filestar_m = fopen(&ccfilename->data[0],
      cpermission);
    Reference_model__emxFree_char_T(&ccfilename);
    if (Reference_model_Control_Engineering_B.filestar_m != NULL) {
      Reference_model_Control_Engineering_DW.eml_openfiles[j - 1] =
        Reference_model_Control_Engineering_B.filestar_m;
      Reference_model_Control_Engineering_DW.eml_autoflush[j - 1] = true;
      i = j + 2;
      if (j + 2 > 127) {
        i = 127;
      }

      fileid = (int8_T)i;
    }
  }

  return fileid;
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
    filestar = Reference_model_Control_Engineering_DW.eml_openfiles[b_fileid - 3];
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
      Reference_model_Control_Engineering_DW.eml_openfiles[fileid - 3] = NULL;
      Reference_model_Control_Engineering_DW.eml_autoflush[fileid - 3] = true;
    }
  }

  return st;
}

/* Model step function for TID0 */
void Reference_model_Control_Engineering_step0(void) /* Sample time: [0.0s, 0.0s] */
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

  /* RandomNumber: '<Root>/Noise' */
  Reference_model_Control_Engineering_B.Noise =
    Reference_model_Control_Engineering_DW.NextOutput;

  /* S-Function (ec_Supervisor): '<S8>/S-Function' */

  /* Level2 S-Function Block: '<S8>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ec_Ebox): '<S7>/ec_Ebox' */

  /* Level2 S-Function Block: '<S7>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* ManualSwitch: '<Root>/Select encoder' */
  if (Reference_model_Control_Engineering_P.Selectencoder_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Select encoder' incorporates:
     *  Gain: '<S2>/count2rad'
     */
    Reference_model_Control_Engineering_B.Selectencoder =
      Reference_model_Control_Engineering_P.count2rad_Gain *
      Reference_model_Control_Engineering_B.ec_Ebox_o2[0];
  } else {
    /* ManualSwitch: '<Root>/Select encoder' incorporates:
     *  Gain: '<S2>/count2rad'
     */
    Reference_model_Control_Engineering_B.Selectencoder =
      Reference_model_Control_Engineering_P.count2rad_Gain *
      Reference_model_Control_Engineering_B.ec_Ebox_o2[1];
  }

  /* End of ManualSwitch: '<Root>/Select encoder' */

  /* MATLAB Function: '<S3>/SPERTE_measurement_function' incorporates:
   *  Constant: '<S3>/SPERTE_measurement_samples'
   *  Constant: '<S3>/SPERTE_measurement_trigger_command'
   *  SignalConversion generated from: '<S9>/ SFunction '
   */
  if ((((Reference_model_Control_Engineering_P.MeasurementBlock_triggertype == 1)
        &&
        (Reference_model_Control_Engineering_P.MeasurementBlock_trigger_comman ==
         1)) ||
       ((Reference_model_Control_Engineering_P.MeasurementBlock_triggertype == 2)
        &&
        (Reference_model_Control_Engineering_P.MeasurementBlock_trigger_comman ==
         1))) && (Reference_model_Control_Engineering_DW.busy != 1)) {
    Reference_model__emxInit_char_T(&charStr, 2);
    Reference_model_Control_Engineering_B.nbytes = (int32_T)snprintf(NULL, 0,
      "measurement_%d.bin", Reference_model_Control_Engineering_DW.NF) + 1;
    tmp = charStr->size[0] * charStr->size[1];
    charStr->size[0] = 1;
    charStr->size[1] = Reference_model_Control_Engineering_B.nbytes;
    Refere_emxEnsureCapacity_char_T(charStr, tmp);
    snprintf(&charStr->data[0], (size_t)
             Reference_model_Control_Engineering_B.nbytes, "measurement_%d.bin",
             Reference_model_Control_Engineering_DW.NF);
    if (1 > Reference_model_Control_Engineering_B.nbytes - 1) {
      Reference_model_Control_Engineering_B.loop_ub = -1;
    } else {
      Reference_model_Control_Engineering_B.loop_ub =
        Reference_model_Control_Engineering_B.nbytes - 2;
    }

    Reference_model__emxInit_char_T(&charStr_0, 2);
    tmp = charStr_0->size[0] * charStr_0->size[1];
    charStr_0->size[0] = 1;
    charStr_0->size[1] = Reference_model_Control_Engineering_B.loop_ub + 1;
    Refere_emxEnsureCapacity_char_T(charStr_0, tmp);
    for (Reference_model_Control_Engineering_B.nbytes = 0;
         Reference_model_Control_Engineering_B.nbytes <=
         Reference_model_Control_Engineering_B.loop_ub;
         Reference_model_Control_Engineering_B.nbytes++) {
      charStr_0->data[Reference_model_Control_Engineering_B.nbytes] =
        charStr->data[Reference_model_Control_Engineering_B.nbytes];
    }

    Reference_model__emxFree_char_T(&charStr);
    b_fileid = Reference_model_Control__cfopen(charStr_0, "wb");
    Reference_model_Control_Engineering_DW.fileID = b_fileid;
    Reference_model_Control_Engineering_B.nbytes =
      Reference_model_Control_Engineering_DW.NF + 1;
    Reference_model__emxFree_char_T(&charStr_0);
    if (Reference_model_Control_Engineering_DW.NF + 1 > 32767) {
      Reference_model_Control_Engineering_B.nbytes = 32767;
    }

    Reference_model_Control_Engineering_DW.NF = (int16_T)
      Reference_model_Control_Engineering_B.nbytes;
    Reference_model_Control_Engineering_DW.busy = 1U;
    Reference_model_Control_Engineering_DW.NS = 0U;
  }

  if (Reference_model_Control_Engineering_DW.busy == 1) {
    if (Reference_model_Control_Engineering_DW.NS <
        Reference_model_Control_Engineering_P.MeasurementBlock_N_samples) {
      b_fileid = (int8_T)rt_roundd_snf
        (Reference_model_Control_Engineering_DW.fileID);
      if ((b_fileid < 0) || (Reference_model_Control_Engineering_DW.fileID !=
                             b_fileid)) {
        b_fileid = -1;
      }

      if (b_fileid >= 3) {
        Reference_model_Control_Engineering_B.filestar =
          Reference_model_Control_Engineering_DW.eml_openfiles[b_fileid - 3];
        autoflush =
          Reference_model_Control_Engineering_DW.eml_autoflush[b_fileid - 3];
      } else if (b_fileid == 0) {
        Reference_model_Control_Engineering_B.filestar = stdin;
        autoflush = true;
      } else if (b_fileid == 1) {
        Reference_model_Control_Engineering_B.filestar = stdout;
        autoflush = true;
      } else if (b_fileid == 2) {
        Reference_model_Control_Engineering_B.filestar = stderr;
        autoflush = true;
      } else {
        Reference_model_Control_Engineering_B.filestar = NULL;
        autoflush = true;
      }

      if (!(Reference_model_Control_Engineering_DW.fileID != 0.0)) {
        Reference_model_Control_Engineering_B.filestar = NULL;
      }

      if (!(Reference_model_Control_Engineering_B.filestar == NULL)) {
        Reference_model_Control_Engineering_B.xout[0] = (real32_T)
          Reference_model_Control_Engineering_B.Noise;
        Reference_model_Control_Engineering_B.xout[1] = (real32_T)
          Reference_model_Control_Engineering_B.Selectencoder;
        Reference_model_Control_Engineering_B.bytesOutSizet = fwrite
          (&Reference_model_Control_Engineering_B.xout[0], sizeof(real32_T),
           (size_t)2, Reference_model_Control_Engineering_B.filestar);
        if (((real_T)Reference_model_Control_Engineering_B.bytesOutSizet > 0.0) &&
            autoflush) {
          fflush(Reference_model_Control_Engineering_B.filestar);
        }
      }

      qY = Reference_model_Control_Engineering_DW.NS + 1U;
      if (Reference_model_Control_Engineering_DW.NS + 1U <
          Reference_model_Control_Engineering_DW.NS) {
        qY = MAX_uint32_T;
      }

      Reference_model_Control_Engineering_DW.NS = qY;
    } else {
      Reference_model_Control_cfclose
        (Reference_model_Control_Engineering_DW.fileID);
      Reference_model_Control_Engineering_DW.busy = 0U;
      Reference_model_Control_Engineering_DW.NS = 0U;
    }
  }

  /* End of MATLAB Function: '<S3>/SPERTE_measurement_function' */

  /* Constant: '<S5>/Start setpoint' */
  Reference_model_Control_Engineering_B.Startsetpoint =
    Reference_model_Control_Engineering_P.Refpower_stat;

  /* S-Function (ref3b): '<S6>/S-Function' */

  /* Level2 S-Function Block: '<S6>/S-Function' (ref3b) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* Quantizer: '<Root>/Quantizer1' */
  Reference_model_Control_Engineering_B.Quantizer1 = rt_roundd_snf
    (Reference_model_Control_Engineering_B.SFunction_c[2] /
     Reference_model_Control_Engineering_P.Quantizer1_Interval) *
    Reference_model_Control_Engineering_P.Quantizer1_Interval;

  /* Sum: '<Root>/Sum' */
  Reference_model_Control_Engineering_B.Sum =
    Reference_model_Control_Engineering_B.Quantizer1 -
    Reference_model_Control_Engineering_B.Selectencoder;

  /* SignalConversion: '<S4>/Buffer' */
  Reference_model_Control_Engineering_B.Buffer[0] =
    Reference_model_Control_Engineering_B.Quantizer1;
  Reference_model_Control_Engineering_B.Buffer[1] =
    Reference_model_Control_Engineering_B.Selectencoder;
  Reference_model_Control_Engineering_B.Buffer[2] =
    Reference_model_Control_Engineering_B.Sum;

  /* RateTransition: '<S4>/Downsample' */
  if (Reference_model_Control_Engineering_M->Timing.RateInteraction.TID1_2) {
    Reference_model_Control_Engineering_DW.Downsample_Buffer[0] =
      Reference_model_Control_Engineering_B.Buffer[0];
    Reference_model_Control_Engineering_DW.Downsample_Buffer[1] =
      Reference_model_Control_Engineering_B.Buffer[1];
    Reference_model_Control_Engineering_DW.Downsample_Buffer[2] =
      Reference_model_Control_Engineering_B.Buffer[2];
  }

  /* End of RateTransition: '<S4>/Downsample' */

  /* Gain: '<S1>/Gain1' */
  Reference_model_Control_Engineering_B.Gain1 =
    Reference_model_Control_Engineering_P.Gain1_Gain *
    Reference_model_Control_Engineering_B.Sum;

  /* S-Function (dpd): '<S1>/Dctpd' */

  /* Level2 S-Function Block: '<S1>/Dctpd' (dpd) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass2): '<S1>/Dct2lowpass' */

  /* Level2 S-Function Block: '<S1>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* Sum: '<Root>/Sum1' */
  Reference_model_Control_Engineering_B.Sum1 =
    Reference_model_Control_Engineering_B.Dct2lowpass +
    Reference_model_Control_Engineering_B.Noise;

  /* SignalConversion generated from: '<Root>/To Workspace' */
  Reference_model_Control_Engineering_B.TmpSignalConversionAtToWorkspac[0] =
    Reference_model_Control_Engineering_B.Noise;
  Reference_model_Control_Engineering_B.TmpSignalConversionAtToWorkspac[1] =
    Reference_model_Control_Engineering_B.Sum1;

  /* Constant: '<S2>/Constant1' */
  memcpy(&Reference_model_Control_Engineering_B.Constant1[0],
         &Reference_model_Control_Engineering_P.Constant1_Value[0], sizeof
         (real_T) << 3U);

  /* Gain: '<S7>/Gain' incorporates:
   *  Constant: '<S2>/Constant'
   */
  Reference_model_Control_Engineering_B.Gain[0] =
    Reference_model_Control_Engineering_P.Gain_Gain *
    Reference_model_Control_Engineering_P.Constant_Value[0];
  Reference_model_Control_Engineering_B.Gain[1] =
    Reference_model_Control_Engineering_P.Gain_Gain *
    Reference_model_Control_Engineering_P.Constant_Value[1];

  /* Saturate: '<S2>/Saturation' */
  if (Reference_model_Control_Engineering_B.Sum1 >
      Reference_model_Control_Engineering_P.Saturation_UpperSat) {
    Reference_model_Control_Engineering_B.Quantizer1 =
      Reference_model_Control_Engineering_P.Saturation_UpperSat;
  } else if (Reference_model_Control_Engineering_B.Sum1 <
             Reference_model_Control_Engineering_P.Saturation_LowerSat) {
    Reference_model_Control_Engineering_B.Quantizer1 =
      Reference_model_Control_Engineering_P.Saturation_LowerSat;
  } else {
    Reference_model_Control_Engineering_B.Quantizer1 =
      Reference_model_Control_Engineering_B.Sum1;
  }

  /* Saturate: '<S7>/Saturation' */
  if (Reference_model_Control_Engineering_B.Quantizer1 >
      Reference_model_Control_Engineering_P.Saturation_UpperSat_d) {
    /* Saturate: '<S7>/Saturation' */
    Reference_model_Control_Engineering_B.Saturation[0] =
      Reference_model_Control_Engineering_P.Saturation_UpperSat_d;
  } else if (Reference_model_Control_Engineering_B.Quantizer1 <
             Reference_model_Control_Engineering_P.Saturation_LowerSat_e) {
    /* Saturate: '<S7>/Saturation' */
    Reference_model_Control_Engineering_B.Saturation[0] =
      Reference_model_Control_Engineering_P.Saturation_LowerSat_e;
  } else {
    /* Saturate: '<S7>/Saturation' */
    Reference_model_Control_Engineering_B.Saturation[0] =
      Reference_model_Control_Engineering_B.Quantizer1;
  }

  /* Saturate: '<S2>/Saturation' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  if (Reference_model_Control_Engineering_P.Constant2_Value >
      Reference_model_Control_Engineering_P.Saturation_UpperSat) {
    Reference_model_Control_Engineering_B.Quantizer1 =
      Reference_model_Control_Engineering_P.Saturation_UpperSat;
  } else if (Reference_model_Control_Engineering_P.Constant2_Value <
             Reference_model_Control_Engineering_P.Saturation_LowerSat) {
    Reference_model_Control_Engineering_B.Quantizer1 =
      Reference_model_Control_Engineering_P.Saturation_LowerSat;
  } else {
    Reference_model_Control_Engineering_B.Quantizer1 =
      Reference_model_Control_Engineering_P.Constant2_Value;
  }

  /* Saturate: '<S7>/Saturation' */
  if (Reference_model_Control_Engineering_B.Quantizer1 >
      Reference_model_Control_Engineering_P.Saturation_UpperSat_d) {
    /* Saturate: '<S7>/Saturation' */
    Reference_model_Control_Engineering_B.Saturation[1] =
      Reference_model_Control_Engineering_P.Saturation_UpperSat_d;
  } else if (Reference_model_Control_Engineering_B.Quantizer1 <
             Reference_model_Control_Engineering_P.Saturation_LowerSat_e) {
    /* Saturate: '<S7>/Saturation' */
    Reference_model_Control_Engineering_B.Saturation[1] =
      Reference_model_Control_Engineering_P.Saturation_LowerSat_e;
  } else {
    /* Saturate: '<S7>/Saturation' */
    Reference_model_Control_Engineering_B.Saturation[1] =
      Reference_model_Control_Engineering_B.Quantizer1;
  }

  /* Update for RandomNumber: '<Root>/Noise' */
  Reference_model_Control_Engineering_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
    (&Reference_model_Control_Engineering_DW.RandSeed) *
    Reference_model_Control_Engineering_P.Noise_StdDev +
    Reference_model_Control_Engineering_P.Noise_Mean;

  /* External mode */
  rtExtModeUploadCheckTrigger(3);
  rtExtModeUpload(1, (real_T)Reference_model_Control_Engineering_M->Timing.t[0]);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Reference_model_Control_Engineering_M)!=-1) &&
        !((rtmGetTFinal(Reference_model_Control_Engineering_M)-
           Reference_model_Control_Engineering_M->Timing.t[0]) >
          Reference_model_Control_Engineering_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(Reference_model_Control_Engineering_M,
                        "Simulation finished");
    }

    if (rtmGetStopRequested(Reference_model_Control_Engineering_M)) {
      rtmSetErrorStatus(Reference_model_Control_Engineering_M,
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
  if (!(++Reference_model_Control_Engineering_M->Timing.clockTick0)) {
    ++Reference_model_Control_Engineering_M->Timing.clockTickH0;
  }

  Reference_model_Control_Engineering_M->Timing.t[0] =
    Reference_model_Control_Engineering_M->Timing.clockTick0 *
    Reference_model_Control_Engineering_M->Timing.stepSize0 +
    Reference_model_Control_Engineering_M->Timing.clockTickH0 *
    Reference_model_Control_Engineering_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Reference_model_Control_Engineering_M->Timing.clockTick1)) {
    ++Reference_model_Control_Engineering_M->Timing.clockTickH1;
  }

  Reference_model_Control_Engineering_M->Timing.t[1] =
    Reference_model_Control_Engineering_M->Timing.clockTick1 *
    Reference_model_Control_Engineering_M->Timing.stepSize1 +
    Reference_model_Control_Engineering_M->Timing.clockTickH1 *
    Reference_model_Control_Engineering_M->Timing.stepSize1 * 4294967296.0;
}

/* Model step function for TID2 */
void Reference_model_Control_Engineering_step2(void) /* Sample time: [0.002s, 0.0s] */
{
  /* RateTransition: '<S4>/Downsample' */
  Reference_model_Control_Engineering_B.Downsample[0] =
    Reference_model_Control_Engineering_DW.Downsample_Buffer[0];
  Reference_model_Control_Engineering_B.Downsample[1] =
    Reference_model_Control_Engineering_DW.Downsample_Buffer[1];
  Reference_model_Control_Engineering_B.Downsample[2] =
    Reference_model_Control_Engineering_DW.Downsample_Buffer[2];
  rtExtModeUpload(2, (real_T)
                  (((Reference_model_Control_Engineering_M->Timing.clockTick2+
                     Reference_model_Control_Engineering_M->Timing.clockTickH2*
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
  Reference_model_Control_Engineering_M->Timing.clockTick2++;
  if (!Reference_model_Control_Engineering_M->Timing.clockTick2) {
    Reference_model_Control_Engineering_M->Timing.clockTickH2++;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Reference_model_Control_Engineering_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Reference_model_Control_Engineering_step0();
    break;

   case 2 :
    Reference_model_Control_Engineering_step2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Reference_model_Control_Engineering_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Reference_model_Control_Engineering_M, 0,
                sizeof(RT_MODEL_Reference_model_Control_Engineering_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Reference_model_Control_Engineering_M->solverInfo,
                          &Reference_model_Control_Engineering_M->Timing.simTimeStep);
    rtsiSetTPtr(&Reference_model_Control_Engineering_M->solverInfo, &rtmGetTPtr
                (Reference_model_Control_Engineering_M));
    rtsiSetStepSizePtr(&Reference_model_Control_Engineering_M->solverInfo,
                       &Reference_model_Control_Engineering_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Reference_model_Control_Engineering_M->solverInfo,
                          (&rtmGetErrorStatus
      (Reference_model_Control_Engineering_M)));
    rtsiSetRTModelPtr(&Reference_model_Control_Engineering_M->solverInfo,
                      Reference_model_Control_Engineering_M);
  }

  rtsiSetSimTimeStep(&Reference_model_Control_Engineering_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&Reference_model_Control_Engineering_M->solverInfo,
                    "FixedStepDiscrete");
  Reference_model_Control_Engineering_M->solverInfoPtr =
    (&Reference_model_Control_Engineering_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      Reference_model_Control_Engineering_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Reference_model_Control_Engineering_M points to
       static memory which is guaranteed to be non-NULL" */
    Reference_model_Control_Engineering_M->Timing.sampleTimeTaskIDPtr =
      (&mdlTsMap[0]);
    Reference_model_Control_Engineering_M->Timing.sampleTimes =
      (&Reference_model_Control_Engineering_M->Timing.sampleTimesArray[0]);
    Reference_model_Control_Engineering_M->Timing.offsetTimes =
      (&Reference_model_Control_Engineering_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Reference_model_Control_Engineering_M->Timing.sampleTimes[0] = (0.0);
    Reference_model_Control_Engineering_M->Timing.sampleTimes[1] = (0.00025);
    Reference_model_Control_Engineering_M->Timing.sampleTimes[2] = (0.002);

    /* task offsets */
    Reference_model_Control_Engineering_M->Timing.offsetTimes[0] = (0.0);
    Reference_model_Control_Engineering_M->Timing.offsetTimes[1] = (0.0);
    Reference_model_Control_Engineering_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Reference_model_Control_Engineering_M,
             &Reference_model_Control_Engineering_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      Reference_model_Control_Engineering_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      Reference_model_Control_Engineering_M->Timing.perTaskSampleHitsArray;
    Reference_model_Control_Engineering_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Reference_model_Control_Engineering_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Reference_model_Control_Engineering_M, -1);
  Reference_model_Control_Engineering_M->Timing.stepSize0 = 0.00025;
  Reference_model_Control_Engineering_M->Timing.stepSize1 = 0.00025;

  /* External mode info */
  Reference_model_Control_Engineering_M->Sizes.checksums[0] = (3477193817U);
  Reference_model_Control_Engineering_M->Sizes.checksums[1] = (1569805435U);
  Reference_model_Control_Engineering_M->Sizes.checksums[2] = (2429156659U);
  Reference_model_Control_Engineering_M->Sizes.checksums[3] = (1168022689U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Reference_model_Control_Engineering_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr
      (Reference_model_Control_Engineering_M->extModeInfo,
       &Reference_model_Control_Engineering_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Reference_model_Control_Engineering_M->extModeInfo,
                        Reference_model_Control_Engineering_M->Sizes.checksums);
    rteiSetTPtr(Reference_model_Control_Engineering_M->extModeInfo, rtmGetTPtr
                (Reference_model_Control_Engineering_M));
  }

  Reference_model_Control_Engineering_M->solverInfoPtr =
    (&Reference_model_Control_Engineering_M->solverInfo);
  Reference_model_Control_Engineering_M->Timing.stepSize = (0.00025);
  rtsiSetFixedStepSize(&Reference_model_Control_Engineering_M->solverInfo,
                       0.00025);
  rtsiSetSolverMode(&Reference_model_Control_Engineering_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  (void) memset(((void *) &Reference_model_Control_Engineering_B), 0,
                sizeof(B_Reference_model_Control_Engineering_T));

  /* states (dwork) */
  (void) memset((void *)&Reference_model_Control_Engineering_DW, 0,
                sizeof(DW_Reference_model_Control_Engineering_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Reference_model_Control_Engineering_M->SpecialInfo.mappingInfo = (&dtInfo);
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
      &Reference_model_Control_Engineering_M->NonInlinedSFcns.sfcnInfo;
    Reference_model_Control_Engineering_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (Reference_model_Control_Engineering_M)));
    Reference_model_Control_Engineering_M->Sizes.numSampTimes = (3);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &Reference_model_Control_Engineering_M->Sizes.numSampTimes);
    Reference_model_Control_Engineering_M->NonInlinedSFcns.taskTimePtrs[0] =
      &(rtmGetTPtr(Reference_model_Control_Engineering_M)[0]);
    Reference_model_Control_Engineering_M->NonInlinedSFcns.taskTimePtrs[1] =
      &(rtmGetTPtr(Reference_model_Control_Engineering_M)[1]);
    Reference_model_Control_Engineering_M->NonInlinedSFcns.taskTimePtrs[2] =
      &(rtmGetTPtr(Reference_model_Control_Engineering_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,
                   Reference_model_Control_Engineering_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart
                     (Reference_model_Control_Engineering_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal
                     (Reference_model_Control_Engineering_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (Reference_model_Control_Engineering_M));
    rtssSetStepSizePtr(sfcnInfo,
                       &Reference_model_Control_Engineering_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (Reference_model_Control_Engineering_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Reference_model_Control_Engineering_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Reference_model_Control_Engineering_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &Reference_model_Control_Engineering_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &Reference_model_Control_Engineering_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Reference_model_Control_Engineering_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Reference_model_Control_Engineering_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo,
                         &Reference_model_Control_Engineering_M->solverInfoPtr);
  }

  Reference_model_Control_Engineering_M->Sizes.numSFcns = (5);

  /* register each child */
  {
    (void) memset((void *)
                  &Reference_model_Control_Engineering_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  5*sizeof(SimStruct));
    Reference_model_Control_Engineering_M->childSfunctions =
      (&Reference_model_Control_Engineering_M->NonInlinedSFcns.childSFunctionPtrs
       [0]);

    {
      int_T i;
      for (i = 0; i < 5; i++) {
        Reference_model_Control_Engineering_M->childSfunctions[i] =
          (&Reference_model_Control_Engineering_M->NonInlinedSFcns.childSFunctions
           [i]);
      }
    }

    /* Level2 S-Function Block: Reference_model_Control_Engineering/<S8>/S-Function (ec_Supervisor) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "Reference_model_Control_Engineering/Fourth Order Motion System/Ethercat Supervisor/S-Function");
      ssSetRTModel(rts,Reference_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_P.SFunction_P1_Size_k);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_P.SFunction_P2_Size);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering/<S7>/ec_Ebox (ec_Ebox) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = Reference_model_Control_Engineering_B.Saturation;
          sfcnUPtrs[1] = &Reference_model_Control_Engineering_B.Saturation[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = Reference_model_Control_Engineering_B.Gain;
          sfcnUPtrs[1] = &Reference_model_Control_Engineering_B.Gain[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.UPtrs2;

          {
            int_T i1;
            const real_T *u2 = Reference_model_Control_Engineering_B.Constant1;
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
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 3);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Reference_model_Control_Engineering_B.ec_Ebox_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 2);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            Reference_model_Control_Engineering_B.ec_Ebox_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 8);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            Reference_model_Control_Engineering_B.ec_Ebox_o3));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_Ebox");
      ssSetPath(rts,
                "Reference_model_Control_Engineering/Fourth Order Motion System/Ethercat E-box/ec_Ebox");
      ssSetRTModel(rts,Reference_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_P.ec_Ebox_P1_Size);
      }

      /* registration */
      ec_Ebox(rts);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering/<S6>/S-Function (ref3b) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [2]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_B.Startsetpoint;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Reference_model_Control_Engineering_B.SFunction_c));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "Reference_model_Control_Engineering/Subsystem/S-Function");
      ssSetRTModel(rts,Reference_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_P.SFunction_P1_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_DW.SFunction_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 50);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_DW.SFunction_RWORK[0]);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering/<S1>/Dctpd (dpd) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [3]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_B.Gain1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_B.Dctpd));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctpd");
      ssSetPath(rts,
                "Reference_model_Control_Engineering/Controller (motor side)/Dctpd");
      ssSetRTModel(rts,Reference_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_P.Dctpd_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_P.Dctpd_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_P.Dctpd_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_DW.Dctpd_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Reference_model_Control_Engineering_DW.Dctpd_RWORK[0]);
      }

      /* registration */
      dpd(rts);
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

    /* Level2 S-Function Block: Reference_model_Control_Engineering/<S1>/Dct2lowpass (dlowpass2) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod =
        Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset =
        Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap =
        Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Reference_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Reference_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Reference_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Reference_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Reference_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Reference_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Reference_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [4]);
        ssSetPeriodicStatesInfo(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &Reference_model_Control_Engineering_B.Dctpd;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Reference_model_Control_Engineering_B.Dct2lowpass));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass");
      ssSetPath(rts,
                "Reference_model_Control_Engineering/Controller (motor side)/Dct2lowpass");
      ssSetRTModel(rts,Reference_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Reference_model_Control_Engineering_P.Dct2lowpass_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Reference_model_Control_Engineering_P.Dct2lowpass_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Reference_model_Control_Engineering_P.Dct2lowpass_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Reference_model_Control_Engineering_DW.Dct2lowpass_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Reference_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Reference_model_Control_Engineering_DW.Dct2lowpass_RWORK[0]);
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

  /* Start for S-Function (ec_Supervisor): '<S8>/S-Function' */
  /* Level2 S-Function Block: '<S8>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S5>/Start setpoint' */
  Reference_model_Control_Engineering_B.Startsetpoint =
    Reference_model_Control_Engineering_P.Refpower_stat;

  /* Start for S-Function (dpd): '<S1>/Dctpd' */
  /* Level2 S-Function Block: '<S1>/Dctpd' (dpd) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass2): '<S1>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S1>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S2>/Constant1' */
  memcpy(&Reference_model_Control_Engineering_B.Constant1[0],
         &Reference_model_Control_Engineering_P.Constant1_Value[0], sizeof
         (real_T) << 3U);

  {
    FILE* a;
    real_T tmp;
    int32_T i;
    int32_T t;
    uint32_T tseed;

    /* InitializeConditions for RandomNumber: '<Root>/Noise' */
    tmp = floor(Reference_model_Control_Engineering_P.Noise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    Reference_model_Control_Engineering_DW.RandSeed = ((((tseed - ((uint32_T)i <<
      16U)) + t) << 16U) + t) + i;
    if (Reference_model_Control_Engineering_DW.RandSeed < 1U) {
      Reference_model_Control_Engineering_DW.RandSeed = 1144108930U;
    } else if (Reference_model_Control_Engineering_DW.RandSeed > 2147483646U) {
      Reference_model_Control_Engineering_DW.RandSeed = 2147483646U;
    }

    Reference_model_Control_Engineering_DW.NextOutput =
      rt_nrand_Upu32_Yd_f_pw_snf
      (&Reference_model_Control_Engineering_DW.RandSeed) *
      Reference_model_Control_Engineering_P.Noise_StdDev +
      Reference_model_Control_Engineering_P.Noise_Mean;

    /* End of InitializeConditions for RandomNumber: '<Root>/Noise' */

    /* InitializeConditions for S-Function (ref3b): '<S6>/S-Function' */
    /* Level2 S-Function Block: '<S6>/S-Function' (ref3b) */
    {
      SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[2];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* SystemInitialize for MATLAB Function: '<S3>/SPERTE_measurement_function' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Reference_model_Control_Engineering_DW.eml_autoflush[i] = false;
      Reference_model_Control_Engineering_DW.eml_openfiles[i] = a;
    }

    Reference_model_Control_Engineering_DW.NF = 0;
    Reference_model_Control_Engineering_DW.NS = 0U;
    Reference_model_Control_Engineering_DW.fileID = 0.0;
    Reference_model_Control_Engineering_DW.busy = 0U;

    /* End of SystemInitialize for MATLAB Function: '<S3>/SPERTE_measurement_function' */
  }
}

/* Model terminate function */
void Reference_model_Control_Engineering_terminate(void)
{
  /* Terminate for S-Function (ec_Supervisor): '<S8>/S-Function' */
  /* Level2 S-Function Block: '<S8>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ec_Ebox): '<S7>/ec_Ebox' */
  /* Level2 S-Function Block: '<S7>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ref3b): '<S6>/S-Function' */
  /* Level2 S-Function Block: '<S6>/S-Function' (ref3b) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dpd): '<S1>/Dctpd' */
  /* Level2 S-Function Block: '<S1>/Dctpd' (dpd) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S1>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S1>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = Reference_model_Control_Engineering_M->childSfunctions[4];
    sfcnTerminate(rts);
  }
}
