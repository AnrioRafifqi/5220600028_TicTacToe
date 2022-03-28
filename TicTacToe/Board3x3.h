#pragma once
#include "Board.h"
#include <iostream>

class Board3x3 : public Board
{
	char board[3][3];
	char winMark;
public:
	Board3x3();

	void Reset();
	void Display();

	void setMark(char, int, int);
	char getMark(int, int);
	char getWinMark();

	bool getHorizontal();
	bool getVertical();
	bool getDiagonal();

	bool isFull();
	bool isEmpty();
	bool isLegal(int, int);
};

