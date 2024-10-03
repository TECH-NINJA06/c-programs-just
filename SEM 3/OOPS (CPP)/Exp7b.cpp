/*Write a C++ program which reads a text from keyboard and display the following

information on screen in 3 column format
1. Number of lines
2. Number of words
3. Number of characters
Strings should be left justified and numbers to be right justified. Use suitable field width, use getc(), to read text*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string text;
    int lines = 0, words = 0, chars = 0;
    char ch;
    cout << "Enter text: ";
    while ((ch = getc(stdin)) != EOF) {
        if (ch == '\n') {
            lines++;
            words++;
        } else if (ch == ' ') {
            words++;
        }
        chars++;
        text += ch;
    }
    cout << left << setw(20) << "Number of lines" << right << setw(10) << lines << endl;
    cout << left << setw(20) << "Number of words" << right << setw(10) << words << endl;
    cout << left << setw(20) << "Number of characters" << right << setw(10) << chars << endl;
    return 0;
}
