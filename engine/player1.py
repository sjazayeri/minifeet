#/usr/bin/env python
from geometry import Vector
from sys import stderr
#sys.path.append('/home/msj/programming/minifeet/engine')

if __name__=='__main__':
    team, number = map(int, raw_input().split(' '))
    #inp = raw_input()
    #print >>stderr, 'TEAM: %d, NUMBER: %d'%(team, number)
    while True:
        playerps = []
        for i in xrange(10):
            x, y = map(int, raw_input().split(' '))
            print >>stderr, 'X: %d Y: %d\n'%(x, y)
            playerps.append(Vector(x, y))
            
        selfpos = playerps[5*team+number]
        ballpos = Vector(*map(int, raw_input().split(' ')))
        game_state = int(raw_input())
        print 'move %d %d'%(ballpos.x, ballpos.y)
