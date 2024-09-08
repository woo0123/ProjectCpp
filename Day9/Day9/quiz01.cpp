#include <iostream>
#include"MainGame.h"

using namespace std;

void main()
{
	//게임을 시작하고 나랑 컴퓨터가 패를 받음
	//베팅을 구현하려 했으나 컴퓨터가 패를 보고 판단하는
	//것은 힘들기에 그냥 내가 건 만큼 컴퓨터가 받고
	//가는것으로 결론을 지음

	MainGame* mainGame = new MainGame();
	mainGame->Init();

	mainGame->Update();
	
	mainGame->Release();
	delete mainGame;
	mainGame = nullptr;


}