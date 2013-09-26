#ifndef GAMEMANAGER_ZHENGLI
#define GAMEMANAGER_ZHENGLI

#include "Chessboard.h"
#include "Player.h"
#include "GameRuler.h"
#include <memory>
#include <vector>

class GameManager
{
public:
	GameManager(int w=10,int h=10,int length=5);
	~GameManager(){}
	int Run();
	void AddPlayer(Player*);
	std::shared_ptr<Chessboard> GetChessboard(){return cb;}

private:
	std::shared_ptr<Chessboard> cb;
	GameRuler ruler;
	std::vector<const Player*> players;

	std::vector<const Player*>::const_iterator currentPlayer;
	void GetNextPlayer();
	Result SendToRuler(const ChessPoint& cp);
};

#endif

