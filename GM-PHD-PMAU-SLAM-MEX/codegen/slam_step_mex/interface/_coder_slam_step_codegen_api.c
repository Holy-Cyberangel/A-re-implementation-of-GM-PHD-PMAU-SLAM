/*
 * _coder_slam_step_codegen_api.c
 *
 * Code generation for function '_coder_slam_step_codegen_api'
 *
 */

/* Include files */
#include "_coder_slam_step_codegen_api.h"
#include "rt_nonfinite.h"
#include "slam_step_codegen.h"
#include "slam_step_codegen_data.h"
#include "slam_step_codegen_emxutil.h"
#include "slam_step_codegen_types.h"

/* Variable Definitions */
static emlrtRTEInfo fb_emlrtRTEI = {
    1,                              /* lineNo */
    1,                              /* colNo */
    "_coder_slam_step_codegen_api", /* fName */
    ""                              /* pName */
};

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[4]);

static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3];

static const mxArray *b_emlrt_marshallOut(real_T u[9]);

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[9]);

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[9];

static const mxArray *c_emlrt_marshallOut(const emxArray_struct0_T *u);

static boolean_T cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                     const emlrtMsgIdentifier *msgId);

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[9];

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[2];

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier))[3];

static const mxArray *emlrt_marshallOut(real_T u[3]);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2];

static real_T *g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                  const char_T *identifier, int32_T y_size[2]);

static real_T *h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  int32_T y_size[2]);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct0_T y_data[],
                               int32_T y_size[2]);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct0_T y_data[], int32_T y_size[2]);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2]);

static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[4]);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct1_T *y);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct1_T *y);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9]);

static real_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier);

static boolean_T r_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *nullptr,
                                    const char_T *identifier);

static boolean_T s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

static real_T (*u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[9];

static real_T (*v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2];

static real_T *w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2]);

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2]);

static real_T y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = t_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *b_emlrt_marshallOut(real_T u[9])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {3, 3};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[9]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[9];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const emxArray_struct0_T *u)
{
  static const int32_T iv1[2] = {2, 2};
  static const int32_T b_i = 2;
  static const char_T *sv[3] = {"m", "w", "P"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *m;
  const mxArray *y;
  const struct0_T *u_data;
  real_T *pData;
  int32_T iv[2];
  int32_T b_j1;
  int32_T i;
  u_data = u->data;
  y = NULL;
  iv[0] = 1;
  iv[1] = u->size[1];
  emlrtAssign(&y,
              emlrtCreateStructArray(2, &iv[0], 3, (const char_T **)&sv[0]));
  emlrtCreateField(y, "m");
  emlrtCreateField(y, "w");
  emlrtCreateField(y, "P");
  i = 0;
  for (b_j1 = 0; b_j1 < u->size[1U]; b_j1++) {
    b_y = NULL;
    m = emlrtCreateNumericArray(1, (const void *)&b_i, mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m);
    pData[0] = u_data[b_j1].m[0];
    pData[1] = u_data[b_j1].m[1];
    emlrtAssign(&b_y, m);
    emlrtSetFieldR2017b(y, i, "m", b_y, 0);
    c_y = NULL;
    m = emlrtCreateDoubleScalar(u_data[b_j1].w);
    emlrtAssign(&c_y, m);
    emlrtSetFieldR2017b(y, i, "w", c_y, 1);
    d_y = NULL;
    m = emlrtCreateNumericArray(2, (const void *)&iv1[0], mxDOUBLE_CLASS,
                                mxREAL);
    pData = emlrtMxGetPr(m);
    pData[0] = u_data[b_j1].P[0];
    pData[1] = u_data[b_j1].P[1];
    pData[2] = u_data[b_j1].P[2];
    pData[3] = u_data[b_j1].P[3];
    emlrtAssign(&d_y, m);
    emlrtSetFieldR2017b(y, i, "P", d_y, 2);
    i++;
  }
  return y;
}

static boolean_T cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                     const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  boolean_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "logical", false, 0U,
                          (const void *)&dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[9]
{
  real_T(*y)[9];
  y = u_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
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

static const mxArray *emlrt_marshallOut(real_T u[3])
{
  static const int32_T i = 0;
  static const int32_T i1 = 3;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2]
{
  real_T(*y)[2];
  y = v_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T *g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                  const char_T *identifier, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *y_data;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y_data = h_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y_size);
  emlrtDestroyArray(&nullptr);
  return y_data;
}

static real_T *h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  int32_T y_size[2])
{
  real_T *y_data;
  y_data = w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_size);
  emlrtDestroyArray(&u);
  return y_data;
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct0_T y_data[],
                               int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y_data, y_size);
  emlrtDestroyArray(&nullptr);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct0_T y_data[], int32_T y_size[2])
{
  static const int32_T dims[2] = {1, 512};
  static const char_T *fieldNames[3] = {"m", "w", "P"};
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
    k_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 0, "m")),
        &thisId, y_data[i].m);
    thisId.fIdentifier = "w";
    y_data[i].w = l_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 1, "w")),
        &thisId);
    thisId.fIdentifier = "P";
    m_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 2, "P")),
        &thisId, y_data[i].P);
  }
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2])
{
  x_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = y_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[4])
{
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  o_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
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
  y->xn_dim = l_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "xn_dim")),
      &thisId);
  thisId.fIdentifier = "xl_dim";
  y->xl_dim = l_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "xl_dim")),
      &thisId);
  thisId.fIdentifier = "u_dim";
  y->u_dim = l_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "u_dim")),
      &thisId);
  thisId.fIdentifier = "h_dim";
  y->h_dim = l_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3, "h_dim")),
      &thisId);
  thisId.fIdentifier = "Qn";
  p_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 4, "Qn")),
      &thisId, y->Qn);
  thisId.fIdentifier = "Qu";
  m_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 5, "Qu")),
      &thisId, y->Qu);
  thisId.fIdentifier = "R";
  m_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 6, "R")),
      &thisId, y->R);
  thisId.fIdentifier = "P_D";
  y->P_D = l_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 7, "P_D")),
      &thisId);
  thisId.fIdentifier = "lambda";
  y->lambda = l_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 8, "lambda")),
      &thisId);
  thisId.fIdentifier = "fov_range";
  y->fov_range = l_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 9, "fov_range")),
      &thisId);
  thisId.fIdentifier = "fov_angle";
  y->fov_angle = l_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 10, "fov_angle")),
      &thisId);
  thisId.fIdentifier = "T";
  y->T = l_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 11, "T")),
      &thisId);
  thisId.fIdentifier = "dt";
  y->dt = l_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 12, "dt")),
      &thisId);
  thisId.fIdentifier = "w_min";
  y->w_min = l_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 13, "w_min")),
      &thisId);
  thisId.fIdentifier = "birth_intensity";
  y->birth_intensity =
      l_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        14, "birth_intensity")),
                         &thisId);
  thisId.fIdentifier = "clutter_rate";
  y->clutter_rate =
      l_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        15, "clutter_rate")),
                         &thisId);
  thisId.fIdentifier = "prune_threshold";
  y->prune_threshold =
      l_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        16, "prune_threshold")),
                         &thisId);
  thisId.fIdentifier = "max_components";
  y->max_components =
      l_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        17, "max_components")),
                         &thisId);
  thisId.fIdentifier = "merge_threshold";
  y->merge_threshold =
      l_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        18, "merge_threshold")),
                         &thisId);
  thisId.fIdentifier = "pHD_det_keep";
  y->pHD_det_keep =
      l_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        19, "pHD_det_keep")),
                         &thisId);
  thisId.fIdentifier = "pHD_miss_keep";
  y->pHD_miss_keep =
      l_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        20, "pHD_miss_keep")),
                         &thisId);
  thisId.fIdentifier = "map_detection_add_threshold";
  y->map_detection_add_threshold = l_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 21,
                                     "map_detection_add_threshold")),
      &thisId);
  thisId.fIdentifier = "map_miss_prune_threshold";
  y->map_miss_prune_threshold = l_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 22,
                                     "map_miss_prune_threshold")),
      &thisId);
  thisId.fIdentifier = "OSPA_p";
  y->OSPA_p = l_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 23, "OSPA_p")),
      &thisId);
  thisId.fIdentifier = "OSPA_c";
  y->OSPA_c = l_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 24, "OSPA_c")),
      &thisId);
  thisId.fIdentifier = "iter_pose_updates";
  y->iter_pose_updates =
      l_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtConstCTX)sp, u, 0, 25, "iter_pose_updates")),
                         &thisId);
  thisId.fIdentifier = "epsilon";
  y->epsilon = l_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 26, "epsilon")),
      &thisId);
  thisId.fIdentifier = "iter_max";
  y->iter_max = l_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 27, "iter_max")),
      &thisId);
  thisId.fIdentifier = "monte_carlo";
  y->monte_carlo =
      l_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        28, "monte_carlo")),
                         &thisId);
  thisId.fIdentifier = "mon_carlo";
  y->mon_carlo = l_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 29, "mon_carlo")),
      &thisId);
  thisId.fIdentifier = "PHD_det_keep";
  y->PHD_det_keep =
      l_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        30, "PHD_det_keep")),
                         &thisId);
  thisId.fIdentifier = "PHD_miss_keep";
  y->PHD_miss_keep =
      l_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        31, "PHD_miss_keep")),
                         &thisId);
  thisId.fIdentifier = "GOSPA_p";
  y->GOSPA_p = l_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 32, "GOSPA_p")),
      &thisId);
  thisId.fIdentifier = "GOSPA_c";
  y->GOSPA_c = l_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 33, "GOSPA_c")),
      &thisId);
  emlrtDestroyArray(&u);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9])
{
  bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = l_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static boolean_T r_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *nullptr,
                                    const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  boolean_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = s_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static boolean_T s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static real_T (*u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[9]
{
  static const int32_T dims[2] = {3, 3};
  real_T(*ret)[9];
  int32_T iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (real_T(*)[9])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims = 2;
  real_T(*ret)[2];
  int32_T i;
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T *w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2])
{
  static const int32_T dims[2] = {2, 32};
  real_T *ret_data;
  boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &ret_size[0]);
  ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret_data;
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static real_T y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

void slam_step_codegen_api(const mxArray *const prhs[8], int32_T nlhs,
                           const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_struct0_T *mapOut;
  struct0_T mapIn_data[512];
  struct1_T params;
  real_T(*curMea_data)[64];
  real_T(*PPrev)[9];
  real_T(*Pk)[9];
  real_T(*xPrev)[3];
  real_T(*xk)[3];
  real_T(*odom)[2];
  real_T T;
  int32_T curMea_size[2];
  int32_T mapIn_size[2];
  boolean_T isLastStep;
  st.tls = emlrtRootTLSGlobal;
  xk = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  Pk = (real_T(*)[9])mxMalloc(sizeof(real_T[9]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  xPrev = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "xPrev");
  PPrev = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "PPrev");
  odom = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "odom");
  *(real_T **)&curMea_data =
      g_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "curMea", curMea_size);
  i_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "mapIn", mapIn_data,
                     mapIn_size);
  n_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "params", &params);
  T = q_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "T");
  isLastStep = r_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "isLastStep");
  /* Invoke the target function */
  emxInit_struct0_T(&st, &mapOut, &fb_emlrtRTEI);
  slam_step_codegen(&st, *xPrev, *PPrev, *odom, *curMea_data, curMea_size,
                    mapIn_data, mapIn_size, &params, T, isLastStep, *xk, *Pk,
                    mapOut);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*xk);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(*Pk);
  }
  if (nlhs > 2) {
    plhs[2] = c_emlrt_marshallOut(mapOut);
  }
  emxFree_struct0_T(&st, &mapOut);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_slam_step_codegen_api.c) */
