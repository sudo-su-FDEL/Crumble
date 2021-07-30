
#include <windows.h> // for 'system("color 08")'
#include <iostream>

//headers
#include "createwordlist.h"
#include "editwordlists.h"
#include "Numbers.h"
#include "Analysis.h"
using namespace std;


int main()
{

	system("color 08");
	//Variables for main
	int del_L = 0;
	int emt = 0;
	string MFile2, MFile3, perm, rplace, wCount, s, Cr_list, cap, low;
	int Rnums = 0;
	unsigned num = 9999999;
	char choices;

	do {
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
		system("cls");

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
					system("cls");
					Createlist(Cr_list);
					system("pause");
					system("cls");
					break;


				case 'B':
				case 'b':
					//merge 2
					system("cls");
					merge2(MFile2);
					system("cls");
					break;


				case 'C':
				case 'c':
					//merge 3
					system("cls");
					merge3(MFile3);
					system("cls");
					break;


				case 'Z':
				case 'z':
					system("cls");
					break;


				default:

					system("cls");
					cout << "Please select a letter from the menu\n";
					cin.ignore();
					break;



				}


			} while (!((wordlist == 'z') || (wordlist == 'Z')));
			break;




		case 'B':
		case 'b':
		{
			system("cls");
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

					system("cls");
					replace(rplace);
					system("cls");
					break;


				case 'B':
				case 'b':

					system("cls");
					swap(s);
					system("cls");
					break;



				case 'C':
				case 'c':
					system("cls");
					permute(perm);
					system("cls");
					break;

				case 'D':
				case 'd':
					system("cls");
					capitalize(cap);
					system("cls");
					break;

				case 'E':
				case 'e':
					lowercase(low);
					system("cls");
					break;

				case 'Z':
				case 'z':



					system("cls");
					break;

				default:
					system("cls");
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
			system("cls");
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

					system("cls");
					GenNum(num);
					system("cls");
					break;


				case 'B':
				case 'b':
					system("cls");
					NumRange(Rnums);
					system("cls");
					break;



				case 'Z':
				case 'z':
					system("cls");
					break;


				default:
					system("cls");
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
			system("cls");
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

					delWords(del_L);
					system("cls");
					break;


				case 'B':
				case 'b':
					//delete empty lines
					system("cls");
					del_empty_lines(emt);
					system("cls");
					break;



				case 'C':
				case 'c':
					//count words
					system("cls");
					ch_count(wCount);
					system("cls");
					break;

				case 'Z':
				case 'z':



					system("cls");
					break;

				default:
					//validating user
					system("cls");
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



