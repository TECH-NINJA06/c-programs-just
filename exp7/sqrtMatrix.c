#include <stdio.h>

int main(){
    int r,c;
    printf("Enter no of rows and columns of matrix:");
    scanf("%d %d",&r,&c);
    float num[r][c];
    printf("\nEnter Matrix:\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%f",&num[i][j]);
            num[i][j]=sqrt(num[i][j]);
        }
    }
    printf("\nThe Resultant Matrix is as folows:\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%.2f \t",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}
