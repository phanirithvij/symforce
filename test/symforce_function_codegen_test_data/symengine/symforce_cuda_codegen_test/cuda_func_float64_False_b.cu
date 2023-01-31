// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.cu.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

namespace sym {

__host__ __device__ void CudaFuncFloat64FalseB(
    const double a, const double1& b, const double* const __restrict__ c,
    const double* const __restrict__ d, const double* const __restrict__ e,
    const double* const __restrict__ f, const double* const __restrict__ g,
    double* const __restrict__ a_out, double* const __restrict__ b_out,
    double* const __restrict__ c_out, double* const __restrict__ d_out,
    double* const __restrict__ e_out, double* const __restrict__ f_out) {
  // Total ops: 36

  // Intermediate terms (1)
  const double _tmp0 = g[static_cast<size_t>(0)];

  // Output terms (6)
  if (a_out != nullptr) {
    *a_out = a;
  }

  if (b_out != nullptr) {
    b_out[0] = b.x;
  }

  if (c_out != nullptr) {
    c_out[0] = c[0];
    c_out[1] = c[1];
    c_out[2] = c[2];
  }

  if (d_out != nullptr) {
    d_out[0] = d[0];
    d_out[2] = d[2];
    d_out[1] = d[1];
    d_out[3] = d[3];
  }

  if (e_out != nullptr) {
    e_out[0] = e[0];
    e_out[1] = e[1];
    e_out[2] = e[2];
    e_out[3] = e[3];
    e_out[4] = e[4];
  }

  if (f_out != nullptr) {
    f_out[0] = _tmp0 + f[0];
    f_out[6] = _tmp0 + f[6];
    f_out[12] = _tmp0 + f[12];
    f_out[18] = _tmp0 + f[18];
    f_out[24] = _tmp0 + f[24];
    f_out[30] = _tmp0 + f[30];
    f_out[1] = _tmp0 + f[1];
    f_out[7] = _tmp0 + f[7];
    f_out[13] = _tmp0 + f[13];
    f_out[19] = _tmp0 + f[19];
    f_out[25] = _tmp0 + f[25];
    f_out[31] = _tmp0 + f[31];
    f_out[2] = _tmp0 + f[2];
    f_out[8] = _tmp0 + f[8];
    f_out[14] = _tmp0 + f[14];
    f_out[20] = _tmp0 + f[20];
    f_out[26] = _tmp0 + f[26];
    f_out[32] = _tmp0 + f[32];
    f_out[3] = _tmp0 + f[3];
    f_out[9] = _tmp0 + f[9];
    f_out[15] = _tmp0 + f[15];
    f_out[21] = _tmp0 + f[21];
    f_out[27] = _tmp0 + f[27];
    f_out[33] = _tmp0 + f[33];
    f_out[4] = _tmp0 + f[4];
    f_out[10] = _tmp0 + f[10];
    f_out[16] = _tmp0 + f[16];
    f_out[22] = _tmp0 + f[22];
    f_out[28] = _tmp0 + f[28];
    f_out[34] = _tmp0 + f[34];
    f_out[5] = _tmp0 + f[5];
    f_out[11] = _tmp0 + f[11];
    f_out[17] = _tmp0 + f[17];
    f_out[23] = _tmp0 + f[23];
    f_out[29] = _tmp0 + f[29];
    f_out[35] = _tmp0 + f[35];
  }
}

}  // namespace sym