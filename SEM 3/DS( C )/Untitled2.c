#include <stdio.h>
#include <stdlib.h>
#define MAX 4;

int queue_arr[MAX];
int front=-1,rear=-1;

void insert(int item){
    if(isfull()){
        printf("\nQueue Overflow\n");
        return;
    }
    if(front==-1){
        front++;
    }
    rear+=1;
    queue_arr[rear]=item;
}
int del(){
    int item;
    if(isempty()){
        printf("\nQueue Underflow\n");
        exit(0);
    }
    item=queue_arr[front];
    front++;
    return item;
}
int isfull(){
    if(rear==MAX-1)
        return 1;
    return 0;

}
int isempty(){
    if(front==-1||front==rear+1)
        return 1;
    return 0;
}
int main(){
    return 0;
}
