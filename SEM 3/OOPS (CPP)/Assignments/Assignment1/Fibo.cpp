#include <iostream>
using namespace std;

int main() {
    int r;
    cout << "\nEnter number of rows: ";
    cin >> r;
    if (r >= 1) {
        for (int i=1; i <= r;i++){
            int a=1, b = 1, temp;
            cout << endl<< a << " ";
            if (i > 1){
                cout<<b<< " ";
            }
            for (int j=3; j<=i;j++) {
                temp=a+b;
                a=b;
                b=temp;
                cout<<temp<<" ";
            }
        }
    }
    else{
        cout<<"\nRows should be atleast greater than or equal to 1";
    }
    return 0;
}
