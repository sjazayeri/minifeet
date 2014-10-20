#!/usr/bin/env python
import math
from referee import Referee
from geometry import Vector
from objects import Ball , Player
from sys import stderr, stdout

class Cycle:
    def __init__(self):
        self.commands = {'kick':self.kick, 'move':self.move,
                         'nop':lambda s:None}
        self.state = None
        self.max_ball_dist = 2
        self.BallVelUnit = 10
        self.PlayerVel = 5
        
    def update_players(self,state):
        """parses commands of players and updates
        the state of them and the ball"""
        self.state=state
        self.state.last_kicked=None
        for p in self.state.players:
            ss=p.comm.get_command().split(' ')
            self.commands[ss[0]](p,*map(float, ss[1:]))
    def kick(self,p,angle,force):
        if math.fabs((p.pos-self.state.ball.pos).len()-self.max_ball_dist) > 0:
            print 'PLAYER %d, %d KICKED TO %f, WITH FORCE %f'%(p.team, p.number, angle, force)
            #state.last_kicked=p
            #state.ball.vel=self.BallVelUnit*strength
            #state.ball.angle=angle
            force = max(force, 1)
            self.state.ball.vel += Vector(self.BallVelUnit*force*math.cos(angle), self.BallVelUnit*force*math.sin(angle))
    def move(self,p,angle,distance):
        vel=min(distance,self.PlayerVel)
        #print >>stderr, 'PLAYER %d, %d: %f, %f'
        p.vel=Vector(vel*math.cos(angle),vel*math.sin(angle))
