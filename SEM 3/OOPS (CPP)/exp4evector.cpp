#include <iostream>
using namespace std;

class Vector {
private:
    int n;
    int* arr;

public:
    Vector(int size){
        n=size;
        arr = new int[n];
    }

    Vector(const Vector& other){
        n=other.n;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = other.arr[i];
        }
    }
    Vector operator*(int s) const {
        Vector result(n);
        for (int i = 0; i < n; i++) {
            result.arr[i] = arr[i] * s;
        }
        return result;
    }

    Vector operator+(const Vector& temp) const {
        Vector result(n);
        for (int i = 0; i < n; i++) {
            result.arr[i] = arr[i] + temp.arr[i];
        }
        return result;
    }

    friend istream& operator>>(istream& temp, Vector& v) {
        for (int i = 0; i < v.n; i++) {
            temp >> v.arr[i];
        }
        return temp;
    }

    friend ostream& operator<<(ostream& temp, const Vector& v) {
        for (int i = 0; i < v.n; i++) {
            temp << v.arr[i] << " ";
        }
        return temp;
    }
};

int main() {
    int size;

    cout << "Enter the size of the vector: ";
    cin >> size;
    Vector v1(size),v2(size);
    cout << "Enter the elements of the vector: ";
    cin >> v1;
    int s;
    cout << "Enter the scalar value: ";
    cin >> s;
    Vector v1m = v1 * s;
    cout<<"Vector v1 after scalar multiplication : "<<v1m<<endl;

    cout << "Enter the elements of the second vector: ";
    cin >> v2;
    Vector sum = v1m + v2;
    cout << "Result of addition of two vectors v1m + v2: " << sum << endl;
    return 0;
}
