"""This module contains functions and classes to facilitate geometrical
calculations"""

class Vector:
    """A vector in the cartesian plane
    Vector(x, y) -> creates a vector
    """
    def __init__(self, x, y):
        self.x = x
        self.y = y
        
    def __add__(self, u):
        return Vector(self.x+u.x, self.y+u.y)

    def __iadd__(self, u):
        self.x += u.x
        self.y += u.y
        return self

    def __mul__(self, s):
        return Vector(s*self.x, s*self.y)

    def __imul__(self, s):
        self.x *= s
        self.y *= s
        return self

    def __int__(self):
        return (self.x-self.y)**(1.0/2)

    def __sub__(self, u):
        return Vector(self.x-u.x,self.y-u.y)