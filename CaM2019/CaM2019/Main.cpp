#include <iostream>
#include "State.h"
#include "search_algs.h"

using namespace std;

int main()
{
	setlocale(0, "Russian");
	State initialState = State(0, 3, 3, Boat::Left, 0, 0);
	initialState.PrintState();
	cout << endl;
	BFS(initialState).PrintState();
}