#include <stdio.h>

void leap(int year){
    if(year%4==0)
        printf("\n%d is a leap year",year);
    else
        printf("\n%d is not a leap year",year);
    return;
}

int main(){
    int y;
    printf("Enter the year:");
    scanf("%d",&y);
    leap(y);
    return 0;
}
