/*
 * mrdivide_helper.c
 *
 * Code generation for function 'mrdivide_helper'
 *
 */

/* Include files */
#include "mrdivide_helper.h"
#include "rt_nonfinite.h"
#include "slam_step_codegen_data.h"
#include "warning.h"
#include "mwmathutil.h"

/* Function Definitions */
void mrdiv(const emlrtStack *sp, const real_T A[2], const real_T B[4],
           real_T Y[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T a21;
  real_T a22;
  real_T a22_tmp;
  int32_T r1;
  int32_T r2;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  st.site = &jb_emlrtRSI;
  b_st.site = &kb_emlrtRSI;
  if (muDoubleScalarAbs(B[1]) > muDoubleScalarAbs(B[0])) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }
  a21 = B[r2] / B[r1];
  a22_tmp = B[r1 + 2];
  a22 = B[r2 + 2] - a21 * a22_tmp;
  if ((a22 == 0.0) || (B[r1] == 0.0)) {
    c_st.site = &lb_emlrtRSI;
    if (!emlrtSetWarningFlag(&c_st)) {
      d_st.site = &mb_emlrtRSI;
      warning(&d_st);
    }
  }
  Y[r1] = A[0] / B[r1];
  Y[r2] = (A[1] - Y[r1] * a22_tmp) / a22;
  Y[r1] -= Y[r2] * a21;
}

/* End of code generation (mrdivide_helper.c) */
