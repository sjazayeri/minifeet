"""Defines a proxy class for communicating with bots"""
from collections import defaultdict
from geometry import Vector
import subprocess as sp
import select

class Proxy:
    """Proxy(program_path, team, number) -> create communicator"""
    max_read = 1024
    def __init__(self, ppath, player):
        self.player = player
        self.goal = 'nop'
        self.dic = defaultdict(lambda:lambda:'nop',
                               {'kick': self.kick, 'move': self.move})
        
        self.process = sp.Popen(ppath, stdin=sp.PIPE, stdout=sp.PIPE)
        self.poller = select.poll()
        self.poller.register(self.process.stdout, select.POLLIN)
        self.process.stdin.write(' '.join([`team`, `number`, '\n']))

    def terminate(self):
        """terminates the player process"""
        self.process.terminate()
        
    def send_state(self, state):
        """sends the current state to the player"""
        for p in state.players:
            self.process.stdin.write(' '.join([`p.pos.x`, `p.pos.y`]))
        self.process.stdin.write(' '.join([`state.ball.x`,
                                           `state.ball.y`]))
        self.process.stdin.write(`game_state`)

    def get_command(self):
        """returns the command for the current cycle as a string"""
        buffer_content = []
        while self.poller.poll(0) and len(command) < max_read:
            buffer_content += self.process.stdout.read(1)
        command = ''.join(buffer_content)
        if command:
            self.goal = command.split('\n')[-1]
        return self.translate(self.goal)

     def translate(self, goal):
        args = goal.split(' ')
        try:
            return self.dic[args[0]](*map(int, args[1:]))
        except TypeError:
            return 'nop'
        
    def kick(self, x, y):
        pass

    def move(self, x, y):
        return 'move '+
        `math.atan((x-self.player.pos.x)/(y-self.player.pos.y))`
