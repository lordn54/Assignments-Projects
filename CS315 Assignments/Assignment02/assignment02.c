/*
*  Name: Nicole Lord
*  Date: September 26, 2019
*  Assignment Name: Homework #02
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct queuedItem {
    char aChar;
    struct queuedItem *next;
} QUEUED_ITEM;

int main() {
    QUEUED_ITEM *Q = NULL, *newItem;
    QUEUED_ITEM *trvPtr = Q; //DELETE
    int x = 1; //DELETE
    char userInput;
    Q = malloc(sizeof(QUEUED_ITEM)); 
    newItem = malloc(sizeof(QUEUED_ITEM));
    Q->next = NULL;
    printf("Enter a letter: "); /*Beginning of Insert*/
    scanf(" %c", &(Q->aChar));
    //newItem = Q;
    Q->next = Q;
    while(x < 3){
        newItem = malloc(sizeof(QUEUED_ITEM));
        printf("Enter a letter: ");
        scanf(" %c", &(newItem->aChar));
        newItem->next = Q->next;
        Q->next = newItem;
        Q = newItem;
        x++;
    }
    trvPtr = Q;     /*Traversing: DELETE*/
    x = 1;
    while (x < 5)
    {
        /*To check if the integer is not 0 so 0 is not printed out in the list*/
        printf("-> %c", trvPtr->aChar);
        trvPtr = trvPtr->next;
        x++;
    }
     x = 1;
     printf("Enter a letter to remove: "); /*Beginning of remove*/
     scanf(" %c", &(userInput));
     if (userInput == Q->next->aChar) {
         Q->next = Q->next->next;
     } else {
         printf("Error. Letter not found.");
     }
     while(x < 3){
        printf("Enter a letter to remove: "); /*Beginning of remove*/
        scanf(" %c", &(userInput));
        if (userInput == Q->next->aChar) {
            if ((userInput == Q->next->next->aChar) && (Q->next->next == Q)) {
                printf("EMPTY");
                free(Q);
            }
            Q->next = Q->next->next;
        } else {
            printf("Error. Letter not found.");
        }
        x++;
    }

    //trvPtr = Q;     /*Traversing: DELETE*/
    /*x = 1;
    while (x < 5)
    {
        printf("-> %c", trvPtr->aChar);
        trvPtr = trvPtr->next;
        x++;
    }*/
}