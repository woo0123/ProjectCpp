#include<iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void GotoXY(int x, int y);

void main()
{
	int korean = -1;
	int math = -1;
	int english = -1;
	int average = 0;

	GotoXY(0, 1); cout << "┌─────────────────────────────────────────────────────┐";
	GotoXY(0, 2); cout << "│ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ ㅤㅤㅤ│";
	GotoXY(0, 3); cout << "│ㅤㅤ수학 :ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ ㅤㅤㅤ│";
	GotoXY(0, 4); cout << "│ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ ㅤㅤㅤ│";
	GotoXY(0, 5); cout << "│ㅤㅤ영어 :ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ ㅤㅤㅤ│";
	GotoXY(0, 6); cout << "│ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ ㅤㅤㅤ│";
	GotoXY(0, 7); cout << "│ㅤㅤ국어 :ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ ㅤㅤㅤ│";
	GotoXY(0, 8); cout << "│ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ ㅤㅤㅤ│";
	GotoXY(0, 9); cout << "│ㅤㅤ평균 :ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ ㅤㅤㅤ│";
	GotoXY(0, 10); cout << "│ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ ㅤㅤㅤ│";
	GotoXY(0, 11); cout << "└─────────────────────────────────────────────────────┘";

	while (0 > math || math > 100)
	{
		GotoXY(0, 13); cout << "수학 점수를 입력해주세요. :";
		cin >> math;
		if (0 <= math <= 100)
		{
			GotoXY(13, 3); cout << math;
		}
		else
		{
			GotoXY(0, 13); cout << "다시 입력해주세요						";
		}
	}

	GotoXY(0, 13); cout << "                                               ";

	while (0 > english || english > 100)
	{
		GotoXY(0, 13); cout << "영어 점수를 입력해주세요. :";
		cin >> english;
		if (0 <= english <= 100)
		{
			GotoXY(13, 5); cout << english;
		}
		else
		{
			GotoXY(0, 13); cout << "다시 입력해주세요						";
		}
	}

	GotoXY(0, 13); cout << "                                               ";

	while (0 > korean || korean > 100)
	{
		GotoXY(0, 13); cout << "국어 점수를 입력해주세요. :";
		cin >> korean;
		if (0 <= korean <= 100)
		{
			GotoXY(13, 7); cout << korean;
		}
		else
		{
			GotoXY(0, 13); cout << "다시 입력해주세요						";
		}
	}

	GotoXY(0, 13); cout << "                                               ";

	average = (math + english + korean) / 3;
	GotoXY(13, 9); cout << average;
	GotoXY(0, 13); cout << "당신의 학생부가 완성됐습니다." << endl;
	cout << "프로그램을 종료합니다." << endl;
}

void GotoXY(int x, int y)
{
	COORD pos = { x,y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}