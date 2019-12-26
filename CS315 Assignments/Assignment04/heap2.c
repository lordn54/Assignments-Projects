/*
*  Name: Nicole Lord
*  Date: November 11, 2019
*  Assignment Name: Homework #04
*  File #04: heap2.c
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
    TREE_NODE *aNode = NULL, *newNode, *temp;
    TREE_NODE *arr[10] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    char userInput;
    int frequency;
    int countTemp;
    int size = 0;
    //int arr[10];
    int i = 1;
    int total;
    int j;
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
    //Removing from the heap
    j = 1;
    i = 1;
    countTemp = size;
    printf("Size = %d\n", size);
    printf("CountTemp = %d\n", countTemp);
    while ((arr[2] != NULL) && (size != 0)) {
        arr[1] = arr[size];
        arr[size] = NULL;
        j = 1;
        while ((j < size) && (2*j < size)){
             if ((2*j < size) && (2*j + 1 < size)) {
                 if ((arr[2*j]->frequency) < (arr[2*j + 1]->frequency)) {
                     if ((arr[2*j]->frequency) < (arr[j]->frequency)) {
                        temp = arr[2*j];
                        arr[2*j] = arr[j];
                        arr[j] = temp;
                        j *= 2; 
                     } else {
                         break;
                     }
                 } else {
                     if (arr[2*j + 1]->frequency < arr[j]->frequency) {
                         temp = arr[2*j + 1];
                         arr[2*j + 1] = arr[j];
                         arr[j] = temp;
                         j = 2*j + 1;
                     } else {
                         break;
                     }
                 }
             } else if (2*j < size) {
                 if (arr[2*j]->frequency < arr[j]->frequency) {
                     temp = arr[2*j];
                     arr[2*j] = arr[j];
                     arr[j] = temp;
                     j *= 2;
                 } else {
                     break;
                 }
             }
        }
        countTemp--;
        printf("\nAfter removal\n");
        for (i = 1; i <= countTemp; i++) {
            printf("%c: %d \n", arr[i]->node, arr[i]->frequency);
        }
        size--;
    }
}