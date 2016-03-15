#include "Helper.h"

//Flushes the input stream
void ClearInput()
{
	//Input stream
	std::istream& in = std::cin;
	char c;

	//Read characters until a newline
	while (in.get(c) && c != '\n');
}