//Write a C++ program to print the following output using ios class member functions(fig-expt4A)
#include <iostream>
using namespace std;

int main() {
    cout.width(10);
    cout.fill('*');
    cout << "Hello" << endl;
    cout.width(10);
    cout.fill('*');
    cout << "World" << endl;
    return 0;
}

