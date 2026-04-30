/*
 * slam_step_codegen.c
 *
 * Code generation for function 'slam_step_codegen'
 *
 */

/* Include files */
#include "slam_step_codegen.h"
#include "chol.h"
#include "det.h"
#include "inv.h"
#include "mrdivide_helper.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "slam_step_codegen_data.h"
#include "slam_step_codegen_emxutil.h"
#include "slam_step_codegen_types.h"
#include "sort.h"
#include "warning.h"
#include "mwmathutil.h"
#include "omp.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo b_emlrtRSI = {
    6,                   /* lineNo */
    "slam_step_codegen", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    11,                  /* lineNo */
    "slam_step_codegen", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    12,                  /* lineNo */
    "slam_step_codegen", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    14,                  /* lineNo */
    "slam_step_codegen", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    15,                  /* lineNo */
    "slam_step_codegen", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    16,                  /* lineNo */
    "slam_step_codegen", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    21,                  /* lineNo */
    "slam_step_codegen", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    25,                  /* lineNo */
    "slam_step_codegen", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo t_emlrtRSI = {
    71,                       /* lineNo */
    "split_map_by_fov_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    72,                       /* lineNo */
    "split_map_by_fov_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo w_emlrtRSI = {
    93,                       /* lineNo */
    "split_map_by_fov_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo x_emlrtRSI = {
    94,                       /* lineNo */
    "split_map_by_fov_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = {
    148,                    /* lineNo */
    "pose_update_mm_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI = {
    154,                    /* lineNo */
    "pose_update_mm_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    200,                    /* lineNo */
    "pose_update_mm_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo db_emlrtRSI = {
    208,                    /* lineNo */
    "pose_update_mm_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    209,                    /* lineNo */
    "pose_update_mm_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    215,                    /* lineNo */
    "pose_update_mm_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo gb_emlrtRSI = {
    216,                    /* lineNo */
    "pose_update_mm_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo hb_emlrtRSI = {
    237,                    /* lineNo */
    "pose_update_mm_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo ib_emlrtRSI = {
    20,                /* lineNo */
    "mrdivide_helper", /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_helper.m" /* pathName
                                                                           */
};

static emlrtRSInfo nb_emlrtRSI = {
    745,                /* lineNo */
    "likelihood_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    746,                /* lineNo */
    "likelihood_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo mc_emlrtRSI = {
    395,                /* lineNo */
    "map_update_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo nc_emlrtRSI = {
    405,                /* lineNo */
    "map_update_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo oc_emlrtRSI = {
    431,                /* lineNo */
    "map_update_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo pc_emlrtRSI = {
    449,                /* lineNo */
    "map_update_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo qc_emlrtRSI = {
    479,                /* lineNo */
    "map_update_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI = {
    485,                /* lineNo */
    "map_update_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    499,                /* lineNo */
    "map_update_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI = {
    685,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    684,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo vc_emlrtRSI = {
    680,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo wc_emlrtRSI = {
    663,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo xc_emlrtRSI = {
    626,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo yc_emlrtRSI = {
    618,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo ad_emlrtRSI = {
    604,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo bd_emlrtRSI = {
    601,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo cd_emlrtRSI = {
    586,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo dd_emlrtRSI = {
    580,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo ed_emlrtRSI = {
    37,                                                      /* lineNo */
    "sort",                                                  /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" /* pathName */
};

static emlrtRSInfo ce_emlrtRSI = {
    20,                                                      /* lineNo */
    "mldivide",                                              /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pathName */
};

static emlrtRSInfo de_emlrtRSI = {
    42,                                                      /* lineNo */
    "mldiv",                                                 /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pathName */
};

static emlrtRSInfo ee_emlrtRSI = {
    694,           /* lineNo */
    "birth_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRSInfo fe_emlrtRSI = {
    716,           /* lineNo */
    "birth_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    10,                  /* lineNo */
    16,                  /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtECInfo emlrtECI = {
    -1,                 /* nDims */
    60,                 /* lineNo */
    5,                  /* colNo */
    "preprocess_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    -1,                 /* nDims */
    59,                 /* lineNo */
    5,                  /* colNo */
    "preprocess_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    63,                 /* lineNo */
    47,                 /* colNo */
    "theta",            /* aName */
    "preprocess_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    63,                 /* lineNo */
    32,                 /* colNo */
    "r",                /* aName */
    "preprocess_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    63,                 /* lineNo */
    24,                 /* colNo */
    "theta",            /* aName */
    "preprocess_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    65,                 /* lineNo */
    20,                 /* colNo */
    "Rstack",           /* aName */
    "preprocess_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    723,                /* lineNo */
    26,                 /* colNo */
    "mapIn",            /* aName */
    "resize_map_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    80,                       /* lineNo */
    20,                       /* colNo */
    "mapIn",                  /* aName */
    "split_map_by_fov_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    81,                       /* lineNo */
    20,                       /* colNo */
    "mapIn",                  /* aName */
    "split_map_by_fov_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    89,                       /* lineNo */
    40,                       /* colNo */
    "mapIn",                  /* aName */
    "split_map_by_fov_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    89,                       /* lineNo */
    21,                       /* colNo */
    "keepMap",                /* aName */
    "split_map_by_fov_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    86,                       /* lineNo */
    38,                       /* colNo */
    "mapIn",                  /* aName */
    "split_map_by_fov_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    86,                       /* lineNo */
    20,                       /* colNo */
    "visMap",                 /* aName */
    "split_map_by_fov_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    13,                                                    /* lineNo */
    9,                                                     /* colNo */
    "sqrt",                                                /* fName */
    "D:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" /* pName */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    416,                /* lineNo */
    40,                 /* colNo */
    "Z",                /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    421,                /* lineNo */
    47,                 /* colNo */
    "RstackLocal",      /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    447,                /* lineNo */
    23,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    421,                /* lineNo */
    20,                 /* colNo */
    "Rworld",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    447,                /* lineNo */
    41,                 /* colNo */
    "Rworld",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    449,                /* lineNo */
    88,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    449,                /* lineNo */
    47,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    449,                /* lineNo */
    60,                 /* colNo */
    "Zmap",             /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    472,                /* lineNo */
    52,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    472,                /* lineNo */
    32,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    478,                /* lineNo */
    35,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    478,                /* lineNo */
    53,                 /* colNo */
    "Rworld",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    479,                /* lineNo */
    35,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    480,                /* lineNo */
    48,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    480,                /* lineNo */
    37,                 /* colNo */
    "Zmap",             /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    431,                /* lineNo */
    61,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    431,                /* lineNo */
    20,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    469,                /* lineNo */
    30,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    452,                /* lineNo */
    25,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    489,                /* lineNo */
    60,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    401,                /* lineNo */
    36,                 /* colNo */
    "keepMap",          /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    401,                /* lineNo */
    16,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    418,                /* lineNo */
    19,                 /* colNo */
    "Z",                /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    419,                /* lineNo */
    19,                 /* colNo */
    "Z",                /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    426,                /* lineNo */
    23,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    432,                /* lineNo */
    20,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    466,                /* lineNo */
    31,                 /* colNo */
    "rawLike_i",        /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    473,                /* lineNo */
    32,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    476,                /* lineNo */
    34,                 /* colNo */
    "birthIdx",         /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    457,                /* lineNo */
    23,                 /* colNo */
    "rawLike_i",        /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    459,                /* lineNo */
    41,                 /* colNo */
    "rawLike_i",        /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    485,                /* lineNo */
    32,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    486,                /* lineNo */
    32,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    491,                /* lineNo */
    34,                 /* colNo */
    "birthIdx",         /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    475,                /* lineNo */
    25,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    475,                /* lineNo */
    50,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    471,                /* lineNo */
    25,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    471,                /* lineNo */
    46,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    488,                /* lineNo */
    25,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    488,                /* lineNo */
    50,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    88,                  /* lineNo */
    13,                  /* colNo */
    "mapOut",            /* aName */
    "eml_mtimes_helper", /* fName */
    "D:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    484,                /* lineNo */
    25,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    484,                /* lineNo */
    46,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    434,                /* lineNo */
    13,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    434,                /* lineNo */
    38,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    430,                /* lineNo */
    13,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    430,                /* lineNo */
    34,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    595,            /* lineNo */
    23,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    609,            /* lineNo */
    21,             /* colNo */
    "order",        /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    621,            /* lineNo */
    25,             /* colNo */
    "order",        /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    640,            /* lineNo */
    28,             /* colNo */
    "members",      /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    642,            /* lineNo */
    40,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    642,            /* lineNo */
    57,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    655,            /* lineNo */
    28,             /* colNo */
    "members",      /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    657,            /* lineNo */
    52,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    684,             /* lineNo */
    39,              /* colNo */
    "mergedWeights", /* aName */
    "tuning_local",  /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = {
    686,            /* lineNo */
    13,             /* colNo */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtBCInfo rc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    586,            /* lineNo */
    64,             /* colNo */
    "mapIn",        /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    586,            /* lineNo */
    20,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    618,            /* lineNo */
    42,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    663,            /* lineNo */
    16,             /* colNo */
    "merged",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    583,            /* lineNo */
    18,             /* colNo */
    "mapIn",        /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    599,            /* lineNo */
    29,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    599,            /* lineNo */
    17,             /* colNo */
    "weights",      /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    587,            /* lineNo */
    43,             /* colNo */
    "mapIn",        /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    587,            /* lineNo */
    20,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    610,            /* lineNo */
    17,             /* colNo */
    "used",         /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    613,            /* lineNo */
    14,             /* colNo */
    "used",         /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    622,            /* lineNo */
    21,             /* colNo */
    "used",         /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    687,            /* lineNo */
    28,             /* colNo */
    "merged",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    687,            /* lineNo */
    34,             /* colNo */
    "order",        /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    687,            /* lineNo */
    16,             /* colNo */
    "mapOut",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    641,            /* lineNo */
    44,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    664,            /* lineNo */
    16,             /* colNo */
    "merged",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    665,             /* lineNo */
    23,              /* colNo */
    "mergedWeights", /* aName */
    "tuning_local",  /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    667,            /* lineNo */
    13,             /* colNo */
    "merged",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    628,            /* lineNo */
    22,             /* colNo */
    "used",         /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    630,            /* lineNo */
    25,             /* colNo */
    "members",      /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    656,            /* lineNo */
    20,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    625,            /* lineNo */
    20,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    669,            /* lineNo */
    13,             /* colNo */
    "merged",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    662,            /* lineNo */
    9,              /* colNo */
    "merged",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    588,            /* lineNo */
    13,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    588,            /* lineNo */
    41,             /* colNo */
    "mapIn",        /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    585,            /* lineNo */
    13,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    585,            /* lineNo */
    37,             /* colNo */
    "mapIn",        /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    707,           /* lineNo */
    49,            /* colNo */
    "Z",           /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    710,           /* lineNo */
    52,            /* colNo */
    "RstackLocal", /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    710,           /* lineNo */
    16,            /* colNo */
    "mapOut",      /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    698,           /* lineNo */
    34,            /* colNo */
    "mapIn",       /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    698,           /* lineNo */
    16,            /* colNo */
    "mapOut",      /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    703,           /* lineNo */
    22,            /* colNo */
    "birthIdx",    /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    708,           /* lineNo */
    19,            /* colNo */
    "Z",           /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    709,           /* lineNo */
    19,            /* colNo */
    "Z",           /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    711,           /* lineNo */
    16,            /* colNo */
    "mapOut",      /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    713,           /* lineNo */
    9,             /* colNo */
    "mapOut",      /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    707,           /* lineNo */
    9,             /* colNo */
    "mapOut",      /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    146,                    /* lineNo */
    45,                     /* colNo */
    "Rstack",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    146,                    /* lineNo */
    61,                     /* colNo */
    "mapIn",                /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo je_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    149,                    /* lineNo */
    22,                     /* colNo */
    "Z",                    /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ke_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    154,                    /* lineNo */
    44,                     /* colNo */
    "Z",                    /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo le_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    151,                    /* lineNo */
    22,                     /* colNo */
    "xDet_i",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo me_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    166,                    /* lineNo */
    46,                     /* colNo */
    "xDet_i",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ne_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    167,                    /* lineNo */
    50,                     /* colNo */
    "PDet_i",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo oe_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    193,                    /* lineNo */
    30,                     /* colNo */
    "Wstore",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo pe_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    193,                    /* lineNo */
    14,                     /* colNo */
    "Wstore",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtECInfo c_emlrtECI = {
    -1,                     /* nDims */
    193,                    /* lineNo */
    5,                      /* colNo */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtBCInfo qe_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    167,                    /* lineNo */
    32,                     /* colNo */
    "Pstore",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo re_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    182,                    /* lineNo */
    24,                     /* colNo */
    "Pstore",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo se_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    201,                    /* lineNo */
    25,                     /* colNo */
    "Wstore",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo te_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    166,                    /* lineNo */
    30,                     /* colNo */
    "Xstore",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ue_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    181,                    /* lineNo */
    22,                     /* colNo */
    "Xstore",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ve_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    209,                    /* lineNo */
    56,                     /* colNo */
    "Xstore",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo we_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    223,                    /* lineNo */
    34,                     /* colNo */
    "Wstore",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo xe_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    223,                    /* lineNo */
    48,                     /* colNo */
    "Xstore",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ye_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    233,                    /* lineNo */
    29,                     /* colNo */
    "Xstore",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo af_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    234,                    /* lineNo */
    34,                     /* colNo */
    "Wstore",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo bf_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    234,                    /* lineNo */
    51,                     /* colNo */
    "Pstore",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo cf_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    152,                    /* lineNo */
    24,                     /* colNo */
    "PDet_i",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo df_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    200,                    /* lineNo */
    50,                     /* colNo */
    "Pstore",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ef_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    134,                    /* lineNo */
    24,                     /* colNo */
    "mapIn",                /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ff_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    135,                    /* lineNo */
    24,                     /* colNo */
    "mapIn",                /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo gf_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    177,                    /* lineNo */
    23,                     /* colNo */
    "mapIn",                /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo hf_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    183,                    /* lineNo */
    20,                     /* colNo */
    "Wstore",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo if_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    162,                    /* lineNo */
    30,                     /* colNo */
    "detRaw_i",             /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo jf_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    168,                    /* lineNo */
    28,                     /* colNo */
    "Wstore",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo kf_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    154,                    /* lineNo */
    64,                     /* colNo */
    "mapIn",                /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo lf_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    156,                    /* lineNo */
    22,                     /* colNo */
    "detRaw_i",             /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m", /* pName */
    0            /* checkKind */
};

static emlrtRTEInfo f_emlrtRTEI = {
    19,                  /* lineNo */
    9,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    15,                  /* lineNo */
    6,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    1,                   /* lineNo */
    29,                  /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    723,                 /* lineNo */
    9,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    93,                  /* lineNo */
    15,                  /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    395,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    405,                 /* lineNo */
    9,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    499,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    499,                 /* lineNo */
    14,                  /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    580,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    595,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    597,                 /* lineNo */
    15,                  /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    38,                                                      /* lineNo */
    5,                                                       /* colNo */
    "sort",                                                  /* fName */
    "D:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = {
    604,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = {
    605,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    37,                                                      /* lineNo */
    6,                                                       /* colNo */
    "sort",                                                  /* fName */
    "D:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" /* pName */
};

static emlrtRTEInfo w_emlrtRTEI = {
    680,                 /* lineNo */
    9,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = {
    615,                 /* lineNo */
    9,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = {
    685,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    597,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    580,                 /* lineNo */
    14,                  /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    716,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    117,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    118,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    119,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    193,                 /* lineNo */
    21,                  /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    193,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-zlj-reproduce-"
    "version\\codes\\LTGM-PHD-PMAU-SLAM-MEX\\tools\\slam_step_"
    "codegen.m" /* pName */
};

/* Function Declarations */
static void b_regularize_cov_local(const emlrtStack *sp, real_T P[9]);

static void
birth_local(const emlrtStack *sp, const real_T x[3], const real_T P[9],
            const emxArray_struct0_T *mapIn, const real_T Z_data[],
            const int32_T Z_size[2], real_T params_birth_intensity,
            const real_T RstackLocal_data[], const int32_T RstackLocal_size[3],
            const boolean_T birthIdx_data[], const int32_T birthIdx_size[2],
            real_T T, emxArray_struct0_T *mapOut);

static real_T likelihood_local(const emlrtStack *sp, const real_T Zhat[2],
                               const real_T Z[2], real_T S[4]);

static void map_update_local(
    const emlrtStack *sp, const real_T x[3], const real_T P[9],
    const struct0_T keepMap_data[], const int32_T keepMap_size[2],
    const struct0_T inMap_data[], const int32_T inMap_size[2],
    const real_T Z_data[], const int32_T Z_size[2], real_T params_P_D,
    real_T params_clutter_rate, real_T c_params_map_detection_add_thre,
    real_T params_map_miss_prune_threshold, real_T params_label_weight_gain,
    const real_T RstackLocal_data[], const int32_T RstackLocal_size[3],
    emxArray_struct0_T *mapOut, boolean_T birthIdx_data[],
    int32_T birthIdx_size[2]);

static void pose_predict_local(const real_T x[3], const real_T P[9],
                               const real_T u[2], real_T dt, const real_T Qu[4],
                               real_T xPred[3], real_T PPred[9]);

static void
pose_update_mm_local(const emlrtStack *sp, real_T xBase[3], real_T PBase[9],
                     const struct0_T mapIn_data[], const int32_T mapIn_size[2],
                     const real_T Z_data[], const int32_T Z_size[2],
                     real_T params_P_D, real_T params_clutter_rate,
                     real_T params_iter_max, real_T params_PHD_det_keep,
                     real_T params_PHD_miss_keep, real_T params_model,
                     const real_T Rstack_data[], const int32_T Rstack_size[3],
                     real_T iterCnt);

static void preprocess_local(const emlrtStack *sp, const real_T curMea_data[],
                             const int32_T curMea_size[2],
                             const real_T Rpolar[4], real_T meaXY_data[],
                             int32_T meaXY_size[2], real_T Rstack_data[],
                             int32_T Rstack_size[3]);

static void regularize_cov_local(const emlrtStack *sp, real_T P[4]);

static void split_map_by_fov_local(const emlrtStack *sp, const real_T x[3],
                                   const struct0_T mapIn_data[],
                                   const int32_T mapIn_size[2], real_T fovRange,
                                   real_T fovAngle, struct0_T keepMap_data[],
                                   int32_T keepMap_size[2],
                                   struct0_T visMap_data[],
                                   int32_T visMap_size[2]);

static void tuning_local(const emlrtStack *sp, const emxArray_struct0_T *mapIn,
                         real_T params_prune_threshold,
                         real_T params_max_components,
                         real_T params_merge_threshold,
                         emxArray_struct0_T *mapOut);

/* Function Definitions */
static void b_regularize_cov_local(const emlrtStack *sp, real_T P[9])
{
  static const int8_T b[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  real_T b_P[9];
  real_T jitter;
  int32_T flag;
  int32_T i;
  for (i = 0; i < 3; i++) {
    b_P[3 * i] = (P[3 * i] + P[i]) / 2.0;
    flag = 3 * i + 1;
    b_P[flag] = (P[flag] + P[i + 3]) / 2.0;
    flag = 3 * i + 2;
    b_P[flag] = (P[flag] + P[i + 6]) / 2.0;
  }
  memcpy(&P[0], &b_P[0], 9U * sizeof(real_T));
  jitter = 1.0E-9;
  memcpy(&b_P[0], &P[0], 9U * sizeof(real_T));
  flag = b_chol(b_P, &flag);
  while (flag != 0) {
    for (i = 0; i < 9; i++) {
      P[i] += jitter * (real_T)b[i];
    }
    jitter *= 10.0;
    memcpy(&b_P[0], &P[0], 9U * sizeof(real_T));
    flag = b_chol(b_P, &flag);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
}

static void
birth_local(const emlrtStack *sp, const real_T x[3], const real_T P[9],
            const emxArray_struct0_T *mapIn, const real_T Z_data[],
            const int32_T Z_size[2], real_T params_birth_intensity,
            const real_T RstackLocal_data[], const int32_T RstackLocal_size[3],
            const boolean_T birthIdx_data[], const int32_T birthIdx_size[2],
            real_T T, emxArray_struct0_T *mapOut)
{
  emlrtStack st;
  const struct0_T *mapIn_data;
  struct0_T *mapOut_data;
  real_T Jx[6];
  real_T b_Jx[6];
  real_T b_rot[4];
  real_T c_rot[4];
  real_T rot[4];
  real_T S_tmp;
  real_T b_S_tmp;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T j;
  int32_T outCount;
  st.prev = sp;
  st.tls = sp->tls;
  mapIn_data = mapIn->data;
  st.site = &ee_emlrtRSI;
  repmat(&st, muDoubleScalarMax(1.0, mapIn->size[1] + Z_size[1]), mapOut);
  mapOut_data = mapOut->data;
  i = mapIn->size[1];
  for (b_i = 0; b_i < i; b_i++) {
    if (b_i + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &yd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (b_i + 1 > mapOut->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, mapOut->size[1], &ae_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    mapOut_data[b_i] = mapIn_data[b_i];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  if (mapIn->size[1] - 1 < 0) {
    outCount = 0;
  } else {
    outCount = mapIn->size[1];
  }
  S_tmp = muDoubleScalarSin(-x[2]);
  b_S_tmp = muDoubleScalarCos(-x[2]);
  rot[0] = b_S_tmp;
  rot[2] = S_tmp;
  rot[1] = -S_tmp;
  rot[3] = b_S_tmp;
  i1 = Z_size[1];
  for (j = 0; j < i1; j++) {
    if (j + 1 > birthIdx_size[1]) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, birthIdx_size[1], &be_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (birthIdx_data[j]) {
      __m128d r;
      __m128d r1;
      real_T Jx_tmp;
      real_T d;
      real_T d1;
      outCount++;
      if (j + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &vd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (outCount > mapOut->size[1]) {
        emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                      &ge_emlrtBCI, (emlrtConstCTX)sp);
      }
      Jx_tmp = Z_data[2 * j];
      d = Z_data[2 * j + 1];
      d1 = S_tmp * d;
      mapOut_data[outCount - 1].m[0] = x[0] + (b_S_tmp * Jx_tmp + d1);
      if (outCount > mapOut->size[1]) {
        emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                      &ge_emlrtBCI, (emlrtConstCTX)sp);
      }
      d *= b_S_tmp;
      mapOut_data[outCount - 1].m[1] = x[1] + (-S_tmp * Jx_tmp + d);
      Jx[0] = 1.0;
      Jx[2] = 0.0;
      if (j + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &ce_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Jx[4] = Jx_tmp * S_tmp - d;
      Jx[1] = 0.0;
      Jx[3] = 1.0;
      if (j + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &de_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Jx[5] = Jx_tmp * b_S_tmp + d1;
      if (j + 1 > RstackLocal_size[2]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, RstackLocal_size[2],
                                      &wd_emlrtBCI, (emlrtConstCTX)sp);
      }
      memset(&b_rot[0], 0, sizeof(real_T) << 2);
      r = _mm_loadu_pd(&rot[0]);
      r1 = _mm_loadu_pd(&b_rot[0]);
      _mm_storeu_pd(
          &b_rot[0],
          _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(RstackLocal_data[4 * j]))));
      r = _mm_loadu_pd(&rot[2]);
      r1 = _mm_loadu_pd(&b_rot[0]);
      _mm_storeu_pd(
          &b_rot[0],
          _mm_add_pd(r1,
                     _mm_mul_pd(r, _mm_set1_pd(RstackLocal_data[4 * j + 1]))));
      r = _mm_loadu_pd(&rot[0]);
      r1 = _mm_loadu_pd(&b_rot[2]);
      _mm_storeu_pd(
          &b_rot[2],
          _mm_add_pd(r1,
                     _mm_mul_pd(r, _mm_set1_pd(RstackLocal_data[4 * j + 2]))));
      r = _mm_loadu_pd(&rot[2]);
      r1 = _mm_loadu_pd(&b_rot[2]);
      _mm_storeu_pd(
          &b_rot[2],
          _mm_add_pd(r1,
                     _mm_mul_pd(r, _mm_set1_pd(RstackLocal_data[4 * j + 3]))));
      memset(&b_Jx[0], 0, 6U * sizeof(real_T));
      for (b_i = 0; b_i < 3; b_i++) {
        r = _mm_loadu_pd(&Jx[0]);
        i = b_i << 1;
        r1 = _mm_loadu_pd(&b_Jx[i]);
        _mm_storeu_pd(&b_Jx[i],
                      _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(P[3 * b_i]))));
        r = _mm_loadu_pd(&Jx[2]);
        r1 = _mm_loadu_pd(&b_Jx[i]);
        _mm_storeu_pd(
            &b_Jx[i],
            _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(P[3 * b_i + 1]))));
        r = _mm_loadu_pd(&Jx[4]);
        r1 = _mm_loadu_pd(&b_Jx[i]);
        _mm_storeu_pd(
            &b_Jx[i],
            _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(P[3 * b_i + 2]))));
      }
      __m128d r2;
      memset(&c_rot[0], 0, sizeof(real_T) << 2);
      r = _mm_loadu_pd(&b_rot[0]);
      r1 = _mm_loadu_pd(&c_rot[0]);
      r2 = _mm_set1_pd(b_S_tmp);
      _mm_storeu_pd(&c_rot[0], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      r = _mm_loadu_pd(&b_rot[2]);
      r1 = _mm_loadu_pd(&c_rot[0]);
      _mm_storeu_pd(&c_rot[0],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(S_tmp))));
      r = _mm_loadu_pd(&b_rot[0]);
      r1 = _mm_loadu_pd(&c_rot[2]);
      _mm_storeu_pd(&c_rot[2],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(-S_tmp))));
      r = _mm_loadu_pd(&b_rot[2]);
      r1 = _mm_loadu_pd(&c_rot[2]);
      _mm_storeu_pd(&c_rot[2], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      memset(&b_rot[0], 0, sizeof(real_T) << 2);
      for (b_i = 0; b_i < 2; b_i++) {
        r = _mm_loadu_pd(&b_Jx[0]);
        i = b_i << 1;
        r1 = _mm_loadu_pd(&b_rot[i]);
        _mm_storeu_pd(&b_rot[i],
                      _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(Jx[b_i]))));
        r = _mm_loadu_pd(&b_Jx[2]);
        r1 = _mm_loadu_pd(&b_rot[i]);
        _mm_storeu_pd(&b_rot[i],
                      _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(Jx[b_i + 2]))));
        r = _mm_loadu_pd(&b_Jx[4]);
        r1 = _mm_loadu_pd(&b_rot[i]);
        _mm_storeu_pd(&b_rot[i],
                      _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(Jx[b_i + 4]))));
      }
      if (outCount > mapOut->size[1]) {
        emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                      &xd_emlrtBCI, (emlrtConstCTX)sp);
      }
      r = _mm_loadu_pd(&c_rot[0]);
      r1 = _mm_loadu_pd(&b_rot[0]);
      _mm_storeu_pd(&mapOut_data[outCount - 1].P[0], _mm_add_pd(r, r1));
      r = _mm_loadu_pd(&c_rot[2]);
      r1 = _mm_loadu_pd(&b_rot[2]);
      _mm_storeu_pd(&mapOut_data[outCount - 1].P[2], _mm_add_pd(r, r1));
      if (outCount > mapOut->size[1]) {
        emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                      &ee_emlrtBCI, (emlrtConstCTX)sp);
      }
      mapOut_data[outCount - 1].w = params_birth_intensity;
      /*  initialize label: [first_seen_time; count] */
      if (outCount > mapOut->size[1]) {
        emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                      &fe_emlrtBCI, (emlrtConstCTX)sp);
      }
      mapOut_data[outCount - 1].label[0] = T;
      if (outCount > mapOut->size[1]) {
        emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                      &fe_emlrtBCI, (emlrtConstCTX)sp);
      }
      mapOut_data[outCount - 1].label[1] = 1.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  st.site = &fe_emlrtRSI;
  if (outCount == 0) {
    mapOut->size[0] = 1;
    mapOut->size[1] = 0;
  } else {
    if (outCount > mapOut->size[1]) {
      emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1], &e_emlrtBCI,
                                    &st);
    }
    i = mapOut->size[0] * mapOut->size[1];
    mapOut->size[1] = outCount;
    emxEnsureCapacity_struct0_T(&st, mapOut, i, &cb_emlrtRTEI);
  }
}

static real_T likelihood_local(const emlrtStack *sp, const real_T Zhat[2],
                               const real_T Z[2], real_T S[4])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T Y[2];
  real_T nu[2];
  real_T b_value;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  _mm_storeu_pd(&nu[0],
                _mm_sub_pd(_mm_loadu_pd(&Z[0]), _mm_loadu_pd(&Zhat[0])));
  st.site = &nb_emlrtRSI;
  regularize_cov_local(&st, S);
  st.site = &ob_emlrtRSI;
  b_st.site = &ib_emlrtRSI;
  mrdiv(&b_st, nu, S, Y);
  st.site = &ob_emlrtRSI;
  b_value = det(S);
  if (b_value < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &c_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  b_value = muDoubleScalarSqrt(b_value);
  return 1.0 / (6.2831853071795862 * b_value) *
         muDoubleScalarExp(-0.5 * Y[0] * nu[0] + -0.5 * Y[1] * nu[1]);
}

static void map_update_local(
    const emlrtStack *sp, const real_T x[3], const real_T P[9],
    const struct0_T keepMap_data[], const int32_T keepMap_size[2],
    const struct0_T inMap_data[], const int32_T inMap_size[2],
    const real_T Z_data[], const int32_T Z_size[2], real_T params_P_D,
    real_T params_clutter_rate, real_T c_params_map_detection_add_thre,
    real_T params_map_miss_prune_threshold, real_T params_label_weight_gain,
    const real_T RstackLocal_data[], const int32_T RstackLocal_size[3],
    emxArray_struct0_T *mapOut, boolean_T birthIdx_data[],
    int32_T birthIdx_size[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_struct0_T *b_mapOut;
  struct0_T *b_mapOut_data;
  struct0_T *mapOut_data;
  real_T rawLike_i_data[512];
  real_T Rworld_data[192];
  real_T Zmap_data[96];
  real_T Jx[6];
  real_T b_Jx[6];
  real_T K[4];
  real_T b_rot[4];
  real_T rot[4];
  real_T nu[2];
  int32_T i;
  int32_T j;
  int32_T loop_ub;
  int32_T numIn;
  int32_T outCount;
  int32_T r1;
  int32_T r2;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  function [xOut, POut] = pose_update_mm_local(xBase, x0, PBase, mapIn, Z,
   * params, Rstack, iterCnt) */
  /*   */
  /*      numMap = numel(mapIn); */
  /*      numZ = size(Z,2); */
  /*   */
  /*      if numMap == 0 */
  /*          xOut = xBase; */
  /*          POut = PBase; */
  /*          return; */
  /*      end */
  /*   */
  /*      PD = params.P_D; */
  /*      detKeep = params.PHD_det_keep; */
  /*      missKeep = params.PHD_miss_keep; */
  /*   */
  /*      theta = xBase(3); */
  /*      c = cos(theta); */
  /*      s = sin(theta); */
  /*   */
  /*      % ===== storage（MEX-friendly）===== */
  /*      maxComp = numMap * (numZ + 1); */
  /*      Xstore = zeros(3, maxComp); */
  /*      Pstore = zeros(3,3,maxComp); */
  /*      Wstore = zeros(1, maxComp); */
  /*   */
  /*      idx = 0; */
  /*      sumW = 0; */
  /*   */
  /*      for i = 1:numMap */
  /*   */
  /*          dx = mapIn(i).m(1) - xBase(1); */
  /*          dy = mapIn(i).m(2) - xBase(2); */
  /*   */
  /*          Zhat = [c*dx + s*dy; */
  /*                 -s*dx + c*dy]; */
  /*   */
  /*          H = [-c, -s, -dx*s + dy*c; */
  /*                s, -c, -dx*c - dy*s]; */
  /*          Hm = [c,s; */
  /*               -s,c;]; */
  /*   */
  /*          % ===== miss detection ===== */
  /*          missW = mapIn(i).w * (1 - PD); */
  /*          if missW > missKeep */
  /*              idx = idx + 1; */
  /*              Xstore(:,idx) = xBase; */
  /*              Pstore(:,:,idx) = PBase; */
  /*              Wstore(idx) = missW; */
  /*              sumW = sumW + missW; */
  /*          end */
  /*   */
  /*          % ===== detection ===== */
  /*          denom = params.clutter_rate; */
  /*          detRaw = zeros(1,numZ); */
  /*          xDet = zeros(3,numZ); */
  /*          PDet = zeros(3,3,numZ); */
  /*   */
  /*          for j = 1:numZ */
  /*              S = H * PBase * H' + Rstack(:,:,j)+Hm*mapIn(i).P*Hm'; */
  /*              % S = H * PBase * H' + Rstack(:,:,j); */
  /*              K = (PBase * H') / S; */
  /*              nu = Z(:,j) - Zhat; */
  /*   */
  /*              % IEKF 更新（关键） */
  /*              % xDet(:,j) = x0 + K * (nu - H * (x0 - xBase)); */
  /*              xDet(:,j) = xBase + K*nu; */
  /*              PDet(:,:,j) = (eye(3) - K * H) * PBase; */
  /*   */
  /*              detRaw(j) = likelihood_local(Zhat, Z(:,j), S) * PD *
   * mapIn(i).w; */
  /*              denom = denom + detRaw(j); */
  /*          end */
  /*   */
  /*          if denom > 0 */
  /*              for j = 1:numZ */
  /*                  w = detRaw(j) / denom; */
  /*                  if w > detKeep */
  /*                      idx = idx + 1; */
  /*                      Xstore(:,idx) = xDet(:,j); */
  /*                      Pstore(:,:,idx) = PDet(:,:,j); */
  /*                      Wstore(idx) = w; */
  /*                      sumW = sumW + w; */
  /*                  end */
  /*              end */
  /*          end */
  /*      end */
  /*   */
  /*      if sumW <= eps */
  /*          xOut = xBase; */
  /*          POut = PBase; */
  /*          return; */
  /*      end */
  /*   */
  /*      % ===== normalize ===== */
  /*      Wstore(1:idx) = Wstore(1:idx) / sumW; */
  /*   */
  /*      % ===== fusion ===== */
  /*      if params.model == 1 */
  /*          % ===== CI fusion ===== */
  /*          invP = zeros(3,3); */
  /*          xInfo = zeros(3,1); */
  /*          omegaSum = 0; */
  /*   */
  /*          for k = 1:idx */
  /*              Pk = regularize_cov_local(Pstore(:,:,k)); */
  /*              wk = Wstore(k); */
  /*   */
  /*              info_w = 1 / trace(Pk); */
  /*              omega = wk * info_w; */
  /*   */
  /*              omegaSum = omegaSum + omega; */
  /*   */
  /*              invP = invP + omega * inv(Pk); */
  /*              xInfo = xInfo + omega * inv(Pk) * Xstore(:,k); */
  /*          end */
  /*   */
  /*          invP = invP / omegaSum; */
  /*          xInfo = xInfo / omegaSum; */
  /*   */
  /*          invP = regularize_cov_local(invP); */
  /*          POut = inv(invP); */
  /*          xOut = POut * xInfo; */
  /*   */
  /*      else */
  /*          % ===== moment matching ===== */
  /*          xOut = zeros(3,1); */
  /*   */
  /*          for k = 1:idx */
  /*              xOut = xOut + Wstore(k) * Xstore(:,k); */
  /*          end */
  /*   */
  /*          if iterCnt ~= params.iter_max */
  /*              POut = PBase; */
  /*              return; */
  /*          end */
  /*   */
  /*          POut = zeros(3,3); */
  /*          for k = 1:idx */
  /*              diff = Xstore(:,k) - xOut; */
  /*              POut = POut + Wstore(k) * (Pstore(:,:,k) + diff*diff'); */
  /*          end */
  /*   */
  /*          POut = regularize_cov_local(POut); */
  /*      end */
  /*  end */
  numIn = inMap_size[1];
  birthIdx_size[0] = 1;
  loop_ub = Z_size[1];
  birthIdx_size[1] = Z_size[1];
  for (i = 0; i < loop_ub; i++) {
    birthIdx_data[i] = true;
  }
  emxInit_struct0_T(sp, &b_mapOut, &o_emlrtRTEI);
  st.site = &mc_emlrtRSI;
  repmat(
      &st,
      muDoubleScalarMax(1.0, keepMap_size[1] + inMap_size[1] * (Z_size[1] + 1)),
      b_mapOut);
  mapOut_data = b_mapOut->data;
  r1 = mapOut->size[0] * mapOut->size[1];
  mapOut->size[0] = 1;
  r2 = b_mapOut->size[1];
  mapOut->size[1] = b_mapOut->size[1];
  emxEnsureCapacity_struct0_T(sp, mapOut, r1, &l_emlrtRTEI);
  b_mapOut_data = mapOut->data;
  for (i = 0; i < r2; i++) {
    b_mapOut_data[i] = mapOut_data[i];
  }
  /*  ===== keep existing map ===== */
  r2 = keepMap_size[1];
  for (i = 0; i < r2; i++) {
    if (i + 1 > r2) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, r2, &gb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (i + 1 > mapOut->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, mapOut->size[1], &hb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    b_mapOut_data[i] = keepMap_data[i];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  if (keepMap_size[1] - 1 < 0) {
    outCount = 0;
  } else {
    outCount = keepMap_size[1];
  }
  if (inMap_size[1] == 0) {
    st.site = &nc_emlrtRSI;
    if (outCount == 0) {
      b_mapOut->size[0] = 1;
      b_mapOut->size[1] = 0;
    } else {
      if (outCount > mapOut->size[1]) {
        emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1], &e_emlrtBCI,
                                      &st);
      }
      r1 = b_mapOut->size[0] * b_mapOut->size[1];
      b_mapOut->size[0] = 1;
      b_mapOut->size[1] = outCount;
      emxEnsureCapacity_struct0_T(&st, b_mapOut, r1, &i_emlrtRTEI);
      mapOut_data = b_mapOut->data;
      for (i = 0; i < outCount; i++) {
        mapOut_data[i] = b_mapOut_data[i];
      }
    }
    r1 = mapOut->size[0] * mapOut->size[1];
    mapOut->size[0] = 1;
    r2 = b_mapOut->size[1];
    mapOut->size[1] = b_mapOut->size[1];
    emxEnsureCapacity_struct0_T(sp, mapOut, r1, &m_emlrtRTEI);
    b_mapOut_data = mapOut->data;
    for (i = 0; i < r2; i++) {
      b_mapOut_data[i] = mapOut_data[i];
    }
  } else {
    __m128d b_r1;
    __m128d r;
    real_T a22;
    real_T cnt;
    real_T detDen;
    real_T missW;
    real_T w;
    /*  ===== transform measurements to world ===== */
    cnt = muDoubleScalarSin(-x[2]);
    a22 = muDoubleScalarCos(-x[2]);
    rot[0] = a22;
    rot[2] = cnt;
    rot[1] = -cnt;
    rot[3] = a22;
    if (Z_size[1] - 1 >= 0) {
      Jx[0] = 1.0;
      Jx[2] = 0.0;
      Jx[1] = 0.0;
      Jx[3] = 1.0;
    }
    for (j = 0; j < loop_ub; j++) {
      if (j + 1 > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, loop_ub, &l_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      w = Z_data[2 * j];
      r1 = 2 * j + 1;
      missW = Z_data[r1];
      detDen = cnt * missW;
      Zmap_data[2 * j] = x[0] + (a22 * w + detDen);
      missW *= a22;
      Zmap_data[r1] = x[1] + (-cnt * w + missW);
      if (j + 1 > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, loop_ub, &ib_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Jx[4] = w * cnt - missW;
      if (j + 1 > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, loop_ub, &jb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Jx[5] = w * a22 + detDen;
      if (j + 1 > RstackLocal_size[2]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, RstackLocal_size[2],
                                      &m_emlrtBCI, (emlrtConstCTX)sp);
      }
      memset(&K[0], 0, sizeof(real_T) << 2);
      r = _mm_loadu_pd(&rot[0]);
      b_r1 = _mm_loadu_pd(&K[0]);
      _mm_storeu_pd(
          &K[0],
          _mm_add_pd(b_r1,
                     _mm_mul_pd(r, _mm_set1_pd(RstackLocal_data[4 * j]))));
      r = _mm_loadu_pd(&rot[2]);
      b_r1 = _mm_loadu_pd(&K[0]);
      _mm_storeu_pd(
          &K[0],
          _mm_add_pd(b_r1,
                     _mm_mul_pd(r, _mm_set1_pd(RstackLocal_data[4 * j + 1]))));
      r = _mm_loadu_pd(&rot[0]);
      b_r1 = _mm_loadu_pd(&K[2]);
      r2 = 4 * j + 2;
      _mm_storeu_pd(
          &K[2],
          _mm_add_pd(b_r1, _mm_mul_pd(r, _mm_set1_pd(RstackLocal_data[r2]))));
      r = _mm_loadu_pd(&rot[2]);
      b_r1 = _mm_loadu_pd(&K[2]);
      _mm_storeu_pd(
          &K[2],
          _mm_add_pd(b_r1,
                     _mm_mul_pd(r, _mm_set1_pd(RstackLocal_data[4 * j + 3]))));
      memset(&b_Jx[0], 0, 6U * sizeof(real_T));
      for (i = 0; i < 3; i++) {
        r = _mm_loadu_pd(&Jx[0]);
        r1 = i << 1;
        b_r1 = _mm_loadu_pd(&b_Jx[r1]);
        _mm_storeu_pd(&b_Jx[r1],
                      _mm_add_pd(b_r1, _mm_mul_pd(r, _mm_set1_pd(P[3 * i]))));
        r = _mm_loadu_pd(&Jx[2]);
        b_r1 = _mm_loadu_pd(&b_Jx[r1]);
        _mm_storeu_pd(
            &b_Jx[r1],
            _mm_add_pd(b_r1, _mm_mul_pd(r, _mm_set1_pd(P[3 * i + 1]))));
        r = _mm_loadu_pd(&Jx[4]);
        b_r1 = _mm_loadu_pd(&b_Jx[r1]);
        _mm_storeu_pd(
            &b_Jx[r1],
            _mm_add_pd(b_r1, _mm_mul_pd(r, _mm_set1_pd(P[3 * i + 2]))));
      }
      __m128d b_r2;
      memset(&b_rot[0], 0, sizeof(real_T) << 2);
      r = _mm_loadu_pd(&K[0]);
      b_r1 = _mm_loadu_pd(&b_rot[0]);
      b_r2 = _mm_set1_pd(a22);
      _mm_storeu_pd(&b_rot[0], _mm_add_pd(b_r1, _mm_mul_pd(r, b_r2)));
      r = _mm_loadu_pd(&K[2]);
      b_r1 = _mm_loadu_pd(&b_rot[0]);
      _mm_storeu_pd(&b_rot[0],
                    _mm_add_pd(b_r1, _mm_mul_pd(r, _mm_set1_pd(cnt))));
      r = _mm_loadu_pd(&K[0]);
      b_r1 = _mm_loadu_pd(&b_rot[2]);
      _mm_storeu_pd(&b_rot[2],
                    _mm_add_pd(b_r1, _mm_mul_pd(r, _mm_set1_pd(-cnt))));
      r = _mm_loadu_pd(&K[2]);
      b_r1 = _mm_loadu_pd(&b_rot[2]);
      _mm_storeu_pd(&b_rot[2], _mm_add_pd(b_r1, _mm_mul_pd(r, b_r2)));
      memset(&K[0], 0, sizeof(real_T) << 2);
      for (i = 0; i < 2; i++) {
        r = _mm_loadu_pd(&b_Jx[0]);
        r1 = i << 1;
        b_r1 = _mm_loadu_pd(&K[r1]);
        _mm_storeu_pd(&K[r1],
                      _mm_add_pd(b_r1, _mm_mul_pd(r, _mm_set1_pd(Jx[i]))));
        r = _mm_loadu_pd(&b_Jx[2]);
        b_r1 = _mm_loadu_pd(&K[r1]);
        _mm_storeu_pd(&K[r1],
                      _mm_add_pd(b_r1, _mm_mul_pd(r, _mm_set1_pd(Jx[i + 2]))));
        r = _mm_loadu_pd(&b_Jx[4]);
        b_r1 = _mm_loadu_pd(&K[r1]);
        _mm_storeu_pd(&K[r1],
                      _mm_add_pd(b_r1, _mm_mul_pd(r, _mm_set1_pd(Jx[i + 4]))));
      }
      if (j + 1 > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, loop_ub, &o_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      r = _mm_loadu_pd(&b_rot[0]);
      b_r1 = _mm_loadu_pd(&K[0]);
      _mm_storeu_pd(&Rworld_data[4 * j], _mm_add_pd(r, b_r1));
      r = _mm_loadu_pd(&b_rot[2]);
      b_r1 = _mm_loadu_pd(&K[2]);
      _mm_storeu_pd(&Rworld_data[r2], _mm_add_pd(r, b_r1));
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    /*  1. MISS DETECTION */
    for (i = 0; i < numIn; i++) {
      if (i + 1 > numIn) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &kb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      missW = inMap_data[i].w * (1.0 - params_P_D);
      if (missW > params_map_miss_prune_threshold) {
        outCount++;
        if ((outCount < 1) || (outCount > mapOut->size[1])) {
          emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                        &gc_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (i + 1 > numIn) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &hc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        b_mapOut_data[outCount - 1].m[0] = inMap_data[i].m[0];
        if (outCount > mapOut->size[1]) {
          emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                        &gc_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (i + 1 > numIn) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &hc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        b_mapOut_data[outCount - 1].m[1] = inMap_data[i].m[1];
        if (i + 1 > numIn) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &bb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (outCount > mapOut->size[1]) {
          emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                        &cb_emlrtBCI, (emlrtConstCTX)sp);
        }
        b_mapOut_data[outCount - 1].P[0] = inMap_data[i].P[0];
        b_mapOut_data[outCount - 1].P[1] = inMap_data[i].P[1];
        b_mapOut_data[outCount - 1].P[2] = inMap_data[i].P[2];
        b_mapOut_data[outCount - 1].P[3] = inMap_data[i].P[3];
        if (outCount > mapOut->size[1]) {
          emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                        &cb_emlrtBCI, (emlrtConstCTX)sp);
        }
        st.site = &oc_emlrtRSI;
        regularize_cov_local(&st, b_mapOut_data[outCount - 1].P);
        if (outCount > mapOut->size[1]) {
          emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                        &lb_emlrtBCI, (emlrtConstCTX)sp);
        }
        b_mapOut_data[outCount - 1].w = missW;
        /*  preserve label (time,count) */
        if (outCount > mapOut->size[1]) {
          emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                        &ec_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (i + 1 > numIn) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &fc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        b_mapOut_data[outCount - 1].label[0] = inMap_data[i].label[0];
        if (outCount > mapOut->size[1]) {
          emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                        &ec_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (i + 1 > numIn) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &fc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        b_mapOut_data[outCount - 1].label[1] = inMap_data[i].label[1];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    /*  2. MEASUREMENT-CENTRIC UPDATE (j → i) */
    for (j = 0; j < loop_ub; j++) {
      detDen = params_clutter_rate;
      /*  -------- first pass: compute likelihoods -------- */
      for (i = 0; i < numIn; i++) {
        real_T Y[2];
        if (i + 1 > numIn) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &n_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (j + 1 > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, loop_ub, &p_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        st.site = &pc_emlrtRSI;
        if (i + 1 > numIn) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &r_emlrtBCI, &st);
        }
        if (j + 1 > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, loop_ub, &s_emlrtBCI, &st);
        }
        nu[0] = Zmap_data[2 * j] - inMap_data[i].m[0];
        r = _mm_loadu_pd(&Rworld_data[4 * j]);
        _mm_storeu_pd(&rot[0],
                      _mm_add_pd(_mm_loadu_pd(&inMap_data[i].P[0]), r));
        nu[1] = Zmap_data[2 * j + 1] - inMap_data[i].m[1];
        r = _mm_loadu_pd(&Rworld_data[4 * j + 2]);
        _mm_storeu_pd(&rot[2],
                      _mm_add_pd(_mm_loadu_pd(&inMap_data[i].P[2]), r));
        b_st.site = &nb_emlrtRSI;
        regularize_cov_local(&b_st, rot);
        b_st.site = &ob_emlrtRSI;
        c_st.site = &ib_emlrtRSI;
        mrdiv(&c_st, nu, rot, Y);
        b_st.site = &ob_emlrtRSI;
        missW = det(rot);
        if (missW < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &b_st, &c_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        missW = muDoubleScalarSqrt(missW);
        if (i + 1 > numIn) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &q_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        /*  apply label-based multiplier (label(2) is observation count) */
        /*  multiplier = 1 + gain * (count - 1) */
        if (i + 1 > numIn) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &eb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        cnt = inMap_data[i].label[1];
        if (cnt < 1.0) {
          cnt = 1.0;
        }
        if (i + 1 > numIn) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &pb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        missW = 1.0 / (6.2831853071795862 * missW) *
                muDoubleScalarExp(-0.5 * Y[0] * nu[0] + -0.5 * Y[1] * nu[1]) *
                params_P_D * inMap_data[i].w *
                (params_label_weight_gain * (cnt - 1.0) + 1.0);
        rawLike_i_data[i] = missW;
        if (i + 1 > numIn) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &qb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        detDen += missW;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtConstCTX)sp);
        }
      }
      /*  -------- second pass: normalize + update -------- */
      if (detDen > 0.0) {
        for (i = 0; i < numIn; i++) {
          if (i + 1 > numIn) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &mb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          w = rawLike_i_data[i] / detDen;
          if (w > c_params_map_detection_add_thre) {
            if (i + 1 > numIn) {
              emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &db_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            missW = inMap_data[i].label[1];
            if (missW > 150.0) {
              outCount++;
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &wb_emlrtBCI, (emlrtConstCTX)sp);
              }
              if (i + 1 > numIn) {
                emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &xb_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              b_mapOut_data[outCount - 1].m[0] = inMap_data[i].m[0];
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &wb_emlrtBCI, (emlrtConstCTX)sp);
              }
              if (i + 1 > numIn) {
                emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &xb_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              b_mapOut_data[outCount - 1].m[1] = inMap_data[i].m[1];
              if (i + 1 > numIn) {
                emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &t_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &u_emlrtBCI, (emlrtConstCTX)sp);
              }
              b_mapOut_data[outCount - 1].P[0] = inMap_data[i].P[0];
              b_mapOut_data[outCount - 1].P[1] = inMap_data[i].P[1];
              b_mapOut_data[outCount - 1].P[2] = inMap_data[i].P[2];
              b_mapOut_data[outCount - 1].P[3] = inMap_data[i].P[3];
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &nb_emlrtBCI, (emlrtConstCTX)sp);
              }
              b_mapOut_data[outCount - 1].w = w;
              /*  keep label and increment observation count */
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &ub_emlrtBCI, (emlrtConstCTX)sp);
              }
              if (i + 1 > numIn) {
                emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &vb_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              b_mapOut_data[outCount - 1].label[0] = inMap_data[i].label[0];
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &ub_emlrtBCI, (emlrtConstCTX)sp);
              }
              if (i + 1 > numIn) {
                emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &vb_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              b_mapOut_data[outCount - 1].label[1] = missW;
              r1 = birthIdx_size[1];
              if (j + 1 > r1) {
                emlrtDynamicBoundsCheckR2012b(j + 1, 1, r1, &ob_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              birthIdx_data[j] = false;
            } else {
              int32_T b_i;
              if (i + 1 > numIn) {
                emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &v_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              if (j + 1 > loop_ub) {
                emlrtDynamicBoundsCheckR2012b(j + 1, 1, loop_ub, &w_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              r = _mm_loadu_pd(&Rworld_data[4 * j]);
              _mm_storeu_pd(&rot[0],
                            _mm_add_pd(_mm_loadu_pd(&inMap_data[i].P[0]), r));
              r = _mm_loadu_pd(&Rworld_data[4 * j + 2]);
              _mm_storeu_pd(&rot[2],
                            _mm_add_pd(_mm_loadu_pd(&inMap_data[i].P[2]), r));
              st.site = &qc_emlrtRSI;
              if (i + 1 > numIn) {
                emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &x_emlrtBCI,
                                              &st);
              }
              b_st.site = &ib_emlrtRSI;
              c_st.site = &jb_emlrtRSI;
              d_st.site = &kb_emlrtRSI;
              if (muDoubleScalarAbs(rot[1]) > muDoubleScalarAbs(rot[0])) {
                r1 = 1;
                r2 = 0;
              } else {
                r1 = 0;
                r2 = 1;
              }
              missW = rot[r2] / rot[r1];
              cnt = rot[r1 + 2];
              a22 = rot[r2 + 2] - missW * cnt;
              if ((a22 == 0.0) || (rot[r1] == 0.0)) {
                e_st.site = &lb_emlrtRSI;
                if (!emlrtSetWarningFlag(&e_st)) {
                  f_st.site = &mb_emlrtRSI;
                  warning(&f_st);
                }
              }
              b_i = r1 << 1;
              _mm_storeu_pd(&K[b_i],
                            _mm_div_pd(_mm_loadu_pd(&inMap_data[i].P[0]),
                                       _mm_set1_pd(rot[r1])));
              r = _mm_loadu_pd(&K[b_i]);
              r1 = r2 << 1;
              _mm_storeu_pd(
                  &K[r1],
                  _mm_div_pd(_mm_sub_pd(_mm_loadu_pd(&inMap_data[i].P[2]),
                                        _mm_mul_pd(r, _mm_set1_pd(cnt))),
                             _mm_set1_pd(a22)));
              r = _mm_loadu_pd(&K[r1]);
              b_r1 = _mm_loadu_pd(&K[b_i]);
              _mm_storeu_pd(
                  &K[b_i], _mm_sub_pd(b_r1, _mm_mul_pd(r, _mm_set1_pd(missW))));
              if (j + 1 > loop_ub) {
                emlrtDynamicBoundsCheckR2012b(j + 1, 1, loop_ub, &ab_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              if (i + 1 > numIn) {
                emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &y_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              outCount++;
              r = _mm_loadu_pd(&Zmap_data[2 * j]);
              _mm_storeu_pd(&nu[0],
                            _mm_sub_pd(r, _mm_loadu_pd(&inMap_data[i].m[0])));
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &cc_emlrtBCI, (emlrtConstCTX)sp);
              }
              if (i + 1 > numIn) {
                emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &dc_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              b_mapOut_data[outCount - 1].m[0] =
                  inMap_data[i].m[0] + (K[0] * nu[0] + nu[1] * K[2]);
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &cc_emlrtBCI, (emlrtConstCTX)sp);
              }
              if (i + 1 > numIn) {
                emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &dc_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              b_mapOut_data[outCount - 1].m[1] =
                  inMap_data[i].m[1] + (nu[0] * K[1] + nu[1] * K[3]);
              rot[1] = 0.0;
              rot[2] = 0.0;
              rot[0] = 1.0;
              rot[3] = 1.0;
              r = _mm_loadu_pd(&rot[0]);
              b_r1 = _mm_loadu_pd(&K[0]);
              _mm_storeu_pd(&rot[0], _mm_sub_pd(r, b_r1));
              r = _mm_loadu_pd(&rot[2]);
              b_r1 = _mm_loadu_pd(&K[2]);
              _mm_storeu_pd(&rot[2], _mm_sub_pd(r, b_r1));
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &bc_emlrtBCI, (emlrtConstCTX)sp);
              }
              b_mapOut_data[outCount - 1].P[0] = 0.0;
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &bc_emlrtBCI, (emlrtConstCTX)sp);
              }
              b_mapOut_data[outCount - 1].P[1] = 0.0;
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &bc_emlrtBCI, (emlrtConstCTX)sp);
              }
              b_mapOut_data[outCount - 1].P[2] = 0.0;
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &bc_emlrtBCI, (emlrtConstCTX)sp);
              }
              b_mapOut_data[outCount - 1].P[3] = 0.0;
              r = _mm_loadu_pd(&rot[0]);
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &bc_emlrtBCI, (emlrtConstCTX)sp);
              }
              b_r1 = _mm_loadu_pd(&b_mapOut_data[outCount - 1].P[0]);
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &bc_emlrtBCI, (emlrtConstCTX)sp);
              }
              _mm_storeu_pd(
                  &b_mapOut_data[outCount - 1].P[0],
                  _mm_add_pd(b_r1,
                             _mm_mul_pd(r, _mm_set1_pd(inMap_data[i].P[0]))));
              r = _mm_loadu_pd(&rot[2]);
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &bc_emlrtBCI, (emlrtConstCTX)sp);
              }
              b_r1 = _mm_loadu_pd(&b_mapOut_data[outCount - 1].P[0]);
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &bc_emlrtBCI, (emlrtConstCTX)sp);
              }
              _mm_storeu_pd(
                  &b_mapOut_data[outCount - 1].P[0],
                  _mm_add_pd(b_r1,
                             _mm_mul_pd(r, _mm_set1_pd(inMap_data[i].P[1]))));
              r = _mm_loadu_pd(&rot[0]);
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &bc_emlrtBCI, (emlrtConstCTX)sp);
              }
              b_r1 = _mm_loadu_pd(&b_mapOut_data[outCount - 1].P[2]);
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &bc_emlrtBCI, (emlrtConstCTX)sp);
              }
              _mm_storeu_pd(
                  &b_mapOut_data[outCount - 1].P[2],
                  _mm_add_pd(b_r1,
                             _mm_mul_pd(r, _mm_set1_pd(inMap_data[i].P[2]))));
              r = _mm_loadu_pd(&rot[2]);
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &bc_emlrtBCI, (emlrtConstCTX)sp);
              }
              b_r1 = _mm_loadu_pd(&b_mapOut_data[outCount - 1].P[2]);
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &bc_emlrtBCI, (emlrtConstCTX)sp);
              }
              _mm_storeu_pd(
                  &b_mapOut_data[outCount - 1].P[2],
                  _mm_add_pd(b_r1,
                             _mm_mul_pd(r, _mm_set1_pd(inMap_data[i].P[3]))));
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &rb_emlrtBCI, (emlrtConstCTX)sp);
              }
              st.site = &rc_emlrtRSI;
              regularize_cov_local(&st, b_mapOut_data[outCount - 1].P);
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &sb_emlrtBCI, (emlrtConstCTX)sp);
              }
              b_mapOut_data[outCount - 1].w = w;
              /*  keep label and increment observation count */
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &yb_emlrtBCI, (emlrtConstCTX)sp);
              }
              if (i + 1 > numIn) {
                emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &ac_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              b_mapOut_data[outCount - 1].label[0] = inMap_data[i].label[0];
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &yb_emlrtBCI, (emlrtConstCTX)sp);
              }
              if (i + 1 > numIn) {
                emlrtDynamicBoundsCheckR2012b(i + 1, 1, numIn, &ac_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              b_mapOut_data[outCount - 1].label[1] = inMap_data[i].label[1];
              if (outCount > mapOut->size[1]) {
                emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                              &fb_emlrtBCI, (emlrtConstCTX)sp);
              }
              b_mapOut_data[outCount - 1].label[1]++;
              r1 = birthIdx_size[1];
              if (j + 1 > r1) {
                emlrtDynamicBoundsCheckR2012b(j + 1, 1, r1, &tb_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              birthIdx_data[j] = false;
            }
          }
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtConstCTX)sp);
          }
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    /*  ===== resize output ===== */
    st.site = &sc_emlrtRSI;
    if (outCount == 0) {
      b_mapOut->size[0] = 1;
      b_mapOut->size[1] = 0;
    } else {
      if (outCount > mapOut->size[1]) {
        emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1], &e_emlrtBCI,
                                      &st);
      }
      r1 = b_mapOut->size[0] * b_mapOut->size[1];
      b_mapOut->size[0] = 1;
      b_mapOut->size[1] = outCount;
      emxEnsureCapacity_struct0_T(&st, b_mapOut, r1, &i_emlrtRTEI);
      mapOut_data = b_mapOut->data;
      for (i = 0; i < outCount; i++) {
        mapOut_data[i] = b_mapOut_data[i];
      }
    }
    r1 = mapOut->size[0] * mapOut->size[1];
    mapOut->size[0] = 1;
    r2 = b_mapOut->size[1];
    mapOut->size[1] = b_mapOut->size[1];
    emxEnsureCapacity_struct0_T(sp, mapOut, r1, &n_emlrtRTEI);
    b_mapOut_data = mapOut->data;
    for (i = 0; i < r2; i++) {
      b_mapOut_data[i] = mapOut_data[i];
    }
  }
  emxFree_struct0_T(sp, &b_mapOut);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void pose_predict_local(const real_T x[3], const real_T P[9],
                               const real_T u[2], real_T dt, const real_T Qu[4],
                               real_T xPred[3], real_T PPred[9])
{
  __m128d r;
  __m128d r1;
  real_T Fx[9];
  real_T b_Fx[9];
  real_T Fu[6];
  real_T b_Fu[6];
  real_T b_xPred_tmp;
  real_T c_xPred_tmp;
  real_T d_xPred_tmp;
  real_T e_xPred_tmp;
  real_T f_xPred_tmp;
  real_T g_xPred_tmp;
  real_T q;
  real_T xPred_tmp;
  real_T xPred_tmp_tmp;
  int32_T Fx_tmp;
  int32_T i;
  xPred_tmp = muDoubleScalarSin(x[2]);
  xPred_tmp_tmp = x[2] + u[1] * dt;
  b_xPred_tmp = muDoubleScalarSin(xPred_tmp_tmp);
  c_xPred_tmp = u[0] / u[1];
  d_xPred_tmp = c_xPred_tmp * b_xPred_tmp;
  xPred[0] = (x[0] - c_xPred_tmp * xPred_tmp) + d_xPred_tmp;
  e_xPred_tmp = muDoubleScalarCos(x[2]);
  f_xPred_tmp = muDoubleScalarCos(xPred_tmp_tmp);
  g_xPred_tmp = c_xPred_tmp * f_xPred_tmp;
  xPred[1] = (x[1] + c_xPred_tmp * e_xPred_tmp) - g_xPred_tmp;
  if (muDoubleScalarIsNaN(xPred_tmp_tmp + 3.1415926535897931) ||
      muDoubleScalarIsInf(xPred_tmp_tmp + 3.1415926535897931)) {
    xPred_tmp_tmp = rtNaN;
  } else {
    q = muDoubleScalarAbs((xPred_tmp_tmp + 3.1415926535897931) /
                          6.2831853071795862);
    if (muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) >
        2.2204460492503131E-16 * q) {
      xPred_tmp_tmp = muDoubleScalarRem(xPred_tmp_tmp + 3.1415926535897931,
                                        6.2831853071795862);
    } else {
      xPred_tmp_tmp = 0.0;
    }
    if (xPred_tmp_tmp == 0.0) {
      xPred_tmp_tmp = 0.0;
    } else if (xPred_tmp_tmp < 0.0) {
      xPred_tmp_tmp += 6.2831853071795862;
    }
  }
  xPred[2] = xPred_tmp_tmp - 3.1415926535897931;
  Fx[0] = 1.0;
  Fx[3] = 0.0;
  xPred_tmp_tmp = -u[0] / u[1];
  Fx[6] = xPred_tmp_tmp * e_xPred_tmp + g_xPred_tmp;
  Fx[1] = 0.0;
  Fx[4] = 1.0;
  Fx[7] = xPred_tmp_tmp * xPred_tmp + d_xPred_tmp;
  Fx[2] = 0.0;
  Fx[5] = 0.0;
  Fx[8] = 1.0;
  q = 1.0 / u[1];
  Fu[0] = -1.0 / u[1] * xPred_tmp + q * b_xPred_tmp;
  d_xPred_tmp = u[1] * u[1];
  g_xPred_tmp = u[0] / d_xPred_tmp;
  xPred_tmp_tmp = c_xPred_tmp * dt;
  Fu[3] = (g_xPred_tmp * xPred_tmp - g_xPred_tmp * b_xPred_tmp) +
          xPred_tmp_tmp * f_xPred_tmp;
  Fu[1] = q * e_xPred_tmp - q * f_xPred_tmp;
  Fu[4] = (-u[0] / d_xPred_tmp * e_xPred_tmp + g_xPred_tmp * f_xPred_tmp) +
          xPred_tmp_tmp * b_xPred_tmp;
  Fu[2] = 0.0;
  Fu[5] = dt;
  memset(&b_Fx[0], 0, 9U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    xPred_tmp_tmp = P[3 * i];
    r = _mm_loadu_pd(&Fx[0]);
    r1 = _mm_loadu_pd(&b_Fx[3 * i]);
    _mm_storeu_pd(&b_Fx[3 * i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(xPred_tmp_tmp))));
    Fx_tmp = 3 * i + 2;
    b_Fx[Fx_tmp] += 0.0 * xPred_tmp_tmp;
    xPred_tmp_tmp = P[3 * i + 1];
    r = _mm_loadu_pd(&Fx[3]);
    r1 = _mm_loadu_pd(&b_Fx[3 * i]);
    _mm_storeu_pd(&b_Fx[3 * i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(xPred_tmp_tmp))));
    b_Fx[Fx_tmp] += 0.0 * xPred_tmp_tmp;
    xPred_tmp_tmp = P[Fx_tmp];
    r = _mm_loadu_pd(&Fx[6]);
    r1 = _mm_loadu_pd(&b_Fx[3 * i]);
    _mm_storeu_pd(&b_Fx[3 * i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(xPred_tmp_tmp))));
    b_Fx[Fx_tmp] += xPred_tmp_tmp;
  }
  __m128d r2;
  memset(&b_Fu[0], 0, 6U * sizeof(real_T));
  r = _mm_loadu_pd(&Fu[0]);
  r1 = _mm_loadu_pd(&b_Fu[0]);
  _mm_storeu_pd(&b_Fu[0], _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(Qu[0]))));
  b_Fu[2] += 0.0 * Qu[0];
  r = _mm_loadu_pd(&Fu[3]);
  r1 = _mm_loadu_pd(&b_Fu[0]);
  r2 = _mm_set1_pd(0.0);
  _mm_storeu_pd(&b_Fu[0], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
  b_Fu[2] += dt * 0.0;
  r = _mm_loadu_pd(&Fu[0]);
  r1 = _mm_loadu_pd(&b_Fu[3]);
  _mm_storeu_pd(&b_Fu[3], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
  r = _mm_loadu_pd(&Fu[3]);
  r1 = _mm_loadu_pd(&b_Fu[3]);
  _mm_storeu_pd(&b_Fu[3], _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(Qu[3]))));
  b_Fu[5] += dt * Qu[3];
  memset(&PPred[0], 0, 9U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    xPred_tmp_tmp = Fx[i];
    r = _mm_loadu_pd(&b_Fx[0]);
    r1 = _mm_loadu_pd(&PPred[3 * i]);
    _mm_storeu_pd(&PPred[3 * i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(xPred_tmp_tmp))));
    Fx_tmp = 3 * i + 2;
    PPred[Fx_tmp] += b_Fx[2] * xPred_tmp_tmp;
    xPred_tmp_tmp = Fx[i + 3];
    r = _mm_loadu_pd(&b_Fx[3]);
    r1 = _mm_loadu_pd(&PPred[3 * i]);
    _mm_storeu_pd(&PPred[3 * i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(xPred_tmp_tmp))));
    PPred[Fx_tmp] += b_Fx[5] * xPred_tmp_tmp;
    xPred_tmp_tmp = Fx[i + 6];
    r = _mm_loadu_pd(&b_Fx[6]);
    r1 = _mm_loadu_pd(&PPred[3 * i]);
    _mm_storeu_pd(&PPred[3 * i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(xPred_tmp_tmp))));
    PPred[Fx_tmp] += b_Fx[8] * xPred_tmp_tmp;
  }
  memset(&Fx[0], 0, 9U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    xPred_tmp_tmp = Fu[i];
    r = _mm_loadu_pd(&b_Fu[0]);
    r1 = _mm_loadu_pd(&Fx[3 * i]);
    _mm_storeu_pd(&Fx[3 * i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(xPred_tmp_tmp))));
    Fx_tmp = 3 * i + 2;
    Fx[Fx_tmp] += b_Fu[2] * xPred_tmp_tmp;
    xPred_tmp_tmp = Fu[i + 3];
    r = _mm_loadu_pd(&b_Fu[3]);
    r1 = _mm_loadu_pd(&Fx[3 * i]);
    _mm_storeu_pd(&Fx[3 * i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(xPred_tmp_tmp))));
    Fx[Fx_tmp] += b_Fu[5] * xPred_tmp_tmp;
  }
  r = _mm_loadu_pd(&PPred[0]);
  r1 = _mm_loadu_pd(&Fx[0]);
  _mm_storeu_pd(&PPred[0], _mm_add_pd(r, r1));
  r = _mm_loadu_pd(&PPred[2]);
  r1 = _mm_loadu_pd(&Fx[2]);
  _mm_storeu_pd(&PPred[2], _mm_add_pd(r, r1));
  r = _mm_loadu_pd(&PPred[4]);
  r1 = _mm_loadu_pd(&Fx[4]);
  _mm_storeu_pd(&PPred[4], _mm_add_pd(r, r1));
  r = _mm_loadu_pd(&PPred[6]);
  r1 = _mm_loadu_pd(&Fx[6]);
  _mm_storeu_pd(&PPred[6], _mm_add_pd(r, r1));
  PPred[8] += Fx[8];
}

static void
pose_update_mm_local(const emlrtStack *sp, real_T xBase[3], real_T PBase[9],
                     const struct0_T mapIn_data[], const int32_T mapIn_size[2],
                     const real_T Z_data[], const int32_T Z_size[2],
                     real_T params_P_D, real_T params_clutter_rate,
                     real_T params_iter_max, real_T params_PHD_det_keep,
                     real_T params_PHD_miss_keep, real_T params_model,
                     const real_T Rstack_data[], const int32_T Rstack_size[3],
                     real_T iterCnt)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_real_T *Pstore;
  emxArray_real_T *Wstore;
  emxArray_real_T *Xstore;
  emxArray_real_T *r;
  real_T PDet_i_data[4608];
  real_T xDet_i_data[1536];
  real_T detRaw_i_data[512];
  real_T Pk[9];
  real_T b_Pk[9];
  real_T invP[9];
  real_T H[6];
  real_T K[6];
  real_T b_H[6];
  real_T y[6];
  real_T Hm[4];
  real_T S[4];
  real_T b_Hm[4];
  real_T c_Hm[4];
  real_T diff[3];
  real_T Z[2];
  real_T Zhat[2];
  real_T *Pstore_data;
  real_T *Wstore_data;
  real_T *Xstore_data;
  real_T *b_r1;
  int32_T b_i;
  int32_T c_i;
  int32_T i1;
  int32_T j;
  int32_T k;
  int32_T numMap;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  numMap = mapIn_size[1];
  emxInit_real_T(sp, &Xstore, 2, &eb_emlrtRTEI);
  emxInit_real_T(sp, &Pstore, 3, &fb_emlrtRTEI);
  emxInit_real_T(sp, &Wstore, 2, &gb_emlrtRTEI);
  emxInit_real_T(sp, &r, 2, &ib_emlrtRTEI);
  if (mapIn_size[1] != 0) {
    __m128d b_r2;
    __m128d r3;
    __m128d r4;
    real_T a21;
    real_T c;
    real_T dy;
    real_T s;
    real_T sumW;
    int32_T K_tmp;
    int32_T i;
    int32_T i2;
    int32_T idx;
    int32_T maxComp;
    int32_T r1;
    int32_T r2;
    c = muDoubleScalarCos(xBase[2]);
    s = muDoubleScalarSin(xBase[2]);
    maxComp = mapIn_size[1] * (Z_size[1] + 1);
    r1 = Xstore->size[0] * Xstore->size[1];
    Xstore->size[0] = 3;
    Xstore->size[1] = maxComp;
    emxEnsureCapacity_real_T(sp, Xstore, r1, &eb_emlrtRTEI);
    Xstore_data = Xstore->data;
    r1 = 3 * maxComp;
    for (k = 0; k < r1; k++) {
      Xstore_data[k] = 0.0;
    }
    r1 = Pstore->size[0] * Pstore->size[1] * Pstore->size[2];
    Pstore->size[0] = 3;
    Pstore->size[1] = 3;
    Pstore->size[2] = maxComp;
    emxEnsureCapacity_real_T(sp, Pstore, r1, &fb_emlrtRTEI);
    Pstore_data = Pstore->data;
    r1 = 9 * maxComp;
    for (k = 0; k < r1; k++) {
      Pstore_data[k] = 0.0;
    }
    r1 = Wstore->size[0] * Wstore->size[1];
    Wstore->size[0] = 1;
    Wstore->size[1] = maxComp;
    emxEnsureCapacity_real_T(sp, Wstore, r1, &gb_emlrtRTEI);
    Wstore_data = Wstore->data;
    for (k = 0; k < maxComp; k++) {
      Wstore_data[k] = 0.0;
    }
    idx = 0;
    sumW = 0.0;
    i = Z_size[1];
    if (Z_size[1] - 1 >= 0) {
      i1 = mapIn_size[1];
      H[0] = -c;
      H[2] = -s;
      H[1] = s;
      H[3] = -c;
      Hm[0] = c;
      Hm[2] = s;
      Hm[1] = -s;
      Hm[3] = c;
    }
    for (j = 0; j < i; j++) {
      real_T denom;
      denom = params_clutter_rate;
      for (c_i = 0; c_i < i1; c_i++) {
        real_T Zhat_tmp;
        real_T dx;
        if (c_i + 1 > numMap) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, numMap, &ef_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        dx = mapIn_data[c_i].m[0] - xBase[0];
        if (c_i + 1 > numMap) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, numMap, &ff_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        dy = mapIn_data[c_i].m[1] - xBase[1];
        Zhat_tmp = s * dy;
        Zhat[0] = c * dx + Zhat_tmp;
        a21 = c * dy;
        Zhat[1] = -s * dx + a21;
        H[4] = -dx * s + a21;
        H[5] = -dx * c - Zhat_tmp;
        for (k = 0; k < 2; k++) {
          K[3 * k] = H[k];
          K[3 * k + 1] = H[k + 2];
          K[3 * k + 2] = H[k + 4];
        }
        if (c_i + 1 > numMap) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, numMap, &ie_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        memset(&b_H[0], 0, 6U * sizeof(real_T));
        for (k = 0; k < 3; k++) {
          b_r2 = _mm_loadu_pd(&H[0]);
          r1 = k << 1;
          r3 = _mm_loadu_pd(&b_H[r1]);
          _mm_storeu_pd(
              &b_H[r1],
              _mm_add_pd(r3, _mm_mul_pd(b_r2, _mm_set1_pd(PBase[3 * k]))));
          b_r2 = _mm_loadu_pd(&H[2]);
          r3 = _mm_loadu_pd(&b_H[r1]);
          _mm_storeu_pd(
              &b_H[r1],
              _mm_add_pd(r3, _mm_mul_pd(b_r2, _mm_set1_pd(PBase[3 * k + 1]))));
          b_r2 = _mm_loadu_pd(&H[4]);
          r3 = _mm_loadu_pd(&b_H[r1]);
          _mm_storeu_pd(
              &b_H[r1],
              _mm_add_pd(r3, _mm_mul_pd(b_r2, _mm_set1_pd(PBase[3 * k + 2]))));
        }
        if (j + 1 > Rstack_size[2]) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, Rstack_size[2], &he_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        memset(&b_Hm[0], 0, sizeof(real_T) << 2);
        memset(&c_Hm[0], 0, sizeof(real_T) << 2);
        r4 = _mm_loadu_pd(&c_Hm[0]);
        /*  S = H * PBase * H' + Rstack(:,:,j); */
        memset(&y[0], 0, 6U * sizeof(real_T));
        for (b_i = 0; b_i < 2; b_i++) {
          a21 = b_H[b_i];
          dy = b_H[b_i + 2];
          dx = b_H[b_i + 4];
          K_tmp = b_i << 1;
          for (k = 0; k < 2; k++) {
            r1 = k << 1;
            b_r2 = _mm_loadu_pd(&Hm[r1]);
            r3 = _mm_loadu_pd(&b_Hm[K_tmp]);
            _mm_storeu_pd(
                &b_Hm[K_tmp],
                _mm_add_pd(
                    r3, _mm_mul_pd(b_r2,
                                   _mm_set1_pd(mapIn_data[c_i].P[k + K_tmp]))));
            S[b_i + r1] =
                ((a21 * K[3 * k] + dy * K[3 * k + 1]) + dx * K[3 * k + 2]) +
                Rstack_data[(b_i + 2 * k) + 4 * j];
          }
          a21 = K[3 * b_i];
          b_r2 = _mm_loadu_pd(&PBase[0]);
          r3 = _mm_loadu_pd(&y[3 * b_i]);
          _mm_storeu_pd(&y[3 * b_i],
                        _mm_add_pd(r3, _mm_mul_pd(b_r2, _mm_set1_pd(a21))));
          r1 = 3 * b_i + 2;
          y[r1] += PBase[2] * a21;
          a21 = K[3 * b_i + 1];
          b_r2 = _mm_loadu_pd(&PBase[3]);
          r3 = _mm_loadu_pd(&y[3 * b_i]);
          _mm_storeu_pd(&y[3 * b_i],
                        _mm_add_pd(r3, _mm_mul_pd(b_r2, _mm_set1_pd(a21))));
          y[r1] += PBase[5] * a21;
          a21 = K[r1];
          b_r2 = _mm_loadu_pd(&PBase[6]);
          r3 = _mm_loadu_pd(&y[3 * b_i]);
          _mm_storeu_pd(&y[3 * b_i],
                        _mm_add_pd(r3, _mm_mul_pd(b_r2, _mm_set1_pd(a21))));
          y[r1] += PBase[8] * a21;
        }
        b_r2 = _mm_loadu_pd(&b_Hm[0]);
        _mm_storeu_pd(&c_Hm[0],
                      _mm_add_pd(r4, _mm_mul_pd(b_r2, _mm_set1_pd(Hm[0]))));
        b_r2 = _mm_loadu_pd(&b_Hm[2]);
        r4 = _mm_loadu_pd(&c_Hm[0]);
        _mm_storeu_pd(&c_Hm[0],
                      _mm_add_pd(r4, _mm_mul_pd(b_r2, _mm_set1_pd(Hm[2]))));
        b_r2 = _mm_loadu_pd(&b_Hm[0]);
        r4 = _mm_loadu_pd(&c_Hm[2]);
        _mm_storeu_pd(&c_Hm[2],
                      _mm_add_pd(r4, _mm_mul_pd(b_r2, _mm_set1_pd(Hm[1]))));
        b_r2 = _mm_loadu_pd(&b_Hm[2]);
        r4 = _mm_loadu_pd(&c_Hm[2]);
        _mm_storeu_pd(&c_Hm[2],
                      _mm_add_pd(r4, _mm_mul_pd(b_r2, _mm_set1_pd(Hm[3]))));
        b_r2 = _mm_loadu_pd(&S[0]);
        r3 = _mm_loadu_pd(&c_Hm[0]);
        _mm_storeu_pd(&S[0], _mm_add_pd(b_r2, r3));
        b_r2 = _mm_loadu_pd(&S[2]);
        r3 = _mm_loadu_pd(&c_Hm[2]);
        _mm_storeu_pd(&S[2], _mm_add_pd(b_r2, r3));
        st.site = &ab_emlrtRSI;
        b_st.site = &ib_emlrtRSI;
        c_st.site = &jb_emlrtRSI;
        d_st.site = &kb_emlrtRSI;
        if (muDoubleScalarAbs(S[1]) > muDoubleScalarAbs(S[0])) {
          r1 = 1;
          r2 = 0;
        } else {
          r1 = 0;
          r2 = 1;
        }
        a21 = S[r2] / S[r1];
        dy = S[r1 + 2];
        dx = S[r2 + 2] - a21 * dy;
        if ((dx == 0.0) || (S[r1] == 0.0)) {
          e_st.site = &lb_emlrtRSI;
          if (!emlrtSetWarningFlag(&e_st)) {
            f_st.site = &mb_emlrtRSI;
            warning(&f_st);
          }
        }
        b_r2 = _mm_loadu_pd(&y[0]);
        _mm_storeu_pd(&K[3 * r1], _mm_div_pd(b_r2, _mm_set1_pd(S[r1])));
        b_r2 = _mm_loadu_pd(&K[3 * r1]);
        r3 = _mm_loadu_pd(&y[3]);
        _mm_storeu_pd(
            &K[3 * r2],
            _mm_div_pd(_mm_sub_pd(r3, _mm_mul_pd(b_r2, _mm_set1_pd(dy))),
                       _mm_set1_pd(dx)));
        b_r2 = _mm_loadu_pd(&K[3 * r2]);
        r3 = _mm_loadu_pd(&K[3 * r1]);
        _mm_storeu_pd(&K[3 * r1],
                      _mm_sub_pd(r3, _mm_mul_pd(b_r2, _mm_set1_pd(a21))));
        K_tmp = 3 * r1 + 2;
        K[K_tmp] = y[2] / S[r1];
        r1 = 3 * r2 + 2;
        K[r1] = (y[5] - K[K_tmp] * dy) / dx;
        K[K_tmp] -= K[r1] * a21;
        if (j + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, i, &je_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        /*  xDet_i(:,i) = x0 + K * (nu - H * (x0 - xBase)); */
        b_r2 = _mm_loadu_pd(&Zhat[0]);
        _mm_storeu_pd(&Z[0], _mm_sub_pd(_mm_loadu_pd(&Z_data[2 * j]), b_r2));
        if (c_i + 1 > numMap) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, numMap, &le_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        dy = Z[0];
        a21 = Z[1];
        b_r2 = _mm_loadu_pd(&K[0]);
        r3 = _mm_mul_pd(b_r2, _mm_set1_pd(dy));
        b_r2 = _mm_loadu_pd(&K[3]);
        b_r2 = _mm_mul_pd(b_r2, _mm_set1_pd(a21));
        b_r2 = _mm_add_pd(r3, b_r2);
        r3 = _mm_loadu_pd(&xBase[0]);
        b_r2 = _mm_add_pd(r3, b_r2);
        _mm_storeu_pd(&xDet_i_data[3 * c_i], b_r2);
        xDet_i_data[2 + 3 * c_i] = xBase[2] + (K[2] * dy + K[5] * a21);
        memset(&Pk[0], 0, 9U * sizeof(real_T));
        Pk[0] = 1.0;
        Pk[4] = 1.0;
        Pk[8] = 1.0;
        for (k = 0; k < 3; k++) {
          dy = K[k];
          a21 = K[k + 3];
          for (b_i = 0; b_i < 3; b_i++) {
            r1 = b_i << 1;
            r2 = k + 3 * b_i;
            b_Pk[r2] = Pk[r2] - (dy * H[r1] + a21 * H[r1 + 1]);
          }
        }
        if (c_i + 1 > numMap) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, numMap, &cf_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        for (k = 0; k < 3; k++) {
          r1 = 3 * k + 9 * c_i;
          PDet_i_data[r1] = 0.0;
          PDet_i_data[r1 + 1] = 0.0;
          PDet_i_data[r1 + 2] = 0.0;
          a21 = PBase[3 * k];
          b_r2 = _mm_loadu_pd(&b_Pk[0]);
          r3 = _mm_loadu_pd(&PDet_i_data[r1]);
          _mm_storeu_pd(&PDet_i_data[r1],
                        _mm_add_pd(r3, _mm_mul_pd(b_r2, _mm_set1_pd(a21))));
          PDet_i_data[r1 + 2] += b_Pk[2] * a21;
          a21 = PBase[3 * k + 1];
          b_r2 = _mm_loadu_pd(&b_Pk[3]);
          r3 = _mm_loadu_pd(&PDet_i_data[r1]);
          _mm_storeu_pd(&PDet_i_data[r1],
                        _mm_add_pd(r3, _mm_mul_pd(b_r2, _mm_set1_pd(a21))));
          PDet_i_data[r1 + 2] += b_Pk[5] * a21;
          a21 = PBase[3 * k + 2];
          b_r2 = _mm_loadu_pd(&b_Pk[6]);
          r3 = _mm_loadu_pd(&PDet_i_data[r1]);
          _mm_storeu_pd(&PDet_i_data[r1],
                        _mm_add_pd(r3, _mm_mul_pd(b_r2, _mm_set1_pd(a21))));
          PDet_i_data[r1 + 2] += b_Pk[8] * a21;
        }
        if (j + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, i, &ke_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (c_i + 1 > numMap) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, numMap, &kf_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        st.site = &bb_emlrtRSI;
        a21 = likelihood_local(&st, Zhat, &Z_data[2 * j], S) * params_P_D *
              mapIn_data[c_i].w;
        if (c_i + 1 > numMap) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, numMap, &lf_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        detRaw_i_data[c_i] = a21;
        denom += a21;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtConstCTX)sp);
        }
      }
      if (denom > 0.0) {
        for (b_i = 0; b_i < numMap; b_i++) {
          if (b_i + 1 > numMap) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, numMap, &if_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          a21 = detRaw_i_data[b_i] / denom;
          if (a21 > params_PHD_det_keep) {
            idx++;
            if (b_i + 1 > numMap) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, numMap, &me_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            if (idx > Xstore->size[1]) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, Xstore->size[1],
                                            &te_emlrtBCI, (emlrtConstCTX)sp);
            }
            r1 = 3 * (idx - 1);
            Xstore_data[r1] = xDet_i_data[3 * b_i];
            Xstore_data[r1 + 1] = xDet_i_data[3 * b_i + 1];
            Xstore_data[r1 + 2] = xDet_i_data[3 * b_i + 2];
            if (b_i + 1 > numMap) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, numMap, &ne_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            if (idx > maxComp) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, maxComp, &qe_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            for (k = 0; k < 3; k++) {
              K_tmp = 3 * k + 9 * b_i;
              i2 = 3 * k + 9 * (idx - 1);
              Pstore_data[i2] = PDet_i_data[K_tmp];
              Pstore_data[i2 + 1] = PDet_i_data[K_tmp + 1];
              Pstore_data[i2 + 2] = PDet_i_data[K_tmp + 2];
            }
            if (idx > Wstore->size[1]) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, Wstore->size[1],
                                            &jf_emlrtBCI, (emlrtConstCTX)sp);
            }
            Wstore_data[idx - 1] = a21;
            sumW += a21;
          }
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtConstCTX)sp);
          }
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    for (b_i = 0; b_i < numMap; b_i++) {
      if (b_i + 1 > numMap) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, numMap, &gf_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      a21 = mapIn_data[b_i].w * (1.0 - params_P_D);
      if (a21 > params_PHD_miss_keep) {
        idx++;
        if (idx > Xstore->size[1]) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, Xstore->size[1], &ue_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        r1 = 3 * (idx - 1);
        Xstore_data[r1] = xBase[0];
        Xstore_data[r1 + 1] = xBase[1];
        Xstore_data[r1 + 2] = xBase[2];
        if (idx > maxComp) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, maxComp, &re_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        for (k = 0; k < 3; k++) {
          r1 = 3 * k + 9 * (idx - 1);
          Pstore_data[r1] = PBase[3 * k];
          Pstore_data[r1 + 1] = PBase[3 * k + 1];
          Pstore_data[r1 + 2] = PBase[3 * k + 2];
        }
        if (idx > Wstore->size[1]) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, Wstore->size[1], &hf_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        Wstore_data[idx - 1] = a21;
        sumW += a21;
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    if (!(sumW <= 2.2204460492503131E-16)) {
      if (idx < 1) {
        K_tmp = 0;
        i2 = 0;
      } else {
        if (idx > Wstore->size[1]) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, Wstore->size[1], &oe_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        K_tmp = idx;
        if (idx > Wstore->size[1]) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, Wstore->size[1], &pe_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        i2 = idx;
      }
      r1 = r->size[0] * r->size[1];
      r->size[0] = 1;
      r->size[1] = K_tmp;
      emxEnsureCapacity_real_T(sp, r, r1, &hb_emlrtRTEI);
      b_r1 = r->data;
      r1 = (K_tmp / 2) << 1;
      r2 = r1 - 2;
      for (k = 0; k <= r2; k += 2) {
        b_r2 = _mm_loadu_pd(&Wstore_data[k]);
        _mm_storeu_pd(&b_r1[k], _mm_div_pd(b_r2, _mm_set1_pd(sumW)));
      }
      for (k = r1; k < K_tmp; k++) {
        b_r1[k] = Wstore_data[k] / sumW;
      }
      r1 = r->size[1];
      if (i2 != r->size[1]) {
        emlrtSubAssignSizeCheck1dR2017a(i2, r->size[1], &c_emlrtECI,
                                        (emlrtConstCTX)sp);
      }
      for (k = 0; k < r1; k++) {
        Wstore_data[k] = b_r1[k];
      }
      if (params_model == 1.0) {
        memset(&invP[0], 0, 9U * sizeof(real_T));
        diff[0] = 0.0;
        diff[1] = 0.0;
        diff[2] = 0.0;
        a21 = 0.0;
        for (b_i = 0; b_i < idx; b_i++) {
          if (b_i + 1 > maxComp) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, maxComp, &df_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          for (k = 0; k < 3; k++) {
            r1 = 3 * k + 9 * b_i;
            Pk[3 * k] = Pstore_data[r1];
            Pk[3 * k + 1] = Pstore_data[r1 + 1];
            Pk[3 * k + 2] = Pstore_data[r1 + 2];
          }
          st.site = &cb_emlrtRSI;
          b_regularize_cov_local(&st, Pk);
          if (b_i + 1 > Wstore->size[1]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, Wstore->size[1],
                                          &se_emlrtBCI, (emlrtConstCTX)sp);
          }
          dy = Wstore_data[b_i] * (1.0 / ((Pk[0] + Pk[4]) + Pk[8]));
          a21 += dy;
          st.site = &db_emlrtRSI;
          inv(&st, Pk, b_Pk);
          b_r2 = _mm_loadu_pd(&b_Pk[0]);
          r3 = _mm_loadu_pd(&invP[0]);
          r4 = _mm_set1_pd(dy);
          _mm_storeu_pd(&invP[0], _mm_add_pd(r3, _mm_mul_pd(r4, b_r2)));
          b_r2 = _mm_loadu_pd(&b_Pk[2]);
          r3 = _mm_loadu_pd(&invP[2]);
          _mm_storeu_pd(&invP[2], _mm_add_pd(r3, _mm_mul_pd(r4, b_r2)));
          b_r2 = _mm_loadu_pd(&b_Pk[4]);
          r3 = _mm_loadu_pd(&invP[4]);
          _mm_storeu_pd(&invP[4], _mm_add_pd(r3, _mm_mul_pd(r4, b_r2)));
          b_r2 = _mm_loadu_pd(&b_Pk[6]);
          r3 = _mm_loadu_pd(&invP[6]);
          _mm_storeu_pd(&invP[6], _mm_add_pd(r3, _mm_mul_pd(r4, b_r2)));
          invP[8] += dy * b_Pk[8];
          st.site = &eb_emlrtRSI;
          inv(&st, Pk, b_Pk);
          if (b_i + 1 > Xstore->size[1]) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, Xstore->size[1],
                                          &ve_emlrtBCI, (emlrtConstCTX)sp);
          }
          for (k = 0; k < 3; k++) {
            diff[k] += (dy * b_Pk[k] * Xstore_data[3 * b_i] +
                        dy * b_Pk[k + 3] * Xstore_data[3 * b_i + 1]) +
                       dy * b_Pk[k + 6] * Xstore_data[3 * b_i + 2];
          }
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtConstCTX)sp);
          }
        }
        b_r2 = _mm_loadu_pd(&invP[0]);
        r3 = _mm_set1_pd(a21);
        _mm_storeu_pd(&invP[0], _mm_div_pd(b_r2, r3));
        b_r2 = _mm_loadu_pd(&invP[2]);
        _mm_storeu_pd(&invP[2], _mm_div_pd(b_r2, r3));
        b_r2 = _mm_loadu_pd(&invP[4]);
        _mm_storeu_pd(&invP[4], _mm_div_pd(b_r2, r3));
        b_r2 = _mm_loadu_pd(&invP[6]);
        _mm_storeu_pd(&invP[6], _mm_div_pd(b_r2, r3));
        invP[8] /= a21;
        b_r2 = _mm_loadu_pd(&diff[0]);
        _mm_storeu_pd(&diff[0], _mm_div_pd(b_r2, r3));
        diff[2] /= a21;
        st.site = &fb_emlrtRSI;
        b_regularize_cov_local(&st, invP);
        st.site = &gb_emlrtRSI;
        inv(&st, invP, PBase);
        xBase[0] = 0.0;
        xBase[1] = 0.0;
        xBase[2] = 0.0;
        b_r2 = _mm_loadu_pd(&PBase[0]);
        r3 = _mm_loadu_pd(&xBase[0]);
        _mm_storeu_pd(&xBase[0],
                      _mm_add_pd(r3, _mm_mul_pd(b_r2, _mm_set1_pd(diff[0]))));
        xBase[2] += diff[0] * PBase[2];
        b_r2 = _mm_loadu_pd(&PBase[3]);
        r3 = _mm_loadu_pd(&xBase[0]);
        _mm_storeu_pd(&xBase[0],
                      _mm_add_pd(r3, _mm_mul_pd(b_r2, _mm_set1_pd(diff[1]))));
        xBase[2] += diff[1] * PBase[5];
        b_r2 = _mm_loadu_pd(&PBase[6]);
        r3 = _mm_loadu_pd(&xBase[0]);
        _mm_storeu_pd(&xBase[0],
                      _mm_add_pd(r3, _mm_mul_pd(b_r2, _mm_set1_pd(diff[2]))));
        xBase[2] += diff[2] * PBase[8];
      } else {
        xBase[0] = 0.0;
        xBase[1] = 0.0;
        xBase[2] = 0.0;
        for (k = 0; k < idx; k++) {
          if (k + 1 > Wstore->size[1]) {
            emlrtDynamicBoundsCheckR2012b(k + 1, 1, Wstore->size[1],
                                          &we_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (k + 1 > Xstore->size[1]) {
            emlrtDynamicBoundsCheckR2012b(k + 1, 1, Xstore->size[1],
                                          &xe_emlrtBCI, (emlrtConstCTX)sp);
          }
          a21 = Wstore_data[k];
          b_r2 = _mm_loadu_pd(&Xstore_data[3 * k]);
          r3 = _mm_loadu_pd(&xBase[0]);
          _mm_storeu_pd(&xBase[0],
                        _mm_add_pd(r3, _mm_mul_pd(_mm_set1_pd(a21), b_r2)));
          xBase[2] += a21 * Xstore_data[3 * k + 2];
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtConstCTX)sp);
          }
        }
        if (!(iterCnt != params_iter_max)) {
          memset(&PBase[0], 0, 9U * sizeof(real_T));
          for (k = 0; k < idx; k++) {
            if (k + 1 > Xstore->size[1]) {
              emlrtDynamicBoundsCheckR2012b(k + 1, 1, Xstore->size[1],
                                            &ye_emlrtBCI, (emlrtConstCTX)sp);
            }
            b_r2 = _mm_loadu_pd(&Xstore_data[3 * k]);
            r3 = _mm_loadu_pd(&xBase[0]);
            _mm_storeu_pd(&diff[0], _mm_sub_pd(b_r2, r3));
            diff[2] = Xstore_data[3 * k + 2] - xBase[2];
            if (k + 1 > Wstore->size[1]) {
              emlrtDynamicBoundsCheckR2012b(k + 1, 1, Wstore->size[1],
                                            &af_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (k + 1 > maxComp) {
              emlrtDynamicBoundsCheckR2012b(k + 1, 1, maxComp, &bf_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            a21 = Wstore_data[k];
            b_r2 = _mm_loadu_pd(&diff[0]);
            r3 = _mm_loadu_pd(&Pstore_data[9 * k]);
            r4 = _mm_set1_pd(0.0);
            _mm_storeu_pd(
                &b_Pk[0],
                _mm_add_pd(r3, _mm_add_pd(r4, _mm_mul_pd(b_r2, _mm_set1_pd(
                                                                   diff[0])))));
            b_Pk[2] = Pstore_data[9 * k + 2] + diff[0] * diff[2];
            b_r2 = _mm_loadu_pd(&diff[0]);
            r3 = _mm_loadu_pd(&Pstore_data[9 * k + 3]);
            _mm_storeu_pd(
                &b_Pk[3],
                _mm_add_pd(r3, _mm_add_pd(r4, _mm_mul_pd(b_r2, _mm_set1_pd(
                                                                   diff[1])))));
            b_Pk[5] = Pstore_data[9 * k + 5] + diff[1] * diff[2];
            b_r2 = _mm_loadu_pd(&diff[0]);
            r3 = _mm_loadu_pd(&Pstore_data[9 * k + 6]);
            _mm_storeu_pd(
                &b_Pk[6],
                _mm_add_pd(r3, _mm_add_pd(r4, _mm_mul_pd(b_r2, _mm_set1_pd(
                                                                   diff[2])))));
            b_Pk[8] = Pstore_data[9 * k + 8] + diff[2] * diff[2];
            for (b_i = 0; b_i <= 6; b_i += 2) {
              b_r2 = _mm_loadu_pd(&b_Pk[b_i]);
              b_r2 = _mm_mul_pd(_mm_set1_pd(a21), b_r2);
              r3 = _mm_loadu_pd(&PBase[b_i]);
              b_r2 = _mm_add_pd(r3, b_r2);
              _mm_storeu_pd(&PBase[b_i], b_r2);
            }
            PBase[8] += a21 * b_Pk[8];
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b((emlrtConstCTX)sp);
            }
          }
          st.site = &hb_emlrtRSI;
          b_regularize_cov_local(&st, PBase);
        }
      }
    }
  }
  emxFree_real_T(sp, &r);
  emxFree_real_T(sp, &Wstore);
  emxFree_real_T(sp, &Pstore);
  emxFree_real_T(sp, &Xstore);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void preprocess_local(const emlrtStack *sp, const real_T curMea_data[],
                             const int32_T curMea_size[2],
                             const real_T Rpolar[4], real_T meaXY_data[],
                             int32_T meaXY_size[2], real_T Rstack_data[],
                             int32_T Rstack_size[3])
{
  real_T J[4];
  real_T b_J[4];
  int32_T iv[2];
  int32_T tmp_size[2];
  int32_T b_loop_ub;
  int32_T k;
  int32_T loop_ub;
  meaXY_size[0] = 2;
  loop_ub = curMea_size[1];
  meaXY_size[1] = curMea_size[1];
  b_loop_ub = curMea_size[1] << 1;
  if (b_loop_ub - 1 >= 0) {
    memset(&meaXY_data[0], 0, (uint32_T)b_loop_ub * sizeof(real_T));
  }
  Rstack_size[0] = 2;
  Rstack_size[1] = 2;
  Rstack_size[2] = curMea_size[1];
  b_loop_ub = curMea_size[1] << 2;
  if (b_loop_ub - 1 >= 0) {
    memset(&Rstack_data[0], 0, (uint32_T)b_loop_ub * sizeof(real_T));
  }
  if (curMea_size[1] != 0) {
    real_T tmp_data[48];
    tmp_size[1] = curMea_size[1];
    for (k = 0; k < loop_ub; k++) {
      tmp_data[k] = curMea_data[2 * k + 1];
    }
    for (k = 0; k < loop_ub; k++) {
      tmp_data[k] = muDoubleScalarCos(tmp_data[k]);
    }
    tmp_size[0] = 1;
    for (k = 0; k < loop_ub; k++) {
      tmp_data[k] *= curMea_data[2 * k];
    }
    iv[0] = 1;
    iv[1] = curMea_size[1];
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &b_emlrtECI,
                                  (emlrtCTX)sp);
    for (k = 0; k < loop_ub; k++) {
      meaXY_data[2 * k] = tmp_data[k];
    }
    for (k = 0; k < loop_ub; k++) {
      tmp_data[k] = curMea_data[2 * k + 1];
    }
    for (k = 0; k < loop_ub; k++) {
      tmp_data[k] = muDoubleScalarSin(tmp_data[k]);
    }
    tmp_size[0] = 1;
    for (k = 0; k < loop_ub; k++) {
      tmp_data[k] *= curMea_data[2 * k];
    }
    iv[0] = 1;
    iv[1] = curMea_size[1];
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &emlrtECI,
                                  (emlrtCTX)sp);
    for (k = 0; k < loop_ub; k++) {
      meaXY_data[2 * k + 1] = tmp_data[k];
    }
    Rstack_size[0] = 2;
    Rstack_size[1] = 2;
    Rstack_size[2] = (int8_T)curMea_size[1];
    for (k = 0; k < loop_ub; k++) {
      __m128d r;
      __m128d r1;
      real_T J_tmp;
      real_T b_J_tmp;
      real_T d;
      if (k + 1 > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, loop_ub, &emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      J_tmp = curMea_data[2 * k + 1];
      b_J_tmp = muDoubleScalarSin(J_tmp);
      if (k + 1 > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, loop_ub, &c_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      J_tmp = muDoubleScalarCos(J_tmp);
      if (k + 1 > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, loop_ub, &b_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      J[0] = J_tmp;
      d = curMea_data[2 * k];
      J[2] = -d * b_J_tmp;
      J[1] = b_J_tmp;
      J[3] = d * J_tmp;
      memset(&b_J[0], 0, sizeof(real_T) << 2);
      r = _mm_loadu_pd(&J[0]);
      r1 = _mm_loadu_pd(&b_J[0]);
      _mm_storeu_pd(&b_J[0],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(Rpolar[0]))));
      r = _mm_loadu_pd(&J[2]);
      r1 = _mm_loadu_pd(&b_J[0]);
      _mm_storeu_pd(&b_J[0],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(Rpolar[1]))));
      r = _mm_loadu_pd(&J[0]);
      r1 = _mm_loadu_pd(&b_J[2]);
      _mm_storeu_pd(&b_J[2],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(Rpolar[2]))));
      r = _mm_loadu_pd(&J[2]);
      r1 = _mm_loadu_pd(&b_J[2]);
      _mm_storeu_pd(&b_J[2],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(Rpolar[3]))));
      if (k + 1 > Rstack_size[2]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, Rstack_size[2], &d_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Rstack_data[4 * k] = 0.0;
      Rstack_data[4 * k + 1] = 0.0;
      r = _mm_loadu_pd(&b_J[0]);
      r1 = _mm_loadu_pd(&Rstack_data[4 * k]);
      _mm_storeu_pd(&Rstack_data[4 * k],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(J_tmp))));
      r = _mm_loadu_pd(&b_J[2]);
      r1 = _mm_loadu_pd(&Rstack_data[4 * k]);
      _mm_storeu_pd(&Rstack_data[4 * k],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(J[2]))));
      b_loop_ub = 4 * k + 2;
      Rstack_data[b_loop_ub] = 0.0;
      Rstack_data[4 * k + 3] = 0.0;
      r = _mm_loadu_pd(&b_J[0]);
      r1 = _mm_loadu_pd(&Rstack_data[b_loop_ub]);
      _mm_storeu_pd(&Rstack_data[b_loop_ub],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(b_J_tmp))));
      r = _mm_loadu_pd(&b_J[2]);
      r1 = _mm_loadu_pd(&Rstack_data[b_loop_ub]);
      _mm_storeu_pd(&Rstack_data[b_loop_ub],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(J[3]))));
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
  }
}

static void regularize_cov_local(const emlrtStack *sp, real_T P[4])
{
  real_T b_P[4];
  real_T jitter;
  int32_T flag;
  jitter = (P[1] + P[2]) / 2.0;
  P[0] = (P[0] + P[0]) / 2.0;
  P[1] = jitter;
  P[2] = jitter;
  P[3] = (P[3] + P[3]) / 2.0;
  jitter = 1.0E-9;
  b_P[0] = P[0];
  b_P[1] = P[1];
  b_P[2] = P[2];
  b_P[3] = P[3];
  flag = chol(b_P, &flag);
  while (flag != 0) {
    real_T d;
    P[0] += jitter;
    d = P[1] + jitter * 0.0;
    P[1] = d;
    P[2] = d;
    P[3] += jitter;
    jitter *= 10.0;
    b_P[0] = P[0];
    b_P[1] = P[1];
    b_P[2] = P[2];
    b_P[3] = P[3];
    flag = chol(b_P, &flag);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
}

static void split_map_by_fov_local(const emlrtStack *sp, const real_T x[3],
                                   const struct0_T mapIn_data[],
                                   const int32_T mapIn_size[2], real_T fovRange,
                                   real_T fovAngle, struct0_T keepMap_data[],
                                   int32_T keepMap_size[2],
                                   struct0_T visMap_data[],
                                   int32_T visMap_size[2])
{
  emlrtStack st;
  emxArray_struct0_T *mapOut;
  struct0_T *mapOut_data;
  int32_T i;
  int32_T keepCount;
  int32_T keepMap_tmp;
  int32_T visCount;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  keepMap_tmp = (int32_T)muDoubleScalarMax(1.0, mapIn_size[1]);
  emxInit_struct0_T(sp, &mapOut, &j_emlrtRTEI);
  st.site = &t_emlrtRSI;
  repmat(&st, keepMap_tmp, mapOut);
  mapOut_data = mapOut->data;
  keepCount = mapOut->size[1];
  keepMap_size[1] = mapOut->size[1];
  for (i = 0; i < keepCount; i++) {
    keepMap_data[i] = mapOut_data[i];
  }
  st.site = &u_emlrtRSI;
  repmat(&st, keepMap_tmp, mapOut);
  mapOut_data = mapOut->data;
  keepMap_tmp = mapOut->size[1];
  visMap_size[1] = mapOut->size[1];
  for (i = 0; i < keepMap_tmp; i++) {
    visMap_data[i] = mapOut_data[i];
  }
  keepCount = 0;
  visCount = 0;
  keepMap_tmp = mapIn_size[1];
  for (i = 0; i < keepMap_tmp; i++) {
    real_T dx;
    real_T dy;
    boolean_T guard1;
    if (i + 1 > keepMap_tmp) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, keepMap_tmp, &f_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    dx = mapIn_data[i].m[0] - x[0];
    if (i + 1 > keepMap_tmp) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, keepMap_tmp, &g_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    dy = mapIn_data[i].m[1] - x[1];
    guard1 = false;
    if (muDoubleScalarSqrt(dx * dx + dy * dy) <= fovRange) {
      dx = (muDoubleScalarAtan2(dy, dx) - x[2]) + 3.1415926535897931;
      if (muDoubleScalarIsNaN(dx) || muDoubleScalarIsInf(dx)) {
        dx = rtNaN;
      } else {
        dy = muDoubleScalarAbs(dx / 6.2831853071795862);
        if (muDoubleScalarAbs(dy - muDoubleScalarFloor(dy + 0.5)) >
            2.2204460492503131E-16 * dy) {
          dx = muDoubleScalarRem(dx, 6.2831853071795862);
        } else {
          dx = 0.0;
        }
        if (dx == 0.0) {
          dx = 0.0;
        } else if (dx < 0.0) {
          dx += 6.2831853071795862;
        }
      }
      if (muDoubleScalarAbs(dx - 3.1415926535897931) <= fovAngle) {
        visCount++;
        if (i + 1 > keepMap_tmp) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, keepMap_tmp, &j_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (visCount > visMap_size[1]) {
          emlrtDynamicBoundsCheckR2012b(visCount, 1, visMap_size[1],
                                        &k_emlrtBCI, (emlrtConstCTX)sp);
        }
        visMap_data[visCount - 1] = mapIn_data[i];
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      keepCount++;
      if (i + 1 > keepMap_tmp) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, keepMap_tmp, &h_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (keepCount > keepMap_size[1]) {
        emlrtDynamicBoundsCheckR2012b(keepCount, 1, keepMap_size[1],
                                      &i_emlrtBCI, (emlrtConstCTX)sp);
      }
      keepMap_data[keepCount - 1] = mapIn_data[i];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  st.site = &w_emlrtRSI;
  if (keepCount == 0) {
    mapOut->size[0] = 1;
    mapOut->size[1] = 0;
  } else {
    if (keepCount > keepMap_size[1]) {
      emlrtDynamicBoundsCheckR2012b(keepCount, 1, keepMap_size[1], &e_emlrtBCI,
                                    &st);
    }
    keepMap_tmp = mapOut->size[0] * mapOut->size[1];
    mapOut->size[0] = 1;
    mapOut->size[1] = keepCount;
    emxEnsureCapacity_struct0_T(&st, mapOut, keepMap_tmp, &i_emlrtRTEI);
    mapOut_data = mapOut->data;
    for (i = 0; i < keepCount; i++) {
      mapOut_data[i] = keepMap_data[i];
    }
  }
  keepMap_size[0] = 1;
  keepMap_tmp = mapOut->size[1];
  keepMap_size[1] = mapOut->size[1];
  for (i = 0; i < keepMap_tmp; i++) {
    keepMap_data[i] = mapOut_data[i];
  }
  st.site = &x_emlrtRSI;
  if (visCount == 0) {
    mapOut->size[0] = 1;
    mapOut->size[1] = 0;
  } else {
    if (visCount > visMap_size[1]) {
      emlrtDynamicBoundsCheckR2012b(visCount, 1, visMap_size[1], &e_emlrtBCI,
                                    &st);
    }
    keepMap_tmp = mapOut->size[0] * mapOut->size[1];
    mapOut->size[0] = 1;
    mapOut->size[1] = visCount;
    emxEnsureCapacity_struct0_T(&st, mapOut, keepMap_tmp, &i_emlrtRTEI);
    mapOut_data = mapOut->data;
    for (i = 0; i < visCount; i++) {
      mapOut_data[i] = visMap_data[i];
    }
  }
  visMap_size[0] = 1;
  keepMap_tmp = mapOut->size[1];
  visMap_size[1] = mapOut->size[1];
  for (i = 0; i < keepMap_tmp; i++) {
    visMap_data[i] = mapOut_data[i];
  }
  emxFree_struct0_T(sp, &mapOut);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void tuning_local(const emlrtStack *sp, const emxArray_struct0_T *mapIn,
                         real_T params_prune_threshold,
                         real_T params_max_components,
                         real_T params_merge_threshold,
                         emxArray_struct0_T *mapOut)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_int32_T *members;
  emxArray_real_T *mergedWeights;
  emxArray_real_T *weights;
  emxArray_struct0_T *merged;
  emxArray_struct0_T *pruned;
  emxArray_struct0_T *r;
  const struct0_T *mapIn_data;
  struct0_T *merged_data;
  struct0_T *pruned_data;
  struct0_T *r1;
  real_T Pi[4];
  real_T b_pruned[4];
  real_T diff[2];
  real_T meanSum[2];
  real_T *mergedWeights_data;
  real_T *weights_data;
  int32_T i;
  int32_T ii;
  int32_T *members_data;
  boolean_T used_data[25600];
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  mapIn_data = mapIn->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  function [mapOut, birthIdx] = map_update_local(x, P, keepMap, inMap, Z,
   * params, RstackLocal) */
  /*      numZ = size(Z, 2); */
  /*      numKeep = numel(keepMap); */
  /*      numIn = numel(inMap); */
  /*   */
  /*      birthIdx = true(1, numZ); */
  /*      cap = max(1, numKeep + numIn * (numZ + 1)); */
  /*      mapOut = repmat(map_template_local(), 1, cap); */
  /*      outCount = 0; */
  /*      for i = 1:numKeep */
  /*          outCount = outCount + 1; */
  /*          mapOut(outCount) = keepMap(i); */
  /*      end */
  /*   */
  /*      if numIn == 0 */
  /*          mapOut = resize_map_local(mapOut, outCount); */
  /*          return; */
  /*      end */
  /*   */
  /*      Zmap = zeros(2, numZ); */
  /*      Rworld = zeros(2, 2, numZ); */
  /*      rot = rotate_x2w_local(-x(3)); */
  /*      for j = 1:numZ */
  /*          Zmap(:,j) = x(1:2) + rot * Z(:,j); */
  /*          Jx = [1 0 Z(1,j) * sin(-x(3)) - Z(2,j) * cos(-x(3)); ... */
  /*                0 1 Z(1,j) * cos(-x(3)) + Z(2,j) * sin(-x(3))]; */
  /*          Rworld(:,:,j) = rot * RstackLocal(:,:,j) * rot' + Jx * P * Jx'; */
  /*      end */
  /*   */
  /*      detDen = params.clutter_rate * ones(1, numZ); */
  /*      rawLike = zeros(numIn, numZ); */
  /*      for i = 1:numIn */
  /*          for j = 1:numZ */
  /*              S = inMap(i).P + Rworld(:,:,j); */
  /*              rawLike(i,j) = likelihood_local(inMap(i).m, Zmap(:,j), S) *
   * params.P_D * inMap(i).w; */
  /*              detDen(j) = detDen(j) + rawLike(i,j); */
  /*          end */
  /*      end */
  /*   */
  /*      for i = 1:numIn */
  /*          missW = inMap(i).w * (1 - params.P_D); */
  /*          if missW > params.map_miss_prune_threshold */
  /*              outCount = outCount + 1; */
  /*              mapOut(outCount).m = inMap(i).m; */
  /*              mapOut(outCount).P = regularize_cov_local(inMap(i).P); */
  /*              mapOut(outCount).w = missW; */
  /*          end */
  /*      end */
  /*   */
  /*      for j = 1:numZ */
  /*          if detDen(j) <= 0 */
  /*              continue; */
  /*          end */
  /*          for i = 1:numIn */
  /*              w = rawLike(i,j) / detDen(j); */
  /*              if w > params.map_detection_add_threshold */
  /*                  S = inMap(i).P + Rworld(:,:,j); */
  /*                  K = inMap(i).P / S; */
  /*                  nu = Zmap(:,j) - inMap(i).m; */
  /*                  outCount = outCount + 1; */
  /*                  mapOut(outCount).m = inMap(i).m + K * nu; */
  /*                  mapOut(outCount).P = regularize_cov_local((eye(2) - K) *
   * inMap(i).P); */
  /*                  mapOut(outCount).w = w; */
  /*                  birthIdx(j) = false; */
  /*              end */
  /*          end */
  /*      end */
  /*   */
  /*      mapOut = resize_map_local(mapOut, outCount); */
  /*  end */
  emxInit_struct0_T(sp, &pruned, &p_emlrtRTEI);
  emxInit_real_T(sp, &weights, 2, &ab_emlrtRTEI);
  emxInit_struct0_T(sp, &merged, &t_emlrtRTEI);
  emxInit_real_T(sp, &mergedWeights, 2, &u_emlrtRTEI);
  emxInit_int32_T(sp, &members, 2, &x_emlrtRTEI);
  emxInit_struct0_T(sp, &r, &bb_emlrtRTEI);
  if (mapIn->size[1] == 0) {
    mapOut->size[0] = 1;
    mapOut->size[1] = 0;
  } else {
    int32_T b_r1;
    int32_T loop_ub;
    int32_T prunedCount;
    st.site = &dd_emlrtRSI;
    repmat(&st, mapIn->size[1], r);
    r1 = r->data;
    b_r1 = pruned->size[0] * pruned->size[1];
    pruned->size[0] = 1;
    loop_ub = r->size[1];
    pruned->size[1] = r->size[1];
    emxEnsureCapacity_struct0_T(sp, pruned, b_r1, &p_emlrtRTEI);
    pruned_data = pruned->data;
    for (i = 0; i < loop_ub; i++) {
      pruned_data[i] = r1[i];
    }
    prunedCount = 0;
    b_r1 = mapIn->size[1];
    for (i = 0; i < b_r1; i++) {
      if (i + 1 > b_r1) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_r1, &vc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (mapIn_data[i].w > params_prune_threshold) {
        prunedCount++;
        if ((prunedCount < 1) || (prunedCount > loop_ub)) {
          emlrtDynamicBoundsCheckR2012b(prunedCount, 1, loop_ub, &td_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (i + 1 > b_r1) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_r1, &ud_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        pruned_data[prunedCount - 1].m[0] = mapIn_data[i].m[0];
        if (prunedCount > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(prunedCount, 1, loop_ub, &td_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (i + 1 > b_r1) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_r1, &ud_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        pruned_data[prunedCount - 1].m[1] = mapIn_data[i].m[1];
        if (i + 1 > b_r1) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_r1, &rc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (prunedCount > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(prunedCount, 1, loop_ub, &sc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        pruned_data[prunedCount - 1].P[0] = mapIn_data[i].P[0];
        pruned_data[prunedCount - 1].P[1] = mapIn_data[i].P[1];
        pruned_data[prunedCount - 1].P[2] = mapIn_data[i].P[2];
        pruned_data[prunedCount - 1].P[3] = mapIn_data[i].P[3];
        if (prunedCount > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(prunedCount, 1, loop_ub, &sc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        st.site = &cd_emlrtRSI;
        regularize_cov_local(&st, pruned_data[prunedCount - 1].P);
        if (i + 1 > b_r1) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_r1, &yc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (prunedCount > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(prunedCount, 1, loop_ub, &ad_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        pruned_data[prunedCount - 1].w = mapIn_data[i].w;
        if (prunedCount > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(prunedCount, 1, loop_ub, &rd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (i + 1 > b_r1) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_r1, &sd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        pruned_data[prunedCount - 1].label[0] = mapIn_data[i].label[0];
        if (prunedCount > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(prunedCount, 1, loop_ub, &rd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (i + 1 > b_r1) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_r1, &sd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        pruned_data[prunedCount - 1].label[1] = mapIn_data[i].label[1];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    if (prunedCount == 0) {
      mapOut->size[0] = 1;
      mapOut->size[1] = 0;
    } else {
      real_T a21;
      int32_T b_loop_ub;
      int32_T c_loop_ub;
      int32_T mergedCount;
      int32_T r2;
      if (prunedCount > r->size[1]) {
        emlrtDynamicBoundsCheckR2012b(prunedCount, 1, r->size[1], &ic_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      b_r1 = pruned->size[0] * pruned->size[1];
      pruned->size[1] = prunedCount;
      emxEnsureCapacity_struct0_T(sp, pruned, b_r1, &q_emlrtRTEI);
      pruned_data = pruned->data;
      b_r1 = weights->size[0] * weights->size[1];
      weights->size[0] = 1;
      weights->size[1] = prunedCount;
      emxEnsureCapacity_real_T(sp, weights, b_r1, &r_emlrtRTEI);
      weights_data = weights->data;
      for (i = 0; i < prunedCount; i++) {
        if (i + 1 > prunedCount) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, prunedCount, &wc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (i + 1 > weights->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, weights->size[1],
                                        &xc_emlrtBCI, (emlrtConstCTX)sp);
        }
        weights_data[i] = pruned_data[i].w;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtConstCTX)sp);
        }
      }
      st.site = &bd_emlrtRSI;
      b_st.site = &ed_emlrtRSI;
      sort(&b_st, weights, members);
      members_data = members->data;
      b_r1 = weights->size[0] * weights->size[1];
      weights->size[0] = 1;
      b_loop_ub = members->size[1];
      weights->size[1] = members->size[1];
      emxEnsureCapacity_real_T(&st, weights, b_r1, &s_emlrtRTEI);
      weights_data = weights->data;
      for (i = 0; i < b_loop_ub; i++) {
        weights_data[i] = members_data[i];
      }
      memset(&used_data[0], 0, (uint32_T)prunedCount * sizeof(boolean_T));
      st.site = &ad_emlrtRSI;
      repmat(&st, prunedCount, r);
      r1 = r->data;
      b_r1 = merged->size[0] * merged->size[1];
      merged->size[0] = 1;
      c_loop_ub = r->size[1];
      merged->size[1] = r->size[1];
      emxEnsureCapacity_struct0_T(sp, merged, b_r1, &t_emlrtRTEI);
      merged_data = merged->data;
      for (i = 0; i < c_loop_ub; i++) {
        merged_data[i] = r1[i];
      }
      b_r1 = mergedWeights->size[0] * mergedWeights->size[1];
      mergedWeights->size[0] = 1;
      mergedWeights->size[1] = prunedCount;
      emxEnsureCapacity_real_T(sp, mergedWeights, b_r1, &u_emlrtRTEI);
      mergedWeights_data = mergedWeights->data;
      for (i = 0; i < prunedCount; i++) {
        mergedWeights_data[i] = 0.0;
      }
      mergedCount = 0;
      for (ii = 0; ii < prunedCount; ii++) {
        int32_T b_i;
        if (ii + 1 > b_loop_ub) {
          emlrtDynamicBoundsCheckR2012b(ii + 1, 1, b_loop_ub, &jc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        b_i = (int32_T)weights_data[ii];
        if ((b_i < 1) || (b_i > prunedCount)) {
          emlrtDynamicBoundsCheckR2012b(b_i, 1, prunedCount, &bd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (!used_data[b_i - 1]) {
          __m128d b_r2;
          __m128d r3;
          __m128d r4;
          __m128d r5;
          __m128d r6;
          real_T a22;
          real_T minLabelT;
          int32_T i1;
          int32_T memberCount;
          if (b_i > prunedCount) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, prunedCount, &cd_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          used_data[b_i - 1] = true;
          b_r1 = members->size[0] * members->size[1];
          members->size[0] = 1;
          members->size[1] = prunedCount;
          emxEnsureCapacity_int32_T(sp, members, b_r1, &x_emlrtRTEI);
          members_data = members->data;
          for (i = 0; i < prunedCount; i++) {
            members_data[i] = 0;
          }
          memberCount = 1;
          members_data[0] = b_i;
          if (b_i > prunedCount) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, prunedCount, &tc_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          Pi[0] = pruned_data[b_i - 1].P[0];
          Pi[1] = pruned_data[b_i - 1].P[1];
          Pi[2] = pruned_data[b_i - 1].P[2];
          Pi[3] = pruned_data[b_i - 1].P[3];
          st.site = &yc_emlrtRSI;
          regularize_cov_local(&st, Pi);
          i1 = prunedCount - ii;
          for (i = 0; i <= i1 - 2; i++) {
            b_r1 = ii + i;
            if (b_r1 + 2 > b_loop_ub) {
              emlrtDynamicBoundsCheckR2012b(b_r1 + 2, 1, b_loop_ub,
                                            &kc_emlrtBCI, (emlrtConstCTX)sp);
            }
            loop_ub = (int32_T)weights_data[b_r1 + 1];
            if ((loop_ub < 1) || (loop_ub > prunedCount)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, prunedCount,
                                            &dd_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (!used_data[loop_ub - 1]) {
              if (loop_ub > prunedCount) {
                emlrtDynamicBoundsCheckR2012b(loop_ub, 1, prunedCount,
                                              &od_emlrtBCI, (emlrtConstCTX)sp);
              }
              b_r2 = _mm_loadu_pd(&pruned_data[loop_ub - 1].m[0]);
              r4 = _mm_loadu_pd(&pruned_data[b_i - 1].m[0]);
              _mm_storeu_pd(&diff[0], _mm_sub_pd(b_r2, r4));
              st.site = &xc_emlrtRSI;
              b_st.site = &ce_emlrtRSI;
              c_st.site = &de_emlrtRSI;
              d_st.site = &kb_emlrtRSI;
              if (muDoubleScalarAbs(Pi[1]) > muDoubleScalarAbs(Pi[0])) {
                b_r1 = 1;
                r2 = 0;
              } else {
                b_r1 = 0;
                r2 = 1;
              }
              a21 = Pi[r2] / Pi[b_r1];
              minLabelT = Pi[b_r1 + 2];
              a22 = Pi[r2 + 2] - a21 * minLabelT;
              if ((a22 == 0.0) || (Pi[b_r1] == 0.0)) {
                e_st.site = &lb_emlrtRSI;
                if (!emlrtSetWarningFlag(&e_st)) {
                  f_st.site = &mb_emlrtRSI;
                  warning(&f_st);
                }
              }
              meanSum[1] = (diff[r2] - diff[b_r1] * a21) / a22;
              meanSum[0] = (diff[b_r1] - meanSum[1] * minLabelT) / Pi[b_r1];
              if (diff[0] * meanSum[0] + diff[1] * meanSum[1] <
                  params_merge_threshold) {
                if (loop_ub > prunedCount) {
                  emlrtDynamicBoundsCheckR2012b(
                      loop_ub, 1, prunedCount, &ld_emlrtBCI, (emlrtConstCTX)sp);
                }
                used_data[loop_ub - 1] = true;
                memberCount++;
                if (memberCount > members->size[1]) {
                  emlrtDynamicBoundsCheckR2012b(memberCount, 1,
                                                members->size[1], &md_emlrtBCI,
                                                (emlrtConstCTX)sp);
                }
                members_data[memberCount - 1] = loop_ub;
              }
            }
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b((emlrtConstCTX)sp);
            }
          }
          a21 = 0.0;
          meanSum[0] = 0.0;
          meanSum[1] = 0.0;
          /*  merge label: keep earliest timestamp and max count */
          minLabelT = rtInf;
          a22 = 0.0;
          for (i = 0; i < memberCount; i++) {
            if (i + 1 > members->size[1]) {
              emlrtDynamicBoundsCheckR2012b(i + 1, 1, members->size[1],
                                            &lc_emlrtBCI, (emlrtConstCTX)sp);
            }
            if ((members_data[i] < 1) || (members_data[i] > prunedCount)) {
              emlrtDynamicBoundsCheckR2012b(members_data[i], 1, prunedCount,
                                            &hd_emlrtBCI, (emlrtConstCTX)sp);
            }
            a21 += pruned_data[members_data[i] - 1].w;
            b_r1 = members_data[i];
            if ((b_r1 < 1) || (b_r1 > prunedCount)) {
              emlrtDynamicBoundsCheckR2012b(b_r1, 1, prunedCount, &mc_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            b_r1 = members_data[i];
            if ((b_r1 < 1) || (b_r1 > prunedCount)) {
              emlrtDynamicBoundsCheckR2012b(b_r1, 1, prunedCount, &nc_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            b_r1 = members_data[i];
            b_r2 = _mm_loadu_pd(&pruned_data[b_r1 - 1].m[0]);
            r4 = _mm_loadu_pd(&meanSum[0]);
            _mm_storeu_pd(
                &meanSum[0],
                _mm_add_pd(r4, _mm_mul_pd(_mm_set1_pd(pruned_data[b_r1 - 1].w),
                                          b_r2)));
            /*  gather label info */
            if (pruned_data[members_data[i] - 1].label[0] < minLabelT) {
              minLabelT = pruned_data[members_data[i] - 1].label[0];
            }
            if (pruned_data[members_data[i] - 1].label[1] > a22) {
              a22 = pruned_data[members_data[i] - 1].label[1];
            }
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b((emlrtConstCTX)sp);
            }
          }
          b_r2 = _mm_loadu_pd(&meanSum[0]);
          r3 = _mm_set1_pd(a21);
          _mm_storeu_pd(&meanSum[0], _mm_div_pd(b_r2, r3));
          Pi[0] = 0.0;
          Pi[1] = 0.0;
          Pi[2] = 0.0;
          Pi[3] = 0.0;
          r5 = _mm_loadu_pd(&meanSum[0]);
          r6 = _mm_set1_pd(0.0);
          for (i = 0; i < memberCount; i++) {
            __m128d r7;
            boolean_T b;
            if (i + 1 > members->size[1]) {
              emlrtDynamicBoundsCheckR2012b(i + 1, 1, members->size[1],
                                            &oc_emlrtBCI, (emlrtConstCTX)sp);
            }
            b = ((members_data[i] < 1) || (members_data[i] > prunedCount));
            if (b) {
              emlrtDynamicBoundsCheckR2012b(members_data[i], 1, prunedCount,
                                            &nd_emlrtBCI, (emlrtConstCTX)sp);
            }
            b_r2 = _mm_loadu_pd(&pruned_data[members_data[i] - 1].m[0]);
            _mm_storeu_pd(&diff[0], _mm_sub_pd(b_r2, r5));
            b_r1 = members_data[i];
            if ((b_r1 < 1) || (b_r1 > prunedCount)) {
              emlrtDynamicBoundsCheckR2012b(b_r1, 1, prunedCount, &pc_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            b_r2 = _mm_loadu_pd(&diff[0]);
            r4 = _mm_loadu_pd(&pruned_data[members_data[i] - 1].P[0]);
            _mm_storeu_pd(
                &b_pruned[0],
                _mm_add_pd(r4, _mm_add_pd(r6, _mm_mul_pd(b_r2, _mm_set1_pd(
                                                                   diff[0])))));
            b_r2 = _mm_loadu_pd(&diff[0]);
            r4 = _mm_loadu_pd(&pruned_data[members_data[i] - 1].P[2]);
            _mm_storeu_pd(
                &b_pruned[2],
                _mm_add_pd(r4, _mm_add_pd(r6, _mm_mul_pd(b_r2, _mm_set1_pd(
                                                                   diff[1])))));
            b_r2 = _mm_loadu_pd(&b_pruned[0]);
            r4 = _mm_loadu_pd(&Pi[0]);
            r7 = _mm_set1_pd(pruned_data[members_data[i] - 1].w);
            _mm_storeu_pd(&Pi[0], _mm_add_pd(r4, _mm_mul_pd(r7, b_r2)));
            b_r2 = _mm_loadu_pd(&b_pruned[2]);
            r4 = _mm_loadu_pd(&Pi[2]);
            _mm_storeu_pd(&Pi[2], _mm_add_pd(r4, _mm_mul_pd(r7, b_r2)));
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b((emlrtConstCTX)sp);
            }
          }
          b_r2 = _mm_loadu_pd(&Pi[0]);
          _mm_storeu_pd(&Pi[0], _mm_div_pd(b_r2, r3));
          b_r2 = _mm_loadu_pd(&Pi[2]);
          _mm_storeu_pd(&Pi[2], _mm_div_pd(b_r2, r3));
          mergedCount++;
          if (mergedCount > c_loop_ub) {
            emlrtDynamicBoundsCheckR2012b(mergedCount, 1, c_loop_ub,
                                          &qd_emlrtBCI, (emlrtConstCTX)sp);
          }
          merged_data[mergedCount - 1].m[0] = meanSum[0];
          if (mergedCount > c_loop_ub) {
            emlrtDynamicBoundsCheckR2012b(mergedCount, 1, c_loop_ub,
                                          &qd_emlrtBCI, (emlrtConstCTX)sp);
          }
          merged_data[mergedCount - 1].m[1] = meanSum[1];
          if (mergedCount > c_loop_ub) {
            emlrtDynamicBoundsCheckR2012b(mergedCount, 1, c_loop_ub,
                                          &uc_emlrtBCI, (emlrtConstCTX)sp);
          }
          merged_data[mergedCount - 1].P[0] = Pi[0];
          merged_data[mergedCount - 1].P[1] = Pi[1];
          merged_data[mergedCount - 1].P[2] = Pi[2];
          merged_data[mergedCount - 1].P[3] = Pi[3];
          if (mergedCount > c_loop_ub) {
            emlrtDynamicBoundsCheckR2012b(mergedCount, 1, c_loop_ub,
                                          &uc_emlrtBCI, (emlrtConstCTX)sp);
          }
          st.site = &wc_emlrtRSI;
          regularize_cov_local(&st, merged_data[mergedCount - 1].P);
          if (mergedCount > c_loop_ub) {
            emlrtDynamicBoundsCheckR2012b(mergedCount, 1, c_loop_ub,
                                          &id_emlrtBCI, (emlrtConstCTX)sp);
          }
          merged_data[mergedCount - 1].w = a21;
          if (mergedCount > mergedWeights->size[1]) {
            emlrtDynamicBoundsCheckR2012b(mergedCount, 1,
                                          mergedWeights->size[1], &jd_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          mergedWeights_data[mergedCount - 1] = a21;
          if ((!muDoubleScalarIsInf(minLabelT)) &&
              (!muDoubleScalarIsNaN(minLabelT))) {
            if (mergedCount > c_loop_ub) {
              emlrtDynamicBoundsCheckR2012b(mergedCount, 1, c_loop_ub,
                                            &kd_emlrtBCI, (emlrtConstCTX)sp);
            }
            merged_data[mergedCount - 1].label[0] = minLabelT;
            if (mergedCount > c_loop_ub) {
              emlrtDynamicBoundsCheckR2012b(mergedCount, 1, c_loop_ub,
                                            &kd_emlrtBCI, (emlrtConstCTX)sp);
            }
            merged_data[mergedCount - 1].label[1] = a22 + 1.0;
          } else {
            if (mergedCount > c_loop_ub) {
              emlrtDynamicBoundsCheckR2012b(mergedCount, 1, c_loop_ub,
                                            &pd_emlrtBCI, (emlrtConstCTX)sp);
            }
            merged_data[mergedCount - 1].label[0] = 0.0;
            if (mergedCount > c_loop_ub) {
              emlrtDynamicBoundsCheckR2012b(mergedCount, 1, c_loop_ub,
                                            &pd_emlrtBCI, (emlrtConstCTX)sp);
            }
            merged_data[mergedCount - 1].label[1] = 0.0;
          }
        }
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtConstCTX)sp);
        }
      }
      if (mergedCount == 0) {
        mapOut->size[0] = 1;
        mapOut->size[1] = 0;
      } else {
        a21 = muDoubleScalarMin(params_max_components, mergedCount);
        if (mergedCount <= a21) {
          st.site = &vc_emlrtRSI;
          if (mergedCount > r->size[1]) {
            emlrtDynamicBoundsCheckR2012b(mergedCount, 1, r->size[1],
                                          &e_emlrtBCI, &st);
          }
          b_r1 = mapOut->size[0] * mapOut->size[1];
          mapOut->size[0] = 1;
          mapOut->size[1] = mergedCount;
          emxEnsureCapacity_struct0_T(sp, mapOut, b_r1, &w_emlrtRTEI);
          pruned_data = mapOut->data;
          for (i = 0; i < mergedCount; i++) {
            pruned_data[i] = merged_data[i];
          }
        } else {
          if (mergedCount > mergedWeights->size[1]) {
            emlrtDynamicBoundsCheckR2012b(mergedCount, 1,
                                          mergedWeights->size[1], &qc_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          st.site = &uc_emlrtRSI;
          b_r1 = weights->size[0] * weights->size[1];
          weights->size[0] = 1;
          weights->size[1] = mergedCount;
          emxEnsureCapacity_real_T(&st, weights, b_r1, &v_emlrtRTEI);
          weights_data = weights->data;
          for (i = 0; i < mergedCount; i++) {
            weights_data[i] = mergedWeights_data[i];
          }
          b_st.site = &ed_emlrtRSI;
          sort(&b_st, weights, members);
          members_data = members->data;
          b_r1 = weights->size[0] * weights->size[1];
          weights->size[0] = 1;
          r2 = members->size[1];
          weights->size[1] = members->size[1];
          emxEnsureCapacity_real_T(&st, weights, b_r1, &s_emlrtRTEI);
          weights_data = weights->data;
          for (i = 0; i < r2; i++) {
            weights_data[i] = members_data[i];
          }
          st.site = &tc_emlrtRSI;
          repmat(&st, a21, r);
          r1 = r->data;
          b_r1 = mapOut->size[0] * mapOut->size[1];
          mapOut->size[0] = 1;
          loop_ub = r->size[1];
          mapOut->size[1] = r->size[1];
          emxEnsureCapacity_struct0_T(sp, mapOut, b_r1, &y_emlrtRTEI);
          pruned_data = mapOut->data;
          for (i = 0; i < loop_ub; i++) {
            pruned_data[i] = r1[i];
          }
          b_r1 = (int32_T)a21;
          emlrtForLoopVectorCheckR2021a(1.0, 1.0, a21, mxDOUBLE_CLASS,
                                        (int32_T)a21, &d_emlrtRTEI,
                                        (emlrtConstCTX)sp);
          for (i = 0; i < b_r1; i++) {
            if (((int32_T)((uint32_T)i + 1U) < 1) ||
                ((int32_T)((uint32_T)i + 1U) > r2)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)i + 1U), 1, r2,
                                            &fd_emlrtBCI, (emlrtConstCTX)sp);
            }
            loop_ub = (int32_T)weights_data[i];
            if ((loop_ub < 1) || (loop_ub > c_loop_ub)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, c_loop_ub, &ed_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            if (((int32_T)((uint32_T)i + 1U) < 1) ||
                ((int32_T)((uint32_T)i + 1U) > mapOut->size[1])) {
              emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)i + 1U), 1,
                                            mapOut->size[1], &gd_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            pruned_data[i] = merged_data[loop_ub - 1];
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b((emlrtConstCTX)sp);
            }
          }
        }
      }
    }
  }
  emxFree_struct0_T(sp, &r);
  emxFree_int32_T(sp, &members);
  emxFree_real_T(sp, &mergedWeights);
  emxFree_struct0_T(sp, &merged);
  emxFree_real_T(sp, &weights);
  emxFree_struct0_T(sp, &pruned);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

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

void slam_step_codegen(const emlrtStack *sp, const real_T xPrev[3],
                       const real_T PPrev[9], const real_T odom[2],
                       const real_T curMea_data[], const int32_T curMea_size[2],
                       const struct0_T mapIn_data[],
                       const int32_T mapIn_size[2], const struct1_T *params,
                       real_T T, boolean_T isLastStep, real_T xk[3],
                       real_T Pk[9], emxArray_struct0_T *mapOut)
{
  emlrtStack st;
  emxArray_struct0_T *b_mapTmp;
  emxArray_struct0_T *mapTmp;
  struct0_T a__1_data[512];
  struct0_T visMap_data[512];
  struct0_T *mapOut_data;
  struct0_T *mapTmp_data;
  real_T Rstack_data[192];
  real_T Z_data[96];
  real_T PBase[9];
  int32_T Rstack_size[3];
  int32_T Z_size[2];
  int32_T a__1_size[2];
  int32_T birthIdx_size[2];
  int32_T visMap_size[2];
  int32_T i;
  int32_T iter;
  boolean_T birthIdx_data[48];
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  Single-step core update packaged for MATLAB Coder / MEX. */
  pose_predict_local(xPrev, PPrev, odom, T, params->Qu, xk, PBase);
  st.site = &b_emlrtRSI;
  preprocess_local(&st, curMea_data, curMea_size, params->R, Z_data, Z_size,
                   Rstack_data, Rstack_size);
  memcpy(&Pk[0], &PBase[0], 9U * sizeof(real_T));
  i = (int32_T)params->iter_max;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, params->iter_max, mxDOUBLE_CLASS,
                                (int32_T)params->iter_max, &emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (iter = 0; iter < i; iter++) {
    st.site = &c_emlrtRSI;
    split_map_by_fov_local(&st, xk, mapIn_data, mapIn_size, params->fov_range,
                           params->fov_angle, a__1_data, a__1_size, visMap_data,
                           visMap_size);
    memcpy(&Pk[0], &PBase[0], 9U * sizeof(real_T));
    st.site = &d_emlrtRSI;
    pose_update_mm_local(&st, xk, Pk, visMap_data, visMap_size, Z_data, Z_size,
                         params->P_D, params->clutter_rate, params->iter_max,
                         params->PHD_det_keep, params->PHD_miss_keep,
                         params->model, Rstack_data, Rstack_size,
                         (real_T)iter + 1.0);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  st.site = &e_emlrtRSI;
  split_map_by_fov_local(&st, xk, mapIn_data, mapIn_size, params->fov_range,
                         params->fov_angle, a__1_data, a__1_size, visMap_data,
                         visMap_size);
  emxInit_struct0_T(sp, &mapTmp, &h_emlrtRTEI);
  st.site = &f_emlrtRSI;
  map_update_local(&st, xk, Pk, a__1_data, a__1_size, visMap_data, visMap_size,
                   Z_data, Z_size, params->P_D, params->clutter_rate,
                   params->map_detection_add_threshold,
                   params->map_miss_prune_threshold, params->label_weight_gain,
                   Rstack_data, Rstack_size, mapTmp, birthIdx_data,
                   birthIdx_size);
  emxInit_struct0_T(sp, &b_mapTmp, &g_emlrtRTEI);
  st.site = &g_emlrtRSI;
  tuning_local(&st, mapTmp, params->prune_threshold, params->max_components,
               params->merge_threshold, b_mapTmp);
  mapTmp_data = b_mapTmp->data;
  emxFree_struct0_T(sp, &mapTmp);
  if (isLastStep) {
    int32_T loop_ub;
    i = mapOut->size[0] * mapOut->size[1];
    mapOut->size[0] = 1;
    loop_ub = b_mapTmp->size[1];
    mapOut->size[1] = b_mapTmp->size[1];
    emxEnsureCapacity_struct0_T(sp, mapOut, i, &f_emlrtRTEI);
    mapOut_data = mapOut->data;
    for (iter = 0; iter < loop_ub; iter++) {
      mapOut_data[iter] = mapTmp_data[iter];
    }
  } else {
    st.site = &h_emlrtRSI;
    birth_local(&st, xk, Pk, b_mapTmp, Z_data, Z_size, params->birth_intensity,
                Rstack_data, Rstack_size, birthIdx_data, birthIdx_size, T,
                mapOut);
  }
  emxFree_struct0_T(sp, &b_mapTmp);
  st.site = &i_emlrtRSI;
  b_regularize_cov_local(&st, Pk);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (slam_step_codegen.c) */
