#include <stdio.h>

int main() {
    float num1 = 10.5;
    float *ptr1 = &num1;
    float num2 = 5.5;
    float *ptr2 = &num2;

    (*ptr1)++;
    printf("After increment, *ptr1 = %.2f\n", *ptr1);

    (*ptr1)--;
    printf("After decrement, *ptr1 = %.2f\n", *ptr1);

    *ptr1 += 5;
        printf("After addition, *ptr1 = %.2f\n", *ptr1);

    *ptr1 -= 8;
    printf("After subtraction, *ptr1 = %.2f\n", *ptr1);

    if (*ptr1 == *ptr2) {
        printf("%.2f is equal to %.2f\n",*ptr1,*ptr2);
    } else {
        printf("%.2f is not equal to %.2f\n",*ptr1,*ptr2);
    }

    return 0;
}
