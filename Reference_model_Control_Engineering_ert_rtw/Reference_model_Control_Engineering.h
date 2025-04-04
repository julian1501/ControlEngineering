/*
 * Reference_model_Control_Engineering.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Reference_model_Control_Engineering".
 *
 * Model version              : 7.25
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Fri Apr  4 12:56:30 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Reference_model_Control_Engineering_h_
#define RTW_HEADER_Reference_model_Control_Engineering_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#ifndef Reference_model_Control_Engineering_COMMON_INCLUDES_
#define Reference_model_Control_Engineering_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                /* Reference_model_Control_Engineering_COMMON_INCLUDES_ */

#include "Reference_model_Control_Engineering_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T ec_Ebox_o2[2];                /* '<S10>/ec_Ebox' */
  real_T ec_Ebox_o3[8];                /* '<S10>/ec_Ebox' */
  real_T Buffer[3];                    /* '<S7>/Buffer' */
  real_T Saturation[2];                /* '<S10>/Saturation' */
  size_t bytesOutSizet;
  real32_T xout[2];
  FILE* filestar;
  FILE* filestar_m;
  real_T SFunction;                    /* '<S11>/S-Function' */
  real_T ec_Ebox_o1[2];                /* '<S10>/ec_Ebox' */
  real_T Gain2;                        /* '<S1>/Gain2' */
  real_T Dctnotch;                     /* '<S1>/Dctnotch' */
  real_T Dctintegrator;                /* '<S1>/Dctintegrator' */
  real_T Dctleadlag;                   /* '<S1>/Dctleadlag' */
  real_T Dct2lowpass;                  /* '<S1>/Dct2lowpass' */
  real_T Dctleadlag1;                  /* '<S1>/Dctleadlag1' */
  real_T Constant1[8];                 /* '<S4>/Constant1' */
  real_T Gain[2];                      /* '<S10>/Gain' */
  real_T Noise;                        /* '<Root>/Noise' */
  real_T Gain2_e;                      /* '<S2>/Gain2' */
  real_T Dctnotch_n;                   /* '<S2>/Dctnotch' */
  real_T Dctleadlag_j;                 /* '<S2>/Dctleadlag' */
  real_T Dctintegrator_c;              /* '<S2>/Dctintegrator' */
  real_T Startsetpoint;                /* '<S8>/Start setpoint' */
  real_T SFunction_c[3];               /* '<S9>/S-Function' */
  real_T Downsample[3];                /* '<S7>/Downsample' */
  real_T Clock;                        /* '<Root>/Clock' */
  real_T p;                            /* '<Root>/MATLAB Function' */
  real_T a;                            /* '<Root>/MATLAB Function' */
  real_T Sum1_p;                       /* '<Root>/Sum1' */
  real_T rtb_Saturation_idx_0;
  int32_T nbytes;
  uint32_T qY;
} B_Reference_model_Control_Engineering_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Downsample_Buffer[3];         /* '<S7>/Downsample' */
  real_T NextOutput;                   /* '<Root>/Noise' */
  real_T fileID;                       /* '<S6>/SPERTE_measurement_function' */
  real_T Dctnotch_RWORK[4];            /* '<S1>/Dctnotch' */
  real_T Dctintegrator_RWORK[2];       /* '<S1>/Dctintegrator' */
  real_T Dctleadlag_RWORK[2];          /* '<S1>/Dctleadlag' */
  real_T Dct2lowpass_RWORK[4];         /* '<S1>/Dct2lowpass' */
  real_T Dctleadlag1_RWORK[2];         /* '<S1>/Dctleadlag1' */
  real_T Dctnotch_RWORK_k[4];          /* '<S2>/Dctnotch' */
  real_T Dctleadlag_RWORK_k[2];        /* '<S2>/Dctleadlag' */
  real_T Dctintegrator_RWORK_a[2];     /* '<S2>/Dctintegrator' */
  real_T SFunction_RWORK[50];          /* '<S9>/S-Function' */
  struct {
    void *LoggedData;
  } Live_Scope_PWORK;                  /* '<S7>/Live_Scope' */

  uint32_T RandSeed;                   /* '<Root>/Noise' */
  uint32_T NS;                         /* '<S6>/SPERTE_measurement_function' */
  int16_T NF;                          /* '<S6>/SPERTE_measurement_function' */
  uint8_T busy;                        /* '<S6>/SPERTE_measurement_function' */
  boolean_T eml_autoflush[20];         /* '<S6>/SPERTE_measurement_function' */
  FILE* eml_openfiles[20];             /* '<S6>/SPERTE_measurement_function' */
} DW_Reference_model_Control_Engineering_T;

/* Parameters (default storage) */
struct P_Reference_model_Control_Engineering_T_ {
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S9>/S-Function'
                                        */
  real_T ref_part[12];                 /* Variable: ref_part
                                        * Referenced by: '<S9>/S-Function'
                                        */
  real_T Refpower_stat;                /* Mask Parameter: Refpower_stat
                                        * Referenced by: '<S8>/Start setpoint'
                                        */
  uint32_T MeasurementBlock_N_samples;
                                   /* Mask Parameter: MeasurementBlock_N_samples
                                    * Referenced by: '<S6>/SPERTE_measurement_samples'
                                    */
  uint8_T MeasurementBlock_trigger_comman;
                              /* Mask Parameter: MeasurementBlock_trigger_comman
                               * Referenced by: '<S6>/SPERTE_measurement_trigger_command'
                               */
  uint8_T MeasurementBlock_triggertype;
                                 /* Mask Parameter: MeasurementBlock_triggertype
                                  * Referenced by: '<S6>/SPERTE_measurement_function'
                                  */
  real_T SFunction_P1_Size_k[2];      /* Computed Parameter: SFunction_P1_Size_k
                                       * Referenced by: '<S11>/S-Function'
                                       */
  real_T SFunction_P1;                 /* Expression: portid
                                        * Referenced by: '<S11>/S-Function'
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S11>/S-Function'
                                        */
  real_T SFunction_P2;                 /* Expression: ectimeout
                                        * Referenced by: '<S11>/S-Function'
                                        */
  real_T ec_Ebox_P1_Size[2];           /* Computed Parameter: ec_Ebox_P1_Size
                                        * Referenced by: '<S10>/ec_Ebox'
                                        */
  real_T ec_Ebox_P1;                   /* Expression: link_id
                                        * Referenced by: '<S10>/ec_Ebox'
                                        */
  real_T count2rad_Gain;               /* Expression: (2*pi)/(4*500)
                                        * Referenced by: '<S4>/count2rad'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Quantizer1_Interval;          /* Expression: (2*pi)/(500*4)
                                        * Referenced by: '<Root>/Quantizer1'
                                        */
  real_T Gain2_Gain;                   /* Expression: -0.8
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T Dctnotch_P1_Size[2];          /* Computed Parameter: Dctnotch_P1_Size
                                        * Referenced by: '<S1>/Dctnotch'
                                        */
  real_T Dctnotch_P1;                  /* Expression: f_num
                                        * Referenced by: '<S1>/Dctnotch'
                                        */
  real_T Dctnotch_P2_Size[2];          /* Computed Parameter: Dctnotch_P2_Size
                                        * Referenced by: '<S1>/Dctnotch'
                                        */
  real_T Dctnotch_P2;                  /* Expression: b_num
                                        * Referenced by: '<S1>/Dctnotch'
                                        */
  real_T Dctnotch_P3_Size[2];          /* Computed Parameter: Dctnotch_P3_Size
                                        * Referenced by: '<S1>/Dctnotch'
                                        */
  real_T Dctnotch_P3;                  /* Expression: f_den
                                        * Referenced by: '<S1>/Dctnotch'
                                        */
  real_T Dctnotch_P4_Size[2];          /* Computed Parameter: Dctnotch_P4_Size
                                        * Referenced by: '<S1>/Dctnotch'
                                        */
  real_T Dctnotch_P4;                  /* Expression: b_den
                                        * Referenced by: '<S1>/Dctnotch'
                                        */
  real_T Dctnotch_P5_Size[2];          /* Computed Parameter: Dctnotch_P5_Size
                                        * Referenced by: '<S1>/Dctnotch'
                                        */
  real_T Dctnotch_P5;                  /* Expression: 0.001
                                        * Referenced by: '<S1>/Dctnotch'
                                        */
  real_T Dctintegrator_P1_Size[2];  /* Computed Parameter: Dctintegrator_P1_Size
                                     * Referenced by: '<S1>/Dctintegrator'
                                     */
  real_T Dctintegrator_P1;             /* Expression: f_num
                                        * Referenced by: '<S1>/Dctintegrator'
                                        */
  real_T Dctintegrator_P2_Size[2];  /* Computed Parameter: Dctintegrator_P2_Size
                                     * Referenced by: '<S1>/Dctintegrator'
                                     */
  real_T Dctintegrator_P2;             /* Expression: 0.001
                                        * Referenced by: '<S1>/Dctintegrator'
                                        */
  real_T Dctleadlag_P1_Size[2];        /* Computed Parameter: Dctleadlag_P1_Size
                                        * Referenced by: '<S1>/Dctleadlag'
                                        */
  real_T Dctleadlag_P1;                /* Expression: f_num
                                        * Referenced by: '<S1>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size[2];        /* Computed Parameter: Dctleadlag_P2_Size
                                        * Referenced by: '<S1>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2;                /* Expression: f_den
                                        * Referenced by: '<S1>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size[2];        /* Computed Parameter: Dctleadlag_P3_Size
                                        * Referenced by: '<S1>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3;                /* Expression: 0.001
                                        * Referenced by: '<S1>/Dctleadlag'
                                        */
  real_T Dct2lowpass_P1_Size[2];      /* Computed Parameter: Dct2lowpass_P1_Size
                                       * Referenced by: '<S1>/Dct2lowpass'
                                       */
  real_T Dct2lowpass_P1;               /* Expression: f_den
                                        * Referenced by: '<S1>/Dct2lowpass'
                                        */
  real_T Dct2lowpass_P2_Size[2];      /* Computed Parameter: Dct2lowpass_P2_Size
                                       * Referenced by: '<S1>/Dct2lowpass'
                                       */
  real_T Dct2lowpass_P2;               /* Expression: b_den
                                        * Referenced by: '<S1>/Dct2lowpass'
                                        */
  real_T Dct2lowpass_P3_Size[2];      /* Computed Parameter: Dct2lowpass_P3_Size
                                       * Referenced by: '<S1>/Dct2lowpass'
                                       */
  real_T Dct2lowpass_P3;               /* Expression: 0.001
                                        * Referenced by: '<S1>/Dct2lowpass'
                                        */
  real_T Dctleadlag1_P1_Size[2];      /* Computed Parameter: Dctleadlag1_P1_Size
                                       * Referenced by: '<S1>/Dctleadlag1'
                                       */
  real_T Dctleadlag1_P1;               /* Expression: f_num
                                        * Referenced by: '<S1>/Dctleadlag1'
                                        */
  real_T Dctleadlag1_P2_Size[2];      /* Computed Parameter: Dctleadlag1_P2_Size
                                       * Referenced by: '<S1>/Dctleadlag1'
                                       */
  real_T Dctleadlag1_P2;               /* Expression: f_den
                                        * Referenced by: '<S1>/Dctleadlag1'
                                        */
  real_T Dctleadlag1_P3_Size[2];      /* Computed Parameter: Dctleadlag1_P3_Size
                                       * Referenced by: '<S1>/Dctleadlag1'
                                       */
  real_T Dctleadlag1_P3;               /* Expression: 0.001
                                        * Referenced by: '<S1>/Dctleadlag1'
                                        */
  real_T Ka_Gain;                      /* Expression: 0.00009
                                        * Referenced by: '<S3>/Ka'
                                        */
  real_T Kfc_Gain;                     /* Expression: 0
                                        * Referenced by: '<S3>/Kfc'
                                        */
  real_T Kv_Gain;                      /* Expression: 0.002
                                        * Referenced by: '<S3>/Kv'
                                        */
  real_T Constant_Value[2];            /* Expression: [0,0]
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant1_Value[8];           /* Expression: [0,0,0,0,0,0,0,0]
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 1/100
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Noise_Mean;                   /* Expression: 0
                                        * Referenced by: '<Root>/Noise'
                                        */
  real_T Noise_StdDev;                 /* Computed Parameter: Noise_StdDev
                                        * Referenced by: '<Root>/Noise'
                                        */
  real_T Noise_Seed;                   /* Expression: 0
                                        * Referenced by: '<Root>/Noise'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 2.5
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -2.5
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 10
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: -10
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Gain2_Gain_h;                 /* Expression: 4.06
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T Dctnotch_P1_Size_f[2];        /* Computed Parameter: Dctnotch_P1_Size_f
                                        * Referenced by: '<S2>/Dctnotch'
                                        */
  real_T Dctnotch_P1_g;                /* Expression: f_num
                                        * Referenced by: '<S2>/Dctnotch'
                                        */
  real_T Dctnotch_P2_Size_k[2];        /* Computed Parameter: Dctnotch_P2_Size_k
                                        * Referenced by: '<S2>/Dctnotch'
                                        */
  real_T Dctnotch_P2_a;                /* Expression: b_num
                                        * Referenced by: '<S2>/Dctnotch'
                                        */
  real_T Dctnotch_P3_Size_j[2];        /* Computed Parameter: Dctnotch_P3_Size_j
                                        * Referenced by: '<S2>/Dctnotch'
                                        */
  real_T Dctnotch_P3_i;                /* Expression: f_den
                                        * Referenced by: '<S2>/Dctnotch'
                                        */
  real_T Dctnotch_P4_Size_n[2];        /* Computed Parameter: Dctnotch_P4_Size_n
                                        * Referenced by: '<S2>/Dctnotch'
                                        */
  real_T Dctnotch_P4_k;                /* Expression: b_den
                                        * Referenced by: '<S2>/Dctnotch'
                                        */
  real_T Dctnotch_P5_Size_e[2];        /* Computed Parameter: Dctnotch_P5_Size_e
                                        * Referenced by: '<S2>/Dctnotch'
                                        */
  real_T Dctnotch_P5_e;                /* Expression: 0.001
                                        * Referenced by: '<S2>/Dctnotch'
                                        */
  real_T Dctleadlag_P1_Size_k[2];    /* Computed Parameter: Dctleadlag_P1_Size_k
                                      * Referenced by: '<S2>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_e;              /* Expression: f_num
                                        * Referenced by: '<S2>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_d[2];    /* Computed Parameter: Dctleadlag_P2_Size_d
                                      * Referenced by: '<S2>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_k;              /* Expression: f_den
                                        * Referenced by: '<S2>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_p[2];    /* Computed Parameter: Dctleadlag_P3_Size_p
                                      * Referenced by: '<S2>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_i;              /* Expression: 0.001
                                        * Referenced by: '<S2>/Dctleadlag'
                                        */
  real_T Dctintegrator_P1_Size_b[2];
                                  /* Computed Parameter: Dctintegrator_P1_Size_b
                                   * Referenced by: '<S2>/Dctintegrator'
                                   */
  real_T Dctintegrator_P1_m;           /* Expression: f_num
                                        * Referenced by: '<S2>/Dctintegrator'
                                        */
  real_T Dctintegrator_P2_Size_l[2];
                                  /* Computed Parameter: Dctintegrator_P2_Size_l
                                   * Referenced by: '<S2>/Dctintegrator'
                                   */
  real_T Dctintegrator_P2_n;           /* Expression: 0.001
                                        * Referenced by: '<S2>/Dctintegrator'
                                        */
  uint8_T Selectencoder_CurrentSetting;
                             /* Computed Parameter: Selectencoder_CurrentSetting
                              * Referenced by: '<Root>/Select encoder'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_Reference_model_Control_Engineering_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[3];
    SimStruct childSFunctions[11];
    SimStruct *childSFunctionPtrs[11];
    struct _ssBlkInfo2 blkInfo2[11];
    struct _ssSFcnModelMethods2 methods2[11];
    struct _ssSFcnModelMethods3 methods3[11];
    struct _ssSFcnModelMethods4 methods4[11];
    struct _ssStatesInfo2 statesInfo2[11];
    ssPeriodicStatesInfo periodicStatesInfo[11];
    struct _ssPortInfo2 inputOutputPortInfo2[11];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[3];
      struct _ssInPortUnit inputPortUnits[3];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[3];
      real_T const *UPtrs0[2];
      real_T const *UPtrs1[2];
      real_T const *UPtrs2[8];
      struct _ssPortOutputs outputPortInfo[3];
      struct _ssOutPortUnit outputPortUnits[3];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[3];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn10;
  } NonInlinedSFcns;

  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Reference_model_Control_Engineering_T
  Reference_model_Control_Engineering_P;

/* Block signals (default storage) */
extern B_Reference_model_Control_Engineering_T
  Reference_model_Control_Engineering_B;

/* Block states (default storage) */
extern DW_Reference_model_Control_Engineering_T
  Reference_model_Control_Engineering_DW;

/* External data declarations for dependent source files */
extern const real_T Reference_model_Control_Engineering_RGND;/* real_T ground */

/* External function called from main */
extern void Reference_model_Control_Engineering_SetEventsForThisBaseStep
  (boolean_T *eventFlags);

/* Model entry point functions */
extern void Reference_model_Control_Engineering_SetEventsForThisBaseStep
  (boolean_T *eventFlags);
extern void Reference_model_Control_Engineering_initialize(void);
extern void Reference_model_Control_Engineering_step0(void);
extern void Reference_model_Control_Engineering_step2(void);
extern void Reference_model_Control_Engineering_step(int_T tid);
extern void Reference_model_Control_Engineering_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Reference_model_Control_Engineering_T *const
  Reference_model_Control_Engineering_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Reference_model_Control_Engineering'
 * '<S1>'   : 'Reference_model_Control_Engineering/Controller (load side)'
 * '<S2>'   : 'Reference_model_Control_Engineering/Controller (motor side)'
 * '<S3>'   : 'Reference_model_Control_Engineering/Feedforward'
 * '<S4>'   : 'Reference_model_Control_Engineering/Fourth Order Motion System'
 * '<S5>'   : 'Reference_model_Control_Engineering/MATLAB Function'
 * '<S6>'   : 'Reference_model_Control_Engineering/Measurement Block'
 * '<S7>'   : 'Reference_model_Control_Engineering/Real-time scope'
 * '<S8>'   : 'Reference_model_Control_Engineering/Ref power'
 * '<S9>'   : 'Reference_model_Control_Engineering/Subsystem'
 * '<S10>'  : 'Reference_model_Control_Engineering/Fourth Order Motion System/Ethercat E-box'
 * '<S11>'  : 'Reference_model_Control_Engineering/Fourth Order Motion System/Ethercat Supervisor'
 * '<S12>'  : 'Reference_model_Control_Engineering/Measurement Block/SPERTE_measurement_function'
 */
#endif                   /* RTW_HEADER_Reference_model_Control_Engineering_h_ */
