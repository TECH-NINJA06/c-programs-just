#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    int m[n][n],temp;
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }

    cout << "Original matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nMatrix After Diagonals Interchanged:\n";
    for(int i=0;i<n;i++){
        temp=m[i][i];
        m[i][i]=m[i][n-i-1];
        m[i][n-i-1]=temp;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}

