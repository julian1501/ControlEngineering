/*
 * Reference_model_Control_Engineering_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Reference_model_Control_Engineering".
 *
 * Model version              : 7.0
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Mar 13 11:31:55 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Reference_model_Control_Engineering_types_h_
#define RTW_HEADER_Reference_model_Control_Engineering_types_h_
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

#ifndef typedef_emxArray_char_T_Reference_mod_T
#define typedef_emxArray_char_T_Reference_mod_T

typedef struct emxArray_char_T emxArray_char_T_Reference_mod_T;

#endif                             /* typedef_emxArray_char_T_Reference_mod_T */

/* Parameters (default storage) */
typedef struct P_Reference_model_Control_Engineering_T_
  P_Reference_model_Control_Engineering_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Reference_model_Control_Engineering_T
  RT_MODEL_Reference_model_Control_Engineering_T;

#endif             /* RTW_HEADER_Reference_model_Control_Engineering_types_h_ */
