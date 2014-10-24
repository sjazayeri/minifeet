a.out : main.o 
	g++ *.o -lSDL2 -lSDL2_image  -lSDL2_ttf -w
main.o : main.cpp Core.o MovingObj.o
	g++ -c main.cpp ./headers/cpp/*.cpp -lSDL2 -lSDL2_image  -lSDL2_ttf -w
Core.o : ./headers/cpp/Core.cpp ./headers/Core.h 
	g++ -c ./headers/cpp/Core.cpp -lSDL2 -lSDL2_image -lSDL2_ttf -w
MovingObj.o : ./headers/cpp/MovingObj.cpp ./headers/MovingObj.h Ball.o Player.o 
	g++ -c ./headers/cpp/MovingObj.cpp -lSDL2 -lSDL2_image -lSDL2_ttf -w
Ball.o : ./headers/cpp/Ball.cpp ./headers/Ball.h LTexture.o
	g++ -c ./headers/cpp/Ball.cpp -lSDL2 -lSDL2_image -lSDL2_ttf -w
Player.o : ./headers/cpp/Player.cpp ./headers/Player.h LTexture.o
	g++ -c ./headers/cpp/Player.cpp -lSDL2 -lSDL2_image -lSDL2_ttf -w
LTexture.o : ./headers/cpp/LTexture.cpp ./headers/LTexture.h
	g++ -c ./headers/cpp/LTexture.cpp -lSDL2 -lSDL2_image -lSDL2_ttf  -w
