#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
};
struct treeNode *root = NULL;
char queue[100];

struct node {
    char data;
    struct node *next;
};

struct node* addEnd(struct node *start, char data) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (start == NULL) {
        start = temp;
    } else {
        struct node *p = start;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
    return start;
}

struct node* createList(char *str) {
    struct node *start = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        start = addEnd(start, str[i]);
    }
    return start;
}

int countNodes(struct node *start) {
    struct node *p = start;
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void displayList(struct node *start) {
    struct node *p = start;
    while (p != NULL) {
        printf("%c ->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

struct treeNode* createTree(struct node *inptr, struct node *preptr, int num) {
    struct treeNode *tmp;
    struct node *q;
    int i,j;
    if(num==0)
        return NULL;
    tmp=(struct treeNode *)malloc(sizeof(struct treeNode));
    tmp->data=preptr->data;
    tmp->left=NULL;
    tmp->right=NULL;
    if(num==1)
        return tmp;
    q=inptr;
    for( i=0;q->data!=preptr->data;i++)
        q=q->next;
    tmp->left=createTree(inptr,preptr->next,i);
    for(j=1;j<=i+1;j++)
        preptr=preptr->next;
    tmp->right=createTree(q->next,preptr,num-i-1);
    return tmp;
}

struct treeNode* createTreeInPost(struct node *inptr, struct node *postptr, int num) {
    if (num == 0)
        return NULL;

    struct treeNode *tmp = (struct treeNode *) malloc(sizeof(struct treeNode));
    if (!tmp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Find the last node in post-order traversal
    struct node *postEnd = postptr;
    for (int k = 1; k < num; k++) {
        postEnd = postEnd->next;
    }

    tmp->data = postEnd->data;
    tmp->left = NULL;
    tmp->right = NULL;

    if (num == 1)
        return tmp;

    // Find the index of the root in in-order traversal
    struct node *q = inptr;
    int i;
    for (i = 0; q->data != postEnd->data; i++) {
        q = q->next;
    }

    tmp->left = createTreeInPost(inptr, postptr, i);

    struct node *newPostPtr = postptr;
    for (int j = 0; j < i; j++) {
        newPostPtr = newPostPtr->next;
    }

    tmp->right = createTreeInPost(q->next, newPostPtr, num - i - 1);

    return tmp;
}


int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct treeNode *node) {
    if (node == NULL)
        return 0;
    return max(height(node->left), height(node->right)) + 1;
}

//level order using queue
void levelOrder(struct treeNode *root) {
    struct treeNode *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct treeNode *temp = queue[front++];
        printf("%c ", temp->data);
        if (temp->left != NULL)
            queue[rear++] = temp->left;
        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
}

void printLevel(struct treeNode *node, int level, int space, int between) {
    if (node == NULL) {
        for (int i = 0; i < space; i++) printf(" ");
        return;
    }
    if (level == 1) {
        for (int i = 0; i < space; i++) printf(" ");
        printf("%c", node->data);
        for (int i = 0; i < between; i++) printf(" ");
    } else if (level > 1) {
        printLevel(node->left, level - 1, space, between);
        printLevel(node->right, level - 1, space, between);
    }
}

void displayTree(struct treeNode *node, int space) {
    int h = height(node);
    int maxSpace = pow(2, h) - 1;

    for (int i = 1; i <= h; i++) {
        int spaceCount = maxSpace / pow(2, i);
        int between = maxSpace / pow(2, i - 1) - 1;
        printLevel(node, i, spaceCount, between);
        printf("\n");
    }
}

int main() {
    char inorder[] = "ERFWAOTUX";
    char preorder[] = "AREWFTOXU";
    char post[] = "EWFRXOUTA";
    struct node *inorderList = createList(inorder);
    displayList(inorderList);
    struct node *preorderList = createList(preorder);
    displayList(preorderList);
    struct node *postorderList = createList(post);
    displayList(postorderList);
    int nodeCount = countNodes(inorderList);
    root = createTree(inorderList, preorderList, nodeCount);
    printf("\nTree created\n");
    displayTree(root, 0);
    root=createTreeInPost(inorderList,postorderList,nodeCount);
    printf("\nTree created\n");
    displayTree(root, 0);
    return 0;
}
