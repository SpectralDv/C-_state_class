#pragma once
#ifndef JUMPSTATE_H
#define JUMPSTATE_H

#include "State.h"
#include "IPlayer.h"


using namespace SpaceIPlayer;
using namespace SpaceState;
namespace SpaceJumpState
{
	class JumpState : public State
	{
	private:
		IPlayer* _player;
	public:
		JumpState(IPlayer* player)
		{
			this->_player = player;
		}
		void Enter() override
		{
			printf("JumpState Enter %s\n", _player->GetName().c_str());
		}
		void Exit() override
		{
			printf("JumpState Exit %s\n", _player->GetName().c_str());
		}
		void Update() override
		{
			printf("JumpState Update %s\n", _player->GetName().c_str());
		}
	};
}
#endif