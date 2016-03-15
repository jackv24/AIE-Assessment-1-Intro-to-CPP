/*
	Author:			Jack Vine
	Date Created:	15/3/2016
	Brief:			An enemy demon, a subclass of character.
*/

#pragma once

#include "Character.h"

class Demon : public Character
{
public:
	Demon();
	virtual ~Demon();

	virtual void Action(std::vector<Character*> characters);
};

