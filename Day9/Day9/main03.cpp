#include<iostream>

using namespace std;


struct Monster
{
private:	//나만 접근
public:	//모두가 접근
	int Hp; 
	int Attack;
};

class CMonster
{
public:	//퍼블릭 없으면 빨간줄 나옴
	int Hp;
	int Attack;
};

void main()
{
	Monster a;
	a.Attack = 10;
	a.Hp = 20;

	CMonster b;
	b.Attack = 10;
	b.Hp = 20;
	//클래스는 구조체랑 거의 동일(C++에선)
	//가져오는거 유지하면서 함.
	//과거 코드 헝가리안네이밍 컨벤션
	
	//int iYear;
	//float fHeight;

	//접근제어자가 기본적으로
	//구조체는 public이고
	//클래스는 private임.

	//최초의 설게자
	//구조체를 뭐로 생각하고
	//클래스는 뭐기에
	//기본 접근제어가 둘이 다를까 고민해보기.

	//왜 그런가?
	//C언어는 절차지향 프로그래밍
	//C++언어는 객체지향 프로그래밍

	// 절차지향 프로그래밍
	//	코드는 위에서 아래로 흐른다.
	//	객체라는 개념이 없다.
	
	// 객체지향 프로그래밍
	//	우리가 월드를 만들음.
	//	Monster, player, Camera, GameRule 등의
	//	객체를 만들어서 서로 알아서 상호작용하는
	//	코드를 짜는 방식을 객체지향 프로그래밍.
	//	이상향임.

	//클래스를 많이 써서 코드를 분할하자.

	//C언어는 파일 하나에 몰아져있다.
}