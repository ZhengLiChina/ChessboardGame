#include "GameManager.h"
#include <iostream>
GameManager::GameManager(int w,int h,int length):cb(new Chessboard(w, h)),ruler(cb,length)
{
	//std::cout<<"GG"<<std::endl;
}

void GameManager::AddPlayer(Player* p)
{
	p->SetChessboard(cb);
	players.push_back(p);
}

void GameManager::GetNextPlayer()
{
	currentPlayer++;
	if (currentPlayer==players.end())
	{
		currentPlayer=players.begin();
	}
}

Result GameManager::SendToRuler(const ChessPoint& cp)
{
	return ruler.Judge(cp);
}



int GameManager::Run()
{
	if (players.size()==0)
	{
		return -1;
	}
	currentPlayer=players.end()-1;//end()-1 is to call GetNextPlayer() later

	ChessPoint currentCP(0,0);
	Result state=Result::ToBeContinued;
	do
	{
		std::cout<<cb->GetSum()+1<<": ";

		GetNextPlayer();
		currentCP=(*currentPlayer)->DoInput();
		state=SendToRuler(currentCP);
	} while (state==Result::ToBeContinued);

	if (state==HasWinner)
	{
		return (*currentPlayer)->GetId();
	}

	if (state==NoWinner)
	{
		return 0;
	}

	return -1;

}
