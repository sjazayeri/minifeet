from collections import defaultdict
from geometry import Vector
import subprocess as sp
import select

max_read = 1024 #this is likely to change as soon as the state specs are in
# test

class MovingObj:
	def __init__ (self , pos=Vector(0, 0) , vel = Vector(0, 0) ,   ground=None) :
		self.ground = ground
	def move (self) :
		raise NotImplementedError ()
		

class Player(MovingObj):
    """Player(program_path, team, number, loc) -> create object to run
    and interface with player program"""
    def __init__(self, ppath, team, number, init_loc):
        self.team = team
        self.number = number
        self.loc = init_loc
        self.goal = 'nop'
        self.dic = defaultdict(lambda:lambda:'nop',
                               {'kick': self.kick, 'move': self.move})
        
        self.process = sp.Popen(ppath, stdin=sp.PIPE, stdout=sp.PIPE)
        self.poller = select.poll()
        self.poller.register(self.process.stdout, select.POLLIN)
        self.process.stdin.write(' '.join(map(str, [team, number, x, y, '\n'])))
        
    def terminate(self):
        """terminates the player process"""
        self.process.terminate()
        
    def send_state(self, state):
        """sends the current state to the player"""
        pass

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
        pos+=vel
	length = self.ground.length
	width = self.ground.width
	if y>(length/2) :
		y=length/2
	if y<-(length/2) :
		y=-length/2
	if x>(width/2) :
		x=width/2
	if x<-(width/2) :
		x=-width/2
class Ground :
	def __init__( self  , length = 0 , width =0 , friction = 0 ) :
		self.length = length
		self.width = width
		self.friction = Vector(friction ,friction )

class Ball (MovingObj) :
	def move ( self ):
		m+=v
		m+=ground.friction
		if vx<0 :
			vx=0
		if vy<0 :
			vy=0
		length = self.ground.length
		width = self.ground.width
		if y>(length/2) :
			self.vy= -vy
			self.y= length-y
		if x>(width/2) :
			self.vx= -vx
			self.x= width-x
		if y<(-(length/2)) :
			self.y= -length-y
			self.vy=-vy
		if x<-(width/2) :
			self.vx= -vx
			self.x= -width-x

