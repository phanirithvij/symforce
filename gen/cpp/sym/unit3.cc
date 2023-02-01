// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     geo_package/CLASS.cc.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include "./unit3.h"

namespace sym {

// Print implementations
std::ostream& operator<<(std::ostream& os, const Unit3d& a) {
  const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
  os << "<Unit3d " << a.Data().transpose().format(fmt) << ">";
  return os;
}
std::ostream& operator<<(std::ostream& os, const Unit3f& a) {
  const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
  os << "<Unit3f " << a.Data().transpose().format(fmt) << ">";
  return os;
}

}  // namespace sym

// --------------------------------------------------------------------------
// Custom generated methods
// --------------------------------------------------------------------------

template <typename Scalar>
sym::Unit3<Scalar> sym::Unit3<Scalar>::FromVector(const Eigen::Matrix<Scalar, 3, 1>& a,
                                                  const Scalar epsilon) {
  // Total ops: 35

  // Input arrays

  // Intermediate terms (8)
  const Scalar _tmp0 = Scalar(1) / Scalar(2) - Scalar(1) / Scalar(2) *
                                                   (((1 - std::pow(epsilon, Scalar(2))) > 0) -
                                                    ((1 - std::pow(epsilon, Scalar(2))) < 0));
  const Scalar _tmp1 = std::pow(Scalar(std::pow(a(0, 0), Scalar(2)) + std::pow(a(1, 0), Scalar(2)) +
                                       std::pow(a(2, 0), Scalar(2)) + epsilon),
                                Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp2 = _tmp1 * a(2, 0);
  const Scalar _tmp3 =
      (((-epsilon + std::fabs(_tmp2 + 1)) > 0) - ((-epsilon + std::fabs(_tmp2 + 1)) < 0)) + 1;
  const Scalar _tmp4 = (Scalar(1) / Scalar(2)) * _tmp3;
  const Scalar _tmp5 = 1 - _tmp4;
  const Scalar _tmp6 = std::sqrt(Scalar(2 * _tmp2 + epsilon + 2));
  const Scalar _tmp7 = _tmp1 * _tmp4 / _tmp6;

  // Output terms (1)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _tmp5 * (1 - _tmp0) - _tmp7 * a(1, 0);
  _res[1] = _tmp0 * _tmp5 + _tmp7 * a(0, 0);
  _res[2] = 0;
  _res[3] = (Scalar(1) / Scalar(4)) * _tmp3 * _tmp6;

  return sym::Unit3<Scalar>(_res);
}

template <typename Scalar>
Eigen::Matrix<Scalar, 3, 1> sym::Unit3<Scalar>::ToUnitVector() const {
  // Total ops: 14

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _self = Data();

  // Intermediate terms (2)
  const Scalar _tmp0 = 2 * _self[1];
  const Scalar _tmp1 = 2 * _self[0];

  // Output terms (1)
  Eigen::Matrix<Scalar, 3, 1> _res;

  _res(0, 0) = _self[2] * _tmp1 + _self[3] * _tmp0;
  _res(1, 0) = _self[2] * _tmp0 - _self[3] * _tmp1;
  _res(2, 0) = -2 * std::pow(_self[0], Scalar(2)) - 2 * std::pow(_self[1], Scalar(2)) + 1;

  return _res;
}

template <typename Scalar>
sym::Rot3<Scalar> sym::Unit3<Scalar>::ToRotation() const {
  // Total ops: 0

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _self = Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _self[0];
  _res[1] = _self[1];
  _res[2] = _self[2];
  _res[3] = _self[3];

  return sym::Rot3<Scalar>(_res);
}

// Explicit instantiation
template class sym::Unit3<double>;
template class sym::Unit3<float>;