/*
 * Reference_model_Control_Engineering_4_data.c
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

#include "Reference_model_Control_Engineering_4.h"
#include "Reference_model_Control_Engineering_4_private.h"

/* Block parameters (default storage) */
P_Reference_model_Control_Engineering_4_T
  Reference_model_Control_Engineering_4_P = {
  /* Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S6>/S-Function'
   */
  { 2.0, 6.0 },

  /* Variable: ref_part
   * Referenced by: '<S6>/S-Function'
   */
  { 0.0, 124.5, 0.0, 5.9981145275035264, 124.5, 0.0, 21.27, 21.27, 0.1448,
    0.1448, 50000.0, 50000.0 },

  /* Mask Parameter: Refpower_stat
   * Referenced by: '<S5>/Start setpoint'
   */
  1.0,

  /* Mask Parameter: MeasurementBlock_N_samples
   * Referenced by: '<S3>/SPERTE_measurement_samples'
   */
  300000U,

  /* Mask Parameter: MeasurementBlock_trigger_comman
   * Referenced by: '<S3>/SPERTE_measurement_trigger_command'
   */
  0U,

  /* Mask Parameter: MeasurementBlock_triggertype
   * Referenced by: '<S3>/SPERTE_measurement_function'
   */
  2U,

  /* Expression: (2*pi)/(4*500)
   * Referenced by: '<S2>/count2rad'
   */
  0.0031415926535897933,

  /* Expression: (2*pi)/(500*4)
   * Referenced by: '<Root>/Quantizer1'
   */
  0.0031415926535897933,

  /* Computed Parameter: SFunction_P1_Size_k
   * Referenced by: '<S9>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: portid
   * Referenced by: '<S9>/S-Function'
   */
  0.0,

  /* Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S9>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: ectimeout
   * Referenced by: '<S9>/S-Function'
   */
  500.0,

  /* Computed Parameter: ec_Ebox_P1_Size
   * Referenced by: '<S8>/ec_Ebox'
   */
  { 1.0, 1.0 },

  /* Expression: link_id
   * Referenced by: '<S8>/ec_Ebox'
   */
  0.0,

  /* Expression: 1e-3
   * Referenced by: '<Root>/Gain1'
   */
  0.001,

  /* Expression: -0.00034
   * Referenced by: '<S1>/Ka'
   */
  -0.00034,

  /* Expression: -0.019
   * Referenced by: '<S1>/Kfc'
   */
  -0.019,

  /* Expression: -0.00013
   * Referenced by: '<S1>/Kv'
   */
  -0.00013,

  /* Expression: [0,0]
   * Referenced by: '<S2>/Constant'
   */
  { 0.0, 0.0 },

  /* Expression: [0,0,0,0,0,0,0,0]
   * Referenced by: '<S2>/Constant1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S2>/Constant2'
   */
  0.0,

  /* Expression: 1/100
   * Referenced by: '<S8>/Gain'
   */
  0.01,

  /* Expression: -0.965
   * Referenced by: '<S7>/Gain5'
   */
  -0.965,

  /* Computed Parameter: Dctnotch8_P1_Size
   * Referenced by: '<S7>/Dctnotch8'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S7>/Dctnotch8'
   */
  60.9,

  /* Computed Parameter: Dctnotch8_P2_Size
   * Referenced by: '<S7>/Dctnotch8'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S7>/Dctnotch8'
   */
  0.014,

  /* Computed Parameter: Dctnotch8_P3_Size
   * Referenced by: '<S7>/Dctnotch8'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S7>/Dctnotch8'
   */
  95.0,

  /* Computed Parameter: Dctnotch8_P4_Size
   * Referenced by: '<S7>/Dctnotch8'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S7>/Dctnotch8'
   */
  0.2,

  /* Computed Parameter: Dctnotch8_P5_Size
   * Referenced by: '<S7>/Dctnotch8'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S7>/Dctnotch8'
   */
  0.001,

  /* Computed Parameter: Dctleadlag4_P1_Size
   * Referenced by: '<S7>/Dctleadlag4'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S7>/Dctleadlag4'
   */
  4.0,

  /* Computed Parameter: Dctleadlag4_P2_Size
   * Referenced by: '<S7>/Dctleadlag4'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S7>/Dctleadlag4'
   */
  1000.0,

  /* Computed Parameter: Dctleadlag4_P3_Size
   * Referenced by: '<S7>/Dctleadlag4'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S7>/Dctleadlag4'
   */
  0.001,

  /* Computed Parameter: Dctnotch9_P1_Size
   * Referenced by: '<S7>/Dctnotch9'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S7>/Dctnotch9'
   */
  3.5,

  /* Computed Parameter: Dctnotch9_P2_Size
   * Referenced by: '<S7>/Dctnotch9'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S7>/Dctnotch9'
   */
  0.4,

  /* Computed Parameter: Dctnotch9_P3_Size
   * Referenced by: '<S7>/Dctnotch9'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S7>/Dctnotch9'
   */
  3.5,

  /* Computed Parameter: Dctnotch9_P4_Size
   * Referenced by: '<S7>/Dctnotch9'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S7>/Dctnotch9'
   */
  0.01,

  /* Computed Parameter: Dctnotch9_P5_Size
   * Referenced by: '<S7>/Dctnotch9'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S7>/Dctnotch9'
   */
  0.001,

  /* Computed Parameter: Dctintegrator_P1_Size
   * Referenced by: '<S7>/Dctintegrator'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S7>/Dctintegrator'
   */
  8.0,

  /* Computed Parameter: Dctintegrator_P2_Size
   * Referenced by: '<S7>/Dctintegrator'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S7>/Dctintegrator'
   */
  0.001,

  /* Computed Parameter: Dct2lowpass4_P1_Size
   * Referenced by: '<S7>/Dct2lowpass4'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S7>/Dct2lowpass4'
   */
  125.0,

  /* Computed Parameter: Dct2lowpass4_P2_Size
   * Referenced by: '<S7>/Dct2lowpass4'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S7>/Dct2lowpass4'
   */
  0.5,

  /* Computed Parameter: Dct2lowpass4_P3_Size
   * Referenced by: '<S7>/Dct2lowpass4'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S7>/Dct2lowpass4'
   */
  0.001,

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
   * Referenced by: '<S2>/Saturation'
   */
  2.5,

  /* Expression: -2.5
   * Referenced by: '<S2>/Saturation'
   */
  -2.5,

  /* Expression: 10
   * Referenced by: '<S8>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S8>/Saturation'
   */
  -10.0,

  /* Computed Parameter: Selectencoder_CurrentSetting
   * Referenced by: '<Root>/Select encoder'
   */
  0U
};
