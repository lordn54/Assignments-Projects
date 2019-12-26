/*
*  Name: Nicole Lord
*  Date: November 11, 2019
*  Assignment Name: Homework #04
*  File #05: heapInt2.c
*/

#include <stdio.h>
#include <stdlib.h>

void insertion(int userInput, int i, int *heap) {
   int j;
   int temp;
   heap[i] = userInput;
   printf("Heap[%d]: %d\n", i, heap[i]); 
   j = i;
   while ((j > 1) && (heap[j/2] > heap[j])){
       temp = heap[j/2];
       heap[j/2] = heap[j];
       heap[j] = temp;
       j /= 2;
   } 
}

void removal(int *heap, int count) {
    int temp;
    int j;
    heap[1] = heap[count];
    heap[count] = -1;
    j = 1;
    while ((j < count) && (2*j < count)){
        if ((2*j < count) && ((2*j + 1) < count)) {
            if (heap[2*j] < heap[2*j + 1]) {
                if (heap[2*j] < heap[j]) {
                    temp = heap[2*j];
                    heap[2*j] = heap[j];
                    heap[j] = temp;
                    j *= 2; 
                } else {
                    break;
                }
            } else {
                if (heap[2*j + 1] < heap[j]) {
                    temp = heap[2*j + 1];
                    heap[2*j + 1] = heap[j];
                    heap[j] = temp;
                    j = 2*j + 1;
                } else {
                    break;
                }
            }
        } else if ((2*j < count)) {
            if (heap[2*j] < heap[j]) {
                temp = heap[2*j];
                heap[2*j] = heap[j];
                heap[j] = temp;
                j *= 2;
            } else {
                break;
            }
        }
    }
}

int main() {
    int heap[10] = {-1, -1, -1, -1, -1, -1, -1 ,-1, -1, -1};
    int count = 0;
    int j = 1;
    int i = 1;
    int userInput;
    int temp;
    int countTemp = 0;
    printf("Oof\n");
    //Insertion
    while (userInput != -1) {
        printf("Enter an integer (enter '-1' to quit entering characters): ");
        scanf("%d", &userInput);
        if (userInput != -1) {
            insertion(userInput, i, heap); 
            count++;
            i++;
        }
          
    }
    printf("After insertion\n");
    for (i = 1; i <= count; i++) {
        printf("%d, ", heap[i]);
    }
    j = 1;
    i = 1;
    countTemp = count;
    //Removal
    while ((heap[2] != -1) && (count != 0)) {
        removal(heap, count);
        printf("\nAfter removal\n");
            for (i = 1; i <= countTemp; i++) {
                printf("%d, ", heap[i]);
            }
        count--;
    }
    
}