#include<iostream>

using namespace std;

void main()
{
	for (int i = 0; i < 1000; i++)
	{
		//1000번 반복
	}

	bool isGamePlaying = true;
	//while (isGamePlaying)
	//{
	//	cout << "게임을 종료하시겠습니까? (0 : 예, 그 외 : 아니요)" << endl;
	//	int choice;
	//	cin >> choice;
	//	if (choice == 0)
	//	{
	//		isGamePlaying = false;
	//	}
	//}

	for (;isGamePlaying;)
	{
		cout << "게임을 종료하시겠습니까? (0 : 예, 그 외 : 아니요)" << endl;
		int choice;
		cin >> choice;
		if (choice == 0)
		{
			isGamePlaying = false;
		}
	}

	int i = 0;

	while (i < 10)
	{
		cout << i << endl;
		i++;
	}


}