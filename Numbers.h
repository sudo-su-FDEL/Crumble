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


// In this function the user will generate a wordlist based of phone numbers 
// by simply putting 3 digits, the function will generate a wordlists of all possible 7 digit
// phone numbers
void GenNum(long long num)
{

	ofstream Outfile;

	int zip;
	cout << "Please enter Zip code to generate list of phone numbers(i.e.'123'):";
	cin >> zip; //user input of 3 digits

	if (zip > 999)
	{
		cout << "Error, Invalid zip code" << endl;
		system("pause");
		return;
	}

	Outfile.open("Phone-Number-Wordlist.txt");

	if (Outfile.is_open())
	{
		for (int a = 1000000; a <= 9999999; a++) {

			Outfile << zip << a << endl; //generate zip number concatanated with generated numbers
		}

	}
	cout << "\n\n\nSuccessfully processed the file!" << endl;
	system("pause");

	Outfile.close();
}


//this function will generate a wordlist with minimum and maximum range, 
//user sets the range
void NumRange(int Rnums)
{

	ofstream Outfile;
	int min, max;

	cout << "Please set the range to generate numbers" << endl;

	//set the range
	cout << "Min range:"; //minimum
	cin >> min;
	cout << "Max range";
	cin >> max;//maximum
	if (min >= max)
	{

		cout << "Error, Min is greater than max" << endl;
		system("pause");
		return;
	}

	Outfile.open("Range-Number-Wordlist.txt");

	if (Outfile.is_open())
	{
		//min = x, max = y , if min is less than x then increment min
		for (min = min; min <= max; min++)
		{

			cout << min << endl;
			Outfile << min << endl; //grabbing all increments of min and setting them to the
									// output file
		}

	}
	cout << "\n\n\nSuccessfully processed the file!" << endl;
	system("pause");

	Outfile.close();
}
