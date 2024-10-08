#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int imag;

public:
    Complex(int r = 0, int i = 0){
        real=r;
        imag=i;
    }
    Complex operator++() {
        ++real;
        ++imag;
    }
    Complex operator++(int) {
        ++real;
        ++imag;
    }
    Complex operator--() {
        --real;
        --imag;
    }
    Complex operator--(int) {
        --real;
        --imag;
    }
    Complex operator+( Complex& temp){
        return Complex(real + temp.real, imag + temp.imag);
    }
    Complex operator*( Complex& temp){
        return Complex(real * temp.real + imag * temp.imag, real * temp.imag + imag * temp.real);
    }
    Complex operator-(int num){
        return Complex(real - num, imag);
    }
    friend ostream& operator<<(ostream& os, Complex& obj) {
        os << obj.real << " + " << obj.imag << "i";
        return os;
    }
    friend istream& operator>>(istream& is, Complex& obj) {
        is >> obj.real >> obj.imag;
        return is;
    }
};

int main() {
    int a,b;
    cout << "Enter values for x (real and imaginary parts): ";
    cin>>a>>b;
    Complex x(a, b),y,z;
    cout << "Enter values for y (real and imaginary parts): ";
    cin>>y;
    cout << "Enter values for z (real and imaginary parts): ";
    cin >> z;
    cout << "Initial values:\n";
    cout << "x: " << x << endl;
    cout << "y: " << y<< endl;
    cout << "z: " << z << endl;
    ++z;
    cout << "z after prefix increment: " << z << endl;
    z++;
    cout << "z after postfix increment: " << z << endl;
    --z;
    cout << "z after prefix decrement: " << z << endl;
    z--;
    cout << "x after postfix decrement: " << z << endl;
    Complex sum = x + y;
    cout << "x+y= " << sum << endl;
    Complex product = x * y;
    cout << "x*y="<<product<<endl;
    Complex diff = y - 5;
    cout << "y - 5: " << diff << endl;
    return 0;
}
