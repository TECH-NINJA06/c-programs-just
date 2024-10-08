/*Write a C++ program which reads a text from keyboard and display the following

information on screen in 3 column format
1. Number of lines
2. Number of words
3. Number of characters
Strings should be left justified and numbers to be right justified. Use suitable field width*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string text;
    cout << "Enter text: ";
    getline(cin, text);
    int lines = 0, words = 0, characters = 0;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '\n') {
            lines++;
        } else if (text[i] == ' ') {
            words++;
        } else {
            characters++;
        }
    }
    //give output in three columns, left justified and right justified as per the question, also put in a box, using '-' and '|'
    cout << setfill('-') << setw(37) << "-" << endl;
    cout << setfill(' ');
    cout << setw(25) << left << "|Number of Lines" << setw(10) << right << lines << setw(2) << "|" << endl;
    cout << setw(25) << left << "|Number of Words" << setw(10) << right << words << setw(2) << "|" << endl;
    cout << setw(25) << left << "|Number of Characters" << setw(10) << right << characters << setw(2) << "|" << endl;
    cout << setfill('-') << setw(37) << "-" << endl;
    return 0;
}