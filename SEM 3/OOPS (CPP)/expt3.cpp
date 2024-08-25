#include <iostream>
using namespace std;

class temp {
    int x, y;
public:
    static int c;

    temp() {
        x = 0;
        y = 0;
        c++;
    }

    temp(int &a, int &b) {
        x = a;
        y = b;
        c++;
    }

    temp(temp &t) {
        x = t.y;
        y = t.x;
        c++;
    }

    ~temp() {
        cout << "\nDestructor called for object " << c << endl;
        c--;
    }

    void display() {
        cout << "x = " << x << " y = " << y << endl;
    }
};
int temp::c = 0;
int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    temp m(x, y);
    cout << "\nBefore Swap\n\t";
    m.display();

    temp n(m);
    cout << "\nAfter Swap\n\t";
    n.display();

    return 0;
}
