#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void delWords(int del_L)
{

	string StoreWord;
	string filename, newfile;



	cout << "Enter the length of the characters to be deleted: ";
	cin >> del_L;


	cout << "Please enter the file" << endl;
	cin >> filename;

	ifstream WordIFILE(filename);

	cout << "Please enter the name for your new file" << endl;
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

	while (getline(WordIFILE, StoreWord))
	{

		oFile << StoreWord << endl;

	}

}
int main() {

	int del_L = 0;
	delWords(del_L);
	return 0;
}