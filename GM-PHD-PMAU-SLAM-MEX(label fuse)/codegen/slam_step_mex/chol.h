/*
 * chol.h
 *
 * Code generation for function 'chol'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
int32_T b_chol(real_T A[9], int32_T *jmax);

int32_T chol(real_T A[4], int32_T *jmax);

/* End of code generation (chol.h) */
