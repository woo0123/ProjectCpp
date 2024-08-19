#include<iostream>

using namespace std;

int main()
{
	int a = 100;
	int b = 30;

	int temp;
	temp = a;
	a = b;
	b = temp;

	cout << a << endl << b << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "i : " << i << endl;
	}
}