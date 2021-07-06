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

void GenNum(long long num)
{
	ofstream Outfile;

	int zip;
	cout << "Please enter Zip code to generate list of phone numbers(i.e.'123'):";
	cin >> zip;

	Outfile.open("Phone-Number-Wordlist.txt");

	if (Outfile.is_open())
	{
		for (int a = 1000000; a <= 9999999; a++) {

			Outfile << zip << a << endl;
		}

	}
	Outfile.close();
}

void NumRange(int Rnums)
{

	ofstream Outfile;
	int min, max;

	cout << "Please set the range to generate numbers" << endl;

	//set the range
	cout << "Min range:";
	cin >> min;
	cout << "Max range";
	cin >> max;

	Outfile.open("Range-Number-Wordlist.txt");

	if (Outfile.is_open())
	{
		//min = 0, max = 10 , if min is less than 10 then increment min
		for (min = min; min <= max; min++)
		{

			cout << min << endl;
			Outfile << min << endl;
		}

	}

}
