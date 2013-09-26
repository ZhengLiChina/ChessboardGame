#ifndef GameRULER_ZHENGLI
#define GameRULER_ZHENGLI


#include "Chessboard.h"
#include <memory>
enum Result {HasWinner,NoWinner,ToBeContinued,Error };

class GameRuler
{
public:
	GameRuler(std::shared_ptr<Chessboard> cb,int length=5);
	~GameRuler(){};
	Result Judge(const ChessPoint& cp);

private:
	std::shared_ptr<Chessboard> chessboard;
	int width,height;
	int length;
};

#endif