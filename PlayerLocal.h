#ifndef PLAYERLOCAL_ZHENGLI
#define PLAYERLOCAL_ZHENGLI

#include "Player.h"
#include <iostream>
class PlayerLocal:public Player
{
public:
	PlayerLocal()
	{

	}
	virtual ~PlayerLocal(){};
	virtual ChessPoint DoInput()const
	{
		ChessPoint cp(0,0);
		do
		{
			std::cin>>cp.x>>cp.y;
		} while (!Submit(cp));
		std::cout<<"LocalPlayer "<<GetId()<<" :"<<cp.x<<" "<<cp.y<<std::endl;
		return cp;
	}

};

#endif
