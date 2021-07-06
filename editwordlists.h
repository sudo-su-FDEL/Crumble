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

void swap(string s)
{

	ofstream myfile;
	string data;
	cout << "Please enter words to swap: " << endl;
	cout << "(i.e. 'word1 word2 word3')" << endl;

	cin.ignore(1);
	getline(cin, data);

	stringstream X(data);
	stringstream Y(data);

	int count_words = 0;

	while (getline(X, data, ' '))
	{
		count_words++;
	}

	vector<string> Store(count_words);
	int index = 0;
	while (Y >> data)
	{
		Store[index] = data;
		index++;
	}

	myfile.open("Word-Swap-File.txt");
	cout << "\n\n";

	for (int i = 0; i < count_words; i++)
	{
		string temp = Store[0];

		for (int j = 0; j < count_words; j++)
		{
			myfile << Store[j];
			cout << Store[j];

			if (j < count_words - 1)
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

	myfile.close();
}

void permute(string perm)
{
	ofstream Permfile;
	string permute_file;
	cout << "Please enter name for your output file: ";
	cin >> permute_file;
	Permfile.open(permute_file);
	char permutations[1000];
	cout << "Please enter letters/word to permutate: ";
	cin >> permutations;
	int len = strlen(permutations);
	sort(permutations, permutations + len);
	do {
		Permfile << permutations << endl;
	} while (next_permutation(permutations, permutations + len));

	Permfile.close();
}
void replace(string rplace)
{
	ifstream fin;
	string filename, txtfile;
	ofstream file;

	cout << "Enter name for new file";
	cin >> filename;
	cout << endl;


	file.open(filename, ios::out);

	cout << "Please insert your txt file: ";
	cin >> txtfile;

	fin.open(txtfile);
	char my_character, inp, outp;

	cout << "Please enter the letter you want to target: ";
	cin >> inp;

	cout << "Please enter the string to replace: ";
	cin >> outp;

	int number_of_lines = 0;
	while (!fin.eof()) {
		fin.get(my_character);
		if (my_character == inp) {
			my_character = outp;
		}
		file << my_character;
	}
	file.close();
	fin.close();
}
