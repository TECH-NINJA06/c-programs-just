#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50},sum=0;
    int *ptrArr[5];
    for (int i = 0; i < 5; i++) {
        ptrArr[i] = &arr[i];
    }
    printf("Elements of the array using array of pointers:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nIndex %d: \n\tAddress: %u \n\tValue: %d", i, ptrArr[i], *ptrArr[i]);
        sum+=*ptrArr[i];
    }
    printf("\nSum of values:%d",sum);
    return 0;
}
