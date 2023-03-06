#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "IPlayer.h"
#include "StateMashine.h"
#include "IdleState.h"
#include "RunState.h"
#include "JumpState.h"


using namespace SpaceJumpState;
using namespace SpaceIdleState;
using namespace SpaceRunState;
using namespace SpaceStateMashine;
using namespace SpaceIPlayer;
namespace SpacePlayer
{
	class Player : public IPlayer
	{
	private:
		StateMashine* _stateMashine;
		RunState* _runState;
		IdleState* _idleState;
		JumpState* _jumpState;
	public:
		std::string _nameCommand;
	public:
		Player(std::string name)
		{
			this->_name = name;
			this->_nameCommand = "IdleState";
		}
		~Player() {}
		std::string GetName() override
		{
			return this->_name;
		}
		void Start()
		{
			this->_stateMashine = new StateMashine();
			this->_stateMashine->Initialize(new IdleState(this));
		}
		void Update()
		{
			this->_stateMashine->CurrentState->Update();

			if (this->_nameCommand == "IdleState")
			{
				this->_stateMashine->ChangeState(new IdleState(this));
			}
			if (this->_nameCommand == "RunState")
			{
				this->_stateMashine->ChangeState(new RunState(this));
			}
			if (this->_nameCommand == "JumpState")
			{
				this->_stateMashine->ChangeState(new JumpState(this));
			}
		}
	};
}
#endif