#include <stdio.h>

int main(){
    int n,temp;
    printf("Enter array size:");
    scanf("%d",&n);
    int num[n];
    printf("\n Enter %d numbers into the array: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(int i = 0; i < n/2; ++i) {
        temp = num[i];
        num[i] = num[n-1-i];
        num[n-1-i] = temp;
    }
    printf("The reversed numay is: \n");
    for(int i = 0; i < n; ++i) {
        printf("%d ", num[i]);
    }
    return 0;
}
