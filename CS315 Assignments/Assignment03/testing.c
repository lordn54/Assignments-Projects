#include <stdio.h>


int main() {
    //Seeing if comparison works with characters
    char aChar;
    char aChar2;
    printf("Enter a the root character. ");
    scanf(" %c", &aChar);
    printf("Enter a new character. ");
    scanf(" %c", &aChar2);
    if (aChar < aChar2) {
        printf("Go to the right: %c", aChar);
    } else if (aChar > aChar2) {
        printf("Go to the left: %c", aChar);
    }
} 