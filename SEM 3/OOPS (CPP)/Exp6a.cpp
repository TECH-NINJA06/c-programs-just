#include <iostream>
using namespace std;

class Staff {
public:
    virtual void work() {
        cout << "Staff is working on general tasks." << endl;
    }

    virtual void getPaid() {
        cout << "Staff receives salary." << endl;
    }
};

class Chef : public Staff {
public:
    void work() {
        cout << "Chef is preparing food." << endl;
    }

    void getPaid() {
        cout << "Chef receives salary and tips." << endl;
    }
};

class Waiter : public Staff {
public:
    void work() {
        cout << "Waiter is serving food to customers." << endl;
    }

    void getPaid() {
        cout << "Waiter receives salary and tips." << endl;
    }
};

int main() {
    Staff *s;
    Chef c;
    Waiter w;
    Staff st;

    s = &c;
    s->work();
    s->getPaid();

    s = &w;
    s->work();
    s->getPaid();

    s = &st;
    s->work();
    s->getPaid();

    return 0;
}
