import subprocess as sp

class State :
    def __init__(self, players, ball, game_state = None):
        self.players = players
        self.ball = ball
        self.game_state = game_state
        self.situation = update() #judge
    def send_data():
        visualizer = sp.Popen(None, stdin=sp.PIPE)
        for i in range(10):
            visualizer.stdin.write(players[i].pos.x) 
            visualizer.stdin.write(players[i].pos.y) 
        visualizer.stdin.write(ball.pos.x) 
        visualizer.stdin.write(ball.pos.y) 
        visualizer.terminate()  
