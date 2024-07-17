#include <iostream>
#include <iomanip>
using namespace std;

class student {
private:
    string name;
    int marks[4];
    float p;

    void calculate() {
        p = 0;
        for (int i = 0; i < 4; ++i) {
            p += marks[i];
        }
        p /= 4;
    }

public:
    void get_data() {
        cout << "\n\tEnter Full name: ";
        cin.ignore();
        getline(cin, name);
        cout << "\n\tEnter marks of 4 subjects: ";
        for (int i = 0; i < 4; ++i) {
            cin >> marks[i];
        }
        calculate();
    }

    void display() {
        cout << left << setw(20) << name << right << setw(10) << fixed << setprecision(2) << p << "\n";
    }
};

int main() {
    int n;
    cout << "\nEnter number of students: ";
    cin >> n;
    student* s = new student[n];
    cout << "\nEnter details of " << n << " students below\n";
    for (int i = 0; i < n; ++i) {
        s[i].get_data();
    }
    cout << "\nThe Student Result is as follows:\n";
    cout << left << setw(20) << "Name" << right << setw(10) << "Percentage(%)\n";
    for (int i = 0; i < n; ++i) {
        s[i].display();
    }
    return 0;
}
