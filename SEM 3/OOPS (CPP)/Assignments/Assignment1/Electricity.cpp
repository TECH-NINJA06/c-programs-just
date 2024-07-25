#include <iostream>
#include <iomanip>
using namespace std;

struct user {
    string name;
    unsigned int units;
};

float calc(int info);

int main() {
    int n;
    cout << "\nEnter Number of users: ";
    cin >> n;
    cin.ignore();
    user u[n];
    cout << "\nEnter Details of users";
    for (int i = 0; i < n; i++) {
        cout << "\n\tEnter User's name: ";
        getline(cin, u[i].name);
        cout << "\n\tEnter electricity units consumed: ";
        cin >> u[i].units;
        cin.ignore();
    }

    cout << setw(20) << "Name" << setw(15) << "Bill(in Rs.)" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(20) << u[i].name << setw(15) <<setprecision(3)<<calc(u[i].units) << endl;
    }
    return 0;
}

float calc(int info) {
    float bill;
    if (info <= 100)
        bill = info * 60 / 100;
    else if (info <= 300)
        bill = ((100 * 60) + ((info - 100) * 80)) / 100;
    else
        bill = ((100 * 60) + (200 * 80) + ((info - 300) * 90)) / 100;

    if (bill < 50)
        bill = 50;
    else if (bill > 300)
        bill += (bill * 0.15);

    return bill;
}
