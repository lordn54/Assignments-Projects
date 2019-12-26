/*
*  Name: Nicole Lord
*  Date: November 11, 2019
*  Assignment Name: Homework #04
*  File #06: treeAttempt.c
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
    char node;
    int frequency;
    struct tree_node *left;
    struct tree_node *right;
}TREE_NODE;

void insertion(char userInput, int i, TREE_NODE **arr) {
        int j;
        TREE_NODE *temp = NULL, *theNode;
        theNode = malloc(sizeof(TREE_NODE));
        theNode->node = userInput;
        //printf("New node '%c'\n ", theNode->node);
        printf("\n    Enter '%c's frequency: ", userInput);
        scanf("%d", &(theNode->frequency));
        arr[i] = theNode;
        j = i;
        while ((j > 1) && (arr[j/2]->frequency > arr[j]->frequency)){
            temp = arr[j/2];
            arr[j/2] = arr[j];
            arr[j] = temp;
            j /= 2;
        }  
}

void removal(TREE_NODE **arr, int size) {
    int j = 1;
    TREE_NODE *temp = NULL;
    arr[1] = arr[size];
    arr[size] = NULL;
    if ((2*j < size) && (2*j + 1 < size)) {
        if ((arr[2*j]->frequency) < (arr[2*j + 1]->frequency)) {
            if ((arr[2*j]->frequency) < (arr[j]->frequency)) {
                temp = arr[2*j];
                arr[2*j] = arr[j];
                arr[j] = temp;
                j *= 2; 
            } 
        } else {
            if (arr[2*j + 1]->frequency < arr[j]->frequency) {
                temp = arr[2*j + 1];
                arr[2*j + 1] = arr[j];
                arr[j] = temp;
                j = 2*j + 1;
            } 
        }
    } else if (2*j < size) {
        if (arr[2*j]->frequency < arr[j]->frequency) {
            temp = arr[2*j];
            arr[2*j] = arr[j];
            arr[j] = temp;
            j *= 2;
        }
    }
}

/*void preOrderTraversal(TREE_NODE *root) {
    int done = 0;  
    while ( ! done ) {
        while (root != NULL) {
            visit(root);
            if (root->left != NULL ) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        if ( stackEmpty(top)) {
            done++;  
        } else {
            root = root->right;
        }         
    }
}*/

/*void inOrderTraversal(TREE_NODE *root) {
    int done = 0;  
    while ( ! done ) {
        while (root != NULL) {
            if (root->left != NULL ) {
                root = root->left;
            } else {
                visit(root);
                root = root->right;
            }
        }
        if (stackEmpty(top)) {
            done++;  
        } else {
            visit(root);
            root = root->right;
        }         
    }
}*/

void preTraversalR(TREE_NODE *root) {
    printf("%c         %d\n", (root->node), (root->frequency));
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
    printf("%c         %d\n", (root->node), (root->frequency));
    if ((root->right) != NULL) {
        inTraversalR(root->right);
    }
}

int main() {
    TREE_NODE *aNode = NULL, *newNode, *temp;
    TREE_NODE *arr[10] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    char userInput;
    int size = 0;
    int i = 1;
    int j;
    /*Insertion into the Heap*/
    while (userInput != '$') {
        printf("Enter a character (enter a '$' to quit entering characters): ");
        scanf(" %c", &userInput);
        if (userInput != '$') {
            if (aNode == NULL) {
                aNode = malloc(sizeof(TREE_NODE));
                aNode->node = userInput;
                printf("\n    Enter '%c's frequency: ", userInput);
                scanf("%d", &(aNode->frequency));
                arr[i] = aNode;
            } else {
                insertion(userInput, i, arr);
            }
            i++;
            size++;
        }
        printf("\n");
    }
    /*printf("Insertion\n");
    for (i = 1; i <= size; i++) {
        printf("%c: %d \n", arr[i]->node, arr[i]->frequency);
    }*/
    while ((arr[2] != NULL) && (size != 0)) {
        newNode = malloc(sizeof(TREE_NODE));
        newNode->node = '-';
        newNode->left = arr[1];
        removal(arr, size);
        size--;
        newNode->right = arr[1];
        removal(arr, size);
        arr[size] = newNode;
        newNode->frequency = (newNode->left->frequency) + (newNode->right->frequency);
        j = size;
        while ((j > 1) && (arr[j/2]->frequency > arr[j]->frequency)){
            temp = arr[j/2];
            arr[j/2] = arr[j];
            arr[j] = temp;
            j /= 2;
        } 
    }
    printf("The nodes of the Huffman tree in Pre-order are:\n\n");
    preTraversalR(newNode);
    printf("\n");
    printf("The nodes of the Huffman tree in In-order are:\n\n");
    inTraversalR(newNode);
    //preOrderTraversal(aNode);
    //inOrderTraversal(aNode);
}