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
};

// Derived class Supervisor from Worker
class Supervisor : public Worker {
public:
    // Constructor
    Supervisor(int wID = 0, string n = "", string addr = "", int deptID = 0)
        : Worker(wID, n, addr, deptID, 0) {}

    // Overriding inputDetails to exclude Supervisor ID input
    void inputDetails() override {
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

    // Overriding printDetails for Supervisor
    void printDetails() const override {
        cout << "Supervisor Name: " << name << ", Department ID: " << departmentID << endl;
    }
};

int main() {
    Worker* worker = new Worker();
    worker->inputDetails();
    worker->printDetails();

    Supervisor* supervisor = new Supervisor();
    supervisor->inputDetails();
    supervisor->printDetails();

    delete worker;
    delete supervisor;

    return 0;
}
