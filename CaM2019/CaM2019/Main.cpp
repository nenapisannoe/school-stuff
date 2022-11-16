#include <iostream>
#include "State.h"
#include "search_algs.h"

using namespace std;

int main()
{
	setlocale(0, "Russian");
	State initialState = State(3, 3, Boat::Left, 0, 0);
	initialState.PrintState();
	BFS(initialState);
}