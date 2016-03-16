/*
	Author:			Jack Vine
	Date Created:	8/3/2016
	Brief:			A subclass of room. Contains monsters which the player must fight in order to pass
*/

#pragma once

#include <vector>
#include "Room.h"

class MonsterRoom : public Room
{
public:
	MonsterRoom();
	virtual ~MonsterRoom();

	virtual void Update(Character* player);

	//Are all the monsters in the room dead?
	bool IsClear();

private:
	std::vector<Character*> m_characters;

	void DisplayInfo();
};

