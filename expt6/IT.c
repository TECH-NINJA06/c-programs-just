#include <stdio.h>

int main() {
    int marks_IT1[10];
    int marks_IT2[10];
    float average_mark[10];

    printf("Enter IT1 marks of 10 students:\n");
    for (int i = 0; i < 10; i++) {
        printf("Enter marks for student %d: ", i + 1);
        scanf("%d", &marks_IT1[i]);
    }
    printf("Enter IT2 marks of 10 students:\n");
    for (int i = 0; i < 10; i++) {
        printf("Enter marks for student %d: ", i + 1);
        scanf("%d", &marks_IT2[i]);
    }

    for (int i = 0; i < 10; i++) {
        average_mark[i] = (marks_IT1[i] + marks_IT2[i]) / 2.0;
    }

    printf("\nAverage marks of 10 students:\n");
    for (int i = 0; i < 10; i++) {
        printf("Student %d: %.2f\n", i + 1, average_mark[i]);
    }

    return 0;
}
