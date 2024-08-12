#include<iostream>

using namespace std;

void main()
{
	int year = 2024;
	if (year == 2024)
	{
		printf("올해는 2024년도 입니다.\n");
	}
	
	int hp = 10;
	if (0 < hp)
	{
		printf("이 유닛은 살아있습니다.\n");
	}
	else
	{
		printf("이 유닛은 죽었습니다.\n");
	}

	int score = 80;
	if (90 <= score)
	{
		printf("이 학생은 A학점입니다.\n");
	}

	else if (80 <= score)
	{
		printf("이 학생은 B학점입니다.\n");
	}

	else if (70 <= score)
	{
		printf("이 학생은 C학점입니다.\n");
	}

	else if (60 <= score)
	{
		printf("이 학생은 D학점입니다.\n");
	}

	else
	{
		printf("이 학생은 F학점입니다.\n");
	}
}

