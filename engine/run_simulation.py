#!/usr/bin/env python
import sys
import state
from objects import Ground ,Ball , Player
from geometry import Vector
import state
import time

cycle_length = 100
game_duration = 18000

gwidth = 90
glength = 120
gfriction = 1

indexi = [0 , 1/3 , -1/3 , 2/3 , -2/3]
indexj = [1 , 2/3 , 2/3 , 1/3 , 1/3 ]

visualizer = sp.Popen(None, stdin=sp.PIPE)

def send_data( state ) :
    for i in range(10):
        visualizer.stdin.write(state.players[i].pos.x) 
        visualizer.stdin.write(state.players[i].pos.y) 
    visualizer.stdin.write(state.ball.pos.x) 
    visualizer.stdin.write(state.ball.pos.y) 

if __name__ =='__main__':

    ppath = sys.argv
    progs = [sys.argv[1], sys.argv[2]]
    ground = Ground(glength , gwidth ,gfriction )
    players=[]
    for i in range(2):
            for j in range(5):
                players.append(Player( progs[i] , i+1 , j+1 , Vector( indexi[j]*gwidth/2  ,  indexj[j]*glength/2 *(-1)**(i) ) ))
    ball = Ball()
    state = State( players , ball )

    for i in xrange(game_duration):
        send_data(state)
        time.sleep(cycle_length)
    
    visualizer.terminate()
