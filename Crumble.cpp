#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Delete words function
void delWords(int del_L) {

    string StoreWord;
    string filename, newfile;
    //User is prompted for file 
    cout << "Please enter or copy and paste the file" << endl;
    cin >> filename;
    // New file created
    ifstream WordIFILE(filename);
    //User prompted for new file name
    cout << "Please enter the name for your new file" << endl;
    cin >> newfile;
    //file closed
    ofstream OutFile(newfile);
    
    //looks for words with specified letter count
    while (getline(WordIFILE, StoreWord)) {
        if (StoreWord.length() > del_L) {
            OutFile << StoreWord << endl;

        }
    }
    WordIFILE.close();
    OutFile.close();
    //store file
    while (getline(WordIFILE, StoreWord)) {

        OutFile << StoreWord << endl;

    }

}

int main() {
    
    int del_L = 0;
    //prompt user to enter the amount of letters 
    cout << "Enter the length of the characters to be deleted: ";
    cin >> del_L;
    //function called
    delWords(del_L);

    return 0;
}
