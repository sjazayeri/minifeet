#!/usr/bin/env python
while True:
    try:
        for i in xrange(5):
            x, y = map(int, raw_input().split(' '))
            #print 'TEAM1 ', 'PLAYER '+`i`+': '+`x`+
            print 'TEAM1 PLAYER#%d X:%d Y:%d'%(i, x, y) 
        for i in xrange(5):
            x, y = map(int, raw_input().split(' '))
            #print 'TEAM1 ', 'PLAYER '+`i`+': '+`x`+
            print 'TEAM2 PLAYER#%d X:%d Y:%d'%(i, x, y)
        x, y = map(int, raw_input().split(' '))
        print 'BALL X:%d Y:%d'%(x, y)
        
    except EOFError:
        break
