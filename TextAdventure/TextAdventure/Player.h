/*
	Author:			Jack Vine
	Date Created:	8/3/2016
	Brief:			The player, a subclass of character. Includes special player data such as inventory.
*/

#pragma once

#include "Character.h"

class Player : public Character
{
public:
	Player();
	virtual ~Player();

	virtual void Action();
};

