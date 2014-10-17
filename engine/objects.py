from collections import defaultdict
from geometry import Vector
import subprocess as sp
import select
import proxy

class MovingObj:
    def __init__ (self , pos=Vector(0, 0) , vel =Vector(0 , 0 ) , ground=None ) :
        self.ground = ground
        self.pos=pos
        self.vel=vel
    def move (self) :
        raise NotImplementedError ()
   

class Player(MovingObj):
    """Player(program_path, team, number, loc) -> create object to run
    and interface with player program"""
    def __init__(self, ppath, team, number, pos):
        self.team=team
        self.number=number
        self.pos=pos        
        self.comm=Proxy(ppath , self)

    def move(self, x, y):
        pos+=vel
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
    def __init__( self  , length = 0 , width =0 , friction = 0 ) :
        self.length = length
        self.width = width
        self.friction = Vector(friction ,friction )

        
class Ball (MovingObj) :
    def move ( self ):
        m+=v
        m+=ground.friction
        if vx<0 :
            vx=0
        if vy<0 :
            vy=0
        length = self.ground.length
        width = self.ground.width
        if y>(length/2) :
            self.vy= -vy
            self.y= length-y
        if x>(width/2) :
            self.vx= -vx
            self.x= width-x
        if y<(-(length/2)) :
            self.y= -length-y
            self.vy=-vy
        if x<-(width/2) :
            self.vx= -vx
            self.x= -width-x

