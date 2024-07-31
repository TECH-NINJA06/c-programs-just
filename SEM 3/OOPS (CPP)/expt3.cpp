#include <iostream>
using namespace std;

class A {
    int x, y;

public:
    A(int a, int b) {
        x = a;
        y = b;
    }
    A(A &a) {
        x = a.x;
        y = a.y;
    }
    ~A() {
        cout << "Destructor called" << endl;
    }
    void display() {
        cout << "x = " << x << " y = " << y << endl;
    }
};

int main() {
    A a(10, 20);
    A b(a);
    a.display();
    b.display();
    return 0;
}