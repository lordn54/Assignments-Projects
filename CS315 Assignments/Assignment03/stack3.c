/*
*  Name: Nicole Lord
*  Date: October 23, 2019
*  Assignment Name: Homework #03
*  File #05: Stack Code with Functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stackItem{
    char node;
    struct stackItem *next;
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

void push(STACKITEM **top, STACKITEM *newItem) {
    newItem->next = *top;
    *top = newItem;
    (*top)->next = newItem->next;
}

STACKITEM *pop(STACKITEM **top) {
    STACKITEM *temp = NULL;
    temp = *top;
    /*if ((temp->next) == NULL) {
        *top = NULL;
        printf("List is now empty. Quitting removal.\n");
    } else  {
        *top = temp->next;
        (*top)->next = temp->next->next;
    }*/
    *top = temp->next;
    (*top)->next = temp->next->next;
    return (*top);
}

int main() {
    STACKITEM *top = NULL, *newItem, *trvPtr;
    int i = 0;
    //int isItEmpty = stackEmpty(top);
    while (i <= 1) {
        if(stackEmpty(top) == true) {
            top = malloc(sizeof(STACKITEM));
            top->node = 'm';
        } else {
            printf("Top: %c\n", top->node);
            newItem->node = 'd';
            push(&top, newItem);
            printf("New Top: %c\n", top->node); 
            printf("Top->next: %c\n", top->next->node);
        }
        i++;
    }
    trvPtr = top;
    printf("trvPtr: %c ", trvPtr->node);
    trvPtr = pop(&top);
    printf("trvPtr: %c ", trvPtr->node);
}