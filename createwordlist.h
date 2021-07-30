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


//This function will allow a user create anew wordlist from scratch based on input 
//program will read via getline all of the users inputs and then create
//a new file with all of the input words

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

	cout << "\n\n\nSuccessfully processed the file!" << endl;
	system("pause");

	file.close();

}


//The merger2 function will allow the user to merge 2 files
//together. Program will create a new file, take the words from first file
//from user input, then take the words from the second file from user input
//and concatanate the words into the new file
//
void merge2(string MFile2)
{

	cout << "You have chosen to merge 2 wordlists" << endl;
	string file1name, file2name, file3name;
	cout << endl << endl;

	cout << "** Drag and drop or type in file name (i.e. filename.txt)\n";

	cout << "Enter name of first file: " << endl;;
	cin >> file1name;

	cout << "Enter name of second file:" << endl;
	cin >> file2name;

	cout << "\nEnter name of output file: " << endl;
	cin >> file3name;

	ofstream oFile(file3name.c_str()); // create output file 

	string word1, word2;
	ifstream inFileOne(file1name.c_str());//first input file
	while (inFileOne >> word1)  //word 1 is set into first input file (which is the first file from user)
	{

		ifstream inFileTwo(file2name.c_str()); //repeated

		while (inFileTwo >> word2) //repeated from first while loop
		{
			oFile << word1 << word2 << endl; //finally word 1 and word 2 are put into output file and concatanated
		}
		inFileTwo.close();
	}
	cout << "\n\n\nSuccessfully processed the file!" << endl;
	system("pause");

	inFileOne.close();
	oFile.close();

}

//merge3 function is similar to the merge2 function 
//only difference is that the concatanation is repeated once more
void merge3(string MFile3)
{



	cout << "You have chosen to merge 3 wordlists" << endl;
	string file1name, file2name, file3name, outfilename, word1, word2, word3;
	cout << endl << endl;

	cout << "** Drag and drop or type in file name (i.e. filename.txt)" << endl;

	cout << "Enter name of first file: " << endl;;
	cin >> file1name;

	cout << "Enter name of second file: " << endl;
	cin >> file2name;

	cout << "Enter name of third file: " << endl;
	cin >> file3name;

	cout << "Enter name of output file: " << endl;
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
				inFileFour << word1 << word2 << word3 << endl; //word 1 2 3 being concatanated into output
			}

			inFileThree.close();
		}

		inFileTwo.close();
	}

	inFileOne.close();
	inFileFour.close();
	cout << "\n\n\nSuccessfully processed the file!" << endl;
	system("pause");

}
