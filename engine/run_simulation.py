#!/usr/bin/env python
import sys
import state
from objects import Ground ,Ball , Player
from geometry import Vector
import state

gwidth = 90
glength = 120
gfriction = 1

indexi = [0 , 1/3 , -1/3 , 2/3 , -2/3]
indexj = [1 , 2/3 , 2/3 , 1/3 , 1/3 ]

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
    state.send_data()
