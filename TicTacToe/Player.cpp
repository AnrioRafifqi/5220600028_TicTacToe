#include "Player.h"

using namespace std;

void Player::setPlayerMark(char mark)
{
	this->mark = mark;
}

Player::Player()
{
	win = 0;
}

char Player::getPlayerMark()
{
	return mark;
}

void Player::updateState(Player win)
{
	if (win.getName() == name)
	{
		cout << "Congratulation " << name << ", you're the winner!!!" << endl;
		setWins(1);
	}
	else if (win.getName() != name)
		cout << "You Lose " << name << ", better luck next time!" << endl;
}

void Player::setName()
{
	cin >> this->name;
}

std::string Player::getName()
{
	return this->name;
}

bool Player::operator==(Player x)
{
	if (this->name == x.name)
	{
		return true;
	}
	else
		return false;
}

void Player::setWins(int score)
{
	win = win + score;
}

int Player::getWins()
{
	return win;
}
