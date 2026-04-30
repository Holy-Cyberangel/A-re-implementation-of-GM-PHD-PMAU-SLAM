/*
 * slam_step_codegen_data.c
 *
 * Code generation for function 'slam_step_codegen_data'
 *
 */

/* Include files */
#include "slam_step_codegen_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131674U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "slam_step_codegen",                                  /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

emlrtRSInfo r_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_"
    "check.m" /* pathName */
};

emlrtRSInfo jb_emlrtRSI = {
    42,      /* lineNo */
    "mrdiv", /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_helper.m" /* pathName
                                                                           */
};

emlrtRSInfo kb_emlrtRSI = {
    55,                                                           /* lineNo */
    "lusolve",                                                    /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" /* pathName */
};

emlrtRSInfo lb_emlrtRSI = {
    210,                                                          /* lineNo */
    "lusolve2x2",                                                 /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" /* pathName */
};

emlrtRSInfo mb_emlrtRSI = {
    90,                                                           /* lineNo */
    "warn_singular",                                              /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" /* pathName */
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t slam_step_codegen_nestLockGlobal;

/* End of code generation (slam_step_codegen_data.c) */
