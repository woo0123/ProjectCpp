#include<iostream>

using namespace std;

int main()
{
	while (1)
	{
		cout << "프로그램을 종료하려면 연산에서 5를 입력해주세요" << endl;

		float num1, num2;
		cout << "숫자 1과 2를 차례대로 입력해주세요." << endl;
		cin >> num1 >> num2;

		float menu;
		cout << "어떤 연산을 진행할까요? (1 : +, 2 : -, 3 : *, 4 : / )" << endl;
		cin >> menu;

		if (menu == 1)
		{
			float result = num1 + num2;
			cout << num1 << " + " << num2 << " = " << result << "입니다." << endl;
		}

		else if (menu == 2)
		{
			float result = num1 - num2;
			cout << num1 << " - " << num2 << " = " << result << "입니다." << endl;
		}

		else if (menu == 3)
		{
			float result = num1 * num2;
			cout << num1 << " * " << num2 << " = " << result << "입니다." << endl;
		}

		else if (menu == 4)
		{
			float result = num1 / num2;
			cout << num1 << " / " << num2 << " = " << result << "입니다." << endl;
		}

		else if (menu == 5)
		{
			break;
		}

		else
		{
			cout << "존재하지 않는 연산입니다." << endl;
		}
	}
}