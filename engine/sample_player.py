#!/usr/bin/python
from geometry import Vector, epsilon
from sys import stderr, stdout, exit
from utils import *
import time


class Player():
    def run(self):
        self.team, self.number = map(int, raw_input().split(' '))
        while True:
            players = get_players(self.team)
            selfpos = players[5 * self.team + self.number]
            ballpos = Vector(*map(float, raw_input().split(' ')))
            game_state = int(raw_input())
            # print >>stderr, 'GOT DATA AT %f'%(time.time())

            ball_reveiver = self.get_ball_receiver(players, ballpos)
            if self.number == ball_reveiver:
                if (selfpos - ballpos).len < 2:
                    self.kick_action()
                else:
                    self.move(ballpos)
            else:
                position = self.get_position(self.number, ballpos)
                if (selfpos - position).len > 2:
                    self.move(position)

            # print >>stderr, 'SENT COMMAND AT %f'%(time.time())

    def get_position(self, number, ballpos):
        pos = Vector(0, 0)
        if number == 0:
            pos = Vector(0, -59)
        elif number == 1:
            pos = Vector(5, -40)
        elif number == 2:
            pos = Vector(20, -20)
        elif number == 3:
            pos = Vector(20, -20)
        elif number == 4:
            pos = Vector(0, -0)
        return pos

    def move(self, position):
        if self.team == 1:
            position.x *= -1
            position.y *= -1
        print 'move %f %f' % (position.x, position.y)
        stdout.flush()

    def kick(self, target, power):
        if self.team == 1:
            target.x *= -1
            target.y *= -1
        print 'kick %f %f %f' % (target.x, target.y, power)
        stdout.flush()

    def get_ball_receiver(self):
        return -1

    def kick_action(self):
        self.kick(Vector(0, 50), 100)


if __name__ == '__main__':
    p = Player()
    p.run()
