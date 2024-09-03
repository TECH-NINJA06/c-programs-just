/*create a base class grandfather, create a derived class called father,which inheris properties , extend functionalities to multivevel by creting derived class from father class, Demonstrate multilevel inheritance*/
#include<iostream>
using namespace std;

class Grandfather {
protected:
    string surname;
public:
    void setSurname(string s) {
        surname = s;
    }
    void display() {
        cout << "Grandfather, Surname: " << surname << endl;
    }
};

class Parent : public Grandfather {
protected:
    string occupation;
public:
    void setOccupation(string o) {
        occupation = o;
    }
    void display() {
        cout << "Parent, Occupation: " << occupation << ", Surname: " << surname << endl;
    }
};

class Child : public Parent {
protected:
    int age;
public:
    void setAge(int a) {
        age = a;
    }
    void display() {
        cout << "Child, Age: " << age << ", Surname: " << surname << ", Parent's Occupation: " << occupation << endl;
    }
};

int main() {
    Child c;
    string surname, occupation;
    int age;

    cout << "Enter surname: ";
    cin >> surname;
    cout << "Enter occupation: ";
    cin >> occupation;
    cout << "Enter age: ";
    cin >> age;

    c.setSurname(surname);
    c.setOccupation(occupation);
    c.setAge(age);

    cout << "\nDisplaying information from Child class:" << endl;
    c.display();
    cout << "\nDisplaying information from Father class:" << endl;
    c.Parent::display();
    cout << "\nDisplaying information from Grandfather class:" << endl;
    c.Grandfather::display();

    return 0;
}