/*
 * Reference_model_Control_Engineering_4_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Reference_model_Control_Engineering_4".
 *
 * Model version              : 7.45
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Wed Apr 16 16:12:12 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(FILE*),
  sizeof(uint64_T),
  sizeof(int64_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "FILE*",
  "uint64_T",
  "int64_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Reference_model_Control_Engineering_4_B.Constant1[0]), 0, 0, 10
  },

  { (char_T *)(&Reference_model_Control_Engineering_4_B.Startsetpoint), 0, 0, 36
  }
  ,

  { (char_T *)(&Reference_model_Control_Engineering_4_DW.Downsample_Buffer[0]),
    0, 0, 71 },

  { (char_T *)
    (&Reference_model_Control_Engineering_4_DW.ToWorkspace_PWORK.LoggedData), 11,
    0, 2 },

  { (char_T *)(&Reference_model_Control_Engineering_4_DW.RandSeed), 7, 0, 2 },

  { (char_T *)(&Reference_model_Control_Engineering_4_DW.NF), 4, 0, 1 },

  { (char_T *)(&Reference_model_Control_Engineering_4_DW.busy), 3, 0, 1 },

  { (char_T *)(&Reference_model_Control_Engineering_4_DW.eml_autoflush[0]), 8, 0,
    20 },

  { (char_T *)(&Reference_model_Control_Engineering_4_DW.eml_openfiles[0]), 15,
    0, 20 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Reference_model_Control_Engineering_4_P.SFunction_P1_Size[0]), 0,
    0, 15 },

  { (char_T *)
    (&Reference_model_Control_Engineering_4_P.MeasurementBlock_N_samples), 7, 0,
    1 },

  { (char_T *)
    (&Reference_model_Control_Engineering_4_P.MeasurementBlock_trigger_comman),
    3, 0, 2 },

  { (char_T *)(&Reference_model_Control_Engineering_4_P.count2rad_Gain), 0, 0,
    89 },

  { (char_T *)
    (&Reference_model_Control_Engineering_4_P.Selectencoder_CurrentSetting), 3,
    0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] Reference_model_Control_Engineering_4_dt.h */
