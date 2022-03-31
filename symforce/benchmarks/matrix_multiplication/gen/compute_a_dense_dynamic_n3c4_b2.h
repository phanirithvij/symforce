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
*     result: Matrix20_15
*
*/
template <typename Scalar>
Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> ComputeADenseDynamicN3C4B2(const Scalar x0, const Scalar x1) {

    // Total ops: 21

    // Input arrays

    // Intermediate terms (9)
    const Scalar _tmp0 = 2*x1;
    const Scalar _tmp1 = x0 + 2;
    const Scalar _tmp2 = -_tmp1;
    const Scalar _tmp3 = -x1;
    const Scalar _tmp4 = 3*x0;
    const Scalar _tmp5 = x1 - 1;
    const Scalar _tmp6 = x1 + 2;
    const Scalar _tmp7 = 2*x0;
    const Scalar _tmp8 = 2 - x1;

    // Output terms (1)
    Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> _result(20, 15);

    _result.setZero();

    _result(0, 9) = _tmp0;
    _result(0, 13) = _tmp0;
    _result(0, 14) = 2;
    _result(1, 8) = _tmp2;
    _result(1, 12) = _tmp2;
    _result(1, 14) = -1;
    _result(2, 7) = 1;
    _result(2, 11) = x1;
    _result(2, 14) = -2;
    _result(3, 6) = _tmp3;
    _result(3, 10) = -_tmp4;
    _result(3, 14) = _tmp5;
    _result(4, 5) = -_tmp5;
    _result(4, 12) = x0 + 1;
    _result(4, 13) = 3;
    _result(5, 4) = 1;
    _result(5, 11) = _tmp3;
    _result(5, 13) = -1;
    _result(6, 3) = 4;
    _result(6, 10) = 1;
    _result(6, 13) = x0;
    _result(7, 2) = x0;
    _result(7, 11) = x1;
    _result(7, 12) = _tmp6;
    _result(8, 1) = _tmp1;
    _result(8, 10) = x1;
    _result(9, 0) = -2;
    _result(9, 10) = _tmp7 - 2;
    _result(9, 11) = -x0*x1;
    _result(10, 5) = _tmp8;
    _result(10, 8) = -1;
    _result(10, 9) = x1;
    _result(11, 4) = Scalar(2.0);
    _result(11, 9) = _tmp2;
    _result(12, 3) = _tmp8;
    _result(12, 6) = _tmp0;
    _result(12, 9) = 3;
    _result(13, 2) = 6;
    _result(13, 7) = -1;
    _result(13, 8) = x1 + 1;
    _result(14, 1) = -2;
    _result(14, 6) = _tmp4;
    _result(14, 8) = x1;
    _result(15, 0) = _tmp6;
    _result(15, 6) = _tmp0 + 1;
    _result(15, 7) = _tmp0;
    _result(16, 2) = 3;
    _result(16, 4) = -x0;
    _result(16, 5) = _tmp7;
    _result(17, 1) = x0;
    _result(17, 3) = -_tmp7;
    _result(17, 5) = 2;
    _result(18, 0) = _tmp0;
    _result(18, 3) = -2;
    _result(18, 4) = 1;
    _result(19, 0) = x0 + 3;
    _result(19, 1) = 4;
    _result(19, 2) = _tmp0 + _tmp7;

    return _result;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
