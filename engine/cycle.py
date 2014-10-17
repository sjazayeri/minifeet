#!/usr/bin/env python
import math
from geometry import Vector
from objects import Ball , Player

#hjshdjahjda

"""a static class for performing each cycle tasks"""
class Cycle:
    commands={'kick':_kick,'turn':_turn,'move':_move}
    _players=[]
    _ball=None
    MaxBallDis=10
    MaxBallVel=100
    PlayerVel=20
    """parses commands of players and updates
    the state of them and the ball"""
    def update_players(players,ball):
        _players=players
        _ball=ball
        for p in players:
            ss=p.comm.get_command().split(' ')
            commands[ss[0]](ss[1%len(ss)],p)
    def _kick(arg,p):
        if (int)(p.pos-ball.pos) <= MaxBallDis:
            ball.vel=MaxBallVel
            ball.angel=arg
    def _turn(arg,p):
        p.angel=arg
    def _move(arg,p):
        p.vel=PlayerVel
