#include <iostream>
#include <cstdlib>
#include <ctime>
#include "reversi_game.h"
#include "minmax.h"
using namespace std;


int main()
{
	srand(time(NULL));
	char board[8][8];
	char curPlayer = 'X';

	initBoard(board);

	while (!gameOver(board))
	{
		displayBoard(board);
		cout << "It is player " << curPlayer << "'s turn." << endl;
		cout << "Enter move." << endl;
		int x, y;
		if (curPlayer == 'O')
			minimaxDecision(board, 'O', x, y);
		else
			cin >> x >> y;
		if (validMove(board, x, y, curPlayer) || (x == -1))
		{
			if (x != -1)
			{
				makeMove(board, x, y, curPlayer);
			}
			if (curPlayer == 'X')
			{
				curPlayer = 'O';
			}
			else
			{
				curPlayer = 'X';
			}
		}
		else
		{
			cout << "Invalid move.  Enter move again. " << endl;
		}
	}
	cout << endl << "The game is over!" << endl;
	displayBoard(board);
	cout << "X's score: " << score(board, 'X') << endl;
	cout << "O's score: " << score(board, 'O') << endl;
	system("pause");
}