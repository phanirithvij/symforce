# -----------------------------------------------------------------------------
# This file was autogenerated by symforce from template:
#     cam_package/CLASS.py.jinja
# Do NOT modify by hand.
# -----------------------------------------------------------------------------

import typing as T

import numpy

from .ops import linear_camera_cal as ops


class LinearCameraCal(object):
    """
    Autogenerated Python implementation of <class 'symforce.cam.linear_camera_cal.LinearCameraCal'>.

    Standard pinhole camera w/ four parameters [fx, fy, cx, cy].
    (fx, fy) representing focal length; (cx, cy) representing principal point.
    """

    __slots__ = ["data"]

    # This is because of an issue where mypy doesn't recognize attributes defined in __slots__
    # See https://github.com/python/mypy/issues/5941
    if T.TYPE_CHECKING:
        data = []  # type: T.List[float]

    def __init__(self, focal_length, principal_point):
        # type: (T.Union[T.Sequence[float], numpy.ndarray], T.Union[T.Sequence[float], numpy.ndarray]) -> None
        self.data = []
        if isinstance(focal_length, numpy.ndarray):
            if focal_length.shape in [(2, 1), (1, 2)]:
                focal_length = focal_length.flatten()
            elif focal_length.shape != (2,):
                raise IndexError(
                    "Expected focal_length to be a vector of length 2; instead had shape {}".format(
                        focal_length.shape
                    )
                )
        elif len(focal_length) != 2:
            raise IndexError(
                "Expected focal_length to be a sequence of length 2, was instead length {}.".format(
                    len(focal_length)
                )
            )
        if isinstance(principal_point, numpy.ndarray):
            if principal_point.shape in [(2, 1), (1, 2)]:
                principal_point = principal_point.flatten()
            elif principal_point.shape != (2,):
                raise IndexError(
                    "Expected principal_point to be a vector of length 2; instead had shape {}".format(
                        principal_point.shape
                    )
                )
        elif len(principal_point) != 2:
            raise IndexError(
                "Expected principal_point to be a sequence of length 2, was instead length {}.".format(
                    len(principal_point)
                )
            )

        self.data.extend(focal_length)
        self.data.extend(principal_point)

    def __repr__(self):
        # type: () -> str
        return "<{} {}>".format(self.__class__.__name__, self.data)

    # --------------------------------------------------------------------------
    # CameraOps
    # --------------------------------------------------------------------------

    def focal_length(self):
        # type: (LinearCameraCal) -> numpy.ndarray
        """
        Return the focal length.
        """

        return ops.CameraOps.focal_length(self)

    def principal_point(self):
        # type: (LinearCameraCal) -> numpy.ndarray
        """
        Return the principal point.
        """

        return ops.CameraOps.principal_point(self)

    def pixel_from_camera_point(self, point, epsilon):
        # type: (LinearCameraCal, T.Union[T.Sequence[float], numpy.ndarray], float) -> T.Tuple[numpy.ndarray, float]
        """
        Project a 3D point in the camera frame into 2D pixel coordinates.

        Return:
            pixel: (x, y) coordinate in pixels if valid
            is_valid: 1 if the operation is within bounds else 0
        """

        return ops.CameraOps.pixel_from_camera_point(self, point, epsilon)

    def pixel_from_camera_point_with_jacobians(self, point, epsilon):
        # type: (LinearCameraCal, T.Union[T.Sequence[float], numpy.ndarray], float) -> T.Tuple[numpy.ndarray, float, numpy.ndarray, numpy.ndarray]
        """
        Project a 3D point in the camera frame into 2D pixel coordinates.

        Return:
            pixel: (x, y) coordinate in pixels if valid
            is_valid: 1 if the operation is within bounds else 0
            pixel_D_cal: Derivative of pixel with respect to intrinsic calibration parameters
            pixel_D_point: Derivative of pixel with respect to point
        """

        return ops.CameraOps.pixel_from_camera_point_with_jacobians(self, point, epsilon)

    def camera_ray_from_pixel(self, pixel, epsilon):
        # type: (LinearCameraCal, T.Union[T.Sequence[float], numpy.ndarray], float) -> T.Tuple[numpy.ndarray, float]
        """
        Backproject a 2D pixel coordinate into a 3D ray in the camera frame.

        TODO(hayk): Add a normalize boolean argument? Like in `cam.Camera`

        Return:
            camera_ray: The ray in the camera frame (NOT normalized)
            is_valid: 1 if the operation is within bounds else 0
        """

        return ops.CameraOps.camera_ray_from_pixel(self, pixel, epsilon)

    def camera_ray_from_pixel_with_jacobians(self, pixel, epsilon):
        # type: (LinearCameraCal, T.Union[T.Sequence[float], numpy.ndarray], float) -> T.Tuple[numpy.ndarray, float, numpy.ndarray, numpy.ndarray]
        """
        Backproject a 2D pixel coordinate into a 3D ray in the camera frame.

        Return:
            camera_ray: The ray in the camera frame (NOT normalized)
            is_valid: 1 if the operation is within bounds else 0
            point_D_cal: Derivative of point with respect to intrinsic calibration parameters
            point_D_pixel: Derivation of point with respect to pixel
        """

        return ops.CameraOps.camera_ray_from_pixel_with_jacobians(self, pixel, epsilon)

    # --------------------------------------------------------------------------
    # StorageOps concept
    # --------------------------------------------------------------------------

    @staticmethod
    def storage_dim():
        # type: () -> int
        return 4

    def to_storage(self):
        # type: () -> T.List[float]
        return list(self.data)

    @classmethod
    def from_storage(cls, vec):
        # type: (T.Sequence[float]) -> LinearCameraCal
        instance = cls.__new__(cls)

        if isinstance(vec, list):
            instance.data = vec
        else:
            instance.data = list(vec)

        if len(vec) != cls.storage_dim():
            raise ValueError(
                "{} has storage dim {}, got {}.".format(cls.__name__, cls.storage_dim(), len(vec))
            )

        return instance

    # --------------------------------------------------------------------------
    # LieGroupOps concept
    # --------------------------------------------------------------------------

    @staticmethod
    def tangent_dim():
        # type: () -> int
        return 4

    @classmethod
    def from_tangent(cls, vec, epsilon=1e-8):
        # type: (T.Union[T.Sequence[float], numpy.ndarray], float) -> LinearCameraCal
        return ops.LieGroupOps.from_tangent(vec, epsilon)

    def to_tangent(self, epsilon=1e-8):
        # type: (float) -> numpy.ndarray
        return ops.LieGroupOps.to_tangent(self, epsilon)

    def retract(self, vec, epsilon=1e-8):
        # type: (T.Union[T.Sequence[float], numpy.ndarray], float) -> LinearCameraCal
        return ops.LieGroupOps.retract(self, vec, epsilon)

    def local_coordinates(self, b, epsilon=1e-8):
        # type: (LinearCameraCal, float) -> numpy.ndarray
        return ops.LieGroupOps.local_coordinates(self, b, epsilon)

    def interpolate(self, b, alpha, epsilon=1e-8):
        # type: (LinearCameraCal, float, float) -> LinearCameraCal
        return ops.LieGroupOps.interpolate(self, b, alpha, epsilon)

    # --------------------------------------------------------------------------
    # General Helpers
    # --------------------------------------------------------------------------
    def __eq__(self, other):
        # type: (T.Any) -> bool
        if isinstance(other, LinearCameraCal):
            return self.data == other.data
        else:
            return False
