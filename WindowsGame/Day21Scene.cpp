#include "pch.h"
#include "Day21Scene.h"

void Day21Scene::Init()
{
}
void Day21Scene::Render(HDC hdc)
{
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day21Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
}
void Day21Scene::Update()
{
}
void Day21Scene::Release()
{
}