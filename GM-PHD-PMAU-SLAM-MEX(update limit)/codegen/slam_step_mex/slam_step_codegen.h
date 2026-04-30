/*
 * slam_step_codegen.h
 *
 * Code generation for function 'slam_step_codegen'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "slam_step_codegen_types.h"
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

void slam_step_codegen(const emlrtStack *sp, const real_T xPrev[3],
                       const real_T PPrev[9], const real_T odom[2],
                       const real_T curMea_data[], const int32_T curMea_size[2],
                       const struct0_T mapIn_data[],
                       const int32_T mapIn_size[2], const struct1_T *params,
                       real_T T, boolean_T isLastStep, real_T xk[3],
                       real_T Pk[9], emxArray_struct0_T *mapOut);

/* End of code generation (slam_step_codegen.h) */
