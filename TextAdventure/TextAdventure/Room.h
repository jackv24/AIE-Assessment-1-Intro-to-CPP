/*
	Author:			Jack Vine
	Date Created:	6/3/2016
	Brief:			Room is the base class from which all other room types derive from.
					It can also be standalone, as a basic room can exist.
*/

#pragma once

#include "String.h"
#include "Character.h"

class Room
{
public:
	enum class Type
	{
		EMPTY,
		BASIC,
		TREASURE,
		MONSTER
	};

	Room();
	virtual ~Room();

	//Sets the description of the room
	void SetDescription(String description);
	//Overloaded to handle c-style strings
	void SetDescription(const char* description);

	String GetDescription();

	Type GetType();
	void SetType(Type type);

	virtual void Update(Character* player);

private:
	String m_description;

	Type m_type;
};

