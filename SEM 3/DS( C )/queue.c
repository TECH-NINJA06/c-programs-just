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
    insert(10);
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
    display();
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
void display() {
    printf("Queue:\n");
    if (isempty()) {
        printf("Empty\n");
    }
    printf("Front=%d \tRear=%d\n",front,rear);
    for (int i = 0; i <= rear; i++) {
        printf("[%-2d]", i);
    }
    printf("\n");
    for (int i = 0; i <= rear; i++) {
        if(i>=front)
        printf("|%-3d", queue_arr[i]);
        else
        printf("|%-3s"," ");
    }
    printf("|\n");
}
int count(){
    if(isempty())
        return 0;
    int count=0;

    for(int i=front;front<=rear;front++)
        count++;
    return count;
}
