#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *lchild, *rchild;
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
struct node *del(struct node *pptr, int dkey);
struct node *del_right_check(struct node *pptr, int *shorter);
struct node *del_left_check(struct node *pptr, int *shorter);
struct node *del_left_balance(struct node *pptr, int *shorter);
struct node *del_right_balance(struct node *pptr, int *shorter);

struct node *insert(struct node *pptr, int ikey) {
    static int taller;
    if (pptr == NULL) {
        pptr = (struct node *)malloc(sizeof(struct node));
        pptr->info = ikey;
        pptr->lchild = NULL;
        pptr->rchild = NULL;
        pptr->balance = 0;
        taller = true;
    } else if (ikey < pptr->info) {
        pptr->lchild = insert(pptr->lchild, ikey);
        if (taller == true)
            pptr = insert_left_check(pptr, &taller);
    } else if (ikey > pptr->info) {
        pptr->rchild = insert(pptr->rchild, ikey);
        if (taller == true)
            pptr = insert_right_check(pptr, &taller);
    } else {
        printf("Duplicate key\n");
        taller = false;
    }
    return pptr;
}

struct node *insert_left_check(struct node *pptr, int *ptaller) {
    switch (pptr->balance) {
        case 0:
            pptr->balance = 1;
            printf("\nP %d : case L_A", pptr->info);
            break;
        case -1:
            pptr->balance = 0;
            printf("\nP %d : case L_B", pptr->info);
            *ptaller = false;
            break;
        case 1:
            pptr = insert_left_balance(pptr);
            *ptaller = false;
            break;
    }
    return pptr;
}

struct node *insert_left_balance(struct node *pptr) {
    struct node *aptr, *bptr;
    aptr = pptr->lchild;
    if (aptr->balance == 1) {
        pptr->balance = 0;
        aptr->balance = 0;
        printf("\nP %d : case L_C1", pptr->info);
        pptr = rotate_right(pptr);
    } else {
        bptr = aptr->rchild;
        switch (bptr->balance) {
            case 1:
                pptr->balance = -1;
                aptr->balance = 0;
                printf("\nP %d : case L_C2a", pptr->info);
                break;
            case 0:
                pptr->balance = 0;
                aptr->balance = 0;
                printf("\nP %d : case L_C2b", pptr->info);
                break;
            case -1:
                pptr->balance = 0;
                aptr->balance = 1;
                printf("\nP %d : case L_C2c", pptr->info);
                break;
        }
        bptr->balance = 0;
        pptr->lchild = rotate_left(aptr);
        pptr = rotate_right(pptr);
    }
    return pptr;
}

struct node *insert_right_check(struct node *pptr, int *ptaller) {
    switch (pptr->balance) {
        case 0:
            pptr->balance = -1;
            printf("\nP %d : case R_A", pptr->info);
            break;
        case 1:
            pptr->balance = 0;
            *ptaller = false;
            printf("\nP %d : case R_B", pptr->info);
            break;
        case -1:
            pptr = insert_right_balance(pptr);
            *ptaller = false;
            break;
    }
    return pptr;
}

struct node *insert_right_balance(struct node *pptr) {
    struct node *aptr, *bptr;
    aptr = pptr->rchild;
    if (aptr->balance == -1) {
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = rotate_left(pptr);
        printf("\nP %d : case R_C1", pptr->info);
    } else {
        bptr = aptr->lchild;
        switch (bptr->balance) {
            case 1:
                pptr->balance = 0;
                aptr->balance = -1;
                printf("\nP %d : case R_C2a", pptr->info);
                break;
            case 0:
                pptr->balance = 0;
                aptr->balance = 0;
                printf("\nP %d : case R_C2b", pptr->info);
                break;
            case -1:
                pptr->balance = 1;
                aptr->balance = 0;
                printf("\nP %d : case R_C2c", pptr->info);
                break;
        }
        bptr->balance = 0;
        pptr->rchild = rotate_right(aptr);
        pptr = rotate_left(pptr);
    }
    return pptr;
}

struct node *del(struct node *pptr, int dkey) {
    static int shorter;
    struct node *tmp, *succ;

    if (pptr == NULL) {
        printf("Key not found\n");
        shorter = false;
        return pptr;
    } else if (dkey < pptr->info) {
        pptr->lchild = del(pptr->lchild, dkey);
        if (shorter == true)
            pptr = del_left_check(pptr, &shorter);
    } else if (dkey > pptr->info) {
        pptr->rchild = del(pptr->rchild, dkey);
        if (shorter == true)
            pptr = del_right_check(pptr, &shorter);
    } else {
        if (pptr->lchild != NULL && pptr->rchild != NULL) {
            succ = pptr->rchild;
            while (succ->lchild != NULL)
                succ = succ->lchild;
            pptr->info = succ->info;
            pptr->rchild = del(pptr->rchild, succ->info);
            if (shorter == true)
                pptr = del_right_check(pptr, &shorter);
        } else {
            tmp = pptr;
            if (pptr->lchild != NULL)
                pptr = pptr->lchild;
            else if (pptr->rchild != NULL)
                pptr = pptr->rchild;
            else
                pptr = NULL;
            free(tmp);
            shorter = true;
        }
    }
    return pptr;
}

struct node *del_right_check(struct node *pptr, int *pshorter) {
    switch (pptr->balance) {
        case 0:
            pptr->balance = 1;
            *pshorter = false;
            break;
        case -1:
            pptr->balance = 0;
            break;
        case 1:
            pptr = del_left_balance(pptr, pshorter);
            break;
    }
    return pptr;
}

struct node *del_left_check(struct node *pptr, int *pshorter) {
    switch (pptr->balance) {
        case 0:
            pptr->balance = -1;
            *pshorter = false;
            break;
        case 1:
            pptr->balance = 0;
            break;
        case -1:
            pptr = del_right_balance(pptr, pshorter);
            break;
    }
    return pptr;
}

struct node *del_left_balance(struct node *pptr, int *pshorter) {
    struct node *aptr, *bptr;

    aptr = pptr->lchild;

    switch (aptr->balance) {
        case 0: /* Case L0 */
            pptr->balance = 1;
            aptr->balance = -1;
            *pshorter = false;
            pptr = rotate_right(pptr);
            break;

        case 1: /* Case L1 */
            pptr->balance = 0;
            aptr->balance = 0;
            pptr = rotate_right(pptr);
            break;

        case -1: /* Case L-1: Double rotation */
            bptr = aptr->rchild;
            switch (bptr->balance) {
                case 0:
                    pptr->balance = 0;
                    aptr->balance = 0;
                    break;
                case 1:
                    pptr->balance = -1;
                    aptr->balance = 0;
                    break;
                case -1:
                    pptr->balance = 0;
                    aptr->balance = 1;
                    break;
            }
            bptr->balance = 0;
            pptr->lchild = rotate_left(aptr);
            pptr = rotate_right(pptr);
            break;
    }

    return pptr;
}

struct node *del_right_balance(struct node *pptr, int *pshorter) {
    struct node *aptr, *bptr;

    aptr = pptr->rchild;

    switch (aptr->balance) {
        case 0: /* Case R0 */
            pptr->balance = -1;
            aptr->balance = 1;
            *pshorter = false;
            pptr = rotate_left(pptr);
            break;

        case -1: /* Case R-1 */
            pptr->balance = 0;
            aptr->balance = 0;
            pptr = rotate_left(pptr);
            break;

        case 1: /* Case R1: Double rotation needed */
            bptr = aptr->lchild;
            switch (bptr->balance) {
                case 0:
                    pptr->balance = 0;
                    aptr->balance = 0;
                    break;
                case 1:
                    pptr->balance = 0;
                    aptr->balance = -1;
                    break;
                case -1:
                    pptr->balance = 1;
                    aptr->balance = 0;
                    break;
            }
            bptr->balance = 0;
            pptr->rchild = rotate_right(aptr);
            pptr = rotate_left(pptr);
            break;
    }

    return pptr;
}

struct node *rotate_left(struct node *pptr) {
    struct node *aptr;
    aptr = pptr->rchild;
    pptr->rchild = aptr->lchild;
    aptr->lchild = pptr;
    return aptr;
}

struct node *rotate_right(struct node *pptr) {
    struct node *aptr;
    aptr = pptr->lchild;
    pptr->lchild = aptr->rchild;
    aptr->rchild = pptr;
    return aptr;
}

void inorder(struct node *pptr) {
    if (pptr != NULL) {
        inorder(pptr->lchild);
        printf("%d ", pptr->info);
        inorder(pptr->rchild);
    }
}

void postorder(struct node *pptr) {
    if (pptr != NULL) {
        postorder(pptr->lchild);
        postorder(pptr->rchild);
        printf("%d ", pptr->info);
    }
}

void preorder(struct node *pptr) {
    if (pptr != NULL) {
        printf("%d ", pptr->info);
        preorder(pptr->lchild);
        preorder(pptr->rchild);
    }
}

int main() {
    struct node *root = NULL;
    int choice, ikey;
    while (1) {
        printf("\n1. Insert\n2. Inorder\n3. Postorder\n4. Preorder\n5.Delete\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the key to be inserted: ");
                scanf("%d", &ikey);
                root = insert(root, ikey);
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
                printf("Enter the key to be deleted: ");
                scanf("%d", &ikey);
                root = del(root, ikey);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}