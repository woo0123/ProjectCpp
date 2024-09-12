#include "MainGame.h"
#include<iostream>
#include<Windows.h>
using namespace std;
//구사패를 진행할때 게임을 다시 시작하지 않고 
//코드가 끝나게 됨. 원인을 모름.
void MainGame::Init()
{
	cout << "섯다 게임을 시작합니다." << endl;
}

void MainGame::SetCard()
{
	for (int i = 0; i < 20; i++)
	{
		_card[i] = i;
	}
}

void MainGame::ShuffleCard()
{
	srand(time(NULL));
	
	for (int i = 0; i < 10000; i++)
	{
		int index1 = rand() % 20;
		int index2 = rand() % 20;
		int temp = _card[index1];
		_card[index1] = _card[index2];
		_card[index2] = temp;
	}
}

void MainGame::GetCard()
{
	for (int i = 0; i < 2; i++)
	{
		_myCard[i] = _card[i];
		_comCard[i] = _card[i+2];
	}
	//내 카드 정렬
	if (_myCard[0] > _myCard[1])
	{
		int temp = _myCard[0];
		_myCard[0] = _myCard[1];
		_myCard[1] = temp;
	}
	//상대 카드 정렬
	if (_comCard[0] > _comCard[1])
	{
		int temp = _comCard[0];
		_comCard[0] = _comCard[1];
		_comCard[1] = temp;
	}
}

void MainGame::CheckMyCard()
{
	//숫자부터 선언 그다음 광이면 광까지 선언
	for (int i = 0; i < 2; i++)
	{
		cout << _myCard[i] / 2 + 1;
		switch (_myCard[i] / 2 + 1)
		{
		case 1:
			if (_myCard[i] % 2 == 0)
			{
				cout << "광";
				break;
			}
		case 3:
			if (_myCard[i] % 2 == 0)
			{
				cout << "광";
				break;
			}
		case 4:
			if (_myCard[i] % 2 == 0)
			{
				cout << "그림";
				break;
			}
		case 7:
			if (_myCard[i] % 2 == 0)
			{
				cout << "그림";
				break;
			}
		case 8:
			if (_myCard[i] % 2 == 0)
			{
				cout << "광";
				break;
			}
		case 9:
			if (_myCard[i] % 2 == 0)
			{
				cout << "그림";
				break;
			}
		default:
			break;
		}
		cout << " ";
	}
	cout << endl;
}

void MainGame::MyVicDiscrimination()
{
	//38 광땡
	if (_myCard[0] == 4 && _myCard[1] == 14)
	{
		_compareWin[0] = 1;
	}
	//13 %% 18 광땡
	else if (_myCard[0] == 0 && _myCard[1] == 4)
	{
		_compareWin[0] = 2;
	}
	else if (_myCard[0] == 0 && _myCard[1] == 14)
	{
		_compareWin[0] = 2;
	}
	//땡
	else if (_myCard[0] / 2 == _myCard[1] / 2)
	{
		_compareWin[0] = 3;
	}
	//마이카드 몫은 -1한 값임을 기억.
	//알리
	else if (_myCard[0] / 2 == 0 &&_myCard[1] / 2 == 1)
	{
		_compareWin[0] = 4;
	}
	//독사
	else if (_myCard[0] / 2 == 0 && _myCard[1] / 2 == 3)
	{
		_compareWin[0] = 5;
	}
	//구삥
	else if (_myCard[0] / 2 == 0 && _myCard[1] / 2 == 8)
	{
		_compareWin[0] = 6;
	}
	//장삥
	else if (_myCard[0] / 2 == 0 && _myCard[1] / 2 == 9)
	{
		_compareWin[0] = 7;
	}
	//장사
	else if (_myCard[0] / 2 == 3 && _myCard[1] / 2 == 9)
	{
		_compareWin[0] = 8;
	}
	//세륙
	else if (_myCard[0] / 2 == 3 && _myCard[1] / 2 == 5)
	{
		_compareWin[0] = 9;
	}
	//갑오
	else if (_myCard[0] / 2 + _myCard[1] / 2 == 7)
	{
		_compareWin[0] = 10;
	}
	else if (_myCard[0] / 2 + _myCard[1] / 2 == 17)
	{
		_compareWin[0] = 10;
	}
	//멍텅구리구사
	else if (_myCard[0] == 6 && _myCard[1] == 16)
	{
		_compareWin[0] = 11;
	}
	//구사
	else if (_myCard[0] / 2 == 3 && _myCard[1] / 2 == 8)
	{
		_compareWin[0] = 12;
	}
	//암행어사
	else if (_myCard[0] == 6 && _myCard[1] == 12)
	{
		_compareWin[0] = 13;
	}
	//땡잡이
	else if (_myCard[0] == 4 && _myCard[1] == 12)
	{
		_compareWin[0] = 14;
	}
	//망통
	else if (_myCard[0] / 2 + _myCard[1] / 2 == 8)
	{
		_compareWin[0] = 16;
	}
	else
	{
		_compareWin[0] = 15;
	}
}

void MainGame::CheckComCard()
{
	//숫자부터 선언 그다음 광이면 광까지 선언
	for (int i = 0; i < 2; i++)
	{
		cout << _comCard[i] / 2 + 1;
		switch (_comCard[i] / 2 + 1)
		{
		case 1:
			if (_comCard[i] % 2 == 0)
			{
				cout << "광";
				break;
			}
		case 3:
			if (_comCard[i] % 2 == 0)
			{
				cout << "광";
				break;
			}
		case 4:
			if (_comCard[i] % 2 == 0)
			{
				cout << "그림";
				break;
			}
		case 7:
			if (_comCard[i] % 2 == 0)
			{
				cout << "그림";
				break;
			}
		case 8:
			if (_comCard[i] % 2 == 0)
			{
				cout << "광";
				break;
			}
		case 9:
			if (_comCard[i] % 2 == 0)
			{
				cout << "그림";
				break;
			}
		default:
			break;
		}
		cout << " ";
	}
	cout << endl;
}

void MainGame::ComVicDiscrimination()
{
	//38 광땡
	if (_comCard[0] == 4 && _comCard[1] == 14)
	{
		_compareWin[1] = 1;
	}
	//13 %% 18 광땡
	else if (_comCard[0] == 0 && _comCard[1] == 4)
	{
		_compareWin[1] = 2;
	}
	else if (_comCard[0] == 0 && _comCard[1] == 14)
	{
		_compareWin[1] = 2;
	}
	//땡
	else if (_comCard[0] / 2 == _comCard[1] / 2)
	{
		_compareWin[1] = 3;
	}
	//마이카드 몫은 -1한 값임을 기억.
	//알리 12
	else if (_comCard[0] / 2 == 0 && _comCard[1] / 2 == 1)
	{
		_compareWin[1] = 4;
	}
	//독사 14
	else if (_comCard[0] / 2 == 0 && _comCard[1] / 2 == 3)
	{
		_compareWin[1] = 5;
	}
	//구삥 19
	else if (_comCard[0] / 2 == 0 && _comCard[1] / 2 == 8)
	{
		_compareWin[1] = 6;
	}
	//장삥 1 10
	else if (_comCard[0] / 2 == 0 && _comCard[1] / 2 == 9)
	{
		_compareWin[1] = 7;
	}
	//장사 4 10
	else if (_comCard[0] / 2 == 3 && _comCard[1] / 2 == 9)
	{
		_compareWin[1] = 8;
	}
	//세륙 46
	else if (_comCard[0] / 2 == 3 && _comCard[1] / 2 == 5)
	{
		_compareWin[1] = 9;
	}
	//갑오 9끗
	else if (_comCard[0] / 2 + _comCard[1] / 2 == 7)
	{
		_compareWin[1] = 10;
	}
	else if (_comCard[0] / 2 + _comCard[1] / 2 == 17)
	{
		_compareWin[1] = 10;
	}
	//멍텅구리구사
	else if (_comCard[0] == 6 && _comCard[1] == 16)
	{
		_compareWin[1] = 11;
	}
	//구사
	else if (_comCard[0] / 2 == 3 && _comCard[1] / 2 == 8)
	{
		_compareWin[1] = 12;
	}
	//암행어사
	else if (_comCard[0] == 6 && _comCard[1] == 12)
	{
		_compareWin[1] = 13;
	}
	//땡잡이
	else if (_comCard[0] == 4 && _comCard[1] == 12)
	{
		_compareWin[1] = 14;
	}
	//망통
	else if (_comCard[0] / 2 + _comCard[1] / 2 == 8)
	{
		_compareWin[1] = 16;
	}
	//나머지 끗
	else
	{
		_compareWin[1] = 15;
	}
}

void MainGame::Victory()
{
	//암행어사
	if(_compareWin[0] == 2 && _compareWin[1] == 13)
	{
		cout << "상대가 승리했습니다!" << endl;
		_isGameExit = true;
	}
	else if (_compareWin[0] == 13 && _compareWin[1] == 2)
	{
		cout << "당신이 승리했습니다!" << endl;
		_isGameExit = true;
	}
	else if (_compareWin[0] != 2 && _compareWin[1] == 13)
	{
		_compareWin[1] = 15;
	}
	else if (_compareWin[0] == 13 && _compareWin[1] != 2)
	{
		_compareWin[0] = 15;
	}
	//땡잡이
	else if (_compareWin[0] == 3 && _compareWin[1] == 14)
	{
		if(_myScore == 37)
		{
			cout << "당신이 승리했습니다!" << endl;
			_isGameExit = true;
		}
		else
		{
			cout << "상대가 승리했습니다!" << endl;
			_isGameExit = true;
		}
	}
	else if (_compareWin[0] == 14 && _compareWin[1] == 3)
	{
		if (_comScore == 37)
		{
			cout << "상대가 승리했습니다!" << endl;
			_isGameExit = true;
		}
		else
		{
			cout << "당신이 승리했습니다!" << endl;
			_isGameExit = true;
		}
	}
	else if (_compareWin[0] != 3 && _compareWin[1] == 14)
	{
		_compareWin[1] = 16;
	}
	else if (_compareWin[0] == 14 && _compareWin[1] != 3)
	{
		_compareWin[0] = 16;
	}
	//멍텅구리구사
	else if (_compareWin[0] >= 3 && _compareWin[1] == 11)
	{
		if (_myScore == 37)
		{
			cout << "당신이 승리했습니다!" << endl;
			_isGameExit = true;
		}
		else
		{
			cout << "게임을 다시 진행합니다." << endl;
		}
	}
	else if (_compareWin[0] == 11 && _compareWin[1] >= 3)
	{
		if (_comScore == 37)
		{
			cout << "상대가 승리했습니다!" << endl;
			_isGameExit = true;
		}
		else
		{
			cout << "게임을 다시 진행합니다." << endl;
		}
	}
	//구사
	else if (_compareWin[0] > 3 && _compareWin[1] == 11)
	{
		cout << "게임을 다시 진행합니다." << endl;
	}
	else if (_compareWin[0] == 11 && _compareWin[1] > 3)
	{
		cout << "게임을 다시 진행합니다." << endl;
	}
	//땡
	else if (_compareWin[0] == 3 && _compareWin[1] == 3)
	{
		if (_myScore > _comScore)
		{
			cout << "당신이 승리했습니다!" << endl;
			_isGameExit = true;
		}
		else
		{
			cout << "상대가 승리했습니다!" << endl;
			_isGameExit = true;
		}
	}
	//끗
	if (_compareWin[0] == 15 && _compareWin[1] == 15)
	{
		if ((_myCard[0] / 2 + _myCard[1] / 2 + 2) % 10 >
			(_comCard[0] / 2 + _comCard[1] / 2 + 2) % 10)
		{
			cout << "당신이 승리했습니다!" << endl;
			_isGameExit = true;
		}
		else if ((_myCard[0] / 2 + _myCard[1] / 2 + 2) % 10 
			== (_comCard[0] / 2 + _comCard[1] / 2 + 2) % 10)
		{
			cout << "게임을 다시 진행합니다." << endl;
		}
		else
		{
			cout << "상대가 승리했습니다!" << endl;
			_isGameExit = true;
		}
	}
	//나머지 경기
	else if (_compareWin[0] < _compareWin[1])
	{
		cout << "당신이 승리했습니다!" << endl;
		_isGameExit = true;
	}
	else if (_compareWin[0] == _compareWin[1])
	{
		cout << "게임을 다시 진행합니다." << endl;
	}
	else
	{
		cout << "상대가 승리했습니다!" << endl;
		_isGameExit = true;
	}
}
void MainGame::Update()
{
	SetCard();
	while (_isGameExit == false)
	{
		ShuffleCard();
		GetCard();
		CheckMyCard();
		MyVicDiscrimination();

		CheckComCard();
		ComVicDiscrimination();
		Victory();
	}
}

void MainGame::Release()
{
	cout << endl << "섯다 게임을 종료합니다." << endl;
}

void GotoXY(int x, int y)
{
	COORD pos = { x,y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
/*_myScore 와 _comScore 를 계산해주는 부분이 없어서 일부 로직 정상작동 안할것같네요!
코드깔끔하고 좋아요!!

조금 아쉬운게 있다면, 
MyVicDiscrimination 와 
ComVicDiscrimination 함수는 
통일시킬수있었을것 같은것

함수의 사용이유중에 
가독성
재사용성
이 있는데, 1은 잘지켜진것같은데 2번 부분에서 아쉬워요

Victory 함수명보다는
ShowGameResult 이런 함수명이 더좋지 않을까 싶습니다!

기본적으로 깔끔하고 잘짜셨어요*/