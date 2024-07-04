#include <stdio.h>
float* pointer(float* a,float* b,float* c);
int main(){
    float A,B,C;
    printf("\nEnter three numbers:");
    scanf("%f %f %f",&A,&B,&C);
    float* max= pointer(&A,&B,&C);
    printf("\nLargest number is: %f",*max);
    return 0;
}
float* pointer(float* a,float* b,float* c){
    if(*a>*b && *a>*c)
        return a;
    else if(*b>*a && *b>*c)
        return b;
    else if(*c>*a && *c>*b)
        return c;
    return a;
}
