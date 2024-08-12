#include<iostream>

using namespace std;

void main()
{
	int year = 05;
	char name[20] = "지현우";
	float height = 170;
	char hometown[100] = "울산";
	char phone[100] = "삼성";
	
	printf("year ; %d\n", year);
	printf("name : %s\n", name);

	printf("year : %d\nname : %s\nheight : %.1f\nhometown = %s\nphone = %s\n", year, name, height, hometown, phone);
}