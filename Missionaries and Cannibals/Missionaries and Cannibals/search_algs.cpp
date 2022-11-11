#include "search_algs.h"
#include<vector>

bool isFinal(int cannibalsLeft, int missionariesLeft)
{
	return cannibalsLeft == 0 && missionariesLeft == 0;
}

State* BFS(State* startingState)
{
	std::deque<State*> q;
	std::vector<State*> explored;
	q.push_front(startingState);
	while (!q.empty())
	{
		State* state = q.front();
		explored.push_back(state);
		std::list<State*> nextStates = state.getNextStates();
		for (State* s : nextStates)
		{
			State fds = std::find(explored.begin(), explored.end(), s);
			State fgkd = *(std::find(q.begin(), q.end(), s));
			if (fds.equals(*explored.end()) || fgkd.equals(q.end()))
			{
				if (isFinal(s->getCannibalLeft(),s->getMissionariesLeft()))
				{
					return s;
				}
				q.push_front(s);
			}
			s.PrintState();
		}
	}
}