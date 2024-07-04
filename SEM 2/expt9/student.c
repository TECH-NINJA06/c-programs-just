#include <stdio.h>

struct student {
    char name[50];
    char roll_number[15];
    char dep[10];
    char course[10];
    int year_of_joining;
};

int main() {
    int year_to_find;
    struct student students[5] = {
        {"Mrunal", "23B-CO-036", "CSE", "B.Tech", 2020},
        {"Justin", "23B-CO-035", "ECE", "M.Tech", 2021},
        {"Enosh", "23B-CO-037", "ME", "BE", 2020},
        {"Rahul", "23B-CO-042", "CSE", "ME", 2022},
        {"Parshuram", "23B-CO-024", "CE", "Phd", 2021}
    };

    printf("Enter the year to find students: ");  
    scanf("%d", &year_to_find);

    int num_students = sizeof(students) / sizeof(students[0]);

    printf("Students who joined in year %d:\n", year_to_find);
    for (int i = 0; i < num_students; i++) {
        if (students[i].year_of_joining == year_to_find) {
            printf("%s\n", students[i].name);
        }
    }

    return 0;
}
