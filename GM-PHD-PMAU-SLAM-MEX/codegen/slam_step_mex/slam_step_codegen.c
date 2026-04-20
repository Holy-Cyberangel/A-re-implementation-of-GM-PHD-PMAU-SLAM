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
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    11,                  /* lineNo */
    "slam_step_codegen", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    12,                  /* lineNo */
    "slam_step_codegen", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    15,                  /* lineNo */
    "slam_step_codegen", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    16,                  /* lineNo */
    "slam_step_codegen", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    17,                  /* lineNo */
    "slam_step_codegen", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    22,                  /* lineNo */
    "slam_step_codegen", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    26,                  /* lineNo */
    "slam_step_codegen", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo t_emlrtRSI = {
    73,                       /* lineNo */
    "split_map_by_fov_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    74,                       /* lineNo */
    "split_map_by_fov_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo w_emlrtRSI = {
    95,                       /* lineNo */
    "split_map_by_fov_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo x_emlrtRSI = {
    96,                       /* lineNo */
    "split_map_by_fov_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = {
    135,                    /* lineNo */
    "pose_update_mm_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI = {
    138,                    /* lineNo */
    "pose_update_mm_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    186,                    /* lineNo */
    "pose_update_mm_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo db_emlrtRSI = {
    190,                    /* lineNo */
    "pose_update_mm_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    206,                    /* lineNo */
    "pose_update_mm_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    20,                /* lineNo */
    "mrdivide_helper", /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_helper.m" /* pathName
                                                                           */
};

static emlrtRSInfo kb_emlrtRSI = {
    434,                /* lineNo */
    "likelihood_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI = {
    435,                /* lineNo */
    "likelihood_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo gc_emlrtRSI = {
    216,                /* lineNo */
    "map_update_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo hc_emlrtRSI = {
    224,                /* lineNo */
    "map_update_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo ic_emlrtRSI = {
    243,                /* lineNo */
    "map_update_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo jc_emlrtRSI = {
    253,                /* lineNo */
    "map_update_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo kc_emlrtRSI = {
    266,                /* lineNo */
    "map_update_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo lc_emlrtRSI = {
    270,                /* lineNo */
    "map_update_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo mc_emlrtRSI = {
    277,                /* lineNo */
    "map_update_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo nc_emlrtRSI = {
    376,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo oc_emlrtRSI = {
    375,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo pc_emlrtRSI = {
    371,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo qc_emlrtRSI = {
    359,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI = {
    332,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    324,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI = {
    310,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    307,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo vc_emlrtRSI = {
    293,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo wc_emlrtRSI = {
    287,            /* lineNo */
    "tuning_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo xc_emlrtRSI = {
    37,                                                      /* lineNo */
    "sort",                                                  /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" /* pathName */
};

static emlrtRSInfo vd_emlrtRSI = {
    20,                                                      /* lineNo */
    "mldivide",                                              /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pathName */
};

static emlrtRSInfo wd_emlrtRSI = {
    42,                                                      /* lineNo */
    "mldiv",                                                 /* fcnName */
    "D:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pathName */
};

static emlrtRSInfo xd_emlrtRSI = {
    385,           /* lineNo */
    "birth_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRSInfo yd_emlrtRSI = {
    405,           /* lineNo */
    "birth_local", /* fcnName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    10,                  /* lineNo */
    16,                  /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtECInfo emlrtECI = {
    -1,                 /* nDims */
    62,                 /* lineNo */
    5,                  /* colNo */
    "preprocess_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    -1,                 /* nDims */
    61,                 /* lineNo */
    5,                  /* colNo */
    "preprocess_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    65,                 /* lineNo */
    47,                 /* colNo */
    "theta",            /* aName */
    "preprocess_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    65,                 /* lineNo */
    32,                 /* colNo */
    "r",                /* aName */
    "preprocess_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    65,                 /* lineNo */
    24,                 /* colNo */
    "theta",            /* aName */
    "preprocess_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    67,                 /* lineNo */
    20,                 /* colNo */
    "Rstack",           /* aName */
    "preprocess_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    412,                /* lineNo */
    26,                 /* colNo */
    "mapIn",            /* aName */
    "resize_map_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    82,                       /* lineNo */
    20,                       /* colNo */
    "mapIn",                  /* aName */
    "split_map_by_fov_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    83,                       /* lineNo */
    20,                       /* colNo */
    "mapIn",                  /* aName */
    "split_map_by_fov_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    91,                       /* lineNo */
    40,                       /* colNo */
    "mapIn",                  /* aName */
    "split_map_by_fov_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    91,                       /* lineNo */
    21,                       /* colNo */
    "keepMap",                /* aName */
    "split_map_by_fov_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    88,                       /* lineNo */
    38,                       /* colNo */
    "mapIn",                  /* aName */
    "split_map_by_fov_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    88,                       /* lineNo */
    20,                       /* colNo */
    "visMap",                 /* aName */
    "split_map_by_fov_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    134,                    /* lineNo */
    45,                     /* colNo */
    "Rstack",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    136,                    /* lineNo */
    22,                     /* colNo */
    "Z",                    /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    138,                    /* lineNo */
    52,                     /* colNo */
    "Z",                    /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    137,                    /* lineNo */
    20,                     /* colNo */
    "xDet",                 /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    147,                    /* lineNo */
    54,                     /* colNo */
    "xDet",                 /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    185,                    /* lineNo */
    45,                     /* colNo */
    "Rstack",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    187,                    /* lineNo */
    22,                     /* colNo */
    "Z",                    /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    190,                    /* lineNo */
    52,                     /* colNo */
    "Z",                    /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    188,                    /* lineNo */
    24,                     /* colNo */
    "detState",             /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    199,                    /* lineNo */
    42,                     /* colNo */
    "detState",             /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    200,                    /* lineNo */
    56,                     /* colNo */
    "detCov",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    13,                                                    /* lineNo */
    9,                                                     /* colNo */
    "sqrt",                                                /* fName */
    "D:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" /* pName */
};

static emlrtBCInfo w_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    189,                    /* lineNo */
    24,                     /* colNo */
    "detCov",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    118,                    /* lineNo */
    20,                     /* colNo */
    "mapIn",                /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    119,                    /* lineNo */
    20,                     /* colNo */
    "mapIn",                /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    167,                    /* lineNo */
    20,                     /* colNo */
    "mapIn",                /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    168,                    /* lineNo */
    20,                     /* colNo */
    "mapIn",                /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    124,                    /* lineNo */
    23,                     /* colNo */
    "mapIn",                /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    173,                    /* lineNo */
    23,                     /* colNo */
    "mapIn",                /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    144,                    /* lineNo */
    32,                     /* colNo */
    "detRaw",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    196,                    /* lineNo */
    32,                     /* colNo */
    "detRaw",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    138,                    /* lineNo */
    72,                     /* colNo */
    "mapIn",                /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    138,                    /* lineNo */
    20,                     /* colNo */
    "detRaw",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    139,                    /* lineNo */
    36,                     /* colNo */
    "detRaw",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    190,                    /* lineNo */
    72,                     /* colNo */
    "mapIn",                /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    190,                    /* lineNo */
    20,                     /* colNo */
    "detRaw",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    191,                    /* lineNo */
    36,                     /* colNo */
    "detRaw",               /* aName */
    "pose_update_mm_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    232,                /* lineNo */
    40,                 /* colNo */
    "Z",                /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    235,                /* lineNo */
    47,                 /* colNo */
    "RstackLocal",      /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    242,                /* lineNo */
    23,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    235,                /* lineNo */
    20,                 /* colNo */
    "Rworld",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    242,                /* lineNo */
    41,                 /* colNo */
    "Rworld",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    243,                /* lineNo */
    51,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    243,                /* lineNo */
    64,                 /* colNo */
    "Zmap",             /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    265,                /* lineNo */
    27,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    265,                /* lineNo */
    45,                 /* colNo */
    "Rworld",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    266,                /* lineNo */
    27,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    267,                /* lineNo */
    40,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    267,                /* lineNo */
    29,                 /* colNo */
    "Zmap",             /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    253,                /* lineNo */
    61,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    253,                /* lineNo */
    20,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    220,                /* lineNo */
    36,                 /* colNo */
    "keepMap",          /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    220,                /* lineNo */
    16,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    233,                /* lineNo */
    19,                 /* colNo */
    "Z",                /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    234,                /* lineNo */
    19,                 /* colNo */
    "Z",                /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    249,                /* lineNo */
    23,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    259,                /* lineNo */
    19,                 /* colNo */
    "detDen",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    263,                /* lineNo */
    25,                 /* colNo */
    "rawLike",          /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    263,                /* lineNo */
    27,                 /* colNo */
    "rawLike",          /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    263,                /* lineNo */
    39,                 /* colNo */
    "detDen",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    254,                /* lineNo */
    20,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    243,                /* lineNo */
    92,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    243,                /* lineNo */
    21,                 /* colNo */
    "rawLike",          /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    243,                /* lineNo */
    23,                 /* colNo */
    "rawLike",          /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    244,                /* lineNo */
    32,                 /* colNo */
    "detDen",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    244,                /* lineNo */
    45,                 /* colNo */
    "rawLike",          /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    244,                /* lineNo */
    47,                 /* colNo */
    "rawLike",          /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    244,                /* lineNo */
    20,                 /* colNo */
    "detDen",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    270,                /* lineNo */
    24,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    271,                /* lineNo */
    24,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    272,                /* lineNo */
    26,                 /* colNo */
    "birthIdx",         /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = {
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

static emlrtBCInfo wc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    269,                /* lineNo */
    17,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    269,                /* lineNo */
    38,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    252,                /* lineNo */
    13,                 /* colNo */
    "mapOut",           /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    252,                /* lineNo */
    34,                 /* colNo */
    "inMap",            /* aName */
    "map_update_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    301,            /* lineNo */
    23,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    315,            /* lineNo */
    21,             /* colNo */
    "order",        /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    327,            /* lineNo */
    25,             /* colNo */
    "order",        /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    343,            /* lineNo */
    28,             /* colNo */
    "members",      /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    345,            /* lineNo */
    40,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    345,            /* lineNo */
    57,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    351,            /* lineNo */
    28,             /* colNo */
    "members",      /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    353,            /* lineNo */
    52,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    375,             /* lineNo */
    39,              /* colNo */
    "mergedWeights", /* aName */
    "tuning_local",  /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = {
    377,            /* lineNo */
    13,             /* colNo */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtBCInfo kd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    293,            /* lineNo */
    64,             /* colNo */
    "mapIn",        /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    293,            /* lineNo */
    20,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    324,            /* lineNo */
    42,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    359,            /* lineNo */
    16,             /* colNo */
    "merged",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    290,            /* lineNo */
    18,             /* colNo */
    "mapIn",        /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    305,            /* lineNo */
    29,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    305,            /* lineNo */
    17,             /* colNo */
    "weights",      /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    294,            /* lineNo */
    43,             /* colNo */
    "mapIn",        /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    294,            /* lineNo */
    20,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    316,            /* lineNo */
    17,             /* colNo */
    "used",         /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    319,            /* lineNo */
    14,             /* colNo */
    "used",         /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    328,            /* lineNo */
    21,             /* colNo */
    "used",         /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    378,            /* lineNo */
    28,             /* colNo */
    "merged",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    378,            /* lineNo */
    34,             /* colNo */
    "order",        /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    378,            /* lineNo */
    16,             /* colNo */
    "mapOut",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    344,            /* lineNo */
    44,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    360,            /* lineNo */
    16,             /* colNo */
    "merged",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    361,             /* lineNo */
    23,              /* colNo */
    "mergedWeights", /* aName */
    "tuning_local",  /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    334,            /* lineNo */
    22,             /* colNo */
    "used",         /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    336,            /* lineNo */
    25,             /* colNo */
    "members",      /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    352,            /* lineNo */
    20,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    331,            /* lineNo */
    20,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    358,            /* lineNo */
    9,              /* colNo */
    "merged",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    292,            /* lineNo */
    13,             /* colNo */
    "pruned",       /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo je_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    292,            /* lineNo */
    37,             /* colNo */
    "mapIn",        /* aName */
    "tuning_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ke_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    398,           /* lineNo */
    49,            /* colNo */
    "Z",           /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo le_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    401,           /* lineNo */
    52,            /* colNo */
    "RstackLocal", /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo me_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    401,           /* lineNo */
    16,            /* colNo */
    "mapOut",      /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo ne_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    389,           /* lineNo */
    34,            /* colNo */
    "mapIn",       /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo oe_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    389,           /* lineNo */
    16,            /* colNo */
    "mapOut",      /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo pe_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    394,           /* lineNo */
    22,            /* colNo */
    "birthIdx",    /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo qe_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    399,           /* lineNo */
    19,            /* colNo */
    "Z",           /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo re_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    400,           /* lineNo */
    19,            /* colNo */
    "Z",           /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo se_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    402,           /* lineNo */
    16,            /* colNo */
    "mapOut",      /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo te_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    398,           /* lineNo */
    9,             /* colNo */
    "mapOut",      /* aName */
    "birth_local", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtRTEInfo f_emlrtRTEI = {
    20,                  /* lineNo */
    9,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    16,                  /* lineNo */
    6,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    1,                   /* lineNo */
    29,                  /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    412,                 /* lineNo */
    9,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    95,                  /* lineNo */
    15,                  /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    216,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    224,                 /* lineNo */
    9,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    239,                 /* lineNo */
    15,                  /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    277,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    239,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    277,                 /* lineNo */
    14,                  /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    287,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    301,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = {
    303,                 /* lineNo */
    15,                  /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = {
    38,                                                      /* lineNo */
    5,                                                       /* colNo */
    "sort",                                                  /* fName */
    "D:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    310,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo w_emlrtRTEI = {
    311,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = {
    37,                                                      /* lineNo */
    6,                                                       /* colNo */
    "sort",                                                  /* fName */
    "D:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = {
    371,                 /* lineNo */
    9,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    321,                 /* lineNo */
    9,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    376,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    303,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    287,                 /* lineNo */
    14,                  /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    405,                 /* lineNo */
    5,                   /* colNo */
    "slam_step_codegen", /* fName */
    "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
    "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
    "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m" /* pName */
};

/* Function Declarations */
static void b_regularize_cov_local(const emlrtStack *sp, real_T P[9]);

static void
birth_local(const emlrtStack *sp, const real_T x[3], const real_T P[9],
            const emxArray_struct0_T *mapIn, const real_T Z_data[],
            const int32_T Z_size[2], real_T params_birth_intensity,
            const real_T RstackLocal_data[], const int32_T RstackLocal_size[3],
            const boolean_T birthIdx_data[], const int32_T birthIdx_size[2],
            emxArray_struct0_T *mapOut);

static void map_update_local(
    const emlrtStack *sp, const real_T x[3], const real_T P[9],
    const struct0_T keepMap_data[], const int32_T keepMap_size[2],
    const struct0_T inMap_data[], const int32_T inMap_size[2],
    const real_T Z_data[], const int32_T Z_size[2], real_T params_P_D,
    real_T params_clutter_rate, real_T c_params_map_detection_add_thre,
    real_T params_map_miss_prune_threshold, const real_T RstackLocal_data[],
    const int32_T RstackLocal_size[3], emxArray_struct0_T *mapOut,
    boolean_T birthIdx_data[], int32_T birthIdx_size[2]);

static void pose_predict_local(const real_T x[3], const real_T P[9],
                               const real_T u[2], real_T dt, const real_T Qu[4],
                               real_T xPred[3], real_T PPred[9]);

static void
pose_update_mm_local(const emlrtStack *sp, const real_T xBase[3],
                     const real_T PBase[9], const struct0_T mapIn_data[],
                     const int32_T mapIn_size[2], const real_T Z_data[],
                     const int32_T Z_size[2], real_T params_P_D,
                     real_T params_clutter_rate, real_T params_iter_max,
                     real_T params_PHD_det_keep, real_T params_PHD_miss_keep,
                     const real_T Rstack_data[], const int32_T Rstack_size[3],
                     real_T iterCnt, real_T xOut[3], real_T POut[9]);

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
            emxArray_struct0_T *mapOut)
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
  st.site = &xd_emlrtRSI;
  repmat(&st, muDoubleScalarMax(1.0, mapIn->size[1] + Z_size[1]), mapOut);
  mapOut_data = mapOut->data;
  i = mapIn->size[1];
  for (b_i = 0; b_i < i; b_i++) {
    if (b_i + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &ne_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (b_i + 1 > mapOut->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, mapOut->size[1], &oe_emlrtBCI,
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
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, birthIdx_size[1], &pe_emlrtBCI,
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
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &ke_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (outCount > mapOut->size[1]) {
        emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                      &te_emlrtBCI, (emlrtConstCTX)sp);
      }
      Jx_tmp = Z_data[2 * j];
      d = Z_data[2 * j + 1];
      d1 = S_tmp * d;
      mapOut_data[outCount - 1].m[0] = x[0] + (b_S_tmp * Jx_tmp + d1);
      if (outCount > mapOut->size[1]) {
        emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                      &te_emlrtBCI, (emlrtConstCTX)sp);
      }
      d *= b_S_tmp;
      mapOut_data[outCount - 1].m[1] = x[1] + (-S_tmp * Jx_tmp + d);
      Jx[0] = 1.0;
      Jx[2] = 0.0;
      if (j + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &qe_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Jx[4] = Jx_tmp * S_tmp - d;
      Jx[1] = 0.0;
      Jx[3] = 1.0;
      if (j + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &re_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Jx[5] = Jx_tmp * b_S_tmp + d1;
      if (j + 1 > RstackLocal_size[2]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, RstackLocal_size[2],
                                      &le_emlrtBCI, (emlrtConstCTX)sp);
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
                                      &me_emlrtBCI, (emlrtConstCTX)sp);
      }
      r = _mm_loadu_pd(&c_rot[0]);
      r1 = _mm_loadu_pd(&b_rot[0]);
      _mm_storeu_pd(&mapOut_data[outCount - 1].P[0], _mm_add_pd(r, r1));
      r = _mm_loadu_pd(&c_rot[2]);
      r1 = _mm_loadu_pd(&b_rot[2]);
      _mm_storeu_pd(&mapOut_data[outCount - 1].P[2], _mm_add_pd(r, r1));
      if (outCount > mapOut->size[1]) {
        emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                      &se_emlrtBCI, (emlrtConstCTX)sp);
      }
      mapOut_data[outCount - 1].w = params_birth_intensity;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  st.site = &yd_emlrtRSI;
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
    emxEnsureCapacity_struct0_T(&st, mapOut, i, &eb_emlrtRTEI);
  }
}

static void map_update_local(
    const emlrtStack *sp, const real_T x[3], const real_T P[9],
    const struct0_T keepMap_data[], const int32_T keepMap_size[2],
    const struct0_T inMap_data[], const int32_T inMap_size[2],
    const real_T Z_data[], const int32_T Z_size[2], real_T params_P_D,
    real_T params_clutter_rate, real_T c_params_map_detection_add_thre,
    real_T params_map_miss_prune_threshold, const real_T RstackLocal_data[],
    const int32_T RstackLocal_size[3], emxArray_struct0_T *mapOut,
    boolean_T birthIdx_data[], int32_T birthIdx_size[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_real_T *rawLike;
  emxArray_struct0_T *b_mapOut;
  struct0_T *b_mapOut_data;
  struct0_T *mapOut_data;
  real_T Rworld_data[128];
  real_T Zmap_data[64];
  real_T Jx[6];
  real_T b_Jx[6];
  real_T K[4];
  real_T b_rot[4];
  real_T rot[4];
  real_T nu[2];
  real_T *rawLike_data;
  int32_T i;
  int32_T j;
  int32_T loop_ub;
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
  birthIdx_size[0] = 1;
  loop_ub = Z_size[1];
  birthIdx_size[1] = Z_size[1];
  for (i = 0; i < loop_ub; i++) {
    birthIdx_data[i] = true;
  }
  emxInit_struct0_T(sp, &b_mapOut, &q_emlrtRTEI);
  st.site = &gc_emlrtRSI;
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
  r1 = keepMap_size[1];
  for (i = 0; i < r1; i++) {
    if (i + 1 > r1) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, r1, &bc_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (i + 1 > mapOut->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, mapOut->size[1], &cc_emlrtBCI,
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
    st.site = &hc_emlrtRSI;
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
    real_T detDen_data[32];
    real_T Jx_tmp;
    real_T a21;
    real_T a22;
    real_T missW;
    real_T w;
    int32_T b_i;
    w = muDoubleScalarSin(-x[2]);
    a21 = muDoubleScalarCos(-x[2]);
    rot[0] = a21;
    rot[2] = w;
    rot[1] = -w;
    rot[3] = a21;
    if (Z_size[1] - 1 >= 0) {
      Jx[0] = 1.0;
      Jx[2] = 0.0;
      Jx[1] = 0.0;
      Jx[3] = 1.0;
    }
    for (j = 0; j < loop_ub; j++) {
      if (j + 1 > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, loop_ub, &mb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Jx_tmp = Z_data[2 * j];
      r1 = 2 * j + 1;
      missW = Z_data[r1];
      a22 = w * missW;
      Zmap_data[2 * j] = x[0] + (a21 * Jx_tmp + a22);
      missW *= a21;
      Zmap_data[r1] = x[1] + (-w * Jx_tmp + missW);
      if (j + 1 > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, loop_ub, &dc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Jx[4] = Jx_tmp * w - missW;
      if (j + 1 > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, loop_ub, &ec_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Jx[5] = Jx_tmp * a21 + a22;
      if (j + 1 > RstackLocal_size[2]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, RstackLocal_size[2],
                                      &nb_emlrtBCI, (emlrtConstCTX)sp);
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
      b_r2 = _mm_set1_pd(a21);
      _mm_storeu_pd(&b_rot[0], _mm_add_pd(b_r1, _mm_mul_pd(r, b_r2)));
      r = _mm_loadu_pd(&K[2]);
      b_r1 = _mm_loadu_pd(&b_rot[0]);
      _mm_storeu_pd(&b_rot[0], _mm_add_pd(b_r1, _mm_mul_pd(r, _mm_set1_pd(w))));
      r = _mm_loadu_pd(&K[0]);
      b_r1 = _mm_loadu_pd(&b_rot[2]);
      _mm_storeu_pd(&b_rot[2],
                    _mm_add_pd(b_r1, _mm_mul_pd(r, _mm_set1_pd(-w))));
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
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, loop_ub, &pb_emlrtBCI,
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
    for (i = 0; i < loop_ub; i++) {
      detDen_data[i] = params_clutter_rate;
    }
    b_i = inMap_size[1];
    emxInit_real_T(sp, &rawLike, 2, &p_emlrtRTEI);
    r1 = rawLike->size[0] * rawLike->size[1];
    rawLike->size[0] = inMap_size[1];
    rawLike->size[1] = Z_size[1];
    emxEnsureCapacity_real_T(sp, rawLike, r1, &n_emlrtRTEI);
    rawLike_data = rawLike->data;
    for (i = 0; i < b_i; i++) {
      for (j = 0; j < loop_ub; j++) {
        real_T Y[2];
        if (i + 1 > b_i) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &ob_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (j + 1 > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, loop_ub, &qb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        st.site = &ic_emlrtRSI;
        if (i + 1 > b_i) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &rb_emlrtBCI, &st);
        }
        if (j + 1 > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, loop_ub, &sb_emlrtBCI, &st);
        }
        nu[0] = Zmap_data[2 * j] - inMap_data[i].m[0];
        r = _mm_loadu_pd(&Rworld_data[4 * j]);
        _mm_storeu_pd(&rot[0],
                      _mm_add_pd(_mm_loadu_pd(&inMap_data[i].P[0]), r));
        nu[1] = Zmap_data[2 * j + 1] - inMap_data[i].m[1];
        r = _mm_loadu_pd(&Rworld_data[4 * j + 2]);
        _mm_storeu_pd(&rot[2],
                      _mm_add_pd(_mm_loadu_pd(&inMap_data[i].P[2]), r));
        b_st.site = &kb_emlrtRSI;
        regularize_cov_local(&b_st, rot);
        b_st.site = &lb_emlrtRSI;
        c_st.site = &fb_emlrtRSI;
        b_mrdiv(&c_st, nu, rot, Y);
        b_st.site = &lb_emlrtRSI;
        missW = det(rot);
        if (missW < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &b_st, &c_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        missW = muDoubleScalarSqrt(missW);
        if (i + 1 > b_i) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &lc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (i + 1 > rawLike->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, rawLike->size[0],
                                        &mc_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (j + 1 > rawLike->size[1]) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, rawLike->size[1],
                                        &nc_emlrtBCI, (emlrtConstCTX)sp);
        }
        rawLike_data[i + rawLike->size[0] * j] =
            1.0 / (6.2831853071795862 * missW) *
            muDoubleScalarExp(-0.5 * Y[0] * nu[0] + -0.5 * Y[1] * nu[1]) *
            params_P_D * inMap_data[i].w;
        if (j + 1 > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, loop_ub, &oc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (i + 1 > rawLike->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, rawLike->size[0],
                                        &pc_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (j + 1 > rawLike->size[1]) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, rawLike->size[1],
                                        &qc_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (j + 1 > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, loop_ub, &rc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        detDen_data[j] += rawLike_data[i + rawLike->size[0] * j];
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtConstCTX)sp);
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    for (i = 0; i < b_i; i++) {
      if (i + 1 > b_i) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &fc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      missW = inMap_data[i].w * (1.0 - params_P_D);
      if (missW > params_map_miss_prune_threshold) {
        outCount++;
        if ((outCount < 1) || (outCount > mapOut->size[1])) {
          emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                        &yc_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (i + 1 > b_i) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &ad_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        b_mapOut_data[outCount - 1].m[0] = inMap_data[i].m[0];
        if (outCount > mapOut->size[1]) {
          emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                        &yc_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (i + 1 > b_i) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &ad_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        b_mapOut_data[outCount - 1].m[1] = inMap_data[i].m[1];
        if (i + 1 > b_i) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &yb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (outCount > mapOut->size[1]) {
          emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                        &ac_emlrtBCI, (emlrtConstCTX)sp);
        }
        b_mapOut_data[outCount - 1].P[0] = inMap_data[i].P[0];
        b_mapOut_data[outCount - 1].P[1] = inMap_data[i].P[1];
        b_mapOut_data[outCount - 1].P[2] = inMap_data[i].P[2];
        b_mapOut_data[outCount - 1].P[3] = inMap_data[i].P[3];
        if (outCount > mapOut->size[1]) {
          emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                        &ac_emlrtBCI, (emlrtConstCTX)sp);
        }
        st.site = &jc_emlrtRSI;
        regularize_cov_local(&st, b_mapOut_data[outCount - 1].P);
        if (outCount > mapOut->size[1]) {
          emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                        &kc_emlrtBCI, (emlrtConstCTX)sp);
        }
        b_mapOut_data[outCount - 1].w = missW;
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    for (i = 0; i < loop_ub; i++) {
      if (i + 1 > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, loop_ub, &gc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      missW = detDen_data[i];
      if (!(missW <= 0.0)) {
        for (j = 0; j < b_i; j++) {
          if (j + 1 > rawLike->size[0]) {
            emlrtDynamicBoundsCheckR2012b(j + 1, 1, rawLike->size[0],
                                          &hc_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (i + 1 > rawLike->size[1]) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, rawLike->size[1],
                                          &ic_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (i + 1 > loop_ub) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, loop_ub, &jc_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          w = rawLike_data[j + rawLike->size[0] * i] / missW;
          if (w > c_params_map_detection_add_thre) {
            int32_T i1;
            if (j + 1 > b_i) {
              emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_i, &tb_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            if (i + 1 > loop_ub) {
              emlrtDynamicBoundsCheckR2012b(i + 1, 1, loop_ub, &ub_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            r = _mm_loadu_pd(&Rworld_data[4 * i]);
            _mm_storeu_pd(&rot[0],
                          _mm_add_pd(_mm_loadu_pd(&inMap_data[j].P[0]), r));
            r = _mm_loadu_pd(&Rworld_data[4 * i + 2]);
            _mm_storeu_pd(&rot[2],
                          _mm_add_pd(_mm_loadu_pd(&inMap_data[j].P[2]), r));
            st.site = &kc_emlrtRSI;
            if (j + 1 > b_i) {
              emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_i, &vb_emlrtBCI, &st);
            }
            b_st.site = &fb_emlrtRSI;
            c_st.site = &gb_emlrtRSI;
            d_st.site = &hb_emlrtRSI;
            if (muDoubleScalarAbs(rot[1]) > muDoubleScalarAbs(rot[0])) {
              r1 = 1;
              r2 = 0;
            } else {
              r1 = 0;
              r2 = 1;
            }
            a21 = rot[r2] / rot[r1];
            Jx_tmp = rot[r1 + 2];
            a22 = rot[r2 + 2] - a21 * Jx_tmp;
            if ((a22 == 0.0) || (rot[r1] == 0.0)) {
              e_st.site = &ib_emlrtRSI;
              if (!emlrtSetWarningFlag(&e_st)) {
                f_st.site = &jb_emlrtRSI;
                warning(&f_st);
              }
            }
            i1 = r1 << 1;
            _mm_storeu_pd(&K[i1], _mm_div_pd(_mm_loadu_pd(&inMap_data[j].P[0]),
                                             _mm_set1_pd(rot[r1])));
            r = _mm_loadu_pd(&K[i1]);
            r1 = r2 << 1;
            _mm_storeu_pd(
                &K[r1],
                _mm_div_pd(_mm_sub_pd(_mm_loadu_pd(&inMap_data[j].P[2]),
                                      _mm_mul_pd(r, _mm_set1_pd(Jx_tmp))),
                           _mm_set1_pd(a22)));
            r = _mm_loadu_pd(&K[r1]);
            b_r1 = _mm_loadu_pd(&K[i1]);
            _mm_storeu_pd(&K[i1],
                          _mm_sub_pd(b_r1, _mm_mul_pd(r, _mm_set1_pd(a21))));
            if (i + 1 > loop_ub) {
              emlrtDynamicBoundsCheckR2012b(i + 1, 1, loop_ub, &xb_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            if (j + 1 > b_i) {
              emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_i, &wb_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            outCount++;
            r = _mm_loadu_pd(&Zmap_data[2 * i]);
            _mm_storeu_pd(&nu[0],
                          _mm_sub_pd(r, _mm_loadu_pd(&inMap_data[j].m[0])));
            if (outCount > mapOut->size[1]) {
              emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                            &wc_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (j + 1 > b_i) {
              emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_i, &xc_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            b_mapOut_data[outCount - 1].m[0] =
                inMap_data[j].m[0] + (K[0] * nu[0] + nu[1] * K[2]);
            if (outCount > mapOut->size[1]) {
              emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                            &wc_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (j + 1 > b_i) {
              emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_i, &xc_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            b_mapOut_data[outCount - 1].m[1] =
                inMap_data[j].m[1] + (nu[0] * K[1] + nu[1] * K[3]);
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
                                            &vc_emlrtBCI, (emlrtConstCTX)sp);
            }
            b_mapOut_data[outCount - 1].P[0] = 0.0;
            if (outCount > mapOut->size[1]) {
              emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                            &vc_emlrtBCI, (emlrtConstCTX)sp);
            }
            b_mapOut_data[outCount - 1].P[1] = 0.0;
            if (outCount > mapOut->size[1]) {
              emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                            &vc_emlrtBCI, (emlrtConstCTX)sp);
            }
            b_mapOut_data[outCount - 1].P[2] = 0.0;
            if (outCount > mapOut->size[1]) {
              emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                            &vc_emlrtBCI, (emlrtConstCTX)sp);
            }
            b_mapOut_data[outCount - 1].P[3] = 0.0;
            r = _mm_loadu_pd(&rot[0]);
            if (outCount > mapOut->size[1]) {
              emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                            &vc_emlrtBCI, (emlrtConstCTX)sp);
            }
            b_r1 = _mm_loadu_pd(&b_mapOut_data[outCount - 1].P[0]);
            if (outCount > mapOut->size[1]) {
              emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                            &vc_emlrtBCI, (emlrtConstCTX)sp);
            }
            _mm_storeu_pd(
                &b_mapOut_data[outCount - 1].P[0],
                _mm_add_pd(b_r1,
                           _mm_mul_pd(r, _mm_set1_pd(inMap_data[j].P[0]))));
            r = _mm_loadu_pd(&rot[2]);
            if (outCount > mapOut->size[1]) {
              emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                            &vc_emlrtBCI, (emlrtConstCTX)sp);
            }
            b_r1 = _mm_loadu_pd(&b_mapOut_data[outCount - 1].P[0]);
            if (outCount > mapOut->size[1]) {
              emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                            &vc_emlrtBCI, (emlrtConstCTX)sp);
            }
            _mm_storeu_pd(
                &b_mapOut_data[outCount - 1].P[0],
                _mm_add_pd(b_r1,
                           _mm_mul_pd(r, _mm_set1_pd(inMap_data[j].P[1]))));
            r = _mm_loadu_pd(&rot[0]);
            if (outCount > mapOut->size[1]) {
              emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                            &vc_emlrtBCI, (emlrtConstCTX)sp);
            }
            b_r1 = _mm_loadu_pd(&b_mapOut_data[outCount - 1].P[2]);
            if (outCount > mapOut->size[1]) {
              emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                            &vc_emlrtBCI, (emlrtConstCTX)sp);
            }
            _mm_storeu_pd(
                &b_mapOut_data[outCount - 1].P[2],
                _mm_add_pd(b_r1,
                           _mm_mul_pd(r, _mm_set1_pd(inMap_data[j].P[2]))));
            r = _mm_loadu_pd(&rot[2]);
            if (outCount > mapOut->size[1]) {
              emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                            &vc_emlrtBCI, (emlrtConstCTX)sp);
            }
            b_r1 = _mm_loadu_pd(&b_mapOut_data[outCount - 1].P[2]);
            if (outCount > mapOut->size[1]) {
              emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                            &vc_emlrtBCI, (emlrtConstCTX)sp);
            }
            _mm_storeu_pd(
                &b_mapOut_data[outCount - 1].P[2],
                _mm_add_pd(b_r1,
                           _mm_mul_pd(r, _mm_set1_pd(inMap_data[j].P[3]))));
            if (outCount > mapOut->size[1]) {
              emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                            &sc_emlrtBCI, (emlrtConstCTX)sp);
            }
            st.site = &lc_emlrtRSI;
            regularize_cov_local(&st, b_mapOut_data[outCount - 1].P);
            if (outCount > mapOut->size[1]) {
              emlrtDynamicBoundsCheckR2012b(outCount, 1, mapOut->size[1],
                                            &tc_emlrtBCI, (emlrtConstCTX)sp);
            }
            b_mapOut_data[outCount - 1].w = w;
            r1 = birthIdx_size[1];
            if (i + 1 > r1) {
              emlrtDynamicBoundsCheckR2012b(i + 1, 1, r1, &uc_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            birthIdx_data[i] = false;
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
    emxFree_real_T(sp, &rawLike);
    st.site = &mc_emlrtRSI;
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
    emxEnsureCapacity_struct0_T(sp, mapOut, r1, &o_emlrtRTEI);
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
  q = -u[0] / u[1];
  Fx[6] = q * e_xPred_tmp + g_xPred_tmp;
  Fx[1] = 0.0;
  Fx[4] = 1.0;
  Fx[7] = q * xPred_tmp + d_xPred_tmp;
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
  xPred_tmp_tmp = Qu[3] * 3.0;
  memset(&b_Fx[0], 0, 9U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    q = P[3 * i];
    r = _mm_loadu_pd(&Fx[0]);
    r1 = _mm_loadu_pd(&b_Fx[3 * i]);
    _mm_storeu_pd(&b_Fx[3 * i], _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(q))));
    Fx_tmp = 3 * i + 2;
    b_Fx[Fx_tmp] += 0.0 * q;
    q = P[3 * i + 1];
    r = _mm_loadu_pd(&Fx[3]);
    r1 = _mm_loadu_pd(&b_Fx[3 * i]);
    _mm_storeu_pd(&b_Fx[3 * i], _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(q))));
    b_Fx[Fx_tmp] += 0.0 * q;
    q = P[Fx_tmp];
    r = _mm_loadu_pd(&Fx[6]);
    r1 = _mm_loadu_pd(&b_Fx[3 * i]);
    _mm_storeu_pd(&b_Fx[3 * i], _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(q))));
    b_Fx[Fx_tmp] += q;
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
  _mm_storeu_pd(&b_Fu[3],
                _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(xPred_tmp_tmp))));
  b_Fu[5] += dt * xPred_tmp_tmp;
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
pose_update_mm_local(const emlrtStack *sp, const real_T xBase[3],
                     const real_T PBase[9], const struct0_T mapIn_data[],
                     const int32_T mapIn_size[2], const real_T Z_data[],
                     const int32_T Z_size[2], real_T params_P_D,
                     real_T params_clutter_rate, real_T params_iter_max,
                     real_T params_PHD_det_keep, real_T params_PHD_miss_keep,
                     const real_T Rstack_data[], const int32_T Rstack_size[3],
                     real_T iterCnt, real_T xOut[3], real_T POut[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T detCov_data[288];
  real_T detState_data[96];
  real_T xDet_data[96];
  real_T detRaw_data[32];
  real_T b_PBase[9];
  real_T H[6];
  real_T K[6];
  real_T b_H[6];
  real_T diffMiss[3];
  real_T Zhat[2];
  real_T nu[2];
  int32_T b_i;
  int32_T b_j;
  int32_T i1;
  int32_T j;
  int32_T numZ;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  numZ = Z_size[1];
  if (mapIn_size[1] == 0) {
    xOut[0] = xBase[0];
    xOut[1] = xBase[1];
    xOut[2] = xBase[2];
    memcpy(&POut[0], &PBase[0], 9U * sizeof(real_T));
  } else {
    __m128d r;
    __m128d r1;
    real_T S[4];
    real_T Y[2];
    real_T Zhat_tmp;
    real_T c;
    real_T denom;
    real_T dx;
    real_T dy;
    real_T missW_tmp;
    real_T s;
    real_T sumW;
    int32_T PBase_tmp;
    int32_T i;
    c = muDoubleScalarCos(xBase[2]);
    s = muDoubleScalarSin(xBase[2]);
    sumW = 0.0;
    xOut[0] = 0.0;
    xOut[1] = 0.0;
    xOut[2] = 0.0;
    i = mapIn_size[1];
    H[0] = -c;
    H[2] = -s;
    H[1] = s;
    H[3] = -c;
    for (b_i = 0; b_i < i; b_i++) {
      if (b_i + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &x_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      dx = mapIn_data[b_i].m[0] - xBase[0];
      if (b_i + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &y_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      dy = mapIn_data[b_i].m[1] - xBase[1];
      Zhat_tmp = s * dy;
      Zhat[0] = c * dx + Zhat_tmp;
      dy *= c;
      Zhat[1] = -s * dx + dy;
      H[4] = -dx * s + dy;
      H[5] = -dx * c - Zhat_tmp;
      if (b_i + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &cb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      missW_tmp = mapIn_data[b_i].w;
      dy = missW_tmp * (1.0 - params_P_D);
      if (dy > params_PHD_miss_keep) {
        sumW += dy;
        r = _mm_loadu_pd(&xOut[0]);
        _mm_storeu_pd(&xOut[0],
                      _mm_add_pd(r, _mm_mul_pd(_mm_set1_pd(dy),
                                               _mm_loadu_pd(&xBase[0]))));
        xOut[2] += dy * xBase[2];
      }
      denom = params_clutter_rate;
      for (j = 0; j < numZ; j++) {
        for (b_j = 0; b_j < 2; b_j++) {
          K[3 * b_j] = H[b_j];
          K[3 * b_j + 1] = H[b_j + 2];
          K[3 * b_j + 2] = H[b_j + 4];
        }
        memset(&b_H[0], 0, 6U * sizeof(real_T));
        for (b_j = 0; b_j < 3; b_j++) {
          r = _mm_loadu_pd(&H[0]);
          PBase_tmp = b_j << 1;
          r1 = _mm_loadu_pd(&b_H[PBase_tmp]);
          _mm_storeu_pd(
              &b_H[PBase_tmp],
              _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(PBase[3 * b_j]))));
          r = _mm_loadu_pd(&H[2]);
          r1 = _mm_loadu_pd(&b_H[PBase_tmp]);
          _mm_storeu_pd(
              &b_H[PBase_tmp],
              _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(PBase[3 * b_j + 1]))));
          r = _mm_loadu_pd(&H[4]);
          r1 = _mm_loadu_pd(&b_H[PBase_tmp]);
          _mm_storeu_pd(
              &b_H[PBase_tmp],
              _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(PBase[3 * b_j + 2]))));
        }
        if (j + 1 > Rstack_size[2]) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, Rstack_size[2], &l_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        for (b_j = 0; b_j < 2; b_j++) {
          dy = b_H[b_j];
          Zhat_tmp = b_H[b_j + 2];
          dx = b_H[b_j + 4];
          for (i1 = 0; i1 < 2; i1++) {
            S[b_j + (i1 << 1)] = ((dy * K[3 * i1] + Zhat_tmp * K[3 * i1 + 1]) +
                                  dx * K[3 * i1 + 2]) +
                                 Rstack_data[(b_j + 2 * i1) + 4 * j];
          }
        }
        st.site = &ab_emlrtRSI;
        memset(&b_H[0], 0, 6U * sizeof(real_T));
        for (b_j = 0; b_j < 2; b_j++) {
          dy = K[3 * b_j];
          r = _mm_loadu_pd(&b_H[3 * b_j]);
          _mm_storeu_pd(&b_H[3 * b_j],
                        _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&PBase[0]),
                                                 _mm_set1_pd(dy))));
          PBase_tmp = 3 * b_j + 2;
          b_H[PBase_tmp] += PBase[2] * dy;
          dy = K[3 * b_j + 1];
          r = _mm_loadu_pd(&b_H[3 * b_j]);
          _mm_storeu_pd(&b_H[3 * b_j],
                        _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&PBase[3]),
                                                 _mm_set1_pd(dy))));
          b_H[PBase_tmp] += PBase[5] * dy;
          dy = K[PBase_tmp];
          r = _mm_loadu_pd(&b_H[3 * b_j]);
          _mm_storeu_pd(&b_H[3 * b_j],
                        _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&PBase[6]),
                                                 _mm_set1_pd(dy))));
          b_H[PBase_tmp] += PBase[8] * dy;
        }
        b_st.site = &fb_emlrtRSI;
        mrdiv(&b_st, b_H, S, K);
        if (j + 1 > numZ) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, numZ, &m_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        r = _mm_loadu_pd(&Zhat[0]);
        _mm_storeu_pd(&nu[0], _mm_sub_pd(_mm_loadu_pd(&Z_data[2 * j]), r));
        if (j + 1 > numZ) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, numZ, &o_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        dy = nu[0];
        Zhat_tmp = nu[1];
        r = _mm_loadu_pd(&K[0]);
        r1 = _mm_mul_pd(r, _mm_set1_pd(dy));
        r = _mm_loadu_pd(&K[3]);
        r = _mm_mul_pd(r, _mm_set1_pd(Zhat_tmp));
        r = _mm_add_pd(r1, r);
        r1 = _mm_loadu_pd(&xBase[0]);
        r = _mm_add_pd(r1, r);
        _mm_storeu_pd(&xDet_data[3 * j], r);
        xDet_data[2 + 3 * j] = xBase[2] + (K[2] * dy + K[5] * Zhat_tmp);
        st.site = &bb_emlrtRSI;
        if (j + 1 > numZ) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, numZ, &n_emlrtBCI, &st);
        }
        b_st.site = &kb_emlrtRSI;
        regularize_cov_local(&b_st, S);
        b_st.site = &lb_emlrtRSI;
        c_st.site = &fb_emlrtRSI;
        b_mrdiv(&c_st, nu, S, Y);
        b_st.site = &lb_emlrtRSI;
        dy = det(S);
        if (dy < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &b_st, &c_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        dy = muDoubleScalarSqrt(dy);
        if (b_i + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &gb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (j + 1 > numZ) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, numZ, &hb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        dy = 1.0 / (6.2831853071795862 * dy) *
             muDoubleScalarExp(-0.5 * Y[0] * nu[0] + -0.5 * Y[1] * nu[1]) *
             params_P_D * missW_tmp;
        detRaw_data[j] = dy;
        if (j + 1 > numZ) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, numZ, &ib_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        denom += dy;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtConstCTX)sp);
        }
      }
      if (denom > 0.0) {
        for (b_j = 0; b_j < numZ; b_j++) {
          if (b_j + 1 > numZ) {
            emlrtDynamicBoundsCheckR2012b(b_j + 1, 1, numZ, &eb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          dy = detRaw_data[b_j] / denom;
          if (dy > params_PHD_det_keep) {
            sumW += dy;
            if (b_j + 1 > numZ) {
              emlrtDynamicBoundsCheckR2012b(b_j + 1, 1, numZ, &p_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            r = _mm_loadu_pd(&xDet_data[3 * b_j]);
            r1 = _mm_loadu_pd(&xOut[0]);
            _mm_storeu_pd(&xOut[0],
                          _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(dy), r)));
            xOut[2] += dy * xDet_data[3 * b_j + 2];
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
    if (sumW <= 2.2204460492503131E-16) {
      xOut[0] = xBase[0];
      xOut[1] = xBase[1];
      xOut[2] = xBase[2];
      memcpy(&POut[0], &PBase[0], 9U * sizeof(real_T));
    } else {
      r = _mm_loadu_pd(&xOut[0]);
      _mm_storeu_pd(&xOut[0], _mm_div_pd(r, _mm_set1_pd(sumW)));
      xOut[2] /= sumW;
      if (iterCnt != params_iter_max) {
        memcpy(&POut[0], &PBase[0], 9U * sizeof(real_T));
      } else {
        memset(&POut[0], 0, 9U * sizeof(real_T));
        H[0] = -c;
        H[2] = -s;
        H[1] = s;
        H[3] = -c;
        for (b_i = 0; b_i < i; b_i++) {
          __m128d r2;
          if (b_i + 1 > i) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &ab_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          dx = mapIn_data[b_i].m[0] - xBase[0];
          if (b_i + 1 > i) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &bb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          dy = mapIn_data[b_i].m[1] - xBase[1];
          Zhat_tmp = s * dy;
          Zhat[0] = c * dx + Zhat_tmp;
          dy *= c;
          Zhat[1] = -s * dx + dy;
          H[4] = -dx * s + dy;
          H[5] = -dx * c - Zhat_tmp;
          if (b_i + 1 > i) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &db_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          missW_tmp = mapIn_data[b_i].w;
          dy = missW_tmp * (1.0 - params_P_D);
          if (dy > params_PHD_miss_keep) {
            dy /= sumW;
            r = _mm_loadu_pd(&xOut[0]);
            _mm_storeu_pd(&diffMiss[0], _mm_sub_pd(_mm_loadu_pd(&xBase[0]), r));
            diffMiss[2] = xBase[2] - xOut[2];
            r = _mm_loadu_pd(&diffMiss[0]);
            r1 = _mm_set1_pd(0.0);
            _mm_storeu_pd(
                &b_PBase[0],
                _mm_add_pd(
                    _mm_loadu_pd(&PBase[0]),
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(diffMiss[0])))));
            b_PBase[2] = PBase[2] + diffMiss[0] * diffMiss[2];
            r = _mm_loadu_pd(&diffMiss[0]);
            _mm_storeu_pd(
                &b_PBase[3],
                _mm_add_pd(
                    _mm_loadu_pd(&PBase[3]),
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(diffMiss[1])))));
            b_PBase[5] = PBase[5] + diffMiss[1] * diffMiss[2];
            r = _mm_loadu_pd(&diffMiss[0]);
            _mm_storeu_pd(
                &b_PBase[6],
                _mm_add_pd(
                    _mm_loadu_pd(&PBase[6]),
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(diffMiss[2])))));
            b_PBase[8] = PBase[8] + diffMiss[2] * diffMiss[2];
            r = _mm_loadu_pd(&b_PBase[0]);
            r1 = _mm_loadu_pd(&POut[0]);
            r2 = _mm_set1_pd(dy);
            _mm_storeu_pd(&POut[0], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
            r = _mm_loadu_pd(&b_PBase[2]);
            r1 = _mm_loadu_pd(&POut[2]);
            _mm_storeu_pd(&POut[2], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
            r = _mm_loadu_pd(&b_PBase[4]);
            r1 = _mm_loadu_pd(&POut[4]);
            _mm_storeu_pd(&POut[4], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
            r = _mm_loadu_pd(&b_PBase[6]);
            r1 = _mm_loadu_pd(&POut[6]);
            _mm_storeu_pd(&POut[6], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
            POut[8] += dy * b_PBase[8];
          }
          denom = params_clutter_rate;
          for (j = 0; j < numZ; j++) {
            int8_T b_I[9];
            for (b_j = 0; b_j < 2; b_j++) {
              K[3 * b_j] = H[b_j];
              K[3 * b_j + 1] = H[b_j + 2];
              K[3 * b_j + 2] = H[b_j + 4];
            }
            memset(&b_H[0], 0, 6U * sizeof(real_T));
            for (b_j = 0; b_j < 3; b_j++) {
              r = _mm_loadu_pd(&H[0]);
              PBase_tmp = b_j << 1;
              r1 = _mm_loadu_pd(&b_H[PBase_tmp]);
              _mm_storeu_pd(
                  &b_H[PBase_tmp],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(PBase[3 * b_j]))));
              r = _mm_loadu_pd(&H[2]);
              r1 = _mm_loadu_pd(&b_H[PBase_tmp]);
              _mm_storeu_pd(
                  &b_H[PBase_tmp],
                  _mm_add_pd(r1,
                             _mm_mul_pd(r, _mm_set1_pd(PBase[3 * b_j + 1]))));
              r = _mm_loadu_pd(&H[4]);
              r1 = _mm_loadu_pd(&b_H[PBase_tmp]);
              _mm_storeu_pd(
                  &b_H[PBase_tmp],
                  _mm_add_pd(r1,
                             _mm_mul_pd(r, _mm_set1_pd(PBase[3 * b_j + 2]))));
            }
            if (j + 1 > Rstack_size[2]) {
              emlrtDynamicBoundsCheckR2012b(j + 1, 1, Rstack_size[2],
                                            &q_emlrtBCI, (emlrtConstCTX)sp);
            }
            for (b_j = 0; b_j < 2; b_j++) {
              dy = b_H[b_j];
              Zhat_tmp = b_H[b_j + 2];
              dx = b_H[b_j + 4];
              for (i1 = 0; i1 < 2; i1++) {
                S[b_j + (i1 << 1)] =
                    ((dy * K[3 * i1] + Zhat_tmp * K[3 * i1 + 1]) +
                     dx * K[3 * i1 + 2]) +
                    Rstack_data[(b_j + 2 * i1) + 4 * j];
              }
            }
            st.site = &cb_emlrtRSI;
            memset(&b_H[0], 0, 6U * sizeof(real_T));
            for (b_j = 0; b_j < 2; b_j++) {
              dy = K[3 * b_j];
              r = _mm_loadu_pd(&b_H[3 * b_j]);
              _mm_storeu_pd(&b_H[3 * b_j],
                            _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&PBase[0]),
                                                     _mm_set1_pd(dy))));
              PBase_tmp = 3 * b_j + 2;
              b_H[PBase_tmp] += PBase[2] * dy;
              dy = K[3 * b_j + 1];
              r = _mm_loadu_pd(&b_H[3 * b_j]);
              _mm_storeu_pd(&b_H[3 * b_j],
                            _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&PBase[3]),
                                                     _mm_set1_pd(dy))));
              b_H[PBase_tmp] += PBase[5] * dy;
              dy = K[PBase_tmp];
              r = _mm_loadu_pd(&b_H[3 * b_j]);
              _mm_storeu_pd(&b_H[3 * b_j],
                            _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&PBase[6]),
                                                     _mm_set1_pd(dy))));
              b_H[PBase_tmp] += PBase[8] * dy;
            }
            b_st.site = &fb_emlrtRSI;
            mrdiv(&b_st, b_H, S, K);
            if (j + 1 > numZ) {
              emlrtDynamicBoundsCheckR2012b(j + 1, 1, numZ, &r_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            r = _mm_loadu_pd(&Zhat[0]);
            _mm_storeu_pd(&nu[0], _mm_sub_pd(_mm_loadu_pd(&Z_data[2 * j]), r));
            if (j + 1 > numZ) {
              emlrtDynamicBoundsCheckR2012b(j + 1, 1, numZ, &t_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            dy = nu[0];
            Zhat_tmp = nu[1];
            r = _mm_loadu_pd(&K[0]);
            r1 = _mm_mul_pd(r, _mm_set1_pd(dy));
            r = _mm_loadu_pd(&K[3]);
            r = _mm_mul_pd(r, _mm_set1_pd(Zhat_tmp));
            r = _mm_add_pd(r1, r);
            r1 = _mm_loadu_pd(&xBase[0]);
            r = _mm_add_pd(r1, r);
            _mm_storeu_pd(&detState_data[3 * j], r);
            detState_data[2 + 3 * j] = xBase[2] + (K[2] * dy + K[5] * Zhat_tmp);
            for (b_j = 0; b_j < 9; b_j++) {
              b_I[b_j] = 0;
            }
            b_I[0] = 1;
            b_I[4] = 1;
            b_I[8] = 1;
            for (b_j = 0; b_j < 3; b_j++) {
              dy = K[b_j];
              Zhat_tmp = K[b_j + 3];
              for (i1 = 0; i1 < 3; i1++) {
                int32_T b_PBase_tmp;
                PBase_tmp = i1 << 1;
                b_PBase_tmp = b_j + 3 * i1;
                b_PBase[b_PBase_tmp] =
                    (real_T)b_I[b_PBase_tmp] -
                    (dy * H[PBase_tmp] + Zhat_tmp * H[PBase_tmp + 1]);
              }
            }
            if (j + 1 > numZ) {
              emlrtDynamicBoundsCheckR2012b(j + 1, 1, numZ, &w_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            for (b_j = 0; b_j < 3; b_j++) {
              PBase_tmp = 3 * b_j + 9 * j;
              detCov_data[PBase_tmp] = 0.0;
              detCov_data[PBase_tmp + 1] = 0.0;
              detCov_data[PBase_tmp + 2] = 0.0;
              dy = PBase[3 * b_j];
              r = _mm_loadu_pd(&b_PBase[0]);
              r1 = _mm_loadu_pd(&detCov_data[PBase_tmp]);
              _mm_storeu_pd(&detCov_data[PBase_tmp],
                            _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(dy))));
              detCov_data[PBase_tmp + 2] += b_PBase[2] * dy;
              dy = PBase[3 * b_j + 1];
              r = _mm_loadu_pd(&b_PBase[3]);
              r1 = _mm_loadu_pd(&detCov_data[PBase_tmp]);
              _mm_storeu_pd(&detCov_data[PBase_tmp],
                            _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(dy))));
              detCov_data[PBase_tmp + 2] += b_PBase[5] * dy;
              dy = PBase[3 * b_j + 2];
              r = _mm_loadu_pd(&b_PBase[6]);
              r1 = _mm_loadu_pd(&detCov_data[PBase_tmp]);
              _mm_storeu_pd(&detCov_data[PBase_tmp],
                            _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(dy))));
              detCov_data[PBase_tmp + 2] += b_PBase[8] * dy;
            }
            st.site = &db_emlrtRSI;
            if (j + 1 > numZ) {
              emlrtDynamicBoundsCheckR2012b(j + 1, 1, numZ, &s_emlrtBCI, &st);
            }
            b_st.site = &kb_emlrtRSI;
            regularize_cov_local(&b_st, S);
            b_st.site = &lb_emlrtRSI;
            c_st.site = &fb_emlrtRSI;
            b_mrdiv(&c_st, nu, S, Y);
            b_st.site = &lb_emlrtRSI;
            dy = det(S);
            if (dy < 0.0) {
              emlrtErrorWithMessageIdR2018a(
                  &b_st, &c_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                  "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
            }
            dy = muDoubleScalarSqrt(dy);
            if (b_i + 1 > i) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &jb_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            if (j + 1 > numZ) {
              emlrtDynamicBoundsCheckR2012b(j + 1, 1, numZ, &kb_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            dy = 1.0 / (6.2831853071795862 * dy) *
                 muDoubleScalarExp(-0.5 * Y[0] * nu[0] + -0.5 * Y[1] * nu[1]) *
                 params_P_D * missW_tmp;
            detRaw_data[j] = dy;
            if (j + 1 > numZ) {
              emlrtDynamicBoundsCheckR2012b(j + 1, 1, numZ, &lb_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            denom += dy;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b((emlrtConstCTX)sp);
            }
          }
          if (denom > 0.0) {
            for (b_j = 0; b_j < numZ; b_j++) {
              if (b_j + 1 > numZ) {
                emlrtDynamicBoundsCheckR2012b(b_j + 1, 1, numZ, &fb_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              dy = detRaw_data[b_j] / denom;
              if (dy > params_PHD_det_keep) {
                dy /= sumW;
                if (b_j + 1 > numZ) {
                  emlrtDynamicBoundsCheckR2012b(b_j + 1, 1, numZ, &u_emlrtBCI,
                                                (emlrtConstCTX)sp);
                }
                r = _mm_loadu_pd(&detState_data[3 * b_j]);
                r1 = _mm_loadu_pd(&xOut[0]);
                _mm_storeu_pd(&diffMiss[0], _mm_sub_pd(r, r1));
                diffMiss[2] = detState_data[3 * b_j + 2] - xOut[2];
                if (b_j + 1 > numZ) {
                  emlrtDynamicBoundsCheckR2012b(b_j + 1, 1, numZ, &v_emlrtBCI,
                                                (emlrtConstCTX)sp);
                }
                r = _mm_loadu_pd(&diffMiss[0]);
                r1 = _mm_loadu_pd(&detCov_data[9 * b_j]);
                r2 = _mm_set1_pd(0.0);
                _mm_storeu_pd(
                    &b_PBase[0],
                    _mm_add_pd(
                        r1, _mm_add_pd(
                                r2, _mm_mul_pd(r, _mm_set1_pd(diffMiss[0])))));
                b_PBase[2] =
                    detCov_data[9 * b_j + 2] + diffMiss[0] * diffMiss[2];
                r = _mm_loadu_pd(&diffMiss[0]);
                r1 = _mm_loadu_pd(&detCov_data[9 * b_j + 3]);
                _mm_storeu_pd(
                    &b_PBase[3],
                    _mm_add_pd(
                        r1, _mm_add_pd(
                                r2, _mm_mul_pd(r, _mm_set1_pd(diffMiss[1])))));
                b_PBase[5] =
                    detCov_data[9 * b_j + 5] + diffMiss[1] * diffMiss[2];
                r = _mm_loadu_pd(&diffMiss[0]);
                r1 = _mm_loadu_pd(&detCov_data[9 * b_j + 6]);
                _mm_storeu_pd(
                    &b_PBase[6],
                    _mm_add_pd(
                        r1, _mm_add_pd(
                                r2, _mm_mul_pd(r, _mm_set1_pd(diffMiss[2])))));
                b_PBase[8] =
                    detCov_data[9 * b_j + 8] + diffMiss[2] * diffMiss[2];
                r = _mm_loadu_pd(&b_PBase[0]);
                r1 = _mm_loadu_pd(&POut[0]);
                r2 = _mm_set1_pd(dy);
                _mm_storeu_pd(&POut[0], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
                r = _mm_loadu_pd(&b_PBase[2]);
                r1 = _mm_loadu_pd(&POut[2]);
                _mm_storeu_pd(&POut[2], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
                r = _mm_loadu_pd(&b_PBase[4]);
                r1 = _mm_loadu_pd(&POut[4]);
                _mm_storeu_pd(&POut[4], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
                r = _mm_loadu_pd(&b_PBase[6]);
                r1 = _mm_loadu_pd(&POut[6]);
                _mm_storeu_pd(&POut[6], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
                POut[8] += dy * b_PBase[8];
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
        st.site = &eb_emlrtRSI;
        b_regularize_cov_local(&st, POut);
      }
    }
  }
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
    real_T tmp_data[32];
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
  boolean_T used_data[17408];
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
  emxInit_struct0_T(sp, &pruned, &r_emlrtRTEI);
  emxInit_real_T(sp, &weights, 2, &cb_emlrtRTEI);
  emxInit_struct0_T(sp, &merged, &v_emlrtRTEI);
  emxInit_real_T(sp, &mergedWeights, 2, &w_emlrtRTEI);
  emxInit_int32_T(sp, &members, 2, &ab_emlrtRTEI);
  emxInit_struct0_T(sp, &r, &db_emlrtRTEI);
  if (mapIn->size[1] == 0) {
    mapOut->size[0] = 1;
    mapOut->size[1] = 0;
  } else {
    int32_T b_r1;
    int32_T loop_ub;
    int32_T prunedCount;
    st.site = &wc_emlrtRSI;
    repmat(&st, mapIn->size[1], r);
    r1 = r->data;
    b_r1 = pruned->size[0] * pruned->size[1];
    pruned->size[0] = 1;
    loop_ub = r->size[1];
    pruned->size[1] = r->size[1];
    emxEnsureCapacity_struct0_T(sp, pruned, b_r1, &r_emlrtRTEI);
    pruned_data = pruned->data;
    for (i = 0; i < loop_ub; i++) {
      pruned_data[i] = r1[i];
    }
    prunedCount = 0;
    b_r1 = mapIn->size[1];
    for (i = 0; i < b_r1; i++) {
      if (i + 1 > b_r1) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_r1, &od_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (mapIn_data[i].w > params_prune_threshold) {
        prunedCount++;
        if ((prunedCount < 1) || (prunedCount > loop_ub)) {
          emlrtDynamicBoundsCheckR2012b(prunedCount, 1, loop_ub, &ie_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (i + 1 > b_r1) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_r1, &je_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        pruned_data[prunedCount - 1].m[0] = mapIn_data[i].m[0];
        if (prunedCount > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(prunedCount, 1, loop_ub, &ie_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (i + 1 > b_r1) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_r1, &je_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        pruned_data[prunedCount - 1].m[1] = mapIn_data[i].m[1];
        if (i + 1 > b_r1) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_r1, &kd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (prunedCount > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(prunedCount, 1, loop_ub, &ld_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        pruned_data[prunedCount - 1].P[0] = mapIn_data[i].P[0];
        pruned_data[prunedCount - 1].P[1] = mapIn_data[i].P[1];
        pruned_data[prunedCount - 1].P[2] = mapIn_data[i].P[2];
        pruned_data[prunedCount - 1].P[3] = mapIn_data[i].P[3];
        if (prunedCount > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(prunedCount, 1, loop_ub, &ld_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        st.site = &vc_emlrtRSI;
        regularize_cov_local(&st, pruned_data[prunedCount - 1].P);
        if (i + 1 > b_r1) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_r1, &rd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (prunedCount > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(prunedCount, 1, loop_ub, &sd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        pruned_data[prunedCount - 1].w = mapIn_data[i].w;
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
        emlrtDynamicBoundsCheckR2012b(prunedCount, 1, r->size[1], &bd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      b_r1 = pruned->size[0] * pruned->size[1];
      pruned->size[1] = prunedCount;
      emxEnsureCapacity_struct0_T(sp, pruned, b_r1, &s_emlrtRTEI);
      pruned_data = pruned->data;
      b_r1 = weights->size[0] * weights->size[1];
      weights->size[0] = 1;
      weights->size[1] = prunedCount;
      emxEnsureCapacity_real_T(sp, weights, b_r1, &t_emlrtRTEI);
      weights_data = weights->data;
      for (i = 0; i < prunedCount; i++) {
        if (i + 1 > prunedCount) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, prunedCount, &pd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (i + 1 > weights->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, weights->size[1],
                                        &qd_emlrtBCI, (emlrtConstCTX)sp);
        }
        weights_data[i] = pruned_data[i].w;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtConstCTX)sp);
        }
      }
      st.site = &uc_emlrtRSI;
      b_st.site = &xc_emlrtRSI;
      sort(&b_st, weights, members);
      members_data = members->data;
      b_r1 = weights->size[0] * weights->size[1];
      weights->size[0] = 1;
      b_loop_ub = members->size[1];
      weights->size[1] = members->size[1];
      emxEnsureCapacity_real_T(&st, weights, b_r1, &u_emlrtRTEI);
      weights_data = weights->data;
      for (i = 0; i < b_loop_ub; i++) {
        weights_data[i] = members_data[i];
      }
      memset(&used_data[0], 0, (uint32_T)prunedCount * sizeof(boolean_T));
      st.site = &tc_emlrtRSI;
      repmat(&st, prunedCount, r);
      r1 = r->data;
      b_r1 = merged->size[0] * merged->size[1];
      merged->size[0] = 1;
      c_loop_ub = r->size[1];
      merged->size[1] = r->size[1];
      emxEnsureCapacity_struct0_T(sp, merged, b_r1, &v_emlrtRTEI);
      merged_data = merged->data;
      for (i = 0; i < c_loop_ub; i++) {
        merged_data[i] = r1[i];
      }
      b_r1 = mergedWeights->size[0] * mergedWeights->size[1];
      mergedWeights->size[0] = 1;
      mergedWeights->size[1] = prunedCount;
      emxEnsureCapacity_real_T(sp, mergedWeights, b_r1, &w_emlrtRTEI);
      mergedWeights_data = mergedWeights->data;
      for (i = 0; i < prunedCount; i++) {
        mergedWeights_data[i] = 0.0;
      }
      mergedCount = 0;
      for (ii = 0; ii < prunedCount; ii++) {
        int32_T b_i;
        if (ii + 1 > b_loop_ub) {
          emlrtDynamicBoundsCheckR2012b(ii + 1, 1, b_loop_ub, &cd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        b_i = (int32_T)weights_data[ii];
        if ((b_i < 1) || (b_i > prunedCount)) {
          emlrtDynamicBoundsCheckR2012b(b_i, 1, prunedCount, &td_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (!used_data[b_i - 1]) {
          __m128d b_r2;
          __m128d r3;
          __m128d r4;
          __m128d r5;
          __m128d r6;
          int32_T i1;
          int32_T memberCount;
          if (b_i > prunedCount) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, prunedCount, &ud_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          used_data[b_i - 1] = true;
          b_r1 = members->size[0] * members->size[1];
          members->size[0] = 1;
          members->size[1] = prunedCount;
          emxEnsureCapacity_int32_T(sp, members, b_r1, &ab_emlrtRTEI);
          members_data = members->data;
          for (i = 0; i < prunedCount; i++) {
            members_data[i] = 0;
          }
          memberCount = 1;
          members_data[0] = b_i;
          if (b_i > prunedCount) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, prunedCount, &md_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          Pi[0] = pruned_data[b_i - 1].P[0];
          Pi[1] = pruned_data[b_i - 1].P[1];
          Pi[2] = pruned_data[b_i - 1].P[2];
          Pi[3] = pruned_data[b_i - 1].P[3];
          st.site = &sc_emlrtRSI;
          regularize_cov_local(&st, Pi);
          i1 = prunedCount - ii;
          for (i = 0; i <= i1 - 2; i++) {
            b_r1 = ii + i;
            if (b_r1 + 2 > b_loop_ub) {
              emlrtDynamicBoundsCheckR2012b(b_r1 + 2, 1, b_loop_ub,
                                            &dd_emlrtBCI, (emlrtConstCTX)sp);
            }
            loop_ub = (int32_T)weights_data[b_r1 + 1];
            if ((loop_ub < 1) || (loop_ub > prunedCount)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, prunedCount,
                                            &vd_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (!used_data[loop_ub - 1]) {
              real_T a22;
              real_T a22_tmp;
              if (loop_ub > prunedCount) {
                emlrtDynamicBoundsCheckR2012b(loop_ub, 1, prunedCount,
                                              &ge_emlrtBCI, (emlrtConstCTX)sp);
              }
              b_r2 = _mm_loadu_pd(&pruned_data[loop_ub - 1].m[0]);
              r4 = _mm_loadu_pd(&pruned_data[b_i - 1].m[0]);
              _mm_storeu_pd(&diff[0], _mm_sub_pd(b_r2, r4));
              st.site = &rc_emlrtRSI;
              b_st.site = &vd_emlrtRSI;
              c_st.site = &wd_emlrtRSI;
              d_st.site = &hb_emlrtRSI;
              if (muDoubleScalarAbs(Pi[1]) > muDoubleScalarAbs(Pi[0])) {
                b_r1 = 1;
                r2 = 0;
              } else {
                b_r1 = 0;
                r2 = 1;
              }
              a21 = Pi[r2] / Pi[b_r1];
              a22_tmp = Pi[b_r1 + 2];
              a22 = Pi[r2 + 2] - a21 * a22_tmp;
              if ((a22 == 0.0) || (Pi[b_r1] == 0.0)) {
                e_st.site = &ib_emlrtRSI;
                if (!emlrtSetWarningFlag(&e_st)) {
                  f_st.site = &jb_emlrtRSI;
                  warning(&f_st);
                }
              }
              meanSum[1] = (diff[r2] - diff[b_r1] * a21) / a22;
              meanSum[0] = (diff[b_r1] - meanSum[1] * a22_tmp) / Pi[b_r1];
              if (diff[0] * meanSum[0] + diff[1] * meanSum[1] <
                  params_merge_threshold) {
                if (loop_ub > prunedCount) {
                  emlrtDynamicBoundsCheckR2012b(
                      loop_ub, 1, prunedCount, &de_emlrtBCI, (emlrtConstCTX)sp);
                }
                used_data[loop_ub - 1] = true;
                memberCount++;
                if (memberCount > members->size[1]) {
                  emlrtDynamicBoundsCheckR2012b(memberCount, 1,
                                                members->size[1], &ee_emlrtBCI,
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
          for (i = 0; i < memberCount; i++) {
            if (i + 1 > members->size[1]) {
              emlrtDynamicBoundsCheckR2012b(i + 1, 1, members->size[1],
                                            &ed_emlrtBCI, (emlrtConstCTX)sp);
            }
            if ((members_data[i] < 1) || (members_data[i] > prunedCount)) {
              emlrtDynamicBoundsCheckR2012b(members_data[i], 1, prunedCount,
                                            &ae_emlrtBCI, (emlrtConstCTX)sp);
            }
            a21 += pruned_data[members_data[i] - 1].w;
            b_r1 = members_data[i];
            if ((b_r1 < 1) || (b_r1 > prunedCount)) {
              emlrtDynamicBoundsCheckR2012b(b_r1, 1, prunedCount, &fd_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            b_r1 = members_data[i];
            if ((b_r1 < 1) || (b_r1 > prunedCount)) {
              emlrtDynamicBoundsCheckR2012b(b_r1, 1, prunedCount, &gd_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            b_r1 = members_data[i];
            b_r2 = _mm_loadu_pd(&pruned_data[b_r1 - 1].m[0]);
            r4 = _mm_loadu_pd(&meanSum[0]);
            _mm_storeu_pd(
                &meanSum[0],
                _mm_add_pd(r4, _mm_mul_pd(_mm_set1_pd(pruned_data[b_r1 - 1].w),
                                          b_r2)));
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
                                            &hd_emlrtBCI, (emlrtConstCTX)sp);
            }
            b = ((members_data[i] < 1) || (members_data[i] > prunedCount));
            if (b) {
              emlrtDynamicBoundsCheckR2012b(members_data[i], 1, prunedCount,
                                            &fe_emlrtBCI, (emlrtConstCTX)sp);
            }
            b_r2 = _mm_loadu_pd(&pruned_data[members_data[i] - 1].m[0]);
            _mm_storeu_pd(&diff[0], _mm_sub_pd(b_r2, r5));
            b_r1 = members_data[i];
            if ((b_r1 < 1) || (b_r1 > prunedCount)) {
              emlrtDynamicBoundsCheckR2012b(b_r1, 1, prunedCount, &id_emlrtBCI,
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
                                          &he_emlrtBCI, (emlrtConstCTX)sp);
          }
          merged_data[mergedCount - 1].m[0] = meanSum[0];
          if (mergedCount > c_loop_ub) {
            emlrtDynamicBoundsCheckR2012b(mergedCount, 1, c_loop_ub,
                                          &he_emlrtBCI, (emlrtConstCTX)sp);
          }
          merged_data[mergedCount - 1].m[1] = meanSum[1];
          if (mergedCount > c_loop_ub) {
            emlrtDynamicBoundsCheckR2012b(mergedCount, 1, c_loop_ub,
                                          &nd_emlrtBCI, (emlrtConstCTX)sp);
          }
          merged_data[mergedCount - 1].P[0] = Pi[0];
          merged_data[mergedCount - 1].P[1] = Pi[1];
          merged_data[mergedCount - 1].P[2] = Pi[2];
          merged_data[mergedCount - 1].P[3] = Pi[3];
          if (mergedCount > c_loop_ub) {
            emlrtDynamicBoundsCheckR2012b(mergedCount, 1, c_loop_ub,
                                          &nd_emlrtBCI, (emlrtConstCTX)sp);
          }
          st.site = &qc_emlrtRSI;
          regularize_cov_local(&st, merged_data[mergedCount - 1].P);
          if (mergedCount > c_loop_ub) {
            emlrtDynamicBoundsCheckR2012b(mergedCount, 1, c_loop_ub,
                                          &be_emlrtBCI, (emlrtConstCTX)sp);
          }
          merged_data[mergedCount - 1].w = a21;
          if (mergedCount > mergedWeights->size[1]) {
            emlrtDynamicBoundsCheckR2012b(mergedCount, 1,
                                          mergedWeights->size[1], &ce_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          mergedWeights_data[mergedCount - 1] = a21;
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
          st.site = &pc_emlrtRSI;
          if (mergedCount > r->size[1]) {
            emlrtDynamicBoundsCheckR2012b(mergedCount, 1, r->size[1],
                                          &e_emlrtBCI, &st);
          }
          b_r1 = mapOut->size[0] * mapOut->size[1];
          mapOut->size[0] = 1;
          mapOut->size[1] = mergedCount;
          emxEnsureCapacity_struct0_T(sp, mapOut, b_r1, &y_emlrtRTEI);
          pruned_data = mapOut->data;
          for (i = 0; i < mergedCount; i++) {
            pruned_data[i] = merged_data[i];
          }
        } else {
          if (mergedCount > mergedWeights->size[1]) {
            emlrtDynamicBoundsCheckR2012b(mergedCount, 1,
                                          mergedWeights->size[1], &jd_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          st.site = &oc_emlrtRSI;
          b_r1 = weights->size[0] * weights->size[1];
          weights->size[0] = 1;
          weights->size[1] = mergedCount;
          emxEnsureCapacity_real_T(&st, weights, b_r1, &x_emlrtRTEI);
          weights_data = weights->data;
          for (i = 0; i < mergedCount; i++) {
            weights_data[i] = mergedWeights_data[i];
          }
          b_st.site = &xc_emlrtRSI;
          sort(&b_st, weights, members);
          members_data = members->data;
          b_r1 = weights->size[0] * weights->size[1];
          weights->size[0] = 1;
          r2 = members->size[1];
          weights->size[1] = members->size[1];
          emxEnsureCapacity_real_T(&st, weights, b_r1, &u_emlrtRTEI);
          weights_data = weights->data;
          for (i = 0; i < r2; i++) {
            weights_data[i] = members_data[i];
          }
          st.site = &nc_emlrtRSI;
          repmat(&st, a21, r);
          r1 = r->data;
          b_r1 = mapOut->size[0] * mapOut->size[1];
          mapOut->size[0] = 1;
          loop_ub = r->size[1];
          mapOut->size[1] = r->size[1];
          emxEnsureCapacity_struct0_T(sp, mapOut, b_r1, &bb_emlrtRTEI);
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
                                            &xd_emlrtBCI, (emlrtConstCTX)sp);
            }
            loop_ub = (int32_T)weights_data[i];
            if ((loop_ub < 1) || (loop_ub > c_loop_ub)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, c_loop_ub, &wd_emlrtBCI,
                                            (emlrtConstCTX)sp);
            }
            if (((int32_T)((uint32_T)i + 1U) < 1) ||
                ((int32_T)((uint32_T)i + 1U) > mapOut->size[1])) {
              emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)i + 1U), 1,
                                            mapOut->size[1], &yd_emlrtBCI,
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
  real_T Rstack_data[128];
  real_T Z_data[64];
  real_T PBase[9];
  int32_T Rstack_size[3];
  int32_T Z_size[2];
  int32_T a__1_size[2];
  int32_T birthIdx_size[2];
  int32_T visMap_size[2];
  int32_T i;
  int32_T i1;
  int32_T iter;
  boolean_T birthIdx_data[32];
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
    real_T b_xk[3];
    st.site = &c_emlrtRSI;
    split_map_by_fov_local(&st, xk, mapIn_data, mapIn_size, params->fov_range,
                           params->fov_angle, a__1_data, a__1_size, visMap_data,
                           visMap_size);
    for (i1 = 0; i1 < 3; i1++) {
      b_xk[i1] = xk[i1];
    }
    st.site = &d_emlrtRSI;
    pose_update_mm_local(&st, b_xk, PBase, visMap_data, visMap_size, Z_data,
                         Z_size, params->P_D, params->clutter_rate,
                         params->iter_max, params->PHD_det_keep,
                         params->PHD_miss_keep, Rstack_data, Rstack_size,
                         (real_T)iter + 1.0, xk, Pk);
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
                   params->map_miss_prune_threshold, Rstack_data, Rstack_size,
                   mapTmp, birthIdx_data, birthIdx_size);
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
                Rstack_data, Rstack_size, birthIdx_data, birthIdx_size, mapOut);
  }
  emxFree_struct0_T(sp, &b_mapTmp);
  st.site = &i_emlrtRSI;
  b_regularize_cov_local(&st, Pk);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (slam_step_codegen.c) */
