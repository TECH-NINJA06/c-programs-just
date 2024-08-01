#include <iostream>
using namespace std;

class temp {
    int x, y;
public:
    temp(int &a, int &b) {
        x = a;
        y = b;
    }
    temp(temp &t) {
        x = t.y;
        y = t.x;
    }
    ~temp() {
        cout << "\nDestructor called" << endl;
    }
    void display() {
        cout << "x = " << x << " y = " << y << endl;
    }
};

int main() {
    int x,y;
    cout<<"Enter two numbers:";
    cin>>x>>y;
    temp m(x,y);
    cout<<"\nBefore Swap\n\t";
    m.display();
    temp n(m);
    cout<<"\nAfter Swap\n\t";
    n.display();
    return 0;
}
