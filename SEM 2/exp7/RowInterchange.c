#include <stdio.h>

int main() {
   int r, c, temp;

   printf("Enter the number of rows and columns: ");
   scanf("%d %d", &r, &c);

   float num[r][c];

   printf("\nEnter the Matrix:\n");
   for (int i = 0; i < r; i++) {
       for (int j = 0; j < c; j++) {
           scanf("%f", &num[i][j]);
       }
   }

   // Directly exchange the first two rows
   for (int j = 0; j < c; j++) {
       temp = num[0][j];
       num[0][j] = num[1][j];
       num[1][j] = temp;
   }

   printf("\nResultant Matrix is as follows:\n");
   for (int i = 0; i < r; i++) {
       for (int j = 0; j < c; j++) {
           printf("%.2f ", num[i][j]);
       }
       printf("\n");
   }

   return 0;
}
