#include "Item.h"

Item::Item()
{
	m_name = "an item";
}

Item::~Item()
{

}

void Item::Use()
{
	std::cout << "It did nothing." << std::endl;
}

String Item::GetName()
{
	return m_name;
}
