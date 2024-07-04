#include <stdio.h>

int main () {
    int arr[5];
    int rev_arr[5];
    int temp;

    printf("Enter the array elements:\n");
    for (int i = 0; i < 5; i++) {
        printf("Enter  %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 5; i++) {
        rev_arr[i] = arr[4 - i];
    }

    for (int i = 0; i < 5/2; i++) {
        temp=arr[i];
        arr[i]=arr[4-i];
        arr[4-i]=temp;
    }

    printf("\nThe reversed array without new array is:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nThe reversed array is:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", rev_arr[i]);
    }
    
    return 0;
}
