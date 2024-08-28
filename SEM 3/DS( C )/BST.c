#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int info;
    struct Node *left;
    struct Node *right;
};

struct Node *insert(struct Node *root, int ikey) {
    if (root == NULL) {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->info = ikey;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if (ikey < root->info) {
        root->left = insert(root->left, ikey);
    } else if (ikey > root->info) {
        root->right = insert(root->right, ikey);
    }
    else{
        printf("\nDuplication Not allowed\n");
        return root;
    }
    return root;
}

struct Node *search(struct Node *ptr, int data) {
    if (ptr == NULL || ptr->info == data) {
        return ptr;
    }
    if (data < ptr->info) {
        return search(ptr->left, data);
    }
    return search(ptr->right, data);
}

struct Node *Del(struct Node *root, int dkey) {
    if (root == NULL) {
        return root;
    }
    if (dkey < root->info) {
        root->left = Del(root->left, dkey);
    } else if (dkey > root->info) {
        root->right = Del(root->right, dkey);
    } else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->info = temp->info;
        root->right = Del(root->right, temp->info);
    }
    return root;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
int height(struct Node *node) {
    if (node == NULL)
        return 0;
    return max(height(node->left), height(node->right)) + 1;
}
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

int main() {
    struct Node *root = NULL;
    int choice, data,n;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Height\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Number of nodes ");
                scanf("%d", &n);
                printf("Enter data to insert: ");
                for(int i=0;i<n;i++){
                    scanf("%d", &data);
                    root = insert(root, data);
                }
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = Del(root, data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                struct Node *result = search(root, data);
                if (result != NULL) {
                    printf("Data found: %d \tAddress:%03d\n", result->info,(int)result%1000);
                } else {
                    printf("Data not found\n");
                }
                break;
            case 4:
                printf("Inorder traversal:\n");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder traversal:\n");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder traversal:\n");
                postorder(root);
                printf("\n");
                break;
            case 7:
                printf("\nHeight:%d\n",height(root));
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}