/*
*  Name: Nicole Lord
*  Date: October 23, 2019
*  Assignment Name: Homework #03
*  File #02: Stack Code
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stackItem{
    char node;
    struct stackItem *next;
}STACKITEM;

int main() {
    STACKITEM *top = NULL, *newItem, *trvPtr, *temp;
    char userInput;
   // top = malloc(sizeof(STACKITEM));
    newItem = malloc(sizeof(STACKITEM));
    newItem->next = NULL;
    printf("Do you want to insert? (y)yes, (n)no ");
    scanf(" %c", &userInput);
    //Insertion into the stack (Push)
    if(userInput == 'y')  {
        top = malloc(sizeof(STACKITEM));
        printf("Enter a character to insert: ");
        scanf(" %c", &(top->node));
    } 
    while (userInput != 'n') {
        printf("Do you want to insert? (y)yes, (n)no " );
        scanf(" %c", &userInput);
        switch(userInput) {
            case 'y':
                newItem = malloc(sizeof(STACKITEM));
                printf("Enter a character: ");
                scanf(" %c", &(newItem->node));
                newItem->next = top;
                top = newItem;
                top->next = newItem->next;
                 //traversal
                if (top != NULL) {
                    trvPtr = top;
                    printf("Your list is: %c", trvPtr->node);
                    trvPtr = trvPtr->next;
                    while (trvPtr != NULL){
                        printf("-> %c", trvPtr->node);
                        trvPtr = trvPtr->next;
                    }
                }
                printf("\n");
                break;
            case 'n':
                break;
        }
    }
    //Removal from the stack (Pop)
    printf("Do you want to remove? (y) yes or (n) no ");
    scanf(" %c", &userInput);
    temp = top;
    while (userInput != 'n') {
        switch(userInput) {
            case 'y':
                if(top == NULL) {
                    printf("Stack is empty. Quitting removal.\n");
                    userInput = 'n';
                } else if ((temp->next) == NULL) {
                    top = NULL;
                    printf("List is now empty. Quitting removal.\n");
                    userInput = 'n';
                } /*else if((temp->next->next) == NULL) {
                    top = temp->next;
                    top->next = NULL;
                    temp = top;
                }*/ else  {
                    top = temp->next;
                    top->next = temp->next->next;
                    temp = top;
                }
                //Traversal
                if (top != NULL) {
                    trvPtr = top;
                    printf("Your list is: %c", trvPtr->node);
                    trvPtr = trvPtr->next;
                    while (trvPtr != NULL){
                        printf("-> %c", trvPtr->node);
                        trvPtr = trvPtr->next;
                    }
                }
                if (top != NULL) {
                    printf("\nDo you want to remove? (y) yes or (n) no ");
                    scanf(" %c", &userInput);
                }
                break;
            case 'n':
                break;
        }
    } 
}