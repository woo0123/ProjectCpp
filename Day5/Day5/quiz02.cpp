#include<iostream>

using namespace std;

void main()
{
	// 1번
	// *    
	// **   
	// ***  
	// **** 
	// *****

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j <= i)
			{
				cout << "*";
			}
		}
		cout << endl;
	}

	cout << endl;

	// 2번
	// *****
	// ****
	// ***
	// **
	// *

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j >= i)
			{
				cout << "*";
			}
		}
		cout << endl;
	}

	cout << endl;

	// 3번
	//     *
	//    **
	//   ***
	//  ****
	// *****

	for (int i = 0; i < 5; i++)
	{
		for (int j = 5; j > 0; j--)
		{
			if (j <= i + 1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	cout << endl;

	// 4번
	// *****
	//  ****
	//   ***
	//    **
	//     *

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j < i)
			{
				cout << " ";
			}
			else
			{
				cout << "*";
			}
		}
		cout << endl;
	}

	cout << endl;

	// 5번
	// *    *****
	// **   ****
	// ***  ***
	// **** **
	// ******
	//     ******
	//    ** ****
	//   ***  ***
	//  ****   **
	// *****    *

	//5번 같은 경우에 구현하는 것은 성공하였으나
	//좀 더 쉬운 방법이 있다면 설명해주세요!

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			for (int j = 0; j < 10; j++)
			{
				if (j <= i)
				{
					cout << "*";
				}

				else if (j< 5 && j>i)
				{
					cout << " ";
				}

				if (j > 4)
				{
					if (j + i < 10)
					{
						cout << "*";
					}

					else
					{
						cout << " ";
					}
				}
			}
			cout << endl;
		}

		//이때 i 값은 5

		else
		{
			for (int j = 0; j < 10; j++)
			{
				if (j < 5 && j + i >= 9)
				{
					cout << "*";
				}

				else if (j < 5 && j + i < 9)
				{
					cout << " ";
				}

				if (j > 4)
				{
					if (i - j <= 0)
					{
						cout << "*";
					}

					else
					{
						cout << " ";
					}
				}
			}
			cout << endl;
		}
	}
}