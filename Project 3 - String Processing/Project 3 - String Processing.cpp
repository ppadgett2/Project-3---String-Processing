// Author: Parker Padgett
// Assignment: String Processing
// Description: Write a program that will receive a string value via the keyboard from a user and then remove any html tags from that value
// Date: 2/2/2022


#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <fstream>

using namespace std;

// Declaring functions
string input();
void alter(string& text);
void output(string& text);

int main()
{
	// Variable declaration
	string text;

	// Title and Description
	cout << "Title: Assignment 3: String Processing" << endl;
	cout << "Description: Write a program that will" << endl;
	cout << "receive a string value via the keyboard" << endl;
	cout << "from a user and then remove any html tags" << endl;
	cout << "from that value" << endl << endl;

	// Get text from user and print it out
	text = input();

	// Read through each character looking for "<" and ">" and removing whats in between
	alter(text);

	// Print out altered text
	output(text);

	return 0;
}

string input()
{
	string text;
	cout << "Enter some text: ";
	getline(cin, text);
	cout << endl << endl;
	cout << "Original Text: " << text << endl;

	return text;
}

void alter(string& text)
{
	for (int a = 0; a < text.length(); a++)
	{
		// Finds "<" and the next ">" then erases it and whatever is in between
		if (text[a] == '<')
		{
			size_t first = text.find("<");
			size_t last = text.find(">");

			text.erase(first, last - first + 1);
			a--;
		}
	}
}

void output(string& text)
{
	cout << "Altered Text: " << text;
}