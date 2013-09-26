#ifndef PLAYERAI_ZHENGLI
#define PLAYERAI_ZHENGLI

#include "Player.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
class PlayerAI:public Player
{
public:
	PlayerAI()
	{

	}
	virtual ~PlayerAI(){};
	virtual ChessPoint DoInput()const
	{
		srand(time(0));
		ChessPoint cp(0,0);
		do
		{
			cp.x=rand()% GetCBWidth();
			cp.y=rand()% GetCBHeight();
		} while (!Submit(cp));

		std::cout<<"AIPlayer "<<GetId()<<" :"<<cp.x<<" "<<cp.y<<std::endl;
		return cp;
	}

};

#endif
