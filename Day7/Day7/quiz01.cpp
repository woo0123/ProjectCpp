#include<iostream>

using namespace std;

void deckSetting();
void shuffleDeck();

void bettingLow();
void bettingSame();
void bettingHigh();

void cardNumber();
void showCard();
void checkChoice();

void plusIndex();

int deck[4][13] = {};
int playerMoney = 10000;
int playerChoice = -1;
int bettingMoney = 0;
int rowIndex = 0;
int colIndex = 0;
bool isGamePlaying = true;

// 트럼프카드 52장으로 시작
// ♤A ~ ♥K 까지 존재
// 이 트럼프카드를 섞고 

// 플레이어가 입장
// 플레이어는 시작골드 10000원으로 시작
// 베팅을하는데
// 다음카드가 7보다작은지, 7보다큰지, 7이랑 같은지 베팅
// 베팅금액따로 존재
// 
// 베팅을하고, 맞추면 
// 7보다작은지, 7보다큰지 => 2배 지급
// 7인걸 맞추면 => 10배 지급
// 
//
// 트럼프카드를 다쓰거나 플레이어가 파산나면 게임종료

void main()
{
	deckSetting();
	shuffleDeck();

	cout << "하이로우세븐 게임을 시작합니다." << endl << endl;

	while (isGamePlaying)
	{
		cout << "다음 카드가 7보다 낮다고 생각하면 0 " << endl;
		cout << "다음 카드가 7과 같다고 생각하면 1 " << endl;
		cout << "다음 카드가 7보다 높다고 생각하면 2 " << endl;
		cin >> playerChoice;

		checkChoice();

		while (bettingMoney == 0)
		{
			cout << "베팅할 금액을 적어주세요 (현재 보유금: " << playerMoney << ")" << endl;
			cin >> bettingMoney;

			if (bettingMoney > playerMoney)
			{
				cout << "돈이 부족합니다." << endl;
				bettingMoney = 0;
			}
			
			else
			{
				break;
			}
		}

		if (playerChoice == 0)
		{
			bettingLow();
		}

		else if (playerChoice == 1)
		{
			bettingSame();
		}

		else if (playerChoice == 2)
		{
			bettingHigh();
		}

		showCard();
		plusIndex();


		if (playerMoney == 0)
		{
			cout << "파산. 나가!" << endl;
			break;
		}

		if (rowIndex == 4)
		{
			cout << "카드를 모두 소모하여 게임을 종료합니다." << endl;
			break;
		}

		cout << "게임을 계속 하시겠습니까? (그만 : 0 / 계속 : 1 )" << endl;
		cin >> isGamePlaying;
		if (isGamePlaying == 0)
		{
			cout << "게임을 종료합니다." << endl;
		}
	}

	//for (int i = 0; i < 4; i++)
	//{
	//	for (int j = 0; j < 13; j++)
	//	{
	//		if (deck[i][j] / 100 == 1)
	//		{
	//			//스페이드 = 100
	//			cout << "♠";
	//			cout << deck[i][j] % 100;
	//			cout << "\t";
	//		}

	//		else if (deck[i][j] / 100 == 2)
	//		{
	//			//다이아몬드 = 200
	//			cout << "◆";
	//			cout << deck[i][j] % 100;
	//			cout << "\t";
	//		}

	//		else if (deck[i][j] / 100 == 3)
	//		{
	//			//하트 = 300
	//			cout << "♥";
	//			cout << deck[i][j] % 100;
	//			cout << "\t";
	//		}

	//		else if (deck[i][j] / 100 == 4)
	//		{
	//			//클로버 = 400
	//			cout << "♣";
	//			cout << deck[i][j] % 100;
	//			cout << "\t";
	//		}

	//		//deck[i][j] = j + 1;
	//		//cout << deck[i][j] << " ";
	//	}
	//	cout << endl;
	//}




}

void deckSetting()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (i == 0)
			{	
				//스페이드 = 100
				deck[i][j] = 100 + j + 1;
				//cout << "♠";
			}

			else if (i == 1)
			{
				//다이아몬드 = 200
				deck[i][j] = 200 + j + 1;
				//cout << "◆";
			}

			else if (i == 2)
			{
				//하트 = 300
				deck[i][j] = 300 + j + 1;
				//cout << "♥";
			}

			else if (i == 3)
			{
				//클로버 = 400
				deck[i][j] = 400 + j + 1;
				//cout << "♣";
			}

			//deck[i][j] = j + 1;
			//cout << deck[i][j] << " ";
		}
		//cout << endl;
	}
}

void shuffleDeck()
{
	srand(time(NULL));
	for (int i = 0; i < 10000; i++) 
	{
		int index1 = rand() % 4;
		int index2 = rand() % 13;
		int index3 = rand() % 4;
		int index4 = rand() % 13;
		int temp = deck[index1][index2];
		deck[index1][index2] = deck[index3][index4];
		deck[index3][index4] = temp;
	}
}

void bettingLow()
{
	if (deck[rowIndex][colIndex] % 100 < 7)
	{
		cout << "축하합니다 맞추셨습니다. 베팅 금액의 2배를 받습니다." << endl;
		bettingMoney *= 2;
		playerMoney += bettingMoney;
	}
	else
	{
		cout << "아쉽게도 맞추지 못하였습니다. 베팅 금액을 잃습니다." << endl;
		playerMoney -= bettingMoney;
	}

	bettingMoney = 0;
	playerChoice = -1;
}

void bettingHigh()
{
	if (deck[rowIndex][colIndex] % 100 > 7)
	{
		cout << "축하합니다 맞추셨습니다. 베팅 금액의 2배를 받습니다." << endl;
		bettingMoney *= 2;
		playerMoney += bettingMoney;
	}
	else
	{
		cout << "아쉽게도 맞추지 못하였습니다. 베팅 금액을 잃습니다." << endl;
		playerMoney -= bettingMoney;
	}

	bettingMoney = 0;
	playerChoice = -1;
}

void bettingSame()
{
	if (deck[rowIndex][colIndex] % 100 == 7)
	{
		cout << "축하합니다 맞추셨습니다! 베팅 금액의 10배를 받습니다." << endl;
		bettingMoney *= 10;
		playerMoney += bettingMoney;
	}
	else
	{
		cout << "아쉽게도 맞추지 못하였습니다. 베팅 금액을 잃습니다." << endl;
		playerMoney -= bettingMoney;
	}

	bettingMoney = 0;
	playerChoice = -1;
}


void plusIndex()
{
	colIndex++;
	if (colIndex == 13)
	{
		rowIndex++;
		colIndex = 0;
	}
}

void cardNumber()
{
	if (deck[rowIndex][colIndex] % 100 == 11)
	{
		cout << "J";
	}

	else if (deck[rowIndex][colIndex] % 100 == 12)
	{
		cout << "Q";
	}

	else if (deck[rowIndex][colIndex] % 100 == 13)
	{
		cout << "K";
	}

	else if (deck[rowIndex][colIndex] % 100 == 1)
	{
		cout << "A";
	}

	else
	{
		cout << deck[rowIndex][colIndex] % 100;
	}
}

void showCard()
{
	cout << "카드의 정체는 ";
	if (deck[rowIndex][colIndex] / 100 == 1)
	{
		cout << "♠";
	}

	else if (deck[rowIndex][colIndex] / 100 == 2)
	{
		cout << "◆";
	}

	else if (deck[rowIndex][colIndex] / 100 == 3)
	{
		cout << "♥";
	}

	else if (deck[rowIndex][colIndex] / 100 == 4)
	{
		cout << "♣";
	}

	cardNumber();
	cout << " 였습니다!" << endl;
}

void checkChoice()
{
	if (playerChoice == 0)
	{
		cout << "낮다에 배팅하셨습니다.";
	}

	else if (playerChoice == 1)
	{
		cout << "같다에 배팅하셨습니다.";
	}

	else if (playerChoice == 2)
	{
		cout << "높다에 배팅하셨습니다.";
	}

	else
	{
		cout << "유효하지 않은 숫자입니다.";
	}

	cout << endl;
}