#include <stdio.h>

int main() {
    int n;
    float fine = 0;
    printf("Number of days the member is late to submit the book: ");
    scanf("%d", &n);

    if (n > 30) {
        printf("\n membership has been cancelled!\n");
        return 0;
    }
    else if (n <= 5)
        fine = n * 0.5;
    else if (n <= 10)
        fine = 5 + (n - 5);
    else
        fine = 10 + (n - 10) * 5;
    printf("Fine: Rs. %.1f\n", fine);
    return 0;
}
