/*
 * map_predict.h
 *
 * Code generation for function 'map_predict'
 *
 */

#pragma once

/* Include files */
#include "map_predict_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
emlrtCTX emlrtGetRootTLSGlobal(void);

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

void map_predict(const emlrtStack *sp, const real_T x_[3],
                 const struct0_T map_data[], const int32_T map_size[2],
                 const struct1_T *params, boolean_T idx_data[],
                 int32_T idx_size[2]);

/* End of code generation (map_predict.h) */
