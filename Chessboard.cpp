#include "Chessboard.h"
#include<cstring>

ChessPoint operator+(const ChessPoint& l,const ChessPoint& r)
{
return ChessPoint(l.x+r.x,l.y+r.y);
}

ChessPoint operator-(const ChessPoint& l,const ChessPoint& r)
{
return ChessPoint(l.x-r.x,l.y-r.y);
}

Chessboard::Chessboard(int w,int h)
{
	width=w>=10?w:10;
	height=h>=10?h:10;
	cb=new int[w*h];//cannot declare int[w][h]. Error
	
	// for (int i = 0; i < w; ++i)
	// {
	// 	for (int j = 0; j < h; ++j)
	// 	{
	// 		cb[i][j]=0;
	// 	}
	// }
	memset(cb,0,w*h*sizeof(int));
	// for (int i = 0; i < w*h; ++i)
	// {
	// 	cb[i]=0;
	// }
	sum=0;
}
Chessboard::~Chessboard()
{
	delete [] cb;
}
bool Chessboard::GetSubmit(const ChessPoint& cp,int id)
{
	if(!isPointValid(cp))
	{
		return false;
	}

	if (GetIdOfPoint(cp)!=0)
	{
		return false;
	}

	cb[cp.x+cp.y*width]=id;
	sum++;
	return true;
}
int Chessboard::GetIdOfPoint(const ChessPoint& cp)const
{
	if (isPointValid(cp))
	{
		return cb[cp.x+cp.y*width];
	}
	return -1;
}


bool Chessboard::isPointValid(const ChessPoint& cp)const
{
	if (cp.x<0||cp.x>=width||cp.y<0||cp.y>=height)
	{
		return false;
	}
	return true;
}
