/*
 * Reference_model_Control_Engineering_4_data.c
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
   * Referenced by: '<S14>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: portid
   * Referenced by: '<S14>/S-Function'
   */
  0.0,

  /* Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S14>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: ectimeout
   * Referenced by: '<S14>/S-Function'
   */
  500.0,

  /* Computed Parameter: ec_Ebox_P1_Size
   * Referenced by: '<S13>/ec_Ebox'
   */
  { 1.0, 1.0 },

  /* Expression: link_id
   * Referenced by: '<S13>/ec_Ebox'
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

  /* Expression: -0.0395
   * Referenced by: '<S1>/Kfc'
   */
  -0.0395,

  /* Expression: 0
   * Referenced by: '<S1>/Kv'
   */
  0.0,

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
   * Referenced by: '<S13>/Gain'
   */
  0.01,

  /* Expression: -1.178
   * Referenced by: '<S11>/Gain5'
   */
  -1.178,

  /* Computed Parameter: Dctnotch8_P1_Size
   * Referenced by: '<S11>/Dctnotch8'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S11>/Dctnotch8'
   */
  60.6,

  /* Computed Parameter: Dctnotch8_P2_Size
   * Referenced by: '<S11>/Dctnotch8'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S11>/Dctnotch8'
   */
  0.001,

  /* Computed Parameter: Dctnotch8_P3_Size
   * Referenced by: '<S11>/Dctnotch8'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S11>/Dctnotch8'
   */
  75.0,

  /* Computed Parameter: Dctnotch8_P4_Size
   * Referenced by: '<S11>/Dctnotch8'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S11>/Dctnotch8'
   */
  0.5,

  /* Computed Parameter: Dctnotch8_P5_Size
   * Referenced by: '<S11>/Dctnotch8'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S11>/Dctnotch8'
   */
  0.001,

  /* Computed Parameter: Dctleadlag4_P1_Size
   * Referenced by: '<S11>/Dctleadlag4'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S11>/Dctleadlag4'
   */
  5.055,

  /* Computed Parameter: Dctleadlag4_P2_Size
   * Referenced by: '<S11>/Dctleadlag4'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S11>/Dctleadlag4'
   */
  600.0,

  /* Computed Parameter: Dctleadlag4_P3_Size
   * Referenced by: '<S11>/Dctleadlag4'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S11>/Dctleadlag4'
   */
  0.001,

  /* Computed Parameter: Dctnotch9_P1_Size
   * Referenced by: '<S11>/Dctnotch9'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S11>/Dctnotch9'
   */
  3.9,

  /* Computed Parameter: Dctnotch9_P2_Size
   * Referenced by: '<S11>/Dctnotch9'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S11>/Dctnotch9'
   */
  0.4,

  /* Computed Parameter: Dctnotch9_P3_Size
   * Referenced by: '<S11>/Dctnotch9'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S11>/Dctnotch9'
   */
  3.5,

  /* Computed Parameter: Dctnotch9_P4_Size
   * Referenced by: '<S11>/Dctnotch9'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S11>/Dctnotch9'
   */
  0.001,

  /* Computed Parameter: Dctnotch9_P5_Size
   * Referenced by: '<S11>/Dctnotch9'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S11>/Dctnotch9'
   */
  0.001,

  /* Computed Parameter: Dctdoubleintegrator4_P1_Size
   * Referenced by: '<S11>/Dctdoubleintegrator4'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S11>/Dctdoubleintegrator4'
   */
  4.5,

  /* Computed Parameter: Dctdoubleintegrator4_P2_Size
   * Referenced by: '<S11>/Dctdoubleintegrator4'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S11>/Dctdoubleintegrator4'
   */
  0.25,

  /* Computed Parameter: Dctdoubleintegrator4_P3_Size
   * Referenced by: '<S11>/Dctdoubleintegrator4'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S11>/Dctdoubleintegrator4'
   */
  0.001,

  /* Computed Parameter: Dct2lowpass4_P1_Size
   * Referenced by: '<S11>/Dct2lowpass4'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S11>/Dct2lowpass4'
   */
  120.0,

  /* Computed Parameter: Dct2lowpass4_P2_Size
   * Referenced by: '<S11>/Dct2lowpass4'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S11>/Dct2lowpass4'
   */
  0.5,

  /* Computed Parameter: Dct2lowpass4_P3_Size
   * Referenced by: '<S11>/Dct2lowpass4'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S11>/Dct2lowpass4'
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
   * Referenced by: '<S13>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S13>/Saturation'
   */
  -10.0,

  /* Expression: -0.998
   * Referenced by: '<S7>/Gain2'
   */
  -0.998,

  /* Computed Parameter: Dctnotch_P1_Size
   * Referenced by: '<S7>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S7>/Dctnotch'
   */
  60.6,

  /* Computed Parameter: Dctnotch_P2_Size
   * Referenced by: '<S7>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S7>/Dctnotch'
   */
  0.001,

  /* Computed Parameter: Dctnotch_P3_Size
   * Referenced by: '<S7>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S7>/Dctnotch'
   */
  70.0,

  /* Computed Parameter: Dctnotch_P4_Size
   * Referenced by: '<S7>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S7>/Dctnotch'
   */
  0.6,

  /* Computed Parameter: Dctnotch_P5_Size
   * Referenced by: '<S7>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S7>/Dctnotch'
   */
  0.001,

  /* Computed Parameter: Dctleadlag_P1_Size
   * Referenced by: '<S7>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S7>/Dctleadlag'
   */
  5.842,

  /* Computed Parameter: Dctleadlag_P2_Size
   * Referenced by: '<S7>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S7>/Dctleadlag'
   */
  600.0,

  /* Computed Parameter: Dctleadlag_P3_Size
   * Referenced by: '<S7>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S7>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dctnotch2_P1_Size
   * Referenced by: '<S7>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S7>/Dctnotch2'
   */
  3.5,

  /* Computed Parameter: Dctnotch2_P2_Size
   * Referenced by: '<S7>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S7>/Dctnotch2'
   */
  0.5,

  /* Computed Parameter: Dctnotch2_P3_Size
   * Referenced by: '<S7>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S7>/Dctnotch2'
   */
  3.5,

  /* Computed Parameter: Dctnotch2_P4_Size
   * Referenced by: '<S7>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S7>/Dctnotch2'
   */
  0.01,

  /* Computed Parameter: Dctnotch2_P5_Size
   * Referenced by: '<S7>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S7>/Dctnotch2'
   */
  0.001,

  /* Computed Parameter: Dctdoubleintegrator6_P1_Size
   * Referenced by: '<S7>/Dctdoubleintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S7>/Dctdoubleintegrator6'
   */
  3.8,

  /* Computed Parameter: Dctdoubleintegrator6_P2_Size
   * Referenced by: '<S7>/Dctdoubleintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S7>/Dctdoubleintegrator6'
   */
  0.12,

  /* Computed Parameter: Dctdoubleintegrator6_P3_Size
   * Referenced by: '<S7>/Dctdoubleintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S7>/Dctdoubleintegrator6'
   */
  0.001,

  /* Computed Parameter: Dct2lowpass_P1_Size
   * Referenced by: '<S7>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S7>/Dct2lowpass'
   */
  140.0,

  /* Computed Parameter: Dct2lowpass_P2_Size
   * Referenced by: '<S7>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S7>/Dct2lowpass'
   */
  0.5,

  /* Computed Parameter: Dct2lowpass_P3_Size
   * Referenced by: '<S7>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S7>/Dct2lowpass'
   */
  0.001,

  /* Expression: -0.985
   * Referenced by: '<S8>/Gain2'
   */
  -0.985,

  /* Computed Parameter: Dctnotch_P1_Size_f
   * Referenced by: '<S8>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S8>/Dctnotch'
   */
  60.6,

  /* Computed Parameter: Dctnotch_P2_Size_k
   * Referenced by: '<S8>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S8>/Dctnotch'
   */
  0.001,

  /* Computed Parameter: Dctnotch_P3_Size_e
   * Referenced by: '<S8>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S8>/Dctnotch'
   */
  80.0,

  /* Computed Parameter: Dctnotch_P4_Size_o
   * Referenced by: '<S8>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S8>/Dctnotch'
   */
  0.7,

  /* Computed Parameter: Dctnotch_P5_Size_e
   * Referenced by: '<S8>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S8>/Dctnotch'
   */
  0.001,

  /* Computed Parameter: Dctleadlag_P1_Size_d
   * Referenced by: '<S8>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S8>/Dctleadlag'
   */
  5.6,

  /* Computed Parameter: Dctleadlag_P2_Size_c
   * Referenced by: '<S8>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S8>/Dctleadlag'
   */
  600.0,

  /* Computed Parameter: Dctleadlag_P3_Size_m
   * Referenced by: '<S8>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S8>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dctnotch2_P1_Size_f
   * Referenced by: '<S8>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S8>/Dctnotch2'
   */
  3.25,

  /* Computed Parameter: Dctnotch2_P2_Size_e
   * Referenced by: '<S8>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S8>/Dctnotch2'
   */
  0.5,

  /* Computed Parameter: Dctnotch2_P3_Size_f
   * Referenced by: '<S8>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S8>/Dctnotch2'
   */
  3.25,

  /* Computed Parameter: Dctnotch2_P4_Size_p
   * Referenced by: '<S8>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S8>/Dctnotch2'
   */
  0.01,

  /* Computed Parameter: Dctnotch2_P5_Size_p
   * Referenced by: '<S8>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S8>/Dctnotch2'
   */
  0.001,

  /* Computed Parameter: Dctdoubleintegrator6_P1_Size_l
   * Referenced by: '<S8>/Dctdoubleintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S8>/Dctdoubleintegrator6'
   */
  3.7,

  /* Computed Parameter: Dctdoubleintegrator6_P2_Size_i
   * Referenced by: '<S8>/Dctdoubleintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S8>/Dctdoubleintegrator6'
   */
  0.18,

  /* Computed Parameter: Dctdoubleintegrator6_P3_Size_i
   * Referenced by: '<S8>/Dctdoubleintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S8>/Dctdoubleintegrator6'
   */
  0.001,

  /* Computed Parameter: Dct2lowpass_P1_Size_g
   * Referenced by: '<S8>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S8>/Dct2lowpass'
   */
  140.0,

  /* Computed Parameter: Dct2lowpass_P2_Size_a
   * Referenced by: '<S8>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S8>/Dct2lowpass'
   */
  0.5,

  /* Computed Parameter: Dct2lowpass_P3_Size_a
   * Referenced by: '<S8>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S8>/Dct2lowpass'
   */
  0.001,

  /* Expression: -1.031
   * Referenced by: '<S9>/Gain2'
   */
  -1.031,

  /* Computed Parameter: Dctnotch_P1_Size_j
   * Referenced by: '<S9>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S9>/Dctnotch'
   */
  60.6,

  /* Computed Parameter: Dctnotch_P2_Size_km
   * Referenced by: '<S9>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S9>/Dctnotch'
   */
  0.005,

  /* Computed Parameter: Dctnotch_P3_Size_h
   * Referenced by: '<S9>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S9>/Dctnotch'
   */
  82.0,

  /* Computed Parameter: Dctnotch_P4_Size_j
   * Referenced by: '<S9>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S9>/Dctnotch'
   */
  0.85,

  /* Computed Parameter: Dctnotch_P5_Size_c
   * Referenced by: '<S9>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S9>/Dctnotch'
   */
  0.001,

  /* Computed Parameter: Dctleadlag_P1_Size_f
   * Referenced by: '<S9>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S9>/Dctleadlag'
   */
  4.825,

  /* Computed Parameter: Dctleadlag_P2_Size_h
   * Referenced by: '<S9>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S9>/Dctleadlag'
   */
  700.0,

  /* Computed Parameter: Dctleadlag_P3_Size_g
   * Referenced by: '<S9>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S9>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dctnotch2_P1_Size_o
   * Referenced by: '<S9>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S9>/Dctnotch2'
   */
  3.7,

  /* Computed Parameter: Dctnotch2_P2_Size_m
   * Referenced by: '<S9>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S9>/Dctnotch2'
   */
  0.6,

  /* Computed Parameter: Dctnotch2_P3_Size_l
   * Referenced by: '<S9>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S9>/Dctnotch2'
   */
  3.25,

  /* Computed Parameter: Dctnotch2_P4_Size_o
   * Referenced by: '<S9>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S9>/Dctnotch2'
   */
  0.01,

  /* Computed Parameter: Dctnotch2_P5_Size_o
   * Referenced by: '<S9>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S9>/Dctnotch2'
   */
  0.001,

  /* Computed Parameter: Dctdoubleintegrator6_P1_Size_j
   * Referenced by: '<S9>/Dctdoubleintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S9>/Dctdoubleintegrator6'
   */
  1.25,

  /* Computed Parameter: Dctdoubleintegrator6_P2_Size_h
   * Referenced by: '<S9>/Dctdoubleintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S9>/Dctdoubleintegrator6'
   */
  0.065,

  /* Computed Parameter: Dctdoubleintegrator6_P3_Size_p
   * Referenced by: '<S9>/Dctdoubleintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S9>/Dctdoubleintegrator6'
   */
  0.001,

  /* Computed Parameter: Dct2lowpass_P1_Size_m
   * Referenced by: '<S9>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S9>/Dct2lowpass'
   */
  120.0,

  /* Computed Parameter: Dct2lowpass_P2_Size_e
   * Referenced by: '<S9>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S9>/Dct2lowpass'
   */
  0.5,

  /* Computed Parameter: Dct2lowpass_P3_Size_j
   * Referenced by: '<S9>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S9>/Dct2lowpass'
   */
  0.001,

  /* Expression: -1.2
   * Referenced by: '<S10>/Gain2'
   */
  -1.2,

  /* Computed Parameter: Dctnotch_P1_Size_c
   * Referenced by: '<S10>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S10>/Dctnotch'
   */
  60.6,

  /* Computed Parameter: Dctnotch_P2_Size_ku
   * Referenced by: '<S10>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S10>/Dctnotch'
   */
  0.001,

  /* Computed Parameter: Dctnotch_P3_Size_f
   * Referenced by: '<S10>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S10>/Dctnotch'
   */
  77.0,

  /* Computed Parameter: Dctnotch_P4_Size_i
   * Referenced by: '<S10>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S10>/Dctnotch'
   */
  0.7,

  /* Computed Parameter: Dctnotch_P5_Size_o
   * Referenced by: '<S10>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S10>/Dctnotch'
   */
  0.001,

  /* Computed Parameter: Dctleadlag_P1_Size_e
   * Referenced by: '<S10>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S10>/Dctleadlag'
   */
  5.3045,

  /* Computed Parameter: Dctleadlag_P2_Size_l
   * Referenced by: '<S10>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S10>/Dctleadlag'
   */
  1000.0,

  /* Computed Parameter: Dctleadlag_P3_Size_k
   * Referenced by: '<S10>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S10>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dctnotch2_P1_Size_ob
   * Referenced by: '<S10>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S10>/Dctnotch2'
   */
  3.998,

  /* Computed Parameter: Dctnotch2_P2_Size_c
   * Referenced by: '<S10>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S10>/Dctnotch2'
   */
  0.5,

  /* Computed Parameter: Dctnotch2_P3_Size_k
   * Referenced by: '<S10>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S10>/Dctnotch2'
   */
  3.435,

  /* Computed Parameter: Dctnotch2_P4_Size_i
   * Referenced by: '<S10>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S10>/Dctnotch2'
   */
  0.0025,

  /* Computed Parameter: Dctnotch2_P5_Size_pa
   * Referenced by: '<S10>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S10>/Dctnotch2'
   */
  0.001,

  /* Computed Parameter: Dctdoubleintegrator6_P1_Size_o
   * Referenced by: '<S10>/Dctdoubleintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S10>/Dctdoubleintegrator6'
   */
  4.0,

  /* Computed Parameter: Dctdoubleintegrator6_P2_Size_f
   * Referenced by: '<S10>/Dctdoubleintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S10>/Dctdoubleintegrator6'
   */
  0.06,

  /* Computed Parameter: Dctdoubleintegrator6_P3_Size_f
   * Referenced by: '<S10>/Dctdoubleintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S10>/Dctdoubleintegrator6'
   */
  0.001,

  /* Computed Parameter: Dct2lowpass_P1_Size_k
   * Referenced by: '<S10>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S10>/Dct2lowpass'
   */
  120.0,

  /* Computed Parameter: Dct2lowpass_P2_Size_j
   * Referenced by: '<S10>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S10>/Dct2lowpass'
   */
  0.5,

  /* Computed Parameter: Dct2lowpass_P3_Size_m
   * Referenced by: '<S10>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S10>/Dct2lowpass'
   */
  0.001,

  /* Expression: -0.985
   * Referenced by: '<S12>/Gain2'
   */
  -0.985,

  /* Computed Parameter: Dctnotch_P1_Size_g
   * Referenced by: '<S12>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S12>/Dctnotch'
   */
  60.6,

  /* Computed Parameter: Dctnotch_P2_Size_l
   * Referenced by: '<S12>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S12>/Dctnotch'
   */
  0.001,

  /* Computed Parameter: Dctnotch_P3_Size_i
   * Referenced by: '<S12>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S12>/Dctnotch'
   */
  80.0,

  /* Computed Parameter: Dctnotch_P4_Size_n
   * Referenced by: '<S12>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S12>/Dctnotch'
   */
  0.7,

  /* Computed Parameter: Dctnotch_P5_Size_ov
   * Referenced by: '<S12>/Dctnotch'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S12>/Dctnotch'
   */
  0.001,

  /* Computed Parameter: Dctleadlag_P1_Size_o
   * Referenced by: '<S12>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S12>/Dctleadlag'
   */
  5.6,

  /* Computed Parameter: Dctleadlag_P2_Size_i
   * Referenced by: '<S12>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S12>/Dctleadlag'
   */
  600.0,

  /* Computed Parameter: Dctleadlag_P3_Size_mn
   * Referenced by: '<S12>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S12>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dctnotch2_P1_Size_a
   * Referenced by: '<S12>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S12>/Dctnotch2'
   */
  3.25,

  /* Computed Parameter: Dctnotch2_P2_Size_c2
   * Referenced by: '<S12>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S12>/Dctnotch2'
   */
  0.5,

  /* Computed Parameter: Dctnotch2_P3_Size_o
   * Referenced by: '<S12>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S12>/Dctnotch2'
   */
  3.25,

  /* Computed Parameter: Dctnotch2_P4_Size_d
   * Referenced by: '<S12>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S12>/Dctnotch2'
   */
  0.01,

  /* Computed Parameter: Dctnotch2_P5_Size_ol
   * Referenced by: '<S12>/Dctnotch2'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S12>/Dctnotch2'
   */
  0.001,

  /* Computed Parameter: Dctdoubleintegrator6_P1_Size_b
   * Referenced by: '<S12>/Dctdoubleintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S12>/Dctdoubleintegrator6'
   */
  3.7,

  /* Computed Parameter: Dctdoubleintegrator6_P2_Size_c
   * Referenced by: '<S12>/Dctdoubleintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S12>/Dctdoubleintegrator6'
   */
  0.18,

  /* Computed Parameter: Dctdoubleintegrator6_P3_Size_pk
   * Referenced by: '<S12>/Dctdoubleintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S12>/Dctdoubleintegrator6'
   */
  0.001,

  /* Computed Parameter: Dct2lowpass_P1_Size_j
   * Referenced by: '<S12>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S12>/Dct2lowpass'
   */
  140.0,

  /* Computed Parameter: Dct2lowpass_P2_Size_d
   * Referenced by: '<S12>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S12>/Dct2lowpass'
   */
  0.5,

  /* Computed Parameter: Dct2lowpass_P3_Size_p
   * Referenced by: '<S12>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S12>/Dct2lowpass'
   */
  0.001,

  /* Computed Parameter: Selectencoder_CurrentSetting
   * Referenced by: '<Root>/Select encoder'
   */
  0U
};
