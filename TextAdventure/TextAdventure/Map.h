/*
	Author:			Jack Vine
	Date Created:	7/3/2016
	Brief:			Contains all map traversal and management related data and functions
*/

#pragma once

#include "Room.h"
#include "TreasureRoom.h"
#include "MonsterRoom.h"
#include "Player.h"

class Map
{
public:
	Map();
	~Map();

	Room& GetRoom(int row, int column);
	Room& GetCurrentRoom();

	//returns true if the room exists, and is available to move to
	bool CheckRooms(int row, int column);
	//Returns true if the move was successful
	bool Move(String direction);

private:
	int m_rows = 0, m_columns = 0;
	int m_row = 0, m_column = 0;

	//Array of pointers to rooms, as there are different types of rooms with the same base class
	Room** m_rooms;

	Player* player;

	//Takes a const array of ints, and uses their values to generate the m_rooms array
	void GenerateMapFromInts(const int* intArray);
};

