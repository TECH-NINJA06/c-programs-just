#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    char s;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL, *top = NULL;

void insert(char);
void push(char);
char delete();
char pop();
int isEmpty();
int palindrome();
void display_S();
void display_Q();

int main() {
    char se[50];
    printf("\nEnter sentence: ");
    scanf("%s", se);

    for (int i = 0; i < strlen(se); i++) {
        push(se[i]);
        insert(se[i]);

        printf("\nAfter inserting '%c':\n", se[i]);
        printf("Stack: ");
        display_S();
        printf("Queue: ");
        display_Q();
    }

    if (palindrome())
        printf("\nIt's a palindrome\n");
    else
        printf("\nIt's not a palindrome\n");

    return 0;
}

void insert(char data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Queue Overflow \n");
        return;
    }
    temp->s = data;
    temp->next = NULL;
    if (isEmpty()) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void push(char info) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("\nStack Overflow\n");
        return;
    }
    temp->s = info;
    temp->next = top;
    top = temp;
}

char delete() {
    struct Node *temp;
    char data;
    if (isEmpty()) {
        printf("Queue Underflow \n");
        return '\0';
    }
    temp = front;
    data = temp->s;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return data;
}

char pop() {
    struct Node *temp = top;
    if (top == NULL) {
        printf("\nStack Underflow\n");
        return '\0';
    }
    top = top->next;
    char data = temp->s;
    free(temp);
    return data;
}

int isEmpty() {
    return (front == NULL);
}

void display_S() {
    struct Node *p = top;
    if (top == NULL) {
        printf("Empty");
        return;
    }
    while (p != NULL) {
        printf("|%c|%p|  ->  ", p->s, (void*)p->next);
        p = p->next;
    }
    printf("NULL\n");
}

void display_Q() {
    struct Node *temp = front;
    if (isEmpty()) {
        printf("Empty");
        return;
    }
    while (temp != NULL) {
        printf("|%c|%p|  ->  ", temp->s, (void*)temp->next);
        temp = temp->next;
    }
    printf("NULL\n");
}

int palindrome() {
    struct Node *t1 = top, *t2 = front;
    while (t1 != NULL && t2 != NULL) {
        if (isalpha(t1->s) && isalpha(t2->s)) {
            if (tolower(t1->s) != tolower(t2->s)) {
                return 0;
            }
        } else if (t1->s != t2->s) {
            return 0;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    return (t1 == NULL && t2 == NULL);
}
