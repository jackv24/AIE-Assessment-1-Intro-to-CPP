#include "String.h"
#include <iostream>

//Constructors
String::String()
{
	//char array should only contain the escape character
	m_string = new char[1];
	m_string[0] = '\0';
}

String::String(const char* string)
{
	int length = strlen(string);

	//Resize char array to the size of the string passed in +1 (leaves room for escape character)
	m_string = new char[length + 1];

	//Iterate through and copy each character
	for (int i = 0; i < length; i++)
	{
		m_string[i] = string[i];
	}

	//Make last character the escape character
	m_string[length] = '\0';
}

String::String(const String& string)
{
	int length = strlen(string.m_string);

	m_string = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		m_string[i] = string.m_string[i];
	}

	m_string[length] = '\0';
}
//Destructor
String::~String()
{
	if (m_string != nullptr)
		delete[] m_string;
}

//Operator overloads
String String::operator = (const char* rhs)
{
	int length = strlen(rhs);

	if (m_string != nullptr)
		delete[] m_string;

	m_string = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		m_string[i] = rhs[i];
	}

	m_string[length] = '\0';

	return String(m_string);
}

String String::operator + (const String& rhs)
{
	int initialLength = strlen(m_string);
	int newLength = rhs.GetLength() + initialLength;

	char* temp = new char[newLength + 1];

	for (int i = 0; i < initialLength; i++)
	{
		temp[i] = m_string[i];
	}

	for (int i = initialLength; i < newLength; i++)
	{
		temp[i] = rhs.m_string[i - initialLength];
	}

	temp[newLength] = '\0';

	return String(temp);
}

bool String::operator == (const String& string)
{
	if (string.GetLength() != strlen(m_string))
		return false;
	else
	{
		for (int i = 0; i < string.GetLength(); i++)
		{
			if (string.m_string[i] != m_string[i])
				return false;
		}

		return true;
	}
}

//Public functions
const char* String::Get() const
{
	return m_string;
}

const int String::GetLength() const
{
	return strlen(m_string);
}

const char String::GetChar(int index) const
{
	return m_string[index];
}

String String::ToLowercase()
{
	int length = strlen(m_string);

	char* temp = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		temp[i] = m_string[i];

		if (temp[i] >= 'A' && temp[i] <= 'Z')
			temp[i] += ('a' - 'A');
	}

	temp[length] = '\0';

	return String(temp);
}

String String::ToUppercase()
{
	int length = strlen(m_string);

	char* temp = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		temp[i] = m_string[i];

		if (temp[i] >= 'a' && temp[i] <= 'z')
			temp[i] += ('A' - 'a');
	}

	temp[length] = '\0';

	return String(temp);
}

void String::SplitString(String& output1, String& output2, int index)
{
	int inputLength = strlen(m_string);
	
	int outputLength1 = index, outputLength2 = inputLength - index;

	output1.m_string = new char[outputLength1 + 1];
	output2.m_string = new char[outputLength2 + 1];

	for (int i = 0; i < outputLength1; i++)
	{
		output1.m_string[i] = m_string[i];
	}
	output1.m_string[outputLength1] = '\0';

	for (int i = 0; i < outputLength2; i++)
	{
		output2.m_string[i] = m_string[i + index];
	}
	output2.m_string[outputLength2] = '\0';
}

int String::FindSubstring(int startIndex, const char* subString)
{
	int fullLength = strlen(m_string);
	int subLength = strlen(subString);

	int subStringIndex = -1;

	int currentSubLength = 0;

	for (int i = startIndex; i < fullLength; i++)
	{
		if (m_string[i] == subString[currentSubLength])
		{
			subStringIndex = i - currentSubLength;

			currentSubLength++;
		}
		else if(currentSubLength > subLength)
			subStringIndex = -1;
	}

	if (currentSubLength != subLength)
		subStringIndex = -1;

	return subStringIndex;
}

int String::FindSubstring(const char* subString)
{
	return FindSubstring(0, subString);
}

String String::FindAndReplace(const char* subString, const char* replaceString)
{
	// If the substring is empty it will cause errors, therefore just return the original string
	if (subString == "")
		return String(m_string);

	// Get the index of the first instance of the substring
	int index = FindSubstring(subString);

	// Container variables
	String left, middle, right;
	String temp;

	// Split into left, middle and right strings
	SplitString(left, temp, index);
	temp.SplitString(middle, right, strlen(subString));

	// Replace the middle string with 
	middle = replaceString;

	// Concatenate the container strings to form the new string with the substring replaced
	String result = left + middle + right;

	// If there are still instances of the substring, call recursively to replace them all
	if (FindSubstring(index + 1, subString) != -1)
		return result.FindAndReplace(subString, replaceString);
	else // Else end the recursion by returning the result
		return result;
}

std::ostream& operator << (std::ostream &out, String& string)
{
	std::cout << string.m_string;
	return out;
}

std::istream& operator >> (std::istream &in, String& string)
{
	char temp[256];

	std::cin >> temp;

	string = temp;

	return in;
}