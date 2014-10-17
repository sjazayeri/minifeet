class Referee:
	goal_1, goal_2 = 0, 0
	
	@classmethod
	is_goal(ball, ground):
		y1 = ball.pos.y - ball.vel.y
		x1 = ball.pos.x - ball.vel.x
		m = 1.0*(ball.pos.y-y1)/(ball.pos.x-x1)
		d = y1 - m * x1
		
		if ball.pos.y > ground.length/2.0 and (ground.length/2.0 + m*ground.gate/2.0 - d)*(ground.length/2.0 - m*ground.gate/2.0 - d) < 0:
			goal_1 += 1
			return 1
		elif ball.pos.y < -(ground.length/2.0) and (-ground.length/2.0 + m*ground.gate/2.0 - d)*(-ground.length/2.0 - m*ground.gate/2.0 - d) < 0:
			goal_2 += 1
			return 2
		else:
			return 0
