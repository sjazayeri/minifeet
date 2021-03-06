#!/usr/bin/env python
import math
import state
from referee import Referee
from geometry import Vector
from objects import Ball , Player
from sys import stderr, stdout

class Cycle:
    def __init__(self):
        self.commands = {'kick':self.kick, 'move':self.move,
                         'nop':self.nop}
        self.state = None
        self.max_ball_dist = 2
        self.BallVelUnit = 10
        self.PlayerVel = 5
        
    def update_players(self, cstate):
        """parses commands of players and updates
        the state of them and the ball"""
        self.state=cstate
        self.state.last_kicked=None
        bad_state = {0:state.kickoff_team2, 1:state.kickoff_team1}
        for p in self.state.players:
            ss=p.comm.get_command().split(' ')
            if self.state.game_state==bad_state[p.team]:
                continue
            self.commands[ss[0]](p,*map(float, ss[1:]))
            
    def kick(self,p,angle,force):
        if math.fabs((p.pos-self.state.ball.pos).len()-self.max_ball_dist) > 0:
            #print 'PLAYER %d, %d KICKED TO %f, WITH FORCE %f'%(p.team, p.number, angle, force)
            self.state.last_kicked=p
            self.state.kicked = True
            #state.ball.vel=self.BallVelUnit*strength
            #state.ball.angle=angle
            force = min(force, 1)
            #print >>stderr, 'KICKING BALL, INIT VEL: %f, %f'%(self.state.ball.vel.x, self.state.ball.vel.y)
            self.state.ball.vel += Vector(self.BallVelUnit*force*math.cos(angle), self.BallVelUnit*force*math.sin(angle))
            #print >>stderr, 'DONE KICKING, FINAL VEL: %f, %f'%(self.state.ball.vel.x, self.state.ball.vel.y)

    def move(self,p,angle,distance):
        vel=min(distance,self.PlayerVel)
        #print >>stderr, 'PLAYER %d, %d: %f, %f'
        p.vel=Vector(vel*math.cos(angle),vel*math.sin(angle))

    def nop(self, p):
        p.vel = Vector(0, 0)
