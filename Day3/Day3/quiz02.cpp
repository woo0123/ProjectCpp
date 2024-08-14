#include<iostream>

using namespace std;

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


	cout << "사망하면 게임 종료, 전투에서 승리시 레벨업" << endl << endl;
	cout << "도망친다 선택시 10% 확률로 사망" << endl;
	cout << "사망하면 게임 종료" << endl << endl;

	for (int i = 0; i<500; i++)
	{
		cout << "당신은 던전을 탐험하고 있습니다." << endl;
		cout << "당신은 " << goblinLevel << " 레벨의 고블린과 마주했습니다.(1: 싸운다 / 2: 도망친다)"
			<< endl << "(싸운다 선택시 " << deathrate << "%의 확률로 사망)" << endl;
		cin >> whatDo;
		myrate = rand() % 100 + 1;


		if (whatDo == 1)
		{
			cout << "당신은 고블린과 싸웠습니다." << endl;
			if (myrate > deathrate)
			{
				cout << "당신은 " << myrate << "%의 확률로 고블린과 싸워서 승리했습니다." << endl;
				cout << "당신은" << playerLevel + 1 << " 레벨이 되었습니다." << endl << endl;
				playerLevel++;
				catchgoblin++;
				wave++;
				goblinLevel = (rand() % 2) + playerLevel;
				deathrate = (goblinLevel * 100 / (1 + playerLevel * 2));
			}

			else
			{
				cout << "당신은 " << myrate << "%의 확률로 고블린과 싸워서 패배했습니다." << endl;
				cout << "게임을 종료합니다." << endl;
				break;
			}
		}

		else if (whatDo == 2)
		{
			cout << "당신은 도망치려 했습니다." << endl;
			if (myrate > 10)
			{
				cout << "운이 좋게 " << myrate << "%의 확률로 당신은 고블린으로부터 도망쳤습니다." << endl << endl;
				wave++;
				goblinLevel = (rand() % 2) + playerLevel;
			}

			else
			{
				cout << "당신은 " << myrate << "%의 확률로 고블린에게 도망치지 못하고 사망했습니다." << endl;
				cout << "게임을 종료합니다." << endl;
				break;
			}
		}

		else
		{
			cout << "숫자를 다시 입력해주세요." << endl;
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