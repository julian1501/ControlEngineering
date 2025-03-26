/*
 * FinalAssingmentModel_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "FinalAssingmentModel".
 *
 * Model version              : 7.0
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Wed Mar 26 12:26:16 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FinalAssingmentModel_types_h_
#define RTW_HEADER_FinalAssingmentModel_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */

/* Custom Type definition for MATLAB Function: '<S3>/SPERTE_measurement_function' */
#include <stdio.h>
#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_char_T */

#ifndef typedef_emxArray_char_T_FinalAssingme_T
#define typedef_emxArray_char_T_FinalAssingme_T

typedef struct emxArray_char_T emxArray_char_T_FinalAssingme_T;

#endif                             /* typedef_emxArray_char_T_FinalAssingme_T */

/* Parameters (default storage) */
typedef struct P_FinalAssingmentModel_T_ P_FinalAssingmentModel_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_FinalAssingmentModel_T RT_MODEL_FinalAssingmentModel_T;

#endif                            /* RTW_HEADER_FinalAssingmentModel_types_h_ */
