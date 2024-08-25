#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
int isFull() { return (front == (rear + 1) % MAX); }
int isEmpty(){return (front == -1);}
void Insert(int value) {
    if (isFull()) {
        printf("Queue is Full\n");
        return;
    }
    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("%d enqueued\n", value);
}

void Del() {
    if (isEmpty()) {
        printf("Empty Queue\n");
        return;
    }
    int value = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
    printf("%d dequeued\n", value);
}
void display() {
    if (isEmpty()) {
        printf("Empty Queue\n");
        return;
    }

    // Display the front and rear indices
    printf("Front = %d   Rear = %d\n", front, rear);

    // Display the indices of the queue elements
    for (int i = 0; i < MAX; i++) {
        printf("[%-3d]", i);
    }
    printf("\n");

    // Display the upper boundary of the array slots
    for (int i = 0; i < MAX; i++) {
        printf(" %-3s ", "___");
    }
    printf("\n");

    // Display the queue elements or empty slots
    for (int i = 0; i < MAX; i++) {
        if ((front <= rear && i >= front && i <= rear) || (front > rear && (i >= front || i <= rear)))
            printf("| %-3d", queue[i]);
        else
            printf("| %-3s", " ");
    }
    printf("|\n");

    // Display the lower boundary of the array slots
    for (int i = 0; i < MAX; i++) {
        printf(" %-3s ", "---");
    }
    printf("\n");
}
int main() {
    Del();display();Insert(13);display();Insert(86);display();Insert(109);display();Insert(68);display();Del();display();Del();display();Insert(100);display();Insert(11);display();Insert(89);display();Del();display();Del();display();Del();display();
    return 0;
}
