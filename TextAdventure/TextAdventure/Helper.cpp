#include "Helper.h"

void ClearInput()
{
	//Input stream
	std::istream& in = std::cin;
	char c;

	//Read characters until a newline
	while (in.get(c) && c != '\n');
}