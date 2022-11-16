#include "search_algs.h"
#include<vector>

bool isFinal(int cannibalsLeft, int missionariesLeft)
{
	return cannibalsLeft == 0 && missionariesLeft == 0;
}


State BFS(State startingState)
{
	std::deque<State> q;
	std::deque<State> explored;
	q.push_front(startingState);
	while (!q.empty())
	{
		State state = q.front();
		explored.push_back(state);
		std::list<State> nextStates = state.getNextStates();
		for (State s : nextStates)
		{
			deque<State>::iterator itr = find(explored.begin(), explored.end(), State(s.getCannibalLeft(), s.getMissionariesLeft(), s.getBoat(), s.getCannibalsRight(), s.getMissionaryRight()));
			if (itr == explored.end())
			{
				if (isFinal(s.getCannibalLeft(), s.getMissionariesLeft()))
				{
					return s;
				}
				q.push_front(s);

			}
			//cout << (*s).getCannibalLeft() << endl;
		}
	}
	return startingState;
}