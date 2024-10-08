#include <iostream>
#include <string>

using namespace std;

// Base class Worker
class Worker {
protected:
    int workerID;
    string name;
    string address;
    int departmentID;
    int supervisorID;

public:
    // Constructor
    Worker(int wID = 0, string n = "", string addr = "", int deptID = 0, int supID = 0)
        : workerID(wID), name(n), address(addr), departmentID(deptID), supervisorID(supID) {}

    // Function to input data
    virtual void inputDetails() {
        cout << "Enter Worker ID: ";
        cin >> workerID;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Department ID: ";
        cin >> departmentID;
        cout << "Enter Supervisor ID: ";
        cin >> supervisorID;
    }

    // Polymorphic function to print details
    virtual void printDetails() const {
        cout << "Worker ID: " << workerID << ", Name: " << name << ", Supervisor ID: " << supervisorID << endl;
    }

    // Function to swap data of two objects
    void swapData(Worker* other) {
        Worker temp = *this;
        *this = *other;
        *other = temp;
    }
};

// Derived class Supervisor from Worker
class Supervisor : public Worker {
public:
    // Constructor
    Supervisor(int wID = 0, string n = "", string addr = "", int deptID = 0)
        : Worker(wID, n, addr, deptID, 0) {}

    // Polymorphic inputDetails function for Supervisor (no `override` keyword)
    void inputDetails() {
        cout << "Enter Supervisor ID: ";
        cin >> workerID;  // Reusing workerID as Supervisor ID
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Department ID: ";
        cin >> departmentID;
        // Supervisor ID is not needed for supervisors themselves
    }

    // Polymorphic printDetails function for Supervisor (no `override` keyword)
    void printDetails() const {
        cout << "Supervisor Name: " << name << ", Department ID: " << departmentID << endl;
    }
};

int main() {
    Worker* worker1 = new Worker();
    worker1->inputDetails();
    worker1->printDetails();

    Worker* worker2 = new Worker();
    worker2->inputDetails();
    worker2->printDetails();

    worker1->swapData(worker2);

    cout << "After swapping:" << endl;
    worker1->printDetails();
    worker2->printDetails();

    delete worker1;
    delete worker2;

    return 0;
}
