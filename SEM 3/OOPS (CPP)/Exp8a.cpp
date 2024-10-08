//Write a C++ program to implement a function template to swap two elements

#include <iostream>
using namespace std;

template <class T>
class Swap {
    T a, b;
    public:
    Swap(T a, T b) {
        this->a = a;
        this->b = b;
    }
    void swap() {
        T temp = a;
        a = b;
        b = temp;
    }
    void display() {
        cout << "a = " << a << ", b = " << b << endl;
    }
};
int main() {
    Swap<int> s1(10, 20);
    cout<<"Before Swapping"<<endl;
    s1.display();
    s1.swap();
    cout<<"After Swapping"<<endl;
    s1.display();
    cout<<endl;
    Swap<float> s2(10.5, 20.5);
    cout<<"Before Swapping"<<endl;
    s2.display();
    s2.swap();
    cout<<"After Swapping"<<endl;
    s2.display();

    return 0;
}