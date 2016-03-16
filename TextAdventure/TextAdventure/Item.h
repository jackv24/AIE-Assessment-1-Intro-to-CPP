/*
	Author:			Jack Vine
	Date Created:	8/3/2016
	Brief:			The item base class. A basic item can be used just like any other item, but will have no effects.
*/

#pragma once

#include "String.h"

class Item
{
public:
	enum class Type
	{
		BASIC,
		WEAPON,
		CONSUMABLE
	};

	Item();
	virtual ~Item();

	Type GetType();

	virtual void Use();

	String GetName();

protected:
	String m_name;
	Type m_type;
};

