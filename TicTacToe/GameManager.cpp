#include "GameManager.h"

using namespace std;

GameManager::GameManager()
{
	cout << "Welcome To TicTacToe!" << endl;
	cout << "Enter player 1 name : " << endl;
	player_1.setName();
	player_1.setPlayerMark('X');
	cout << "Enter player 2 name : " << endl;
	player_2.setName();
	player_2.setPlayerMark('O');

	player_turn = player_1;

}

bool GameManager::checkWin()
{
	//cout << "checkWin is called" << endl;
	if (board.getDiagonal() || board.getHorizontal() || board.getVertical())
	{
		isWin = true;
		switchTurn();
		player_win = player_turn;
		board.Display();
		return true;
	}
	else if (board.isFull())
	{
		isDraw = true;
		return true;
	}
	else
	{
		return false;
	}
}

void GameManager::switchTurn()
{
	if (player_turn == player_1)
	{
		player_turn = player_2;
	}
	else if (player_turn == player_2)
	{
		player_turn = player_1;
	}
}

void GameManager::makeMove()
{
	int coorX, coorY;
	cout << player_turn.getName() << "'s turn";
	board.Display();
	cout << "Insert coordinate : ";
	cin >> coorX; cin >> coorY;
	if (board.isLegal(coorX, coorY))
	{
		board.setMark(player_turn.getPlayerMark(), coorX, coorY);
		switchTurn();
	}
	else {
		cout << "Move is illegal" << endl;
	}
}

void GameManager::announce()
{
	if (isWin)
	{
		// cout << "The Winner is: " << player_win.getName() << endl;
		player_1.updateState(player_win);
		player_2.updateState(player_win);
		cout << endl << "Current Score : " << endl;
		cout << player_1.getName() << ": " << player_1.getWins() << endl;
		cout << player_2.getName() << ": " << player_2.getWins() << endl;
	}
	else if (isDraw)
	{
		cout << "It's a Draw!" << endl;
	}
}

void GameManager::newGame()
{
	board.Reset();
	if (!board.isEmpty())
	{
		cout << "Error";
		exit;
	}
	else
	{
		isWin = false;
		isDraw = false;
	}
}

int main()
{
	GameManager game1;
	char retry;
	bool gameState = true;
	while (gameState)
	{
		game1.makeMove();
		if (game1.checkWin())
		{
			game1.announce();
			cout << endl << "Do you want to play again? (Y/N)";
			cin >> retry;
			if (retry == 'Y')
			{
				game1.newGame();
			}
			else
			{
				cout << endl << "Thank you for playing :D ";
				break;
			}
		}
	}

	return 0;
}
