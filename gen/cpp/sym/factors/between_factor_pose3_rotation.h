// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>

#include <sym/pose3.h>
#include <sym/rot3.h>

namespace sym {

/**
 * Residual that penalizes the difference between between(a, b) and a_R_b.
 *
 * In vector space terms that would be:
 *     (b - a) - a_R_b
 *
 * In lie group terms:
 *     local_coordinates(a_R_b, between(a, b))
 *     to_tangent(compose(inverse(a_R_b), compose(inverse(a), b)))
 *
 * Args:
 *     sqrt_info: Square root information matrix to whiten residual. This can be computed from
 *                a covariance matrix as the cholesky decomposition of the inverse. In the case
 *                of a diagonal it will contain 1/sigma values. Must match the tangent dim.
 *     jacobian: (3x12) jacobian of res wrt args a (6), b (6)
 *     hessian: (12x12) Gauss-Newton hessian for args a (6), b (6)
 *     rhs: (12x1) Gauss-Newton rhs for args a (6), b (6)
 */
template <typename Scalar>
void BetweenFactorPose3Rotation(const sym::Pose3<Scalar>& a, const sym::Pose3<Scalar>& b,
                                const sym::Rot3<Scalar>& a_R_b,
                                const Eigen::Matrix<Scalar, 3, 3>& sqrt_info, const Scalar epsilon,
                                Eigen::Matrix<Scalar, 3, 1>* const res = nullptr,
                                Eigen::Matrix<Scalar, 3, 12>* const jacobian = nullptr,
                                Eigen::Matrix<Scalar, 12, 12>* const hessian = nullptr,
                                Eigen::Matrix<Scalar, 12, 1>* const rhs = nullptr) {
  // Total ops: 742

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _b = b.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _a_R_b = a_R_b.Data();

  // Intermediate terms (209)
  const Scalar _tmp0 = _a[1] * _b[1];
  const Scalar _tmp1 = _a[2] * _b[2];
  const Scalar _tmp2 = _a[0] * _b[0];
  const Scalar _tmp3 = _a[3] * _b[3];
  const Scalar _tmp4 = _tmp0 + _tmp1 + _tmp2 + _tmp3;
  const Scalar _tmp5 = _a[2] * _b[1];
  const Scalar _tmp6 = _a[0] * _b[3];
  const Scalar _tmp7 = _a[1] * _b[2];
  const Scalar _tmp8 = _a[3] * _b[0];
  const Scalar _tmp9 = _tmp5 - _tmp6 - _tmp7 + _tmp8;
  const Scalar _tmp10 = _a[3] * _b[1];
  const Scalar _tmp11 = _a[1] * _b[3];
  const Scalar _tmp12 = _a[0] * _b[2];
  const Scalar _tmp13 = _a[2] * _b[0];
  const Scalar _tmp14 = _tmp10 - _tmp11 + _tmp12 - _tmp13;
  const Scalar _tmp15 = _a[0] * _b[1];
  const Scalar _tmp16 = _a[2] * _b[3];
  const Scalar _tmp17 = _a[3] * _b[2];
  const Scalar _tmp18 = _a[1] * _b[0];
  const Scalar _tmp19 = -_tmp15 - _tmp16 + _tmp17 + _tmp18;
  const Scalar _tmp20 =
      -_a_R_b[0] * _tmp4 - _a_R_b[1] * _tmp19 + _a_R_b[2] * _tmp14 + _a_R_b[3] * _tmp9;
  const Scalar _tmp21 = 1 - epsilon;
  const Scalar _tmp22 = _a_R_b[0] * _tmp9;
  const Scalar _tmp23 = _a_R_b[1] * _tmp14;
  const Scalar _tmp24 = _a_R_b[2] * _tmp19;
  const Scalar _tmp25 = -_tmp22 - _tmp23 - _tmp24;
  const Scalar _tmp26 = _a_R_b[3] * _tmp4;
  const Scalar _tmp27 = std::min<Scalar>(_tmp21, std::fabs(_tmp25 - _tmp26));
  const Scalar _tmp28 =
      std::pow(Scalar(1 - std::pow(_tmp27, Scalar(2))), Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp29 = std::acos(_tmp27);
  const Scalar _tmp30 =
      2 * std::min<Scalar>(0, (((-_tmp25 + _tmp26) > 0) - ((-_tmp25 + _tmp26) < 0))) + 1;
  const Scalar _tmp31 = 2 * _tmp30;
  const Scalar _tmp32 = _tmp28 * _tmp29 * _tmp31;
  const Scalar _tmp33 = _tmp20 * _tmp32;
  const Scalar _tmp34 =
      -_a_R_b[0] * _tmp14 + _a_R_b[1] * _tmp9 - _a_R_b[2] * _tmp4 + _a_R_b[3] * _tmp19;
  const Scalar _tmp35 = _tmp34 * sqrt_info(0, 2);
  const Scalar _tmp36 =
      _a_R_b[0] * _tmp19 - _a_R_b[1] * _tmp4 - _a_R_b[2] * _tmp9 + _a_R_b[3] * _tmp14;
  const Scalar _tmp37 = _tmp32 * _tmp36;
  const Scalar _tmp38 = _tmp32 * _tmp35 + _tmp33 * sqrt_info(0, 0) + _tmp37 * sqrt_info(0, 1);
  const Scalar _tmp39 = _tmp34 * sqrt_info(1, 2);
  const Scalar _tmp40 = _tmp32 * _tmp39 + _tmp33 * sqrt_info(1, 0) + _tmp37 * sqrt_info(1, 1);
  const Scalar _tmp41 = _tmp31 * sqrt_info(2, 2);
  const Scalar _tmp42 =
      _tmp28 * _tmp29 * _tmp34 * _tmp41 + _tmp33 * sqrt_info(2, 0) + _tmp37 * sqrt_info(2, 1);
  const Scalar _tmp43 = (Scalar(1) / Scalar(2)) * _tmp0;
  const Scalar _tmp44 = (Scalar(1) / Scalar(2)) * _tmp3;
  const Scalar _tmp45 = (Scalar(1) / Scalar(2)) * _tmp1;
  const Scalar _tmp46 = (Scalar(1) / Scalar(2)) * _tmp2;
  const Scalar _tmp47 = -_tmp43 - _tmp44 - _tmp45 - _tmp46;
  const Scalar _tmp48 = _a_R_b[1] * _tmp47;
  const Scalar _tmp49 = (Scalar(1) / Scalar(2)) * _tmp15;
  const Scalar _tmp50 = (Scalar(1) / Scalar(2)) * _tmp16;
  const Scalar _tmp51 = (Scalar(1) / Scalar(2)) * _tmp17;
  const Scalar _tmp52 = (Scalar(1) / Scalar(2)) * _tmp18;
  const Scalar _tmp53 = -_tmp49 - _tmp50 + _tmp51 + _tmp52;
  const Scalar _tmp54 = -_a_R_b[0] * _tmp53;
  const Scalar _tmp55 = (Scalar(1) / Scalar(2)) * _tmp5;
  const Scalar _tmp56 = (Scalar(1) / Scalar(2)) * _tmp6;
  const Scalar _tmp57 = (Scalar(1) / Scalar(2)) * _tmp7;
  const Scalar _tmp58 = (Scalar(1) / Scalar(2)) * _tmp8;
  const Scalar _tmp59 = _tmp55 - _tmp56 - _tmp57 + _tmp58;
  const Scalar _tmp60 = _a_R_b[2] * _tmp59;
  const Scalar _tmp61 = (Scalar(1) / Scalar(2)) * _tmp10;
  const Scalar _tmp62 = (Scalar(1) / Scalar(2)) * _tmp11;
  const Scalar _tmp63 = (Scalar(1) / Scalar(2)) * _tmp12;
  const Scalar _tmp64 = (Scalar(1) / Scalar(2)) * _tmp13;
  const Scalar _tmp65 = -_tmp61 + _tmp62 - _tmp63 + _tmp64;
  const Scalar _tmp66 = _a_R_b[3] * _tmp65;
  const Scalar _tmp67 = _tmp48 + _tmp54 - _tmp60 + _tmp66;
  const Scalar _tmp68 = _tmp22 + _tmp23 + _tmp24 + _tmp26;
  const Scalar _tmp69 = std::fabs(_tmp68);
  const Scalar _tmp70 = std::min<Scalar>(_tmp21, _tmp69);
  const Scalar _tmp71 = 1 - std::pow(_tmp70, Scalar(2));
  const Scalar _tmp72 = std::acos(_tmp70);
  const Scalar _tmp73 = _tmp72 / std::sqrt(_tmp71);
  const Scalar _tmp74 = _tmp31 * _tmp73;
  const Scalar _tmp75 = _tmp67 * _tmp74;
  const Scalar _tmp76 = -_a_R_b[1] * _tmp59;
  const Scalar _tmp77 = _a_R_b[2] * _tmp47;
  const Scalar _tmp78 = _a_R_b[3] * _tmp53;
  const Scalar _tmp79 = _a_R_b[0] * _tmp65;
  const Scalar _tmp80 = _tmp78 + _tmp79;
  const Scalar _tmp81 = _tmp76 - _tmp77 + _tmp80;
  const Scalar _tmp82 = _tmp74 * _tmp81;
  const Scalar _tmp83 = _a_R_b[3] * _tmp47;
  const Scalar _tmp84 = _a_R_b[0] * _tmp59;
  const Scalar _tmp85 = _a_R_b[2] * _tmp53;
  const Scalar _tmp86 = -_a_R_b[1] * _tmp65;
  const Scalar _tmp87 = _tmp85 + _tmp86;
  const Scalar _tmp88 = _tmp83 - _tmp84 + _tmp87;
  const Scalar _tmp89 = _tmp74 * sqrt_info(0, 0);
  const Scalar _tmp90 = _tmp36 * sqrt_info(0, 1);
  const Scalar _tmp91 = _a_R_b[3] * _tmp59;
  const Scalar _tmp92 = _a_R_b[0] * _tmp47;
  const Scalar _tmp93 = _a_R_b[1] * _tmp53;
  const Scalar _tmp94 = _a_R_b[2] * _tmp65;
  const Scalar _tmp95 = _tmp93 + _tmp94;
  const Scalar _tmp96 = _tmp91 + _tmp92 + _tmp95;
  const Scalar _tmp97 = _tmp30 * ((((_tmp21 - _tmp69) > 0) - ((_tmp21 - _tmp69) < 0)) + 1) *
                        (((_tmp68) > 0) - ((_tmp68) < 0));
  const Scalar _tmp98 = _tmp97 / _tmp71;
  const Scalar _tmp99 = _tmp96 * _tmp98;
  const Scalar _tmp100 = _tmp35 * _tmp98;
  const Scalar _tmp101 = _tmp20 * _tmp98;
  const Scalar _tmp102 = _tmp101 * sqrt_info(0, 0);
  const Scalar _tmp103 = _tmp70 * _tmp72 * _tmp97 / (_tmp71 * std::sqrt(_tmp71));
  const Scalar _tmp104 = _tmp20 * sqrt_info(0, 0);
  const Scalar _tmp105 = _tmp103 * _tmp104;
  const Scalar _tmp106 = _tmp103 * _tmp96;
  const Scalar _tmp107 = -_tmp100 * _tmp96 - _tmp102 * _tmp96 + _tmp105 * _tmp96 +
                         _tmp106 * _tmp35 + _tmp106 * _tmp90 + _tmp75 * sqrt_info(0, 2) +
                         _tmp82 * sqrt_info(0, 1) + _tmp88 * _tmp89 - _tmp90 * _tmp99;
  const Scalar _tmp108 = _tmp61 - _tmp62 + _tmp63 - _tmp64;
  const Scalar _tmp109 = _a_R_b[0] * _tmp108;
  const Scalar _tmp110 = _tmp49 + _tmp50 - _tmp51 - _tmp52;
  const Scalar _tmp111 = _a_R_b[3] * _tmp110;
  const Scalar _tmp112 = _tmp111 + _tmp76;
  const Scalar _tmp113 = -_tmp109 + _tmp112 + _tmp77;
  const Scalar _tmp114 = _a_R_b[3] * _tmp108;
  const Scalar _tmp115 = _a_R_b[0] * _tmp110;
  const Scalar _tmp116 = _tmp115 + _tmp60;
  const Scalar _tmp117 = _tmp114 + _tmp116 + _tmp48;
  const Scalar _tmp118 = _tmp117 * _tmp98;
  const Scalar _tmp119 = _tmp118 * _tmp36;
  const Scalar _tmp120 = _tmp101 * _tmp117;
  const Scalar _tmp121 = _a_R_b[1] * _tmp108;
  const Scalar _tmp122 = -_a_R_b[2] * _tmp110;
  const Scalar _tmp123 = _tmp122 + _tmp84;
  const Scalar _tmp124 = -_tmp121 + _tmp123 + _tmp83;
  const Scalar _tmp125 = _tmp124 * _tmp74;
  const Scalar _tmp126 = -_a_R_b[2] * _tmp108;
  const Scalar _tmp127 = _a_R_b[1] * _tmp110;
  const Scalar _tmp128 = _tmp127 + _tmp91;
  const Scalar _tmp129 = _tmp126 + _tmp128 - _tmp92;
  const Scalar _tmp130 = _tmp74 * sqrt_info(0, 2);
  const Scalar _tmp131 = _tmp103 * _tmp117;
  const Scalar _tmp132 = _tmp131 * _tmp20;
  const Scalar _tmp133 = -_tmp100 * _tmp117 + _tmp113 * _tmp89 - _tmp119 * sqrt_info(0, 1) -
                         _tmp120 * sqrt_info(0, 0) + _tmp125 * sqrt_info(0, 1) + _tmp129 * _tmp130 +
                         _tmp131 * _tmp35 + _tmp131 * _tmp90 + _tmp132 * sqrt_info(0, 0);
  const Scalar _tmp134 = -_tmp55 + _tmp56 + _tmp57 - _tmp58;
  const Scalar _tmp135 = _a_R_b[2] * _tmp134;
  const Scalar _tmp136 = _tmp114 + _tmp135;
  const Scalar _tmp137 = _tmp136 - _tmp48 + _tmp54;
  const Scalar _tmp138 = _a_R_b[3] * _tmp134;
  const Scalar _tmp139 = _tmp126 + _tmp138 + _tmp92 - _tmp93;
  const Scalar _tmp140 = _tmp139 * _tmp74;
  const Scalar _tmp141 = _a_R_b[1] * _tmp134;
  const Scalar _tmp142 = _tmp109 + _tmp141;
  const Scalar _tmp143 = _tmp142 + _tmp77 + _tmp78;
  const Scalar _tmp144 = _tmp103 * _tmp143;
  const Scalar _tmp145 = -_a_R_b[0] * _tmp134;
  const Scalar _tmp146 = _tmp121 + _tmp145;
  const Scalar _tmp147 = _tmp146 + _tmp83 - _tmp85;
  const Scalar _tmp148 = _tmp143 * _tmp98;
  const Scalar _tmp149 = -_tmp100 * _tmp143 - _tmp102 * _tmp143 + _tmp104 * _tmp144 +
                         _tmp130 * _tmp147 + _tmp137 * _tmp89 + _tmp140 * sqrt_info(0, 1) +
                         _tmp144 * _tmp35 + _tmp144 * _tmp90 - _tmp148 * _tmp90;
  const Scalar _tmp150 = _tmp43 + _tmp44 + _tmp45 + _tmp46;
  const Scalar _tmp151 = _a_R_b[0] * _tmp150;
  const Scalar _tmp152 = _tmp138 + _tmp151;
  const Scalar _tmp153 = _tmp152 + _tmp95;
  const Scalar _tmp154 = _tmp153 * _tmp98;
  const Scalar _tmp155 = _tmp154 * _tmp36;
  const Scalar _tmp156 = _tmp101 * _tmp153;
  const Scalar _tmp157 = _a_R_b[1] * _tmp150;
  const Scalar _tmp158 = _tmp157 + _tmp66;
  const Scalar _tmp159 = -_tmp135 + _tmp158 + _tmp54;
  const Scalar _tmp160 = _a_R_b[3] * _tmp150;
  const Scalar _tmp161 = _tmp145 + _tmp160 + _tmp87;
  const Scalar _tmp162 = _a_R_b[2] * _tmp150;
  const Scalar _tmp163 = -_tmp141 - _tmp162 + _tmp80;
  const Scalar _tmp164 = _tmp163 * _tmp74;
  const Scalar _tmp165 = _tmp103 * _tmp153;
  const Scalar _tmp166 = -_tmp100 * _tmp153 + _tmp105 * _tmp153 + _tmp130 * _tmp159 -
                         _tmp155 * sqrt_info(0, 1) - _tmp156 * sqrt_info(0, 0) + _tmp161 * _tmp89 +
                         _tmp164 * sqrt_info(0, 1) + _tmp165 * _tmp35 + _tmp165 * _tmp90;
  const Scalar _tmp167 = _tmp112 + _tmp162 - _tmp79;
  const Scalar _tmp168 = _tmp116 + _tmp158;
  const Scalar _tmp169 = _tmp168 * _tmp98;
  const Scalar _tmp170 = _tmp128 - _tmp151 - _tmp94;
  const Scalar _tmp171 = _tmp103 * _tmp168;
  const Scalar _tmp172 = _tmp123 + _tmp160 + _tmp86;
  const Scalar _tmp173 = _tmp172 * _tmp74;
  const Scalar _tmp174 = -_tmp100 * _tmp168 - _tmp102 * _tmp168 + _tmp104 * _tmp171 +
                         _tmp130 * _tmp170 + _tmp167 * _tmp89 - _tmp169 * _tmp90 +
                         _tmp171 * _tmp35 + _tmp171 * _tmp90 + _tmp173 * sqrt_info(0, 1);
  const Scalar _tmp175 = _tmp111 + _tmp142 + _tmp162;
  const Scalar _tmp176 = _tmp103 * _tmp175;
  const Scalar _tmp177 = _tmp175 * _tmp98;
  const Scalar _tmp178 = _tmp126 - _tmp127 + _tmp152;
  const Scalar _tmp179 = _tmp178 * _tmp74;
  const Scalar _tmp180 = _tmp122 + _tmp146 + _tmp160;
  const Scalar _tmp181 = -_tmp115 + _tmp136 - _tmp157;
  const Scalar _tmp182 = -_tmp100 * _tmp175 - _tmp102 * _tmp175 + _tmp104 * _tmp176 +
                         _tmp130 * _tmp180 + _tmp176 * _tmp35 + _tmp176 * _tmp90 -
                         _tmp177 * _tmp90 + _tmp179 * sqrt_info(0, 1) + _tmp181 * _tmp89;
  const Scalar _tmp183 = _tmp74 * sqrt_info(1, 1);
  const Scalar _tmp184 = _tmp74 * _tmp88;
  const Scalar _tmp185 = _tmp39 * _tmp98;
  const Scalar _tmp186 = _tmp36 * sqrt_info(1, 1);
  const Scalar _tmp187 = _tmp101 * sqrt_info(1, 0);
  const Scalar _tmp188 = _tmp20 * sqrt_info(1, 0);
  const Scalar _tmp189 = _tmp106 * _tmp186 + _tmp106 * _tmp188 + _tmp106 * _tmp39 +
                         _tmp183 * _tmp81 + _tmp184 * sqrt_info(1, 0) - _tmp185 * _tmp96 -
                         _tmp186 * _tmp99 - _tmp187 * _tmp96 + _tmp75 * sqrt_info(1, 2);
  const Scalar _tmp190 = _tmp74 * sqrt_info(1, 0);
  const Scalar _tmp191 = _tmp74 * sqrt_info(1, 2);
  const Scalar _tmp192 = _tmp113 * _tmp190 - _tmp117 * _tmp185 - _tmp117 * _tmp187 -
                         _tmp118 * _tmp186 + _tmp124 * _tmp183 + _tmp129 * _tmp191 +
                         _tmp131 * _tmp186 + _tmp131 * _tmp39 + _tmp132 * sqrt_info(1, 0);
  const Scalar _tmp193 = _tmp137 * _tmp190 + _tmp139 * _tmp183 - _tmp143 * _tmp185 -
                         _tmp143 * _tmp187 + _tmp144 * _tmp186 + _tmp144 * _tmp188 +
                         _tmp144 * _tmp39 + _tmp147 * _tmp191 - _tmp148 * _tmp186;
  const Scalar _tmp194 = -_tmp153 * _tmp185 - _tmp153 * _tmp187 - _tmp154 * _tmp186 +
                         _tmp159 * _tmp191 + _tmp161 * _tmp190 + _tmp163 * _tmp183 +
                         _tmp165 * _tmp186 + _tmp165 * _tmp188 + _tmp165 * _tmp39;
  const Scalar _tmp195 = _tmp167 * _tmp190 - _tmp168 * _tmp185 - _tmp168 * _tmp187 -
                         _tmp169 * _tmp186 + _tmp170 * _tmp191 + _tmp171 * _tmp186 +
                         _tmp171 * _tmp188 + _tmp171 * _tmp39 + _tmp172 * _tmp183;
  const Scalar _tmp196 = -_tmp175 * _tmp185 - _tmp175 * _tmp187 + _tmp176 * _tmp186 +
                         _tmp176 * _tmp188 + _tmp176 * _tmp39 - _tmp177 * _tmp186 +
                         _tmp178 * _tmp183 + _tmp180 * _tmp191 + _tmp181 * _tmp190;
  const Scalar _tmp197 = _tmp41 * _tmp73;
  const Scalar _tmp198 = _tmp101 * sqrt_info(2, 0);
  const Scalar _tmp199 = _tmp34 * sqrt_info(2, 2);
  const Scalar _tmp200 = _tmp36 * sqrt_info(2, 1);
  const Scalar _tmp201 = _tmp20 * sqrt_info(2, 0);
  const Scalar _tmp202 = _tmp106 * _tmp199 + _tmp106 * _tmp200 + _tmp106 * _tmp201 +
                         _tmp184 * sqrt_info(2, 0) + _tmp197 * _tmp67 - _tmp198 * _tmp96 -
                         _tmp199 * _tmp99 - _tmp200 * _tmp99 + _tmp82 * sqrt_info(2, 1);
  const Scalar _tmp203 = _tmp74 * sqrt_info(2, 0);
  const Scalar _tmp204 = _tmp113 * _tmp203 - _tmp118 * _tmp199 - _tmp119 * sqrt_info(2, 1) -
                         _tmp120 * sqrt_info(2, 0) + _tmp125 * sqrt_info(2, 1) + _tmp129 * _tmp197 +
                         _tmp131 * _tmp199 + _tmp131 * _tmp200 + _tmp132 * sqrt_info(2, 0);
  const Scalar _tmp205 = _tmp137 * _tmp203 + _tmp140 * sqrt_info(2, 1) - _tmp143 * _tmp198 +
                         _tmp144 * _tmp199 + _tmp144 * _tmp200 + _tmp144 * _tmp201 +
                         _tmp147 * _tmp197 - _tmp148 * _tmp199 - _tmp148 * _tmp200;
  const Scalar _tmp206 = -_tmp154 * _tmp199 - _tmp155 * sqrt_info(2, 1) -
                         _tmp156 * sqrt_info(2, 0) + _tmp159 * _tmp197 + _tmp161 * _tmp203 +
                         _tmp164 * sqrt_info(2, 1) + _tmp165 * _tmp199 + _tmp165 * _tmp200 +
                         _tmp165 * _tmp201;
  const Scalar _tmp207 = _tmp167 * _tmp203 - _tmp168 * _tmp198 - _tmp169 * _tmp199 -
                         _tmp169 * _tmp200 + _tmp170 * _tmp197 + _tmp171 * _tmp199 +
                         _tmp171 * _tmp200 + _tmp171 * _tmp201 + _tmp173 * sqrt_info(2, 1);
  const Scalar _tmp208 = -_tmp175 * _tmp198 + _tmp176 * _tmp199 + _tmp176 * _tmp200 +
                         _tmp176 * _tmp201 - _tmp177 * _tmp199 - _tmp177 * _tmp200 +
                         _tmp179 * sqrt_info(2, 1) + _tmp180 * _tmp197 + _tmp181 * _tmp203;

  // Output terms (4)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 3, 1>& _res = (*res);

    _res(0, 0) = _tmp38;
    _res(1, 0) = _tmp40;
    _res(2, 0) = _tmp42;
  }

  if (jacobian != nullptr) {
    Eigen::Matrix<Scalar, 3, 12>& _jacobian = (*jacobian);

    _jacobian(0, 0) = _tmp107;
    _jacobian(0, 1) = _tmp133;
    _jacobian(0, 2) = _tmp149;
    _jacobian(0, 3) = 0;
    _jacobian(0, 4) = 0;
    _jacobian(0, 5) = 0;
    _jacobian(0, 6) = _tmp166;
    _jacobian(0, 7) = _tmp174;
    _jacobian(0, 8) = _tmp182;
    _jacobian(0, 9) = 0;
    _jacobian(0, 10) = 0;
    _jacobian(0, 11) = 0;
    _jacobian(1, 0) = _tmp189;
    _jacobian(1, 1) = _tmp192;
    _jacobian(1, 2) = _tmp193;
    _jacobian(1, 3) = 0;
    _jacobian(1, 4) = 0;
    _jacobian(1, 5) = 0;
    _jacobian(1, 6) = _tmp194;
    _jacobian(1, 7) = _tmp195;
    _jacobian(1, 8) = _tmp196;
    _jacobian(1, 9) = 0;
    _jacobian(1, 10) = 0;
    _jacobian(1, 11) = 0;
    _jacobian(2, 0) = _tmp202;
    _jacobian(2, 1) = _tmp204;
    _jacobian(2, 2) = _tmp205;
    _jacobian(2, 3) = 0;
    _jacobian(2, 4) = 0;
    _jacobian(2, 5) = 0;
    _jacobian(2, 6) = _tmp206;
    _jacobian(2, 7) = _tmp207;
    _jacobian(2, 8) = _tmp208;
    _jacobian(2, 9) = 0;
    _jacobian(2, 10) = 0;
    _jacobian(2, 11) = 0;
  }

  if (hessian != nullptr) {
    Eigen::Matrix<Scalar, 12, 12>& _hessian = (*hessian);

    _hessian.setZero();

    _hessian(0, 0) =
        std::pow(_tmp107, Scalar(2)) + std::pow(_tmp189, Scalar(2)) + std::pow(_tmp202, Scalar(2));
    _hessian(1, 0) = _tmp107 * _tmp133 + _tmp189 * _tmp192 + _tmp202 * _tmp204;
    _hessian(1, 1) =
        std::pow(_tmp133, Scalar(2)) + std::pow(_tmp192, Scalar(2)) + std::pow(_tmp204, Scalar(2));
    _hessian(2, 0) = _tmp107 * _tmp149 + _tmp189 * _tmp193 + _tmp202 * _tmp205;
    _hessian(2, 1) = _tmp133 * _tmp149 + _tmp192 * _tmp193 + _tmp204 * _tmp205;
    _hessian(2, 2) =
        std::pow(_tmp149, Scalar(2)) + std::pow(_tmp193, Scalar(2)) + std::pow(_tmp205, Scalar(2));
    _hessian(6, 0) = _tmp107 * _tmp166 + _tmp189 * _tmp194 + _tmp202 * _tmp206;
    _hessian(6, 1) = _tmp133 * _tmp166 + _tmp192 * _tmp194 + _tmp204 * _tmp206;
    _hessian(6, 2) = _tmp149 * _tmp166 + _tmp193 * _tmp194 + _tmp205 * _tmp206;
    _hessian(6, 6) =
        std::pow(_tmp166, Scalar(2)) + std::pow(_tmp194, Scalar(2)) + std::pow(_tmp206, Scalar(2));
    _hessian(7, 0) = _tmp107 * _tmp174 + _tmp189 * _tmp195 + _tmp202 * _tmp207;
    _hessian(7, 1) = _tmp133 * _tmp174 + _tmp192 * _tmp195 + _tmp204 * _tmp207;
    _hessian(7, 2) = _tmp149 * _tmp174 + _tmp193 * _tmp195 + _tmp205 * _tmp207;
    _hessian(7, 6) = _tmp166 * _tmp174 + _tmp194 * _tmp195 + _tmp206 * _tmp207;
    _hessian(7, 7) =
        std::pow(_tmp174, Scalar(2)) + std::pow(_tmp195, Scalar(2)) + std::pow(_tmp207, Scalar(2));
    _hessian(8, 0) = _tmp107 * _tmp182 + _tmp189 * _tmp196 + _tmp202 * _tmp208;
    _hessian(8, 1) = _tmp133 * _tmp182 + _tmp192 * _tmp196 + _tmp204 * _tmp208;
    _hessian(8, 2) = _tmp149 * _tmp182 + _tmp193 * _tmp196 + _tmp205 * _tmp208;
    _hessian(8, 6) = _tmp166 * _tmp182 + _tmp194 * _tmp196 + _tmp206 * _tmp208;
    _hessian(8, 7) = _tmp174 * _tmp182 + _tmp195 * _tmp196 + _tmp207 * _tmp208;
    _hessian(8, 8) =
        std::pow(_tmp182, Scalar(2)) + std::pow(_tmp196, Scalar(2)) + std::pow(_tmp208, Scalar(2));
  }

  if (rhs != nullptr) {
    Eigen::Matrix<Scalar, 12, 1>& _rhs = (*rhs);

    _rhs(0, 0) = _tmp107 * _tmp38 + _tmp189 * _tmp40 + _tmp202 * _tmp42;
    _rhs(1, 0) = _tmp133 * _tmp38 + _tmp192 * _tmp40 + _tmp204 * _tmp42;
    _rhs(2, 0) = _tmp149 * _tmp38 + _tmp193 * _tmp40 + _tmp205 * _tmp42;
    _rhs(3, 0) = 0;
    _rhs(4, 0) = 0;
    _rhs(5, 0) = 0;
    _rhs(6, 0) = _tmp166 * _tmp38 + _tmp194 * _tmp40 + _tmp206 * _tmp42;
    _rhs(7, 0) = _tmp174 * _tmp38 + _tmp195 * _tmp40 + _tmp207 * _tmp42;
    _rhs(8, 0) = _tmp182 * _tmp38 + _tmp196 * _tmp40 + _tmp208 * _tmp42;
    _rhs(9, 0) = 0;
    _rhs(10, 0) = 0;
    _rhs(11, 0) = 0;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
