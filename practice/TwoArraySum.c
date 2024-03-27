#include <stdio.h>

int main(){
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    int a[n],b[n],c[n];
    printf("\nEnter Array 1 :");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nEnter Array 2 :");
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
        c[i]=a[i]+b[i];
    }
    printf("\nResultant Sum of two Arrays: ");
    for(int i=0;i<n;i++){
        printf("%d ",c[i]);
    }
    return 0;
}
