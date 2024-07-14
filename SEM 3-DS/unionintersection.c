#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *createlist(struct node *, int);
struct node *addatbeg(struct node *, int);
struct node *addatend(struct node *, int);
struct node *unionl(struct node *, struct node *, struct node *);
struct node *intersection(struct node *, struct node *, struct node *);
struct node *match(struct node *, int data);
struct node *diff(struct node *, struct node *, struct node *);
struct node *reverse(struct node *);
struct node *del(struct node *,int);
struct node *sort(struct node *);
void display(struct node *start);

int main() {
    struct node *start1 = NULL;
    struct node *start2 = NULL;
    struct node *start3 = NULL;
    struct node *start4 = NULL;
    struct node *start5 = NULL;
    struct node *start6 = NULL;
    int choice, num, r1, r2;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Union of List 1 and List 2\n");
        printf("6. Intersection of List 1 and List 2\n");
        printf("7. Difference L1 - L2\n");
        printf("8. Difference L2 - L1\n");
        printf("9. Reverse\n");
        printf("10.Delete Node\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter number of nodes for List 1: ");
                scanf("%d", &r1);
                start1 = NULL;
                start1 = createlist(start1, r1);
                break;
            case 2:
                printf("\nEnter number of nodes for List 2: ");
                scanf("%d", &r2);
                start2 = NULL;
                start2 = createlist(start2, r2);
                break;
            case 3:
                printf("\nList 1: ");
                display(start1);
                break;
            case 4:
                printf("\nList 2: ");
                display(start2);
                break;
            case 5:
                start3 = NULL;
                start3 = unionl(start1, start2, start3);
                start3 = sort(start3);
                printf("\nUnion List: ");
                display(start3);
                break;
            case 6:
                start4 = NULL;
                start4 = intersection(start1, start2, start4);
                start4 = sort(start4);
                printf("\nIntersection List: ");
                display(start4);
                break;
            case 7:
                start5 = NULL;
                start5 = diff(start1, start2, start5);
                start5 = sort(start5);
                printf("\nL1 - L2 : ");
                display(start5);
                break;
            case 8:
                start6 = NULL;
                start6 = diff(start2, start1, start6);
                start6 = sort(start6);
                printf("\nL2 - L1 : ");
                display(start6);
                break;
            case 9:
                printf("\n1.List 1\n2.List 2\nEnter:");
                scanf("%d",&choice);
                switch(choice){
                case 1:
                    start1=reverse(start1);
                    break;
                case 2:
                    start2=reverse(start2);
                    break;
                default:
                    printf("\nInvalid Choice\n");
                }
                break;
            case 10:
                printf("\n1.List 1\n2.List 2\nEnter:");
                scanf("%d",&choice);
                switch(choice){
                case 1:
                    printf("\nEnter Node to be deleted:");
                    scanf("%d",&num);
                    start1=del(start1,num);
                    break;
                case 2:
                    printf("\nEnter Node to be deleted:");
                    scanf("%d",&num);
                    start2=del(start2,num);
                    break;
                default:
                    printf("\nInvalid Choice\n");
                }
                break;
            case 11:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

struct node *createlist(struct node *start, int n) {
    int i, info;
    if (n == 0) {
        return start;
    }
    printf("Enter:");
    scanf("%d", &info);
    start = addatbeg(start, info);
    for (i = 1; i < n; i++) {
        printf("\nEnter:");
        scanf("%d", &info);
        start = addatend(start, info);
    }
    return start;
}

struct node *addatbeg(struct node *start, int info) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = info;
    temp->link = start;
    start = temp;
    return start;
}

struct node *addatend(struct node *start, int info) {
    struct node *p, *temp;
    p = start;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = info;
    while (p->link != NULL)
        p = p->link;
    p->link = temp;
    temp->link = NULL;
    return start;
}

struct node *unionl(struct node *start1, struct node *start2, struct node *start3) {
    struct node *temp = start1;
    while (temp != NULL) {
        if(start3 == NULL){
            start3 = addatbeg(start3, temp->data);
        } else {
            start3 = addatend(start3, temp->data);
        }
        temp = temp->link;
    }

    temp = start2;
    while (temp != NULL) {
        if (!match(start3, temp->data)) {
            start3 = addatend(start3, temp->data);
        }
        temp = temp->link;
    }
    return start3;
}

struct node *intersection(struct node *start1, struct node *start2, struct node *start4) {
    struct node *temp = start2;
    while (temp != NULL) {
        if (match(start1, temp->data)) {
            if(start4 == NULL){
                start4 = addatbeg(start4, temp->data);
            } else {
                start4 = addatend(start4, temp->data);
            }
        }
        temp = temp->link;
    }
    return start4;
}

struct node *diff(struct node *start1, struct node *start2, struct node *start5) {
    struct node *temp = start1;
    while (temp != NULL) {
        if (!match(start2, temp->data)) {
            if(start5 == NULL){
                start5 = addatbeg(start5, temp->data);
            } else {
                start5 = addatend(start5, temp->data);
        }
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
    if (start == NULL) {
        printf("Empty List\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
struct node *reverse(struct node *start){
    struct node *prev,*ptr,*next;
    prev=NULL;
    ptr=start;
    while(ptr!=NULL){
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    start=prev;
    return prev;
}
struct node *del(struct node *start,int info){
    struct node *temp,*p;
    if(start==NULL){
        printf("\nList is Empty\n");
        return start;
    }
    if(start->data==info){
        temp=start;
        start=start->link;
        free(temp);
        return start;
    }
    p=start;
    while(p->link!=NULL){
        if(p->link->data==info){
            temp=p->link;
            p->link=temp->link;
            free(temp);
            return start;
        }
        p=p->link;
    }
    printf("\nNode Not found\n");
    return start;
}
struct node *sort(struct node *start) {
    struct node *i, *j;
    int temp;

    if (start == NULL || start->link == NULL) {
        return start;
    }

    for (i = start; i != NULL; i = i->link) {
        for (j = i->link; j != NULL; j = j->link) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    return start;
}
