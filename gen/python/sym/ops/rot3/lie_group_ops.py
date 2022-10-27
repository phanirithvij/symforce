# -----------------------------------------------------------------------------
# This file was autogenerated by symforce from template:
#     ops/CLASS/lie_group_ops.py.jinja
# Do NOT modify by hand.
# -----------------------------------------------------------------------------

import math
import typing as T

import numpy

import sym  # pylint: disable=unused-import
from sym.util import check_size_and_reshape


class LieGroupOps(object):
    """
    Python LieGroupOps implementation for <class 'symforce.geo.rot3.Rot3'>.
    """

    @staticmethod
    def from_tangent(vec, epsilon):
        # type: (T.Union[T.Sequence[float], numpy.ndarray], float) -> sym.Rot3

        # Total ops: 15

        # Input arrays
        vec = check_size_and_reshape(vec, "vec", (3, 1))

        # Intermediate terms (3)
        _tmp0 = math.sqrt(epsilon ** 2 + vec[0, 0] ** 2 + vec[1, 0] ** 2 + vec[2, 0] ** 2)
        _tmp1 = (1.0 / 2.0) * _tmp0
        _tmp2 = math.sin(_tmp1) / _tmp0

        # Output terms
        _res = [0.0] * 4
        _res[0] = _tmp2 * vec[0, 0]
        _res[1] = _tmp2 * vec[1, 0]
        _res[2] = _tmp2 * vec[2, 0]
        _res[3] = math.cos(_tmp1)
        return sym.Rot3.from_storage(_res)

    @staticmethod
    def to_tangent(a, epsilon):
        # type: (sym.Rot3, float) -> numpy.ndarray

        # Total ops: 17

        # Input arrays
        _a = a.data

        # Intermediate terms (2)
        _tmp0 = min(abs(_a[3]), 1 - epsilon)
        _tmp1 = (
            2
            * (2 * min(0, (0.0 if _a[3] == 0 else math.copysign(1, _a[3]))) + 1)
            * math.acos(_tmp0)
            / math.sqrt(1 - _tmp0 ** 2)
        )

        # Output terms
        _res = numpy.zeros((3, 1))
        _res[0, 0] = _a[0] * _tmp1
        _res[1, 0] = _a[1] * _tmp1
        _res[2, 0] = _a[2] * _tmp1
        return _res

    @staticmethod
    def retract(a, vec, epsilon):
        # type: (sym.Rot3, T.Union[T.Sequence[float], numpy.ndarray], float) -> sym.Rot3

        # Total ops: 44

        # Input arrays
        _a = a.data
        vec = check_size_and_reshape(vec, "vec", (3, 1))

        # Intermediate terms (8)
        _tmp0 = math.sqrt(epsilon ** 2 + vec[0, 0] ** 2 + vec[1, 0] ** 2 + vec[2, 0] ** 2)
        _tmp1 = (1.0 / 2.0) * _tmp0
        _tmp2 = math.cos(_tmp1)
        _tmp3 = math.sin(_tmp1) / _tmp0
        _tmp4 = _a[2] * _tmp3
        _tmp5 = _a[3] * _tmp3
        _tmp6 = _a[1] * _tmp3
        _tmp7 = _a[0] * _tmp3

        # Output terms
        _res = [0.0] * 4
        _res[0] = _a[0] * _tmp2 - _tmp4 * vec[1, 0] + _tmp5 * vec[0, 0] + _tmp6 * vec[2, 0]
        _res[1] = _a[1] * _tmp2 + _tmp4 * vec[0, 0] + _tmp5 * vec[1, 0] - _tmp7 * vec[2, 0]
        _res[2] = _a[2] * _tmp2 + _tmp5 * vec[2, 0] - _tmp6 * vec[0, 0] + _tmp7 * vec[1, 0]
        _res[3] = _a[3] * _tmp2 - _tmp4 * vec[2, 0] - _tmp6 * vec[1, 0] - _tmp7 * vec[0, 0]
        return sym.Rot3.from_storage(_res)

    @staticmethod
    def local_coordinates(a, b, epsilon):
        # type: (sym.Rot3, sym.Rot3, float) -> numpy.ndarray

        # Total ops: 45

        # Input arrays
        _a = a.data
        _b = b.data

        # Intermediate terms (3)
        _tmp0 = _a[0] * _b[0] + _a[1] * _b[1] + _a[2] * _b[2] + _a[3] * _b[3]
        _tmp1 = min(abs(_tmp0), 1 - epsilon)
        _tmp2 = (
            2
            * (2 * min(0, (0.0 if _tmp0 == 0 else math.copysign(1, _tmp0))) + 1)
            * math.acos(_tmp1)
            / math.sqrt(1 - _tmp1 ** 2)
        )

        # Output terms
        _res = numpy.zeros((3, 1))
        _res[0, 0] = _tmp2 * (-_a[0] * _b[3] - _a[1] * _b[2] + _a[2] * _b[1] + _a[3] * _b[0])
        _res[1, 0] = _tmp2 * (_a[0] * _b[2] - _a[1] * _b[3] - _a[2] * _b[0] + _a[3] * _b[1])
        _res[2, 0] = _tmp2 * (-_a[0] * _b[1] + _a[1] * _b[0] - _a[2] * _b[3] + _a[3] * _b[2])
        return _res

    @staticmethod
    def interpolate(a, b, alpha, epsilon):
        # type: (sym.Rot3, sym.Rot3, float, float) -> sym.Rot3

        # Total ops: 99

        # Input arrays
        _a = a.data
        _b = b.data

        # Intermediate terms (18)
        _tmp0 = -_a[0] * _b[3] - _a[1] * _b[2] + _a[2] * _b[1] + _a[3] * _b[0]
        _tmp1 = _a[0] * _b[0] + _a[1] * _b[1] + _a[2] * _b[2] + _a[3] * _b[3]
        _tmp2 = min(abs(_tmp1), 1 - epsilon)
        _tmp3 = 1 - _tmp2 ** 2
        _tmp4 = 2 * min(0, (0.0 if _tmp1 == 0 else math.copysign(1, _tmp1))) + 1
        _tmp5 = -_a[0] * _b[1] + _a[1] * _b[0] - _a[2] * _b[3] + _a[3] * _b[2]
        _tmp6 = math.acos(_tmp2)
        _tmp7 = 4 * _tmp4 ** 2 * _tmp6 ** 2 * alpha ** 2 / _tmp3
        _tmp8 = _a[0] * _b[2] - _a[1] * _b[3] - _a[2] * _b[0] + _a[3] * _b[1]
        _tmp9 = math.sqrt(
            _tmp0 ** 2 * _tmp7 + _tmp5 ** 2 * _tmp7 + _tmp7 * _tmp8 ** 2 + epsilon ** 2
        )
        _tmp10 = (1.0 / 2.0) * _tmp9
        _tmp11 = 2 * _tmp4 * _tmp6 * alpha * math.sin(_tmp10) / (math.sqrt(_tmp3) * _tmp9)
        _tmp12 = _a[3] * _tmp11
        _tmp13 = _a[1] * _tmp11
        _tmp14 = math.cos(_tmp10)
        _tmp15 = _tmp11 * _tmp8
        _tmp16 = _tmp0 * _tmp11
        _tmp17 = _tmp11 * _tmp5

        # Output terms
        _res = [0.0] * 4
        _res[0] = _a[0] * _tmp14 - _a[2] * _tmp15 + _tmp0 * _tmp12 + _tmp13 * _tmp5
        _res[1] = -_a[0] * _tmp17 + _a[1] * _tmp14 + _a[2] * _tmp16 + _tmp12 * _tmp8
        _res[2] = _a[0] * _tmp15 + _a[2] * _tmp14 - _tmp0 * _tmp13 + _tmp12 * _tmp5
        _res[3] = -_a[0] * _tmp16 - _a[2] * _tmp17 + _a[3] * _tmp14 - _tmp13 * _tmp8
        return sym.Rot3.from_storage(_res)
