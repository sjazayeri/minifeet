from collections import defaultdict
from geometry import Vector
import subprocess as sp
import select
import math
from proxy import Proxy
from sys import stderr

player_size = 0.5

class MovingObj(object):
    def __init__(self, ground):
        self.pos = Vector(0, 0)
        self.vel = Vector(0 , 0)
        self.ground = ground
    def move (self) :
        raise NotImplementedError ()

class Player(MovingObj):
    """Player(program_path, team, number, loc) -> create object to run
    and interface with player program"""
    def __init__(self, ground, ppath, team, number, pos):
        super(Player, self).__init__(ground)
        self.ppath=ppath
        self.team=team
        self.number=number
        self.pos=pos
        self.comm = Proxy(ppath, self)     
        
    def move(self, coefficient=1):
        self.pos += (self.vel * coefficient)
        length = self.ground.length
        width = self.ground.width
        if self.pos.y>(length/2) :
            self.pos.y=length/2
        if self.pos.y<-(length/2) :
            self.pos.y=-length/2
        if self.pos.x>(width/2) :
            self.pos.x=width/2
        if self.pos.x<-(width/2) :
            self.pos.x=-width/2
            
    def is_overlap(self, r1, r2, pos2):
        #global player_size
        diff = pos2 - self.pos
        if( diff.len() < r1+r2):
            return True
        return False
            
class Ball (MovingObj) :
    def move (self,coefficient=1):
        #pv = self.vel
        if(self.ground.friction.len()*coefficient >= (self.vel.len() * coefficient)):
            self.vel=Vector(0 , 0)
            #if self.pv.len()>0:
            #    print >>stderr, 'ZEROED BALL VELOCITY'
            #    raw_input()
            return
        #print >>stderr, 'MOVING BALL, INIT VEL: %f, %f'%(self.vel.x, self.vel.y)    
        self.vel.x -= math.copysign(self.ground.friction.x*coefficient,
                                    self.vel.x)
        self.vel.y -= math.copysign(self.ground.friction.y*coefficient,
                                    self.vel.y)
        self.pos += self.vel*coefficient
        #print >>stderr, 'DONE MOVING, FINAL VEL: %f, %f' %(self.vel.x, self.vel.y)

class Ground(object):
    def __init__(self, length=0, width =0, friction=0, gate_length=20):
        self.length = length
        self.width = width
        self.friction = Vector(friction ,friction )
        self.gate=gate_length

                
