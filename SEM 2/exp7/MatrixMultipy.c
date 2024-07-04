#include <stdio.h>

int main(){
    int r,c;
    printf("Enter No. Of rows and columns of matrix:");
    scanf("%d %d",&r,&c);
    float num[r][c],x;
    printf("Enter a number to perform scalar multiplication of the matrix to be entered: ");
    scanf("%f",&x);
    printf("\nEnter the matrix:");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%f",&num[i][j]);
            num[i][j]*=x;
        }
    }
    printf("\nThe Resultant Matrix is as follows:\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%.3f \t",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}
