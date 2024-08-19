#include<iostream>

using namespace std;

void main()
{
	srand(time(NULL));
	int lotteryList[45] = {};

	cout << "로또 번호 뽑기를 시작하겠습니다." << endl;

	for (int i = 0; i < 45; i++)
	{
		lotteryList[i] = i + 1;
	}

	for (int i = 0; i < 100000; i++)
	{
		int index1 = rand() % 45;
		int index2 = rand() % 45;

		int temp = lotteryList[index1];
		lotteryList[index1] = lotteryList[index2];
		lotteryList[index2] = temp;
	}

	for (int i = 0; i < 6; i++)
	{
		cout << i + 1 << "번째 숫자는 " << lotteryList[i] << " 입니다." << endl;
	}

	cout << "보너스 번호는 " << lotteryList[6] << " 입니다." << endl;

	cout << "당첨 번호는 {";
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (lotteryList[i] < lotteryList[j])
			{
				int temp = lotteryList[i];
				lotteryList[i] = lotteryList[j];
				lotteryList[j] = temp;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << lotteryList[i] << ", ";
	}
	cout << lotteryList[5] << "} + {" <<lotteryList[6]<<"} 입니다." << endl;
}