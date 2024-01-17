// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Core>

#include <sym/pose3.h>

namespace sym {

/**
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: pose_inverse
 *
 * Args:
 *     pose: Pose3
 *
 * Outputs:
 *     res: Pose3
 *     res_D_pose: (6x6) jacobian of res (6) wrt arg pose (6)
 */
template <typename Scalar>
__attribute__((noinline)) sym::Pose3<Scalar> PoseInverseWithJacobian(
    const sym::Pose3<Scalar>& pose, Eigen::Matrix<Scalar, 6, 6>* const res_D_pose = nullptr) {
  // Total ops: 75

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _pose = pose.Data();

  // Intermediate terms (40)
  const Scalar _tmp0 = 2 * _pose[1];
  const Scalar _tmp1 = _pose[3] * _tmp0;
  const Scalar _tmp2 = 2 * _pose[2];
  const Scalar _tmp3 = _pose[0] * _tmp2;
  const Scalar _tmp4 = _tmp1 - _tmp3;
  const Scalar _tmp5 = _pose[3] * _tmp2;
  const Scalar _tmp6 = _pose[0] * _tmp0;
  const Scalar _tmp7 = _tmp5 + _tmp6;
  const Scalar _tmp8 = _pose[5] * _tmp7;
  const Scalar _tmp9 = std::pow(_pose[1], Scalar(2));
  const Scalar _tmp10 = 2 * _tmp9;
  const Scalar _tmp11 = std::pow(_pose[2], Scalar(2));
  const Scalar _tmp12 = 2 * _tmp11 - 1;
  const Scalar _tmp13 = _tmp10 + _tmp12;
  const Scalar _tmp14 = _tmp5 - _tmp6;
  const Scalar _tmp15 = _pose[4] * _tmp14;
  const Scalar _tmp16 = 2 * _pose[0] * _pose[3];
  const Scalar _tmp17 = _pose[1] * _tmp2;
  const Scalar _tmp18 = _tmp16 + _tmp17;
  const Scalar _tmp19 = _pose[6] * _tmp18;
  const Scalar _tmp20 = std::pow(_pose[0], Scalar(2));
  const Scalar _tmp21 = 2 * _tmp20;
  const Scalar _tmp22 = _tmp12 + _tmp21;
  const Scalar _tmp23 = _tmp16 - _tmp17;
  const Scalar _tmp24 = _tmp1 + _tmp3;
  const Scalar _tmp25 = _pose[4] * _tmp24;
  const Scalar _tmp26 = _tmp10 + _tmp21 - 1;
  const Scalar _tmp27 = -_tmp11;
  const Scalar _tmp28 = std::pow(_pose[3], Scalar(2));
  const Scalar _tmp29 = _tmp28 - _tmp9;
  const Scalar _tmp30 = _tmp20 + _tmp27 + _tmp29;
  const Scalar _tmp31 = -_tmp7;
  const Scalar _tmp32 = -_tmp20;
  const Scalar _tmp33 = _tmp11 + _tmp29 + _tmp32;
  const Scalar _tmp34 = -_pose[5] * _tmp23 + _pose[6] * _tmp33 + _tmp25;
  const Scalar _tmp35 = _tmp27 + _tmp28 + _tmp32 + _tmp9;
  const Scalar _tmp36 = _pose[5] * _tmp35 - _tmp15 + _tmp19;
  const Scalar _tmp37 = -_tmp18;
  const Scalar _tmp38 = _pose[4] * _tmp30 - _pose[6] * _tmp4 + _tmp8;
  const Scalar _tmp39 = -_tmp24;

  // Output terms (2)
  Eigen::Matrix<Scalar, 7, 1> _res;

  _res[0] = -_pose[0];
  _res[1] = -_pose[1];
  _res[2] = -_pose[2];
  _res[3] = _pose[3];
  _res[4] = _pose[4] * _tmp13 + _pose[6] * _tmp4 - _tmp8;
  _res[5] = _pose[5] * _tmp22 + _tmp15 - _tmp19;
  _res[6] = _pose[5] * _tmp23 + _pose[6] * _tmp26 - _tmp25;

  if (res_D_pose != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _res_D_pose = (*res_D_pose);

    _res_D_pose(0, 0) = -_tmp30;
    _res_D_pose(1, 0) = _tmp31;
    _res_D_pose(2, 0) = _tmp4;
    _res_D_pose(3, 0) = 0;
    _res_D_pose(4, 0) = -_tmp34;
    _res_D_pose(5, 0) = _tmp36;
    _res_D_pose(0, 1) = _tmp14;
    _res_D_pose(1, 1) = -_tmp35;
    _res_D_pose(2, 1) = _tmp37;
    _res_D_pose(3, 1) = _tmp34;
    _res_D_pose(4, 1) = 0;
    _res_D_pose(5, 1) = -_tmp38;
    _res_D_pose(0, 2) = _tmp39;
    _res_D_pose(1, 2) = _tmp23;
    _res_D_pose(2, 2) = -_tmp33;
    _res_D_pose(3, 2) = -_tmp36;
    _res_D_pose(4, 2) = _tmp38;
    _res_D_pose(5, 2) = 0;
    _res_D_pose(0, 3) = 0;
    _res_D_pose(1, 3) = 0;
    _res_D_pose(2, 3) = 0;
    _res_D_pose(3, 3) = _tmp13;
    _res_D_pose(4, 3) = _tmp14;
    _res_D_pose(5, 3) = _tmp39;
    _res_D_pose(0, 4) = 0;
    _res_D_pose(1, 4) = 0;
    _res_D_pose(2, 4) = 0;
    _res_D_pose(3, 4) = _tmp31;
    _res_D_pose(4, 4) = _tmp22;
    _res_D_pose(5, 4) = _tmp23;
    _res_D_pose(0, 5) = 0;
    _res_D_pose(1, 5) = 0;
    _res_D_pose(2, 5) = 0;
    _res_D_pose(3, 5) = _tmp4;
    _res_D_pose(4, 5) = _tmp37;
    _res_D_pose(5, 5) = _tmp26;
  }

  return sym::Pose3<Scalar>(_res);
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
