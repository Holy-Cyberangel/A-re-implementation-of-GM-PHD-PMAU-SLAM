/*
 * slam_step_codegen_initialize.c
 *
 * Code generation for function 'slam_step_codegen_initialize'
 *
 */

/* Include files */
#include "slam_step_codegen_initialize.h"
#include "_coder_slam_step_codegen_mex.h"
#include "rt_nonfinite.h"
#include "slam_step_codegen_data.h"

/* Function Declarations */
static void slam_step_codegen_once(void);

/* Function Definitions */
static void slam_step_codegen_once(void)
{
  mex_InitInfAndNan();
}

void slam_step_codegen_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    slam_step_codegen_once();
  }
}

/* End of code generation (slam_step_codegen_initialize.c) */
