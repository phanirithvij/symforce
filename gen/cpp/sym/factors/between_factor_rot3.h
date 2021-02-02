// -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <Eigen/Dense>
#include <geo/rot3.h>

namespace sym {

/**
 * Residual that penalizes the difference between between(a, b) and a_T_b.
 *
 * In vector space terms that would be:
 *     (b - a) - a_T_b
 *
 * In lie group terms:
 *     local_coordinates(a_T_b, between(a, b))
 *     to_tangent(compose(inverse(a_T_b), compose(inverse(a), b)))
 *
 * Args:
 *     sqrt_info: Square root information matrix to whiten residual. This can be computed from
 *                a covariance matrix as the cholesky decomposition of the inverse. In the case
 *                of a diagonal it will contain 1/sigma values. Must match the tangent dim.
 *
 */
template <typename Scalar>
void BetweenFactorRot3(const geo::Rot3<Scalar>& a, const geo::Rot3<Scalar>& b,
                       const geo::Rot3<Scalar>& a_T_b, const Eigen::Matrix<Scalar, 3, 3>& sqrt_info,
                       const Scalar epsilon, Eigen::Matrix<Scalar, 3, 1>* const res = nullptr,
                       Eigen::Matrix<Scalar, 3, 6>* const jac = nullptr) {
  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _a_T_b = a_T_b.Data();

  // Intermediate terms (207)
  const Scalar _tmp0 = -_a[0] * _b[1] + _a[1] * _b[0] - _a[2] * _b[3] + _a[3] * _b[2];
  const Scalar _tmp1 = _a[0] * _b[0] + _a[1] * _b[1] + _a[2] * _b[2] + _a[3] * _b[3];
  const Scalar _tmp2 = -_a[0] * _b[3] - _a[1] * _b[2] + _a[2] * _b[1] + _a[3] * _b[0];
  const Scalar _tmp3 = _a[0] * _b[2] - _a[1] * _b[3] - _a[2] * _b[0] + _a[3] * _b[1];
  const Scalar _tmp4 =
      _a_T_b[0] * _tmp0 - _a_T_b[1] * _tmp1 - _a_T_b[2] * _tmp2 + _a_T_b[3] * _tmp3;
  const Scalar _tmp5 =
      _a_T_b[0] * _tmp2 + _a_T_b[1] * _tmp3 + _a_T_b[2] * _tmp0 + _a_T_b[3] * _tmp1;
  const Scalar _tmp6 = (((_tmp5) > 0) - ((_tmp5) < 0));
  const Scalar _tmp7 = 2 * std::min<Scalar>(0, _tmp6) + 1;
  const Scalar _tmp8 = _tmp7 * sqrt_info(0, 1);
  const Scalar _tmp9 = std::fabs(_tmp5);
  const Scalar _tmp10 = 1 - epsilon;
  const Scalar _tmp11 = std::min<Scalar>(_tmp10, _tmp9);
  const Scalar _tmp12 = 1 - (_tmp11 * _tmp11);
  const Scalar _tmp13 = std::acos(_tmp11);
  const Scalar _tmp14 = 2 * _tmp13 / std::sqrt(_tmp12);
  const Scalar _tmp15 = _tmp14 * _tmp8;
  const Scalar _tmp16 =
      -_a_T_b[0] * _tmp3 + _a_T_b[1] * _tmp2 - _a_T_b[2] * _tmp1 + _a_T_b[3] * _tmp0;
  const Scalar _tmp17 = _tmp14 * _tmp7;
  const Scalar _tmp18 = _tmp16 * _tmp17;
  const Scalar _tmp19 =
      -_a_T_b[0] * _tmp1 - _a_T_b[1] * _tmp0 + _a_T_b[2] * _tmp3 + _a_T_b[3] * _tmp2;
  const Scalar _tmp20 = _tmp17 * sqrt_info(0, 0);
  const Scalar _tmp21 = _tmp17 * _tmp4;
  const Scalar _tmp22 = _tmp17 * sqrt_info(1, 0);
  const Scalar _tmp23 = _tmp17 * sqrt_info(2, 0);
  const Scalar _tmp24 = _tmp16 * sqrt_info(0, 2);
  const Scalar _tmp25 = _a_T_b[2] * _b[2];
  const Scalar _tmp26 = _a_T_b[3] * _b[3];
  const Scalar _tmp27 = _a_T_b[1] * _b[1];
  const Scalar _tmp28 = _a_T_b[0] * _b[0];
  const Scalar _tmp29 = _tmp27 + _tmp28;
  const Scalar _tmp30 = _tmp25 + _tmp26 + _tmp29;
  const Scalar _tmp31 = _tmp30 * _tmp7;
  const Scalar _tmp32 = _tmp6 * ((((_tmp10 - _tmp9) > 0) - ((_tmp10 - _tmp9) < 0)) + 1);
  const Scalar _tmp33 = _tmp11 * _tmp13 * _tmp32 / (_tmp12 * std::sqrt(_tmp12));
  const Scalar _tmp34 = _tmp31 * _tmp33;
  const Scalar _tmp35 = _tmp32 / _tmp12;
  const Scalar _tmp36 = _tmp19 * _tmp35;
  const Scalar _tmp37 = _tmp36 * sqrt_info(0, 0);
  const Scalar _tmp38 = _tmp35 * _tmp4;
  const Scalar _tmp39 = _tmp38 * _tmp8;
  const Scalar _tmp40 = _tmp19 * _tmp34;
  const Scalar _tmp41 = _tmp33 * _tmp4;
  const Scalar _tmp42 = _tmp41 * _tmp8;
  const Scalar _tmp43 = _a_T_b[1] * _b[3];
  const Scalar _tmp44 = -_tmp43;
  const Scalar _tmp45 = _a_T_b[0] * _b[2];
  const Scalar _tmp46 = _a_T_b[3] * _b[1];
  const Scalar _tmp47 = _a_T_b[2] * _b[0];
  const Scalar _tmp48 = -_tmp47;
  const Scalar _tmp49 = _tmp46 + _tmp48;
  const Scalar _tmp50 = _tmp44 + _tmp45 + _tmp49;
  const Scalar _tmp51 = _a_T_b[3] * _b[0];
  const Scalar _tmp52 = _a_T_b[2] * _b[1];
  const Scalar _tmp53 = _a_T_b[0] * _b[3];
  const Scalar _tmp54 = -_tmp53;
  const Scalar _tmp55 = _a_T_b[1] * _b[2];
  const Scalar _tmp56 = -_tmp55;
  const Scalar _tmp57 = _tmp54 + _tmp56;
  const Scalar _tmp58 = _tmp17 * (_tmp51 + _tmp52 + _tmp57);
  const Scalar _tmp59 = _a_T_b[0] * _b[1];
  const Scalar _tmp60 = -_tmp59;
  const Scalar _tmp61 = _a_T_b[1] * _b[0];
  const Scalar _tmp62 = _a_T_b[3] * _b[2];
  const Scalar _tmp63 = _a_T_b[2] * _b[3];
  const Scalar _tmp64 = -_tmp63;
  const Scalar _tmp65 = _tmp62 + _tmp64;
  const Scalar _tmp66 = _tmp17 * (_tmp60 + _tmp61 + _tmp65);
  const Scalar _tmp67 = _tmp16 * _tmp35;
  const Scalar _tmp68 = _tmp67 * sqrt_info(0, 2);
  const Scalar _tmp69 =
      (1.0 / 2.0) * _tmp15 * _tmp50 + (1.0 / 2.0) * _tmp24 * _tmp34 - 1.0 / 2.0 * _tmp30 * _tmp39 +
      (1.0 / 2.0) * _tmp30 * _tmp42 - 1.0 / 2.0 * _tmp31 * _tmp37 - 1.0 / 2.0 * _tmp31 * _tmp68 +
      (1.0 / 2.0) * _tmp40 * sqrt_info(0, 0) + (1.0 / 2.0) * _tmp58 * sqrt_info(0, 0) +
      (1.0 / 2.0) * _tmp66 * sqrt_info(0, 2);
  const Scalar _tmp70 = -_tmp61;
  const Scalar _tmp71 = _tmp59 + _tmp65 + _tmp70;
  const Scalar _tmp72 = _tmp7 * _tmp71;
  const Scalar _tmp73 = _tmp33 * _tmp72;
  const Scalar _tmp74 = _tmp19 * _tmp73;
  const Scalar _tmp75 = -_tmp26;
  const Scalar _tmp76 = _tmp17 * (-_tmp25 + _tmp29 + _tmp75);
  const Scalar _tmp77 = -_tmp45;
  const Scalar _tmp78 = _tmp17 * (_tmp43 + _tmp49 + _tmp77);
  const Scalar _tmp79 = _tmp16 * _tmp73;
  const Scalar _tmp80 = -_tmp52;
  const Scalar _tmp81 = -_tmp51 + _tmp57 + _tmp80;
  const Scalar _tmp82 = _tmp15 * _tmp81 - _tmp37 * _tmp72 - _tmp39 * _tmp71 + _tmp42 * _tmp71 -
                        _tmp68 * _tmp72 + _tmp74 * sqrt_info(0, 0) + _tmp76 * sqrt_info(0, 2) +
                        _tmp78 * sqrt_info(0, 0) + _tmp79 * sqrt_info(0, 2);
  const Scalar _tmp83 = (1.0 / 2.0) * _tmp82;
  const Scalar _tmp84 = _tmp60 + _tmp70;
  const Scalar _tmp85 = -_tmp62 + _tmp64 + _tmp84;
  const Scalar _tmp86 = _tmp44 + _tmp77;
  const Scalar _tmp87 = _tmp46 + _tmp47 + _tmp86;
  const Scalar _tmp88 = _tmp7 * _tmp87;
  const Scalar _tmp89 = _tmp33 * _tmp88;
  const Scalar _tmp90 = _tmp19 * _tmp89;
  const Scalar _tmp91 = _tmp51 + _tmp80;
  const Scalar _tmp92 = _tmp17 * (_tmp53 + _tmp56 + _tmp91);
  const Scalar _tmp93 = _tmp36 * _tmp88;
  const Scalar _tmp94 = _tmp25 + _tmp75;
  const Scalar _tmp95 = -_tmp27 + _tmp28 + _tmp94;
  const Scalar _tmp96 = _tmp15 * _tmp95 + _tmp20 * _tmp85 + _tmp24 * _tmp89 - _tmp39 * _tmp87 +
                        _tmp42 * _tmp87 - _tmp68 * _tmp88 + _tmp90 * sqrt_info(0, 0) +
                        _tmp92 * sqrt_info(0, 2) - _tmp93 * sqrt_info(0, 0);
  const Scalar _tmp97 = (1.0 / 2.0) * _tmp96;
  const Scalar _tmp98 = _tmp27 - _tmp28 + _tmp94;
  const Scalar _tmp99 = _tmp54 + _tmp55 + _tmp91;
  const Scalar _tmp100 = _tmp7 * _tmp99;
  const Scalar _tmp101 = _tmp100 * _tmp36;
  const Scalar _tmp102 = _tmp17 * (-_tmp46 + _tmp48 + _tmp86);
  const Scalar _tmp103 = _tmp100 * _tmp33;
  const Scalar _tmp104 = _tmp103 * _tmp16;
  const Scalar _tmp105 = _tmp103 * _tmp19;
  const Scalar _tmp106 = _tmp62 + _tmp63 + _tmp84;
  const Scalar _tmp107 = -_tmp100 * _tmp68 - _tmp101 * sqrt_info(0, 0) + _tmp102 * sqrt_info(0, 2) +
                         _tmp104 * sqrt_info(0, 2) + _tmp105 * sqrt_info(0, 0) + _tmp106 * _tmp15 +
                         _tmp20 * _tmp98 - _tmp39 * _tmp99 + _tmp42 * _tmp99;
  const Scalar _tmp108 = (1.0 / 2.0) * _a[3];
  const Scalar _tmp109 = (1.0 / 2.0) * _tmp107;
  const Scalar _tmp110 = _a[0] * _a_T_b[3];
  const Scalar _tmp111 = _a[2] * _a_T_b[1];
  const Scalar _tmp112 = _a[1] * _a_T_b[2];
  const Scalar _tmp113 = _a[3] * _a_T_b[0];
  const Scalar _tmp114 = -_tmp110 + _tmp111 - _tmp112 - _tmp113;
  const Scalar _tmp115 =
      -_a[0] * _a_T_b[0] - _a[1] * _a_T_b[1] - _a[2] * _a_T_b[2] + _a[3] * _a_T_b[3];
  const Scalar _tmp116 = _tmp115 * _tmp7;
  const Scalar _tmp117 = _tmp116 * _tmp33;
  const Scalar _tmp118 = _tmp117 * _tmp19;
  const Scalar _tmp119 = _a[2] * _a_T_b[3];
  const Scalar _tmp120 = _a[3] * _a_T_b[2];
  const Scalar _tmp121 = _a[0] * _a_T_b[1];
  const Scalar _tmp122 = _a[1] * _a_T_b[0];
  const Scalar _tmp123 = -_tmp119 - _tmp120 - _tmp121 + _tmp122;
  const Scalar _tmp124 = _tmp123 * _tmp17;
  const Scalar _tmp125 = _tmp115 * _tmp8;
  const Scalar _tmp126 = _a[1] * _a_T_b[3];
  const Scalar _tmp127 = _a[0] * _a_T_b[2];
  const Scalar _tmp128 = _a[2] * _a_T_b[0];
  const Scalar _tmp129 = _a[3] * _a_T_b[1];
  const Scalar _tmp130 = -_tmp126 + _tmp127 - _tmp128 - _tmp129;
  const Scalar _tmp131 = _tmp114 * _tmp20 - _tmp116 * _tmp37 - _tmp116 * _tmp68 + _tmp117 * _tmp24 +
                         _tmp118 * sqrt_info(0, 0) + _tmp124 * sqrt_info(0, 2) - _tmp125 * _tmp38 +
                         _tmp125 * _tmp41 + _tmp130 * _tmp15;
  const Scalar _tmp132 = (1.0 / 2.0) * _b[0];
  const Scalar _tmp133 = _tmp119 + _tmp120 + _tmp121 - _tmp122;
  const Scalar _tmp134 = _tmp133 * _tmp7;
  const Scalar _tmp135 = _tmp134 * _tmp33;
  const Scalar _tmp136 = _tmp135 * _tmp19;
  const Scalar _tmp137 = _tmp134 * _tmp36;
  const Scalar _tmp138 = _tmp115 * _tmp17;
  const Scalar _tmp139 = _tmp110 - _tmp111 + _tmp112 + _tmp113;
  const Scalar _tmp140 = _tmp130 * _tmp20 - _tmp133 * _tmp39 + _tmp133 * _tmp42 - _tmp134 * _tmp68 +
                         _tmp135 * _tmp24 + _tmp136 * sqrt_info(0, 0) - _tmp137 * sqrt_info(0, 0) +
                         _tmp138 * sqrt_info(0, 2) + _tmp139 * _tmp15;
  const Scalar _tmp141 = (1.0 / 2.0) * _b[1];
  const Scalar _tmp142 = _tmp126 - _tmp127 + _tmp128 + _tmp129;
  const Scalar _tmp143 = _tmp142 * _tmp7;
  const Scalar _tmp144 = _tmp143 * _tmp33;
  const Scalar _tmp145 = _tmp144 * _tmp16;
  const Scalar _tmp146 = _tmp144 * _tmp19;
  const Scalar _tmp147 = _tmp114 * _tmp17;
  const Scalar _tmp148 = _tmp125 * _tmp14 + _tmp133 * _tmp20 - _tmp142 * _tmp39 + _tmp142 * _tmp42 -
                         _tmp143 * _tmp37 - _tmp143 * _tmp68 + _tmp145 * sqrt_info(0, 2) +
                         _tmp146 * sqrt_info(0, 0) + _tmp147 * sqrt_info(0, 2);
  const Scalar _tmp149 = (1.0 / 2.0) * _b[2];
  const Scalar _tmp150 = _tmp142 * _tmp17;
  const Scalar _tmp151 = _tmp139 * _tmp7;
  const Scalar _tmp152 = _tmp151 * _tmp33;
  const Scalar _tmp153 = _tmp139 * _tmp38;
  const Scalar _tmp154 = _tmp152 * _tmp19;
  const Scalar _tmp155 = _tmp123 * _tmp15 + _tmp138 * sqrt_info(0, 0) + _tmp139 * _tmp42 +
                         _tmp150 * sqrt_info(0, 2) - _tmp151 * _tmp37 - _tmp151 * _tmp68 +
                         _tmp152 * _tmp24 - _tmp153 * _tmp8 + _tmp154 * sqrt_info(0, 0);
  const Scalar _tmp156 = (1.0 / 2.0) * _b[3];
  const Scalar _tmp157 = (1.0 / 2.0) * _tmp155;
  const Scalar _tmp158 = _tmp19 * sqrt_info(1, 0);
  const Scalar _tmp159 = _tmp17 * sqrt_info(1, 1);
  const Scalar _tmp160 = _tmp16 * sqrt_info(1, 2);
  const Scalar _tmp161 = _tmp38 * sqrt_info(1, 1);
  const Scalar _tmp162 = _tmp36 * sqrt_info(1, 0);
  const Scalar _tmp163 = _tmp67 * sqrt_info(1, 2);
  const Scalar _tmp164 = _tmp31 * _tmp41;
  const Scalar _tmp165 =
      (1.0 / 2.0) * _tmp158 * _tmp34 + (1.0 / 2.0) * _tmp159 * _tmp50 +
      (1.0 / 2.0) * _tmp160 * _tmp34 - 1.0 / 2.0 * _tmp161 * _tmp31 - 1.0 / 2.0 * _tmp162 * _tmp31 -
      1.0 / 2.0 * _tmp163 * _tmp31 + (1.0 / 2.0) * _tmp164 * sqrt_info(1, 1) +
      (1.0 / 2.0) * _tmp58 * sqrt_info(1, 0) + (1.0 / 2.0) * _tmp66 * sqrt_info(1, 2);
  const Scalar _tmp166 = _tmp41 * _tmp72;
  const Scalar _tmp167 = _tmp17 * _tmp81;
  const Scalar _tmp168 = _tmp158 * _tmp73 + _tmp160 * _tmp73 - _tmp161 * _tmp72 - _tmp162 * _tmp72 -
                         _tmp163 * _tmp72 + _tmp166 * sqrt_info(1, 1) + _tmp167 * sqrt_info(1, 1) +
                         _tmp76 * sqrt_info(1, 2) + _tmp78 * sqrt_info(1, 0);
  const Scalar _tmp169 = (1.0 / 2.0) * _tmp168;
  const Scalar _tmp170 = _tmp41 * _tmp88;
  const Scalar _tmp171 = _tmp158 * _tmp89 + _tmp159 * _tmp95 + _tmp160 * _tmp89 - _tmp161 * _tmp88 -
                         _tmp162 * _tmp88 - _tmp163 * _tmp88 + _tmp170 * sqrt_info(1, 1) +
                         _tmp22 * _tmp85 + _tmp92 * sqrt_info(1, 2);
  const Scalar _tmp172 = (1.0 / 2.0) * _tmp171;
  const Scalar _tmp173 = _tmp106 * _tmp17;
  const Scalar _tmp174 = _tmp100 * _tmp41;
  const Scalar _tmp175 = -_tmp100 * _tmp161 - _tmp100 * _tmp162 - _tmp100 * _tmp163 +
                         _tmp102 * sqrt_info(1, 2) + _tmp103 * _tmp158 + _tmp103 * _tmp160 +
                         _tmp173 * sqrt_info(1, 1) + _tmp174 * sqrt_info(1, 1) + _tmp22 * _tmp98;
  const Scalar _tmp176 = (1.0 / 2.0) * _tmp175;
  const Scalar _tmp177 = _tmp117 * _tmp4;
  const Scalar _tmp178 = _tmp114 * _tmp22 - _tmp116 * _tmp161 - _tmp116 * _tmp162 -
                         _tmp116 * _tmp163 + _tmp117 * _tmp158 + _tmp117 * _tmp160 +
                         _tmp124 * sqrt_info(1, 2) + _tmp130 * _tmp159 + _tmp177 * sqrt_info(1, 1);
  const Scalar _tmp179 = _tmp134 * _tmp41;
  const Scalar _tmp180 = _tmp134 * _tmp38;
  const Scalar _tmp181 = _tmp130 * _tmp22 - _tmp134 * _tmp162 - _tmp134 * _tmp163 +
                         _tmp135 * _tmp158 + _tmp135 * _tmp160 + _tmp138 * sqrt_info(1, 2) +
                         _tmp139 * _tmp159 + _tmp179 * sqrt_info(1, 1) - _tmp180 * sqrt_info(1, 1);
  const Scalar _tmp182 = _tmp143 * _tmp41;
  const Scalar _tmp183 = _tmp133 * _tmp22 + _tmp138 * sqrt_info(1, 1) - _tmp143 * _tmp161 -
                         _tmp143 * _tmp162 - _tmp143 * _tmp163 + _tmp144 * _tmp158 +
                         _tmp144 * _tmp160 + _tmp147 * sqrt_info(1, 2) + _tmp182 * sqrt_info(1, 1);
  const Scalar _tmp184 = (1.0 / 2.0) * _tmp183;
  const Scalar _tmp185 = _tmp151 * _tmp41;
  const Scalar _tmp186 = _tmp153 * _tmp7;
  const Scalar _tmp187 = _tmp124 * sqrt_info(1, 1) + _tmp138 * sqrt_info(1, 0) +
                         _tmp150 * sqrt_info(1, 2) - _tmp151 * _tmp162 - _tmp151 * _tmp163 +
                         _tmp152 * _tmp158 + _tmp152 * _tmp160 + _tmp185 * sqrt_info(1, 1) -
                         _tmp186 * sqrt_info(1, 1);
  const Scalar _tmp188 = (1.0 / 2.0) * _tmp187;
  const Scalar _tmp189 = _tmp36 * sqrt_info(2, 0);
  const Scalar _tmp190 = _tmp67 * sqrt_info(2, 2);
  const Scalar _tmp191 = _tmp38 * sqrt_info(2, 1);
  const Scalar _tmp192 = _tmp166 * sqrt_info(2, 1) + _tmp167 * sqrt_info(2, 1) - _tmp189 * _tmp72 -
                         _tmp190 * _tmp72 - _tmp191 * _tmp72 + _tmp74 * sqrt_info(2, 0) +
                         _tmp76 * sqrt_info(2, 2) + _tmp78 * sqrt_info(2, 0) +
                         _tmp79 * sqrt_info(2, 2);
  const Scalar _tmp193 = (1.0 / 2.0) * _tmp192;
  const Scalar _tmp194 = _tmp17 * sqrt_info(2, 1);
  const Scalar _tmp195 = _tmp16 * sqrt_info(2, 2);
  const Scalar _tmp196 =
      (1.0 / 2.0) * _tmp164 * sqrt_info(2, 1) - 1.0 / 2.0 * _tmp189 * _tmp31 -
      1.0 / 2.0 * _tmp190 * _tmp31 - 1.0 / 2.0 * _tmp191 * _tmp31 + (1.0 / 2.0) * _tmp194 * _tmp50 +
      (1.0 / 2.0) * _tmp195 * _tmp34 + (1.0 / 2.0) * _tmp40 * sqrt_info(2, 0) +
      (1.0 / 2.0) * _tmp58 * sqrt_info(2, 0) + (1.0 / 2.0) * _tmp66 * sqrt_info(2, 2);
  const Scalar _tmp197 = _tmp170 * sqrt_info(2, 1) - _tmp190 * _tmp88 - _tmp191 * _tmp88 +
                         _tmp194 * _tmp95 + _tmp195 * _tmp89 + _tmp23 * _tmp85 +
                         _tmp90 * sqrt_info(2, 0) + _tmp92 * sqrt_info(2, 2) -
                         _tmp93 * sqrt_info(2, 0);
  const Scalar _tmp198 = (1.0 / 2.0) * _tmp197;
  const Scalar _tmp199 = -_tmp100 * _tmp190 - _tmp100 * _tmp191 - _tmp101 * sqrt_info(2, 0) +
                         _tmp102 * sqrt_info(2, 2) + _tmp104 * sqrt_info(2, 2) +
                         _tmp105 * sqrt_info(2, 0) + _tmp173 * sqrt_info(2, 1) +
                         _tmp174 * sqrt_info(2, 1) + _tmp23 * _tmp98;
  const Scalar _tmp200 = (1.0 / 2.0) * _tmp199;
  const Scalar _tmp201 = _tmp130 * _tmp23 - _tmp134 * _tmp190 + _tmp135 * _tmp195 +
                         _tmp136 * sqrt_info(2, 0) - _tmp137 * sqrt_info(2, 0) +
                         _tmp138 * sqrt_info(2, 2) + _tmp139 * _tmp194 + _tmp179 * sqrt_info(2, 1) -
                         _tmp180 * sqrt_info(2, 1);
  const Scalar _tmp202 = _tmp114 * _tmp23 - _tmp116 * _tmp189 - _tmp116 * _tmp190 -
                         _tmp116 * _tmp191 + _tmp117 * _tmp195 + _tmp118 * sqrt_info(2, 0) +
                         _tmp124 * sqrt_info(2, 2) + _tmp130 * _tmp194 + _tmp177 * sqrt_info(2, 1);
  const Scalar _tmp203 = _tmp133 * _tmp23 + _tmp138 * sqrt_info(2, 1) - _tmp143 * _tmp189 -
                         _tmp143 * _tmp190 - _tmp143 * _tmp191 + _tmp145 * sqrt_info(2, 2) +
                         _tmp146 * sqrt_info(2, 0) + _tmp147 * sqrt_info(2, 2) +
                         _tmp182 * sqrt_info(2, 1);
  const Scalar _tmp204 = (1.0 / 2.0) * _tmp203;
  const Scalar _tmp205 = _tmp123 * _tmp194 + _tmp138 * sqrt_info(2, 0) + _tmp150 * sqrt_info(2, 2) -
                         _tmp151 * _tmp189 - _tmp151 * _tmp190 + _tmp152 * _tmp195 +
                         _tmp154 * sqrt_info(2, 0) + _tmp185 * sqrt_info(2, 1) -
                         _tmp186 * sqrt_info(2, 1);
  const Scalar _tmp206 = (1.0 / 2.0) * _tmp205;

  // Output terms (2)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 3, 1>& _res = (*res);

    _res(0, 0) = _tmp15 * _tmp4 + _tmp18 * sqrt_info(0, 2) + _tmp19 * _tmp20;
    _res(1, 0) = _tmp18 * sqrt_info(1, 2) + _tmp19 * _tmp22 + _tmp21 * sqrt_info(1, 1);
    _res(2, 0) = _tmp18 * sqrt_info(2, 2) + _tmp19 * _tmp23 + _tmp21 * sqrt_info(2, 1);
  }

  if (jac != nullptr) {
    Eigen::Matrix<Scalar, 3, 6>& _jac = (*jac);

    _jac(0, 0) = -_a[0] * _tmp69 - _a[1] * _tmp83 + _a[2] * _tmp97 + _tmp107 * _tmp108;
    _jac(0, 1) = _a[0] * _tmp83 - _a[1] * _tmp69 - _a[2] * _tmp109 + _tmp108 * _tmp96;
    _jac(0, 2) = -_a[0] * _tmp97 + _a[1] * _tmp109 - _a[2] * _tmp69 + _tmp108 * _tmp82;
    _jac(0, 3) = -_tmp131 * _tmp132 - _tmp140 * _tmp141 + _tmp148 * _tmp149 + _tmp155 * _tmp156;
    _jac(0, 4) = -_b[2] * _tmp157 - _tmp131 * _tmp141 + _tmp132 * _tmp140 + _tmp148 * _tmp156;
    _jac(0, 5) = _b[1] * _tmp157 - _tmp131 * _tmp149 - _tmp132 * _tmp148 + _tmp140 * _tmp156;
    _jac(1, 0) = -_a[0] * _tmp165 - _a[1] * _tmp169 + _a[2] * _tmp172 + _tmp108 * _tmp175;
    _jac(1, 1) = _a[0] * _tmp169 - _a[1] * _tmp165 - _a[2] * _tmp176 + _tmp108 * _tmp171;
    _jac(1, 2) = -_a[0] * _tmp172 + _a[1] * _tmp176 - _a[2] * _tmp165 + _tmp108 * _tmp168;
    _jac(1, 3) = _b[2] * _tmp184 - _tmp132 * _tmp178 - _tmp141 * _tmp181 + _tmp156 * _tmp187;
    _jac(1, 4) = -_b[2] * _tmp188 + _tmp132 * _tmp181 - _tmp141 * _tmp178 + _tmp156 * _tmp183;
    _jac(1, 5) = -_b[0] * _tmp184 + _b[1] * _tmp188 - _tmp149 * _tmp178 + _tmp156 * _tmp181;
    _jac(2, 0) = -_a[0] * _tmp196 - _a[1] * _tmp193 + _a[2] * _tmp198 + _tmp108 * _tmp199;
    _jac(2, 1) = _a[0] * _tmp193 - _a[1] * _tmp196 - _a[2] * _tmp200 + _tmp108 * _tmp197;
    _jac(2, 2) = -_a[0] * _tmp198 + _a[1] * _tmp200 - _a[2] * _tmp196 + _tmp108 * _tmp192;
    _jac(2, 3) = _b[2] * _tmp204 - _tmp132 * _tmp202 - _tmp141 * _tmp201 + _tmp156 * _tmp205;
    _jac(2, 4) = -_b[2] * _tmp206 + _tmp132 * _tmp201 - _tmp141 * _tmp202 + _tmp156 * _tmp203;
    _jac(2, 5) = -_b[0] * _tmp204 + _b[1] * _tmp206 - _tmp149 * _tmp202 + _tmp156 * _tmp201;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
