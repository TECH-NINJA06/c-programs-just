#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string name;
    int rollNo;
    int marks;
};

// Function to create a result file for a student
void createResult() {
    Student student;
    cout << "Enter Student Name: ";
    cin >> student.name;
    cout << "Enter Roll Number: ";
    cin >> student.rollNo;
    cout << "Enter Marks: ";
    cin >> student.marks;

    string filename = to_string(student.rollNo) + ".txt";
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << "Name: " << student.name << endl;
        outFile << "Roll No: " << student.rollNo << endl;
        outFile << "Marks: " << student.marks << endl;
        outFile.close();
        cout << "Result file created for student " << student.name << " (Roll No: " << student.rollNo << ").\n";
    } else {
        cout << "Unable to create result file.\n";
    }
}

// Function to display the content of a result file
void displayResult(int rollNo) {
    string filename = to_string(rollNo) + ".txt";
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        cout << "Displaying result for Roll No: " << rollNo << endl;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Result file not found for Roll No: " << rollNo << endl;
    }
}

// Function to edit marks in a result file
void editMarks(int rollNo) {
    string filename = to_string(rollNo) + ".txt";
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string name, dummy;
        int marks, newMarks;
        inFile >> dummy >> name >> dummy >> rollNo >> dummy >> marks;
        inFile.close();

        cout << "Current marks for " << name << " (Roll No: " << rollNo << ") are: " << marks << endl;
        cout << "Enter new marks: ";
        cin >> newMarks;

        ofstream outFile(filename);
        outFile << "Name: " << name << endl;
        outFile << "Roll No: " << rollNo << endl;
        outFile << "Marks: " << newMarks << endl;
        outFile.close();

        cout << "Marks updated successfully.\n";
        displayResult(rollNo);
    } else {
        cout << "Result file not found for Roll No: " << rollNo << endl;
    }
}

// Function to append branch to a result file
void appendBranch(int rollNo) {
    string filename = to_string(rollNo) + ".txt";
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string branch;
        cout << "Enter branch to append: ";
        cin >> branch;

        ofstream outFile(filename, ios::app);
        outFile << "Branch: " << branch << endl;
        outFile.close();

        cout << "Branch appended successfully.\n";
        displayResult(rollNo);
    } else {
        cout << "Result file not found for Roll No: " << rollNo << endl;
    }
}

// Main function with menu-driven options
int main() {
    int choice, rollNo;
    do {
        cout << "\n1. Enter result details and display\n";
        cout << "2. Edit marks of a student\n";
        cout << "3. Append branch to a result file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createResult();
                break;
            case 2:
                cout << "Enter Roll Number to edit marks: ";
                cin >> rollNo;
                editMarks(rollNo);
                break;
            case 3:
                cout << "Enter Roll Number to append branch: ";
                cin >> rollNo;
                appendBranch(rollNo);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
