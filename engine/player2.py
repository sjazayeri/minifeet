#!/usr/bin/python
from geometry import Vector, epsilon
from sys import stderr, stdout, exit
import time

max_ball_dist = 2

if __name__=='__main__':
    team, number = map(int, raw_input().split(' '))
    while True:
        players = []
        for i in xrange(10):
            x, y = map(float, raw_input().split(' '))
            players.append(Vector(x, y))
            
        selfpos = players[5*team+number]
        ballpos = Vector(*map(float, raw_input().split(' ')))
        game_state = int(raw_input())
        #print >>stderr, 'GOT DATA AT %f'%(time.time())
        if (ballpos-selfpos).len()<2:
            balldest = ballpos+Vector(-10, 10)
            print 'kick %f %f %f'%(balldest.x, balldest.y, 100.0)
        else:
            print 'move %f %f'%(ballpos.x, ballpos.y)
        stdout.flush()
       # print >>stderr, 'SENT COMMAND AT %f'%(time.time())
