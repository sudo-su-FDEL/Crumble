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

void delWords(int del_L)
{

	string StoreWord;
	string filename, newfile;
	cout << "You have chosen to delete characters based on length" << endl;
	cout << endl << endl;

	cout << "** Drag and drop or type in file name (i.e. filename.txt)" << endl;

	cout << "Enter the length of the characters to be deleted: ";
	cin >> del_L;

	cout << "Please enter the file: ";
	cin >> filename;

	ifstream WordIFILE(filename);

	cout << "Please enter the name for your new file: ";
	cin >> newfile;

	ofstream oFile(newfile);

	while (getline(WordIFILE, StoreWord))
	{
		if (StoreWord.length() != del_L)
		{

			oFile << StoreWord << endl;

		}
	}
	WordIFILE.close();
	oFile.close();

}


void ch_count(string wCount)
{


	string infilename;
	string newfilename;
	cout << "Please enter name of text file: ";
	cin >> infilename;


	ifstream fin(infilename);


	cout << "\nPlease enter name for the new file: ";
	cin >> newfilename;

	ofstream fiout(newfilename);

	int count[300] = { 0 };

	string word;

	int len;

	
		while (fin >> word)
		{

			len = word.length();

			count[len - 1] += 1;
		}
	
		fiout << "Wordlist contains:\n";

		
		for (int i = 19; i >= 0; i--)
		{
			
			if (count[i] != 0)
			{
				
				fiout << count[i] << " words of " << i + 1 << " characters\n";
			}
		}
	
}

