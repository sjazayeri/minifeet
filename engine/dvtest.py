#!/usr/bin/env python
import subprocess as sp
import time

cat = sp.Popen('cat', stdin=sp.PIPE)
for i in xrange(100):
    cat.stdin.write('hah\n')
    #time.sleep(1)
