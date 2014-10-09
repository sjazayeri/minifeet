"""This module contains functions and classes to facilitate geometrical
calculations"""

class Vector:
    """A point on the cartesian plane.
    Point(x, y) -> Point referring to (x, y) on the plane"""
    def __init__(self, x, y):
        self.x = x
        self.y = y
