#include<iostream>

using namespace std;

void main()
{
	int year = 0;
	printf("연도를 입력해주세요 : ");
	scanf_s("%d", &year);

	printf("현재 year : %d\n", year);

	char name[100] = "";
	printf("이름을 입력해주세요. :");
	scanf_s("%s", name, (int)sizeof(name));
	printf("이름 : %s\n", name);

	printf("제 이름은 %s입니다.\n", name);
	printf("저는 %d년생 입니다.\n", year);

}