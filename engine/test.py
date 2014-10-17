from run_simulation import send_data
from geometry import Vector
import subprocess as sp
from objects import Ball

visualizer = sp.Popen('rs_debug/dv.py', stdin=sp.PIPE)

class P:
    def __init__(self , pos):
        self.pos = pos
        
class S:
    def __init__(self , p):
        self.players=p
        self.ball =Ball(Vector(0,0) , Vector(0,0)) 
 
p=[]
     
for i in xrange(10):
    p.append(P(Vector(i+1 , i+5)))
            
state = S(p)

send_data( state , visualizer )
visualizer.terminate()
