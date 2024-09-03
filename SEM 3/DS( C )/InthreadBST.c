#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
    int lthread, rthread;
};

struct Node *root = NULL;

void insert(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = root;
    struct Node *parent = NULL;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->lthread = newNode->rthread = 1;

    if (root == NULL) {
        root = newNode;
        return;
    }

    while (1) {
        parent = temp;
        if (data < temp->data) {
            if (temp->lthread == 1) {
                newNode->left = temp->left;
                newNode->right = temp;
                temp->left = newNode;
                temp->lthread = 0;
                return;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->rthread == 1) {
                newNode->right = temp->right;
                newNode->left = temp;
                temp->right = newNode;
                temp->rthread = 0;
                return;
            } else {
                temp = temp->right;
            }
        }
    }
}

void inorder() {
    struct Node *temp = root;
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    while (temp->lthread == 0) {
        temp = temp->left;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->rthread == 1) {
            temp = temp->right;
        } else {
            temp = temp->right;
            while (temp->lthread == 0) {
                temp = temp->left;
            }
        }
    }
    printf("\n");
}

void postorder() {
    struct Node *temp = root;
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    while (temp->lthread == 0) {
        temp = temp->left;
    }
    while (temp != NULL) {
        if (temp->rthread == 1) {
            printf("%d ", temp->data);
            temp = temp->right;
        } else {
            temp = temp->right;
            while (temp->lthread == 0) {
                temp = temp->left;
            }
        }
    }
    printf("\n");
}

void search(int data) {
    struct Node *temp = root;
    while (temp != NULL) {
        if (data == temp->data) {
            printf("Element found\n");
            return;
        } else if (data < temp->data) {
            if (temp->lthread == 1) {
                break;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->rthread == 1) {
                break;
            } else {
                temp = temp->right;
            }
        }
    }
    printf("Element not found\n");
}

struct Node *inorder_successor(struct Node *temp) {
    if (temp->rthread == 1) {
        return temp->right;
    }
    temp = temp->right;
    while (temp->lthread == 0) {
        temp = temp->left;
    }
    return temp;
}

struct Node *inorder_predecessor(struct Node *temp) {
    if (temp->lthread == 1) {
        return temp->left;
    }
    temp = temp->left;
    while (temp->rthread == 0) {
        temp = temp->right;
    }
    return temp;
}

struct Node *case_a(struct Node *root, struct Node *parent, struct Node *temp) {
    if (parent == NULL) {
        root = NULL;
    } else if (temp == parent->left) {
        parent->lthread = 1;
        parent->left = temp->left;
    } else {
        parent->rthread = 1;
        parent->right = temp->right;
    }
    free(temp);
    return root;
}

struct Node *case_b(struct Node *root, struct Node *parent, struct Node *temp) {
    struct Node *child = (temp->lthread == 1) ? temp->right : temp->left;

    if (parent == NULL) {
        root = child;
    } else if (temp == parent->left) {
        parent->left = child;
    } else {
        parent->right = child;
    }

    struct Node *inorderSuccessor = inorder_successor(temp);
    struct Node *inorderPredecessor = inorder_predecessor(temp);

    if (temp->lthread == 1) {
        inorderPredecessor->right = child;
    } else {
        inorderSuccessor->left = child;
    }
    free(temp);
    return root;
}

struct Node *case_c(struct Node *root, struct Node *parent, struct Node *temp) {
    struct Node *inorderSuccessor = inorder_successor(temp);
    temp->data = inorderSuccessor->data;

    if (inorderSuccessor->lthread == 1 && inorderSuccessor->rthread == 1) {
        root = case_a(root, parent, inorderSuccessor);
    } else {
        root = case_b(root, parent, inorderSuccessor);
    }
    return root;
}

struct Node *deleteNode(struct Node *root, int data) {
    struct Node *temp = root;
    struct Node *parent = NULL;
    int found = 0;

    while (temp != NULL) {
        if (data == temp->data) {
            found = 1;
            break;
        } else if (data < temp->data) {
            if (temp->lthread == 1) {
                break;
            } else {
                parent = temp;
                temp = temp->left;
            }
        } else {
            if (temp->rthread == 1) {
                break;
            } else {
                parent = temp;
                temp = temp->right;
            }
        }
    }

    if (!found) {
        printf("Element not found\n");
        return root;
    }

    if (temp->lthread == 0 && temp->rthread == 0) {
        root = case_c(root, parent, temp);
    } else if ((temp->lthread == 1 && temp->rthread == 0) || (temp->lthread == 0 && temp->rthread == 1)) {
        root = case_b(root, parent, temp);
    } else {
        root = case_a(root, parent, temp);
    }

    return root;
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Search\n");
        printf("5. Delete\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                inorder();
                break;
            case 3:
                postorder();
                break;
            case 4:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 5:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
