#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student {
    string name, roll, address, branch;
public:
    // Function to take input from the user
    void add() {
        cout << "Enter name: ";
        cin >> ws;  // To consume any leading whitespace
        getline(cin, name);  // For full name input
        cout << "Enter roll: ";
        getline(cin, roll);
        cout << "Enter address: ";
        getline(cin, address);
        cout << "Enter branch: ";
        getline(cin, branch);
    }

    // Function to display student details
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll: " << roll << endl;
        cout << "Address: " << address << endl;
        cout << "Branch: " << branch << endl;
    }

    // Function to return roll number
    string getRoll() const {
        return roll;
    }

    // Overload >> operator for reading from file
    friend istream& operator>>(istream& in, Student& s) {
        getline(in, s.name);
        getline(in, s.roll);
        getline(in, s.address);
        getline(in, s.branch);
        return in;
    }

    // Overload << operator for writing to file
    friend ostream& operator<<(ostream& out, const Student& s) {
        out << s.name << endl;
        out << s.roll << endl;
        out << s.address << endl;
        out << s.branch << endl;
        return out;
    }
};

// Function to add a student and save to a file
void addStudent() {
    Student s;
    s.add();
    fstream file;
    file.open(s.getRoll() + ".txt", ios::out);  // Create a file named after the roll number
    if (file.is_open()) {
        file << s;  // Write student details to the file
        file.close();
        cout << "Student details added successfully!\n";
    } else {
        cout << "Error opening file for writing!\n";
    }
}

// Function to search for a student by roll number
void searchStudent(const string& roll) {
    Student s;
    fstream file;
    file.open(roll + ".txt", ios::in);  // Open the file with the given roll number
    if (file.is_open()) {
        file >> s;  // Read student details from the file
        s.display();
        file.close();
    } else {
        cout << "No student found with roll number " << roll << "!\n";
    }
}

// Function to update student details
void updateStudent(const string& roll) {
    Student s;
    fstream file;
    file.open(roll + ".txt", ios::in);  // Open the file to check if it exists
    if (file.is_open()) {
        file.close();
        cout << "Enter updated details:\n";
        s.add();  // Get new details from the user

        file.open(roll + ".txt", ios::out);  // Reopen the file in output mode to overwrite
        file << s;  // Write updated details to the file
        file.close();
        cout << "Student details updated successfully!\n";
    } else {
        cout << "No student found with roll number " << roll << "!\n";
    }
}

// Function to display a student's details
void displayStudent(const string& roll) {
    searchStudent(roll);  // Reusing the search function to display student details
}

int main() {
    int choice;
    string roll;

    while (true) {
        cout << "\n1. Add\n2. Search\n3. Update\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                cout << "Enter roll number to search: ";
                cin >> roll;
                searchStudent(roll);
                break;
            case 3:
                cout << "Enter roll number to update: ";
                cin >> roll;
                updateStudent(roll);
                break;
            case 4:
                cout << "Enter roll number to display: ";
                cin >> roll;
                displayStudent(roll);
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
