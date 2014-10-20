import time
import subprocess as sp

cycle_length = 0.1
game_duration = 2000
    
class Player :
    def __init__(self , x , y):
        self.x = x
        self.y = y    

        
if __name__ =='__main__':

    players = [Player(0,60),Player(-30,40),Player(-30,20),Player(30,40),Player(30,20),Player(0,-50),Player(-30,-30),Player(-30,-10),Player(30,-30),Player(30,-10),Player(0,0)] 
    for i in xrange(11):
        players.append(Player(i , i ))
       
    visualizer = sp.Popen('./a.out', stdin=sp.PIPE)
    try:
        for j in xrange(game_duration):
            for i in range(11):
                visualizer.stdin.write(`int(players[i].x)`+'\n') 
                visualizer.stdin.write(`int(players[i].y)`+'\n') 
                print 'THIS IS TEST, WROTE %f, %f'%(players[i].x, players[i].y)
            visualizer.stdin.write('0'+'\n')
            time.sleep(cycle_length)
    except IOError:
        print 'err in vis'
    visualizer.terminate()
