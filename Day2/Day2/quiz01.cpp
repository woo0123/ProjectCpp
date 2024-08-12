#include<iostream>

using namespace std;

int main()
{
	float height,weight;
	cout << "키(m)와 몸무게(kg)를 차례대로 입력해주세요." << endl;
	cin >> height >> weight;
	float BMI = weight / (height * height);
	
	if (0 < BMI <= 18.5)
	{
		cout << "BMI 지수는 " << BMI << "이고, 저체중입니다." << endl;
	}
	else if (BMI <= 23)
	{
		cout << "BMI 지수는 " << BMI << "이고, 정상체중입니다." << endl;
	}
	else if (BMI <= 25)
	{
		cout << "BMI 지수는 " << BMI << "이고, 과체중입니다." << endl;
	}
	else if (BMI <= 30)
	{
		cout << "BMI 지수는 " << BMI << "이고, 비만입니다." << endl;
	}
	else if (BMI > 30)
	{
		cout << "BMI 지수는 " << BMI << "이고, 고도비만입니다." << endl;
	}
	else
	{
		cout << "다시 입력해주세요" << endl;
	}
}