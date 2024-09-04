#include<iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

//수업 9월 6일부터 시작
//

//구조체는 
//변수 + 함수들을 묶어놓는 기능
struct Monster
{
	float hp;
	float attack;

	void PrintInfo()
	{
		cout << "몬스터 hp: " << this->hp << endl;
		cout << "몬스터 Atk: " << this->attack << endl;
	}
};
void GotoXY(int x, int y);
void UpdateGame();


void main()
{
	//int, float, __int64, char, bool
	//기본 자료형

	//언어에서 기본적으로 제공해주는 자료형
	//(정수, 실수, 문자열, 참거짓 ...)


	// 사용자 정의 자료형
	// -> 저희가 직접 자료형을 만드는 것
	//(enum, struct, class)
	// 
	
	//구조체 초기화
	Monster monster = {};
	monster.hp = 10;
	monster.attack = 20;
	
	monster.PrintInfo();

	//GotoXY
	//윈도우s헤더안에는 콘솔창을 제어하는 기능이 있음

	GotoXY(20, 10);
	cout << "위치";
	
	//현재 시간 기억
	int oldGameTime = ::GetTickCount64();
	//게임이 진행되고 몇ms가 지났는가


	while (true)
	{
		//현재 게임시간
		int currentGameTime = ::GetTickCount64();

		if (750 < currentGameTime - oldGameTime)
		{
			UpdateGame();
			oldGameTime = currentGameTime;
		}
	}
}

void UpdateGame()
{
	cout << "1초 지남" << endl;
}

void GotoXY(int x, int y)
{
	COORD pos = { x,y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}