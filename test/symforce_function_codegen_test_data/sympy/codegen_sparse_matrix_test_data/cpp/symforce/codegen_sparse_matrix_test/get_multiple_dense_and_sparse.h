// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>
#include <Eigen/Sparse>

namespace codegen_sparse_matrix_test {

/**
 * This function was autogenerated. Do not modify by hand.
 *
 * Args:
 *     matrix_in: Matrix100_100
 *
 * Outputs:
 *     sparse_first: Matrix100_100
 *     dense: Matrix44
 *     sparse_second: Matrix100_100
 *     result: Matrix33
 *
 */
template <typename Scalar>
Eigen::Matrix<Scalar, 3, 3> GetMultipleDenseAndSparse(
    const Eigen::Matrix<Scalar, 100, 100>& matrix_in,
    Eigen::SparseMatrix<Scalar>* const sparse_first = nullptr,
    Eigen::Matrix<Scalar, 4, 4>* const dense = nullptr,
    Eigen::SparseMatrix<Scalar>* const sparse_second = nullptr) {
  // Total ops: 200

  // Input arrays

  // Intermediate terms (0)

  // Output terms (4)
  if (dense != nullptr) {
    Eigen::Matrix<Scalar, 4, 4>& _dense = (*dense);

    _dense.setZero();

    _dense(0, 0) = 3;
    _dense(1, 1) = 3;
    _dense(2, 2) = 3;
    _dense(3, 3) = 3;
  }

  Eigen::Matrix<Scalar, 3, 3> _result;

  _result.setZero();

  if (sparse_first != nullptr) {
    static constexpr int kRows_sparse_first = 100;
    static constexpr int kCols_sparse_first = 100;
    static constexpr int kNumNonZero_sparse_first = 100;
    static constexpr int kColPtrs_sparse_first[] = {
        0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41,
        42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62,
        63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83,
        84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
    static constexpr int kRowIndices_sparse_first[] = {
        0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
        40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
        60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
        80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
    if (sparse_first->nonZeros() != 100 || sparse_first->outerSize() != 100 ||
        sparse_first->innerSize() != 100 || !sparse_first->isCompressed()) {
      // Matrix does not have the expected layout, create a correctly initialized sparse matrix
      Scalar sparse_first_empty_value_ptr[100];
      *sparse_first = Eigen::Map<const Eigen::SparseMatrix<Scalar>>(
          kRows_sparse_first, kCols_sparse_first, kNumNonZero_sparse_first, kColPtrs_sparse_first,
          kRowIndices_sparse_first, sparse_first_empty_value_ptr);
    }
    Scalar* sparse_first_value_ptr = sparse_first->valuePtr();

    sparse_first_value_ptr[0] = 2 * matrix_in(0, 0);
    sparse_first_value_ptr[1] = 2 * matrix_in(1, 1);
    sparse_first_value_ptr[2] = 2 * matrix_in(2, 2);
    sparse_first_value_ptr[3] = 2 * matrix_in(3, 3);
    sparse_first_value_ptr[4] = 2 * matrix_in(4, 4);
    sparse_first_value_ptr[5] = 2 * matrix_in(5, 5);
    sparse_first_value_ptr[6] = 2 * matrix_in(6, 6);
    sparse_first_value_ptr[7] = 2 * matrix_in(7, 7);
    sparse_first_value_ptr[8] = 2 * matrix_in(8, 8);
    sparse_first_value_ptr[9] = 2 * matrix_in(9, 9);
    sparse_first_value_ptr[10] = 2 * matrix_in(10, 10);
    sparse_first_value_ptr[11] = 2 * matrix_in(11, 11);
    sparse_first_value_ptr[12] = 2 * matrix_in(12, 12);
    sparse_first_value_ptr[13] = 2 * matrix_in(13, 13);
    sparse_first_value_ptr[14] = 2 * matrix_in(14, 14);
    sparse_first_value_ptr[15] = 2 * matrix_in(15, 15);
    sparse_first_value_ptr[16] = 2 * matrix_in(16, 16);
    sparse_first_value_ptr[17] = 2 * matrix_in(17, 17);
    sparse_first_value_ptr[18] = 2 * matrix_in(18, 18);
    sparse_first_value_ptr[19] = 2 * matrix_in(19, 19);
    sparse_first_value_ptr[20] = 2 * matrix_in(20, 20);
    sparse_first_value_ptr[21] = 2 * matrix_in(21, 21);
    sparse_first_value_ptr[22] = 2 * matrix_in(22, 22);
    sparse_first_value_ptr[23] = 2 * matrix_in(23, 23);
    sparse_first_value_ptr[24] = 2 * matrix_in(24, 24);
    sparse_first_value_ptr[25] = 2 * matrix_in(25, 25);
    sparse_first_value_ptr[26] = 2 * matrix_in(26, 26);
    sparse_first_value_ptr[27] = 2 * matrix_in(27, 27);
    sparse_first_value_ptr[28] = 2 * matrix_in(28, 28);
    sparse_first_value_ptr[29] = 2 * matrix_in(29, 29);
    sparse_first_value_ptr[30] = 2 * matrix_in(30, 30);
    sparse_first_value_ptr[31] = 2 * matrix_in(31, 31);
    sparse_first_value_ptr[32] = 2 * matrix_in(32, 32);
    sparse_first_value_ptr[33] = 2 * matrix_in(33, 33);
    sparse_first_value_ptr[34] = 2 * matrix_in(34, 34);
    sparse_first_value_ptr[35] = 2 * matrix_in(35, 35);
    sparse_first_value_ptr[36] = 2 * matrix_in(36, 36);
    sparse_first_value_ptr[37] = 2 * matrix_in(37, 37);
    sparse_first_value_ptr[38] = 2 * matrix_in(38, 38);
    sparse_first_value_ptr[39] = 2 * matrix_in(39, 39);
    sparse_first_value_ptr[40] = 2 * matrix_in(40, 40);
    sparse_first_value_ptr[41] = 2 * matrix_in(41, 41);
    sparse_first_value_ptr[42] = 2 * matrix_in(42, 42);
    sparse_first_value_ptr[43] = 2 * matrix_in(43, 43);
    sparse_first_value_ptr[44] = 2 * matrix_in(44, 44);
    sparse_first_value_ptr[45] = 2 * matrix_in(45, 45);
    sparse_first_value_ptr[46] = 2 * matrix_in(46, 46);
    sparse_first_value_ptr[47] = 2 * matrix_in(47, 47);
    sparse_first_value_ptr[48] = 2 * matrix_in(48, 48);
    sparse_first_value_ptr[49] = 2 * matrix_in(49, 49);
    sparse_first_value_ptr[50] = 2 * matrix_in(50, 50);
    sparse_first_value_ptr[51] = 2 * matrix_in(51, 51);
    sparse_first_value_ptr[52] = 2 * matrix_in(52, 52);
    sparse_first_value_ptr[53] = 2 * matrix_in(53, 53);
    sparse_first_value_ptr[54] = 2 * matrix_in(54, 54);
    sparse_first_value_ptr[55] = 2 * matrix_in(55, 55);
    sparse_first_value_ptr[56] = 2 * matrix_in(56, 56);
    sparse_first_value_ptr[57] = 2 * matrix_in(57, 57);
    sparse_first_value_ptr[58] = 2 * matrix_in(58, 58);
    sparse_first_value_ptr[59] = 2 * matrix_in(59, 59);
    sparse_first_value_ptr[60] = 2 * matrix_in(60, 60);
    sparse_first_value_ptr[61] = 2 * matrix_in(61, 61);
    sparse_first_value_ptr[62] = 2 * matrix_in(62, 62);
    sparse_first_value_ptr[63] = 2 * matrix_in(63, 63);
    sparse_first_value_ptr[64] = 2 * matrix_in(64, 64);
    sparse_first_value_ptr[65] = 2 * matrix_in(65, 65);
    sparse_first_value_ptr[66] = 2 * matrix_in(66, 66);
    sparse_first_value_ptr[67] = 2 * matrix_in(67, 67);
    sparse_first_value_ptr[68] = 2 * matrix_in(68, 68);
    sparse_first_value_ptr[69] = 2 * matrix_in(69, 69);
    sparse_first_value_ptr[70] = 2 * matrix_in(70, 70);
    sparse_first_value_ptr[71] = 2 * matrix_in(71, 71);
    sparse_first_value_ptr[72] = 2 * matrix_in(72, 72);
    sparse_first_value_ptr[73] = 2 * matrix_in(73, 73);
    sparse_first_value_ptr[74] = 2 * matrix_in(74, 74);
    sparse_first_value_ptr[75] = 2 * matrix_in(75, 75);
    sparse_first_value_ptr[76] = 2 * matrix_in(76, 76);
    sparse_first_value_ptr[77] = 2 * matrix_in(77, 77);
    sparse_first_value_ptr[78] = 2 * matrix_in(78, 78);
    sparse_first_value_ptr[79] = 2 * matrix_in(79, 79);
    sparse_first_value_ptr[80] = 2 * matrix_in(80, 80);
    sparse_first_value_ptr[81] = 2 * matrix_in(81, 81);
    sparse_first_value_ptr[82] = 2 * matrix_in(82, 82);
    sparse_first_value_ptr[83] = 2 * matrix_in(83, 83);
    sparse_first_value_ptr[84] = 2 * matrix_in(84, 84);
    sparse_first_value_ptr[85] = 2 * matrix_in(85, 85);
    sparse_first_value_ptr[86] = 2 * matrix_in(86, 86);
    sparse_first_value_ptr[87] = 2 * matrix_in(87, 87);
    sparse_first_value_ptr[88] = 2 * matrix_in(88, 88);
    sparse_first_value_ptr[89] = 2 * matrix_in(89, 89);
    sparse_first_value_ptr[90] = 2 * matrix_in(90, 90);
    sparse_first_value_ptr[91] = 2 * matrix_in(91, 91);
    sparse_first_value_ptr[92] = 2 * matrix_in(92, 92);
    sparse_first_value_ptr[93] = 2 * matrix_in(93, 93);
    sparse_first_value_ptr[94] = 2 * matrix_in(94, 94);
    sparse_first_value_ptr[95] = 2 * matrix_in(95, 95);
    sparse_first_value_ptr[96] = 2 * matrix_in(96, 96);
    sparse_first_value_ptr[97] = 2 * matrix_in(97, 97);
    sparse_first_value_ptr[98] = 2 * matrix_in(98, 98);
    sparse_first_value_ptr[99] = 2 * matrix_in(99, 99);
  }

  if (sparse_second != nullptr) {
    static constexpr int kRows_sparse_second = 100;
    static constexpr int kCols_sparse_second = 100;
    static constexpr int kNumNonZero_sparse_second = 100;
    static constexpr int kColPtrs_sparse_second[] = {
        0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41,
        42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62,
        63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83,
        84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
    static constexpr int kRowIndices_sparse_second[] = {
        0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
        40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
        60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
        80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
    if (sparse_second->nonZeros() != 100 || sparse_second->outerSize() != 100 ||
        sparse_second->innerSize() != 100 || !sparse_second->isCompressed()) {
      // Matrix does not have the expected layout, create a correctly initialized sparse matrix
      Scalar sparse_second_empty_value_ptr[100];
      *sparse_second = Eigen::Map<const Eigen::SparseMatrix<Scalar>>(
          kRows_sparse_second, kCols_sparse_second, kNumNonZero_sparse_second,
          kColPtrs_sparse_second, kRowIndices_sparse_second, sparse_second_empty_value_ptr);
    }
    Scalar* sparse_second_value_ptr = sparse_second->valuePtr();

    sparse_second_value_ptr[0] = 4 * matrix_in(0, 0);
    sparse_second_value_ptr[1] = 4 * matrix_in(1, 1);
    sparse_second_value_ptr[2] = 4 * matrix_in(2, 2);
    sparse_second_value_ptr[3] = 4 * matrix_in(3, 3);
    sparse_second_value_ptr[4] = 4 * matrix_in(4, 4);
    sparse_second_value_ptr[5] = 4 * matrix_in(5, 5);
    sparse_second_value_ptr[6] = 4 * matrix_in(6, 6);
    sparse_second_value_ptr[7] = 4 * matrix_in(7, 7);
    sparse_second_value_ptr[8] = 4 * matrix_in(8, 8);
    sparse_second_value_ptr[9] = 4 * matrix_in(9, 9);
    sparse_second_value_ptr[10] = 4 * matrix_in(10, 10);
    sparse_second_value_ptr[11] = 4 * matrix_in(11, 11);
    sparse_second_value_ptr[12] = 4 * matrix_in(12, 12);
    sparse_second_value_ptr[13] = 4 * matrix_in(13, 13);
    sparse_second_value_ptr[14] = 4 * matrix_in(14, 14);
    sparse_second_value_ptr[15] = 4 * matrix_in(15, 15);
    sparse_second_value_ptr[16] = 4 * matrix_in(16, 16);
    sparse_second_value_ptr[17] = 4 * matrix_in(17, 17);
    sparse_second_value_ptr[18] = 4 * matrix_in(18, 18);
    sparse_second_value_ptr[19] = 4 * matrix_in(19, 19);
    sparse_second_value_ptr[20] = 4 * matrix_in(20, 20);
    sparse_second_value_ptr[21] = 4 * matrix_in(21, 21);
    sparse_second_value_ptr[22] = 4 * matrix_in(22, 22);
    sparse_second_value_ptr[23] = 4 * matrix_in(23, 23);
    sparse_second_value_ptr[24] = 4 * matrix_in(24, 24);
    sparse_second_value_ptr[25] = 4 * matrix_in(25, 25);
    sparse_second_value_ptr[26] = 4 * matrix_in(26, 26);
    sparse_second_value_ptr[27] = 4 * matrix_in(27, 27);
    sparse_second_value_ptr[28] = 4 * matrix_in(28, 28);
    sparse_second_value_ptr[29] = 4 * matrix_in(29, 29);
    sparse_second_value_ptr[30] = 4 * matrix_in(30, 30);
    sparse_second_value_ptr[31] = 4 * matrix_in(31, 31);
    sparse_second_value_ptr[32] = 4 * matrix_in(32, 32);
    sparse_second_value_ptr[33] = 4 * matrix_in(33, 33);
    sparse_second_value_ptr[34] = 4 * matrix_in(34, 34);
    sparse_second_value_ptr[35] = 4 * matrix_in(35, 35);
    sparse_second_value_ptr[36] = 4 * matrix_in(36, 36);
    sparse_second_value_ptr[37] = 4 * matrix_in(37, 37);
    sparse_second_value_ptr[38] = 4 * matrix_in(38, 38);
    sparse_second_value_ptr[39] = 4 * matrix_in(39, 39);
    sparse_second_value_ptr[40] = 4 * matrix_in(40, 40);
    sparse_second_value_ptr[41] = 4 * matrix_in(41, 41);
    sparse_second_value_ptr[42] = 4 * matrix_in(42, 42);
    sparse_second_value_ptr[43] = 4 * matrix_in(43, 43);
    sparse_second_value_ptr[44] = 4 * matrix_in(44, 44);
    sparse_second_value_ptr[45] = 4 * matrix_in(45, 45);
    sparse_second_value_ptr[46] = 4 * matrix_in(46, 46);
    sparse_second_value_ptr[47] = 4 * matrix_in(47, 47);
    sparse_second_value_ptr[48] = 4 * matrix_in(48, 48);
    sparse_second_value_ptr[49] = 4 * matrix_in(49, 49);
    sparse_second_value_ptr[50] = 4 * matrix_in(50, 50);
    sparse_second_value_ptr[51] = 4 * matrix_in(51, 51);
    sparse_second_value_ptr[52] = 4 * matrix_in(52, 52);
    sparse_second_value_ptr[53] = 4 * matrix_in(53, 53);
    sparse_second_value_ptr[54] = 4 * matrix_in(54, 54);
    sparse_second_value_ptr[55] = 4 * matrix_in(55, 55);
    sparse_second_value_ptr[56] = 4 * matrix_in(56, 56);
    sparse_second_value_ptr[57] = 4 * matrix_in(57, 57);
    sparse_second_value_ptr[58] = 4 * matrix_in(58, 58);
    sparse_second_value_ptr[59] = 4 * matrix_in(59, 59);
    sparse_second_value_ptr[60] = 4 * matrix_in(60, 60);
    sparse_second_value_ptr[61] = 4 * matrix_in(61, 61);
    sparse_second_value_ptr[62] = 4 * matrix_in(62, 62);
    sparse_second_value_ptr[63] = 4 * matrix_in(63, 63);
    sparse_second_value_ptr[64] = 4 * matrix_in(64, 64);
    sparse_second_value_ptr[65] = 4 * matrix_in(65, 65);
    sparse_second_value_ptr[66] = 4 * matrix_in(66, 66);
    sparse_second_value_ptr[67] = 4 * matrix_in(67, 67);
    sparse_second_value_ptr[68] = 4 * matrix_in(68, 68);
    sparse_second_value_ptr[69] = 4 * matrix_in(69, 69);
    sparse_second_value_ptr[70] = 4 * matrix_in(70, 70);
    sparse_second_value_ptr[71] = 4 * matrix_in(71, 71);
    sparse_second_value_ptr[72] = 4 * matrix_in(72, 72);
    sparse_second_value_ptr[73] = 4 * matrix_in(73, 73);
    sparse_second_value_ptr[74] = 4 * matrix_in(74, 74);
    sparse_second_value_ptr[75] = 4 * matrix_in(75, 75);
    sparse_second_value_ptr[76] = 4 * matrix_in(76, 76);
    sparse_second_value_ptr[77] = 4 * matrix_in(77, 77);
    sparse_second_value_ptr[78] = 4 * matrix_in(78, 78);
    sparse_second_value_ptr[79] = 4 * matrix_in(79, 79);
    sparse_second_value_ptr[80] = 4 * matrix_in(80, 80);
    sparse_second_value_ptr[81] = 4 * matrix_in(81, 81);
    sparse_second_value_ptr[82] = 4 * matrix_in(82, 82);
    sparse_second_value_ptr[83] = 4 * matrix_in(83, 83);
    sparse_second_value_ptr[84] = 4 * matrix_in(84, 84);
    sparse_second_value_ptr[85] = 4 * matrix_in(85, 85);
    sparse_second_value_ptr[86] = 4 * matrix_in(86, 86);
    sparse_second_value_ptr[87] = 4 * matrix_in(87, 87);
    sparse_second_value_ptr[88] = 4 * matrix_in(88, 88);
    sparse_second_value_ptr[89] = 4 * matrix_in(89, 89);
    sparse_second_value_ptr[90] = 4 * matrix_in(90, 90);
    sparse_second_value_ptr[91] = 4 * matrix_in(91, 91);
    sparse_second_value_ptr[92] = 4 * matrix_in(92, 92);
    sparse_second_value_ptr[93] = 4 * matrix_in(93, 93);
    sparse_second_value_ptr[94] = 4 * matrix_in(94, 94);
    sparse_second_value_ptr[95] = 4 * matrix_in(95, 95);
    sparse_second_value_ptr[96] = 4 * matrix_in(96, 96);
    sparse_second_value_ptr[97] = 4 * matrix_in(97, 97);
    sparse_second_value_ptr[98] = 4 * matrix_in(98, 98);
    sparse_second_value_ptr[99] = 4 * matrix_in(99, 99);
  }

  return _result;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace codegen_sparse_matrix_test
