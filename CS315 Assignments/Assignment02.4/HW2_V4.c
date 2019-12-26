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

void insert(QUEUED_ITEM **ptrQ, QUEUED_ITEM *newGuy) {
        if (*ptrQ == NULL) {
            *ptrQ = newGuy;
            (*ptrQ)->next = *ptrQ;
        } else {
            newGuy->next = (*ptrQ)->next;
            (*ptrQ)->next = newGuy;
            *ptrQ = newGuy;
        }
}

void delete (QUEUED_ITEM **ptrQ2) {
    QUEUED_ITEM *temp;
    if (*ptrQ2 == NULL) {
        printf("\nNothing to remove; queue is empty.\n");
    } else if ((*ptrQ2)->next == (*ptrQ2)) {
        printf("\nThe character removed was an " "%c" ".\n", (*ptrQ2)->next->aChar);
        free(*ptrQ2);
        *ptrQ2 = NULL;
    } else {
        temp = (*ptrQ2)->next;
        (*ptrQ2)->next = (*ptrQ2)->next->next;
        printf("\nThe character removed was an ""%c"".\n", temp->aChar);
        free(temp);
    }
}

int main() {
    QUEUED_ITEM *Q = NULL, *newItem;
    newItem = malloc(sizeof(QUEUED_ITEM));
    char userInput;
    printf("\nEnter i to insert a new element, r to remove an element, q to quit: ");
    scanf(" %c", &(userInput));
    while(userInput != 'q') {
        if (userInput == 'i') {
            newItem = malloc(sizeof(QUEUED_ITEM));
            printf("\nEnter character to be enqueued (inserted): ");
            scanf(" %c", &(newItem->aChar));
            insert(&Q, newItem);
        } else if (userInput == 'r') {
            delete(&Q);
        } 
        printf("\nEnter i to insert a new element, r to remove an element, q to quit: ");
        scanf(" %c", &(userInput));
    }   
}
