/*
 * slam_step_codegen_internal_types.h
 *
 * Code generation for function 'slam_step_codegen'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "slam_step_codegen_types.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_rtDesignRangeCheckInfo
#define typedef_rtDesignRangeCheckInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtDesignRangeCheckInfo;
#endif /* typedef_rtDesignRangeCheckInfo */

#ifndef typedef_rtRunTimeErrorInfo
#define typedef_rtRunTimeErrorInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtRunTimeErrorInfo;
#endif /* typedef_rtRunTimeErrorInfo */

/* End of code generation (slam_step_codegen_internal_types.h) */
