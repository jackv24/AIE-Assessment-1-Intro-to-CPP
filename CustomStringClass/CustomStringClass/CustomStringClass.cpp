// CustomStringClass.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include "String.h"

using namespace std;

// Prints out test-related information
void RunTest(const char* name, bool expression, int& testNumber, int&passedCount)
{
	testNumber++;
	if (expression) passedCount++;

	//Print info out to console
	cout << "Test " << testNumber << "\t\t"
		<< name << ((strlen(name) < 8) ? "\t\t" : "\t") //Accounts for test names which don't require an extra tab character
		<< ((expression) ? "Successful" : "Failed")
		<< endl;

	//Save info to file (append)
	fstream file;
	file.open("Log.txt", ios_base::app);

	if (file.is_open())
	{
		file << "Test " << testNumber << "\t\t"
			<< name << ((strlen(name) < 8) ? "\t\t" : "\t") //Accounts for test names which don't require an extra tab character
			<< ((expression) ? "Successful" : "Failed")
			<< endl;

		file.close();
	}
}

int main()
{
	int testNumber = 0;
	int passedCount = 0;

	String string = "Words and stuff";
	String a = "One", b = "Two";

	//Run tests
	RunTest("Length", (string.GetLength() == 15), testNumber, passedCount);
	RunTest("Char At", (string.GetChar(2) == 'r'), testNumber, passedCount);
	RunTest("Compare", (string == "Words and stuff"), testNumber, passedCount);

	RunTest("Append", (a + b == "OneTwo"), testNumber, passedCount);
	RunTest("Prepend", (b + a == "TwoOne"), testNumber, passedCount);

	RunTest("ToLower", (string.ToLowercase() == "words and stuff"), testNumber, passedCount);
	RunTest("ToUpper", (string.ToUppercase() == "WORDS AND STUFF"), testNumber, passedCount);

	RunTest("FindSubstring", (string.FindSubstring("and") >= 0), testNumber, passedCount);
	RunTest("FindFromIndex", (string.FindSubstring(5, "and") >= 0), testNumber, passedCount);

	RunTest("FindReplace", (string.FindAndReplace("and", "herpderp") == "Words herpderp stuff"), testNumber, passedCount);

	string = "NEW";
	RunTest("SetString", (string == "NEW"), testNumber, passedCount);

	//Display percentage passed
	cout << "\nPercentage Passed: " << (int)(((float)passedCount / testNumber) * 100) << "\n";

	//Write percentage passed to file
	fstream file;
	file.open("Log.txt", ios_base::app);
	if (file.is_open())
	{
		file << "\nPercentage Passed: " << (int)(((float)passedCount / testNumber) * 100) << "\n\n\n";
		file.close();
	}

	cin.get();

    return 0;
}

