#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm> 
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <map>

using namespace std;

//This unctio will delete words based on the character length that the user 
//sets it to.
// User is allowed to have multiple inputs 

void delWords(int del_L)
{

	string filename;
	ifstream fin;
	ofstream fout;

	//string line;

	cout << "Please enter the file to delete characters: " << endl; // User applies the filename
	cin >> filename;

	fin.open(filename);

	cout << "Enter the characters to be deleted" << endl;
	int num;
	vector<int> v;
	char c = 'a';
	for (;;)
	{
		if (c == '\n')
			break;
		cin >> num;
		v.push_back(num);
		c = getchar();
		if (c == '\n')
			break;
	}
	map<int, int>mm;
	for (auto x : v) {
		mm[x] = 1;// see if the word of particular length should be deleted or not
	}
	string ofile;
	cout << "enter the output file name" << endl;
	cin >> ofile;
	fout.open(ofile + "-deleted-characters");

	char ch;
	string sss = "";
	while (fin)
	{
		fin.get(ch);
		if (ch == ' ' || ch == '\n') {
			if (!mm[sss.length()]) {//if word length matches one of the input lengths then delete the word
				fout << sss;
			}
			fout << ch;
			sss = "";
		}
		else {
			sss += ch;
		}
	}

	cout << "Please run the 'delete empty lines', option after!" << endl;
	cout << "\n\n\nSuccessfully processed the file!" << endl;
	system("Pause");

	// Close the File
	fin.close();
	fout.close();


}



// This function will use getline to detect what line is 0 characters
// for every line that is x>=1 characters, will grab the word and place it in another file
// that user names.

void del_empty_lines(int emt)
{

	string StoreWord;
	string filename, newfile;
	cout << "You have chosen to delete characters based on length" << endl;
	cout << endl << endl;

	cout << "** Drag and drop or type in file name (i.e. filename.txt)" << endl;

	emt = 0;

	cout << "Please enter the file: ";
	cin >> filename;

	cout << "Deleting empty lines..." << endl;
	ifstream WordIFILE(filename);


	ofstream oFile(filename + " -emptylines");

	while (getline(WordIFILE, StoreWord))
	{
		if (StoreWord.length() != emt)
		{

			oFile << StoreWord << endl;

		}
	}
	WordIFILE.close();
	oFile.close();

	cout << "\n\n\nSuccessfully processed the file!" << endl;
	system("pause");
}




//This function will count all the words and character on each line, 
//the way this works is by reading each word on each line and then taking that 
//and creating another file with the information of how many words containing what amount of characters

void ch_count(string wCount)
{

	string infilename;
	string newfilename;

	cout << "Please enter name of text file: ";
	cin >> infilename;

	ifstream fin(infilename); //added some validation incase anything goes wrong
	if (!fin)
	{
		cout << "\nERROR FILE DOES NOT EXIST";

	}



	ofstream fiout(infilename + "-Counted"); //file will appear with endinf of "-Counted"

	int count[500] = { 0 }; //amount of word space to count
	string word;
	int len;

	while (fin >> word)
	{

		len = word.length(); //reading word lenght and initiallizing it into another variable named len

		count[len - 1] += 1; //counting
	}

	fiout << "This wordlist contains:\n";

	// print larger word count first
	// Loop form i = 19 to 0
	for (int i = 19; i >= 0; i--)
	{
		// If count of ith index is not ==  0
		if (count[i] != 0)
		{
			// Write count & length of word in file
			fiout << count[i] << " word(s) of " << i + 1 << " characters\n";
		}
	}
	cout << "\n\n\nSuccessfully processed the file!" << endl;
	system("pause");
}

