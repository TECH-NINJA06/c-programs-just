#include <iostream>
#include <string>
using namespace std;

class Worker {
protected:
    int workerID;
    string name;
    string address;
    int departmentID;
    int supervisorID;

public:
    Worker(int wID = 0, string n = "", string addr = "", int deptID = 0, int supID = 0)
        : workerID(wID), name(n), address(addr), departmentID(deptID), supervisorID(supID) {}

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
    virtual void printDetails() {
        cout << "Worker ID: " << workerID << ", Name: " << name << ", Supervisor ID: " << supervisorID << endl;
    }
};

class Supervisor : public Worker {
public:
    Supervisor(int wID = 0, string n = "", string addr = "", int deptID = 0)
        : Worker(wID, n, addr, deptID, 0) {}
    void inputDetails(){
        cout << "Enter Supervisor ID: ";
        cin >> workerID;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Department ID: ";
        cin >> departmentID;
    }
    void printDetails(){
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
