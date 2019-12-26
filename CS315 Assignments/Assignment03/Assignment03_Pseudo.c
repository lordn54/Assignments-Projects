/*
*  Name: Nicole Lord
*  Date: October 23, 2019
*  Assignment Name: Homework #03
*  File #01: Pseudo Code
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
    char node;
    struct tree_node *left;
    struct tree_node *right;
}TREE_NODE;

void preTraversal(TREE_NODE *root) {
    printf("%c", (root->node));
    if((root->left) != NULL) {
        preTraversal(root->left);
    } 
    if ((root->right) != NULL) {
        preTraversal(root->right);
    }
}

void inTraversal(TREE_NODE *root) {
    if((root->left) != NULL) {
        inTraversal(root->left);
    } 
    printf("%c", (root->node));
    if ((root->right) != NULL) {
        inTraversal(root->right);
    }
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
    /*printf("aNode: %c\n", (aNode->node));
    printf("newNode: %c\n", (newNode->node));
    printf("aNode->left: %c\n", (aNode->left->node));
    printf("aNode->right: %c\n", (aNode->right->node));*/
    
    
    preTraversal(aNode);
    printf("\n");
    inTraversal(aNode);
     
} 