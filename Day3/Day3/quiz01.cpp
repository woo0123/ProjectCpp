#include<iostream>

using namespace std;

void main()
{
	while (1)

	{
		int rps;
		rps = rand() % 3;

		int mypick;

		cout << "1.가위 / 2.바위 / 3.보 (종료 : 5)" << endl;

		cin >> mypick;

		if (mypick == 1)
		{
			if (rps == 0)
			{
				cout << "비겼음" << endl;
			}

			else if (rps == 1)
			{
				cout << "이겼음" << endl;
			}

			else if (rps == 2)
			{
				cout << "졌음" << endl;
			}
		}

		else if (mypick == 2)
		{
			if (rps == 0)
			{
				cout << "졌음" << endl;
			}

			else if (rps == 1)
			{
				cout << "비겼음" << endl;
			}

			else if (rps == 2)
			{
				cout << "이겼음" << endl;
			}
		}

		else if (mypick == 3)
		{
			if (rps == 0)
			{
				cout << "이겼음" << endl;
			}

			else if (rps == 1)
			{
				cout << "졌음" << endl;
			}

			else if (rps == 2)
			{
				cout << "비겼음" << endl;
			}
		}

		else if (mypick == 5)
		{
			break;
		}

		else
		{
			cout << "숫자를 다시 입력해주세요." << endl;
		}
	}
}
