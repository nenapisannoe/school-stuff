#ifndef reversi_game
#define reversi_game

void initBoard(char[][8]);
void displayBoard(char[][8]);
bool gameOver(char[][8]);
bool validMove(char[][8], int , int , char );
bool checkFlip(char[][8], int , int , int, int, char, char);
void flipPieces(char[][8], int , int , int, int, char, char);
void getMoveList(char[][8], int[], int[], int&, char);
void makeMove(char[][8], int, int, char);
int score(char[][8], char);


#endif reversi_game
