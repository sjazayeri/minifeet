#!/usr/bin/python
from geometry import Vector
from sys import stderr, stdout, exit
import time

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
        print 'move %f %f'%(ballpos.x, ballpos.y)
        stdout.flush()
       # print >>stderr, 'SENT COMMAND AT %f'%(time.time())
