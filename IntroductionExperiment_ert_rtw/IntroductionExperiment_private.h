/*
 * IntroductionExperiment_private.h
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

#ifndef RTW_HEADER_IntroductionExperiment_private_h_
#define RTW_HEADER_IntroductionExperiment_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_roundd_snf(real_T u);
extern void ec_Supervisor(SimStruct *rts);
extern void ec_Ebox(SimStruct *rts);
extern void ref3b(SimStruct *rts);
extern void dleadlag(SimStruct *rts);
extern void dlowpass1(SimStruct *rts);
extern void dnotch(SimStruct *rts);

#endif                        /* RTW_HEADER_IntroductionExperiment_private_h_ */
