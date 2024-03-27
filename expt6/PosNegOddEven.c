#include <stdio.h>

int main(){
    int num[10],pos=0,neg=0,odd=0,even=0;
    printf("Enter 10 Integers: ");
    for(int i=0;i<10;i++){
        scanf("%d",&num[i]);
        if(num[i]%2==0){
            even++;
            if(num[i]<0)
                neg++;
            else if(num[i]>0)
                pos++;
        }
        else{
            odd++;
            if(num[i]<0)
                neg++;
            else if(num[i]>0)
                pos++;
        }
    }
    printf("\nPositive Numbers:%d\nNegative Numbers:%d\nEven Numbers:%d\nOdd Numbers:%d",pos,neg,even,odd);
    return 0;

}
