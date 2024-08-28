#include<iostream>
using namespace std;

class Person {
    string name;
public:
    void getdata() {
        cout << "Enter the name: " << endl;
        cin >> name;
    }
    void display() {
        cout << "Name: " << name << endl;
    }
};

class Employee : public Person {
    string company;
public:
    void getdata() {
        Person::getdata();
        cout << "Enter the company name: " << endl;
        cin >> company;
    }
    void display() {
        Person::display();
        cout << "Company: " << company << endl;
    }
};

class Student : public Person {
    string university;
public:
    void getdata() {
        Person::getdata();
        cout << "Enter the university name: " << endl;
        cin >> university;
    }
    void display() {
        Person::display();
        cout << "University: " << university << endl;
    }
};

int main() {
    Employee e;
    Student s;
  
    cout << "For Employee:" << endl;
    e.getdata();
    e.display();
    
    cout << "For Student:" << endl;
    s.getdata();
    s.display();
    
    return 0;
}
