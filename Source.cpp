#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void delWords(int del_L) {

    string StoreWord;
    string filename, newfile;

    cout << "Please enter or copy and paste the file" << endl;
    cin >> filename;
    ifstream WordIFILE(filename);
    cout << "Please enter the name for your new file" << endl;
    cin >> newfile;
    ofstream OutFile(newfile);

    while (getline(WordIFILE, StoreWord)) {
        if (StoreWord.length() != del_L) {
            OutFile << StoreWord << endl;

        }
    }
    WordIFILE.close();
    OutFile.close();

    while (getline(WordIFILE, StoreWord)) {

        OutFile << StoreWord << endl;

    }

}

int main() {

    int del_L = 0;
    cout << "Enter the length of the characters to be deleted: ";
    cin >> del_L;

    delWords(del_L);

    return 0;
}