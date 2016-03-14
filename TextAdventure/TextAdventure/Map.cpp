#include "Map.h"

Map::Map()
{
	m_rows = 5;
	m_columns = 5;

	//Hacky implementation of loading the level, but it works -- will be replaced with file IO
	//Define map layout with ints (0 = empty, 1 = basic, 2 = start, 3 = Monster, 4 = treasure)
	int level[25] = {
		3, 1, 1, 0, 3,
		1, 2, 1, 3, 1,
		4, 1, 4, 1, 0,
		1, 3, 0, 1, 3,
		0, 1, 1, 1, 4
	};

	GenerateMapFromInts(level);
}

Map::~Map()
{
	//Delete each room individually
	int arraySize = m_rows * m_columns;

	for (int i = 0; i < arraySize; i++)
	{
		delete m_rooms[i];
	}

	//Delete the room array when no longer needed
	delete[] m_rooms;
}


void Map::GenerateMapFromInts(const int* intArray)
{
	//new array of room baseclass pointers
	m_rooms = new Room*[m_rows * m_columns];

	//Iterate through the array, setting room types
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			//use 2D iterative values in the 1D array
			int type = intArray[i * m_rows + j];
			int index = i * m_rows + j;

			switch (type)
			{
			//case 0 not needed, as default cases are an empty room
			case 1:
				m_rooms[index] = new Room();
				m_rooms[index]->SetType(Room::Type::BASIC);
				break;
			case 2:
				m_row = i;
				m_column = j;

				m_rooms[index] = new Room();
				m_rooms[index]->SetType(Room::Type::BASIC);
				break;
			case 3:
				m_rooms[index] = new MonsterRoom();
				break;
			case 4:
				m_rooms[index] = new TreasureRoom();
				break;
			default:
				m_rooms[index] = new Room();
				break;
			}
		}
	}
}


Room& Map::GetRoom(int row, int column)
{
	return *m_rooms[row * m_rows + column];
}

Room& Map::GetCurrentRoom()
{
	//return the room from the 1D array, using 2D values
	return *m_rooms[m_row * m_rows + m_column];
}

bool Map::CheckRooms(int row, int column)
{
	//If the room is out of array bounds, it is not available
	if (row < 0 || row >= m_rows)
		return false;
	if (column < 0 || column >= m_columns)
		return false;

	//If the room is of empty type, it is not available
	if (m_rooms[row * m_rows + column]->GetType() == Room::Type::EMPTY)
		return false;

	return true;
}

bool Map::Move(String direction)
{
	//Check each direction...
	if (direction == "north" || direction == "up")
	{
		//Make sure the place to move to is available
		if (CheckRooms(m_row - 1, m_column))
		{
			//Move to it
			m_row -= 1;

			//Return true to handle successful move elsewhere
			return true;
		}
	}
	// etc..
	else if (direction == "south" || direction == "down")
	{
		if (CheckRooms(m_row + 1, m_column))
		{
			m_row += 1;

			return true;
		}
	}
	else if (direction == "west" || direction == "left")
	{
		if (CheckRooms(m_row, m_column - 1))
		{
			m_column -= 1;
		
			return true;
		}
	}
	else if (direction == "east" || direction == "right")
	{
		if (CheckRooms(m_row, m_column + 1))
		{
			m_column += 1;

			return true;
		}
	}
	else //If the direction entered does not exist
		std::cout << "That direction is invalid. ";

	//If the entered direction is unavailable
	std::cout << "You can't go that way." << std::endl;

	return false;
}