#include "quicksort.h"

int cmpfunc(const void * a, const void * b) {
    node* firstNode = (node*)a;
    node* secondNode = (node*)b;

    return (firstNode->number - secondNode->number);
}

void quicksort(int amount, double *timeInSeconds){
    node* nodeArray = randomizedArray(amount);

    printf("-----------------------\n");
    printf("Array for quicksort: \n");
    for(int i = 0; i < amount; i++){
        node* current = nodeArray + i;
        printf("%d,", current->number);
        if((i + 1) % 15 == 0){
            printf("\n");
        }
        if(i == amount - 1){
            printf("\n");
        }
    }

    printf("---------------------\n");
    printf("Quicksorting...\n");

    clock_t start, end;

    start = clock();

    qsort(nodeArray, amount, sizeof(node), cmpfunc);

    end = clock();
    *timeInSeconds = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time used by quicksort: %f seconds\n", *timeInSeconds);
    printf("---------------------\n");


    for(int i = 0; i < amount; i++){
        node* current = nodeArray + i;
        printf("%d,", current->number);
        if((i + 1) % 15 == 0){
            printf("\n");
        }
    }

    free(nodeArray);
}
