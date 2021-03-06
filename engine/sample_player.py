#!/usr/bin/python
from geometry import Vector, epsilon
from sys import stderr, stdout, exit
from utils import *
import time
from random import random


class Player():
    def run(self):
        self.last_move_pos = Vector(0, 0)
        self.team, self.number = map(int, raw_input().split(' '))
        while True:
            players = get_players(self.team)
            selfpos = players[5 * self.team + self.number]
            self.self_pos = selfpos
            self._players = players
            ballpos = get_ballpos(self.team)
            game_state = int(raw_input())
            # print >>stderr, 'GOT DATA AT %f'%(time.time())

            ball_receiver = self.get_ball_receiver(players, ballpos)
            if self.number == ball_receiver:
                if (selfpos - ballpos).len() < 2:
                    self.kick_action(ballpos)
                else:
                    self.move(ballpos)
            else:
                position = self.get_target_position(self.number, ballpos)
                if (selfpos - position).len() > 2:
                    self.move(position)

            # print >>stderr, 'SENT COMMAND AT %f'%(time.time())

    def get_target_position(self, number, ballpos):
        pos = Vector(0, 0)
        if number == 0:
            pos = Vector(0, -45)
        elif number == 1:
            pos = Vector(5, -30)
        elif number == 2:
            pos = Vector(-20, -20)
        elif number == 3:
            pos = Vector(20, -20)
        elif number == 4:
            pos = Vector(0, 0)
        return pos

    def move(self, position):
        if self.team == 0:
            position.x *= -1
            position.y *= -1
        if (self.last_move_pos-position).len() < 0.3 and self.nearest_opponent_dist() < 2:
            vec = Vector(-2 + int(random()*2) * 2, -2 + int(random() * 2) * 2)
            position = self.self_pos + vec
        print 'move %f %f' % (position.x, position.y)
        stdout.flush()
        self.last_move_pos = position

    def kick(self, target, power):
        if self.team == 0:
            target.x *= -1
            target.y *= -1
        print 'kick %f %f %f' % (target.x, target.y, power)
        stdout.flush()

    def nearest_opponent_dist(self):
        opp = 1 - self.team
        res = 10000
        for i in range(0, 5):
            print >>stderr, 'stuck'
            p = self._players[5*opp+i]
            if (p-self.self_pos).len() < res:
                res = (p-self.self_pos).len()
        return res

    def get_ball_receiver(self, players, ballpos):
        min_dist = 10000
        receiver = 0
        for i in range(5):
            pos = self.get_target_position(i, ballpos)
            if (pos - ballpos).len() < min_dist:
                min_dist = (pos - ballpos).len()
                receiver = i
        return receiver

    def kick_action(self, ballpos):
        if int(random() * 2) == 1:
            self.kick(Vector(10, 50), 1)
        else:
            self.kick(ballpos + Vector(10, 10), 1)


if __name__ == '__main__':
    p = Player()
    p.run()
