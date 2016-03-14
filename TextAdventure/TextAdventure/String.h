/*
	Author:			Jack Vine
	Date Created:	23/2/2016
	Brief:			A custom string class (emulating the std::string).
*/

#pragma once

#include <iostream>

class String
{
public:
	// Constructors
	String();
	String(const char* string);
	// Copy contructor
	String(const String& string);
	// Destructor
	~String();

	// Operator overloads
	String operator = (const char* string);
	String operator + (const String& rhs);
	bool operator == (const String& string);

	friend std::ostream& operator << (std::ostream &in, String& string);
	friend std::istream& operator >> (std::istream &in, String& string);

	// Returns a C-style string
	const char* Get() const;
	// Returns the length of the string 
	const int GetLength() const;
	// Returns a character at a given index in the character array
	const char GetChar(int index) const;

	// Performs conversions between uppercase and lowercase, and returns the resulting string
	String String::ToLowercase();
	String String::ToUppercase();

	void SplitString(String& output1, String& output2, int index);

	// Finds a string within the string and returns the index
	int FindSubstring(int startIndex, const char* subString);
	int FindSubstring(const char* subString);

	// Finds a string within the string and replaces it with another
	String FindAndReplace(const char* subString, const char* replaceString);

private:
	char* m_string;
};