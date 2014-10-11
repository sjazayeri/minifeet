class State:
    """Holds the state of a game"""
class Ground :
	def __init__( self  , length = 0 , width =0 ) :
		self.length = length
		self.width = width
class MovingObj:
	def __init__ (self , vx=0 , vy=0 , x=0 , y =0 , friction = 0 ,  Ground=None) :
		self.ground = Ground
		self.vx = vx
		self.vy = vy
		self.x = x
		self.y = y
		self.friction = friction
	def move (self) :
		raise NotImplementedError ()
		
class Ball (MovingObj) :
	def move ( self ):
		self.x+=vx
		self.y+=vy
		self.vx-=friction
		self.vy-=friction
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

class Player (MovingObj):
	def move ( self ):
		self.x+=vx
		self.y+=vy
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

