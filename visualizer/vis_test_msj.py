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
        players.append(Player((i-2)*2 , (i-5)*3))
       
    visualizer = sp.Popen('./a.out', stdin=sp.PIPE)
    for j in xrange(game_duration):
        for i in range(11):
            if players[i].x > 50 or players[i].x < -50:
                layers[i].dir = -players[i].dir/10
            players[i].x = players[i].x+players[i].dir
            visualizer.stdin.write(`players[i].x`+'\n') 
            visualizer.stdin.write(`players[i].y`+'\n') 
            print 'THIS IS TEST, WROTE %f, %f'%(players[i].x, players[i].y)
        visualizer.stdin.write(`0`+'\n') 
        
        time.sleep(cycle_length)
        
    visualizer.terminate()
