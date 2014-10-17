import subprocess as sp

defualt = 0 
team1_goal =1
team2_goal =2
offside = 3
kickoff = 4

class State :
    def __init__(self, players, team1_goal=0 ,team2_goal=0 ,game_state = 0 , last_kicked =None):
        self.players = players
        self.ball = ball
        self.game_state = game_state   
        self.last_kicked=last_kicked
        self.team1_goal=team1_goal
        self.team2_goal=team2_goal
          
    def update( self , gs  ) :
        game_state = gs
        if(gs == 2):
            team2_goal+=1
        elif(gs == 1):
            team1_goal+=1
        return
