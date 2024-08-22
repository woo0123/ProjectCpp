#include<iostream>

using namespace std;

int comfirstNumber = 0;
int comsecondNumber = 0;
int comthirdNumber = 0;

int firstNumber = 0;
int secondNumber = 0;
int thirdNumber = 0;

int gameround = 0;

void shuffleNumber()
{
	int arr[10] = {};

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < 10000; i++)
	{
		int index1 = rand() % 10;
		int index2 = rand() % 10;

		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}

	if (arr[0] == 0)
	{
		shuffleNumber();
	}

	comfirstNumber = arr[0];
	comsecondNumber = arr[1];
	comthirdNumber = arr[2];

}

void chooseNumber()
{
	while (1)
	{
		int userNumber = 0;
		cin >> userNumber;

		firstNumber = userNumber / 100;
		secondNumber = userNumber % 100 / 10;
		thirdNumber = userNumber % 10;

		if (100 < userNumber < 1000)
		{
			break;
		}
		else
		{
			cout << "숫자를 다시 입력해주세요" << endl;
		}
	}
}

void isNumCorrect()
{
	while(1)
	{
		int ball = 0;
		int strike = 0;
		gameround += 1;

		if (comfirstNumber == firstNumber)
			strike += 1;

		if (comsecondNumber == secondNumber)
			strike += 1;

		if (comthirdNumber == thirdNumber)
			strike += 1;

		if (firstNumber == comsecondNumber || firstNumber == comthirdNumber)
			ball += 1;

		if (secondNumber == comfirstNumber || secondNumber == comthirdNumber)
			ball += 1;

		if (thirdNumber == comfirstNumber || thirdNumber == comsecondNumber)
			ball += 1;

		if (strike == 3)
		{
			cout << endl << "정답입니다! 총 "
				<< gameround << " 번 만에 맞췄습니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		cout << strike << " Strike " << ball << " Ball" << endl;

		chooseNumber();
	}
}

void main()
{
	cout << "야구 게임을 시작합니다. 겹치지 않는 숫자 "
		"세 개를 따로 입력해주세요." << endl;

	srand(time(NULL));

	shuffleNumber();

	chooseNumber();

	isNumCorrect();
}