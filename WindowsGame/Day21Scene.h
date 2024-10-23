#pragma once
#include "Scene.h"
class Day21Scene : public Scene
{
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	Day21Scene() {}
	virtual ~Day21Scene() {}

};

