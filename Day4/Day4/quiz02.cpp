#include<iostream>

using namespace std;

enum class eRockScissorPaper
{
	SCISSOR = 1,
	ROCK,
	PAPER,
	END
};

void main()
{
	srand(time(NULL));

	int computerFirstChoice = 1 + rand() % (int)eRockScissorPaper::PAPER;
	int computerSecondChoice = 1 + rand() % (int)eRockScissorPaper::PAPER;
	int computerFinalChoice = rand() % 2;

	int myFirstChoice = 0;
	int	mySecondChoice = 0;
	int myFinalChoice = 0;

	// 1 일때 가위
	// 2 일때 바위
	// 3 일때 보

	cout << "가위(1), 바위(2), 보(3) 중에 2개를 선택하세요." << endl;
	cin >> myFirstChoice >> mySecondChoice;
	cout << "당신은 ";

	if (myFirstChoice == (int)eRockScissorPaper::SCISSOR)
	{
		cout << "가위";
	}
	else if (myFirstChoice == (int)eRockScissorPaper::ROCK)
	{
		cout << "바위";
	}
	else if (myFirstChoice == (int)eRockScissorPaper::PAPER)
	{
		cout << "보";
	}

	cout << "와 ";

	if (mySecondChoice == (int)eRockScissorPaper::SCISSOR)
	{
		cout << "가위";
	}
	else if (mySecondChoice == (int)eRockScissorPaper::ROCK)
	{
		cout << "바위";
	}
	else if (mySecondChoice == (int)eRockScissorPaper::PAPER)
	{
		cout << "보";
	}

	cout << "를 선택했습니다." << endl;

	cout << "컴퓨터는 ";

	if (computerFirstChoice == (int)eRockScissorPaper::SCISSOR)
	{
		cout << "가위";
	}
	else if (computerFirstChoice == (int)eRockScissorPaper::ROCK)
	{
		cout << "바위";
	}
	else if (computerFirstChoice == (int)eRockScissorPaper::PAPER)
	{
		cout << "보";
	}

	cout << "와 ";

	if (computerSecondChoice == (int)eRockScissorPaper::SCISSOR)
	{
		cout << "가위";
	}
	else if (computerSecondChoice == (int)eRockScissorPaper::ROCK)
	{
		cout << "바위";
	}
	else if (computerSecondChoice == (int)eRockScissorPaper::PAPER)
	{
		cout << "보";
	}

	cout << "를 선택했습니다." << endl;

	cout << "당신은 어떤 걸 내겠습니까? (순서대로 1번/2번)" << endl;
	cin >> myFinalChoice;

	if (myFinalChoice == 1)
	{
		cout << "당신은 ";

		if (myFirstChoice == (int)eRockScissorPaper::SCISSOR)
		{
			cout << "가위";
		}
		else if (myFirstChoice == (int)eRockScissorPaper::ROCK)
		{
			cout << "바위";
		}
		else if (myFirstChoice == (int)eRockScissorPaper::PAPER)
		{
			cout << "보";
		}

		cout << "를 냈습니다." << endl;
	}

	else if (myFinalChoice == 2)
	{
		cout << "당신은 ";

		if (mySecondChoice == (int)eRockScissorPaper::SCISSOR)
		{
			cout << "가위";
		}
		else if (mySecondChoice == (int)eRockScissorPaper::ROCK)
		{
			cout << "바위";
		}
		else if (mySecondChoice == (int)eRockScissorPaper::PAPER)
		{
			cout << "보";
		}

		cout << "를 냈습니다." << endl;
	}

	if (computerFinalChoice == 0)
	{
		cout << "컴퓨터는 ";

		if (computerFirstChoice == (int)eRockScissorPaper::SCISSOR)
		{
			cout << "가위";
		}
		else if (computerFirstChoice == (int)eRockScissorPaper::ROCK)
		{
			cout << "바위";
		}
		else if (computerFirstChoice == (int)eRockScissorPaper::PAPER)
		{
			cout << "보";
		}

		cout << "를 냈습니다." << endl;
	}

	else if (computerFinalChoice == 1)
	{
		cout << "컴퓨터는 ";

		if (computerSecondChoice == (int)eRockScissorPaper::SCISSOR)
		{
			cout << "가위";
		}
		else if (computerSecondChoice == (int)eRockScissorPaper::ROCK)
		{
			cout << "바위";
		}
		else if (computerSecondChoice == (int)eRockScissorPaper::PAPER)
		{
			cout << "보";
		}

		cout << "를 냈습니다." << endl;
	}

	cout << endl;
	//줄바꿈

	if (myFinalChoice == computerFinalChoice)
	{
		cout << "비겼습니다." << endl;
	}
	else if (myFinalChoice == (int)eRockScissorPaper::SCISSOR && computerFinalChoice == (int)eRockScissorPaper::ROCK)
	{
		cout << "졌습니다." << endl;
	}
	else if (myFinalChoice == (int)eRockScissorPaper::ROCK && computerFinalChoice == (int)eRockScissorPaper::PAPER)
	{
		cout << "졌습니다." << endl;
	}
	else if (myFinalChoice == (int)eRockScissorPaper::PAPER && computerFinalChoice == (int)eRockScissorPaper::SCISSOR)
	{
		cout << "졌습니다." << endl;
	}
	else
	{
		cout << "이겼습니다." << endl;
	}
}

