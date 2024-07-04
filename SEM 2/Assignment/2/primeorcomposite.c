#include <stdio.h>

int main(){
    int num,flag;
    printf("Enter a number to check if prime or composite:");
    scanf("%d",&num);
    for(int i = 2; i <= num / 2; ++i) {
        if(num % i == 0) {
            flag = 0;
            break;
        }
    }
    if(flag)
        printf("\n%d is a prime number",num);
    else
        printf("\n%d is a composite number",num);
    return 0;
}
