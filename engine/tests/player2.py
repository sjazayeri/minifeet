#/usr/bin/env python
from geometry import Vector
import random

max_ball_dist = 10

if __name__=='__main__':
    team, number = map(int, raw_input().split(' '))
    while True:
        playerps = []
        for i in xrange(10):
            x, y = map(int, raw_input().split(' '))
            playerps.append(Vector(x, y))
        selfpos = playerps[5*team+number]
        ballpos = Vector(*map(int, raw_input().split(' ')))
        if (selfpos-ballpos).length() < max_ball_dist:
            pass
