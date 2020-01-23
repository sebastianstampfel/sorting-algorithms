#include "quicksort.h"

int cmpfunc(const void * a, const void * b) {
    node* firstNode = (node*)a;
    node* secondNode = (node*)b;

    return (firstNode->number - secondNode->number);
}

void quicksort(int amount, double *timeInSeconds){
    node* nodeArray = randomizedArray(amount);

    printw("-----------------------\n");
    printw("Array for quicksort: \n");
    for(int i = 0; i < amount; i++){
        node* current = nodeArray + i;
        printw("%d,", current->number);
        if((i + 1) % 15 == 0){
            printw("\n");
        }
        if(i == amount - 1){
            printw("\n");
        }
    }

    printw("---------------------\n");
    printw("Quicksorting...\n");

    clock_t start, end;

    start = clock();

    qsort(nodeArray, amount, sizeof(node), cmpfunc);

    end = clock();
    *timeInSeconds = ((double) (end - start)) / CLOCKS_PER_SEC;

    for(int i = 0; i < amount; i++){
        node* current = nodeArray + i;
        printw("%d,", current->number);
        if((i + 1) % 15 == 0){
            printw("\n");
        } else if(i == amount - 1) {
            printw("\n");
        }
    }

    free(nodeArray);
}
