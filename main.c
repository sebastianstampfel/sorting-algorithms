#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct node {
    unsigned int number;
    char text[20];
};

struct node* randomizedArray(int elementCount){
    struct node* array = malloc(sizeof(struct node) * elementCount);

    for(int i = 0; i < elementCount; i++){
        struct node* current = array + i;
        current->number = rand() % 32767;
        strcpy(current->text, "Hello World!");
    }

    return array;
}

int main() {
    int amount = 1000;
    struct node* nodeArray = randomizedArray(amount);
    srand(time(0));

    for(int i = 0; i < amount; i++){
        struct node* current = nodeArray + i;
        printf("Number: %d, Text: %s\n", current->number, current->text);
    }

    free(nodeArray);

    /* for(int i = 0; i < amount; i++){

    } */
    return 0;
}
