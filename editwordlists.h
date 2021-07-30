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



// This function will swap words or will apply all the possible combinations the words from 
// user input may have
void swap(string s)
{


	ofstream myfile;
	string data;
	cout << "Please enter words to swap: " << endl;
	cout << "(i.e. 'word1 word2 word3')" << endl;

	cin.ignore(1); //for some reason I was getting an error if i wasnt using cin.ignore, using this bypassed that error
	getline(cin, data);

	stringstream X(data); //Used stirngstream since dealing with int and string data types
	stringstream Y(data);

	int countW = 0;

	while (getline(X, data, ' ')) //counting x(data)...
	{
		countW++; //count
	}

	vector<string> Store(countW);//once words were counted, they are stored
	int index = 0;
	while (Y >> data)//repeat
	{
		Store[index] = data;
		index++;
	}

	myfile.open("Word-Swap-File.txt"); //opened new file
	cout << "\n\n";

	for (int i = 0; i < countW; i++) //these for loops consists of placing all coutned words into 
										  //new file
	{
		string temp = Store[0];

		for (int j = 0; j < countW; j++)
		{
			myfile << Store[j];
			cout << Store[j];

			if (j < countW - 1)
			{
				Store[j] = Store[j + 1];
			}
			else
			{
				Store[j] = temp;

			}
		}
		cout << "\n";
		myfile << "\n";
	}
	cout << "\n\n\nSuccessfully processed the file!" << endl;
	system("pause");
	myfile.close(); //close file
}


//similar to the swap function, this function serves to permute all possible 
	//combinations of letters that the user inputs
void permute(string perm)
{

	ofstream Permfile;
	string permute_file;

	cout << "Please enter name for your output file: ";
	cin >> permute_file; //user inputs file name for output file

	Permfile.open(permute_file);

	char permutations[1000];//little overexagerated here but it is set to take 1000 characters
	cout << "Please enter letters/word to permutate: ";
	cin >> permutations;//user inputs word to permute

	int len = strlen(permutations);

	sort(permutations, permutations + len);//sorting between permutation and length of word

	do
	{
		Permfile << permutations << endl;

	} while (next_permutation(permutations, permutations + len));

	cout << "Successfully processed the file" << endl;
	system("pause");

	Permfile.close();
}


//This function will replace a specified letter for another letter.
void replace(string rplace)
{

	ifstream fin;
	string filename, txtfile;
	ofstream file;

	cout << "Enter name for new file";
	cin >> filename;
	cout << endl;

	file.open(filename + "-Replaced", ios::out);

	cout << "Please insert your text file: ";
	cin >> txtfile;

	fin.open(txtfile);
	char Mchar, inp, outp;

	cout << "Please enter the letter you want to target: ";
	cin >> inp;

	cout << "Please enter the string to replace: ";
	cin >> outp;

	int number_of_lines = 0;
	while (!fin.eof()) // while its not the end of file
	{
		fin.get(Mchar); //searching for letter to replace
		if (Mchar == inp)
		{
			Mchar = outp;
		}
		file << Mchar; //input new words with replaced letters into a new file
	}
	cout << "\n\n\nSuccessfully processed the file!" << endl;
	system("pause");

	file.close();
	fin.close();
}

//The capitalize function will capitalize the first letter of every word and the whole word
//similartly, for the lowercase function, the exact method was applied
//except the method "tolower"
//these two functions have a switch statement that has two options, First letter and whole word.


void capitalize(string cap)
{
	char choice;
	system("cls");

	do {
		cout << "Would you like to capitalize the first letter or whole word?" << endl;
		cout << "\n Choose an option:                                    \t";
		cout << "\n [A] First Letter                                     \t";
		cout << "\n [B] Whole Word                                       \t";
		cout << "\n [Z] Exit" << endl;
		cout << "Input: ";
		cin >> choice;
		switch (choice)
		{
		case'a':
		case'A':
		{
			string filename, newfile;
			cout << "Please input text file:";
			cin >> filename;

			ifstream RFILE(filename);

			string Text;
			cout << "Please enter a name for your output file:";
			cin >> newfile;
			ofstream WFILE(newfile + "First-letter-Capitalized");

			while (getline(RFILE, Text)) {
				Text[0] = toupper(Text[0]);
				WFILE << Text + '\n';
			}

			// Close the file
			RFILE.close();
			WFILE.close();
			system("pause");

			cout << "\n\n\nSuccessfully processed the file!" << endl;
			break;
		};

		case'b':
		case'B':
		{

			ifstream inputfile;
			ofstream outputfile;
			string inputname, outputname;
			cout << "Please enter the file to capitalize" << endl;
			cin >> inputname;
			inputfile.open(inputname);


			outputfile.open(inputname + " -capitalized");// write to file
			if (inputfile.is_open()) {
				string Line;
				// get line from inputstring
				while (getline(inputfile, Line))
				{
					// capitalizing the string process
					string Capstring;
					for (int i = 0; i < Line.size(); i++) {
						// first word of the sentence always capital
						Capstring += toupper(Line[i]);
					}
					// writing the capitalized sentence to the output file
					outputfile << Capstring << endl;
				}
			}
			// closing the file
			cout << "\n\n\nSuccessfully processed the file!" << endl;
			system("pause");

			inputfile.close();
			outputfile.close();
		};

		default:

			system("cls");
			cout << "Please select a letter from the menu\n";
			cin.ignore();
			break;





		}


	} while (!((choice == 'z') || (choice == 'Z')));



}

void lowercase(string low)
{
	char choice;
	system("cls");

	do {
		cout << "Would you like to lowercase the first letter or whole word?" << endl;
		cout << "\n Choose an option:                                    \t";
		cout << "\n [A] First Letter                                     \t";
		cout << "\n [B] Whole Word                                       \t";
		cout << "\n [Z] Exit" << endl;
		cout << "Input: ";
		cin >> choice;
		switch (choice)
		{
		case'a':
		case'A':
		{
			system("cls");
			string filename, newfile;
			cout << "Please input text file:";
			cin >> filename;

			ifstream RFILE(filename);

			string Text;
			cout << "Please enter a name for your output file:";
			cin >> newfile;
			ofstream WFILE(newfile + "First-letter-Lowercased");

			while (getline(RFILE, Text)) {
				Text[0] = tolower(Text[0]);
				WFILE << Text + '\n';
			}

			// Close the file
			RFILE.close();
			WFILE.close();
			cout << "\n\n\nSuccessfully processed the file!" << endl;
			system("pause");

			break;
		};

		case'b':
		case'B':
		{
			system("cls");
			ifstream inputfile;
			ofstream outputfile;
			string inputname, outputname;
			cout << "Please enter the file to lowercase" << endl;
			cin >> inputname;
			inputfile.open(inputname);

			// writing to a file
			outputfile.open(inputname + " -lowercase");
			if (inputfile.is_open()) {
				string Line;
				// getting each line from a file
				while (getline(inputfile, Line))
				{
					// capitalizing the string
					string Capstring;
					for (int i = 0; i < Line.size(); i++) {
						// first word of the sentence always capital
						Capstring += tolower(Line[i]);
					}
					// writing the capitalized sentence to the output file
					outputfile << Capstring << endl;
				}
			}
			// closing the file
			cout << "\n\n\nSuccessfully processed the file!" << endl;
			system("pause");

			inputfile.close();
			outputfile.close();
		};
		default:

			system("cls");
			cout << "Please select a letter from the menu\n";
			cin.ignore();
			break;
		}


	} while (!((choice == 'z') || (choice == 'Z')));



}

