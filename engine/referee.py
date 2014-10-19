class Referee:
	goal_1, goal_2 = 0, 0
	def is_goal(self,ball, ground):
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

'''
players = [[1,1],[4,2],[4,3],[4,4],[5,5],[1,2],[3,2],[3,1],[2,4],[2,1]]
curr_player_number = 2
last_player_number = 1

if curr_player_number < 5:
	if last_player_number >= 5 or last_player_number == curr_player_number or players[curr_player_number][0] <= 0 or players[curr_player_number][0] <= players[last_player_number][0]:
		return 0

	max1, max2 = -(float('inf')), -(float('inf'))
	for i in range(5,10):
		if players[i][0] > max2:
			max2 = players[i][0]
		if max2 > max1:
			max1, max2 = max2, max1
	if players[curr_player_number][0]>max2:
		return 1
	return 0

elif curr_player_number > 5:
	if last_player_number < 5 or last_player_number == curr_player_number or players[curr_player_number][0] >= 0 or players[curr_player_number][0] >= players[last_player_number][0]:
		return 0

	min1, min2 = float('inf'), float('inf')
	for i in range(0,5):
		if players[i][0] < min2:
			min2 = players[i][0]
		if min2 < min1:
			min1, min2 = min2, min1
	if players[curr_player_number][0]<min2:
		return 2
	return 0
'''
