#!/usr/bin/env python
import sys
import state
from objects import Ground ,Ball , Player
from geometry import Vector
import time
import subprocess as sp
from refree import Refree
from cycle import Cycle
import random

cycle_length = 100
game_duration = 1000

indexi = [0 , 1/3 , -1/3 , 2/3 , -2/3]
indexj = [1 , 2/3 , 2/3 , 1/3 , 1/3 ]

class Simulator :

    def __init__(self ,progs , gwidth = 90 , glength = 120 , gfriction = 1):
        self.ground = Ground(glength , gwidth ,gfriction )
        self.players =[]
        for i in range(2):
            for j in range(5):
                players.append(Player( progs[i] , i+1 , j+1 , Vector( indexi[j]*gwidth/2  ,  indexj[j]*glength/2 *(-1)**(i) ) )) 
        self.ball = Ball(Vector(0,0) , Vector(0,0))
        self.state = State( players , ball )

    def send_data(self, state , visualizer ) :
        for i in range(10):
            visualizer.stdin.write(`state.players[i].pos.x`+' ') 
            visualizer.stdin.write(`state.players[i].pos.y`+'\n') 
        visualizer.stdin.write(`state.ball.pos.x`+' ') 
        visualizer.stdin.write(`state.ball.pos.y`+'\n')
        
    def player_move(self, i , coefficient=1.0/100):
        players[i].move(coefficient)
         
    def ball_move(self , coefficient=1.0/100):
        ball.move(coefficient)
        
        x = ball.pos.x 
        y = ball.pos.y
        width = ground.gwidth
        length = ground.glength
        
        if x>(width/2) :
            self.vx= -vx
            self.x= width-x
       
        if x<-(width/2) :
            self.vx= -vx
            self.x= -width-x
            
        if y>(length/2) :
            self.vy= -vy
            self.y= length-y
            Refree.is_goal(ball , ground)
            
        if y<(-(length/2)) :
            self.y= -length-y
            self.vy=-vy
            Refree.is_goal(ball , ground)          
         
    def check_pos(self , coefficient=1.0/100):
        a = range(10)    
        random.shuffle(a)
        for i in a:
            pos = players[i].pos
            for j in range(10):
                if( (pos == players[j].pos) && (j!=i))
                    players[i].move(-coefficient)
                    break        
        
    def move(self):
        for j in xrange(100):
            for i in xrange(10):
                player_move(i)
            ball_move()
            check_pos()
        
        
if __name__ =='__main__':

    ppath = sys.argv
    progs = [sys.argv[1], sys.argv[2]]
    sim = Simulator(progs) 
    visualizer = sp.Popen('rs_debug/dv.py', stdin=sp.PIPE)
           
    for i in xrange(game_duration):
        sim.send_data(state , visualizer)
        time.sleep(cycle_length)
        Cycle.update_players(state.players, state.ball)
        sim.move()
       
    visualizer.terminate()
