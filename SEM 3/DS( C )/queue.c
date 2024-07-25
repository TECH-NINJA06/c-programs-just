#include <stdio.h>
#define MAX 4

int queue_arr[MAX];
int front=-1,rear=-1,flag=0;

void insert(int);
void del_queue();
int isempty();
int isfull();
int peek();
void display();
int count();

void main(){
    int c,item;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter:");
        scanf("%d",&c);
        switch(c){
        case 1:
            printf("\nEnter info:");
            scanf("%d",&item);
            insert(item);
            break;
        case 2:
            del_queue();
            break;
        case 3:
            display();
            break;
        case 4:
            int x=count();
            if(x!=0)
                printf("\nTOTAL:%d nodes",x);
            else
                printf("\nEMPTY");
        case 5:
            eit(0);
        default:
            printf("\nInvalid Option\n");
        }
    }
/*    insert(10);
    display();
    insert(64);
    display();
    insert(105);
    display();
    insert(100);
    display();
    insert(89);
    display();
    insert(100);
    display();
    del_queue();
    display();
    del_queue();
    display();
    del_queue();
    display();
    del_queue();
    display();
    insert(27);
    display();
    del_queue();
    display();
    del_queue();
    display();
    insert(45);
    display();*/
}
void insert(int item){
    if(isfull()){
        printf("\nQueue Overflow\n");
        return;
    }
    if(front==-1){
        front=0;
    }
    rear+=1;
    queue_arr[rear]=item;
    printf("\n%d inserted into the queue\n",queue_arr[rear]);
}
void del_queue(){
    if(isempty()){
        printf("\nQueue Underflow\n");
        return ;
    }
    int item=queue_arr[front];
    printf("\n%d deleted from the queue\n",item);
    front+=1;
}
int isempty(){
    if(front==-1 || front==rear+1)
        return 1;
    return 0;
}

int isfull(){
    if(rear==MAX-1)
        return 1;
    return 0;
}
int peek(){
    if(isempty()){
        printf("\nQueue Underflow\n");
        exit(1);
    }
    return queue_arr[front];
}
void display(){
    printf("Queue: ");
    if(isempty()){
        printf("Empty\n");
        return;
    }
    for(int i=front;i<=rear;i++){
        printf("%d  ",queue_arr[i]);
    }
    printf("\n");
}
int count(){
    if(isempty())
        return 0;
    int count=0;

    for(int i=front;front<=rear;front++)
        count++;
    return count;
}
