#include "Item.h"

Item::Item()
{
	m_name = "Item";
	m_type = Type::BASIC;
}

Item::~Item()
{

}

Item::Type Item::GetType()
{
	return m_type;
}

void Item::Use(Character* target)
{
	std::cout << "It did nothing." << std::endl;
}

String Item::GetName()
{
	return m_name;
}
