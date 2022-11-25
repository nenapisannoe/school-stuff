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
	int layer = 0;
	while (!q.empty())
	{
		layer++;
		State state = q.back();
		q.pop_back();
		explored.push_back(state);
		std::list<State> nextStates = state.getNextStates();
		for (State s : nextStates)
		{
			bool used = false;
			bool added = false;
			for (State exp : explored)
			{
				if (s.equals(exp))
				{
					used = true;
				}
			}
			for (State exp : q)
			{
				if (s.equals(exp))
				{
					added = true;
				}
			}
			if (!used && !added)
			{
				if (isFinal(s.getCannibalLeft(), s.getMissionariesLeft()))
				{
					return s;
				}
				q.push_front(s);
				
			}
		}
	}
	return startingState;
}

std::deque<State> explored;

State DFS(State state)
{
	if (isFinal(state.getCannibalLeft(), state.getMissionariesLeft()))
	{
		return state;
	}
	else
	{
		explored.push_back(state);
		std::list<State> nextStates = state.getNextStates();
		for (State s : nextStates)
		{
			bool used = false;
			for (State exp : explored)
			{
				if (s.equals(exp))
				{
					used = true;
				}
			}
			if (!used)
			{
				State result = DFS(s);
				return result;
			}
		}
	}
	State s =  State(0,0,0,Boat::Left,0,0);
	State* p = &s;
	p = NULL;
	return *p;
}