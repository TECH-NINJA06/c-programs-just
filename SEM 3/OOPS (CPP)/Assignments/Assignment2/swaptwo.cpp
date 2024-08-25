#include <iostream>
using namespace std;

void swapp(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int m,n;
    printf("Enter two numbers:");
    scanf("%d %d",&m,&n);
    cout << "Before swap:" << endl;
    cout << "m = " << m << ", n = " << n << endl;
    swapp(m, n);
    cout << "After swap:" << endl;
    cout << "m = " << m << ", n = " << n << endl;

    return 0;
}
