/*
*  Name: Nicole Lord
*  Date: November 11, 2019
*  Assignment Name: Homework #04
*  File #02: heap.c
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
    char node;
    int frequency;
    struct tree_node *left;
    struct tree_node *right;
}TREE_NODE;

int main() {
    //Inserting into the heap
    TREE_NODE *aNode = NULL, *newNode, *temp, *arr[10];
    char userInput;
    int frequency;
    int size = 0;
    //int arr[10];
    int i = 1;
    int total;
    int j;
   /*printf("Enter a character (enter a '$' to quit entering characters): ");
    scanf(" %c", &userInput);
    printf("Enter '%c's frequency: ", userInput);
    scanf("%d", &frequency);
    arr[1] = userInput;*/
    while (userInput != '$') {
        //Insertion into the heap
        printf("Enter a character (enter a '$' to quit entering characters): ");
        scanf(" %c", &userInput);
        if (userInput != '$') {
            if (aNode == NULL) {
                aNode = malloc(sizeof(TREE_NODE));
                aNode->node = userInput;
                printf("New node '%c'\n ", aNode->node);
                printf("Enter '%c's frequency: ", userInput);
                scanf("%d", &(aNode->frequency));
                arr[i] = aNode;
            } else {
                newNode = malloc(sizeof(TREE_NODE));
                newNode->node = userInput;
                printf("New node '%c'\n ", newNode->node);
                printf("Enter '%c's frequency: ", userInput);
                scanf("%d", &(newNode->frequency));
                arr[i] = newNode;
                j = i;
                while ((j > 1) && (arr[j/2]->frequency > arr[j]->frequency)){
                    temp = arr[j/2];
                    arr[j/2] = arr[j];
                    arr[j] = temp;
                    j /= 2;
                }
            }    
            i++;
            size++;  
        }
    }
    printf("Insertion\n");
    for (i = 1; i <= size; i++) {
        printf("%c: %d \n", arr[i]->node, arr[i]->frequency);
    }
    i = 1;
    //Removing from the heap
   // while(arr[i] != NULL) {
       // printf("are we in?");
        newNode = malloc(sizeof(TREE_NODE));
        newNode->node = '-';
        newNode->frequency = 0;
        if (newNode->frequency == 0) {
            while (newNode->frequency == 0) {
                if (newNode->left == NULL) {
                    newNode->left = arr[i];
                } else if ((newNode->left != NULL) && (newNode->right == NULL)) {
                    newNode->right = arr[i];
                } else if (newNode->right != NULL) {
                 newNode->frequency = (newNode->left->frequency) + (newNode->right->frequency);
               }   
               j = 1;
               while (j < i) {
                   printf("no?\n");
                   if (arr[j + 1] != NULL) {
                       arr[j] = arr[j + 1];
                       //arr[j + 1] = arr[j + 2];
                       printf("arr[%d]: %c - %d\n", j, arr[j]->node, arr[j]->frequency);
                       printf("arr[%d]: %c - %d\n", j+1, arr[(j + 1)]->node, arr[j + 1]->frequency);
                   } else {
                       printf("hi?\n");
                       printf("arr[%d]: %c - %d\n", j-2, arr[j - 2]->node, arr[j - 2]->frequency);
                       printf("arr[%d]: %c - %d\n", j-1, arr[(j - 1)]->node, arr[j - 1]->frequency);
                       printf("arr[%d]: %c - %d\n", j, arr[j]->node, arr[j]->frequency);
                       arr[j] = newNode;
                   }
                   j++;
               }
               j = i;
               while ((j > 1) && (arr[j/2]->frequency > arr[j]->frequency)){
                   printf("howdy?\n");
                   temp = arr[j/2];
                   arr[j/2] = arr[j];
                   arr[j] = temp;
                   j--;
               }
               printf("move\n");
               for (i = 1; i <= size; i++) {
                   printf("%c: %d \n", arr[i]->node, arr[i]->frequency);
               }
             }
            
           /* arr[i] = newNode;
            while ((j > 1) && (arr[j/2]->frequency > arr[j]->frequency)){
                temp = arr[j/2];
                arr[j/2] = arr[j];
                arr[j] = temp;
                j--;
            }*/
        }
        
       /* if (newNode->left->node == NULL) {
            newNode->left = arr[i];
        } else if (newNode->right->node == NULL) {
            newNode->right = arr[i];
        }
        while ((j > 1) && (arr[j/2]->frequency > arr[j]->frequency)){
            temp = arr[j/2];
            arr[j/2] = arr[j];
            arr[j] = temp;
            j--;
        }
        newNode->frequency = (newNode->left->frequency) + (newNode->right->frequency);*/
    //}
  /* while(arr[i] != 0) {
        //i = 1;
        newNode = malloc(sizeof(TREE_NODE));
        newNode->node = '-';
        small1 = arr[1];
        small2 = arr[2];
        for (j = 1; j < i; j++) {
            if (small1->frequency > arr[j]->frequency) {
                small1 = arr[j];
                free(arr[j]);
            } else if ((small2->frequency > arr[j]->frequency) && (small2 != small1)) {
                small2 = arr[j];
                free(arr[j]);
            }
        }
        newNode->left = small1;
        newNode->right = small2;
        newNode->frequency = (newNode->right->frequency) + (newNode->left->frequency);
        printf("Newnode: %c: %d\n", newNode->node, newNode->frequency);
        printf("Newnode left: %c: %d\n", newNode->left->node, newNode->left->frequency);
        printf("Newnode right: %c: %d\n", newNode->right->node, newNode->right->frequency);
        
        j = 1;
        while ((j < i) && (arr[j/2]->frequency < arr[j]->frequency)){
            temp = arr[j];
            arr[j] = arr[j/2];
            arr[j/2] = temp;
            j++;
        }
        i++;
    }*/
    printf("Removal\n");
    for (i = 1; i <= size; i++) {
        printf("%c: %d \n", arr[i]->node, arr[i]->frequency);
    }
}