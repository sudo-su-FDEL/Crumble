#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm> 
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>

using namespace std;

void Createlist(string Cr_list)
{
	// set variable
	string input, outputname;
	cout << "Please enter a name for the output file :";
	cin >> outputname;
	cout << "\nPlease input words: ";
	cin.ignore(1);
	getline(cin, input); //reads input

	string word;
	vector<string> words;
	// stringstream variable
	stringstream in_str(input);
	while (getline(in_str, word, ' '))
	{
		//moves word back
		words.push_back(word);
	}
	//read size of words
	for (int i = 0; i < (int)words.size(); i++)
		cout << words[i] << "\n";
	//set output file
	ofstream file;
	file.open(outputname); //open file
	for (int i = 0; i < (int)words.size(); i++)
	{
		file << words[i];
		file << "\n";
	}
	file.close();

}

void merge2(string MFile2)
{

	cout << "You have chosen to merge 2 wordlists" << endl;
	string file1name, file2name, file3name;
	cout << endl << endl;

	cout << "** Drag and drop or type in file name (i.e. filename.txt)\n";

	cout << "Enter name of first file: ";
	cin >> file1name;

	cout << "Enter name of second file:";
	cin >> file2name;

	cout << "\nEnter name of output file: ";
	cin >> file3name;

	ofstream oFile(file3name.c_str());

	string word1, word2;
	ifstream inFileOne(file1name.c_str());
	while (inFileOne >> word1) {

		ifstream inFileTwo(file2name.c_str());

		while (inFileTwo >> word2)
		{
			oFile << word1 << word2 << endl;
		}
		inFileTwo.close();
	}
	inFileOne.close();
	oFile.close();

}

void merge3(string MFile3)
{
	cout << "You have chosen to merge 3 wordlists" << endl;
	string file1name, file2name, file3name, outfilename, word1, word2, word3;
	cout << endl << endl;

	cout << "** Drag and drop or type in file name (i.e. filename.txt)" << endl;

	cout << "Enter name of first file: ";
	cin >> file1name;

	cout << "Enter name of second file: ";
	cin >> file2name;

	cout << "Enter name of third file: ";
	cin >> file3name;

	cout << "Enter name of output file: ";
	cin >> outfilename;


	ofstream inFileFour(outfilename.c_str());

	ifstream inFileOne(file1name.c_str());
	while (inFileOne >> word1)
	{
		ifstream inFileTwo(file2name.c_str());

		while (inFileTwo >> word2)
		{

			ifstream inFileThree(file3name.c_str());

			while (inFileThree >> word3)
			{
				inFileFour << word1 << word2 << word3 << endl;
			}
			inFileThree.close();
		}
		inFileTwo.close();
	}
	inFileOne.close();
	inFileFour.close();

}
