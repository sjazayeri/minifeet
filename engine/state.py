import subprocess as sp


default = 0 
team1_goal =1
team2_goal =2
offside = 3
kickoff = 4

class State :
    def __init__(self, players, ball, team1_goals=0,
                 team2_goals=0, game_state=0, last_kicked =None):
        self.players = players
        self.ball = ball
        self.game_state = game_state   
        self.last_kicked=last_kicked
        self.team1_goals=team1_goals
        self.team2_goals=team2_goals
          
    def update(self, gs):
        self.game_state = gs
        if(gs == 2):
            self.team2_goals+=1
        elif(gs == 1):
            self.team1_goals+=1
        return
