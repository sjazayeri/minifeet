a.out : main.o 
	g++ ./headers/cpp/*.o -lSDL2 -lSDL2_image
main.o : main.cpp ./headers/cpp/Core.o ./headers/cpp/MovingObj.o
	g++ main.cpp  -lSDL2 -lSDL2_image
./headers/cpp/Core.o : ./headers/cpp/Core.cpp ./headers/Core.h 
	g++ -c ./headers/cpp/Core.cpp -lSDL2 -lSDL2_image
./headers/cpp/MovingObj.o : ./headers/cpp/MovingObj.cpp ./headers/MovingObj.h ./headers/cpp/Ball.o ./headers/cpp/Player.o 
	g++ -c ./headers/cpp/MovingObj.cpp -lSDL2 -lSDL2_image
./headers/cpp/Ball.o : ./headers/cpp/Ball.cpp ./headers/Ball.h ./headers/cpp/LTexture.o
	g++ -c ./headers/cpp/Ball.cpp -lSDL2 -lSDL2_image
./headers/cpp/Player.o : ./headers/cpp/Player.cpp ./headers/Player.h ./headers/cpp/LTexture.o
	g++ -c ./headers/cpp/Player.cpp -lSDL2 -lSDL2_image
./headers/cpp/LTexture.o : ./headers/cpp/LTexture.cpp ./headers/LTexture.h
	g++ -c ./headers/cpp/LTexture.cpp -lSDL2 -lSDL2_image
