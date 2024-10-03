/*Write a C++ program to format the following o/p using manipulators(fig-expt4C), do something unique, dont copy code of Exp7d.cpp*/
//dont copy Exp7b.cpp
//maybe do program on result of marksheet,using class, array of objects (students), and display result dashboard in tabular format
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
    public:
        string name;
        int marks[5];
        int total;
        float percentage;
        char grade;
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
};

int main() {
    int n;
    cout<<"Enter number of students: ";
    cin>>n;
    Student students[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> students[i].name;
        cout << "Enter marks of student " << i + 1 << " in 5 subjects: ";
        for (int j = 0; j < 5; j++) {
            cin >> students[i].marks[j];
        }
        students[i].calculate();
    }
    cout << left << setw(20) << "Name" << setw(10) << "Total" << setw(15) << "Percentage" << setw(10) << "Grade" << endl;
    for (int i = 0; i < n; i++) {
        cout << left << setw(20) << students[i].name << setw(10) << students[i].total << setw(15) << students[i].percentage << setw(10) << students[i].grade << endl;
    }
    return 0;
}