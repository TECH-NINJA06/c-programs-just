/*Write a C++ program to format the following o/p using manipulators(fig-expt4C), do something unique, dont copy code of Exp7d.cpp*/
//dont copy Exp7b.cpp
//maybe do program on result of marksheet,using class, array of objects (students), and display result dashboard in tabular format
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
        string name;
        int marks[5];
        int total;
        float percentage;
        char grade;
    public:
        void read() {
            cout << "Enter name: ";
            getline(cin,name);
            cout << "Enter marks in 5 subjects: ";
            for (int i = 0; i < 5; i++) {
                cin >> marks[i];
            }
            cin.ignore();
            calculate();
        }
        void calculate() {
            total = 0;
            for (int i = 0; i < 5; i++) {
                total += marks[i];
            }
            percentage = total / 5.0;
            if (percentage >= 90) {
                grade = 'A';
            } else if (percentage >= 80) {
                grade = 'B';
            } else if (percentage >= 70) {
                grade = 'C';
            } else if (percentage >= 60) {
                grade = 'D';
            } else if (percentage >= 50) {
                grade = 'E';
            } else {
                grade = 'F';
            }
        }
        void display() {
            cout << setw(20) << left << name << setw(10) << right << total << setw(12) << setprecision(2) << fixed << percentage << setw(10) << grade << endl;
        }
};
int main(){
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();
    Student s[n];
    for (int i = 0; i < n; i++) {
        s[i].read();
    }
    // give column lines to give a table look
    cout << setfill('-') << setw(52) << "-" << endl;
    cout << setfill(' ');
    cout << setw(20) << left << "Name" << setw(10) << right << "Total" << setw(12) << "Percentage" << setw(10) << "Grade" << endl;
    cout << setfill('-') << setw(52) << "-" << endl;
    cout << setfill(' ');
    for (int i = 0; i < n; i++) {
        s[i].display();
    }
    cout << setfill('-') << setw(52) << "-" << endl;
    return 0;
}