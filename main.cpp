#include <iostream>

#include "GameManager.h"
#include "PlayerLocal.h"
#include "PlayerAI.h"
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
	GameManager gm(12,12,5);

	PlayerAI p1;
	gm.AddPlayer(&p1);
	// PlayerLocal p1;
	// gm.AddPlayer(&p1);

	PlayerAI p2;
	gm.AddPlayer(&p2);
	// PlayerLocal p2;
	// gm.AddPlayer(&p2);

	// PlayerAI p3;
	// gm.AddPlayer(&p3);
	int result=gm.Run();

	if (result==0)
	{
		cout<<"THE CHESSBOARD IS FULL, NO WINNER!"<<endl;
	}

	if (result>0)
	{
		cout<<"ID "<<result<<" WIN!"<<endl;
	}

	system("pause");
	return 0;
}