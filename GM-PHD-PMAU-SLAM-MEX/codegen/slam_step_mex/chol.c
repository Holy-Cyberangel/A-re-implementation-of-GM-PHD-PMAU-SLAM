/*
 * chol.c
 *
 * Code generation for function 'chol'
 *
 */

/* Include files */
#include "chol.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
int32_T b_chol(real_T A[9], int32_T *jmax)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T beta1;
  real_T ssq_tmp;
  int32_T flag;
  int32_T idxAjj;
  int32_T info;
  int32_T j;
  int32_T k;
  char_T TRANSA;
  boolean_T exitg1;
  info = -1;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 3)) {
    real_T ssq;
    flag = j * 3;
    idxAjj = flag + j;
    ssq = 0.0;
    if (j >= 1) {
      for (k = 0; k < j; k++) {
        ssq_tmp = A[flag + k];
        ssq += ssq_tmp * ssq_tmp;
      }
    }
    ssq = A[idxAjj] - ssq;
    if (ssq > 0.0) {
      ssq = muDoubleScalarSqrt(ssq);
      A[idxAjj] = ssq;
      if (j + 1 < 3) {
        int32_T idxAjjp1;
        idxAjjp1 = idxAjj + 4;
        if (j >= 1) {
          ssq_tmp = -1.0;
          beta1 = 1.0;
          TRANSA = 'T';
          m_t = (ptrdiff_t)j;
          n_t = (ptrdiff_t)(2 - j);
          lda_t = (ptrdiff_t)3;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)3;
          dgemv(&TRANSA, &m_t, &n_t, &ssq_tmp, &A[flag + 3], &lda_t, &A[flag],
                &incx_t, &beta1, &A[idxAjj + 3], &incy_t);
        }
        ssq = 1.0 / ssq;
        idxAjj = (idxAjj + 3 * (1 - j)) + 4;
        for (k = idxAjjp1; k <= idxAjj; k += 3) {
          A[k - 1] *= ssq;
        }
      }
      j++;
    } else {
      A[idxAjj] = ssq;
      info = j;
      exitg1 = true;
    }
  }
  flag = info + 1;
  if (info + 1 == 0) {
    *jmax = 3;
  } else {
    *jmax = info;
  }
  for (k = 0; k <= *jmax - 2; k++) {
    idxAjj = k + 2;
    if (idxAjj <= *jmax) {
      memset(&A[(k * 3 + idxAjj) + -1], 0,
             (uint32_T)((*jmax - idxAjj) + 1) * sizeof(real_T));
    }
  }
  return flag;
}

int32_T chol(real_T A[4], int32_T *jmax)
{
  int32_T flag;
  int32_T info;
  int32_T j;
  int32_T k;
  boolean_T exitg1;
  info = -1;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 2)) {
    real_T ssq;
    int32_T idxAjj;
    flag = j << 1;
    idxAjj = flag + j;
    ssq = 0.0;
    if (j >= 1) {
      ssq = A[flag] * A[flag];
    }
    ssq = A[idxAjj] - ssq;
    if (ssq > 0.0) {
      ssq = muDoubleScalarSqrt(ssq);
      A[idxAjj] = ssq;
      if (j + 1 < 2) {
        flag = idxAjj + 3;
        ssq = 1.0 / ssq;
        for (k = flag; k <= flag; k += 2) {
          A[k - 1] *= ssq;
        }
      }
      j++;
    } else {
      A[idxAjj] = ssq;
      info = j;
      exitg1 = true;
    }
  }
  flag = info + 1;
  if (info + 1 == 0) {
    *jmax = 2;
  } else {
    *jmax = info;
  }
  if (*jmax - 2 >= 0) {
    for (k = 2; k <= *jmax; k++) {
      A[1] = 0.0;
    }
  }
  return flag;
}

/* End of code generation (chol.c) */
