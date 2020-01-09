#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct node {
    unsigned int number;
    char text[20];
};

int main() {
    long long int amount = 10000000;
    struct node* nodeArray = malloc(sizeof(struct node) * amount);
    srand(time(0));

    for(int i = 0; i < amount; i++){
        struct node* current = nodeArray + i;
        current->number = rand() % 32767;
        strcpy(current->text, "Hello World!");
    }

    for(int i = 0; i < amount; i++){
        struct node* current = nodeArray + i;
        printf("Number: %d, Text: %s\n", current->number, current->text);
    }

    free(nodeArray);

    /* for(int i = 0; i < amount; i++){

    } */
    return 0;
}
