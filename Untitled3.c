#include <stdio.h>

float bill(int u){
    float bill;
    if(u>250){
        bill=((u-250)*1.5)+(100*1.2)+(100*0.75)+(50*0.5);
    }
    else if(u>150){
        bill=((u-150)*1.2)+(100*0.75)+(50*0.5);
    }
    else if(u>50){
        bill=((u-50)*0.75)+(50*0.5);
    }
    else
        bill=u*0.5;
    bill*=1.2;
    return bill;
}
int main(){
    int unit;
    printf("Enter Electricity unit charge :");
    scanf("%d",&unit);
    printf("\nThe Electricity bill is Rs. %f",bill(unit));
    return 0;
}
