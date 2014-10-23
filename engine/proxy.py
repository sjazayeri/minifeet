"""Defines a proxy class for communicating with bots"""
from collections import defaultdict
from geometry import Vector, epsilon
import subprocess as sp
import select
from math import atan
from sys import stderr
import time
import config

class Proxy(object):
    """Proxy(program_path, team, number) -> create communicator"""
    def __init__(self, ppath, player):
        self.player = player
        self.goal = 'nop'
        self.dic = defaultdict(lambda:lambda:'nop',
                               {'kick': self.kick, 'move': self.move})

        self.process = sp.Popen(ppath, stdin=sp.PIPE, stdout=sp.PIPE)
        self.poller = select.poll()
        self.poller.register(self.process.stdout, select.POLLIN)
        self.process.stdin.write('%d %d\n'%(self.player.team,
                                          self.player.number))
        
    def terminate(self):
        """terminates the player process"""
        self.process.terminate()

    def send_state(self, state):
        """sends the current state to the player"""
        for p in state.players:
            self.process.stdin.write('%d %d\n'%(p.pos.x, p.pos.y))
        self.process.stdin.write('%d %d\n'%(state.ball.pos.x,
                                            state.ball.pos.y))
        self.process.stdin.write(`state.game_state`+'\n')
        #self.process.stdin.flush()
        
    def get_command(self):
        """returns the command for the current cycle as a string"""
        #print >>stderr, 'GC CALLED AT %f'%(time.time())
        buffer_content = []
        while self.poller.poll(0) and len(buffer_content) < config.max_read:
            buffer_content += self.process.stdout.read(1)

        #print >>stderr, buffer_content
        command = ''.join(buffer_content).rstrip()
        #print >>stderr, 'PLAYER: %d, %d: '%(self.player.team,
        #                                    self.player.number)+command
        if command:
            self.goal = command
            print >>stderr, 'PLAYER %d, %d: %s'%(self.player.team, self.player.number, command)
        return self.translate(self.goal)

    def translate(self, goal):
        args = goal.split(' ')
        rv = None
        try:
            rv = self.dic[args[0]](*map(float, args[1:]))
        except TypeError:
            rv = 'nop'
        except ValueError:
            rv = 'nop'    
        return rv
        
    def kick(self, x, y, force):
        angle = (Vector(x, y)-self.player.pos).angle()
        print 'kick %f %f'%(angle, force)
        self.goal = 'nop'
        return 'kick %f %f' % (angle, force)

    def move(self, x, y):
        dest = Vector(x, y)
        if((dest-self.player.pos).len() < epsilon):
            self.goal = 'nop'
            return 'nop'
        rv = 'move %f %f'%((dest-self.player.pos).angle(), (dest-self.player.pos).len())
        #print >>stderr, rv
        return rv
