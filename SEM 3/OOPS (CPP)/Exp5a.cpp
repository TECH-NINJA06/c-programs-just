
#include <iostream>
#include <iomanip>
using namespace std;

class Department{
protected:
    string name;
public:
    Department(){
        cout << "Enter name of department: ";
        cin >> name;
        cin.ignore();
    }
};

class Faculty : public Department{
protected:
    string faculty_name,designation;
public:
    Faculty(){
        cout << "Enter name of faculty: ";
        getline(cin, faculty_name);
        cin.ignore();
        cout << "Enter designation: ";
        getline(cin, designation);
        cin.ignore();
    }
    void display(){
        cout<<setw(15)<<name<<setw(20)<<faculty_name<<setw(25)<<designation<<endl;
    }
};

class Student : public Department{
protected:
    string student_name;
public:
    Student(){
        cout << "Enter name of student: ";
        cin >> student_name;
    }
    void display(){
        cout<<setw(15)<<name<<setw(15)<<student_name<<endl;
    }
};

int main(){ 
    cout << "Enter number of faculties: ";
    int n;
    cin >> n;
    Faculty *f = new Faculty[n];
    cout << "\n\nEnter number of students: ";
    int m;
    cin >> m;
    Student *s = new Student[m];
    cout << "\n\nFaculty Details:\n";
    cout << setw(15) << "Department" << setw(20) << "Faculty Name" << setw(25) << "Designation" << endl;
    for (int i = 0; i < n; i++) {
        f[i].display();
    }
    cout << "\n\nStudent Details:\n";
    cout << setw(15) << "Department" << setw(15) << "Student Name" << endl;
    for (int i = 0; i < m; i++) {
        s[i].display();
    }
    return 0;
}
