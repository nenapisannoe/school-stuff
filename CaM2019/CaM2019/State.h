#ifndef MaC_State
#define MaC_State

#include<iostream>
#include <list>    

using namespace std;

enum class Boat { Left, Right };

class State {
private:
	int Layer;
	int CannibalsLeft;
	int MissionariesLeft;
	int CannibalsRight;
	int MissionariesRight;
	Boat boat;

	State* ParentState;
public:
	State(int layer, int cannibalsLeft, int missionariesLeft, Boat _boat, int cannibalsRight, int missionariesRight)
	{
		this->Layer = layer;
		this->CannibalsLeft = cannibalsLeft;
		this->MissionariesLeft = missionariesLeft;
		this->boat = _boat;
		this->CannibalsRight = cannibalsRight;
		this->MissionariesRight = missionariesRight;
	}


	bool isValid()
	{
		if ((MissionariesLeft >= 0 && MissionariesRight >= 0 && CannibalsLeft >= 0 && CannibalsRight >= 0) &&
			(MissionariesLeft == 0 || MissionariesLeft >= CannibalsLeft) && (MissionariesRight == 0 || MissionariesRight >= CannibalsRight))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	std::list<State> getNextStates()
	{
		std::list<State> newStates = std::list<State>();
		if (this->boat == Boat::Left)//лодка сейчас у левого берега
		{
			State state = State(this->Layer +1, this->CannibalsLeft, this->MissionariesLeft - 2, Boat::Right, this->CannibalsRight, this->MissionariesRight + 2); //два миссионера переплывают слева направо
			if (state.isValid())
			{
				state.setParentState(this);
				newStates.push_back(state);
				cout << "два миссионера переплывают слева направо" << endl;
				this->PrintState();
				cout << " => ";
				state.PrintState();
				cout << endl;
			}
			state = State(this->Layer + 1, this->CannibalsLeft - 2, this->MissionariesLeft, Boat::Right, this->CannibalsRight + 2, this->MissionariesRight); //два канибалла переплывают слева направо
			if (state.isValid())
			{
				state.setParentState(this);
				newStates.push_back(state);
				cout << "два канибалла переплывают слева направо" << endl;
				this->PrintState();
				cout << " => ";
				state.PrintState();
				cout << endl;
			}
			state = State(this->Layer + 1, this->CannibalsLeft - 1, this->MissionariesLeft - 1, Boat::Right, this->CannibalsRight + 1, this->MissionariesRight + 1); //миссионер и канибалл переплывают слева направо
			if (state.isValid())
			{
				state.setParentState(this);
				newStates.push_back(state);
				cout << "миссионер и канибалл переплывают слева направо" << endl;
				this->PrintState();
				cout << " => ";
				state.PrintState();
				cout << endl;
			}
			state = State(this->Layer + 1, this->CannibalsLeft - 1, this->MissionariesLeft, Boat::Right, this->CannibalsRight + 1, this->MissionariesRight); // один канибалл переплывает слева направо
			if (state.isValid())
			{
				state.setParentState(this);
				newStates.push_back(state);
				cout << "один канибалл переплывает слева направо" << endl;
				this->PrintState();
				cout << " => ";
				state.PrintState();
				cout << endl;
			}
			state = State(this->Layer + 1, this->CannibalsLeft, this->MissionariesLeft - 1, Boat::Right, this->CannibalsRight, this->MissionariesRight + 1); // один миссионер переплывает слева направо
			if (state.isValid())
			{
				state.setParentState(this);
				newStates.push_back(state);
				cout << "один миссионер переплывает слева направо" << endl;
				this->PrintState();
				cout << " => ";
				state.PrintState();
				cout << endl;
			}
		}
		else//лодка сейчас у правого берега
		{
			State state = State(this->Layer + 1, this->CannibalsLeft, this->MissionariesLeft +2, Boat::Left, this->CannibalsRight, this->MissionariesRight - 2); //два миссионера переплывают справа налево
			if (state.isValid())
			{
				state.setParentState(this);
				newStates.push_back(state);
				cout << "два миссионера переплывают справа налево" << endl;
				this->PrintState();
				cout << " => ";
				state.PrintState();
				cout << endl;
			}
			state = State(this->Layer + 1, this->CannibalsLeft + 2, this->MissionariesLeft, Boat::Left, this->CannibalsRight - 2, this->MissionariesRight); //два канибалла переплывают справа налево
			if (state.isValid())
			{
				state.setParentState(this);
				newStates.push_back(state);
				cout << "два канибалла переплывают справа налево" << endl;
				this->PrintState();
				cout << " => ";
				state.PrintState();
				cout << endl;
			}
			state = State(this->Layer + 1, this->CannibalsLeft + 1, this->MissionariesLeft + 1, Boat::Left, this->CannibalsRight - 1, this->MissionariesRight - 1); //миссионер и канибалл переплывают справа налево
			if (state.isValid())
			{
				state.setParentState(this);
				newStates.push_back(state);
				cout << "миссионер и канибалл переплывают справа налево" << endl;
				this->PrintState();
				cout << " => ";
				state.PrintState();
				cout << endl;
			}
			state = State(this->Layer + 1, this->CannibalsLeft + 1, this->MissionariesLeft, Boat::Left, this->CannibalsRight - 1, this->MissionariesRight); // один канибалл переплывает справа налево
			if (state.isValid())
			{
				state.setParentState(this);
				newStates.push_back(state);
				cout << "один канибалл переплывает справа налево" << endl;
				this->PrintState();
				cout << " => ";
				state.PrintState();
				cout << endl;
			}
			state = State(this->Layer + 1, this->CannibalsLeft, this->MissionariesLeft + 1, Boat::Left, this->CannibalsRight, this->MissionariesRight - 1); // один миссионер переплывает справа налево
			if (state.isValid())
			{
				state.setParentState(this);
				newStates.push_back(state);
				cout << "один миссионер переплывает справа налево" << endl;
				this->PrintState();
				cout << " => ";
				state.PrintState();
				cout << endl;
			}
		}
		return newStates;
	}

	void setParentState(State* parentState)
	{
		this->ParentState = parentState;
	}

	int getCannibalLeft()
	{
		return this->CannibalsLeft;
	}

	void setCannibalLeft(int cannibalsLeft)
	{
		this->CannibalsLeft = cannibalsLeft;
	}

	int getMissionariesLeft()
	{
		return this->MissionariesLeft;
	}

	void setMissionariesLeft(int missionariesLeft)
	{
		this->MissionariesLeft = missionariesLeft;
	}

	int getCannibalsRight()
	{
		return this->CannibalsRight;
	}

	void setCannibalRight(int cannibalsRight)
	{
		this->CannibalsRight = cannibalsRight;
	}

	int getMissionaryRight()
	{
		return this->MissionariesRight;
	}

	void setMissionaryRight(int missionariesRight)
	{
		this->MissionariesRight = missionariesRight;
	}

	void goToLeft()
	{
		boat = Boat::Left;
	}

	void goToRight()
	{
		boat = Boat::Right;
	}

	bool isOnLeft()
	{
		return boat == Boat::Left;
	}

	bool isOnRigth()
	{
		return boat == Boat::Right;
	}

	Boat getBoat()
	{
		return boat;
	}

	State* getParentState()
	{
		return this->ParentState;
	}

	void PrintState()
	{
		cout << "Уровень: ";
		cout << this->Layer + 1,
		cout << ", (";
		cout << this->CannibalsLeft;
		cout << ", ";
		cout << this->MissionariesLeft;
		if (boat == Boat::Left)
		{
			cout << ", L, ";
		}
		else
		{
			cout << ", R, ";
		}
		cout << this->CannibalsRight;
		cout << ", ";
		cout << this->MissionariesRight;
		cout << ")";
	}


	bool equals(State s) {
		return (s.CannibalsLeft == CannibalsLeft && s.MissionariesLeft == MissionariesLeft
			&& s.boat == boat && s.CannibalsRight == CannibalsRight
			&& s.MissionariesRight == MissionariesRight);
	}

	friend bool operator ==(State lS, State rS)
	{
		return lS.equals(rS);
	}
};
#endif //MaC_State#pragma once
