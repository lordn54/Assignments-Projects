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

QUEUED_ITEM *Q = NULL;

void insert(char data) {
    if (Q == NULL) {
        Q = malloc(sizeof(QUEUED_ITEM));
        Q->aChar = data;
        Q->next = Q;
    } else {
        QUEUED_ITEM *newItem = NULL;
        newItem = malloc(sizeof(QUEUED_ITEM));
        newItem->aChar = data;
        newItem->next = Q->next;
        Q->next = newItem;
        Q = newItem;
    }
}

void delete() {
    QUEUED_ITEM *temp;
    if (Q == NULL) {
        printf("\nIt's empty mate\n");
    } else if (Q->next == Q) {
        printf("\nYou removed %c.\n", Q->next->aChar);
        printf("\nEMPTY\n");
        free(Q);
        Q = NULL;
    } else {
        temp = Q->next;
        Q->next = Q->next->next;
        printf("\nYou removed ""%c"".\n", temp->aChar);
        free(temp);
    }
}

int main() {
    char userInput;
    printf("\nEnter i to insert a new element, r to remove an element, q to quit: ");
    scanf(" %c", &(userInput));
    while(userInput != 'q') {
        if (userInput == 'i') {
            printf("\nEnter character to be enqueued (inserted): ");
            scanf(" %c", &(userInput));
            insert(userInput);
        } else if (userInput == 'r') {
            delete();
        } 
        printf("\nEnter i to insert a new element, r to remove an element, q to quit: ");
        scanf(" %c", &(userInput));
    }   
}



