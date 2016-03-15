#include "MonsterRoom.h"
#include "Demon.h"

MonsterRoom::MonsterRoom()
{
	SetType(Type::MONSTER);
	SetDescription("You encounter a monster room!");
}

MonsterRoom::~MonsterRoom()
{

}

void MonsterRoom::Update(Character* player)
{
	//If the character vector hasn't been populated
	if (m_characters.empty())
	{
		m_characters.push_back(player);
		m_characters.push_back(new Demon());
	}

	//List enemies
	if (m_characters.size() <= 1)
		std::cout << "\nThere are no enemies here.\n";
	else
	{
		std::cout << "\nEnemies:\n";
		for (int i = 1; i < m_characters.size(); i++)
		{
			std::cout << " - " << m_characters[i]->GetName() << "\n";
		}

		//Let each character take a turn
		for (Character* character : m_characters)
		{
			character->Action(m_characters);
		}

		std::cout << "\nYour HP: " << m_characters[0]->GetHealth() << std::endl;
	}
}
