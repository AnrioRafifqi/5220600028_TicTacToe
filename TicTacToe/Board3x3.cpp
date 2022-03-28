#include "Board3x3.h"

using namespace std;
Board3x3::Board3x3()
{
	this->Reset();
}
void Board3x3::Reset()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] =  ' ';
		}
	}
}

void Board3x3::Display()
{
	cout << endl << "      (0)  (1)  (2)  ";
	cout << endl << "(0) || " << getMark(0, 0) << " |" << "| " << getMark(0, 1) << " |" << "| " << getMark(0, 2) << " ||" ;
	cout << endl << "(1) || " << getMark(1, 0) << " |" << "| " << getMark(1, 1) << " |" << "| " << getMark(1, 2) << " ||" ;
	cout << endl << "(2) || " << getMark(2, 0) << " |" << "| " << getMark(2, 1) << " |" << "| " << getMark(2, 2) << " ||" ;
	cout << endl;
}

void Board3x3::setMark(char mark, int x, int y)
{
	board[x][y] = mark;
}

char Board3x3::getMark(int x, int y)
{
	char tempMark;
	tempMark = board[x][y];

	return tempMark;
}

char Board3x3::getWinMark()
{
	return winMark;
}

bool Board3x3::getHorizontal()
{
	bool retVal = false;
	for (int i = 0; i < 3; i++)
	{
		if (getMark(i, 0) == getMark(i, 1) && getMark(i, 0) == getMark(i, 2))
		{
			winMark = getMark(i, 0);
			if (winMark != ' ')
			{
				retVal = true;
			}
		}
	}

	return retVal;
}

bool Board3x3::getVertical()
{
	bool retVal = false;
	for (int i = 0; i < 3; i++)
	{
		if (getMark(1, i) == getMark(2, i) && getMark(0, i) == getMark(2, i))
		{
			winMark = getMark(1, i);
			if (winMark != ' ')
			{
				retVal = true;
			}
		}
	}

	return retVal;
}

bool Board3x3::getDiagonal()
{
	bool retVal = false;
	if (getMark(0, 0) == getMark(1, 1) && getMark(0, 0) == getMark(2, 2))
	{
		winMark = getMark(0, 0);
		if (winMark != ' ')
		{
			retVal = true;
		}
	}

	if (getMark(0, 2) == getMark(1, 1) && getMark(0, 2) == getMark(2, 0))
	{
		winMark = getMark(0, 2);
		if (winMark != ' ')
		{
			retVal = true;
		}
	}
	
	return retVal;

}

bool Board3x3::isFull()
{
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
			{
				count++;
			}
		}
	}

	if (count >= 1)
		return false;
	else
		return true;
}

bool Board3x3::isEmpty()
{
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != ' ')
			{
				count++;
			}
		}
	}

	if (count >= 1)
		return false;
	else
		return true;
}

bool Board3x3::isLegal(int x, int y)
{
	if (board[x][y] == ' ')
		return true;
	else
		return false;
}

//int main()
//{
//	Board3x3 bord;
//	bord.setMark('O', 0, 1);
//	bord.setMark('O', 1, 1);
//	bord.setMark('O', 2, 1);
//	bord.setMark('X', 0, 0);
//
//	bord.Display();
////	if (bord.getMark(0, 1) == bord.getMark(0, 2) == bord.getMark(0,0))
////		cout << "!";
////	if (bord.getMark(0, 1) == bord.getMark(0, 2) && bord.getMark(0, 0) == bord.getMark(0, 2))
////		cout << "1";
//	//if ('X' == 'O' && 'O' == 'O')
//	
//	cout << bord.getVertical();
//	//cout << bord.getHorizontal();
//	//cout << bord.getDiagonal();
//
//	
//}
