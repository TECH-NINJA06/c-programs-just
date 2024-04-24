#include <stdio.h>
int compare(float* a, float* b, int n);
int main(){
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    float a[n],b[n];
    printf("Enter array 1:");
    for(int i=0;i<n;i++){
        scanf("%f",&a[i]);
    }
    printf("\nEnter array 2:");
    for(int i=0;i<n;i++){
        scanf("%f",&b[i]);
    }
    if(compare(a,b,n)){
        printf("\nBoth arrays are identical");
    }
    else
        printf("\nBoth arrays are not identical");
    return 0;
}
int compare(float* a, float* b, int n){
    for(int i=0;i<n;i++){
        if(*(a+i)!= *(b+i))
            return 0;
    }
    return 1;
}
