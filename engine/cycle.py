#!/usr/bin/env python
import math
from referee import Referee
from geometry import Vector
from objects import Ball , Player
from sys import stderr

class Cycle:
    def __init__(self):
        self.commands = {'kick':self._kick, 'move':self._move,
                         'nop':lambda s:None}
        self._state = None
        self.MaxBallDis = 10
        self.BallVelUnit = 100
        self.PlayerVel = 20
        
    def update_players(self,state):
        """parses commands of players and updates
        the state of them and the ball"""
        self._state=state
        state.last_kicked=None
        for p in state.players:
            ss=p.comm.get_command().split(' ')
            #print >>stderr, ss
            self.commands[ss[0]](p,*map(float, ss[1:]))
    def _kick(self,p,angle,strength):
        if len(p.pos-ball.pos) <= self.MaxBallDis:
            _state.last_kicked=p
            _state.ball.vel=self.BallVelUnit*strength
            _state.ball.angel=angle
    def _move(self,p,angle,distance):
        vel=min(distance,self.PlayerVel)
        p.vel=Vector(vel*math.cos(angle),vel*math.sin(angle))
