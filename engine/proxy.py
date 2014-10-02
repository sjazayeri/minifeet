import subprocess as sp
import state
class Player:
    """Player(program_path) -> create object to run
    and interface with player program"""
    def __init__(self, ppath, team, number):
        self.team = team
        self.number = number
        self.cmd_list = []
        self.process = sp.Popen(ppath, stdin=sp.PIPE, stdout=sp.PIPE)
        self.process.stdin.write(team+' '+number+'\n')
        
    def terminate(self):
        self.process.terminate()
        
    def send_state(self, state):
        """sends the current state to the player"""
        pass

    def get_command(self):
        """returns the command for the current cycle""" 
        pass
