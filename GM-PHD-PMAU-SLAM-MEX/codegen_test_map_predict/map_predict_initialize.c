/*
 * map_predict_initialize.c
 *
 * Code generation for function 'map_predict_initialize'
 *
 */

/* Include files */
#include "map_predict_initialize.h"
#include "_coder_map_predict_mex.h"
#include "map_predict_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void map_predict_once(void);

/* Function Definitions */
static void map_predict_once(void)
{
  mex_InitInfAndNan();
}

void map_predict_initialize(void)
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
    map_predict_once();
  }
}

/* End of code generation (map_predict_initialize.c) */
