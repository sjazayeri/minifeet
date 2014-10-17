from collections import defaultdict
from geometry import Vector
import subprocess as sp
import select

class MovingObj:
    def __init__ (self , pos=Vector(0, 0) , vel = Vector(0 , 0),   ground=None ) :
        self.ground = ground
        self.pos=pos
        self.vel=vel
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
##
    def move(self, coefficient=1):
        pos+=(vel*coefficient)
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
#CHANGE
            
class Ground :
    def __init__( self  , length = 0 , width =0 , friction = 0 , gate_length=0 ) :
        self.length = length
        self.width = width
        self.friction = Vector(friction ,friction )
        self.gate=gate_length

        
class Ball (MovingObj) :
    def move ( self ,coefficient=1):
        if(ground.friction.len() >= (vel.len()*coefficient) )
            vel=Vector(0 , 0)
            return
            
        pos = pos+(vel*coefficient)+ground.friction
        
