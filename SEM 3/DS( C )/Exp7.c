//Expt7.c : Write a C program to create and display the graph using adjacency matrix and adjacency list.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int adj[MAX][MAX],state[MAX], n;
void create_graph();
void display();
void adj_list();
void BFS_traversal();
void BFS(int v);
int queue[MAX], front = -1, rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();
void DFS_traversal();
void DFS(int v);
int stack[MAX], top = -1;
void push(int v);
int pop();
int isEmpty_stack();

void create_graph(){
    int i, max_edges, origin, destin;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    max_edges = n * (n - 1);
    for (i = 1; i <= max_edges; i++)
    {
        printf("Enter edge %d(-1 -1 to quit): ", i);
        scanf("%d %d", &origin, &destin);
        if ((origin == -1) && (destin == -1))
            break;
        if (origin >= n || destin >= n || origin < 0 || destin < 0)
        {
            printf("Invalid edge!\n");
            i--;
        }
        else
        {
            adj[origin][destin] = 1;
        }
    }    
}
void display(){
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }
}
void adj_list(){
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("adjacency list of vertex %d\n", i);
        for (j = 0; j < n; j++)
        {
            if (adj[i][j] == 1)
                printf("%d -> %d\n", i, j);
        }
    }
}
void BFS_traversal(){
    int v;
    for(v=0;v<n;v++)
        state[v]=initial;
    printf("Enter starting vertex for BFS: ");
    scanf("%d", &v);
    for(v=0;v<n;v++)
        if(state[v]==initial)
            BFS(v);
}
void BFS(int v){
    int i;
    insert_queue(v);
    state[v]=waiting;
    while(!isEmpty_queue()){
        v=delete_queue();
        printf("%d ",v);
        state[v]=visited;
        for(i=0;i<n;i++){
            if(adj[v][i]==1 && state[i]==initial){
                insert_queue(i);
                state[i]=waiting;
            }
        }
    }
    printf("\n");
}
void insert_queue(int vertex){
    if(rear==MAX-1)
        printf("Queue overflow\n");
    else{
        if(front==-1)
            front=0;
        rear=rear+1;
        queue[rear]=vertex;
    }
}
int delete_queue(){
    int del_item;
    if(front==-1 || front>rear){
        printf("Queue underflow\n");
        exit(1);
    }
    del_item=queue[front];
    front=front+1;
    return del_item;
}
int isEmpty_queue(){
    if(front==-1 || front>rear)
        return 1;
    else
        return 0;
}
void DFS_traversal(){
    int v;
    for(v=0;v<n;v++)
        state[v]=initial;
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &v);
    for(v=0;v<n;v++)
        if(state[v]==initial)
            DFS(v);
}
void DFS(int v){
    int i;
    push(v);
    state[v]=waiting;
    while(!isEmpty_stack()){
        v=pop();
        printf("%d ",v);
        state[v]=visited;
        for(i=0;i<n;i++){
            if(adj[v][i]==1 && state[i]==initial){
                push(i);
                state[i]=waiting;
            }
        }
    }
    printf("\n");
}
void push(int v){
    if(top==MAX-1)
        printf("Stack overflow\n");
    else
        stack[++top]=v;
}
int pop(){
    if(top==-1){
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}
int isEmpty_stack(){
    if(top==-1)
        return 1;
    else
        return 0;
}
int main(){
    int choice;
    while(1){
        printf("1. Create graph\n2. Display\n3. Adjacency list\n4. BFS traversal\n5. DFS traversal\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                create_graph();
                break;
            case 2:
                display();
                break;
            case 3:
                adj_list();
                break;
            case 4:
                BFS_traversal();
                break;
            case 5:
                DFS_traversal();
                break;
            case 6:
                exit(0);
        }
    }
    return 0;
}