#include<iostream>
using namespace std;

class Animal
{
public:
	int aa;
	int bb;
};

void main()
{
	//캐스팅 3대장

	Animal* animal;

	float a = 3.3;
	int b = (int)a;
	
	//C형식의 캐스팅
	//귀찮으면 쓰긴 함

	int* c = new int();
	animal = (Animal*)c;
	printf("animal.aa : %d\n", animal->aa);
	printf("animal.bb : %d\n", animal->bb);

	int intVariable = 3;
	float floatVariable = 5.3f;

	int newValue = intVariable + static_cast<int>(floatVariable);
	//int newValue = intVariable + (int)floatVariable;

	//static_cast 
	//불가능한 캐스팅은 에러띄움.

	//dynamic_cast
	//클래스끼리 무언가 관계가 있을 때 클래스 자료형끼리 변환을 자유롭게 해주는
	//캐스팅 방식임.
	

	//reinterpret_cast
	//위험한 캐스팅방식
	//메모리구조 그대로 변형해서 캐스팅하는 방식

}