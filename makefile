all: MyGame.exe
MyGame.exe:main.o Chessboard.o GameManager.o GameRuler.o
	g++ -std=c++11 $^ -o $@
main.o:main.cpp GameManager.h PlayerLocal.h PlayerAI.h Player.h
	g++ -std=c++11 -c $^
Chessboard.o:Chessboard.cpp Chessboard.h
	g++ -std=c++11 -c $^
GameManager.o:GameManager.cpp GameManager.h Player.h GameRuler.h Chessboard.h
	g++ -std=c++11 -c $^
GameRuler.o:GameRuler.cpp GameRuler.h Chessboard.h
	g++ -std=c++11 -c $^
clean:
	del *.o
cleanall:
	del *.o
	del *.gch
