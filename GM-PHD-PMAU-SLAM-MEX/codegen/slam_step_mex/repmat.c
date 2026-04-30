/*
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "repmat.h"
#include "rt_nonfinite.h"
#include "slam_step_codegen_emxutil.h"
#include "slam_step_codegen_types.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo y_emlrtRSI = {
    34,                                                      /* lineNo */
    "repmat",                                                /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pathName */
};

static emlrtDCInfo emlrtDCI = {
    37,                                                       /* lineNo */
    14,                                                       /* colNo */
    "repmat",                                                 /* fName */
    "D:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m", /* pName */
    4                                                         /* checkKind */
};

static emlrtRTEInfo
    b_emlrtRTEI =
        {
            58,                   /* lineNo */
            23,                   /* colNo */
            "assertValidSizeArg", /* fName */
            "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\assertValidSizeArg.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    67,                                                      /* lineNo */
    9,                                                       /* colNo */
    "repmat",                                                /* fName */
    "D:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pName */
};

/* Function Definitions */
void repmat(const emlrtStack *sp, real_T varargin_2, emxArray_struct0_T *b)
{
  emlrtStack st;
  struct0_T s;
  struct0_T *b_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &y_emlrtRSI;
  if ((varargin_2 != muDoubleScalarFloor(varargin_2)) ||
      muDoubleScalarIsInf(varargin_2) || (varargin_2 < -2.147483648E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &b_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (!(varargin_2 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_2, &emlrtDCI, (emlrtConstCTX)sp);
  }
  s.m[0] = 0.0;
  s.m[1] = 0.0;
  s.w = 0.0;
  s.P[0] = 0.0;
  s.P[1] = 0.0;
  s.P[2] = 0.0;
  s.P[3] = 0.0;
  i = b->size[0] * b->size[1];
  b->size[0] = 1;
  loop_ub = (int32_T)varargin_2;
  b->size[1] = (int32_T)varargin_2;
  emxEnsureCapacity_struct0_T(sp, b, i, &k_emlrtRTEI);
  b_data = b->data;
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_data[i1] = s;
  }
}

/* End of code generation (repmat.c) */
