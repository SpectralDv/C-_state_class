#pragma once
#ifndef IPLAYER_H
#define IPLAYER_H

#include <iostream>


namespace SpaceIPlayer
{
	class IPlayer
	{
	protected:
		std::string _name;
	public:
		virtual ~IPlayer() {}
		virtual std::string GetName() = 0;
	};
}
#endif