class Referee:
	goal_width=30
	def is_goal(ground,ball):
		y1,y2=(ground.width-goal_width)/2,(ground.width+goal_width)/2
		return  y1<ball.pos.y<y2