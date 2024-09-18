/*Write a c program on insertion in AVL tree */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *lchild,*rchild;
    int balance;
};
struct node *rotate_left(struct node *pptr);
struct node *rotate_right(struct node *pptr);
struct node *insert(struct node *pptr, int ikey);
struct node *insert_left_check(struct node *pptr, int *ptaller);
struct node *insert_right_check(struct node *pptr, int *ptaller);
struct node *insert_left_balance(struct node *pptr);
struct node *insert_right_balance(struct node *pptr);
void inorder(struct node *pptr);
void postorder(struct node *pptr);
void preorder(struct node *pptr);

struct node *insert(struct node *pptr, int ikey){
    static int taller;
    if(pptr==NULL){
        pptr=(struct node*)malloc(sizeof(struct node));
        pptr->info=ikey;
        pptr->lchild=NULL;
        pptr->rchild=NULL;
        pptr->balance=0;
        taller=true;
    }
    else if(ikey<pptr->info){
        pptr->lchild=insert(pptr->lchild,ikey);
        if(taller==true)
            pptr=insert_left_check(pptr,&taller);
    }
    else if(ikey>pptr->info){
        pptr->rchild=insert(pptr->rchild,ikey);
        if(taller==true)
            pptr=insert_right_check(pptr,&taller);
    }
    else{
        printf("Duplicate key\n");
        taller=false;
    }
    return pptr;
}
struct node *insert_left_check(struct node *pptr, int *ptaller){
    switch(pptr->balance){
        case 0:
            pptr->balance=1;
            printf("\nP %d : case L_A",pptr->info);
            break;
        case -1:
            pptr->balance=0;
            printf("\nP %d : case L_B",pptr->info);
            *ptaller=false;
            break;
        case 1:
            pptr=insert_left_balance(pptr);
            *ptaller=false;
            break;
    }
    return pptr;
}
struct node *insert_left_balance(struct node *pptr){
    struct node *aptr, *bptr;
    aptr=pptr->lchild;
    if(aptr->balance ==1){
        pptr->balance=0;
        aptr->balance=0;
        printf("\nP %d : case L_C1",pptr->info);
        pptr=rotate_right(pptr);
    }
    else{
        bptr=aptr->rchild;
        switch(bptr->balance){
            case 1:
                pptr->balance=-1;
                aptr->balance=0;
                printf("\nP %d : case L_C2a",pptr->info);
                break;
            case 0:
                pptr->balance=0;
                aptr->balance=0;
                printf("\nP %d : case L_C2b",pptr->info);
                break;
            case -1:
                pptr->balance=0;
                aptr->balance=1;
                printf("\nP %d : case L_C2c",pptr->info);
                break;
        }
        bptr->balance=0;
        pptr->lchild=rotate_left(aptr);
        pptr=rotate_right(pptr);
    }
    return pptr;
}
struct node *insert_right_check(struct node *pptr, int *ptaller){
    switch(pptr->balance){
        case 0:
            pptr->balance=-1;
            printf("\nP %d : case R_A",pptr->info);
            break;
        case 1:
            pptr->balance=0;
            *ptaller=false;
            printf("\nP %d : case R_B",pptr->info);
            break;
        case -1:
            pptr=insert_right_balance(pptr);
            *ptaller=false;
            break;
    }
    return pptr;
}
struct node *insert_right_balance(struct node *pptr){
    struct node *aptr, *bptr;
    aptr=pptr->rchild;
    if(aptr->balance==-1){
        pptr->balance=0;
        aptr->balance=0;
        pptr=rotate_left(pptr);
        printf("\nP %d : case R_C1",pptr->info);
    }
    else{
        bptr=aptr->lchild;
        switch(bptr->balance){
            case 1:
                pptr->balance=0;
                aptr->balance=-1;
                printf("\nP %d : case R_C2a",pptr->info);
                break;
            case 0:
                pptr->balance=0;
                aptr->balance=0;
                printf("\nP %d : case R_C2b",pptr->info);
                break;
            case -1:
                pptr->balance=1;
                aptr->balance=0;
                printf("\nP %d : case R_C2c",pptr->info);
                break;
        }
        bptr->balance=0;
        pptr->rchild=rotate_right(aptr);
        pptr=rotate_left(pptr);
    }
    return pptr;
}
struct node *rotate_left(struct node *pptr){
    struct node *aptr;
    aptr=pptr->rchild;
    pptr->rchild=aptr->lchild;
    aptr->lchild=pptr;
    return aptr;
}
struct node *rotate_right(struct node *pptr){
    struct node *aptr;
    aptr=pptr->lchild;
    pptr->lchild=aptr->rchild;
    aptr->rchild=pptr;
    return aptr;
}
void inorder(struct node *pptr){
    if(pptr!=NULL){
        inorder(pptr->lchild);
        printf("%d ",pptr->info);
        inorder(pptr->rchild);
    }
}
void postorder(struct node *pptr){
    if(pptr!=NULL){
        postorder(pptr->lchild);
        postorder(pptr->rchild);
        printf("%d ",pptr->info);
    }
}
void preorder(struct node *pptr){
    if(pptr!=NULL){
        printf("%d ",pptr->info);
        preorder(pptr->lchild);
        preorder(pptr->rchild);
    }
}
int main(){
    struct node *root=NULL;
    int choice, ikey;
    while(1){
        printf("\n1. Insert\n2. Inorder\n3. Postorder\n4. Preoder\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the key to be inserted: ");
                scanf("%d",&ikey);
                root=insert(root,ikey);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                postorder(root);
                break;
            case 4:
                preorder(root);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}