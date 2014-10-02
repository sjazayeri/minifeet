import subprocess as sp
import select
import state

def move_to(x, y):
    pass

def kick(x, y):
    pass

def translate(cmd):
    pass

class Player:
    """Player(program_path, team, number) -> create object to run
    and interface with player program"""
    def __init__(self, ppath, team, number):
        self.team = team
        self.number = number
        self.cmd_list = []
        self.process = sp.Popen(ppath, stdin=sp.PIPE, stdout=sp.PIPE)
        self.process.stdin.write(team+' '+number+'\n')
        self.poller = select.poll()
        self.poller.register(self.process.stdout, select.POLLIN)
        
    def terminate(self):
        self.process.terminate()
        
    def send_state(self, state):
        """sends the current state to the player"""
        pass

    def get_command(self):
        """returns the command for the current cycle as a string"""
        buffer_content = []
        while self.poller.poll(0):
            buffer_content += self.process.read(1)
        command = ''.join(buffer_content)
