/*
 * sort.c
 *
 * Code generation for function 'sort'
 *
 */

/* Include files */
#include "sort.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "slam_step_codegen_data.h"
#include "slam_step_codegen_emxutil.h"
#include "slam_step_codegen_types.h"
#include "sortIdx.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo fd_emlrtRSI = {
    72,                                                        /* lineNo */
    "sort",                                                    /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" /* pathName */
};

static emlrtRSInfo gd_emlrtRSI = {
    105,                                                          /* lineNo */
    "sortIdx",                                                    /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo hd_emlrtRSI = {
    301,                                                          /* lineNo */
    "block_merge_sort",                                           /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo id_emlrtRSI = {
    309,                                                          /* lineNo */
    "block_merge_sort",                                           /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo jd_emlrtRSI = {
    310,                                                          /* lineNo */
    "block_merge_sort",                                           /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo kd_emlrtRSI = {
    318,                                                          /* lineNo */
    "block_merge_sort",                                           /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo ld_emlrtRSI = {
    326,                                                          /* lineNo */
    "block_merge_sort",                                           /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo md_emlrtRSI = {
    333,                                                          /* lineNo */
    "block_merge_sort",                                           /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo nd_emlrtRSI = {
    381,                                                          /* lineNo */
    "initialize_vector_sort",                                     /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo od_emlrtRSI = {
    409,                                                          /* lineNo */
    "initialize_vector_sort",                                     /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo pd_emlrtRSI = {
    416,                                                          /* lineNo */
    "initialize_vector_sort",                                     /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo qd_emlrtRSI = {
    576,                                                          /* lineNo */
    "merge_pow2_block",                                           /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo rd_emlrtRSI = {
    578,                                                          /* lineNo */
    "merge_pow2_block",                                           /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo sd_emlrtRSI = {
    606,                                                          /* lineNo */
    "merge_pow2_block",                                           /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo ae_emlrtRSI = {
    347,                                                          /* lineNo */
    "shift_NaNs",                                                 /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo be_emlrtRSI = {
    356,                                                          /* lineNo */
    "shift_NaNs",                                                 /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pathName */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    56,                                                           /* lineNo */
    5,                                                            /* colNo */
    "sortIdx",                                                    /* fName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = {
    296,                                                          /* lineNo */
    1,                                                            /* colNo */
    "sortIdx",                                                    /* fName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    298,                                                          /* lineNo */
    24,                                                           /* colNo */
    "sortIdx",                                                    /* fName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = {
    298,                                                          /* lineNo */
    1,                                                            /* colNo */
    "sortIdx",                                                    /* fName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" /* pName */
};

/* Function Definitions */
void sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_int32_T *iwork;
  emxArray_real_T *xwork;
  real_T x4[4];
  real_T *x_data;
  real_T *xwork_data;
  int32_T b;
  int32_T bLen;
  int32_T bLen2;
  int32_T b_b;
  int32_T b_k;
  int32_T i1;
  int32_T i2;
  int32_T i4;
  int32_T ib;
  int32_T k;
  int32_T loop_ub;
  int32_T nNaNs;
  int32_T quartetOffset;
  int32_T wOffset;
  int32_T *idx_data;
  int32_T *iwork_data;
  int16_T idx4[4];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &fd_emlrtRSI;
  i1 = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  loop_ub = x->size[1];
  idx->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(&st, idx, i1, &jb_emlrtRTEI);
  idx_data = idx->data;
  for (k = 0; k < loop_ub; k++) {
    idx_data[k] = 0;
  }
  b_st.site = &gd_emlrtRSI;
  emxInit_int32_T(&b_st, &iwork, 1, &kb_emlrtRTEI);
  i1 = iwork->size[0];
  iwork->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(&b_st, iwork, i1, &kb_emlrtRTEI);
  iwork_data = iwork->data;
  for (k = 0; k < loop_ub; k++) {
    iwork_data[k] = 0;
  }
  emxInit_real_T(&b_st, &xwork, 1, &mb_emlrtRTEI);
  i1 = xwork->size[0];
  xwork->size[0] = loop_ub;
  emxEnsureCapacity_real_T(&b_st, xwork, i1, &lb_emlrtRTEI);
  xwork_data = xwork->data;
  c_st.site = &hd_emlrtRSI;
  x4[0] = 0.0;
  idx4[0] = 0;
  x4[1] = 0.0;
  idx4[1] = 0;
  x4[2] = 0.0;
  idx4[2] = 0;
  x4[3] = 0.0;
  idx4[3] = 0;
  nNaNs = 0;
  ib = 0;
  d_st.site = &nd_emlrtRSI;
  for (k = 0; k < loop_ub; k++) {
    if (muDoubleScalarIsNaN(x_data[k])) {
      i1 = (loop_ub - nNaNs) - 1;
      idx_data[i1] = k + 1;
      xwork_data[i1] = x_data[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = (int16_T)(k + 1);
      x4[ib - 1] = x_data[k];
      if (ib == 4) {
        real_T d;
        real_T d1;
        quartetOffset = k - nNaNs;
        if (x4[0] >= x4[1]) {
          i1 = 1;
          i2 = 2;
        } else {
          i1 = 2;
          i2 = 1;
        }
        if (x4[2] >= x4[3]) {
          ib = 3;
          i4 = 4;
        } else {
          ib = 4;
          i4 = 3;
        }
        d = x4[i1 - 1];
        d1 = x4[ib - 1];
        if (d >= d1) {
          real_T d2;
          d2 = x4[i2 - 1];
          if (d2 >= d1) {
            bLen = i1;
            bLen2 = i2;
            i1 = ib;
            i2 = i4;
          } else if (d2 >= x4[i4 - 1]) {
            bLen = i1;
            bLen2 = ib;
            i1 = i2;
            i2 = i4;
          } else {
            bLen = i1;
            bLen2 = ib;
            i1 = i4;
          }
        } else {
          real_T d2;
          d2 = x4[i4 - 1];
          if (d >= d2) {
            if (x4[i2 - 1] >= d2) {
              bLen = ib;
              bLen2 = i1;
              i1 = i2;
              i2 = i4;
            } else {
              bLen = ib;
              bLen2 = i1;
              i1 = i4;
            }
          } else {
            bLen = ib;
            bLen2 = i4;
          }
        }
        idx_data[quartetOffset - 3] = idx4[bLen - 1];
        idx_data[quartetOffset - 2] = idx4[bLen2 - 1];
        idx_data[quartetOffset - 1] = idx4[i1 - 1];
        idx_data[quartetOffset] = idx4[i2 - 1];
        x_data[quartetOffset - 3] = x4[bLen - 1];
        x_data[quartetOffset - 2] = x4[bLen2 - 1];
        x_data[quartetOffset - 1] = x4[i1 - 1];
        x_data[quartetOffset] = x4[i2 - 1];
        ib = 0;
      }
    }
  }
  wOffset = x->size[1] - nNaNs;
  if (ib > 0) {
    int8_T perm[4];
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] >= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] >= x4[1]) {
      if (x4[1] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }
    d_st.site = &od_emlrtRSI;
    if (ib > 2147483646) {
      e_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    i1 = (uint8_T)ib;
    for (k = 0; k < i1; k++) {
      quartetOffset = (wOffset - ib) + k;
      i2 = perm[k];
      idx_data[quartetOffset] = idx4[i2 - 1];
      x_data[quartetOffset] = x4[i2 - 1];
    }
  }
  i1 = nNaNs >> 1;
  d_st.site = &pd_emlrtRSI;
  for (k = 0; k < i1; k++) {
    quartetOffset = wOffset + k;
    i2 = idx_data[quartetOffset];
    ib = (loop_ub - k) - 1;
    idx_data[quartetOffset] = idx_data[ib];
    idx_data[ib] = i2;
    x_data[quartetOffset] = xwork_data[ib];
    x_data[ib] = xwork_data[quartetOffset];
  }
  if (((uint32_T)nNaNs & 1U) != 0U) {
    i1 += wOffset;
    x_data[i1] = xwork_data[i1];
  }
  i1 = 2;
  if (wOffset > 1) {
    if (x->size[1] >= 256) {
      int32_T nBlocks;
      nBlocks = wOffset >> 8;
      if (nBlocks > 0) {
        c_st.site = &id_emlrtRSI;
        for (b = 0; b < nBlocks; b++) {
          real_T b_xwork[256];
          int16_T b_iwork[256];
          c_st.site = &jd_emlrtRSI;
          i4 = (b << 8) - 1;
          for (b_b = 0; b_b < 6; b_b++) {
            bLen = 1 << (b_b + 2);
            bLen2 = bLen << 1;
            loop_ub = 256 >> (b_b + 3);
            d_st.site = &qd_emlrtRSI;
            for (b_k = 0; b_k < loop_ub; b_k++) {
              i1 = (i4 + b_k * bLen2) + 1;
              d_st.site = &rd_emlrtRSI;
              for (k = 0; k < bLen2; k++) {
                ib = i1 + k;
                b_iwork[k] = (int16_T)idx_data[ib];
                b_xwork[k] = x_data[ib];
              }
              i2 = 0;
              quartetOffset = bLen;
              ib = i1 - 1;
              int32_T exitg1;
              do {
                exitg1 = 0;
                ib++;
                if (b_xwork[i2] >= b_xwork[quartetOffset]) {
                  idx_data[ib] = b_iwork[i2];
                  x_data[ib] = b_xwork[i2];
                  if (i2 + 1 < bLen) {
                    i2++;
                  } else {
                    exitg1 = 1;
                  }
                } else {
                  idx_data[ib] = b_iwork[quartetOffset];
                  x_data[ib] = b_xwork[quartetOffset];
                  if (quartetOffset + 1 < bLen2) {
                    quartetOffset++;
                  } else {
                    ib -= i2;
                    d_st.site = &sd_emlrtRSI;
                    for (k = i2 + 1; k <= bLen; k++) {
                      quartetOffset = ib + k;
                      idx_data[quartetOffset] = b_iwork[k - 1];
                      x_data[quartetOffset] = b_xwork[k - 1];
                    }
                    exitg1 = 1;
                  }
                }
              } while (exitg1 == 0);
            }
          }
        }
        i1 = nBlocks << 8;
        quartetOffset = wOffset - i1;
        if (quartetOffset > 0) {
          c_st.site = &kd_emlrtRSI;
          merge_block(&c_st, idx, x, i1, quartetOffset, 2, iwork, xwork);
        }
        i1 = 8;
      }
    }
    c_st.site = &ld_emlrtRSI;
    merge_block(&c_st, idx, x, 0, wOffset, i1, iwork, xwork);
    xwork_data = xwork->data;
    iwork_data = iwork->data;
    x_data = x->data;
    idx_data = idx->data;
  }
  if ((nNaNs > 0) && (wOffset > 0)) {
    c_st.site = &md_emlrtRSI;
    d_st.site = &ae_emlrtRSI;
    for (k = 0; k < nNaNs; k++) {
      i1 = wOffset + k;
      xwork_data[k] = x_data[i1];
      iwork_data[k] = idx_data[i1];
    }
    for (k = wOffset; k >= 1; k--) {
      i1 = (nNaNs + k) - 1;
      x_data[i1] = x_data[k - 1];
      idx_data[i1] = idx_data[k - 1];
    }
    d_st.site = &be_emlrtRSI;
    for (k = 0; k < nNaNs; k++) {
      x_data[k] = xwork_data[k];
      idx_data[k] = iwork_data[k];
    }
  }
  emxFree_real_T(&b_st, &xwork);
  emxFree_int32_T(&b_st, &iwork);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (sort.c) */
