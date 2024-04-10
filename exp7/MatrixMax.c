#include <stdio.h>

int main(){
    int r,c;
    printf("Enter no of rows and columns:");
    scanf("%d %d",&r,&c);
    float num[r][c],max;
    printf("Enter the matrix:");

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%f",&num[i][j]);
        }
    }
    printf("\nMax Values of each row in the matrix is as follows:\n");
    for(int i=0;i<r;i++){
        max=num[i][0];
        for(int j=0;j<c;j++){
            if(num[i][j]>max)
                max=num[i][j];
        }
        printf("\tRow %d : %.2f \n",i+1,max);
    }
    printf("\nMax Values of each column in the matrix is as follows:\n");
    for(int j=0;j<c;j++){
        max=num[0][j];
        for(int i=0;i<r;i++){
            if(num[i][j]>max)
                max=num[i][j];
        }
        printf("\tColumn %d : %.2f \n",j+1,max);
    }
    return 0;
}
