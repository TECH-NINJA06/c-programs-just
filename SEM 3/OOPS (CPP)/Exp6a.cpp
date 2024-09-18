//Write a C++ program to understand virtual functions in C++ using an example unqiue good , real world. dont do a simple base derived exa mple.
#include <iostream>
using namespace std;

class Parent{
    public:
    virtual void display(){
        cout<<"Parent Function"<<endl;
    }
};

class Child:public Parent{
    public:
    void display(){
        cout<<"Child Function"<<endl;
    }
};

int main(){
    Parent *p;
    Parent b;
    Child c;
    p = &c;
    p->display();
    p=&b;
    p->display();
    return 0;
}