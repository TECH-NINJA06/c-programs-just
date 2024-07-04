#include <stdio.h>

int main(){
    int r,c;
    printf("Enter size of the 2D array:");
    scanf("%d %d",&r,&c);
    int a[r][c],b[r][c],res[r][c];
    printf("\nEnter array 1:\n");
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    printf("\nEnter array 2:\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&b[i][j]);
            res[i][j]=a[i][j]-b[i][j];
        }
    }
    printf("\Resultant Array:\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            printf("%d\t",res[i][j]);
        printf("\n");
    }
    return 0;
}
