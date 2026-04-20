/*
 * map_predict_data.c
 *
 * Code generation for function 'map_predict_data'
 *
 */

/* Include files */
#include "map_predict_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131674U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "map_predict",                                        /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t map_predict_nestLockGlobal;

/* End of code generation (map_predict_data.c) */
