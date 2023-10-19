// wordSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

string reverseIt(string); // function that reverses a line
int wordFinder(ifstream& infile); // function that searches for words horizontally

int main()
{
	ifstream infile;

	infile.open("C:/Users/smith/source/repos/CS121/Data/word_puzzle_2D_problem_six.txt");

	if (!infile)
	{
		cout << "Could not open file!" << endl;
		return 1;
	}

	int wordsFound = wordFinder(infile);

	cout << "\n" << wordsFound << " words found in the puzzle." << endl;

	infile.close();

	cout << endl;
	system("PAUSE");

}

int wordFinder(ifstream& infile) // function that finds all horizontal words in the word scramble
{
	string horizontalWords[21] = // store all horizontal words in an array
	{ "burp", "back", "kegs", "rose", "sore", "eros", "mood", "doom", "cent", "ball", "able",
		"lead", "dark", "loot", "tool", "mice", "talk", "dust", "quit", "data", "salt" };

	string puzzleLine[10]; 
	string reversedPuzzleLine[10]; 
	int wordsFound = 0;

	cout << "Normal words: " << endl;

	for (int i = 0; i < 10; i++)
	{
		getline(infile, puzzleLine[i]); // increments what row you are searching

		for (int j = 0; j < 21; j++) // the following for loops find words left to right in each line
		{
			size_t position = puzzleLine[i].find(horizontalWords[j]); // searches the current row for any horizontal words

			if (position != string::npos)
			{
				cout << "Found the word " << horizontalWords[j] << " on line " << i + 1 << ". " << endl;
				wordsFound++; // keeps track of the amount of words found
			}
		}
	}

	cout << endl;

	cout << "Reversed words: " << endl;
			
	for (int i = 0; i < 10; i++)
	{
		getline(infile, puzzleLine[i]); // increments what row you are searching
		reversedPuzzleLine[i] = reverseIt(puzzleLine[i]); // reverses the line

		for (int j = 0; j < 21; j++) 
		{
			size_t position = reversedPuzzleLine[i].find(horizontalWords[j]); // searches the current row for any horizontal words

			if (position != string::npos)
			{
					cout << "Found the word " << horizontalWords[j] << " on line " << i + 1 << ". " << endl;
					wordsFound++;
			}
		}
	}

	cout << endl;

	//------------- Code between comments swaps rows and columns

	string verticalLine[10];
	string reversedVerticalLine[10];

	int i = 0, k = 0;

	for (int i = 0; i < 10; i++)
	{
		getline(infile, puzzleLine[i]); // stores all of the seperate lines the puzzleLine array
	}

	for (int k = 0; k < 10; k++) // increments the row position
	{
		string letter = "";

		for (int j = 0; j < 10; j++) // stores current row position's letter for each column
		{
			letter += puzzleLine[j][k];
		}

		verticalLine[k] = letter; // each line of the swapped column and reverse data
	}

	//------------- Code between comments swaps rows and columns 
	//verticalLine[k] is the new infile basically

	string verticalWords[11] =
	{ "peek", "keep", "dons", "slam", "dart", "trad", "arts", "able", "bait", "teem", "meet" };

	cout << "Column Words: " << endl;

	for (int i = 0; i < 10; i++)
	{
		verticalLine[i];

		for (int j = 0; j < 11; j++)
		{
			size_t position = verticalLine[i].find(verticalWords[j]);

			if (position != string::npos)
			{
				cout << "Found the word " << verticalWords[j] << " on line " << i + 1 << "." << endl;
				wordsFound++; 
			}
		}
	}

	cout << endl;

	cout << "Reversed Column Words: " << endl;

	for (int i = 0; i < 10; i++)
	{
		verticalLine[i];
		reversedVerticalLine[i] = reverseIt(verticalLine[i]);

		for (int j = 0; j < 11; j++)
		{
			size_t position = reversedVerticalLine[i].find(verticalWords[j]);

			if (position != string::npos)
			{
				cout << "Found the word " << verticalWords[j] << " on line " << i + 1 << "." << endl;
				wordsFound++;
			}
		}
	}


	return wordsFound;

}


string reverseIt(string line)
{
	string invertLine = "";
	int position = 0;

	for (position = line.length() - 1; position >= 0; position--)
		invertLine += line.at(position);

	return invertLine;
}