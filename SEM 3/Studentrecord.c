#include <stdio.h>
#include <string.h>

struct name {
    char first[20];
    char sec[20];
    char last[20];
};

struct subject {
    char subcode[10];
    int marks;
    char grade[2];
};

struct semester {
    int currSem;
    struct subject subjects[4];
    float SGPA;
};

struct student {
    int roll_no;
    struct name fullname;
    struct semester sem[2];
    float CGPA;
};

char calculateGrade(int marks) {
    if (marks >= 85) {
        return 'O';
    } else if (marks >= 75) {
        return 'A';
    } else if (marks >= 65) {
        return 'B';
    } else if (marks >= 55) {
        return 'C';
    } else if (marks >= 45) {
        return 'D';
    } else {
        return 'F';
    }
}

float calculateSGPA(struct semester *sem) {
    int total_marks = 0;
    for (int i = 0; i < 4; i++) {
        total_marks += sem->subjects[i].marks;
    }
    return total_marks / 40.0; // Assuming each subject has equal weightage and out of 100
}

float calculateCGPA(struct student *student) {
    float totalSGPA = 0;
    for (int i = 0; i < 2; i++) {
        totalSGPA += student->sem[i].SGPA;
    }
    return totalSGPA / 2.0;
}

int main() {
    struct student student1;
    printf("Enter student's first name: ");
    scanf("%19s", student1.fullname.first);
    printf("Enter student's second name: ");
    scanf("%19s", student1.fullname.sec);
    printf("Enter student's last name: ");
    scanf("%19s", student1.fullname.last);

    printf("Enter student's roll number: ");
    scanf("%d", &student1.roll_no);

    for (int sem = 0; sem < 2; sem++) {
        printf("Enter subjects and marks for semester %d\n", sem + 1);
        for (int i = 0; i < 4; i++) {
            printf("Enter subject %d code: ", i + 1);
            scanf("%9s", student1.sem[sem].subjects[i].subcode);
            printf("Enter subject %d marks: ", i + 1);
            scanf("%d", &student1.sem[sem].subjects[i].marks);
            student1.sem[sem].subjects[i].grade[0] = calculateGrade(student1.sem[sem].subjects[i].marks);
            student1.sem[sem].subjects[i].grade[1] = '\0';
        }
        student1.sem[sem].SGPA = calculateSGPA(&student1.sem[sem]);
    }

    student1.CGPA = calculateCGPA(&student1);

    printf("\nStudent Information:\n");
    printf("Name: %s %s %s\n", student1.fullname.first, student1.fullname.sec, student1.fullname.last);
    printf("Roll No: %d\n", student1.roll_no);

    for (int sem = 0; sem < 2; sem++) {
        printf("\nSemester %d:\n", sem + 1);
        printf("%-15s%-10s%-10s\n", "Subject Code", "Marks", "Grade");
        printf("---------------------------------\n");
        for (int i = 0; i < 4; i++) {
            printf("%-15s%-10d%-10s\n", student1.sem[sem].subjects[i].subcode, student1.sem[sem].subjects[i].marks, student1.sem[sem].subjects[i].grade);
        }
        printf("SGPA: %.2f\n", student1.sem[sem].SGPA);
    }

    printf("\nCGPA: %.2f\n", student1.CGPA);

    return 0;
}
