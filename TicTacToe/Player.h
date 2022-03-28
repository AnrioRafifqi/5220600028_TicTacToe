#pragma once
#include <string>
#include <iostream>

class Player
{
	char mark;
	std::string name;
	int win;
public:
	Player();
	void setPlayerMark(char);
	char getPlayerMark();
	void updateState(Player);
	void setName();
	std::string getName();
	bool operator==(Player);

	void setWins(int);
	int getWins();
};

