#pragma once

#include "Demon.h"

class StrongerDemon : public Demon
{
public:
	StrongerDemon();
	virtual ~StrongerDemon();

	virtual void Action(std::vector<Character*> characters);
};

