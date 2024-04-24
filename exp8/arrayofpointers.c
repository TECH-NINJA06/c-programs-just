#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptrArr[5];
    for (int i = 0; i < 5; i++) {
        ptrArr[i] = &arr[i];
    }
    printf("Elements of the array using array of pointers:\n");
    for (int i = 0; i < 5; i++) {
        printf("Value at index %d: %d\n", i, *ptrArr[i]);
    }
    return 0;
}
