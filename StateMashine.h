#pragma once
#ifndef STATEMASHINE_H
#define STATEMASHINE_H

#include "State.h"


using namespace SpaceState;
namespace SpaceStateMashine
{
	class StateMashine
	{
	public:
		State *CurrentState;
	public:
		void Initialize(State *startState)
		{
			CurrentState = startState;
			CurrentState->Enter();
		}
		void ChangeState(State *newState)
		{
			CurrentState->Exit();
			CurrentState = newState;
			CurrentState->Enter();
		}
	};
}
#endif