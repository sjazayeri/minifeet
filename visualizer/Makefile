a.out : main.o 
	g++ *.o   -lSDL2 -lSDL2_image
main.o : main.cpp Core.o MovingObj.o
	g++ main.cpp  -lSDL2 -lSDL2_image
Core.o : Core.cpp Core.h 
	g++ -c main.cpp -lSDL2 -lSDL2_image
MovingObj.o : MovingObj.cpp MovingObj.h Ball.o Player.o 
	g++ -c MovingObj.cpp -lSDL2 -lSDL2_image
Ball.o : Ball.cpp Ball.h
	g++ -c Ball.cpp -lSDL2 -lSDL2_image
Player.o : Player.cpp Player.h
	g++ -c Player.cpp -lSDL2 -lSDL2_image
