/*
 * map_predict.c
 *
 * Code generation for function 'map_predict'
 *
 */

/* Include files */
#include "map_predict.h"
#include "map_predict_data.h"
#include "map_predict_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "omp.h"
#include <string.h>

/* Variable Definitions */
static emlrtBCInfo emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    8,             /* lineNo */
    22,            /* colNo */
    "map",         /* aName */
    "map_predict", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\map_predict.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    9,             /* lineNo */
    22,            /* colNo */
    "map",         /* aName */
    "map_predict", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\map_predict.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    13,            /* lineNo */
    21,            /* colNo */
    "idx",         /* aName */
    "map_predict", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\map_predict.m", /* pName */
    0                                               /* checkKind */
};

/* Function Definitions */
emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

void map_predict(const emlrtStack *sp, const real_T x_[3],
                 const struct0_T map_data[], const int32_T map_size[2],
                 const struct1_T *params, boolean_T idx_data[],
                 int32_T idx_size[2])
{
  int32_T i;
  int32_T loop_ub;
  idx_size[0] = 1;
  loop_ub = map_size[1];
  idx_size[1] = map_size[1];
  if (loop_ub - 1 >= 0) {
    memset(&idx_data[0], 0, (uint32_T)loop_ub * sizeof(boolean_T));
  }
  for (i = 0; i < loop_ub; i++) {
    real_T dx;
    real_T dy;
    real_T x;
    if (i + 1 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, loop_ub, &emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    dx = map_data[i].m[0] - x_[0];
    if (i + 1 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, loop_ub, &b_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    dy = map_data[i].m[1] - x_[1];
    x = (muDoubleScalarAtan2(dy, dx) - x_[2]) + 3.1415926535897931;
    if (muDoubleScalarIsNaN(x) || muDoubleScalarIsInf(x)) {
      x = rtNaN;
    } else {
      real_T q;
      q = muDoubleScalarAbs(x / 6.2831853071795862);
      if (muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) >
          2.2204460492503131E-16 * q) {
        x = muDoubleScalarRem(x, 6.2831853071795862);
      } else {
        x = 0.0;
      }
      if (x == 0.0) {
        x = 0.0;
      } else if (x < 0.0) {
        x += 6.2831853071795862;
      }
    }
    if ((muDoubleScalarSqrt(dx * dx + dy * dy) <= params->fov_range) &&
        (muDoubleScalarAbs(x - 3.1415926535897931) <= params->fov_angle)) {
      if (i + 1 > idx_size[1]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, idx_size[1], &c_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      idx_data[i] = true;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
}

/* End of code generation (map_predict.c) */
