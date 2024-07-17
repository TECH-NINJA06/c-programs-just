#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NUM_SUBJECTS 4

struct name {
    char first[20];
    char sec[20];
    char last[20];
};

struct subject {
    char subcode[10];
    int marks;
    char grade[2];
    int credits;
};

struct semester {
    int currSem;
    struct subject subjects[NUM_SUBJECTS];
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

int gradeToPoints(char grade) {
    switch (grade) {
        case 'O': return 10;
        case 'A': return 9;
        case 'B': return 8;
        case 'C': return 7;
        case 'D': return 6;
        case 'F': return 0;
        default: return 0;
    }
}

float calculateSGPA(struct semester *sem) {
    int totalCredits = 0;
    int totalPoints = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        int gradePoints = gradeToPoints(sem->subjects[i].grade[0]);
        totalPoints += gradePoints * sem->subjects[i].credits;
        totalCredits += sem->subjects[i].credits;
    }
    return (float) totalPoints / totalCredits;
}

float calculateCGPA(struct student *student) {
    float totalSGPA = 0;
    for (int i = 0; i < 2; i++) {
        totalSGPA += student->sem[i].SGPA;
    }
    return totalSGPA / 2.0;
}

void inputStudentData(struct student *student) {
    printf("Enter student's first name: ");
    scanf("%19s", student->fullname.first);
    printf("Enter student's second name: ");
    scanf("%19s", student->fullname.sec);
    printf("Enter student's last name: ");
    scanf("%19s", student->fullname.last);

    printf("Enter student's roll number: ");
    scanf("%d", &student->roll_no);

    for (int sem = 0; sem < 2; sem++) {
        printf("Enter subjects and marks for semester %d\n", sem + 1);
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            printf("Enter subject %d code: ", i + 1);
            scanf("%9s", student->sem[sem].subjects[i].subcode);
            printf("Enter subject %d marks: ", i + 1);
            scanf("%d", &student->sem[sem].subjects[i].marks);
            printf("Enter subject %d credits: ", i + 1);
            scanf("%d", &student->sem[sem].subjects[i].credits);
            student->sem[sem].subjects[i].grade[0] = calculateGrade(student->sem[sem].subjects[i].marks);
            student->sem[sem].subjects[i].grade[1] = '\0';
        }
        student->sem[sem].SGPA = calculateSGPA(&student->sem[sem]);
    }

    student->CGPA = calculateCGPA(student);
}

void displayStudentData(struct student *student) {
    printf("\nStudent Information:\n");
    printf("Name: %s %s %s\n", student->fullname.first, student->fullname.sec, student->fullname.last);
    printf("Roll No: %d\n", student->roll_no);

    for (int sem = 0; sem < 2; sem++) {
        printf("\nSemester %d:\n", sem + 1);
        printf("%-15s%-10s%-10s%-10s\n", "Subject Code", "Marks", "Grade", "Credits");
        printf("-----------------------------------------\n");
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            printf("%-15s%-10d%-10s%-10d\n", student->sem[sem].subjects[i].subcode, student->sem[sem].subjects[i].marks, student->sem[sem].subjects[i].grade, student->sem[sem].subjects[i].credits);
        }
        printf("SGPA: %.2f\n", student->sem[sem].SGPA);
    }

    printf("\nCGPA: %.2f\n", student->CGPA);
}

int findStudentIndex(struct student students[], int num_students, int roll_no) {
    for (int i = 0; i < num_students; i++) {
        if (students[i].roll_no == roll_no) {
            return i;
        }
    }
    return -1;
}

void updateStudentData(struct student *student) {
    printf("Updating student data for roll no %d\n", student->roll_no);
    inputStudentData(student);
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add student data\n");
    printf("2. Display all students\n");
    printf("3. Search for a student by roll number\n");
    printf("4. Update student data\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct student students[MAX_STUDENTS];
    int num_students = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_students < MAX_STUDENTS) {
                    inputStudentData(&students[num_students]);
                    num_students++;
                } else {
                    printf("Maximum number of students reached.\n");
                }
                break;
            case 2:
                for (int i = 0; i < num_students; i++) {
                    displayStudentData(&students[i]);
                }
                break;
            case 3:
                printf("Enter roll number to search: ");
                int roll_no;
                scanf("%d", &roll_no);
                int index = findStudentIndex(students, num_students, roll_no);
                if (index != -1) {
                    displayStudentData(&students[index]);
                } else {
                    printf("Student with roll number %d not found.\n", roll_no);
                }
                break;
            case 4:
                printf("Enter roll number to update: ");
                scanf("%d", &roll_no);
                index = findStudentIndex(students, num_students, roll_no);
                if (index != -1) {
                    updateStudentData(&students[index]);
                } else {
                    printf("Student with roll number %d not found.\n", roll_no);
                }
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
