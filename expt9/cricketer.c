#include <stdio.h>

struct cricketer {
    char name[50];
    int age;
    float no_of_matches;
    int total_runs;
    float avg_runs;
};

int main() {
    struct cricketer v1 = {"Virat Kohli", 34, 100, 4800, 0};
    v1.avg_runs = v1.total_runs/v1.no_of_matches;
    printf("Name: %s\n", v1.name);
    printf("Age: %d\n", v1.age);
    printf("Matches Played: %d\n", v1.no_of_matches);
    printf("Average Runs: %.2f\n", v1.avg_runs);

    return 0;
}
