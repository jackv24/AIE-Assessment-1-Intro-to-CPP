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
	Item();
	virtual ~Item();

	virtual void Use();

	String GetName();

protected:
	String m_name;
};

