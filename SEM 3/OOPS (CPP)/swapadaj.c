#include  <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *prev;
    struct node *next;
};
void display(struct node *);
struct node *addatbeg(struct node *,int);
struct node *addatend(struct node *,int);
struct node *createlist(struct node *);
struct node *addbefore(struct node *, int ,int);
struct node *addafter(struct node *,int,int);
struct node *swapnode(struct node *);

int main(){
    struct node *start=NULL;
    start=createlist(start);
    display(start);
    start=swapnode(start);
    display(start);
    return 0;
}
void display(struct node *start){
    if(start==NULL){
        printf("\nEmpty List\n");
        return;
    }
    struct node *p=start;
    while(p!=NULL){
        printf("|%d|%u|->",p->info,p->next);
        p=p->next;
    }
    printf("NULL\n");
    return;
}
struct node *addatbeg(struct node *start,int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->prev=NULL;
    temp->next=start;
    if(start!=NULL)
        start=temp;
    return start;
}
struct node *addatend(struct node *start,int data){
    struct node *p,*temp;
    if(start==NULL){
        return addatbeg(start,data);
    }
    p=start;
    while(p->next!=NULL){
        p=p->next;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->next=NULL;
    temp->prev=p;
    p->next=temp;
    return start;
}
struct node *createlist(struct node *start){
    int n,data;
    printf("\nEnter no of nodes:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("\nEnter data:");
        scanf("%d",&data);
        start=addatend(start,data);
    }
    return start;
}
struct node *addbefore(struct node *start,int data,int item){
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    if(start->info==item){
        temp->next=start;
        start->prev=temp;
        temp->prev=NULL;
        start=temp;
        return start;
    }
    p=start->next;
    while(p!=NULL){
        if(p->info==item){
            temp->next=p;
            temp->prev=p->prev;
            p->prev->next=temp;
            p->prev=temp;
            return start;
        }
        p=p->link;
    }
    printf("\nItem not found\n");
    return start;
}
struct node *addafter(struct node *start, int data,int item){
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    p=start;
    while(p!=NULL){
        if(p->info==item){
            temp->next=p;
            temp->prev=p->prev;
            p->prev->next=temp;
            p->prev=temp;
            return start;
        }
        p=p->link;
    }
    printf("\nItem not found\n");
    return start;
}
struct node *swapnode(struct node *){
    struct node *p1,*p2,*newstart;
    if(start==NULL){
        printf("\nEmpty List\n");
        return start;
    }
    if(start->next=NULL){
        return start;
    }
    newstart=start->link;
    p1=start;
    while (p1 != NULL && p1->next != NULL) {
        p2 = p1->next;
        p1->next = p2->next;
        if (p2->next != NULL) {
            p2->next->prev = p1;
        }
        p2->prev = p1->prev;
        if (p1->prev != NULL) {
            p1->prev->next = p2;
        }
        p2->next = p1;
        p1->prev = p2;
        p1 = p1->next;
    }
    return newstart;
}
