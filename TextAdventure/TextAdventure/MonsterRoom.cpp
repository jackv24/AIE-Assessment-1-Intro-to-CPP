#include "MonsterRoom.h"

MonsterRoom::MonsterRoom()
{
	SetType(Type::MONSTER);
	SetDescription("You encounter a monster!");
}

MonsterRoom::~MonsterRoom()
{

}

void MonsterRoom::Update(Character* player)
{
	if(m_characters.empty())
		m_characters.push_back(player);

	for (Character* character : m_characters)
	{
		character->Action();
	}
}
