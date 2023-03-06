#pragma once
#ifndef RUNSTATE_H
#define RUNSTATE_H

#include "State.h"
#include "IPlayer.h"


using namespace SpaceIPlayer;
using namespace SpaceState;
namespace SpaceRunState
{
	class RunState : public State
	{
	private:
		IPlayer* _player;
	public:
		RunState(IPlayer* player)
		{
			this->_player = player;
		}
		void Enter() override
		{
			printf("RunState Enter %s\n", _player->GetName().c_str());
		}
		void Exit() override
		{
			printf("RunState Exit %s\n", _player->GetName().c_str());
		}
		void Update() override
		{
			printf("RunState Update %s\n", _player->GetName().c_str());
		}
	};
}
#endif