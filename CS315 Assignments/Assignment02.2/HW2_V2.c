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
    QUEUED_ITEM *newItem = NULL;
    newItem = malloc(sizeof(QUEUED_ITEM));
    newItem->aChar = data;
    newItem->next = Q->next;
    Q->next = newItem;
    Q = newItem;
}

void delete() {
    QUEUED_ITEM *temp;
    if (Q->next == Q) {
        printf("You removed %c.\n", Q->next->aChar);
        printf("EMPTY");
        free(Q);
        Q = NULL;
    } else {
        temp = Q->next;
        Q->next = Q->next->next;
        printf("You removed %c.\n", temp->aChar);
        free(temp);
    }
}

int main() {
    Q = malloc(sizeof(QUEUED_ITEM));
    Q->aChar = 'd';
    Q->next = Q;
    insert('A');
    insert('B');
    insert('C');
    delete();
    delete();
    delete();
    delete();
    
}



