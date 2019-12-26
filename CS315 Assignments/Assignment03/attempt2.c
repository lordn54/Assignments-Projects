/*
*  Name: Nicole Lord
*  Date: October 23, 2019
*  Assignment Name: Homework #03
*  File #03: Part #03
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
    char node;
    char data[11];
    struct tree_node *left;
    struct tree_node *right;
}TREE_NODE;

typedef struct stackItem{
    struct stackItem *next;
    TREE_NODE *treeNode;
}STACKITEM;

int stackEmpty(STACKITEM *top) {
    int status;
    if (top == NULL) {
        status = 1;
    } else {
        status = 0;
    }
    return status;
}

void push(STACKITEM **top, TREE_NODE *tNode) {
    STACKITEM *newItem = NULL;
    newItem = malloc(sizeof(STACKITEM));
    newItem->treeNode = tNode;
    newItem->next = *top;
    *top = newItem;
    (*top)->next = newItem->next;
}

TREE_NODE *pop(STACKITEM **top) {
    STACKITEM *temp = NULL;
    TREE_NODE *returned = NULL;
    temp = *top;
    returned = (*top)->treeNode;
    *top = temp->next;
    free(temp);
    return returned;
}

void visit(TREE_NODE *root) {
    printf("%c", root->node);
}

void preTraversalR(TREE_NODE *root) {
    printf("%c", (root->node));
    if((root->left) != NULL) {
        preTraversalR(root->left);
    } 
    if ((root->right) != NULL) {
        preTraversalR(root->right);
    }
}

void inTraversalR(TREE_NODE *root) {
    if((root->left) != NULL) {
        inTraversalR(root->left);
    } 
    printf("%c", (root->node));
    if ((root->right) != NULL) {
        inTraversalR(root->right);
    }
}

void preOrderTraversal(TREE_NODE *root) {
    STACKITEM *top = NULL;
    int done = 0;  /* Boolean, controls the outer loop */
    while ( ! done ) {
        while (root != NULL) {
            visit(root);
            if (root->left != NULL ) {
                push(&top, root);
                root = root->left;
            } else {
                root = root->right;
            }
        }
        if ( stackEmpty(top)) {
            done++;  /* We're done */
        } else {
            root = pop(&top);
            root = root->right;
        }         
    }
}

void inOrderTraversal(TREE_NODE *root) {
    STACKITEM *top = NULL;
    int done = 0;  /* Boolean, controls the outer loop */
    while ( ! done ) {
        while (root != NULL) {
            if (root->left != NULL ) {
                push(&top, root);
                root = root->left;
            } else {
                visit(root);
                root = root->right;
            }
        }
        if (stackEmpty(top)) {
            done++;  /* We're done */
        } else {
            root = pop(&top);
            visit(root);
            root = root->right;
        }         
    }
}

void insertionInTree(TREE_NODE *root) {
    TREE_NODE *newNode = NULL, *trvPtrLead, *trvPtrTail;
    newNode = malloc(sizeof(TREE_NODE));
    trvPtrLead = root;
    trvPtrTail = root;
    printf("Enter a character: ");
    scanf(" %c", &(newNode->node));
    printf("Enter string of up to 10 characters for '%c' data: ", newNode->node);
    scanf("%s", newNode->data);
    while (trvPtrLead != NULL) {
        trvPtrTail = trvPtrLead;
        if ((newNode->node) < (trvPtrLead->node)) {
            trvPtrLead = trvPtrLead->left;
        } else if ((newNode->node) > (trvPtrLead->node)) {
            trvPtrLead = trvPtrLead->right;
        }
    }
    if ((newNode->node) < (trvPtrTail->node)) {
        trvPtrTail->left = newNode;
    } else if ((newNode->node) > (trvPtrTail->node)) {
        trvPtrTail->right = newNode;
    }
}

void find(TREE_NODE *root, char finding) {
    while((root != NULL) && ((root->node) != finding)) {
        if (finding < (root->node)) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    if (root == NULL) {
        printf("'%c' is not in the tree\n", finding);
    } else {
        printf("Found the string '%s' there\n", root->data);
    }
}

int main() {
    char userInput = 'a';
    char findInput;
    TREE_NODE *aNode = NULL;
    aNode = malloc(sizeof(TREE_NODE));
    aNode->left = NULL;
    aNode->right = NULL;
    //Insertion into the Binary Tree
    printf("Enter choice (lower case is also acceptable) --- (I)nsert, (F)ind, (Q)uit: ");
    scanf(" %c", &userInput);
    if ((userInput == 'i') || (userInput == 'I')) {
        printf("Enter new node's key value: ");
        scanf(" %c", &(aNode->node));
        printf("Enter string of up to 10 characters for '%c' data: ", aNode->node);
        scanf("%s", aNode->data);
        printf("Pre-order traversal is: ");
        preOrderTraversal(aNode);
        printf("\nInorder traversal is: ");
        inOrderTraversal(aNode);
        printf("\n");
    }
    while (userInput != 'q') {
        printf("Enter choice (lower case is also acceptable) --- (I)nsert, (F)ind, (Q)uit: ");
        scanf(" %c", &userInput);
        switch(userInput){
            case 'I':
            case 'i':
                insertionInTree(aNode);
                printf("Pre-order traversal is: ");
                preOrderTraversal(aNode);
                printf("\nInorder traversal is: ");
                inOrderTraversal(aNode);
                printf("\n");
                break;
            case 'F':
            case 'f':
                printf("Enter the search key: ");
                scanf(" %c", &findInput);
                find(aNode, findInput);
        }
    }
    return 0;
} 