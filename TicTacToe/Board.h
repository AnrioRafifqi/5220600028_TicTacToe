#pragma once
class Board
{
public:
	virtual void Reset();
	virtual void Display();

	virtual void setMark();
	virtual char getMark();

	virtual bool getHorizontal();
	virtual bool getVertical();
	virtual bool getDiagonal();

	virtual bool isFull();
	virtual bool isEmpty();
	virtual bool isLegal();
};

