#include <iostream>
#include <string>
using namespace std;

struct employee {
    string name, address;
    int id;
};

int main() {
    int n, c;
    cout << "\nEnter number of employees: ";
    cin >> n;
    cin.ignore();
    struct employee e[n];
    cout << "\nEnter Employee Data\n";
    for (int i = 0; i < n; i++) {
        cout << "\nEmployee " << i + 1;
        cout << "\n\tEnter Employee name: ";
        getline(cin, e[i].name);
        cout << "\n\tEnter Employee-Id: ";
        cin >> e[i].id;
        cin.ignore();
        cout << "\n\tEnter Employee Address: ";
        getline(cin, e[i].address);
    }

    int flag, se;
    string add;

    do {
        flag = 0;
        cout << "\nOperations Available\n1. Search By Employee Id\n2. Search By Employee Address\n3. Exit\nEnter: ";
        cin >> c;
        cin.ignore();
        switch(c) {
            case 1:
                cout << "\nEnter Employee-Id: ";
                cin >> se;
                for (int i = 0; i < n; i++) {
                    if (e[i].id == se) {
                        cout << "\nEmployee Name: " << e[i].name
                             << "\nEmployee-id: " << e[i].id
                             << "\nEmployee Address: " << e[i].address << endl;
                        flag = 1;
                        break;
                    }
                }
                if (!flag) {
                    cout << "\nEmployee Not Found\n";
                }
                break;
            case 2:
                cout << "\nEnter Employee Address: ";
                getline(cin, add);
                for (int i = 0; i < n; i++) {
                    if (e[i].address == add) {
                        cout << "\nEmployee Name: " << e[i].name
                             << "\nEmployee-id: " << e[i].id
                             << "\nEmployee Address: " << e[i].address << endl;
                        flag = 1;
                        break;
                    }
                }
                if (!flag) {
                    cout << "\nEmployee Not Found\n";
                }
                break;
            case 3:
                cout << "\nExiting the program\n";
                exit(0);
            default:
                cout << "\nInvalid choice\n";
        }
    } while (1);
    return 0;
}
