#include <stdio.h>
#include <stdlib.h>
struct node{
    char s;
    struct node *link;
};
struct node *top=NULL;
char exp[30];

int match(char a);
int eval();
struct node *push(struct node *top,char s);
struct node *pop(struct node *top);
char peek();
int space(char);
void display();

int main(){
    printf("Enter expression:");
    gets(exp);
    if(eval()==1)
        printf("\nExpression is valid\n");
    else
        printf("\nExpression is not valid\n");
    return 0;
}
struct node *push(struct node *top,char info){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("\nStack Overflow\n");
        return top;
    }
    temp->s=info;
    temp->link=top;
    top=temp;
    return top;
}
struct node *pop(struct node *top){
    struct node *temp=top;
    if(!top){
        printf("\nStack Underflow\n");
        return top;
    }
    top=top->link;
    free(temp);
    return top;
}
char peek(){
    if(!top){
        printf("\nStack Underflow\n");
        return '\0';
    }
    return top->s;
}
int match(char a){
    switch(a){
        case '(':
               if(a==peek())
                    return 1;
               return 0;
        case '[':
               if(a==peek())
                    return 1;
               return 0;
        case '{':
               if(a==peek())
                    return 1;
               return 0;

    }
}
int space(char s) {
    if(s == ' ' || s == '\t')
        return 1;
    return 0;
}
void display(){
    struct node *p=top;
    if(!top){
        printf("Stack Empty\n");
        return;
    }
    while(p!=NULL){
        printf("%c",p->s);
        p=p->link;
    }

    return;
}
int eval() {
    char a;
    printf("\n%-8s%-15s%\n", "SYMBOL", "STACK");
    for (int i = 0; i < strlen(exp); i++) {
        a = exp[i];
        if (!space(a)) {
            switch (a) {
                case '(':
                case '[':
                case '{':
                    top=push(top,a);
                    break;

                case ')':
                case ']':
                case '}':
                    if(!match(a))
                        return 0;
                    else{

                        top=pop(top);
                    }
                    break;
                default:
                    continue;
            }

            printf("%-8c", a);
            display(top);
            printf("\n");
        }
    }
    if(top==NULL)
        return 1;
    return 0;
}
