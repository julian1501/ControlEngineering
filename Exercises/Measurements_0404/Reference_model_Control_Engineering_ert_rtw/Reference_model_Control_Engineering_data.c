/*
 * Reference_model_Control_Engineering_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Reference_model_Control_Engineering".
 *
 * Model version              : 7.21
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Fri Apr  4 11:34:22 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Reference_model_Control_Engineering.h"
#include "Reference_model_Control_Engineering_private.h"

/* Block parameters (default storage) */
P_Reference_model_Control_Engineering_T Reference_model_Control_Engineering_P =
  {
  /* Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S8>/S-Function'
   */
  { 3.0, 6.0 },

  /* Variable: ref_part
   * Referenced by: '<S8>/S-Function'
   */
  { 0.0, 3.0, 0.0, 0.8, 2.0, -1.0, 3.0, 0.0, 0.0, 8.0, 8.0, 0.0,
    0.21000000000000002, 0.21000000000000002, 0.0, 1000.0, 1000.0, 0.0 },

  /* Mask Parameter: Refpower_stat
   * Referenced by: '<S7>/Start setpoint'
   */
  1.0,

  /* Mask Parameter: MeasurementBlock_N_samples
   * Referenced by: '<S5>/SPERTE_measurement_samples'
   */
  300000U,

  /* Mask Parameter: MeasurementBlock_trigger_comman
   * Referenced by: '<S5>/SPERTE_measurement_trigger_command'
   */
  0U,

  /* Mask Parameter: MeasurementBlock_triggertype
   * Referenced by: '<S5>/SPERTE_measurement_function'
   */
  2U,

  /* Computed Parameter: SFunction_P1_Size_k
   * Referenced by: '<S10>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: portid
   * Referenced by: '<S10>/S-Function'
   */
  0.0,

  /* Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S10>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: ectimeout
   * Referenced by: '<S10>/S-Function'
   */
  500.0,

  /* Computed Parameter: ec_Ebox_P1_Size
   * Referenced by: '<S9>/ec_Ebox'
   */
  { 1.0, 1.0 },

  /* Expression: link_id
   * Referenced by: '<S9>/ec_Ebox'
   */
  0.0,

  /* Expression: (2*pi)/(4*500)
   * Referenced by: '<S3>/count2rad'
   */
  0.0031415926535897933,

  /* Expression: (2*pi)/(500*4)
   * Referenced by: '<Root>/Quantizer1'
   */
  0.0031415926535897933,

  /* Expression: 1
   * Referenced by: '<Root>/Gain1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Gain'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain2'
   */
  -1.0,

  /* Computed Parameter: Dctnotch_P1_Size
   * Referenced by: '<S1>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S1>/Dctnotch'
   */
  60.9,

  /* Computed Parameter: Dctnotch_P2_Size
   * Referenced by: '<S1>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S1>/Dctnotch'
   */
  0.015,

  /* Computed Parameter: Dctnotch_P3_Size
   * Referenced by: '<S1>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S1>/Dctnotch'
   */
  120.0,

  /* Computed Parameter: Dctnotch_P4_Size
   * Referenced by: '<S1>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S1>/Dctnotch'
   */
  0.5,

  /* Computed Parameter: Dctnotch_P5_Size
   * Referenced by: '<S1>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S1>/Dctnotch'
   */
  0.001,

  /* Computed Parameter: Dctintegrator_P1_Size
   * Referenced by: '<S1>/Dctintegrator'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S1>/Dctintegrator'
   */
  3.0,

  /* Computed Parameter: Dctintegrator_P2_Size
   * Referenced by: '<S1>/Dctintegrator'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S1>/Dctintegrator'
   */
  0.001,

  /* Computed Parameter: Dctleadlag_P1_Size
   * Referenced by: '<S1>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S1>/Dctleadlag'
   */
  5.0,

  /* Computed Parameter: Dctleadlag_P2_Size
   * Referenced by: '<S1>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S1>/Dctleadlag'
   */
  9.0,

  /* Computed Parameter: Dctleadlag_P3_Size
   * Referenced by: '<S1>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S1>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dctleadlag1_P1_Size
   * Referenced by: '<S1>/Dctleadlag1'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S1>/Dctleadlag1'
   */
  6.0,

  /* Computed Parameter: Dctleadlag1_P2_Size
   * Referenced by: '<S1>/Dctleadlag1'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S1>/Dctleadlag1'
   */
  70.0,

  /* Computed Parameter: Dctleadlag1_P3_Size
   * Referenced by: '<S1>/Dctleadlag1'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S1>/Dctleadlag1'
   */
  0.001,

  /* Expression: 0.0001
   * Referenced by: '<S2>/Ka'
   */
  0.0001,

  /* Expression: 0
   * Referenced by: '<S2>/Kfc'
   */
  0.0,

  /* Expression: 0.02
   * Referenced by: '<S2>/Kv'
   */
  0.02,

  /* Expression: [0,0]
   * Referenced by: '<S3>/Constant'
   */
  { 0.0, 0.0 },

  /* Expression: [0,0,0,0,0,0,0,0]
   * Referenced by: '<S3>/Constant1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S3>/Constant2'
   */
  0.0,

  /* Expression: 1/100
   * Referenced by: '<S9>/Gain'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<Root>/Noise'
   */
  0.0,

  /* Computed Parameter: Noise_StdDev
   * Referenced by: '<Root>/Noise'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Noise'
   */
  0.0,

  /* Expression: 2.5
   * Referenced by: '<S3>/Saturation'
   */
  2.5,

  /* Expression: -2.5
   * Referenced by: '<S3>/Saturation'
   */
  -2.5,

  /* Expression: 10
   * Referenced by: '<S9>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S9>/Saturation'
   */
  -10.0,

  /* Computed Parameter: Selectencoder_CurrentSetting
   * Referenced by: '<Root>/Select encoder'
   */
  0U
};
