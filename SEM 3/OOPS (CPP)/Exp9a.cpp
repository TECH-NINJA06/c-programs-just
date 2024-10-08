/*Write a C++ program to implement exceptional handling concept (Divide by zero) using
exception rethrow mechanism*/
#include<iostream>
using namespace std;

int main()
{
    int a, b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    try
    {
        if(b==0)
            throw b;
        cout<<"Result: "<<a/b<<endl;
    }
    catch(int x)
    {
        cout<<"Exception: Division by zero"<<endl;
        throw;
    }
    return 0;
}