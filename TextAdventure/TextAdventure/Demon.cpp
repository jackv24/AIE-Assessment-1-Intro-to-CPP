#include "Demon.h"
#include <time.h>

Demon::Demon()
{
	m_name = "Demon";
	m_health = 50;
}

Demon::~Demon()
{
}

void Demon::Action(std::vector<Character*> characters)
{
	srand(time(NULL));

	//The enemy to attack (index 0 is always the player)
	Character* target = characters[0];

	//Attack target
	std::cout << "\n" << m_name << " attacked " << target->GetName() << "\n\n";

	//Damage between 5 and 20
	int damage = rand() % 15 + 5;

	target->RemoveHealth(damage);
}