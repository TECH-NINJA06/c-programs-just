#include <iostream>
#include <math.h>
using namespace std;

double calcFactorial(int k) {
    if (k == 0 || k == 1) {
        return 1.0;
    }
    double result = 1.0;
    for (int i = 2; i <= k; ++i) {
        result *= i;
    }
    return result;
}

double computeSine(double angle, double tol) {
    double term = angle;
    double total = term;
    int index = 1;

    while (abs(term) >= tol) {
        index += 2;
        term *= -angle * angle / ((index - 1) * index);
        total += term;
    }
    return total;
}

double computeSeriesSum(int terms) {
    double total = 0.0;
    for (int i = 1; i <= terms; ++i) {
        total += 1.0 / pow(i, i);
    }
    return total;
}

int main() {
    double angle;
    int terms;
    cout << "Enter the value of x in radians: ";
    cin >> angle;
    double tol = 0.0001;
    double sinApprox = computeSine(angle, tol);
    cout << "Approximated sin(" << angle << ") = " << sinApprox << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Enter the number of terms (n) for the series: ";
    cin >> terms;
    double seriesSum = computeSeriesSum(terms);
    cout << "Sum of the series 1 + (1/2)^2 + (1/3)^3 + ... up to " << terms << " terms is: " << seriesSum << endl;

    return 0;
}
