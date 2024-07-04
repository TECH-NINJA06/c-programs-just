#include <stdio.h>
struct date{
    int day,month,year;
};
int main(){
    struct date d1,d2;
    printf("Enter first date (DD MM YYYY): ");
    scanf("%d %d %d",&d1.day,&d1.month,&d1.year);
    printf("\nEnter second date (DD MM YYYY): ");
    scanf("%d %d %d",&d2.day,&d2.month,&d2.year);
    if((d1.day==d2.day)&&(d1.month==d2.month)&&(d1.year==d2.year))
        printf("\nEqual");
    else
        printf("\nUnequal");
    return 0;
}
