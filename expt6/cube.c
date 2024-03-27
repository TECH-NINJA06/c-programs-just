#include <stdio.h>
#include <math.h>
void cube();
int main(){
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    int num[n];
    printf("\nEnter:");
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    cube(n,num);
    return 0;
}
void cube(int n,int num[]){
    for(int i=0;i<n;i++){
        num[i]=pow(num[i],3);
    }
    printf("\nResultant Array:");
    for(int i=0;i<n;i++){
        printf("%d ",num[i]);
    }
}
