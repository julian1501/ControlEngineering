/*
 * Reference_model_Control_Engineering_4.h
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

#ifndef RTW_HEADER_Reference_model_Control_Engineering_4_h_
#define RTW_HEADER_Reference_model_Control_Engineering_4_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#ifndef Reference_model_Control_Engineering_4_COMMON_INCLUDES_
#define Reference_model_Control_Engineering_4_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#endif              /* Reference_model_Control_Engineering_4_COMMON_INCLUDES_ */

#include "Reference_model_Control_Engineering_4_types.h"

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
  real_T Startsetpoint;                /* '<S5>/Start setpoint' */
  real_T SFunction[3];                 /* '<S6>/S-Function' */
  real_T Quantizer1;                   /* '<Root>/Quantizer1' */
  real_T SFunction_b;                  /* '<S14>/S-Function' */
  real_T ec_Ebox_o1[2];                /* '<S13>/ec_Ebox' */
  real_T ec_Ebox_o2[2];                /* '<S13>/ec_Ebox' */
  real_T ec_Ebox_o3[8];                /* '<S13>/ec_Ebox' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T Buffer[3];                    /* '<S4>/Buffer' */
  real_T TmpSignalConversionAtToWorkspac[2];
  real_T Constant1[8];                 /* '<S2>/Constant1' */
  real_T Gain[2];                      /* '<S13>/Gain' */
  real_T Gain5;                        /* '<S11>/Gain5' */
  real_T Dctnotch8;                    /* '<S11>/Dctnotch8' */
  real_T Dctleadlag4;                  /* '<S11>/Dctleadlag4' */
  real_T Dctnotch9;                    /* '<S11>/Dctnotch9' */
  real_T Dctdoubleintegrator4;         /* '<S11>/Dctdoubleintegrator4' */
  real_T Dct2lowpass4;                 /* '<S11>/Dct2lowpass4' */
  real_T Noise;                        /* '<Root>/Noise' */
  real_T Saturation[2];                /* '<S13>/Saturation' */
  real_T Gain2;                        /* '<S7>/Gain2' */
  real_T Dctnotch;                     /* '<S7>/Dctnotch' */
  real_T Dctleadlag;                   /* '<S7>/Dctleadlag' */
  real_T Dctnotch2;                    /* '<S7>/Dctnotch2' */
  real_T Dctdoubleintegrator6;         /* '<S7>/Dctdoubleintegrator6' */
  real_T Dct2lowpass;                  /* '<S7>/Dct2lowpass' */
  real_T Gain2_d;                      /* '<S8>/Gain2' */
  real_T Dctnotch_c;                   /* '<S8>/Dctnotch' */
  real_T Dctleadlag_g;                 /* '<S8>/Dctleadlag' */
  real_T Dctnotch2_n;                  /* '<S8>/Dctnotch2' */
  real_T Dctdoubleintegrator6_j;       /* '<S8>/Dctdoubleintegrator6' */
  real_T Dct2lowpass_a;                /* '<S8>/Dct2lowpass' */
  real_T Gain2_k;                      /* '<S9>/Gain2' */
  real_T Dctnotch_p;                   /* '<S9>/Dctnotch' */
  real_T Dctleadlag_a;                 /* '<S9>/Dctleadlag' */
  real_T Dctnotch2_m;                  /* '<S9>/Dctnotch2' */
  real_T Dctdoubleintegrator6_g;       /* '<S9>/Dctdoubleintegrator6' */
  real_T Dct2lowpass_b;                /* '<S9>/Dct2lowpass' */
  real_T Gain2_m;                      /* '<S10>/Gain2' */
  real_T Dctnotch_m;                   /* '<S10>/Dctnotch' */
  real_T Dctleadlag_n;                 /* '<S10>/Dctleadlag' */
  real_T Dctnotch2_c;                  /* '<S10>/Dctnotch2' */
  real_T Dctdoubleintegrator6_l;       /* '<S10>/Dctdoubleintegrator6' */
  real_T Dct2lowpass_a4;               /* '<S10>/Dct2lowpass' */
  real_T Gain2_kd;                     /* '<S12>/Gain2' */
  real_T Dctnotch_d;                   /* '<S12>/Dctnotch' */
  real_T Dctleadlag_i;                 /* '<S12>/Dctleadlag' */
  real_T Dctnotch2_k;                  /* '<S12>/Dctnotch2' */
  real_T Dctdoubleintegrator6_n;       /* '<S12>/Dctdoubleintegrator6' */
  real_T Dct2lowpass_j;                /* '<S12>/Dct2lowpass' */
  real_T Downsample[3];                /* '<S4>/Downsample' */
  size_t bytesOutSizet;
  real32_T xout[2];
  FILE* filestar;
  FILE* filestar_m;
  real_T u0;
  int32_T nbytes;
  int32_T loop_ub;
} B_Reference_model_Control_Engineering_4_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Downsample_Buffer[3];         /* '<S4>/Downsample' */
  real_T NextOutput;                   /* '<Root>/Noise' */
  real_T fileID;                       /* '<S3>/SPERTE_measurement_function' */
  real_T SFunction_RWORK[50];          /* '<S6>/S-Function' */
  real_T Dctnotch8_RWORK[4];           /* '<S11>/Dctnotch8' */
  real_T Dctleadlag4_RWORK[2];         /* '<S11>/Dctleadlag4' */
  real_T Dctnotch9_RWORK[4];           /* '<S11>/Dctnotch9' */
  real_T Dctdoubleintegrator4_RWORK[4];/* '<S11>/Dctdoubleintegrator4' */
  real_T Dct2lowpass4_RWORK[4];        /* '<S11>/Dct2lowpass4' */
  real_T Dctnotch_RWORK[4];            /* '<S7>/Dctnotch' */
  real_T Dctleadlag_RWORK[2];          /* '<S7>/Dctleadlag' */
  real_T Dctnotch2_RWORK[4];           /* '<S7>/Dctnotch2' */
  real_T Dctdoubleintegrator6_RWORK[4];/* '<S7>/Dctdoubleintegrator6' */
  real_T Dct2lowpass_RWORK[4];         /* '<S7>/Dct2lowpass' */
  real_T Dctnotch_RWORK_e[4];          /* '<S8>/Dctnotch' */
  real_T Dctleadlag_RWORK_c[2];        /* '<S8>/Dctleadlag' */
  real_T Dctnotch2_RWORK_g[4];         /* '<S8>/Dctnotch2' */
  real_T Dctdoubleintegrator6_RWORK_n[4];/* '<S8>/Dctdoubleintegrator6' */
  real_T Dct2lowpass_RWORK_g[4];       /* '<S8>/Dct2lowpass' */
  real_T Dctnotch_RWORK_c[4];          /* '<S9>/Dctnotch' */
  real_T Dctleadlag_RWORK_g[2];        /* '<S9>/Dctleadlag' */
  real_T Dctnotch2_RWORK_o[4];         /* '<S9>/Dctnotch2' */
  real_T Dctdoubleintegrator6_RWORK_f[4];/* '<S9>/Dctdoubleintegrator6' */
  real_T Dct2lowpass_RWORK_m[4];       /* '<S9>/Dct2lowpass' */
  real_T Dctnotch_RWORK_o[4];          /* '<S10>/Dctnotch' */
  real_T Dctleadlag_RWORK_b[2];        /* '<S10>/Dctleadlag' */
  real_T Dctnotch2_RWORK_i[4];         /* '<S10>/Dctnotch2' */
  real_T Dctdoubleintegrator6_RWORK_k[4];/* '<S10>/Dctdoubleintegrator6' */
  real_T Dct2lowpass_RWORK_f[4];       /* '<S10>/Dct2lowpass' */
  real_T Dctnotch_RWORK_p[4];          /* '<S12>/Dctnotch' */
  real_T Dctleadlag_RWORK_m[2];        /* '<S12>/Dctleadlag' */
  real_T Dctnotch2_RWORK_f[4];         /* '<S12>/Dctnotch2' */
  real_T Dctdoubleintegrator6_RWORK_m[4];/* '<S12>/Dctdoubleintegrator6' */
  real_T Dct2lowpass_RWORK_i[4];       /* '<S12>/Dct2lowpass' */
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  struct {
    void *LoggedData;
  } Live_Scope_PWORK;                  /* '<S4>/Live_Scope' */

  uint32_T RandSeed;                   /* '<Root>/Noise' */
  uint32_T NS;                         /* '<S3>/SPERTE_measurement_function' */
  int16_T NF;                          /* '<S3>/SPERTE_measurement_function' */
  uint8_T busy;                        /* '<S3>/SPERTE_measurement_function' */
  boolean_T eml_autoflush[20];         /* '<S3>/SPERTE_measurement_function' */
  FILE* eml_openfiles[20];             /* '<S3>/SPERTE_measurement_function' */
} DW_Reference_model_Control_Engineering_4_T;

/* Parameters (default storage) */
struct P_Reference_model_Control_Engineering_4_T_ {
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S6>/S-Function'
                                        */
  real_T ref_part[12];                 /* Variable: ref_part
                                        * Referenced by: '<S6>/S-Function'
                                        */
  real_T Refpower_stat;                /* Mask Parameter: Refpower_stat
                                        * Referenced by: '<S5>/Start setpoint'
                                        */
  uint32_T MeasurementBlock_N_samples;
                                   /* Mask Parameter: MeasurementBlock_N_samples
                                    * Referenced by: '<S3>/SPERTE_measurement_samples'
                                    */
  uint8_T MeasurementBlock_trigger_comman;
                              /* Mask Parameter: MeasurementBlock_trigger_comman
                               * Referenced by: '<S3>/SPERTE_measurement_trigger_command'
                               */
  uint8_T MeasurementBlock_triggertype;
                                 /* Mask Parameter: MeasurementBlock_triggertype
                                  * Referenced by: '<S3>/SPERTE_measurement_function'
                                  */
  real_T count2rad_Gain;               /* Expression: (2*pi)/(4*500)
                                        * Referenced by: '<S2>/count2rad'
                                        */
  real_T Quantizer1_Interval;          /* Expression: (2*pi)/(500*4)
                                        * Referenced by: '<Root>/Quantizer1'
                                        */
  real_T SFunction_P1_Size_k[2];      /* Computed Parameter: SFunction_P1_Size_k
                                       * Referenced by: '<S14>/S-Function'
                                       */
  real_T SFunction_P1;                 /* Expression: portid
                                        * Referenced by: '<S14>/S-Function'
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S14>/S-Function'
                                        */
  real_T SFunction_P2;                 /* Expression: ectimeout
                                        * Referenced by: '<S14>/S-Function'
                                        */
  real_T ec_Ebox_P1_Size[2];           /* Computed Parameter: ec_Ebox_P1_Size
                                        * Referenced by: '<S13>/ec_Ebox'
                                        */
  real_T ec_Ebox_P1;                   /* Expression: link_id
                                        * Referenced by: '<S13>/ec_Ebox'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1e-3
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Ka_Gain;                      /* Expression: -0.00034
                                        * Referenced by: '<S1>/Ka'
                                        */
  real_T Kfc_Gain;                     /* Expression: -0.0395
                                        * Referenced by: '<S1>/Kfc'
                                        */
  real_T Kv_Gain;                      /* Expression: 0
                                        * Referenced by: '<S1>/Kv'
                                        */
  real_T Constant_Value[2];            /* Expression: [0,0]
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant1_Value[8];           /* Expression: [0,0,0,0,0,0,0,0]
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/100
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Gain5_Gain;                   /* Expression: -1.178
                                        * Referenced by: '<S11>/Gain5'
                                        */
  real_T Dctnotch8_P1_Size[2];         /* Computed Parameter: Dctnotch8_P1_Size
                                        * Referenced by: '<S11>/Dctnotch8'
                                        */
  real_T Dctnotch8_P1;                 /* Expression: f_num
                                        * Referenced by: '<S11>/Dctnotch8'
                                        */
  real_T Dctnotch8_P2_Size[2];         /* Computed Parameter: Dctnotch8_P2_Size
                                        * Referenced by: '<S11>/Dctnotch8'
                                        */
  real_T Dctnotch8_P2;                 /* Expression: b_num
                                        * Referenced by: '<S11>/Dctnotch8'
                                        */
  real_T Dctnotch8_P3_Size[2];         /* Computed Parameter: Dctnotch8_P3_Size
                                        * Referenced by: '<S11>/Dctnotch8'
                                        */
  real_T Dctnotch8_P3;                 /* Expression: f_den
                                        * Referenced by: '<S11>/Dctnotch8'
                                        */
  real_T Dctnotch8_P4_Size[2];         /* Computed Parameter: Dctnotch8_P4_Size
                                        * Referenced by: '<S11>/Dctnotch8'
                                        */
  real_T Dctnotch8_P4;                 /* Expression: b_den
                                        * Referenced by: '<S11>/Dctnotch8'
                                        */
  real_T Dctnotch8_P5_Size[2];         /* Computed Parameter: Dctnotch8_P5_Size
                                        * Referenced by: '<S11>/Dctnotch8'
                                        */
  real_T Dctnotch8_P5;                 /* Expression: 0.001
                                        * Referenced by: '<S11>/Dctnotch8'
                                        */
  real_T Dctleadlag4_P1_Size[2];      /* Computed Parameter: Dctleadlag4_P1_Size
                                       * Referenced by: '<S11>/Dctleadlag4'
                                       */
  real_T Dctleadlag4_P1;               /* Expression: f_num
                                        * Referenced by: '<S11>/Dctleadlag4'
                                        */
  real_T Dctleadlag4_P2_Size[2];      /* Computed Parameter: Dctleadlag4_P2_Size
                                       * Referenced by: '<S11>/Dctleadlag4'
                                       */
  real_T Dctleadlag4_P2;               /* Expression: f_den
                                        * Referenced by: '<S11>/Dctleadlag4'
                                        */
  real_T Dctleadlag4_P3_Size[2];      /* Computed Parameter: Dctleadlag4_P3_Size
                                       * Referenced by: '<S11>/Dctleadlag4'
                                       */
  real_T Dctleadlag4_P3;               /* Expression: 0.001
                                        * Referenced by: '<S11>/Dctleadlag4'
                                        */
  real_T Dctnotch9_P1_Size[2];         /* Computed Parameter: Dctnotch9_P1_Size
                                        * Referenced by: '<S11>/Dctnotch9'
                                        */
  real_T Dctnotch9_P1;                 /* Expression: f_num
                                        * Referenced by: '<S11>/Dctnotch9'
                                        */
  real_T Dctnotch9_P2_Size[2];         /* Computed Parameter: Dctnotch9_P2_Size
                                        * Referenced by: '<S11>/Dctnotch9'
                                        */
  real_T Dctnotch9_P2;                 /* Expression: b_num
                                        * Referenced by: '<S11>/Dctnotch9'
                                        */
  real_T Dctnotch9_P3_Size[2];         /* Computed Parameter: Dctnotch9_P3_Size
                                        * Referenced by: '<S11>/Dctnotch9'
                                        */
  real_T Dctnotch9_P3;                 /* Expression: f_den
                                        * Referenced by: '<S11>/Dctnotch9'
                                        */
  real_T Dctnotch9_P4_Size[2];         /* Computed Parameter: Dctnotch9_P4_Size
                                        * Referenced by: '<S11>/Dctnotch9'
                                        */
  real_T Dctnotch9_P4;                 /* Expression: b_den
                                        * Referenced by: '<S11>/Dctnotch9'
                                        */
  real_T Dctnotch9_P5_Size[2];         /* Computed Parameter: Dctnotch9_P5_Size
                                        * Referenced by: '<S11>/Dctnotch9'
                                        */
  real_T Dctnotch9_P5;                 /* Expression: 0.001
                                        * Referenced by: '<S11>/Dctnotch9'
                                        */
  real_T Dctdoubleintegrator4_P1_Size[2];
                             /* Computed Parameter: Dctdoubleintegrator4_P1_Size
                              * Referenced by: '<S11>/Dctdoubleintegrator4'
                              */
  real_T Dctdoubleintegrator4_P1;      /* Expression: f_num
                                        * Referenced by: '<S11>/Dctdoubleintegrator4'
                                        */
  real_T Dctdoubleintegrator4_P2_Size[2];
                             /* Computed Parameter: Dctdoubleintegrator4_P2_Size
                              * Referenced by: '<S11>/Dctdoubleintegrator4'
                              */
  real_T Dctdoubleintegrator4_P2;      /* Expression: b_num
                                        * Referenced by: '<S11>/Dctdoubleintegrator4'
                                        */
  real_T Dctdoubleintegrator4_P3_Size[2];
                             /* Computed Parameter: Dctdoubleintegrator4_P3_Size
                              * Referenced by: '<S11>/Dctdoubleintegrator4'
                              */
  real_T Dctdoubleintegrator4_P3;      /* Expression: 0.001
                                        * Referenced by: '<S11>/Dctdoubleintegrator4'
                                        */
  real_T Dct2lowpass4_P1_Size[2];    /* Computed Parameter: Dct2lowpass4_P1_Size
                                      * Referenced by: '<S11>/Dct2lowpass4'
                                      */
  real_T Dct2lowpass4_P1;              /* Expression: f_den
                                        * Referenced by: '<S11>/Dct2lowpass4'
                                        */
  real_T Dct2lowpass4_P2_Size[2];    /* Computed Parameter: Dct2lowpass4_P2_Size
                                      * Referenced by: '<S11>/Dct2lowpass4'
                                      */
  real_T Dct2lowpass4_P2;              /* Expression: b_den
                                        * Referenced by: '<S11>/Dct2lowpass4'
                                        */
  real_T Dct2lowpass4_P3_Size[2];    /* Computed Parameter: Dct2lowpass4_P3_Size
                                      * Referenced by: '<S11>/Dct2lowpass4'
                                      */
  real_T Dct2lowpass4_P3;              /* Expression: 0.001
                                        * Referenced by: '<S11>/Dct2lowpass4'
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
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -2.5
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 10
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: -10
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Gain2_Gain;                   /* Expression: -0.998
                                        * Referenced by: '<S7>/Gain2'
                                        */
  real_T Dctnotch_P1_Size[2];          /* Computed Parameter: Dctnotch_P1_Size
                                        * Referenced by: '<S7>/Dctnotch'
                                        */
  real_T Dctnotch_P1;                  /* Expression: f_num
                                        * Referenced by: '<S7>/Dctnotch'
                                        */
  real_T Dctnotch_P2_Size[2];          /* Computed Parameter: Dctnotch_P2_Size
                                        * Referenced by: '<S7>/Dctnotch'
                                        */
  real_T Dctnotch_P2;                  /* Expression: b_num
                                        * Referenced by: '<S7>/Dctnotch'
                                        */
  real_T Dctnotch_P3_Size[2];          /* Computed Parameter: Dctnotch_P3_Size
                                        * Referenced by: '<S7>/Dctnotch'
                                        */
  real_T Dctnotch_P3;                  /* Expression: f_den
                                        * Referenced by: '<S7>/Dctnotch'
                                        */
  real_T Dctnotch_P4_Size[2];          /* Computed Parameter: Dctnotch_P4_Size
                                        * Referenced by: '<S7>/Dctnotch'
                                        */
  real_T Dctnotch_P4;                  /* Expression: b_den
                                        * Referenced by: '<S7>/Dctnotch'
                                        */
  real_T Dctnotch_P5_Size[2];          /* Computed Parameter: Dctnotch_P5_Size
                                        * Referenced by: '<S7>/Dctnotch'
                                        */
  real_T Dctnotch_P5;                  /* Expression: 0.001
                                        * Referenced by: '<S7>/Dctnotch'
                                        */
  real_T Dctleadlag_P1_Size[2];        /* Computed Parameter: Dctleadlag_P1_Size
                                        * Referenced by: '<S7>/Dctleadlag'
                                        */
  real_T Dctleadlag_P1;                /* Expression: f_num
                                        * Referenced by: '<S7>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size[2];        /* Computed Parameter: Dctleadlag_P2_Size
                                        * Referenced by: '<S7>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2;                /* Expression: f_den
                                        * Referenced by: '<S7>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size[2];        /* Computed Parameter: Dctleadlag_P3_Size
                                        * Referenced by: '<S7>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3;                /* Expression: 0.001
                                        * Referenced by: '<S7>/Dctleadlag'
                                        */
  real_T Dctnotch2_P1_Size[2];         /* Computed Parameter: Dctnotch2_P1_Size
                                        * Referenced by: '<S7>/Dctnotch2'
                                        */
  real_T Dctnotch2_P1;                 /* Expression: f_num
                                        * Referenced by: '<S7>/Dctnotch2'
                                        */
  real_T Dctnotch2_P2_Size[2];         /* Computed Parameter: Dctnotch2_P2_Size
                                        * Referenced by: '<S7>/Dctnotch2'
                                        */
  real_T Dctnotch2_P2;                 /* Expression: b_num
                                        * Referenced by: '<S7>/Dctnotch2'
                                        */
  real_T Dctnotch2_P3_Size[2];         /* Computed Parameter: Dctnotch2_P3_Size
                                        * Referenced by: '<S7>/Dctnotch2'
                                        */
  real_T Dctnotch2_P3;                 /* Expression: f_den
                                        * Referenced by: '<S7>/Dctnotch2'
                                        */
  real_T Dctnotch2_P4_Size[2];         /* Computed Parameter: Dctnotch2_P4_Size
                                        * Referenced by: '<S7>/Dctnotch2'
                                        */
  real_T Dctnotch2_P4;                 /* Expression: b_den
                                        * Referenced by: '<S7>/Dctnotch2'
                                        */
  real_T Dctnotch2_P5_Size[2];         /* Computed Parameter: Dctnotch2_P5_Size
                                        * Referenced by: '<S7>/Dctnotch2'
                                        */
  real_T Dctnotch2_P5;                 /* Expression: 0.001
                                        * Referenced by: '<S7>/Dctnotch2'
                                        */
  real_T Dctdoubleintegrator6_P1_Size[2];
                             /* Computed Parameter: Dctdoubleintegrator6_P1_Size
                              * Referenced by: '<S7>/Dctdoubleintegrator6'
                              */
  real_T Dctdoubleintegrator6_P1;      /* Expression: f_num
                                        * Referenced by: '<S7>/Dctdoubleintegrator6'
                                        */
  real_T Dctdoubleintegrator6_P2_Size[2];
                             /* Computed Parameter: Dctdoubleintegrator6_P2_Size
                              * Referenced by: '<S7>/Dctdoubleintegrator6'
                              */
  real_T Dctdoubleintegrator6_P2;      /* Expression: b_num
                                        * Referenced by: '<S7>/Dctdoubleintegrator6'
                                        */
  real_T Dctdoubleintegrator6_P3_Size[2];
                             /* Computed Parameter: Dctdoubleintegrator6_P3_Size
                              * Referenced by: '<S7>/Dctdoubleintegrator6'
                              */
  real_T Dctdoubleintegrator6_P3;      /* Expression: 0.001
                                        * Referenced by: '<S7>/Dctdoubleintegrator6'
                                        */
  real_T Dct2lowpass_P1_Size[2];      /* Computed Parameter: Dct2lowpass_P1_Size
                                       * Referenced by: '<S7>/Dct2lowpass'
                                       */
  real_T Dct2lowpass_P1;               /* Expression: f_den
                                        * Referenced by: '<S7>/Dct2lowpass'
                                        */
  real_T Dct2lowpass_P2_Size[2];      /* Computed Parameter: Dct2lowpass_P2_Size
                                       * Referenced by: '<S7>/Dct2lowpass'
                                       */
  real_T Dct2lowpass_P2;               /* Expression: b_den
                                        * Referenced by: '<S7>/Dct2lowpass'
                                        */
  real_T Dct2lowpass_P3_Size[2];      /* Computed Parameter: Dct2lowpass_P3_Size
                                       * Referenced by: '<S7>/Dct2lowpass'
                                       */
  real_T Dct2lowpass_P3;               /* Expression: 0.001
                                        * Referenced by: '<S7>/Dct2lowpass'
                                        */
  real_T Gain2_Gain_f;                 /* Expression: -0.985
                                        * Referenced by: '<S8>/Gain2'
                                        */
  real_T Dctnotch_P1_Size_f[2];        /* Computed Parameter: Dctnotch_P1_Size_f
                                        * Referenced by: '<S8>/Dctnotch'
                                        */
  real_T Dctnotch_P1_l;                /* Expression: f_num
                                        * Referenced by: '<S8>/Dctnotch'
                                        */
  real_T Dctnotch_P2_Size_k[2];        /* Computed Parameter: Dctnotch_P2_Size_k
                                        * Referenced by: '<S8>/Dctnotch'
                                        */
  real_T Dctnotch_P2_m;                /* Expression: b_num
                                        * Referenced by: '<S8>/Dctnotch'
                                        */
  real_T Dctnotch_P3_Size_e[2];        /* Computed Parameter: Dctnotch_P3_Size_e
                                        * Referenced by: '<S8>/Dctnotch'
                                        */
  real_T Dctnotch_P3_g;                /* Expression: f_den
                                        * Referenced by: '<S8>/Dctnotch'
                                        */
  real_T Dctnotch_P4_Size_o[2];        /* Computed Parameter: Dctnotch_P4_Size_o
                                        * Referenced by: '<S8>/Dctnotch'
                                        */
  real_T Dctnotch_P4_j;                /* Expression: b_den
                                        * Referenced by: '<S8>/Dctnotch'
                                        */
  real_T Dctnotch_P5_Size_e[2];        /* Computed Parameter: Dctnotch_P5_Size_e
                                        * Referenced by: '<S8>/Dctnotch'
                                        */
  real_T Dctnotch_P5_j;                /* Expression: 0.001
                                        * Referenced by: '<S8>/Dctnotch'
                                        */
  real_T Dctleadlag_P1_Size_d[2];    /* Computed Parameter: Dctleadlag_P1_Size_d
                                      * Referenced by: '<S8>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_k;              /* Expression: f_num
                                        * Referenced by: '<S8>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_c[2];    /* Computed Parameter: Dctleadlag_P2_Size_c
                                      * Referenced by: '<S8>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_p;              /* Expression: f_den
                                        * Referenced by: '<S8>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_m[2];    /* Computed Parameter: Dctleadlag_P3_Size_m
                                      * Referenced by: '<S8>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_f;              /* Expression: 0.001
                                        * Referenced by: '<S8>/Dctleadlag'
                                        */
  real_T Dctnotch2_P1_Size_f[2];      /* Computed Parameter: Dctnotch2_P1_Size_f
                                       * Referenced by: '<S8>/Dctnotch2'
                                       */
  real_T Dctnotch2_P1_g;               /* Expression: f_num
                                        * Referenced by: '<S8>/Dctnotch2'
                                        */
  real_T Dctnotch2_P2_Size_e[2];      /* Computed Parameter: Dctnotch2_P2_Size_e
                                       * Referenced by: '<S8>/Dctnotch2'
                                       */
  real_T Dctnotch2_P2_i;               /* Expression: b_num
                                        * Referenced by: '<S8>/Dctnotch2'
                                        */
  real_T Dctnotch2_P3_Size_f[2];      /* Computed Parameter: Dctnotch2_P3_Size_f
                                       * Referenced by: '<S8>/Dctnotch2'
                                       */
  real_T Dctnotch2_P3_n;               /* Expression: f_den
                                        * Referenced by: '<S8>/Dctnotch2'
                                        */
  real_T Dctnotch2_P4_Size_p[2];      /* Computed Parameter: Dctnotch2_P4_Size_p
                                       * Referenced by: '<S8>/Dctnotch2'
                                       */
  real_T Dctnotch2_P4_j;               /* Expression: b_den
                                        * Referenced by: '<S8>/Dctnotch2'
                                        */
  real_T Dctnotch2_P5_Size_p[2];      /* Computed Parameter: Dctnotch2_P5_Size_p
                                       * Referenced by: '<S8>/Dctnotch2'
                                       */
  real_T Dctnotch2_P5_o;               /* Expression: 0.001
                                        * Referenced by: '<S8>/Dctnotch2'
                                        */
  real_T Dctdoubleintegrator6_P1_Size_l[2];
                           /* Computed Parameter: Dctdoubleintegrator6_P1_Size_l
                            * Referenced by: '<S8>/Dctdoubleintegrator6'
                            */
  real_T Dctdoubleintegrator6_P1_m;    /* Expression: f_num
                                        * Referenced by: '<S8>/Dctdoubleintegrator6'
                                        */
  real_T Dctdoubleintegrator6_P2_Size_i[2];
                           /* Computed Parameter: Dctdoubleintegrator6_P2_Size_i
                            * Referenced by: '<S8>/Dctdoubleintegrator6'
                            */
  real_T Dctdoubleintegrator6_P2_d;    /* Expression: b_num
                                        * Referenced by: '<S8>/Dctdoubleintegrator6'
                                        */
  real_T Dctdoubleintegrator6_P3_Size_i[2];
                           /* Computed Parameter: Dctdoubleintegrator6_P3_Size_i
                            * Referenced by: '<S8>/Dctdoubleintegrator6'
                            */
  real_T Dctdoubleintegrator6_P3_j;    /* Expression: 0.001
                                        * Referenced by: '<S8>/Dctdoubleintegrator6'
                                        */
  real_T Dct2lowpass_P1_Size_g[2];  /* Computed Parameter: Dct2lowpass_P1_Size_g
                                     * Referenced by: '<S8>/Dct2lowpass'
                                     */
  real_T Dct2lowpass_P1_p;             /* Expression: f_den
                                        * Referenced by: '<S8>/Dct2lowpass'
                                        */
  real_T Dct2lowpass_P2_Size_a[2];  /* Computed Parameter: Dct2lowpass_P2_Size_a
                                     * Referenced by: '<S8>/Dct2lowpass'
                                     */
  real_T Dct2lowpass_P2_b;             /* Expression: b_den
                                        * Referenced by: '<S8>/Dct2lowpass'
                                        */
  real_T Dct2lowpass_P3_Size_a[2];  /* Computed Parameter: Dct2lowpass_P3_Size_a
                                     * Referenced by: '<S8>/Dct2lowpass'
                                     */
  real_T Dct2lowpass_P3_d;             /* Expression: 0.001
                                        * Referenced by: '<S8>/Dct2lowpass'
                                        */
  real_T Gain2_Gain_a;                 /* Expression: -1.031
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real_T Dctnotch_P1_Size_j[2];        /* Computed Parameter: Dctnotch_P1_Size_j
                                        * Referenced by: '<S9>/Dctnotch'
                                        */
  real_T Dctnotch_P1_b;                /* Expression: f_num
                                        * Referenced by: '<S9>/Dctnotch'
                                        */
  real_T Dctnotch_P2_Size_km[2];      /* Computed Parameter: Dctnotch_P2_Size_km
                                       * Referenced by: '<S9>/Dctnotch'
                                       */
  real_T Dctnotch_P2_h;                /* Expression: b_num
                                        * Referenced by: '<S9>/Dctnotch'
                                        */
  real_T Dctnotch_P3_Size_h[2];        /* Computed Parameter: Dctnotch_P3_Size_h
                                        * Referenced by: '<S9>/Dctnotch'
                                        */
  real_T Dctnotch_P3_f;                /* Expression: f_den
                                        * Referenced by: '<S9>/Dctnotch'
                                        */
  real_T Dctnotch_P4_Size_j[2];        /* Computed Parameter: Dctnotch_P4_Size_j
                                        * Referenced by: '<S9>/Dctnotch'
                                        */
  real_T Dctnotch_P4_c;                /* Expression: b_den
                                        * Referenced by: '<S9>/Dctnotch'
                                        */
  real_T Dctnotch_P5_Size_c[2];        /* Computed Parameter: Dctnotch_P5_Size_c
                                        * Referenced by: '<S9>/Dctnotch'
                                        */
  real_T Dctnotch_P5_k;                /* Expression: 0.001
                                        * Referenced by: '<S9>/Dctnotch'
                                        */
  real_T Dctleadlag_P1_Size_f[2];    /* Computed Parameter: Dctleadlag_P1_Size_f
                                      * Referenced by: '<S9>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_d;              /* Expression: f_num
                                        * Referenced by: '<S9>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_h[2];    /* Computed Parameter: Dctleadlag_P2_Size_h
                                      * Referenced by: '<S9>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_a;              /* Expression: f_den
                                        * Referenced by: '<S9>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_g[2];    /* Computed Parameter: Dctleadlag_P3_Size_g
                                      * Referenced by: '<S9>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_o;              /* Expression: 0.001
                                        * Referenced by: '<S9>/Dctleadlag'
                                        */
  real_T Dctnotch2_P1_Size_o[2];      /* Computed Parameter: Dctnotch2_P1_Size_o
                                       * Referenced by: '<S9>/Dctnotch2'
                                       */
  real_T Dctnotch2_P1_h;               /* Expression: f_num
                                        * Referenced by: '<S9>/Dctnotch2'
                                        */
  real_T Dctnotch2_P2_Size_m[2];      /* Computed Parameter: Dctnotch2_P2_Size_m
                                       * Referenced by: '<S9>/Dctnotch2'
                                       */
  real_T Dctnotch2_P2_f;               /* Expression: b_num
                                        * Referenced by: '<S9>/Dctnotch2'
                                        */
  real_T Dctnotch2_P3_Size_l[2];      /* Computed Parameter: Dctnotch2_P3_Size_l
                                       * Referenced by: '<S9>/Dctnotch2'
                                       */
  real_T Dctnotch2_P3_a;               /* Expression: f_den
                                        * Referenced by: '<S9>/Dctnotch2'
                                        */
  real_T Dctnotch2_P4_Size_o[2];      /* Computed Parameter: Dctnotch2_P4_Size_o
                                       * Referenced by: '<S9>/Dctnotch2'
                                       */
  real_T Dctnotch2_P4_l;               /* Expression: b_den
                                        * Referenced by: '<S9>/Dctnotch2'
                                        */
  real_T Dctnotch2_P5_Size_o[2];      /* Computed Parameter: Dctnotch2_P5_Size_o
                                       * Referenced by: '<S9>/Dctnotch2'
                                       */
  real_T Dctnotch2_P5_l;               /* Expression: 0.001
                                        * Referenced by: '<S9>/Dctnotch2'
                                        */
  real_T Dctdoubleintegrator6_P1_Size_j[2];
                           /* Computed Parameter: Dctdoubleintegrator6_P1_Size_j
                            * Referenced by: '<S9>/Dctdoubleintegrator6'
                            */
  real_T Dctdoubleintegrator6_P1_j;    /* Expression: f_num
                                        * Referenced by: '<S9>/Dctdoubleintegrator6'
                                        */
  real_T Dctdoubleintegrator6_P2_Size_h[2];
                           /* Computed Parameter: Dctdoubleintegrator6_P2_Size_h
                            * Referenced by: '<S9>/Dctdoubleintegrator6'
                            */
  real_T Dctdoubleintegrator6_P2_k;    /* Expression: b_num
                                        * Referenced by: '<S9>/Dctdoubleintegrator6'
                                        */
  real_T Dctdoubleintegrator6_P3_Size_p[2];
                           /* Computed Parameter: Dctdoubleintegrator6_P3_Size_p
                            * Referenced by: '<S9>/Dctdoubleintegrator6'
                            */
  real_T Dctdoubleintegrator6_P3_l;    /* Expression: 0.001
                                        * Referenced by: '<S9>/Dctdoubleintegrator6'
                                        */
  real_T Dct2lowpass_P1_Size_m[2];  /* Computed Parameter: Dct2lowpass_P1_Size_m
                                     * Referenced by: '<S9>/Dct2lowpass'
                                     */
  real_T Dct2lowpass_P1_k;             /* Expression: f_den
                                        * Referenced by: '<S9>/Dct2lowpass'
                                        */
  real_T Dct2lowpass_P2_Size_e[2];  /* Computed Parameter: Dct2lowpass_P2_Size_e
                                     * Referenced by: '<S9>/Dct2lowpass'
                                     */
  real_T Dct2lowpass_P2_k;             /* Expression: b_den
                                        * Referenced by: '<S9>/Dct2lowpass'
                                        */
  real_T Dct2lowpass_P3_Size_j[2];  /* Computed Parameter: Dct2lowpass_P3_Size_j
                                     * Referenced by: '<S9>/Dct2lowpass'
                                     */
  real_T Dct2lowpass_P3_a;             /* Expression: 0.001
                                        * Referenced by: '<S9>/Dct2lowpass'
                                        */
  real_T Gain2_Gain_d;                 /* Expression: -1.2
                                        * Referenced by: '<S10>/Gain2'
                                        */
  real_T Dctnotch_P1_Size_c[2];        /* Computed Parameter: Dctnotch_P1_Size_c
                                        * Referenced by: '<S10>/Dctnotch'
                                        */
  real_T Dctnotch_P1_a;                /* Expression: f_num
                                        * Referenced by: '<S10>/Dctnotch'
                                        */
  real_T Dctnotch_P2_Size_ku[2];      /* Computed Parameter: Dctnotch_P2_Size_ku
                                       * Referenced by: '<S10>/Dctnotch'
                                       */
  real_T Dctnotch_P2_k;                /* Expression: b_num
                                        * Referenced by: '<S10>/Dctnotch'
                                        */
  real_T Dctnotch_P3_Size_f[2];        /* Computed Parameter: Dctnotch_P3_Size_f
                                        * Referenced by: '<S10>/Dctnotch'
                                        */
  real_T Dctnotch_P3_j;                /* Expression: f_den
                                        * Referenced by: '<S10>/Dctnotch'
                                        */
  real_T Dctnotch_P4_Size_i[2];        /* Computed Parameter: Dctnotch_P4_Size_i
                                        * Referenced by: '<S10>/Dctnotch'
                                        */
  real_T Dctnotch_P4_m;                /* Expression: b_den
                                        * Referenced by: '<S10>/Dctnotch'
                                        */
  real_T Dctnotch_P5_Size_o[2];        /* Computed Parameter: Dctnotch_P5_Size_o
                                        * Referenced by: '<S10>/Dctnotch'
                                        */
  real_T Dctnotch_P5_k3;               /* Expression: 0.001
                                        * Referenced by: '<S10>/Dctnotch'
                                        */
  real_T Dctleadlag_P1_Size_e[2];    /* Computed Parameter: Dctleadlag_P1_Size_e
                                      * Referenced by: '<S10>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_do;             /* Expression: f_num
                                        * Referenced by: '<S10>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_l[2];    /* Computed Parameter: Dctleadlag_P2_Size_l
                                      * Referenced by: '<S10>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_h;              /* Expression: f_den
                                        * Referenced by: '<S10>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_k[2];    /* Computed Parameter: Dctleadlag_P3_Size_k
                                      * Referenced by: '<S10>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_l;              /* Expression: 0.001
                                        * Referenced by: '<S10>/Dctleadlag'
                                        */
  real_T Dctnotch2_P1_Size_ob[2];    /* Computed Parameter: Dctnotch2_P1_Size_ob
                                      * Referenced by: '<S10>/Dctnotch2'
                                      */
  real_T Dctnotch2_P1_i;               /* Expression: f_num
                                        * Referenced by: '<S10>/Dctnotch2'
                                        */
  real_T Dctnotch2_P2_Size_c[2];      /* Computed Parameter: Dctnotch2_P2_Size_c
                                       * Referenced by: '<S10>/Dctnotch2'
                                       */
  real_T Dctnotch2_P2_k;               /* Expression: b_num
                                        * Referenced by: '<S10>/Dctnotch2'
                                        */
  real_T Dctnotch2_P3_Size_k[2];      /* Computed Parameter: Dctnotch2_P3_Size_k
                                       * Referenced by: '<S10>/Dctnotch2'
                                       */
  real_T Dctnotch2_P3_nk;              /* Expression: f_den
                                        * Referenced by: '<S10>/Dctnotch2'
                                        */
  real_T Dctnotch2_P4_Size_i[2];      /* Computed Parameter: Dctnotch2_P4_Size_i
                                       * Referenced by: '<S10>/Dctnotch2'
                                       */
  real_T Dctnotch2_P4_ld;              /* Expression: b_den
                                        * Referenced by: '<S10>/Dctnotch2'
                                        */
  real_T Dctnotch2_P5_Size_pa[2];    /* Computed Parameter: Dctnotch2_P5_Size_pa
                                      * Referenced by: '<S10>/Dctnotch2'
                                      */
  real_T Dctnotch2_P5_c;               /* Expression: 0.001
                                        * Referenced by: '<S10>/Dctnotch2'
                                        */
  real_T Dctdoubleintegrator6_P1_Size_o[2];
                           /* Computed Parameter: Dctdoubleintegrator6_P1_Size_o
                            * Referenced by: '<S10>/Dctdoubleintegrator6'
                            */
  real_T Dctdoubleintegrator6_P1_b;    /* Expression: f_num
                                        * Referenced by: '<S10>/Dctdoubleintegrator6'
                                        */
  real_T Dctdoubleintegrator6_P2_Size_f[2];
                           /* Computed Parameter: Dctdoubleintegrator6_P2_Size_f
                            * Referenced by: '<S10>/Dctdoubleintegrator6'
                            */
  real_T Dctdoubleintegrator6_P2_l;    /* Expression: b_num
                                        * Referenced by: '<S10>/Dctdoubleintegrator6'
                                        */
  real_T Dctdoubleintegrator6_P3_Size_f[2];
                           /* Computed Parameter: Dctdoubleintegrator6_P3_Size_f
                            * Referenced by: '<S10>/Dctdoubleintegrator6'
                            */
  real_T Dctdoubleintegrator6_P3_h;    /* Expression: 0.001
                                        * Referenced by: '<S10>/Dctdoubleintegrator6'
                                        */
  real_T Dct2lowpass_P1_Size_k[2];  /* Computed Parameter: Dct2lowpass_P1_Size_k
                                     * Referenced by: '<S10>/Dct2lowpass'
                                     */
  real_T Dct2lowpass_P1_i;             /* Expression: f_den
                                        * Referenced by: '<S10>/Dct2lowpass'
                                        */
  real_T Dct2lowpass_P2_Size_j[2];  /* Computed Parameter: Dct2lowpass_P2_Size_j
                                     * Referenced by: '<S10>/Dct2lowpass'
                                     */
  real_T Dct2lowpass_P2_d;             /* Expression: b_den
                                        * Referenced by: '<S10>/Dct2lowpass'
                                        */
  real_T Dct2lowpass_P3_Size_m[2];  /* Computed Parameter: Dct2lowpass_P3_Size_m
                                     * Referenced by: '<S10>/Dct2lowpass'
                                     */
  real_T Dct2lowpass_P3_at;            /* Expression: 0.001
                                        * Referenced by: '<S10>/Dct2lowpass'
                                        */
  real_T Gain2_Gain_b;                 /* Expression: -0.985
                                        * Referenced by: '<S12>/Gain2'
                                        */
  real_T Dctnotch_P1_Size_g[2];        /* Computed Parameter: Dctnotch_P1_Size_g
                                        * Referenced by: '<S12>/Dctnotch'
                                        */
  real_T Dctnotch_P1_m;                /* Expression: f_num
                                        * Referenced by: '<S12>/Dctnotch'
                                        */
  real_T Dctnotch_P2_Size_l[2];        /* Computed Parameter: Dctnotch_P2_Size_l
                                        * Referenced by: '<S12>/Dctnotch'
                                        */
  real_T Dctnotch_P2_a;                /* Expression: b_num
                                        * Referenced by: '<S12>/Dctnotch'
                                        */
  real_T Dctnotch_P3_Size_i[2];        /* Computed Parameter: Dctnotch_P3_Size_i
                                        * Referenced by: '<S12>/Dctnotch'
                                        */
  real_T Dctnotch_P3_c;                /* Expression: f_den
                                        * Referenced by: '<S12>/Dctnotch'
                                        */
  real_T Dctnotch_P4_Size_n[2];        /* Computed Parameter: Dctnotch_P4_Size_n
                                        * Referenced by: '<S12>/Dctnotch'
                                        */
  real_T Dctnotch_P4_l;                /* Expression: b_den
                                        * Referenced by: '<S12>/Dctnotch'
                                        */
  real_T Dctnotch_P5_Size_ov[2];      /* Computed Parameter: Dctnotch_P5_Size_ov
                                       * Referenced by: '<S12>/Dctnotch'
                                       */
  real_T Dctnotch_P5_n;                /* Expression: 0.001
                                        * Referenced by: '<S12>/Dctnotch'
                                        */
  real_T Dctleadlag_P1_Size_o[2];    /* Computed Parameter: Dctleadlag_P1_Size_o
                                      * Referenced by: '<S12>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_m;              /* Expression: f_num
                                        * Referenced by: '<S12>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_i[2];    /* Computed Parameter: Dctleadlag_P2_Size_i
                                      * Referenced by: '<S12>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_c;              /* Expression: f_den
                                        * Referenced by: '<S12>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_mn[2];  /* Computed Parameter: Dctleadlag_P3_Size_mn
                                     * Referenced by: '<S12>/Dctleadlag'
                                     */
  real_T Dctleadlag_P3_d;              /* Expression: 0.001
                                        * Referenced by: '<S12>/Dctleadlag'
                                        */
  real_T Dctnotch2_P1_Size_a[2];      /* Computed Parameter: Dctnotch2_P1_Size_a
                                       * Referenced by: '<S12>/Dctnotch2'
                                       */
  real_T Dctnotch2_P1_m;               /* Expression: f_num
                                        * Referenced by: '<S12>/Dctnotch2'
                                        */
  real_T Dctnotch2_P2_Size_c2[2];    /* Computed Parameter: Dctnotch2_P2_Size_c2
                                      * Referenced by: '<S12>/Dctnotch2'
                                      */
  real_T Dctnotch2_P2_p;               /* Expression: b_num
                                        * Referenced by: '<S12>/Dctnotch2'
                                        */
  real_T Dctnotch2_P3_Size_o[2];      /* Computed Parameter: Dctnotch2_P3_Size_o
                                       * Referenced by: '<S12>/Dctnotch2'
                                       */
  real_T Dctnotch2_P3_d;               /* Expression: f_den
                                        * Referenced by: '<S12>/Dctnotch2'
                                        */
  real_T Dctnotch2_P4_Size_d[2];      /* Computed Parameter: Dctnotch2_P4_Size_d
                                       * Referenced by: '<S12>/Dctnotch2'
                                       */
  real_T Dctnotch2_P4_b;               /* Expression: b_den
                                        * Referenced by: '<S12>/Dctnotch2'
                                        */
  real_T Dctnotch2_P5_Size_ol[2];    /* Computed Parameter: Dctnotch2_P5_Size_ol
                                      * Referenced by: '<S12>/Dctnotch2'
                                      */
  real_T Dctnotch2_P5_oh;              /* Expression: 0.001
                                        * Referenced by: '<S12>/Dctnotch2'
                                        */
  real_T Dctdoubleintegrator6_P1_Size_b[2];
                           /* Computed Parameter: Dctdoubleintegrator6_P1_Size_b
                            * Referenced by: '<S12>/Dctdoubleintegrator6'
                            */
  real_T Dctdoubleintegrator6_P1_f;    /* Expression: f_num
                                        * Referenced by: '<S12>/Dctdoubleintegrator6'
                                        */
  real_T Dctdoubleintegrator6_P2_Size_c[2];
                           /* Computed Parameter: Dctdoubleintegrator6_P2_Size_c
                            * Referenced by: '<S12>/Dctdoubleintegrator6'
                            */
  real_T Dctdoubleintegrator6_P2_o;    /* Expression: b_num
                                        * Referenced by: '<S12>/Dctdoubleintegrator6'
                                        */
  real_T Dctdoubleintegrator6_P3_Size_pk[2];
                          /* Computed Parameter: Dctdoubleintegrator6_P3_Size_pk
                           * Referenced by: '<S12>/Dctdoubleintegrator6'
                           */
  real_T Dctdoubleintegrator6_P3_lo;   /* Expression: 0.001
                                        * Referenced by: '<S12>/Dctdoubleintegrator6'
                                        */
  real_T Dct2lowpass_P1_Size_j[2];  /* Computed Parameter: Dct2lowpass_P1_Size_j
                                     * Referenced by: '<S12>/Dct2lowpass'
                                     */
  real_T Dct2lowpass_P1_b;             /* Expression: f_den
                                        * Referenced by: '<S12>/Dct2lowpass'
                                        */
  real_T Dct2lowpass_P2_Size_d[2];  /* Computed Parameter: Dct2lowpass_P2_Size_d
                                     * Referenced by: '<S12>/Dct2lowpass'
                                     */
  real_T Dct2lowpass_P2_j;             /* Expression: b_den
                                        * Referenced by: '<S12>/Dct2lowpass'
                                        */
  real_T Dct2lowpass_P3_Size_p[2];  /* Computed Parameter: Dct2lowpass_P3_Size_p
                                     * Referenced by: '<S12>/Dct2lowpass'
                                     */
  real_T Dct2lowpass_P3_o;             /* Expression: 0.001
                                        * Referenced by: '<S12>/Dct2lowpass'
                                        */
  uint8_T Selectencoder_CurrentSetting;
                             /* Computed Parameter: Selectencoder_CurrentSetting
                              * Referenced by: '<Root>/Select encoder'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_Reference_model_Control_Engineering_4_T {
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
    SimStruct childSFunctions[33];
    SimStruct *childSFunctionPtrs[33];
    struct _ssBlkInfo2 blkInfo2[33];
    struct _ssSFcnModelMethods2 methods2[33];
    struct _ssSFcnModelMethods3 methods3[33];
    struct _ssSFcnModelMethods4 methods4[33];
    struct _ssStatesInfo2 statesInfo2[33];
    ssPeriodicStatesInfo periodicStatesInfo[33];
    struct _ssPortInfo2 inputOutputPortInfo2[33];
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
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn1;

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
      uint_T attribs[5];
      mxArray *params[5];
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
      uint_T attribs[5];
      mxArray *params[5];
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
      uint_T attribs[3];
      mxArray *params[3];
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
      uint_T attribs[5];
      mxArray *params[5];
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
      uint_T attribs[3];
      mxArray *params[3];
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
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn10;

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
    } Sfcn11;

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
    } Sfcn12;

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
    } Sfcn13;

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
    } Sfcn14;

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
    } Sfcn15;

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
    } Sfcn16;

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
    } Sfcn17;

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
    } Sfcn18;

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
    } Sfcn19;

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
    } Sfcn20;

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
    } Sfcn21;

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
    } Sfcn22;

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
    } Sfcn23;

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
    } Sfcn24;

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
    } Sfcn25;

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
    } Sfcn26;

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
    } Sfcn27;

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
    } Sfcn28;

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
    } Sfcn29;

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
    } Sfcn30;

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
    } Sfcn31;

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
    } Sfcn32;
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
extern P_Reference_model_Control_Engineering_4_T
  Reference_model_Control_Engineering_4_P;

/* Block signals (default storage) */
extern B_Reference_model_Control_Engineering_4_T
  Reference_model_Control_Engineering_4_B;

/* Block states (default storage) */
extern DW_Reference_model_Control_Engineering_4_T
  Reference_model_Control_Engineering_4_DW;

/* External function called from main */
extern void Reference_model_Control_Engineering_4_SetEventsForThisBaseStep
  (boolean_T *eventFlags);

/* Model entry point functions */
extern void Reference_model_Control_Engineering_4_SetEventsForThisBaseStep
  (boolean_T *eventFlags);
extern void Reference_model_Control_Engineering_4_initialize(void);
extern void Reference_model_Control_Engineering_4_step0(void);
extern void Reference_model_Control_Engineering_4_step2(void);
extern void Reference_model_Control_Engineering_4_step(int_T tid);
extern void Reference_model_Control_Engineering_4_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Reference_model_Control_Engineering_4_T *const
  Reference_model_Control_Engineering_4_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Gain' : Unused code path elimination
 * Block '<Root>/Sum2' : Unused code path elimination
 */

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
 * '<Root>' : 'Reference_model_Control_Engineering_4'
 * '<S1>'   : 'Reference_model_Control_Engineering_4/Feedforward'
 * '<S2>'   : 'Reference_model_Control_Engineering_4/Fourth Order Motion System'
 * '<S3>'   : 'Reference_model_Control_Engineering_4/Measurement Block'
 * '<S4>'   : 'Reference_model_Control_Engineering_4/Real-time scope'
 * '<S5>'   : 'Reference_model_Control_Engineering_4/Ref power'
 * '<S6>'   : 'Reference_model_Control_Engineering_4/Subsystem'
 * '<S7>'   : 'Reference_model_Control_Engineering_4/T-II High gain - similar 3 Hz notch + 60 Notch_Lowpass 140 (High)_ 51.04 dB gain'
 * '<S8>'   : 'Reference_model_Control_Engineering_4/T10 Gain_Notch_60(Low second order)+3_LeadLag_Integrator_Lowpass_50 Hz1'
 * '<S9>'   : 'Reference_model_Control_Engineering_4/T10-1 Low gain - large 3 Hz notch wide (second order) + 60 Notch wider _ 24.44 dB gain'
 * '<S10>'  : 'Reference_model_Control_Engineering_4/T10-2 High gain - similar 3 Hz notch + 60 Notch wide (second order)_ 53.68 dB gain'
 * '<S11>'  : 'Reference_model_Control_Engineering_4/T10-2 High gain - similar 3 Hz notch + 60 Notch wide (second order)_ 53.68 dB gain1'
 * '<S12>'  : 'Reference_model_Control_Engineering_4/T10-3 Low gain - large 3 Hz notch wide (second order) + 60 Notch + LP even wider_ 40 dB dB gain'
 * '<S13>'  : 'Reference_model_Control_Engineering_4/Fourth Order Motion System/Ethercat E-box'
 * '<S14>'  : 'Reference_model_Control_Engineering_4/Fourth Order Motion System/Ethercat Supervisor'
 * '<S15>'  : 'Reference_model_Control_Engineering_4/Measurement Block/SPERTE_measurement_function'
 */
#endif                 /* RTW_HEADER_Reference_model_Control_Engineering_4_h_ */
