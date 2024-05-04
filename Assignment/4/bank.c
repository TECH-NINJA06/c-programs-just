#include <stdio.h>
struct Customer{
    int ac;
    char name[50];
    float bal;
};
int main(){
    int n;
    struct Customer c[200];
    printf("Enter no of customers(max:200): ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter account number , name, and balance: ");
        scanf("%d %s %f",&c[i].ac,&c[i].name,&c[i].bal);
    }
    printf("\nAccount number \t Name\n");
    for(int i=0;i<n;i++){
        if(c[i].bal<500)
            printf("%d\t%s\n",c[i].ac,c[i].name);
    }
    return 0;
}
