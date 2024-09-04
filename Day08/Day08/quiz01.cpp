#include<iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void GotoXY(int x, int y);

void main()
{
	srand(time(NULL));

	int playerLevel = 1;
	int goblinLevel = (rand() % 2) + playerLevel;
	int whatDo = 0;
	int deathrate = (goblinLevel * 100 / (1 + playerLevel * 2));
	int myrate = rand() % 100 + 1;
	//나의 확률 1~100% 까지
	int catchgoblin = 0;
	int wave = 0;
	int choice = 0;


	cout << "사망하면 게임 종료, 전투에서 승리시 레벨업" << endl << endl;
	cout << "도망친다 선택시 10% 확률로 사망" << endl;
	cout << "사망하면 게임 종료" << endl;
	cout << "w와 s로 이동 / k로 선택" << endl << endl;

	while(wave != 3)
	{//678줄
		GotoXY(0, 6); cout << "당신은 던전을 탐험하고 있습니다." << endl;
		GotoXY(0, 7); cout << "당신은 " << goblinLevel << " 레벨의 고블린과 마주했습니다.(1: 싸운다 / 2: 도망친다)";
		GotoXY(0, 8); cout << "(싸운다 선택시 " << deathrate << "%의 확률로 사망)";

		GotoXY(0, 10); cout << "┌─────────────────────────────────────────────────────┐";
		GotoXY(0, 11); cout << "│ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ ㅤㅤㅤ│";
		GotoXY(0, 12); cout << "│ㅤㅤㅤ 1. 싸운다ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ               │";
		GotoXY(0, 13); cout << "│ㅤㅤㅤ 2. 도망친다ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ ㅤㅤ│";
		GotoXY(0, 14); cout << "│ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ ㅤㅤㅤ│";
		GotoXY(0, 15); cout << "└─────────────────────────────────────────────────────┘";

		myrate = rand() % 100 + 1;

		GotoXY(3, 12);
		cout << "▶▷";
		int choice = 0;
		while (true)
		{

			if (_kbhit())	//키보드를 눌렀다면
			{
				char inputkey = _getch();	//누른값을 inputkey에 담겠다.
				GotoXY(3, 12 + choice);
				cout << "ㅤㅤ";	//기존거를 지워주고

				if (inputkey == 's')
				{
					if (choice == 1)
					{
						choice == 1;
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

				GotoXY(3, 12 + choice);
				cout << "▶▷";	// 새로 그 위치에 그린다.

				if (inputkey == 'k')
				{
					break;
				}
			}
		}

		if (choice == 0)
		{
			GotoXY(0, 17); cout << "당신은 고블린과 싸웠습니다.";
			if (myrate > deathrate)
			{
				GotoXY(0, 18); cout << "당신은 " << myrate << "%의 확률로 고블린과 싸워서 승리했습니다.";
				GotoXY(0, 19); cout << "당신은 " << playerLevel + 1 << " 레벨이 되었습니다.";
				playerLevel++;
				catchgoblin++;
				wave++;
				goblinLevel = (rand() % 2) + playerLevel;
				deathrate = (goblinLevel * 100 / (1 + playerLevel * 2));
			}

			else
			{
				GotoXY(0, 18); cout << "당신은 " << myrate << "%의 확률로 고블린과 싸워서 패배했습니다.";
				GotoXY(0, 19); cout << "게임을 종료합니다.            ";
				break;
			}
		}

		else if (choice == 1)
		{
			GotoXY(0, 17); cout << "당신은 도망치려 했습니다.       ";
			if (myrate > 10)
			{
				GotoXY(0, 18); cout << "운이 좋게 " << myrate << "%의 확률로 당신은 고블린으로부터 도망쳤습니다.";
				GotoXY(0, 19); cout << "                                                                        ";
				wave++;
				goblinLevel = (rand() % 2) + playerLevel;
			}

			else
			{
				GotoXY(0, 18); cout << "당신은 " << myrate << "%의 확률로 고블린에게 도망치지 못하고 사망했습니다.";
				GotoXY(0, 19); cout << "게임을 종료합니다.            ";
				break;
			}
		}

		if (wave == 3)
		{
			cout << "당신은 총 " << catchgoblin << " 마리의 고블린을 잡고 던전에서 탈출하였습니다." << endl;
			if (catchgoblin == 0)
			{
				cout << "당신은 평화주의자 업적을 달성했습니다!" << endl;
			}
			cout << "게임을 플레이 해주셔서 감사합니다." << endl;
			break;
		}
	}
}

void GotoXY(int x, int y)
{
	COORD pos = { x,y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}