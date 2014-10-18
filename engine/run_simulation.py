#!/usr/bin/env python
import sys
import state
from objects import Ground ,Ball , Player
from geometry import Vector
import time
import subprocess as sp
from referee import Referee
from state import State
from cycle import Cycle
import random

cycle_length = 100
game_duration = 1000

indexi = [0 , 1/3 , -1/3 , 2/3 , -2/3]
indexj = [1 , 2/3 , 2/3 , 1/3 , 1/3 ]

class Simulator :

    def __init__(self ,progs , gwidth = 90 , glength = 120 , gfriction = 1):
        self.cycle = Cycle()
        self.ground = Ground(glength , gwidth ,gfriction )
        self.players =[]
        for i in range(2):
            for j in range(5):
                self.players.append(Player(progs[i] , i , j , Vector(indexi[j] * gwidth / 2  , indexj[j] * glength / 2 * (-1) ** (i))))
        self.ball = Ball(Vector(0,0) , Vector(0,0))
        self.state = State(self.players , self.ball)

    def send_data(self, state , visualizer ) :
        for i in range(10):
            visualizer.stdin.write(`state.players[i].pos.x`+' ') 
            visualizer.stdin.write(`state.players[i].pos.y`+'\n') 
        visualizer.stdin.write(`state.ball.pos.x`+' ') 
        visualizer.stdin.write(`state.ball.pos.y`+'\n')
        
    def player_move(self, i , coefficient=1.0/100):
        self.players[i].move(coefficient)
         
    def ball_move(self , coefficient=1.0/100):
        self.ball.move(coefficient)
        
        x = self.ball.pos.x 
        y = self.ball.pos.y
        width = self.ground.gwidth
        length = self.ground.glength
        
        if x>(width/2) :
            self.ball.vel.x= -vx
            self.ball.pos.x= width-x
       
        if x<-(width/2) :
            self.ball.vel.x= -vx
            self.ball.pos.x= -width-x
            
        if y>(length/2) :
            self.ball.vel.y= -vy
            self.ball.pos.y= length-y
            self.state.update( Refree.is_goal(ball , ground) )
            
        if y<(-(length/2)) :
            self.ball.vel.y= -length-y
            self.ball.pos.y=-vy
            self.state.update( Refree.is_goal(ball , ground) )       
         
    def check_pos(self , coefficient=1.0/100):
        a = range(10)    
        random.shuffle(a)
        for i in a:
            pos = self.players[i].pos
            for j in range(10):
                if( ( self.players[j].is_overlap(pos) ) and (j!=i)):
                    self.players[i].move(-coefficient)
                    break        
        
    def move(self):
        for j in xrange(100):
            for i in xrange(10):
                self.player_move(i)
            self.ball_move()
            self.check_pos()
            
    def simulate(self) :
        for i in xrange(game_duration):
            self.send_data(state , visualizer)
            self.state.update(0)
            for j in range(10):
                self.players[j].comm.send_state(state)
            time.sleep(cycle_length)
            self.cycle.update_players(state.players, state.ball)
            self.move()
            if(self.state.last_kicked != None):
                pass
       
if __name__ =='__main__':

    ppath = sys.argv
    progs = [sys.argv[1], sys.argv[2]]
    sim = Simulator(progs) 
    visualizer = sp.Popen('rs_debug/dv.py', stdin=sp.PIPE)
    sim.simulate()
    visualizer.terminate()
    
    
    
