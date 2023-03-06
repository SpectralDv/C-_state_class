#pragma once
#ifndef STATE_H
#define STATE_H

#include "iostream"


namespace SpaceState
{
	class State
	{
	public:
		virtual ~State() {}
		virtual void Enter() {}
		virtual void Exit() {}
		virtual void Update() {}
	};
}
#endif