/*Write a C++ program to create a class template to represent a generic vector. Include the

member functions to perform the following tasks
1. Create the vector
2. To modify the value of a given element
3. To display the vector elements*/

#include<iostream>
using namespace std;

template<class T>
class Vector
{
    T *v;
    int size;
public:
    Vector(int m)
    {
        size = m;
        v = new T[size];
    }
    void modify(int i, T x)
    {
        v[i] = x;
    }
    void display()
    {
        for(int i=0; i<size; i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
};

int main()
{
    Vector<int> v1(5);
    v1.modify(0, 1);
    v1.modify(1, 2);
    v1.modify(2, 3);
    v1.modify(3, 4);
    v1.modify(4, 5);
    v1.display();

    Vector<float> v2(5);
    v2.modify(0, 1.1);
    v2.modify(1, 2.2);
    v2.modify(2, 3.3);
    v2.modify(3, 4.4);
    v2.modify(4, 5.5);
    v2.display();

    Vector<char> v3(5);
    v3.modify(0, 'a');
    v3.modify(1, 'b');
    v3.modify(2, 'c');
    v3.modify(3, 'd');
    v3.modify(4, 'e');
    v3.display();

    return 0;
}