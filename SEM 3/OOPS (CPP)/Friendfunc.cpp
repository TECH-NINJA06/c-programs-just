#include <iostream>
using namespace std;

class temp2;
class temp1 {
    int a;
public:
    inline void setval(int &x) { a = x; }
    friend int result(temp1, temp2);
    int getval() { return a; }
};
class temp2 {
    int a;
public:
    inline void setval(int &y) { a = y; }
    friend int result(temp1, temp2);
    int getval() { return a; }
};
int result(temp1 t1, temp2 t2) {
    return (t1.a - t2.a);
}
void swapp(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void swapp(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}
int main() {
    int x, y, z;
    temp1 m;
    temp2 n;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    m.setval(x);
    n.setval(y);
    cout << "Before swap:\nx = " << m.getval() << ", y = " << n.getval() << endl;
    swapp(x, y);
    m.setval(x);
    n.setval(y);
    cout << "After swapping two numbers:\nx = " << m.getval() << ", y = " << n.getval() << endl;
    cout << "Result after swapping two numbers (x - y): " << result(m, n) << endl;
    cout << "Enter a third number for swapping three numbers: ";
    cin >> z;
    cout << "Before swapping three numbers:\nx = " << x << ", y = " << y << ", z = " << z << endl;
    swapp(x, y, z);
    cout << "After swapping three numbers:\nx = " << x << ", y = " << y << ", z = " << z << endl;
    return 0;
}
