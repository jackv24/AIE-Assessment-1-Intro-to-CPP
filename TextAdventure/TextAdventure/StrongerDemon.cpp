#include "StrongerDemon.h"

StrongerDemon::StrongerDemon()
{
	m_name = "Stronger Demon";
	m_health = m_maxHealth = 100;
}

StrongerDemon::~StrongerDemon()
{

}

void StrongerDemon::Action(std::vector<Character*> characters)
{
	//The enemy to attack (index 0 is always the player)
	Character* target = characters[0];

	//Attack target
	std::cout << "\n" << m_name << " attacked " << target->GetName() << ", but like, stronger than a normal demon would.\n\n";

	//Damage between 10 and 30
	int damage = rand() % 20 + 10;

	target->RemoveHealth(damage);
}