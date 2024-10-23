﻿#pragma once
class Scene;
class SceneManager
{
	DECLARE_SINGLE(SceneManager);

public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();

public:
	void ChangeScene(SceneType sceneType);
	Scene* GetCurrentScene() { return _scene; }
private:
	Scene* CreateScene(SceneType sceneType);

private:
	SceneType _sceneType = SceneType::None;
	SceneType _nextSceneType = SceneType::None;

private:
	Scene* _scene = nullptr;
};