#include "GameRuler.h"

GameRuler::GameRuler(std::shared_ptr<Chessboard> cb,int length)
{
	this->length=length;
	chessboard=cb;
	width=cb->GetWidth();
	height=cb->GetHeight();
}

Result GameRuler::Judge(const ChessPoint& cp)
{
	int id=chessboard->GetIdOfPoint(cp);
	if (id<=0)
	{
		return Result::Error;
	}

	ChessPoint tempp=cp;
	//Four directions
	ChessPoint directions[4]={ChessPoint(1,0),ChessPoint(0,1),ChessPoint(1,1),ChessPoint(1,-1)};
	for (int i = 0; i < 4; ++i)
	{
		//No need to worry about ACCESS VIOLATION! 
		//GetIdOfPoint() assures us that it won't happen
		int halfa=0,halfb=0;
		//int total=0;
		while(chessboard->GetIdOfPoint(tempp=tempp+directions[i])==id)
		{
			halfa++;//total++;
		}
		tempp=cp;
		while(chessboard->GetIdOfPoint(tempp=tempp-directions[i])==id)
		{
			halfb++;//total++;
		}
		if (halfa+1+halfb>=length)//total+1>=length
		{
			return Result::HasWinner;
		}

	}

	if (chessboard->GetSum()==width*height)
	{
		return Result::NoWinner;
	}

	return Result::ToBeContinued;
}