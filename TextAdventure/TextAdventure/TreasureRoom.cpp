#include "TreasureRoom.h"

TreasureRoom::TreasureRoom()
{
	SetType(Type::TREASURE);
	SetDescription("You encounter a treasure room!");
}

TreasureRoom::~TreasureRoom()
{
}

void TreasureRoom::Update(Character* player)
{
	std::cout << "\nThere's no treasure here..." << std::endl;
}
