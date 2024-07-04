#include <stdio.h>

void swap(float* a, float* b);

int main(){
    float a,b;
    printf("Enter two numbers to swap:");
    scanf("%f %f",&a,&b);
    printf("\n\tBefore Swap: %.2f %.2f",a,b);
    swap(&a,&b);
    printf("\n\tAfter Swap: %.2f %.2f",a,b);
    return 0;
}
void swap(float * a,float * b){
    float t=*a;
    *a=*b;
    *b=t;
}
