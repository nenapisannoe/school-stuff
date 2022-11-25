#include<cstring>
#include "reversi_game.h"

void copyBoard(char src[][8], char dest[][8])
{
	memcpy(dest, src, 8 * 8 * sizeof(char));
}


int heuristic(char currentBoard[][8], char whoseTurn)
{
	char opponent = 'O';
	if (whoseTurn == 'O')
	{
		opponent = 'X';
	}
	int playerScore = score(currentBoard, whoseTurn);
	int opponentScore = score(currentBoard, opponent);
	return (playerScore - opponentScore);
}

int minimaxValue(char currentBoard[][8], char originalTurn, char currentTurn, int searchPly)
{
	if ((searchPly == 5) || gameOver(currentBoard))
	{
		return heuristic(currentBoard, originalTurn);
	}
	int moveX[60], moveY[60];
	int numMoves;
	char opponent = 'X';
	if (currentTurn == 'X')
	{
		opponent = 'O';
	}
	getMoveList(currentBoard, moveX, moveY, numMoves, currentTurn);
	if (numMoves == 0)
	{
		return minimaxValue(currentBoard, originalTurn, opponent, searchPly + 1);
	}
	else
	{
		int bestMoveVal = -99999;
		if (originalTurn != currentTurn)
		{
			bestMoveVal = 99999;
		}
		for (int i = 0; i < numMoves; i++)
		{
			char tempBoard[8][8];
			copyBoard(currentBoard, tempBoard);
			makeMove(tempBoard, moveX[i], moveY[i], currentTurn);
			int val = minimaxValue(tempBoard, originalTurn, opponent, searchPly + 1);
			if (originalTurn == currentTurn)
			{
				if (val > bestMoveVal)
				{
					bestMoveVal = val;
				}
			}
			else
			{
				if (val < bestMoveVal)
				{
					bestMoveVal = val;
				}
			}
		}
		return bestMoveVal;
	}
	return -1;
}

void minimaxDecision(char currentBoard[][8], char whoseTurn, int& x, int& y)
{
	int moveX[60], moveY[60];
	int Moves;
	char opponent = 'X';
	if (whoseTurn == 'X')
	{
		opponent = 'O';
	}
	getMoveList(currentBoard, moveX, moveY, Moves, whoseTurn);
	if (Moves == 0)
	{
		x = -1;
		y = -1;
	}
	else
	{
		int bestMoveVal = -99999;
		int bestX = moveX[0], bestY = moveY[0];
		for (int i = 0; i < Moves; i++)
		{
			char tempBoard[8][8];
			copyBoard(currentBoard, tempBoard);
			makeMove(tempBoard, moveX[i], moveY[i], whoseTurn);
			int val = minimaxValue(tempBoard, whoseTurn, opponent, 1);
			if (val > bestMoveVal)
			{
				bestMoveVal = val;
				bestX = moveX[i];
				bestY = moveY[i];
			}
		}
		x = bestX;
		y = bestY;
	}
}
