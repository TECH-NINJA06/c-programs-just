#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

struct node *createlist(struct node *, int);
struct node *addatbeg(struct node *, int);
struct node *addatend(struct node *, int);
struct node *del(struct node *, int);
void display(struct node *);
struct node *swapAdjacent(struct node *);

int main() {
    int choice, n, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Display Doubly Linked List\n");
        printf("3. Swap Adjacent Nodes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                start = createlist(start, n);
                break;

            case 2:
                display(start);
                break;

            case 3:
                start = swapAdjacent(start);
                printf("Swapped adjacent nodes:\n");
                display(start);
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

struct node *createlist(struct node *start, int n) {
    int i, info;
    if (n == 0) {
        return start;
    }
    printf("Enter data for node 1: ");
    scanf("%d", &info);
    start = addatbeg(start, info);
    for (i = 1; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &info);
        start = addatend(start, info);
    }
    return start;
}

struct node *addatbeg(struct node *start, int info) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = info;
    temp->prev = NULL;
    temp->next = start;

    if (start != NULL) {
        start->prev = temp;
    }

    start = temp;
    return start;
}

struct node *addatend(struct node *start, int info) {
    struct node *p, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = info;
    temp->next = NULL;

    if (start == NULL) {
        temp->prev = NULL;
        return temp;
    }

    p = start;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = temp;
    temp->prev = p;
    return start;
}

struct node *del(struct node *start, int info) {
    struct node *temp = start;
    if (start == NULL) {
        printf("\nList is Empty\n");
        return start;
    }
    while (temp != NULL) {
        if (temp->data == info) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                start = temp->next; // Removing the head node
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
            return start;
        }
        temp = temp->next;
    }
    printf("\nElement Not found\n");
    return start;
}

void display(struct node *start) {
    struct node *temp = start;
    if (start == NULL) {
        printf("Empty List\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node *swapAdjacent(struct node *start) {
    struct node *temp = start;
    while (temp != NULL && temp->next != NULL) {
        struct node *first = temp;
        struct node *second = temp->next;

        if (first->prev != NULL) {
            first->prev->next = second;
        } else {
            start = second; // Update head if swapping the first two nodes
        }

        second->prev = first->prev;
        first->next = second->next;
        if (second->next != NULL) {
            second->next->prev = first;
        }
        second->next = first;
        first->prev = second;

        temp = first->next;
    }
    return start;
}
