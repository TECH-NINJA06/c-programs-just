#include<iostream>
using namespace std;

class A {
    int a;
public:
    A() {
        cout << "Constructor of A" << endl;
    }
    void getdata() {
        cout << "Enter the value of a" << endl;
        cin >> a;
    }
    void display() {
        cout << "Value of a is " << a << endl;
    }
};

class B : public A {
    int b;
public:
    B() {
        cout << "Constructor of B" << endl;
    }
    void getdata() {
        A::getdata();
        cout << "Enter the value of b" << endl;
        cin >> b;
    }
    void display() {
        A::display();
        cout << "Value of b is " << b << endl;
    }
};

class C : public A {
    int c;  
public:
    C() {
        cout << "Constructor of C" << endl;
    }
    void getdata() {
        A::getdata();
        cout << "Enter the value of c" << endl;
        cin >> c;
    }
    void display() {
        A::display();
        cout << "Value of c is " << c << endl;
    }
};

int main() {
    B b;
    C c;
    cout << "For class B" << endl;
    b.getdata();
    b.display();
    cout << "For class C" << endl;
    c.getdata();
    c.display();
    return 0;
}