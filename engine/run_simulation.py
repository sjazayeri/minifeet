#!/usr/bin/python
import sys
import state
import config
from objects import Ground ,Ball , Player
from geometry import Vector
import time
import subprocess as sp
from referee import Referee
from state import State
from cycle import Cycle
import random

cycle_length = 0.1
game_duration = 200

indexi = [0 , 1.0/3 , -1.0/3 , 2.0/3 , -2.0/3]
indexj = [1 , 2.0/3 , 2.0/3 , 1.0/3 , 1.0/3 ]

class Simulator(object):
    def __init__(self ,progs, visualizer,gwidth = 90, glength = 120 , gfriction = 1):
        self.cycle = Cycle()
        self.ground = Ground(glength , gwidth ,gfriction )
        self.players =[]
        for i in range(2):
            for j in range(5):
                self.players.append(Player(self.ground, progs[i] , i , j , Vector( ((1.0*indexi[j]) * (gwidth / 2))  , (1.0*indexj[j]) * (glength / 2) * ((-1) ** (i)) ) ))
                #print >>sys.stderr, 'PLAYER %d, %d: %f, %f'%(i, j, self.players[j].pos.x, self.players[j].pos.y)
                #print >>sys.stderr, 'PLAYER %d, %d: %f, %f'%(i, j, indexi[j] * gwidth / 2, indexj[j] * glength / 2 * (-1) ** (i))
                self.ball = Ball(self.ground)
        self.state = State(self.players , self.ball)
        self.referee = Referee(self.state)
        self.visualizer = visualizer

    def send_data(self):
        for i in range(10):
            self.visualizer.stdin.write(`int(self.state.players[i].pos.x)`+'\n') 
            self.visualizer.stdin.write(`int(self.state.players[i].pos.y)`+'\n')
            #print >>sys.stderr, 'THIS IS RS, PLAYER %d: %d, %d'%(i, int(self.state.players[i].pos.x), int(self.state.players[i].pos.y)) 
        self.visualizer.stdin.write(`int(self.state.ball.pos.x)`+'\n') 
        self.visualizer.stdin.write(`int(self.state.ball.pos.y)`+'\n')
        self.visualizer.stdin.write(`self.state.game_state `+'\n') 
        
    def player_move(self, i , coefficient=1.0/100):
        self.players[i].move(coefficient)
         
    def ball_move(self , coefficient=1.0/100):
        self.ball.move(coefficient)
        
        width = self.ground.width
        length = self.ground.length
        while True:
            x = self.ball.pos.x 
            y = self.ball.pos.y
            if x <= width/2 and x >= -width/2 and y <= length/2 and y >= -length/2:
                break

            print >>sys.stderr, 'BALL IS OUTSIDE GROUND, VELOCITY IS: %f, %f'%(self.ball.vel.x, self.ball.vel.y)
                
            if x>(width/2) :
                self.ball.vel.x= -self.ball.vel.x
                self.ball.pos.x= width-x
                print >>sys.stderr, 'THE BALL WENT TOO RIGHT, NEW X: %f'%(self.ball.pos.x)
       
            if x<-(width/2) :
                self.ball.vel.x= -self.ball.vel.x
                self.ball.pos.x= -width-x
                print >>sys.stderr, 'THE BALL WENT TOO LEFT, NEW X: %f'%(self.ball.pos.x)
            
            if y>(length/2) :
                self.state.update( self.referee.is_goal(self.ball , self.ground) )
                self.ball.vel.y= -self.ball.vel.y
                self.ball.pos.y= length-y
                print >>sys.stderr, 'THE BALL WENT TOO UP, NEW Y: %f'%(self.ball.pos.y)
            
            if y<(-(length/2)) :
                self.state.update( self.referee.is_goal(self.ball , self.ground) )
                self.ball.pos.y= -length-y
                self.ball.vel.y=-self.ball.vel.y
                print >>sys.stderr, 'THE BALL WENT TOO DOWN, NEW Y: %f'%(self.ball.pos.y)

         
    def check_pos(self , coefficient=1.0/100):
        a = range(10)    
        random.shuffle(a)
        sizes = [i/20.0 for i in xrange(1, 11)]
        random.shuffle(sizes)
        for i in a:
            temp_pos = self.players[i].pos
            for j in range(10):
                if( ( self.players[j].is_overlap(sizes[i], sizes[j], temp_pos) ) and (j!=i)):
                    self.players[i].move(-coefficient)
                    break        
        
    def move(self):
        for j in xrange(100):
            for i in xrange(10):
                self.player_move(i)
            self.ball_move()
            self.check_pos()

    def goto_kickoff(self):
        self.ball.pos = Vector(0, 0)
        self.ball.vel = Vector(0, 0)
        gwidth = config.gwidth
        glength = config.glength
        for i in xrange(2):
            for j in xrange(5):
                self.players[i*5+j].pos=Vector( ((1.0*indexi[j]) * (gwidth / 2))  , (1.0*indexj[j]) * (glength / 2) * ((-1) ** (i)) )
                self.players[i*5+j].vel = Vector(0, 0)
            
    def simulate(self) :
        global cycle_length
        print self.state.game_state
        for i in xrange(game_duration):
            self.referee.update_state()
            self.send_data()
            #self.state.update()
            for j in xrange(10):
                self.players[j].comm.send_state(self.state)
            #print >>sys.stderr, 'DOOOOOOOOOOOOOOOOOOOOOOONE SENDING DATA AT %f'%(time.time())
            time.sleep(cycle_length)
            self.cycle.update_players(self.state)
            self.move()
            if self.state.game_state==state.team1_goal:
                self.state.game_state = state.kickoff_team2
                self.goto_kickoff()
            if self.state.game_state==state.team2_goal:
                self.state.game_state = state.kickoff_team1
                self.goto_kickoff()
            if(self.state.last_kicked != None):
                pass
        for i in xrange(10):
            self.players[i].comm.terminate()
        
if __name__ =='__main__':
    ppath = sys.argv
    progs = [sys.argv[1], sys.argv[2]]
    visualizer = sp.Popen('../visualizer/a.out', stdin=sp.PIPE)
    sim = Simulator(progs, visualizer)
    sim.simulate()
    visualizer.terminate()
    
    
    
