from collections import defaultdict
from geometry import Vector
import subprocess as sp
import select
from proxy import Proxy

class MovingObj:
    def __init__ (self ) :
        self.pos = Vector(0, 0)
        self.vel = Vector(0 , 0)
        self.ground = None
    def move (self) :
        raise NotImplementedError ()

class Player(MovingObj):
    """Player(program_path, team, number, loc) -> create object to run
    and interface with player program"""
    def __init__(self, ppath, team, number, pos):
        self.ppath=ppath
        self.team=team
        self.number=number
        self.pos=pos   
        self.comm = Proxy(ppath, self)     
        
    def move(self, coefficient=1):
        self.pos += (self.vel * coefficient)
        length = self.ground.length
        width = self.ground.width
        if y>(length/2) :
            y=length/2
        if y<-(length/2) :
            y=-length/2
        if x>(width/2) :
            x=width/2
        if x<-(width/2) :
            x=-width/2
            
    def is_overlap(self , pos2):
        diff = pos2 - self.pos
        if( diff.len() < 0.2 ):
            return True
        return False
            
class Ball (MovingObj) :
    def move ( self ,coefficient=1):
        if(self.ground.friction.len() >= (self.vel.len() * coefficient)):
            vel=Vector(0 , 0)
            return
            
        pos = self.pos + (vel * coefficient) + self.ground.friction

class Ground :
    def __init__( self  , length = 0 , width =0 , friction = 0 , gate_length=0 ) :
        self.length = length
        self.width = width
        self.friction = Vector(friction ,friction )
        self.gate=gate_length

                
