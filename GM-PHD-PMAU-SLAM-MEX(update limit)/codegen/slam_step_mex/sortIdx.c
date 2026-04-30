/*
 * sortIdx.c
 *
 * Code generation for function 'sortIdx'
 *
 */

/* Include files */
#include "sortIdx.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "slam_step_codegen_data.h"
#include "slam_step_codegen_types.h"

/* Variable Definitions */
static emlrtRSInfo td_emlrtRSI = {
    488,                                                          /* lineNo */
    "merge_block",                                                /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo vd_emlrtRSI = {
    496,                                                          /* lineNo */
    "merge_block",                                                /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo wd_emlrtRSI = {
    503,                                                          /* lineNo */
    "merge_block",                                                /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo xd_emlrtRSI = {
    550,                                                          /* lineNo */
    "merge",                                                      /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo yd_emlrtRSI = {
    519,                                                          /* lineNo */
    "merge",                                                      /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

/* Function Declarations */
static void merge(const emlrtStack *sp, emxArray_int32_T *idx,
                  emxArray_real_T *x, int32_T offset, int32_T np, int32_T nq,
                  emxArray_int32_T *iwork, emxArray_real_T *xwork);

/* Function Definitions */
static void merge(const emlrtStack *sp, emxArray_int32_T *idx,
                  emxArray_real_T *x, int32_T offset, int32_T np, int32_T nq,
                  emxArray_int32_T *iwork, emxArray_real_T *xwork)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T *x_data;
  real_T *xwork_data;
  int32_T j;
  int32_T *idx_data;
  int32_T *iwork_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  xwork_data = xwork->data;
  iwork_data = iwork->data;
  x_data = x->data;
  idx_data = idx->data;
  if (nq != 0) {
    int32_T iout;
    int32_T n;
    int32_T p;
    int32_T q;
    n = np + nq;
    st.site = &yd_emlrtRSI;
    if (n > 2147483646) {
      b_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (j = 0; j < n; j++) {
      q = offset + j;
      iwork_data[j] = idx_data[q];
      xwork_data[j] = x_data[q];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    int32_T exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork_data[p] >= xwork_data[q]) {
        idx_data[iout] = iwork_data[p];
        x_data[iout] = xwork_data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x_data[iout] = xwork_data[q];
        if (q + 1 < n) {
          q++;
        } else {
          q = iout - p;
          st.site = &xd_emlrtRSI;
          if ((p + 1 <= np) && (np > 2147483646)) {
            b_st.site = &r_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }
          for (j = p + 1; j <= np; j++) {
            iout = q + j;
            idx_data[iout] = iwork_data[j - 1];
            x_data[iout] = xwork_data[j - 1];
          }
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

void merge_block(const emlrtStack *sp, emxArray_int32_T *idx,
                 emxArray_real_T *x, int32_T offset, int32_T n,
                 int32_T preSortLevel, emxArray_int32_T *iwork,
                 emxArray_real_T *xwork)
{
  emlrtStack st;
  int32_T bLen;
  int32_T k;
  int32_T nPairs;
  st.prev = sp;
  st.tls = sp->tls;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    int32_T tailOffset;
    if (((uint32_T)nPairs & 1U) != 0U) {
      int32_T nTail;
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        st.site = &td_emlrtRSI;
        merge(&st, idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
              xwork);
      }
    }
    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (k = 0; k < nPairs; k++) {
      st.site = &vd_emlrtRSI;
      merge(&st, idx, x, offset + k * tailOffset, bLen, bLen, iwork, xwork);
    }
    bLen = tailOffset;
  }
  if (n > bLen) {
    st.site = &wd_emlrtRSI;
    merge(&st, idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

/* End of code generation (sortIdx.c) */
