#include<iostream>

using namespace std;

int main()
{
	int num;
	cout << "숫자를 입력해주세요" << endl;
	cin >> num;
	int result = num % 2;
	if (result == 1)
	{
		cout << num << "은 홀수입니다." << endl;
	}
	else
	{
		cout << num << "은 짝수입니다." << endl;
	}
}