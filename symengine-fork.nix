{
  lib,
  stdenv,
  cmake,
  gmp,
  flint,
  mpfr,
  libmpc,
  src,
}:

# https://github.com/NixOS/nixpkgs/blob/0c226d20b0df09c84d3a49df2a4f71870d0e723d/pkgs/development/libraries/symengine/default.nix
stdenv.mkDerivation rec {
  pname = "symengine";
  version = "0.7.0";
  inherit src;
  sourceRoot = "${src.name}/third_party/symengine";

  nativeBuildInputs = [ cmake ];

  buildInputs = [
    gmp
    flint
    mpfr
    libmpc
  ];

  cmakeFlags = [
    "-DWITH_FLINT=ON"
    "-DINTEGER_CLASS=flint"
    "-DWITH_SYMENGINE_THREAD_SAFE=yes"
    "-DWITH_MPC=yes"
    "-DBUILD_FOR_DISTRIBUTION=yes"
  ];

  doCheck = true;

  checkPhase = ''
    ctest
  '';

  meta = with lib; {
    description = "A fast symbolic manipulation library";
    license = licenses.bsd3;
  };

}
