/*
 * _coder_map_predict_api.c
 *
 * Code generation for function '_coder_map_predict_api'
 *
 */

/* Include files */
#include "_coder_map_predict_api.h"
#include "map_predict.h"
#include "map_predict_data.h"
#include "map_predict_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3];

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct0_T y_data[],
                               int32_T y_size[2]);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct0_T y_data[], int32_T y_size[2]);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2]);

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier))[3];

static const mxArray *emlrt_marshallOut(boolean_T u_data[],
                                        const int32_T u_size[2]);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[4]);

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct1_T *y);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct1_T *y);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9]);

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2]);

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[4]);

static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[9]);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct0_T y_data[],
                               int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y_data, y_size);
  emlrtDestroyArray(&nullptr);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct0_T y_data[], int32_T y_size[2])
{
  static const int32_T dims[2] = {1, 300};
  static const char_T *fieldNames[3] = {"m", "P", "w"};
  emlrtMsgIdentifier thisId;
  int32_T i;
  boolean_T bv[2] = {false, true};
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckVsStructR2012b((emlrtCTX)sp, parentId, u, 3,
                           (const char_T **)&fieldNames[0], 2U,
                           (const void *)&dims[0], &bv[0], &y_size[0]);
  for (i = 0; i < y_size[1]; i++) {
    thisId.fIdentifier = "m";
    e_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 0, "m")),
        &thisId, y_data[i].m);
    thisId.fIdentifier = "P";
    f_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 1, "P")),
        &thisId, y_data[i].P);
    thisId.fIdentifier = "w";
    y_data[i].w = g_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 2, "w")),
        &thisId);
  }
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2])
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[3];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static const mxArray *emlrt_marshallOut(boolean_T u_data[],
                                        const int32_T u_size[2])
{
  static const int32_T iv[2] = {0, 0};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateLogicalArray(2, &iv[0]);
  emlrtMxSetData((mxArray *)m, &u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u_size[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[4])
{
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = n_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  i_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct1_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[34] = {"xn_dim",
                                         "xl_dim",
                                         "u_dim",
                                         "h_dim",
                                         "Qn",
                                         "Qu",
                                         "R",
                                         "P_D",
                                         "lambda",
                                         "fov_range",
                                         "fov_angle",
                                         "T",
                                         "dt",
                                         "w_min",
                                         "birth_intensity",
                                         "clutter_rate",
                                         "prune_threshold",
                                         "max_components",
                                         "merge_threshold",
                                         "pHD_det_keep",
                                         "pHD_miss_keep",
                                         "map_detection_add_threshold",
                                         "map_miss_prune_threshold",
                                         "OSPA_p",
                                         "OSPA_c",
                                         "iter_pose_updates",
                                         "epsilon",
                                         "iter_max",
                                         "monte_carlo",
                                         "mon_carlo",
                                         "PHD_det_keep",
                                         "PHD_miss_keep",
                                         "GOSPA_p",
                                         "GOSPA_c"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 34,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "xn_dim";
  y->xn_dim = g_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "xn_dim")),
      &thisId);
  thisId.fIdentifier = "xl_dim";
  y->xl_dim = g_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "xl_dim")),
      &thisId);
  thisId.fIdentifier = "u_dim";
  y->u_dim = g_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "u_dim")),
      &thisId);
  thisId.fIdentifier = "h_dim";
  y->h_dim = g_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3, "h_dim")),
      &thisId);
  thisId.fIdentifier = "Qn";
  j_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 4, "Qn")),
      &thisId, y->Qn);
  thisId.fIdentifier = "Qu";
  f_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 5, "Qu")),
      &thisId, y->Qu);
  thisId.fIdentifier = "R";
  f_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 6, "R")),
      &thisId, y->R);
  thisId.fIdentifier = "P_D";
  y->P_D = g_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 7, "P_D")),
      &thisId);
  thisId.fIdentifier = "lambda";
  y->lambda = g_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 8, "lambda")),
      &thisId);
  thisId.fIdentifier = "fov_range";
  y->fov_range = g_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 9, "fov_range")),
      &thisId);
  thisId.fIdentifier = "fov_angle";
  y->fov_angle = g_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 10, "fov_angle")),
      &thisId);
  thisId.fIdentifier = "T";
  y->T = g_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 11, "T")),
      &thisId);
  thisId.fIdentifier = "dt";
  y->dt = g_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 12, "dt")),
      &thisId);
  thisId.fIdentifier = "w_min";
  y->w_min = g_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 13, "w_min")),
      &thisId);
  thisId.fIdentifier = "birth_intensity";
  y->birth_intensity =
      g_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        14, "birth_intensity")),
                         &thisId);
  thisId.fIdentifier = "clutter_rate";
  y->clutter_rate =
      g_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        15, "clutter_rate")),
                         &thisId);
  thisId.fIdentifier = "prune_threshold";
  y->prune_threshold =
      g_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        16, "prune_threshold")),
                         &thisId);
  thisId.fIdentifier = "max_components";
  y->max_components =
      g_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        17, "max_components")),
                         &thisId);
  thisId.fIdentifier = "merge_threshold";
  y->merge_threshold =
      g_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        18, "merge_threshold")),
                         &thisId);
  thisId.fIdentifier = "pHD_det_keep";
  y->pHD_det_keep =
      g_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        19, "pHD_det_keep")),
                         &thisId);
  thisId.fIdentifier = "pHD_miss_keep";
  y->pHD_miss_keep =
      g_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        20, "pHD_miss_keep")),
                         &thisId);
  thisId.fIdentifier = "map_detection_add_threshold";
  y->map_detection_add_threshold = g_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 21,
                                     "map_detection_add_threshold")),
      &thisId);
  thisId.fIdentifier = "map_miss_prune_threshold";
  y->map_miss_prune_threshold = g_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 22,
                                     "map_miss_prune_threshold")),
      &thisId);
  thisId.fIdentifier = "OSPA_p";
  y->OSPA_p = g_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 23, "OSPA_p")),
      &thisId);
  thisId.fIdentifier = "OSPA_c";
  y->OSPA_c = g_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 24, "OSPA_c")),
      &thisId);
  thisId.fIdentifier = "iter_pose_updates";
  y->iter_pose_updates =
      g_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtConstCTX)sp, u, 0, 25, "iter_pose_updates")),
                         &thisId);
  thisId.fIdentifier = "epsilon";
  y->epsilon = g_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 26, "epsilon")),
      &thisId);
  thisId.fIdentifier = "iter_max";
  y->iter_max = g_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 27, "iter_max")),
      &thisId);
  thisId.fIdentifier = "monte_carlo";
  y->monte_carlo =
      g_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        28, "monte_carlo")),
                         &thisId);
  thisId.fIdentifier = "mon_carlo";
  y->mon_carlo = g_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 29, "mon_carlo")),
      &thisId);
  thisId.fIdentifier = "PHD_det_keep";
  y->PHD_det_keep =
      g_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        30, "PHD_det_keep")),
                         &thisId);
  thisId.fIdentifier = "PHD_miss_keep";
  y->PHD_miss_keep =
      g_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        31, "PHD_miss_keep")),
                         &thisId);
  thisId.fIdentifier = "GOSPA_p";
  y->GOSPA_p = g_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 32, "GOSPA_p")),
      &thisId);
  thisId.fIdentifier = "GOSPA_c";
  y->GOSPA_c = g_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 33, "GOSPA_c")),
      &thisId);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9])
{
  o_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3]
{
  static const int32_T dims = 3;
  real_T(*ret)[3];
  int32_T i;
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims = 2;
  real_T(*r)[2];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                          (const void *)&dims);
  r = (real_T(*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[4])
{
  static const int32_T dims[2] = {2, 2};
  real_T(*r)[4];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[4])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  ret[3] = (*r)[3];
  emlrtDestroyArray(&src);
}

static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[9])
{
  static const int32_T dims[2] = {3, 3};
  real_T(*r)[9];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[9])emlrtMxGetData(src);
  for (i = 0; i < 9; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

void map_predict_api(const mxArray *const prhs[3], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  struct0_T map_data[300];
  struct1_T params;
  real_T(*x_)[3];
  int32_T idx_size[2];
  int32_T map_size[2];
  boolean_T(*idx_data)[300];
  st.tls = emlrtRootTLSGlobal;
  idx_data = (boolean_T(*)[300])mxMalloc(sizeof(boolean_T[300]));
  /* Marshall function inputs */
  x_ = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "x_");
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "map", map_data, map_size);
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "params", &params);
  /* Invoke the target function */
  map_predict(&st, *x_, map_data, map_size, &params, *idx_data, idx_size);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(*idx_data, idx_size);
}

/* End of code generation (_coder_map_predict_api.c) */
