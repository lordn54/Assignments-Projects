/*
*  Name: Nicole Lord
*  Date: October 23, 2019
*  Assignment Name: Homework #03
*  File #05: Stack Code with Functions
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stackItem{
    char node;
    struct stackItem *next;
}STACKITEM;

int stackEmpty(STACKITEM *top) {
    if (top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void push(STACKITEM **top, STACKITEM *newItem) {
    newItem->next = *top;
    *top = newItem;
    (*top)->next = newItem->next;
}

void pop(STACKITEM **top) {
    STACKITEM *temp = NULL;
    temp = *top;
    if ((temp->next) == NULL) {
        *top = NULL;
        printf("List is now empty. Quitting removal.\n");
        //userInput = 'n';
    } /*else if((temp->next->next) == NULL) {
        top = temp->next;
        top->next = NULL;
        temp = top;
    }*/ else  {
        *top = temp->next;
        (*top)->next = temp->next->next;
        //temp = top;
    }
}

int main() {
    STACKITEM *top = NULL, *newItem;
    char userInput = 'a';
    int isItEmpty = stackEmpty(top);
    while (userInput != 'n') {
        switch(userInput) {
            printf("Do you want to insert? (y)es or (n)o ");
            scanf(" %c", &userInput);
            case 'y':
                if (isItEmpty == 1) {
                    top = malloc(sizeof(STACKITEM));
                    top->node = 'm';
                    isItEmpty = stackEmpty(top);
                } else {
                    newItem->node = 'a';
                    push(&top, newItem);
                    printf("Top: %c, Top->next: %c\n", (top->node), (top->next->node));
                }
                break;
            case 'n':
                break;
        }
        printf("Do you want to insert? (y)es or (n)o ");
        scanf(" %c", &userInput);
    }
    userInput = 'a';
    while (userInput != 'n') {
        isItEmpty = stackEmpty(top);
        printf("isItEmpty: %d\n", isItEmpty);
        switch(userInput) {
            case 'y':
                if (isItEmpty == 1) {
                    printf("Stack is empty. Quitting");
                    userInput = 'n';
                } else {
                    //printf("Top: %c, Top->next: %c\n", (top->node), (top->next->node));
                    pop(&top);
                    //printf("Top: %c\n", (top->node));
                    printf("Do you want to remove? (y)es or (n)o ");
                    scanf(" %c", &userInput);
                }
                break;
            case 'n':
                break;
        }
        
    }
}
/*CHANGE IT TO WHERE THERE IS NO USERINPUT*/