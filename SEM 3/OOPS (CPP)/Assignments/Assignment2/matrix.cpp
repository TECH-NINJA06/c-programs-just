#include <iostream>
using namespace std;

int main() {
    int numRows, numCols;

    cout << "Enter the number of rows: ";
    cin >> numRows;
    cout << "Enter the number of columns: ";
    cin >> numCols;

    int **matrix = new int*[numRows];
    for (int row = 0; row < numRows; ++row) {
        matrix[row] = new int[numCols];
    }

    cout << "Input matrix elements:" << endl;
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            cin >> matrix[row][col];
        }
    }

    cout << "Displaying the matrix:" << endl;
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }

    for (int row = 0; row < numRows; ++row) {
        delete[] matrix[row];
    }
    delete[] matrix;

    return 0;
}
