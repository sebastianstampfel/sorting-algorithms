#include "bubblesort.h"

void bubblesort(int amount, double *timeInSeconds){
    node* nodeArray = randomizedArray(amount);
    srand(time(0));

    printf("-----------------------\n");
    printf("Array for bubblesort: \n");
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
    printf("Bubblesorting...\n");

    clock_t start, end;

    start = clock();


    int sorted = 0;

    while(sorted == 0){
        int swaps = 0;
        for(int i = 0; i < amount; i++){
            if(i != amount - 1){
                node* current = nodeArray + i;
                node* next = nodeArray + i +1;

                if(current->number > next->number){
                    int temp = next->number;
                    next->number = current->number;
                    current->number = temp;
                    swaps++;
                }
            }
        }

        if(swaps == 0){
            sorted = 1;
        }
    }

    end = clock();
    *timeInSeconds = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time used by bubblesort: %f seconds\n", *timeInSeconds);
    printf("---------------------\n");


    for(int i = 0; i < amount; i++){
        node* current = nodeArray + i;
        printf("%d,", current->number);
        if((i + 1) % 15 == 0){
            printf("\n");
        }
    }
    printf("\n");

    free(nodeArray);
}
