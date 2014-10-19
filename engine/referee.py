class Referee:
	def __init__(self):
		self.goal1, self.goal2 = 0, 0
		self.players = []
		self.last_player_kicked = ()

	def is_goal(self, ball, ground):
		y1 = ball.pos.y - ball.vel.y
		x1 = ball.pos.x - ball.vel.x
		m = 1.0*(ball.pos.y-y1)/(ball.pos.x-x1)
		d = y1 - m * x1
		
		if ball.pos.y > ground.length/2.0 and (ground.length/2.0 + m*ground.gate/2.0 - d)*(ground.length/2.0 - m*ground.gate/2.0 - d) < 0:
			self.goal_1 += 1
			return 1
		elif ball.pos.y < -(ground.length/2.0) and (-ground.length/2.0 + m*ground.gate/2.0 - d)*(-ground.length/2.0 - m*ground.gate/2.0 - d) < 0:
			self.goal_2 += 1
			return 2
		else:
			return 0

	'''players=>a list with binary tuples of player and vector and player is a similar binary tuple'''	
	def update(self,players,last_player_kicked):
		self.players=players
		self.last_player_kciked=last_player_kicked

	def is_offside(self, player):
		player_last_pos = None
		for p in players:
			if p[0]==player:
				player_last_pos=p[1]
				break

		if player.team == 0:
			if self.last_player_kicked[0].team == 1 or self.last_player_kicked[0] == player or player_last_pos.y <= 0 or player_last_pos.y <= last_player_kicked[1].y:
				return 0

			max1, max2 = -(float('inf')), -(float('inf'))
			for p in players:
				if p.team == 0:
					continue
				if p[1].y > max2:
					max2 = players[1].y
				if max2 > max1:
					max1, max2 = max2, max1
			if player_last_pos.y > max2:
				return 3
			return 0

		elif player.team == 1:
			if self.last_player_kicked[0].team == 0 or self.last_player_kicked[0] == player or player_last_pos.y >= 0 or player_last_pos.y >= last_player_kicked[1].y:
				return 0

			min1, min2 = float('inf'), float('inf')
			for p in players:
				if p.team == 1:
					continue
				if min2 < min1:
					min1, min2 = min2, min1
			if player_last_pos.y < min2:
				return 4
			return 0
