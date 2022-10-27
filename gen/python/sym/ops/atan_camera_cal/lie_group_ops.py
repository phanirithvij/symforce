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
    Python LieGroupOps implementation for <class 'symforce.cam.atan_camera_cal.ATANCameraCal'>.
    """

    @staticmethod
    def from_tangent(vec, epsilon):
        # type: (T.Union[T.Sequence[float], numpy.ndarray], float) -> sym.ATANCameraCal

        # Total ops: 0

        # Input arrays
        vec = check_size_and_reshape(vec, "vec", (5, 1))

        # Intermediate terms (0)

        # Output terms
        _res = [0.0] * 5
        _res[0] = vec[0, 0]
        _res[1] = vec[1, 0]
        _res[2] = vec[2, 0]
        _res[3] = vec[3, 0]
        _res[4] = vec[4, 0]
        return sym.ATANCameraCal.from_storage(_res)

    @staticmethod
    def to_tangent(a, epsilon):
        # type: (sym.ATANCameraCal, float) -> numpy.ndarray

        # Total ops: 0

        # Input arrays
        _a = a.data

        # Intermediate terms (0)

        # Output terms
        _res = numpy.zeros((5, 1))
        _res[0, 0] = _a[0]
        _res[1, 0] = _a[1]
        _res[2, 0] = _a[2]
        _res[3, 0] = _a[3]
        _res[4, 0] = _a[4]
        return _res

    @staticmethod
    def retract(a, vec, epsilon):
        # type: (sym.ATANCameraCal, T.Union[T.Sequence[float], numpy.ndarray], float) -> sym.ATANCameraCal

        # Total ops: 5

        # Input arrays
        _a = a.data
        vec = check_size_and_reshape(vec, "vec", (5, 1))

        # Intermediate terms (0)

        # Output terms
        _res = [0.0] * 5
        _res[0] = _a[0] + vec[0, 0]
        _res[1] = _a[1] + vec[1, 0]
        _res[2] = _a[2] + vec[2, 0]
        _res[3] = _a[3] + vec[3, 0]
        _res[4] = _a[4] + vec[4, 0]
        return sym.ATANCameraCal.from_storage(_res)

    @staticmethod
    def local_coordinates(a, b, epsilon):
        # type: (sym.ATANCameraCal, sym.ATANCameraCal, float) -> numpy.ndarray

        # Total ops: 5

        # Input arrays
        _a = a.data
        _b = b.data

        # Intermediate terms (0)

        # Output terms
        _res = numpy.zeros((5, 1))
        _res[0, 0] = -_a[0] + _b[0]
        _res[1, 0] = -_a[1] + _b[1]
        _res[2, 0] = -_a[2] + _b[2]
        _res[3, 0] = -_a[3] + _b[3]
        _res[4, 0] = -_a[4] + _b[4]
        return _res

    @staticmethod
    def interpolate(a, b, alpha, epsilon):
        # type: (sym.ATANCameraCal, sym.ATANCameraCal, float, float) -> sym.ATANCameraCal

        # Total ops: 15

        # Input arrays
        _a = a.data
        _b = b.data

        # Intermediate terms (0)

        # Output terms
        _res = [0.0] * 5
        _res[0] = _a[0] + alpha * (-_a[0] + _b[0])
        _res[1] = _a[1] + alpha * (-_a[1] + _b[1])
        _res[2] = _a[2] + alpha * (-_a[2] + _b[2])
        _res[3] = _a[3] + alpha * (-_a[3] + _b[3])
        _res[4] = _a[4] + alpha * (-_a[4] + _b[4])
        return sym.ATANCameraCal.from_storage(_res)
