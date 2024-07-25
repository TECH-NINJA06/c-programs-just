#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isFull() {
    return (front == (rear + 1) % MAX);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = value;
    printf("%d enqueued to queue\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    int value = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    printf("%d dequeued from queue\n", value);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    printf("Queue: ");
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int c,item;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter:");
        scanf("%d",&c);
        switch(c){
        case 1:
            printf("\nEnter info:");
            scanf("%d",&item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Option\n");
        }
    }
    return 0;
}
