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

//강사 I 수신자 사용자 (DM) 8:51 PM
변수명이랑 함수명의 네이밍규칙을 같게하지마세요 서로 다르게해주세요!
2.
if (comfirstNumber == firstNumber)
strike += 1;

이런식의 한줄적기위한 if문이라도 중괄호는 꼭 써주세요!

추후에, 유지보수할때 어쩌피 여러줄이 될 확률이 매우 높습니다.
(로그라도 찍기위해)
3. #define 써서 3자리, 4자리 숫자야구 충분히 만드실수있으실거같은데

// while 안에 isNumCorrect, chooseNumber 하는형식을 main	서하면 더좋았을것같음.
// shuffleNumber에서 첫번째자리수 0 뽑힐수도있을것같음
이부분은 숙제풀이 참고해주세요

기본적으로 수도코드생각하는과정은 저랑 비슷하셨어요!
빙고 피드백
1. 함수명은 꼭 동사로 시작해주세요
- 함수는 동사의 의미가 아니면 쓰일경우가 없어요
- 변수는 명사, 함수는 동사 기억해주세요

2. while문 true로 안묶은건 매우좋은데,
userBingoCount != 3 && comBingoCount != 3
가아니라
3 <= userBingoCount && 3 <= comBingoCount
가 맞을것같아요!

1번피드백 추가 :
userMarking() 함수는 MarkUserBingo() 이런식으로 동사를 앞으로 보내면 좋아요
함수는 액션포인트라서요

3.
if (userNumber == 0)
{
	cout << "다시 입력해주세요" << endl;
	userMarking();
}

이 부분 자기함수를 다시 호출하는거 안좋아요.차라리 while문으로 묶어주세요

나중에 유지보수 진행되고하면 아래 로직이 길어지면 길어질수록 알수없는 버그를 초래합니다.

4. 함수명을 깔끔하게 잘지었긴한데, 뭔가 함수명만보고 어떤의미인지 판단하기가 
난해한부분이 있었어요 조금만 신경써주면 좋을거같아요.
전체적으로 되게 잘하셨어요!