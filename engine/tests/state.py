import subprocess as sp

class State :
    def __init__(self, players, ball, game_state = None):
        self.players = players
        self.ball = ball
        self.game_state = game_state
        self.situation = update() #judge