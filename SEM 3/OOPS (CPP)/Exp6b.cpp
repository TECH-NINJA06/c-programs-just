#include <iostream>
using namespace std;

class Shape{
    protected:
    float r,l,b;
    public:
    virtual void area()=0;
    virtual void display(){
        cout<<"Shape Function"<<endl;
    }
};

class Circle:public Shape{
    public:
    void area(){
        cout<<"Enter the radius of the circle: ";
        cin>>r;
        cout<<"Area of the circle is: "<<3.14*r*r<<endl;
    }
};

class Rectangle:public Shape{
    public:
    void area(){
        cout<<"Enter the length and breadth of the rectangle: ";
        cin>>l>>b;
        cout<<"Area of the rectangle is: "<<l*b<<endl;
    }
};

int main(){
    Shape *s;
    Circle c;
    Rectangle r;
    s = &c;
    s->area();
    s->display();
    s = &r;
    s->area();
    s->display();
    return 0;
}