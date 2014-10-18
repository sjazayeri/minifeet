#!/usr/bin/python
from geometry import Vector
from sys import stderr

if __name__=='__main__':
    team, number = map(int, raw_input().split(' '))
    players = []
    for i in xrange(10):
        x, y = map(int, raw_input().split(' '))
        players.append(Vector(x, y))
            
    selfpos = players[5*team+number]
    ballpos = Vector(*map(int, raw_input().split(' ')))
    game_state = int(raw_input())
    print 'move %d %d'%(ballpos.x, ballpos.y)
