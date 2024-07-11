#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *createlist(struct node *, int);
struct node *unionl(struct node *, struct node *, struct node *);
struct node *intersection(struct node *, struct node *, struct node *);
struct node *match(struct node *, int data);
struct node *diff(struct node *, struct node *, struct node *);
void display(struct node *start);

int main() {
    struct node *start1 = NULL;
    struct node *start2 = NULL;
    struct node *start3 = NULL;
    struct node *start4 = NULL;
    struct node *start5 = NULL;
    struct node *start6 = NULL;
    int num, r1, r2;
    printf("Enter no of nodes for list 1 & list 2:");
    scanf("%d %d", &r1, &r2);

    printf("\nEnter the data for list 1:");
    for (int i = 0; i < r1; i++) {
        scanf("%d", &num);
        start1 = createlist(start1, num);
    }

    printf("\nEnter the data for list 2:");
    for (int i = 0; i < r2; i++) {
        scanf("%d", &num);
        start2 = createlist(start2, num);
    }

    start3 = unionl(start1, start2, start3);
    start4 = intersection(start1, start2, start4);
    start5 = diff(start1, start2, start5);
    start6 = diff(start2, start1, start6);

    printf("\nUnion List:");
    display(start3);
    printf("\nIntersection List:");
    display(start4);
    printf("\nL1 - L2 : ");
    display(start5);
    printf("\nL2 - L1 : ");
    display(start6);
    return 0;
}

struct node *createlist(struct node *start, int num) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->link = NULL;

    if (start == NULL) {
        start = temp;
    }
    else {
        struct node *p = start;
        while (p->link != NULL) {
            p = p->link;
        }
        p->link = temp;
    }
    return start;
}

struct node *unionl(struct node *start1, struct node *start2, struct node *start3) {
    struct node *temp = start1;
    while (temp != NULL) {
        start3 = createlist(start3, temp->data);
        temp = temp->link;
    }

    temp = start2;
    while (temp != NULL) {
        if (!match(start3, temp->data)) {
            start3 = createlist(start3, temp->data);
        }
        temp = temp->link;
    }
    return start3;
}

struct node *intersection(struct node *start1, struct node *start2, struct node *start4) {
    struct node *temp = start2;
    while (temp != NULL) {
        if (match(start1, temp->data)) {
            start4 = createlist(start4, temp->data);
        }
        temp = temp->link;
    }
    return start4;
}

struct node *diff(struct node *start1, struct node *start2, struct node *start5) {
    struct node *temp = start1;
    while (temp != NULL) {
        if (!match(start2, temp->data)) {
            start5 = createlist(start5, temp->data);
        }
        temp = temp->link;
    }
    return start5;
}

struct node *match(struct node *start, int num) {
    struct node *p = start;
    while (p != NULL) {
        if (p->data == num) {
            return p;
        }
        p = p->link;
    }
    return NULL;
}

void display(struct node *start) {
    struct node *temp = start;
    if(start==NULL){
        printf("Empty List");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
