// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/geo_package/CLASS.cc.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include "./rot3.h"

namespace sym {

// Print implementations
std::ostream& operator<<(std::ostream& os, const Rot3d& a) {
  const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
  os << "<Rot3d " << a.Data().transpose().format(fmt) << ">";
  return os;
}
std::ostream& operator<<(std::ostream& os, const Rot3f& a) {
  const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
  os << "<Rot3f " << a.Data().transpose().format(fmt) << ">";
  return os;
}

}  // namespace sym

// --------------------------------------------------------------------------
// Custom generated methods
// --------------------------------------------------------------------------

template <typename Scalar>
Eigen::Matrix<Scalar, 3, 3> sym::Rot3<Scalar>::ToRotationMatrix() const {
  // Total ops: 29

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _self = Data();

  // Intermediate terms (11)
  const Scalar _tmp0 = -2 * std::pow(_self[1], Scalar(2));
  const Scalar _tmp1 = 1 - 2 * std::pow(_self[2], Scalar(2));
  const Scalar _tmp2 = 2 * _self[0];
  const Scalar _tmp3 = _self[1] * _tmp2;
  const Scalar _tmp4 = 2 * _self[2];
  const Scalar _tmp5 = _self[3] * _tmp4;
  const Scalar _tmp6 = 2 * _self[1] * _self[3];
  const Scalar _tmp7 = _self[2] * _tmp2;
  const Scalar _tmp8 = -2 * std::pow(_self[0], Scalar(2));
  const Scalar _tmp9 = _self[3] * _tmp2;
  const Scalar _tmp10 = _self[1] * _tmp4;

  // Output terms (1)
  Eigen::Matrix<Scalar, 3, 3> _res;

  _res(0, 0) = _tmp0 + _tmp1;
  _res(0, 1) = _tmp3 - _tmp5;
  _res(0, 2) = _tmp6 + _tmp7;
  _res(1, 0) = _tmp3 + _tmp5;
  _res(1, 1) = _tmp1 + _tmp8;
  _res(1, 2) = _tmp10 - _tmp9;
  _res(2, 0) = -_tmp6 + _tmp7;
  _res(2, 1) = _tmp10 + _tmp9;
  _res(2, 2) = _tmp0 + _tmp8 + 1;

  return _res;
}

template <typename Scalar>
sym::Rot3<Scalar> sym::Rot3<Scalar>::RandomFromUniformSamples(const Scalar u1, const Scalar u2,
                                                              const Scalar u3) {
  // Total ops: 15

  // Input arrays

  // Intermediate terms (5)
  const Scalar _tmp0 = std::sqrt(1 - u1);
  const Scalar _tmp1 = 2 * M_PI;
  const Scalar _tmp2 = _tmp1 * u2;
  const Scalar _tmp3 = std::sqrt(u1);
  const Scalar _tmp4 = _tmp1 * u3;

  // Output terms (1)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _tmp0 * std::sin(_tmp2);
  _res[1] = _tmp0 * std::cos(_tmp2);
  _res[2] = _tmp3 * std::sin(_tmp4);
  _res[3] = _tmp3 * std::cos(_tmp4);

  return sym::Rot3<Scalar>(_res);
}

// Explicit instantiation
template class sym::Rot3<double>;
template class sym::Rot3<float>;
