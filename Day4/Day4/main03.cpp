#include<iostream>

using namespace std;

void main()
{
	int arr[10] = {};

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << "arr[" << i << "] " << arr[i] << endl;
	}

	cout << endl;

	srand(time(NULL));

	for (int i = 0; i < 100000; i++)
	{
		int index1 = rand() % 10;
		int index2 = rand() % 10;

		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << "arr[" << i << "] " << arr[i] << endl;
	}
}