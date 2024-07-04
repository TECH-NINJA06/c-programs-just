#include <stdio.h>
#include <math.h>
int main(){
    double arr[5] = {1.5, 2.7, 3.9, 4.1, 5.3};
    double *ptr[5];
    for(int i = 0; i < 5; i++) {
        ptr[i] = &arr[i];
        *ptr[i]=pow(*ptr[i],2);
    }
    printf("\nResultant squared array:");
    for(int i=0;i<5;i++)
        printf(" %.2f",*ptr[i]);
    return 0;
}
