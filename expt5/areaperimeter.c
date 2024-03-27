#include <stdio.h>
#include <math.h>

float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void PA(float a, float b, float c) {
    float s = (a + b + c) / 2.0;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("\nThe Perimeter of triangle is : %.2f units", 2 * s);
    printf("\nThe Area of triangle is : %.2f sq. units", area);
}

int main() {
    float x1, y1, x2, y2, x3, y3;
    printf("Enter x1,y1:");
    scanf("%f %f", &x1, &y1);
    printf("Enter x2,y2:");
    scanf("%f %f", &x2, &y2);
    printf("Enter x3,y3:");
    scanf("%f %f", &x3, &y3);
    float a = distance(x1, y1, x2, y2);
    float b = distance(x2, y2, x3, y3);
    float c = distance(x1, y1, x3, y3);
    PA(a, b, c);
    return 0;
}

