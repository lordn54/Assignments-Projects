#include <stdio.h>
#include <stdlib.h>

/*The structure for our soon to be ordered list*/
typedef struct listItem
{
    int anInteger;
    struct listItem *next;
} LIST_ITEM;

int main()
{
    LIST_ITEM *start = NULL, *temp, *lead, *trail;
    LIST_ITEM *trvPtr = start;
    int valueToBeDeleted = 0;
    temp = malloc(sizeof(LIST_ITEM));
    start = malloc(sizeof(LIST_ITEM));
    /*To get the value of start*/
    printf("Enter an integer: ");
    scanf("%d", &(start->anInteger));
    temp = start;
    /*After getting the first value the while loop keeps asking for numbers until
      the user does not want to put in anymore numbers*/
    while ((temp->anInteger) != 0)
    {
        temp = malloc(sizeof(LIST_ITEM));
        printf("Enter an integer: ");
        scanf("%d", &(temp->anInteger));
        if (temp->anInteger != 0)
        {
            /*Sorting process*/
            if (temp->anInteger < start->anInteger) {
               temp->next = start;
               start = temp;
            } else if (temp->anInteger > start->anInteger) {
                trvPtr = start;
                while ((trvPtr->next != NULL) && (temp->anInteger > trvPtr->next->anInteger)) 
                {
                    trvPtr = trvPtr->next; 
                }
                /*Makes sure there are not two of the same integer.*/
                if ((trvPtr->next == NULL) || (temp->anInteger != trvPtr->next->anInteger)) {
                    temp->next = trvPtr->next;
                    trvPtr->next = temp;
                }  
            }
        }
    } 
    trvPtr = start->next;
    printf("Your list is: %d", start->anInteger);
    /*Traversing*/
    while (trvPtr != NULL)
    {
        /*To check if the integer is not 0 so 0 is not printed out in the list*/
        if (trvPtr->anInteger != 0) {
            printf("-> %d", trvPtr->anInteger);
        }
        trvPtr = trvPtr->next;
    }
    printf("\n");
    printf("What do you want to delete? ");
    scanf("%d", &valueToBeDeleted);
    while(valueToBeDeleted != 0)
    {
        lead = start;
        trail = start;
        /*Deletion*/  
        if (start == NULL){
            printf("Empty List. \n");
        }else if(valueToBeDeleted == start->anInteger)
        {
            start = start->next;
        } else {
            lead = lead->next;
            while((lead != NULL) && (lead->anInteger != valueToBeDeleted))
            {
                lead = lead->next;
                trail = trail->next;
            }
            if (lead == NULL)
            {
                printf("Can't delete, %d it isn't in the list. \n", valueToBeDeleted);
            } else {
                trail->next = lead->next;
                free(lead);
            }
        }
        trvPtr = start->next;
        printf("Your list is: %d", start->anInteger);
        /*Traversing*/
        while (trvPtr != NULL)
        {
            /*To check if the integer is not 0 so 0 is not printed out in the list*/
            if (trvPtr->anInteger != 0) {
                printf("-> %d", trvPtr->anInteger);
            }
            trvPtr = trvPtr->next;
        }
        printf("\nWhat do you want to delete? ");
        scanf("%d", &valueToBeDeleted);
    }
    
}