#!/usr/bin/python

from sys import stderr

while True:
    for i in xrange(11):
        try:
            x, y = map(float, raw_input().split(' '))
        except EOFError:
            break
        print x, y
