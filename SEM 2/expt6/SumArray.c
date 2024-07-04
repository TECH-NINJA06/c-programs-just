#include <stdio.h>

int main(){
    float num[10],sum=0;
    printf("Enter 10 Numbers to calculate sum:");
    for(int i=0;i<10;i++){
        scanf("%f",&num[i]);
        sum+=num[i];
    }
    printf("\nSum:%.3f",sum);
    return 0;
}
