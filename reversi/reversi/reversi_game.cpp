#include <iostream>

using namespace std;

void initBoard(char board[][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = '.';
		}
	}
	board[3][3] = 'X';
	board[3][4] = 'O';
	board[4][3] = 'O';
	board[4][4] = 'X';
}


void displayBoard(char board[][8])
{
	for (int y = 7; y >= 0; y--)
	{
		cout << y << " ";
		for (int x = 0; x < 8; x++)
		{
			cout << " " << board[x][y];
		}
		cout << endl;
	}
	cout << "   0 1 2 3 4 5 6 7" << endl;
}

bool checkFlip(char currentBoard[][8], int x, int y, int deltaX, int deltaY, char myPiece, char opponentPiece)
{
	if (currentBoard[x][y] == opponentPiece)
	{
		while ((x >= 0) && (x < 8) && (y >= 0) && (y < 8))
		{
			x += deltaX;
			y += deltaY;

			if ((x >= 0) && (x < 8) && (y >= 0) && (y < 8))
			{
				if (currentBoard[x][y] == '.')
				{
					return false;
				}
				if (currentBoard[x][y] == myPiece)
				{
					return true;
				}
				else
				{

				}
			}
		}
	}
	return false;
}


bool validMove(char currentBoard[][8], int x, int y, char piece)
{

	if (currentBoard[x][y] != '.')
	{
		return false;
	}


	char opponent = 'O';
	if (piece == 'O')
	{
		opponent = 'X';
	}


	if (checkFlip(currentBoard, x - 1, y, -1, 0, piece, opponent))
	{
		return true;
	}

	if (checkFlip(currentBoard, x + 1, y, 1, 0, piece, opponent))
	{
		return true;
	}

	if (checkFlip(currentBoard, x, y - 1, 0, -1, piece, opponent))
	{
		return true;
	}

	if (checkFlip(currentBoard, x, y + 1, 0, 1, piece, opponent))
	{
		return true;
	}

	if (checkFlip(currentBoard, x - 1, y - 1, -1, -1, piece, opponent))
	{
		return true;
	}

	if (checkFlip(currentBoard, x + 1, y - 1, 1, -1, piece, opponent))
	{
		return true;
	}

	if (checkFlip(currentBoard, x - 1, y + 1, -1, 1, piece, opponent))
	{
		return true;
	}

	if (checkFlip(currentBoard, x + 1, y + 1, 1, 1, piece, opponent))
	{
		return true;
	}

	return false;
}


void getMoveList(char currentBoard[][8], int moveX[], int moveY[], int& Moves, char piece)
{
	Moves = 0;

	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (validMove(currentBoard, x, y, piece))
			{
				moveX[Moves] = x;
				moveY[Moves] = y;
				Moves++;
			}
		}
	}
}


bool gameOver(char currentBoard[][8])
{
	int XMoveX[60], XMoveY[60], OMoveX[60], OMoveY[60];
	int XMoves, OMoves;

	getMoveList(currentBoard, XMoveX, XMoveY, XMoves, 'X');
	getMoveList(currentBoard, OMoveX, OMoveY, OMoves, 'O');
	if ((XMoves == 0) && (OMoves == 0))
	{
		return true;
	}
	return false;
}



void flipPieces(char currentBoard[][8], int x, int y, int deltaX, int deltaY, char myPiece, char opponentPiece)
{
	while (currentBoard[x][y] == opponentPiece)
	{
		currentBoard[x][y] = myPiece;
		x += deltaX;
		y += deltaY;
	}
}

int score(char currentBoard[][8], char piece)
{
	int total = 0;
	for (int x = 0; x < 8; x++)
		for (int y = 0; y < 8; y++)
		{
			if (currentBoard[x][y] == piece)
			{
				total++;
			}
		}
	return total;
}

void makeMove(char currentBoard[][8], int x, int y, char piece)
{

	currentBoard[x][y] = piece;


	char opponent = 'O';
	if (piece == 'O')
	{
		opponent = 'X';
	}

	if (checkFlip(currentBoard, x - 1, y, -1, 0, piece, opponent))
	{
		flipPieces(currentBoard, x - 1, y, -1, 0, piece, opponent);
	}

	if (checkFlip(currentBoard, x + 1, y, 1, 0, piece, opponent))
	{
		flipPieces(currentBoard, x + 1, y, 1, 0, piece, opponent);
	}

	if (checkFlip(currentBoard, x, y - 1, 0, -1, piece, opponent))
	{
		flipPieces(currentBoard, x, y - 1, 0, -1, piece, opponent);
	}

	if (checkFlip(currentBoard, x, y + 1, 0, 1, piece, opponent))
	{
		flipPieces(currentBoard, x, y + 1, 0, 1, piece, opponent);
	}

	if (checkFlip(currentBoard, x - 1, y - 1, -1, -1, piece, opponent))
	{
		flipPieces(currentBoard, x - 1, y - 1, -1, -1, piece, opponent);
	}

	if (checkFlip(currentBoard, x + 1, y - 1, 1, -1, piece, opponent))
	{
		flipPieces(currentBoard, x + 1, y - 1, 1, -1, piece, opponent);
	}

	if (checkFlip(currentBoard, x - 1, y + 1, -1, 1, piece, opponent))
	{
		flipPieces(currentBoard, x - 1, y + 1, -1, 1, piece, opponent);
	}

	if (checkFlip(currentBoard, x + 1, y + 1, 1, 1, piece, opponent))
	{
		flipPieces(currentBoard, x + 1, y + 1, 1, 1, piece, opponent);
	}
}

