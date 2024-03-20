#include <stdio.h>

int recur(int num){
    if(num!=0){
        return (num%10+recur(num/10));
    }
}
int nonrecur(int num){
    int sum=0;
    for(int i=0;i<4;i++){
        sum+=num%10;
        num/=10;
    }
    return sum;
}
int main(){
    int num;
    printf("Enter a 4 digit number:");
    scanf("%d",&num);
    printf("Sum of digits Using recursive function:%d",recur(num));
    printf("\nSum of digits Using non-recursive function:%d",nonrecur(num));
    return 0;
}
