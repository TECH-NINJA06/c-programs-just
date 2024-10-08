//Write a C++ program to implement a multi catch exception handling mechanism
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
    }
    catch(...)
    {
        cout<<"Exception: Unknown"<<endl;
    }
    return 0;
}