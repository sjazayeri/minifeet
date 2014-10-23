#!/usr/bin/python
from geometry import Vector, epsilon
from sys import stderr, stdout, exit
from utils import *
import time


def get_position(team, number, ballpos):
    pos = Vector(0, 0)
    if number == 1:
        pass
    elif number == 2:
        pass
    elif number == 3:
        pass
    elif number == 4:
        pass
    elif number == 5:
        pass
    if team == 1:
        pos.y = pos.y * -1


def move(position):
    print 'move %f %f' % (position.x, position.y)
    stdout.flush()


def kick(target, power):
    print 'kick %f %f %f' % (target.x, target.y, power)
    stdout.flush()


def get_ball_receiver():
    pass


def kick_action():
    pass


if __name__=='__main__':
    team, number = map(int, raw_input().split(' '))
    while True:
        players = get_players()
        selfpos = players[5 * team + number]
        ballpos = Vector(*map(float, raw_input().split(' ')))
        game_state = int(raw_input())
        #print >>stderr, 'GOT DATA AT %f'%(time.time())

        position = get_position(team, number, ballpos)
        move(position)
        # print >>stderr, 'SENT COMMAND AT %f'%(time.time())
