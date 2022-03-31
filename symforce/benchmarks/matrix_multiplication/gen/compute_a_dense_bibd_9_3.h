// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once


#include <Eigen/Dense>



namespace sym {


/**
* This function was autogenerated. Do not modify by hand.
*
* Args:
*     x0: Scalar
*     x1: Scalar
*
* Outputs:
*     result: Matrix36_84
*
*/
template <typename Scalar>
Eigen::Matrix<Scalar, 36, 84> ComputeADenseBibd93(const Scalar x0, const Scalar x1) {

    // Total ops: 74

    // Input arrays

    // Intermediate terms (31)
    const Scalar _tmp0 = 4*x0;
    const Scalar _tmp1 = 2*x0;
    const Scalar _tmp2 = x1 + 2;
    const Scalar _tmp3 = std::pow(x0, Scalar(2));
    const Scalar _tmp4 = x0 - 1;
    const Scalar _tmp5 = x1 - 1;
    const Scalar _tmp6 = 2*x1;
    const Scalar _tmp7 = -x0;
    const Scalar _tmp8 = -_tmp6;
    const Scalar _tmp9 = x1 + 1;
    const Scalar _tmp10 = -_tmp1;
    const Scalar _tmp11 = x0 + x1;
    const Scalar _tmp12 = x0 + 1;
    const Scalar _tmp13 = -_tmp12;
    const Scalar _tmp14 = 2*_tmp3;
    const Scalar _tmp15 = _tmp1 - 4;
    const Scalar _tmp16 = x1 - 2;
    const Scalar _tmp17 = x0*x1;
    const Scalar _tmp18 = -_tmp17;
    const Scalar _tmp19 = x0 + 2;
    const Scalar _tmp20 = -_tmp19;
    const Scalar _tmp21 = _tmp1*x1;
    const Scalar _tmp22 = -x1;
    const Scalar _tmp23 = -_tmp11;
    const Scalar _tmp24 = x0 - 3;
    const Scalar _tmp25 = -std::pow(x1, Scalar(2));
    const Scalar _tmp26 = _tmp6 - 4;
    const Scalar _tmp27 = _tmp22 + x0;
    const Scalar _tmp28 = -_tmp5;
    const Scalar _tmp29 = -_tmp9;
    const Scalar _tmp30 = _tmp1 + 2;

    // Output terms (1)
    Eigen::Matrix<Scalar, 36, 84> _result;

    _result.setZero();

    _result(0, 0) = _tmp0;
    _result(0, 1) = _tmp1 + 1;
    _result(0, 2) = -2;
    _result(0, 3) = _tmp2;
    _result(0, 4) = -4;
    _result(0, 6) = Scalar(-0.5);
    _result(1, 0) = -_tmp3;
    _result(1, 7) = -_tmp2;
    _result(1, 8) = -1;
    _result(1, 9) = 2;
    _result(1, 10) = -2;
    _result(1, 11) = -_tmp4;
    _result(1, 12) = _tmp5;
    _result(2, 1) = -2;
    _result(2, 7) = 8;
    _result(2, 13) = _tmp4;
    _result(2, 14) = _tmp1;
    _result(2, 15) = 1;
    _result(2, 16) = -2;
    _result(2, 17) = _tmp6;
    _result(3, 2) = 1;
    _result(3, 13) = _tmp1;
    _result(3, 18) = x1;
    _result(3, 19) = x1;
    _result(3, 20) = _tmp7;
    _result(3, 21) = -1;
    _result(4, 9) = _tmp8;
    _result(4, 14) = _tmp9;
    _result(4, 18) = 1;
    _result(4, 22) = _tmp6;
    _result(4, 23) = _tmp10;
    _result(4, 24) = 4;
    _result(5, 4) = -1;
    _result(5, 10) = 2;
    _result(5, 15) = _tmp11*x1;
    _result(5, 19) = x0;
    _result(5, 22) = Scalar(-1.0);
    _result(5, 25) = x0;
    _result(5, 26) = 2;
    _result(6, 5) = x1 + 3;
    _result(6, 11) = Scalar(0.5);
    _result(6, 16) = 3*x0;
    _result(6, 20) = _tmp13;
    _result(6, 23) = _tmp14;
    _result(6, 25) = 1;
    _result(6, 27) = _tmp7;
    _result(7, 6) = _tmp10;
    _result(7, 12) = 2;
    _result(7, 17) = Scalar(-1.0);
    _result(7, 21) = _tmp8;
    _result(7, 24) = _tmp2;
    _result(7, 26) = _tmp13;
    _result(8, 0) = -1;
    _result(8, 28) = _tmp8;
    _result(8, 29) = -3;
    _result(8, 30) = -3;
    _result(8, 31) = -_tmp15;
    _result(8, 32) = 1;
    _result(8, 33) = -2;
    _result(9, 1) = _tmp1;
    _result(9, 28) = -_tmp16;
    _result(9, 34) = _tmp10;
    _result(9, 35) = x1 - 4;
    _result(9, 36) = x0;
    _result(9, 37) = _tmp2;
    _result(9, 38) = x0;
    _result(10, 29) = x1;
    _result(10, 34) = _tmp18;
    _result(10, 39) = _tmp1;
    _result(10, 40) = -1;
    _result(10, 41) = _tmp17;
    _result(10, 42) = -2;
    _result(11, 3) = x1;
    _result(11, 30) = -1;
    _result(11, 35) = 4;
    _result(11, 39) = _tmp1;
    _result(11, 43) = _tmp20;
    _result(11, 45) = x0;
    _result(12, 4) = 1;
    _result(12, 31) = _tmp20;
    _result(12, 36) = x0;
    _result(12, 40) = _tmp7;
    _result(12, 43) = x0;
    _result(12, 46) = -_tmp1 - _tmp6;
    _result(12, 47) = -1;
    _result(13, 5) = 1;
    _result(13, 32) = -2;
    _result(13, 37) = x1;
    _result(13, 41) = -_tmp21;
    _result(13, 44) = x1 + Scalar(-0.5);
    _result(13, 46) = _tmp22;
    _result(13, 48) = x1;
    _result(14, 6) = -_tmp6 - 2;
    _result(14, 33) = Scalar(1.0);
    _result(14, 38) = _tmp17 - 2;
    _result(14, 42) = 4;
    _result(14, 45) = 1;
    _result(14, 47) = _tmp22;
    _result(15, 7) = _tmp6 - 2;
    _result(15, 28) = (Scalar(1)/Scalar(2))/x0;
    _result(15, 49) = _tmp9;
    _result(15, 50) = _tmp23;
    _result(15, 51) = _tmp24;
    _result(15, 52) = x1;
    _result(15, 53) = 4;
    _result(16, 8) = _tmp19;
    _result(16, 29) = _tmp7;
    _result(16, 49) = x1;
    _result(16, 54) = 2;
    _result(16, 55) = 1;
    _result(16, 56) = 4;
    _result(16, 57) = 2;
    _result(17, 9) = _tmp23;
    _result(17, 30) = _tmp12;
    _result(17, 50) = 3 - x1;
    _result(17, 58) = _tmp25;
    _result(17, 59) = -1;
    _result(17, 60) = 1;
    _result(18, 10) = _tmp7;
    _result(18, 31) = _tmp12*x0;
    _result(18, 51) = x0;
    _result(18, 55) = -1;
    _result(18, 58) = 1;
    _result(18, 61) = 2;
    _result(18, 62) = -1;
    _result(19, 11) = x1;
    _result(19, 32) = -2;
    _result(19, 56) = _tmp19;
    _result(19, 59) = 1;
    _result(19, 61) = _tmp6;
    _result(19, 63) = _tmp10;
    _result(20, 12) = _tmp8;
    _result(20, 33) = -_tmp26;
    _result(20, 53) = 1;
    _result(20, 57) = _tmp21;
    _result(20, 60) = 2;
    _result(20, 62) = -4;
    _result(20, 63) = 5;
    _result(21, 13) = -2;
    _result(21, 34) = -_tmp27;
    _result(21, 49) = 4 - x0;
    _result(21, 64) = 3;
    _result(21, 65) = _tmp28;
    _result(21, 67) = Scalar(1.0);
    _result(22, 35) = _tmp17;
    _result(22, 50) = 2;
    _result(22, 64) = _tmp20;
    _result(22, 68) = 2;
    _result(22, 69) = 4;
    _result(22, 70) = _tmp19;
    _result(23, 15) = _tmp22;
    _result(23, 36) = Scalar(1.0);
    _result(23, 51) = _tmp29;
    _result(23, 65) = x1;
    _result(23, 68) = 1;
    _result(23, 71) = _tmp6 + 1;
    _result(23, 72) = Scalar(1.0);
    _result(24, 16) = x0;
    _result(24, 37) = 2;
    _result(24, 52) = _tmp7;
    _result(24, 66) = _tmp28;
    _result(24, 69) = -1;
    _result(24, 71) = -6;
    _result(24, 73) = _tmp20;
    _result(25, 17) = _tmp9 + x0;
    _result(25, 38) = _tmp10;
    _result(25, 53) = -_tmp14;
    _result(25, 67) = _tmp29;
    _result(25, 70) = _tmp25;
    _result(25, 72) = _tmp10;
    _result(25, 73) = -4;
    _result(26, 18) = 2;
    _result(26, 39) = -3;
    _result(26, 54) = 1;
    _result(26, 64) = _tmp7;
    _result(26, 74) = -Scalar(1)/Scalar(2)*x0;
    _result(26, 75) = 3;
    _result(26, 76) = 3;
    _result(27, 19) = _tmp26;
    _result(27, 40) = x1;
    _result(27, 55) = _tmp26;
    _result(27, 65) = 1;
    _result(27, 74) = _tmp30;
    _result(27, 77) = _tmp16;
    _result(27, 78) = x0;
    _result(28, 20) = _tmp10;
    _result(28, 41) = _tmp25;
    _result(28, 56) = 2 - x0;
    _result(28, 66) = -2;
    _result(28, 75) = _tmp6 - 1;
    _result(28, 77) = -3*x1;
    _result(28, 79) = 3;
    _result(29, 21) = _tmp4 + x1;
    _result(29, 42) = _tmp19;
    _result(29, 57) = -_tmp30;
    _result(29, 67) = 2/x1;
    _result(29, 76) = Scalar(1.0);
    _result(29, 78) = -2;
    _result(29, 79) = -_tmp24;
    _result(30, 22) = 3;
    _result(30, 43) = -1;
    _result(30, 58) = _tmp10;
    _result(30, 68) = 1;
    _result(30, 74) = _tmp18;
    _result(30, 80) = _tmp22;
    _result(30, 81) = _tmp1;
    _result(31, 23) = _tmp1 - 2;
    _result(31, 44) = _tmp10;
    _result(31, 69) = _tmp15;
    _result(31, 75) = _tmp25;
    _result(31, 80) = -_tmp0;
    _result(31, 82) = _tmp13;
    _result(32, 24) = _tmp6;
    _result(32, 45) = 2;
    _result(32, 60) = _tmp19 + _tmp22;
    _result(32, 76) = Scalar(-2.0);
    _result(32, 81) = _tmp6;
    _result(32, 82) = _tmp18;
    _result(33, 25) = 4;
    _result(33, 46) = -2;
    _result(33, 61) = _tmp27;
    _result(33, 77) = 2;
    _result(33, 80) = 3;
    _result(33, 83) = 2;
    _result(34, 26) = _tmp29;
    _result(34, 47) = _tmp8;
    _result(34, 62) = -4;
    _result(34, 72) = x1 + 4;
    _result(34, 78) = _tmp2;
    _result(34, 81) = x0;
    _result(34, 83) = 1;
    _result(35, 27) = 3;
    _result(35, 48) = _tmp23;
    _result(35, 63) = _tmp8;
    _result(35, 73) = _tmp7;
    _result(35, 79) = _tmp8;
    _result(35, 82) = -4;
    _result(35, 83) = x0;

    return _result;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
