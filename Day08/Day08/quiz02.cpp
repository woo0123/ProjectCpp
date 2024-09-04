#include<iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

struct Monster
{
	float hp;
	float attack;

	void PrintInfo(Monster)
	{
		cout << "몬스터 HP : " << this->hp << endl;
		cout << "몬스터 ATK : " << this->attack << endl;
	}
};

struct Human
{
	float hp;
	float attack;

	void PrintInfo(Human)
	{
		cout << "나의 HP : " << this->hp << endl;
		cout << "나의 ATK : " << this->attack << endl;
	}
};

void GotoXY(int x, int y);


void main()
{
	srand(time(NULL));

	Monster monster = { };
	monster.hp = 100;
	monster.attack = 20;

	Human human = { };
	human.hp = 100;
	human.attack = 20;

	int comChoice = rand() % 3;
	int criticalRate = 1 + rand() % 100;

	while(human.hp != 0 || monster.hp != 0)
	{
		GotoXY(0, 0); monster.PrintInfo(monster);
		GotoXY(0, 9); human.PrintInfo(human);

		GotoXY(0, 13); cout << "┌─────────────────────────────────────────────┐";
		GotoXY(0, 14); cout << "│ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ ㅤㅤㅤㅤㅤㅤㅤ│";
		GotoXY(0, 15); cout << "│ㅤㅤㅤ 1. 가위ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ ㅤ│";
		GotoXY(0, 16); cout << "│ㅤㅤㅤ 2. 바위ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ │";
		GotoXY(0, 17); cout << "│ㅤㅤㅤ 3. 보ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ ㅤㅤ│";
		GotoXY(0, 18); cout << "│ㅤㅤㅤ (s와 w로 이동 / k로 선택)ㅤㅤ ㅤㅤㅤㅤ│";
		GotoXY(0, 19); cout << "└─────────────────────────────────────────────┘";

		GotoXY(3, 15);
		cout << "▶▷";
		int choice = 0;
		//선택지를 선택하는 커맨드
		while (true)
		{
			if (_kbhit())
			{
				char inputkey = _getch();
				GotoXY(3, 15 + choice);
				cout << "ㅤㅤ";

				if (inputkey == 's')
				{
					if (choice == 2)
					{
						choice == 2;
					}
					else
					{
						choice++;
					}
				}

				else if (inputkey == 'w')
				{
					if (choice == 0)
					{
						choice == 0;
					}
					else
					{
						choice--;
					}
				}

				GotoXY(3, 15 + choice);
				cout << "▶▷";

				if (inputkey == 'k')
				{
					break;
				}
			}
		}

		//컴퓨터 가위바위보 경우
		switch (comChoice)
		{
		case 0:
			GotoXY(0, 21); cout << "상대는 가위를 냈습니다.            ";
			break;

		case 1:
			GotoXY(0, 21); cout << "상대는 바위를 냈습니다.            ";
			break;

		case 2:
			GotoXY(0, 21); cout << "상대는 보를 냈습니다.            ";
			break;
		}
		//비긴 경우
		if (choice == comChoice)
		{
			GotoXY(0, 22); cout << "비겼습니다.";
			GotoXY(0, 23); cout << "다시 가위바위보를 진행합니다.                                                                         ";
		}
		//컴퓨터가 이긴 모든 경우
		else if (choice == 0 && comChoice == 1)
		{
			GotoXY(0, 22); cout << "졌습니다.        ";
			if (criticalRate <= 5)
			{
				GotoXY(0, 23); cout << "당신은 5%의 확률을 뚫고 크리티컬로 상대를 공격했습니다. 2배의 데미지를 입힙니다.";
				if (monster.attack * 2 > human.hp)
				{
					human.hp == 0;
				}
				else
				{
					human.hp = human.hp - monster.attack * 2;
				}
			}
			else
			{
				GotoXY(0, 23); cout << "몬스터가 당신을 " << monster.attack << "의 공격력으로 공격했습니다.                                                      ";
				if (monster.attack > human.hp)
				{
					human.hp == 0;
				}
				else
				{
					human.hp = human.hp - monster.attack;
				}
			}
		}
		else if (choice == 1 && comChoice == 2)
		{
			GotoXY(0, 22); cout << "졌습니다.        ";
			if (criticalRate <= 5)
			{
				GotoXY(0, 23); cout << "몬스터가 5%의 확률을 뚫고 크리티컬로 상대를 공격했습니다. 2배의 데미지를 입습니다.";
				if (monster.attack * 2 > human.hp)
				{
					human.hp == 0;
				}
				else
				{
					human.hp = human.hp - monster.attack * 2;
				}
			}
			else
			{
				GotoXY(0, 23); cout << "몬스터가 당신을 " << monster.attack << "의 공격력으로 공격했습니다.                                                      ";
				if (monster.attack > human.hp)
				{
					human.hp == 0;
				}
				else
				{
					human.hp = human.hp - monster.attack;
				}
			}
		}
		else if (choice == 2 && comChoice == 0)
		{
			GotoXY(0, 22); cout << "졌습니다.        ";
			if (criticalRate <= 5)
			{
				GotoXY(0, 23); cout << "몬스터가 5%의 확률을 뚫고 크리티컬로 상대를 공격했습니다. 2배의 데미지를 입습니다.";
				if (monster.attack * 2 > human.hp)
				{
					human.hp == 0;
				}
				else
				{
					human.hp = human.hp - monster.attack * 2;
				}
			}
			else
			{
				GotoXY(0, 23); cout << "몬스터가 당신을 " << monster.attack << "의 공격력으로 공격했습니다.                                                      ";
				if (monster.attack > human.hp)
				{
					human.hp == 0;
				}
				else
				{
					human.hp = human.hp - monster.attack;
				}
			}
		}
		//내가 이긴 경우
		else
		{
			GotoXY(0, 22); cout << "이겼습니다.";
			if (criticalRate <= 5)
			{
				GotoXY(0, 23); cout << "당신은 5%의 확률을 뚫고 크리티컬로 상대를 공격했습니다. 2배의 데미지를 입힙니다.";
				if (human.attack * 2 > monster.hp)
				{
					monster.hp == 0;
				}
				else
				{
					monster.hp = monster.hp - human.attack * 2;
				}
			}
			else
			{
				GotoXY(0, 23); cout << "당신은 몬스터를 " << human.attack << "의 공격력으로 공격했습니다.                                                      ";
				if (human.attack  > monster.hp)
				{
					monster.hp == 0;
				}
				else
				{
					monster.hp = monster.hp - human.attack;
				}
			}
		}
		GotoXY(0, 0); cout << "                           ";
		GotoXY(0, 9); cout << "                           ";
		GotoXY(0, 0); monster.PrintInfo(monster);
		GotoXY(0, 9); human.PrintInfo(human);

		if (human.hp == 0)
		{
			GotoXY(0, 25); cout << "몬스터에게 패배했습니다." << endl;
			cout << "게임을 종료합니다.";
			break;
		}
		if (monster.hp == 0)
		{
			GotoXY(0, 25); cout << "몬스터를 처치했습니다." << endl;
			cout << "게임을 종료합니다.";
			break;
		}
		comChoice = rand() % 3;
		criticalRate = 1 + rand() % 100;
		choice = 0;
	}
}

void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}