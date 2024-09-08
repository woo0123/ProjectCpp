#pragma once

class MainGame
{
public:
	void Init();
	void SetCard();
	void ShuffleCard();
	void GetCard();
	void CheckMyCard();
	void MyVicDiscrimination();
	void CheckComCard();
	void ComVicDiscrimination();
	void Victory();
	void Update();
	void Release();

	bool _isGameExit = false;

public:
	int _card[40] = {};
	int _myCard[2] = {};
	int _comCard[2] = {};
	int _myScore = _myCard[0] + _myCard[1];
	int _comScore = _comCard[0] + _comCard[1];
	int _compareWin[2] = {};
};

