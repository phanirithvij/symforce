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
      # or use fetchgit+shallow+dotgit
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
  # https://github.com/NixOS/nixpkgs/blob/0342938d212691bca7bdac277fde6a78ed7c32c9/pkgs/development/python-modules/symengine/default.nix
  symenginepy = python3.pkgs.buildPythonPackage {
    pname = "symenginepy";
    inherit src version;
    sourceRoot = "${src.name}/third_party/symenginepy";
    patches = [ ./symenginepy-setup.patch ];
    format = "setuptools";
    dontUseCmakeConfigure = true;
    nativeBuildInputs = [ pkgs.cmake ];
    env.SymEngine_DIR = "${symengine}";
    buildInputs = [
      python3.pkgs.cython
    ];
    build-system = [
      python3.pkgs.setuptools
    ];
    nativeCheckInputs = [
      python3.pkgs.pytest
      python3.pkgs.sympy
    ];
  };
in
python3.pkgs.buildPythonPackage rec {
  pname = "symforce";
  inherit src version;
  patches = [
    (replaceVars ./metis-cmake.patch {
      inherit (pkgs) metis;
    })
  ];
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
}
