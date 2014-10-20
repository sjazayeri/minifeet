import time
import subprocess as sp

cycle_length = 0.1
game_duration = 2000
    
class Player :
    def __init__(self , x , y):
        self.x = x
        self.y = y    


        
if __name__ =='__main__':

    players = [] 
    for i in xrange(11):
        players.append(Player(i , i ))
       
    visualizer = sp.Popen('./a.out', stdin=sp.PIPE)
    try:
        for j in xrange(game_duration):
            for i in range(11):
                visualizer.stdin.write(`int(players[i].x) + j`+'\n') 
                visualizer.stdin.write(`int(players[i].y) + j`+'\n') 
                print 'THIS IS TEST, WROTE %f, %f'%(players[i].x, players[i].y)
            visualizer.stdin.write('0'+'\n')
            time.sleep(cycle_length)
    except IOError:
        print 'err in vis'
    visualizer.terminate()
