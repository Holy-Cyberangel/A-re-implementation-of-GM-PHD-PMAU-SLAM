/*
 * map_predict_types.h
 *
 * Code generation for function 'map_predict'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  real_T m[2];
  real_T P[4];
  real_T w;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  real_T xn_dim;
  real_T xl_dim;
  real_T u_dim;
  real_T h_dim;
  real_T Qn[9];
  real_T Qu[4];
  real_T R[4];
  real_T P_D;
  real_T lambda;
  real_T fov_range;
  real_T fov_angle;
  real_T T;
  real_T dt;
  real_T w_min;
  real_T birth_intensity;
  real_T clutter_rate;
  real_T prune_threshold;
  real_T max_components;
  real_T merge_threshold;
  real_T pHD_det_keep;
  real_T pHD_miss_keep;
  real_T map_detection_add_threshold;
  real_T map_miss_prune_threshold;
  real_T OSPA_p;
  real_T OSPA_c;
  real_T iter_pose_updates;
  real_T epsilon;
  real_T iter_max;
  real_T monte_carlo;
  real_T mon_carlo;
  real_T PHD_det_keep;
  real_T PHD_miss_keep;
  real_T GOSPA_p;
  real_T GOSPA_c;
} struct1_T;
#endif /* typedef_struct1_T */

/* End of code generation (map_predict_types.h) */
