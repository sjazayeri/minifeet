#!/usr/bin/env python
import math
from geometry import Vector
from objects import Ball , Player

"""a static class for performing each cycle tasks"""
class Cycle:
    commands={'kick':_kick,'turn':_turn,'move':_move}
    _players=[]
    _ball=None
    MaxBallDis=10
    BallVelUnit=100
    PlayerVel=20
    """parses commands of players and updates
    the state of them and the ball"""
    @classmethod
    def update_players(players,ball):
        _players=players
        _ball=ball
        for p in players:
            ss=p.comm.get_command().split(' ')
            commands[ss[0]](p,*map(int, ss[1:]))
    def _kick(p,angle,strength):
        if int(p.pos-ball.pos) <= MaxBallDis:
            ball.vel=BallVelUnit*strength
            ball.angel=angle
    def _move(p,angle):
        p.vel=Vector(PlayerVel*math.cos(angel),PlayerVel*math.sin(angel))