#!/usr/bin/python
from geometry import Vector
from sys import stderr

if __name__=='__main__':
    team, number = map(int, raw_input().split(' '))
    while True:
        players = []
        for i in xrange(10):
            #print >>stderr, 'waiting %d'%(i)
            x, y = map(float, raw_input().split(' '))
            players.append(Vector(x, y))
            #print >>stderr, 'DONE'
        
        selfpos = players[5*team+number]
        ballpos = Vector(*map(float, raw_input().split(' ')))
        game_state = int(raw_input())
        #print >>stderr, '%d\n'%(game_state) 
        print 'move %d %d'%(ballpos.x, ballpos.y)
        print >>stderr, 'printed'
