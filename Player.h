#ifndef PLAYER_ZHENGLI
#define PLAYER_ZHENGLI


#include <memory>
#include "Chessboard.h"

class Player
{
public:
	Player()
	{
		static int gid=0;
		id=++gid;//player id starts from 1
	}
	void SetChessboard(std::shared_ptr<Chessboard> cb)
	{
		chessboard=cb;
	}
	virtual ~Player(){};
	virtual ChessPoint DoInput()const=0;
	int GetId() const{return id;}
	bool Submit(const ChessPoint& cp)const
	{
		return chessboard->GetSubmit(cp,id);
	}
	int GetCBWidth()const{return chessboard->GetWidth();}
	int GetCBHeight()const{return chessboard->GetHeight();}

private:
	std::shared_ptr<Chessboard> chessboard;
	int id;
};

#endif
