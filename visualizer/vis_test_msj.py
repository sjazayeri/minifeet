import time
import subprocess as sp

cycle_length = 0.1
game_duration = 2000
    
class Player :
    def __init__(self , x , y):
        self.x = x
        self.y = y    
        self.dir = -0.5

        
if __name__ =='__main__':

    players = [] 
    for i in xrange(11):
        players.append(Player(i , i ))
       
    visualizer = sp.Popen('./a.out', stdin=sp.PIPE)
    for i in xrange(game_duration):
        for i in range(11):
            if players[i].x > 50 or players[i].x < -50:
                players[i].dir = -players[i].dir
            players[i].x += players[i].dir/10
            visualizer.stdin.write(`players[i].x`+' ') 
            visualizer.stdin.write(`players[i].y`+'\n') 
        
        time.sleep(cycle_length)
        
    visualizer.terminate()
