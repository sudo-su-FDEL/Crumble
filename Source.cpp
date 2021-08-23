#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm> 
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <map>
#include <cstring>

using namespace std;

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
	cin >> filename >> endl;
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
//except the method "tolower"ss
//these two functions have a switch statement that has two options, First letter and whole word.


void capitalize(string cap)
{
	char choice;
	system("clear");

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


			outputfile.open(inputname + " -capitalized");// wrie to file
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

			system("clear");
			cout << "Please select a letter from the menu\n";
			cin.ignore();
			break;





		}


	} while (!((choice == 'z') || (choice == 'Z')));



}

void lowercase(string low)
{
	char choice;
	system("clear");

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
			system("clear");
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
			system("clear");
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

			system("clear");
			cout << "Please select a letter from the menu\n";
			cin.ignore();
			break;
		}


	} while (!((choice == 'z') || (choice == 'Z')));



}



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



//This unctio will delete words based on the character length that the user 
//sets it to.
// User is allowed to have multiple inputs 

void delWords(int del_L)
{

	string filename;
	ifstream fin;
	ofstream fout;

	//string line;

	cout << "Please enter the file to delete characters: "; // User applies the filename
	cin >> filename;

	fin.open(filename);

	cout << "\nEnter the characters to be deleted" << endl;
	cout << "Seperate using spaces\n\nEXAMPLE: 5 7 10" << endl;
	cout << "Input: ";
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


int main()
{


	//Variables for main
	int del_L = 0;
	int emt = 0;
	string MFile2, MFile3, perm, rplace, wCount, s, Cr_list, cap, low;
	int Rnums = 0;
	unsigned num = 9999999;
	char choices;

	do {
		system("clear");
		cout << "\n\n\t\tCRUMBLE" << endl;
		cout << "\t\t" << endl;
		cout << "By: " << endl;
		cout << "sudo-su-FDEL" << endl;
		cout << "-----------------------------------------------------------";
		cout << "\n Choose an option:                                        |\t";
		cout << "\n [A] Create wordlist                                      |\t";
		cout << "\n [B] Edit Wordlists                                       |\t";
		cout << "\n [C] Numbers for Wordlists                                |\t";
		cout << "\n [D] Analysis                                             |\t";
		cout << "\n                                                          |\t";
		cout << "\n [Z] Exit                                                 |" << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "Input: ";
		cin >> choices;
		system("clear");

		switch (choices)
		{

		case 'A':
		case 'a':
			char wordlist;
			do {

				cout << "\n [A] Create Wordlist";
				cout << "\n [B] Merge two wordlists";
				cout << "\n [C] Merge three wordlists\n";
				cout << "\n [Z] Go back\n";
				cout << "Input: ";
				cin >> wordlist;
				switch (wordlist)
				{


				case 'A':
				case 'a':
					//create wordlist
					system("clear");
					Createlist(Cr_list);
					system("pause");
					system("clear");
					break;


				case 'B':
				case 'b':
					//merge 2
					system("clear");
					merge2(MFile2);
					system("clear");
					break;


				case 'C':
				case 'c':
					//merge 3
					system("clear");
					merge3(MFile3);
					system("clear");
					break;


				case 'Z':
				case 'z':
					system("clear");
					break;


				default:

					system("clear");
					cout << "Please select a letter from the menu\n";
					cin.ignore();
					break;



				}


			} while (!((wordlist == 'z') || (wordlist == 'Z')));
			break;




		case 'B':
		case 'b':
		{
			system("clear");
			char Schar;
			do {
				cout << "'*' manually input word(s) input\n";
				cout << "\n [A] Replace letters";
				cout << "\n [B] Swap*";
				cout << "\n [C] Permute*";
				cout << "\n [D] Capitalize first letter";
				cout << "\n [E] Lowercase first letter\n";
				cout << "\n [Z] Go back\n";
				cout << "Input: ";
				cin >> Schar;
				switch (Schar)
				{


				case 'A':
				case 'a':

					system("clear");
					replace(rplace);
					system("clear");
					break;


				case 'B':
				case 'b':

					system("clear");
					swap(s);
					system("clear");
					break;



				case 'C':
				case 'c':
					system("clear");
					permute(perm);
					system("clear");
					break;

				case 'D':
				case 'd':
					system("clear");
					capitalize(cap);
					system("clear");
					break;

				case 'E':
				case 'e':
					lowercase(low);
					system("clear");
					break;

				case 'Z':
				case 'z':



					system("clear");
					break;

				default:
					system("clear");
					cout << "Please select a letter from the menu\n";
					cin.ignore();
					break;
				}


			} while (!((Schar == 'z') || (Schar == 'Z')));
			break;
		}

		case 'C':
		case 'c':
		{
			system("clear");
			//Numbers
			char Numbers;
			do {

				cout << "\n [A] Create Phone Number wordlist";
				cout << "\n [B] Generate numbers based on range\n";
				cout << "\n [Z] Go back\n";
				cout << "Input: ";
				cin >> Numbers;
				switch (Numbers)
				{


				case 'A':
				case 'a':

					system("clear");
					GenNum(num);
					system("clear");
					break;


				case 'B':
				case 'b':
					system("clear");
					NumRange(Rnums);
					system("clear");
					break;



				case 'Z':
				case 'z':
					system("clear");
					break;


				default:
					system("clear");
					cout << "Please select a letter from the menu\n";
					cin.ignore();
					break;
				}


			} while (!((Numbers == 'z') || (Numbers == 'Z')));
			break;
		}


		case 'D':
		case 'd':
		{
			system("clear");
			char Analysis;
			do {

				cout << "\n [A] Delete words based on character length";
				cout << "\n [B] Delete empty lines";
				cout << "\n [C] Count words\n";
				cout << "\n [Z] Go back\n";
				cout << "Input: ";
				cin >> Analysis;
				switch (Analysis)
				{


				case 'A':
				case 'a':
					//delete words
					system("clear");
					delWords(del_L);
					system("clear");
					break;


				case 'B':
				case 'b':
					//delete empty lines
					system("clear");
					del_empty_lines(emt);
					system("clear");
					break;



				case 'C':
				case 'c':
					//count words
					system("clear");
					ch_count(wCount);
					system("clear");
					break;

				case 'Z':
				case 'z':



					system("clear");
					break;

				default:
					//validating user
					system("clear");
					cout << "Please select a letter from the menu\n";
					cin.ignore();
					break;
				}


			} while (!((Analysis == 'z') || (Analysis == 'Z')));

			break;
		}

		default:
			//validating user for whole menu
			cout << endl;
			cout << "Please select a letter from the menu\n" << endl;


		}

	} while (!((choices == 'z') || (choices == 'Z')));

	return 0;
}


