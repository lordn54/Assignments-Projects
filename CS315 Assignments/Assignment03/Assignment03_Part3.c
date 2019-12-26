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
    
}

int main() {
    char userInput;
    TREE_NODE *aNode = NULL, *newNode, *trvPtrLead, *trvPtrTail;
    aNode = malloc(sizeof(TREE_NODE));
    newNode = malloc(sizeof(TREE_NODE));
    aNode->left = NULL;
    aNode->right = NULL;
    //Insertion into the Binary Tree
    printf("(i) to insert, (q) to quit: ");
    scanf(" %c", &userInput);
    if (userInput == 'i') {
        printf("Enter a character: ");
        scanf(" %c", &(aNode->node));
    }
    trvPtrLead = aNode;
    trvPtrTail = aNode;
    while (userInput != 'q') {
        printf("(i) to insert, (q) to quit: ");
        scanf(" %c", &userInput);
        switch(userInput){
            case 'i':
                newNode = malloc(sizeof(TREE_NODE));
                printf("Enter a character: ");
                scanf(" %c", &(newNode->node));
                while (trvPtrLead != NULL) {
                    trvPtrTail = trvPtrLead;
                    if ((newNode->node) < (trvPtrLead->node)) {
                        trvPtrLead = trvPtrLead->left;
                        //printf("Success\n");
                    } else if ((newNode->node) > (trvPtrLead->node)) {
                        trvPtrLead = trvPtrLead->right;
                        //printf("Success3\n");
                    }
                }
                if ((newNode->node) < (trvPtrTail->node)) {
                        trvPtrTail->left = newNode;
                        //printf("Success\n");
                } else if ((newNode->node) > (trvPtrTail->node)) {
                    trvPtrTail->right = newNode;
                    //printf("Success3\n");
                }
                trvPtrLead = aNode;
                trvPtrTail = aNode;
                break;
            case 'q':
                break;
        }
    }

    
    
    preTraversalR(aNode);
    printf("\n");
    inTraversalR(aNode);
    printf("\n");
    preOrderTraversal(aNode);
    printf("\n");
    inOrderTraversal(aNode);
    return 0;
} 