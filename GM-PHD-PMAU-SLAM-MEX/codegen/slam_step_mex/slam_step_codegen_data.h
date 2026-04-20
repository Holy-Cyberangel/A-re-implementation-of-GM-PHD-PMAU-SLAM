/*
 * slam_step_codegen_data.h
 *
 * Code generation for function 'slam_step_codegen_data'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern const volatile char_T *emlrtBreakCheckR2012bFlagVar;
extern emlrtContext emlrtContextGlobal;
extern emlrtRSInfo r_emlrtRSI;
extern emlrtRSInfo gb_emlrtRSI;
extern emlrtRSInfo hb_emlrtRSI;
extern emlrtRSInfo ib_emlrtRSI;
extern emlrtRSInfo jb_emlrtRSI;
extern omp_lock_t emlrtLockGlobal;
extern omp_nest_lock_t slam_step_codegen_nestLockGlobal;

/* End of code generation (slam_step_codegen_data.h) */
