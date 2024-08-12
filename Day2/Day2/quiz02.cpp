#include<iostream>

using namespace std;

int main()
{
	float middle = 0;
	float final = 0;
	float attendence = 0;
	float work = 0;

	printf("중간고사 성적을 입력해주세요\n");
	scanf_s("%f", &middle);
	printf("기말고사 성적을 입력해주세요\n");
	scanf_s("%f", &final);
	printf("출석 점수를 입력해주세요\n");
	scanf_s("%f", &attendence);
	printf("과제 점수를 입력해주세요\n");
	scanf_s("%f", &work);

	float result = (middle + final + attendence + work) / 4;

	if (result >= 90)
	{
		printf("총점은 %f 이고 A학점입니다.", result);
	}

	else if (result >= 80)
	{
		printf("총점은 %f 이고 B학점입니다.", result);
	}

	else if (result >= 70)
	{
		printf("총점은 %f 이고 C학점입니다.", result);
	}

	else if (result >= 60)
	{
		printf("총점은 %f 이고 D학점입니다.", result);
	}

	else
	{
		printf("총점은 %f 이고 F학점입니다.", result);
	}
}