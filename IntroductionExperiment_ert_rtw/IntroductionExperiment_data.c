/*
 * IntroductionExperiment_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "IntroductionExperiment".
 *
 * Model version              : 7.7
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Mar 20 10:31:02 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "IntroductionExperiment.h"
#include "IntroductionExperiment_private.h"

/* Block parameters (default storage) */
P_IntroductionExperiment_T IntroductionExperiment_P = {
  /* Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S7>/S-Function'
   */
  { 3.0, 6.0 },

  /* Variable: ref_part
   * Referenced by: '<S7>/S-Function'
   */
  { 0.0, 6.2832, 0.0, 1.5, 4.5, -1.0, 6.2832, 0.0, 0.0, 5.0, 5.0, 0.0,
    0.22499999999999998, 0.22499999999999998, 0.0, 1000.0, 1000.0, 0.0 },

  /* Mask Parameter: Refpower_stat
   * Referenced by: '<S6>/Start setpoint'
   */
  1.0,

  /* Mask Parameter: MeasurementBlock_N_samples
   * Referenced by: '<S4>/SPERTE_measurement_samples'
   */
  160000U,

  /* Mask Parameter: MeasurementBlock_trigger_comman
   * Referenced by: '<S4>/SPERTE_measurement_trigger_command'
   */
  0U,

  /* Mask Parameter: MeasurementBlock_triggertype
   * Referenced by: '<S4>/SPERTE_measurement_function'
   */
  2U,

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

  /* Expression: (2*pi)/(4*500)
   * Referenced by: '<S3>/count2rad'
   */
  0.0031415926535897933,

  /* Expression: 0.65
   * Referenced by: '<S1>/Gain1'
   */
  0.65,

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
  18.0,

  /* Computed Parameter: Dctleadlag_P3_Size
   * Referenced by: '<S1>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S1>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dct2lowpass_P1_Size
   * Referenced by: '<S1>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S1>/Dct2lowpass'
   */
  40.0,

  /* Computed Parameter: Dct2lowpass_P2_Size
   * Referenced by: '<S1>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S1>/Dct2lowpass'
   */
  1.0,

  /* Computed Parameter: Dct2lowpass_P3_Size
   * Referenced by: '<S1>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S1>/Dct2lowpass'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S2>/Kfa'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Kfv'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Kfp'
   */
  0.0,

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
   * Referenced by: '<S8>/Gain'
   */
  0.01,

  /* Expression: 2.5
   * Referenced by: '<S3>/Saturation'
   */
  2.5,

  /* Expression: -2.5
   * Referenced by: '<S3>/Saturation'
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
  1U
};
