#include<iostream>
using namespace std;

class Vehicle {
    string registrationNumber;

public:
    void getdata() {
        cout << "Enter the vehicle's registration number: " << endl;
        cin >> registrationNumber;
    }
    void display() {
        cout << "Registration Number: " << registrationNumber << endl;
    }
};

class Car : virtual public Vehicle {
    int numberOfDoors;

public:
    void getdata() {
        Vehicle::getdata();
        cout << "Enter the number of doors: " << endl;
        cin >> numberOfDoors;
    }
    void display() {
        Vehicle::display();
        cout << "Number of Doors: " << numberOfDoors << endl;
    }
};

class Truck : virtual public Vehicle {
    double cargoCapacity;

public:
    void getdata() { 
        cout << "Enter the cargo capacity (in tons): " << endl;
        cin >> cargoCapacity;
    }
    void display() {
        Vehicle::display(); 
        cout << "Cargo Capacity: " << cargoCapacity << " tons" << endl;
    }
};

class PickupTruck : public Car, public Truck {
    string bedType;

public:
    void getdata() {
        Vehicle::getdata();
        Car::getdata();   
        Truck::getdata();    
        cout << "Enter the type of bed (e.g., open, closed): " << endl;
        cin >> bedType;
    }
    void display() {
        Vehicle::display();
        Car::display();
        Truck::display(); 
        cout << "Bed Type: " << bedType << endl;
    }
};

int main() {
    PickupTruck myPickup;
    cout << "For Pickup Truck:" << endl;
    myPickup.getdata();
    myPickup.display();
    return 0;
}
