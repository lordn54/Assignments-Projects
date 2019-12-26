/*
*  Name: Nicole Lord
*  Date: November 11, 2019
*  Assignment Name: Homework #04
*  File #01: firstAttempt.c
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
    //Making the heap
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
                //arr[i] = newNode;
                j = 1;
                if ((newNode->frequency) < (arr[1]->frequency)){
                    temp = arr[1];
                    arr[1] = newNode;
                    printf("%d", i);
                    while (i >= 2) {
                        printf("WE");
                        printf("arr[i + 1}: %d\narr[i]: %d\n", (arr[i + 1]->frequency), (arr[i]->frequency));
                        arr[i + 1] = arr[i];
                        printf("arr[i + 1}: %d\narr[i]: %d\n", arr[i + 1]->frequency, arr[i]->frequency);
                        i--;
                    }
                    arr[i] = temp;
                } /*else if ((newNode->frequency) > (arr[j]->frequency)) {
                    do {
                        printf("New nodes frequency: %d\n", newNode->frequency);
                        printf("arr[j] frequency: %d\n", arr[j]->frequency);
                        j++;
                    } while ((newNode->frequency) > (arr[j]->frequency));
                }*/ else {
                    arr[i] = newNode;
                }
                /*for (j = 1; j <= i; j++) {
                    if ((arr[j]) > (newNode->frequency)){
                        //i = j;
                        temp = malloc(sizeof(TREE_NODE));
                        if ((arr[j]) == (aNode->frequency)) {
                            temp = aNode;
                            aNode = newNode;
                            arr[1] = aNode->frequency;
                            arr[i] = temp->frequency;
                        } else {
                            temp->frequency = arr[j];
                            printf("%c\n%d\n", temp->node, temp->frequency);
                            
                        }
                    }*/
                //}
                //arr[i] = newNode->frequency;
                //trail = newNode;
            }
            //Fixing the heap property
           /*if((newNode->frequency) < (arr[1]->frequency)){
                temp = aNode;
                aNode = newNode;
                arr[1] = aNode;
                arr[i] = temp;
            } else if ((arr[i]) < (arr[i - 1])) {
                /*Figure out how to sort if the new node isn't less than the root
            }*/
           /*while ((newNode->frequency) > (arr[j]->frequency)){
                printf("New nodes frequency: %d\n", newNode->frequency);
                printf("arr[j] frequency: %d\n", arr[j]->frequency);
                j++;
            }*/
            i++;
            size++;
            
        }
    }
    //printf("%c \n", arr[i]);
    for (i = 1; i <= size; i++) {
        printf("%c \n", arr[i]->node);
    }
}