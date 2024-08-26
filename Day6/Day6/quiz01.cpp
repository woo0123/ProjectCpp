#include<iostream>

using namespace std;

//둘의 빙고판 번호

int bingo[25] = {};
int comBingo[25] = {};

//둘이 고르는 숫자

int userNumber = 0;
int comNumber = 0;

//둘의 빙고 개수

int userBingoCount = 0;
int comBingoCount = 0;

//숫자가 없음을 판별

int wrongNumber = 0;

//가로행 빙고 행열

int rowUserBingo[5] = {};
int rowComBingo[5] = {};

int rowUserCount = 0;
int rowComCount = 0;

//세로행 빙고 행열

int colUserBingo[5] = {};
int colComBingo[5] = {};

int colUserCount = 0;
int colComCount = 0;

//대각선 빙고 행열

int diaUserBingo[2] = {};
int diaComBingo[2] = {};

int diaUserCount = 0;
int diaComCount = 0;

void setUserRow()
{
	for (int i = 0; i < 5; i++)
	{
		rowUserBingo[i] = 0;
	}
}

void setUserCol()
{
	for (int i = 0; i < 5; i++)
	{
		colUserBingo[i] = 0;
	}
}

void setUserDia()
{
	for (int i = 0; i < 2; i++)
	{
		diaUserBingo[i] = 0;
	}
}

void setComRow()
{
	for (int i = 0; i < 5; i++)
	{
		rowComBingo[i] = 0;
	}
}

void setComCol()
{
	for (int i = 0; i < 5; i++)
	{
		colComBingo[i] = 0;
	}
}

void setComDia()
{
	for (int i = 0; i < 2; i++)
	{
		diaComBingo[i] = 0;
	}
}

void showBingo() 
{
	cout << "나의 빙고판" << endl << endl;

	for (int i = 0; i < 25; i++)
	{
		cout << bingo[i] << "\t";
		if (i % 5 == 4)
		{
			cout << endl;
		}
	}
	cout << endl;
}

void setBingo()
{
	for (int i = 0; i < 25; i++)
	{
		bingo[i] = i + 1;
	}
}

void resetBingo()
{
	for (int i = 0; i < 10000; i++)
	{
		int index1 = rand() % 25;
		int index2 = rand() % 25;

		int temp = bingo[index1];
		bingo[index1] = bingo[index2];
		bingo[index2] = temp;
	}
}

void showComBingo()
{
	cout << "상대의 빙고판" << endl << endl;

	for (int i = 0; i < 25; i++)
	{
		cout << comBingo[i] << "\t";
		if (i % 5 == 4)
		{
			cout << endl;
		}
	}
	cout << endl;
}

void setComBingo()
{
	for (int i = 0; i < 25; i++)
	{
		comBingo[i] = i + 1;
	}
}

void resetComBingo()
{
	for (int i = 0; i < 10000; i++)
	{
		int index1 = rand() % 25;
		int index2 = rand() % 25;

		int temp = comBingo[index1];
		comBingo[index1] = comBingo[index2];
		comBingo[index2] = temp;
	}
}

void userMarking()
{
	wrongNumber = 0;

	cout << "어느 번호를 지우시겠습니까?" << endl;
	cin >> userNumber;

	if (userNumber == 0)
	{
		cout << "다시 입력해주세요" << endl;
		userMarking();
	}

	for (int i = 0; i < 25; i++)
	{
		if (bingo[i] == userNumber)
		{
			bingo[i] = 0;
		}

		else
		{
			wrongNumber++;
		}
	}

	for (int i = 0; i < 25; i++)
	{
		if (comBingo[i] == userNumber)
		{
			comBingo[i] = 0;
		}

		else
		{
			wrongNumber++;
		}
	}

	if (wrongNumber == 50)
	{
		cout << "다시 입력해주세요" << endl;
		userMarking();
	}
}

void comMarking()
{
	wrongNumber = 0;
	comNumber = rand() % 25 + 1;

	for (int i = 0; i < 25; i++)
	{
		if (comBingo[i] == comNumber)
		{
			comBingo[i] = 0;
		}

		else
		{
			wrongNumber++;
		}
	}

	for (int i = 0; i < 25; i++)
	{
		if (bingo[i] == comNumber)
		{	
			bingo[i] = 0;
		}

		else
		{
			wrongNumber++;
		}
	}

	if (wrongNumber == 50)
	{
		comMarking();
	}
}

void rowBingo()
{
	//유저의 가로
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (bingo[i * 5 + j] != 0)
				break;

			else
			{
				rowUserCount++;
			}
		}

		if (rowUserCount == 5 && rowUserBingo[i] == 0)
		{
			rowUserBingo[i]++;
			userBingoCount++;
		}

		rowUserCount = 0;
	}

	//컴퓨터의 가로
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (comBingo[i * 5 + j] != 0)
				break;

			else
			{
				rowComCount++;
			}
		}

		if (rowComCount == 5 && rowUserBingo[i] == 0)
		{
			rowComBingo[i]++;
			comBingoCount++;
		}

		rowComCount = 0;
	}
}


void colBingo()
{
	//유저의 세로
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (bingo[i + j * 5] != 0)
				break;

			else
			{
				colUserCount++;
			}
		}

		if (colUserCount == 5 && colUserBingo[i] == 0)
		{
			colUserBingo[i]++;
			userBingoCount++;
		}

		colUserCount = 0;
	}

	//컴퓨터의 세로
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (comBingo[i + j * 5] != 0)
				break;

			else
			{
				colComCount++;
			}
		}

		if (colComCount == 5 && colUserBingo[i] == 0)
		{
			colComBingo[i]++;
			comBingoCount++;
		}

		colComCount = 0;
	}
}

void diaBingo()
{
	//왼대각
	for (int i = 0; i < 5; i++)
	{
		if (bingo[i * 6] != 0)
		{
			break;
		}

		else
		{
			diaUserCount++;
		}

		if (diaUserCount == 5 && diaUserBingo[0] == 0)
		{
			diaUserBingo[0]++;
			userBingoCount++;
		}

	}

	diaUserCount = 0;

	//오른대각
	for (int i = 0; i < 5; i++)
	{
		if (bingo[i * 4] != 0)
		{
			break;
		}

		else
		{
			diaUserCount++;
		}

		if (diaUserCount == 5 && diaUserBingo[1] == 0)
		{
			diaUserBingo[1]++;
			userBingoCount++;
		}

	}

	diaUserCount = 0;

	//왼대각
	for (int i = 0; i < 5; i++)
	{
		if (comBingo[i * 6] != 0)
		{
			break;
		}

		else
		{
			diaComCount++;
		}

		if (diaComCount == 5 && diaComBingo[0] == 0)
		{
			diaComBingo[0]++;
			comBingoCount++;
		}

	}

	diaComCount = 0;

	//오른대각
	for (int i = 0; i < 5; i++)
	{
		if (comBingo[i * 4] != 0)
		{
			break;
		}

		else
		{
			diaComCount++;
		}

		if (diaComCount == 5 && diaComBingo[1] == 0)
		{
			diaComBingo[1]++;
			comBingoCount++;
		}

	}

	diaComCount = 0;
}


void bingos()
{
	rowBingo();
	colBingo();
	diaBingo();
}

void announceBingoCount()
{
	cout << "나 : " << userBingoCount << " 빙고" << endl;
	cout << "상대 : " << comBingoCount << " 빙고" << endl << endl;
}

void main()
{
	srand(time(NULL));

	setBingo();

	resetBingo();

	showBingo();

	cout << endl;

	setComBingo();

	resetComBingo();

	showComBingo();

	while(userBingoCount != 3 && comBingoCount != 3)
	{
		userNumber = 0;
		comNumber = 0;

		userMarking();
		cout << "당신은 " << userNumber << "번을 지웠습니다." << endl << endl;
		showBingo();
		showComBingo();

		comMarking();
		cout << "상대는 " << comNumber << "번을 지웠습니다." << endl;
		showBingo();
		showComBingo();

		bingos();
		announceBingoCount();
	}
}