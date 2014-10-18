#!/usr/bin/env python
import math
from referee import Referee
from geometry import Vector
from objects import Ball , Player
from sys import stderr

"""a static class for performing each cycle tasks"""
class Cycle:
    def __init__(self):
        self.commands = {'kick':self._kick, 'move':self._move}
        self._players = []
        self._state = None
        # _ball=None
        self.MaxBallDis = 10
        self.BallVelUnit = 100
        self.PlayerVel = 20
    """parses commands of players and updates
    the state of them and the ball"""
    def update_players(self, players,ball,state):
        Cycle._players=players
        #Cycle._ball=ball
        state.last_kicked=None
        _state=state
        #print >>stderr, players
        for p in players:
            ss=p.comm.get_command().split(' ')
            self.commands[ss[0]](p,*map(int, ss[1:]))
    def _kick(p,angle,strength):
        if len(p.pos-ball.pos) <= Cycle.MaxBallDis:
            state.last_kicked=p
            ball.vel=Cycle.BallVelUnit*strength
            ball.angel=angle
    def _move(p,angle,distance):
        vel=min(distance,Cycle.PlayerVel)
        p.vel=Vector(vel*math.cos(angel),vel*math.sin(angel))#
