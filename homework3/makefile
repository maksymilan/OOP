program: game.o castle.o room.o
	g++ game.o castle.o room.o -o program

game.o: game.cpp
	g++ -c game.cpp castle.cpp room.cpp

castle.o: castle.cpp
	g++ -c castle.cpp game.cpp

room.o: room.cpp
	g++ -c room.cpp