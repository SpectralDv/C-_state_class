#pragma once
#ifndef IDLESTATE_H
#define IDLESTATE_H

#include "State.h"
#include "IPlayer.h"


using namespace SpaceIPlayer;
using namespace SpaceState;
namespace SpaceIdleState
{
	class IdleState : public State
	{
	private:
		IPlayer *_player;
	public:
		IdleState(IPlayer *player)
		{
			this->_player = player;
		}
		~IdleState() {}
		void Enter() override
		{
			printf("IdleState Enter %s\n", _player->GetName().c_str());
		}
		void Exit() override
		{
			printf("IdleState Exit %s\n", _player->GetName().c_str());
		}
		void Update() override
		{
			printf("IdleState Update %s\n", _player->GetName().c_str());
		}
	};
}
#endif