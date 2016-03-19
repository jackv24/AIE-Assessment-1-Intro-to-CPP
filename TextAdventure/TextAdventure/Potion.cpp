#include "Potion.h"

Potion::Potion()
{
	m_name = "Potion";
	m_type = Type::CONSUMABLE;
}

Potion::~Potion()
{

}

void Potion::Use(Character* target)
{
	//Heal target
	target->AddHealth(50);
}