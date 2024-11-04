{
  pkgs ? import <nixpkgs> { },
}:
let
  inherit (pkgs)
    lib
    python311
    callPackage
    fetchFromGitHub
    replaceVars
    ;
  python3 = python311;
  version = "0.9.0";
  src = fetchFromGitHub {
    owner = "symforce-org";
    repo = "symforce";
    rev = "v${version}";
    hash = "sha256-cOpycn48zSdR8clJEc2Zff/D6bDY453cVE2/L9gOgtc=";
    postFetch = ''
      # git init
      # git add remote
      # git tag
    '';
  };
  skymarshal = python3.pkgs.buildPythonPackage {
    pname = "skymarshal";
    inherit src version;
    sourceRoot = "${src.name}/third_party/skymarshal";
    pyproject = true;
    dependencies =
      (with python3.pkgs; [
        argh
        jinja2
        numpy
        ply
        six
      ])
      ++ (with pkgs; [
        eigen
        catch2_3
        fmt_8
        spdlog
        (callPackage ./tl-optional.nix { })
      ]);
    build-system = [
      python3.pkgs.setuptools
      python3.pkgs.wheel
    ];
  };
  symengine = callPackage ./symengine-fork.nix { inherit src; };
  symenginepy = python3.pkgs.buildPythonPackage {
    pname = "symenginepy";
    inherit src version;
    format = "setuptools";
    sourceRoot = "${src.name}/third_party/symenginepy";
    patches = [ ./symenginepy-setup.patch ];
    buildInputs = [ symengine ];
    dependencies = [
      python3.pkgs.cython
      python3.pkgs.cmake
    ];
    build-system = [
      python3.pkgs.setuptools
      python3.pkgs.wheel
    ];
  };
  out = python3.pkgs.buildPythonPackage rec {
    pname = "symforce";
    inherit src version;
    patches = [
      (replaceVars ./metis-cmake.patch {
        inherit (pkgs) metis;
      })
    ];
    #format = "pyproject";
    format = "setuptools";
    dependencies = [
      pkgs.metis
      pkgs.gmp
      python3.pkgs.pip
      python3.pkgs.pybind11
      python3.pkgs.cmake
      python3.pkgs.cython
      skymarshal
      symenginepy
    ];
    #env.USE_DISTUTILS = "TRUE";

    postPatch = ''
      substituteInPlace setup.py \
        --replace "pip<23.1" "pip"
    '';

    preBuild = ''
      cd ..
    '';

    build-system = [
      python3.pkgs.setuptools
      python3.pkgs.wheel
    ];

    nativeBuildInputs = [
      pkgs.cmake
      pkgs.gitMinimal
    ];

    pythonImportsCheck = [
      "symforce"
      "symforce.cc_sym"
      # TODO also https://github.com/symforce-org/symforce#verify-your-installation
    ];

    meta = {
      description = "Fast symbolic computation, code generation, and nonlinear optimization for robotics";
      homepage = "https://github.com/symforce-org/symforce";
      license = lib.licenses.asl20;
    };
  };
in
out
