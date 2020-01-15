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

void bubblesort(int amount){
    struct node* nodeArray = randomizedArray(amount);
    srand(time(0));

    for(int i = 0; i < amount; i++){
        struct node* current = nodeArray + i;
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
    double cpu_time_used;

    start = clock();


    int sorted = 0;

    while(sorted == 0){
        int swaps = 0;
        for(int i = 0; i < amount; i++){
            if(i != amount - 1){
                struct node* current = nodeArray + i;
                struct node* next = nodeArray + i +1;

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
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time used by bubblesort: %f seconds\n", cpu_time_used);
    printf("---------------------\n");


    for(int i = 0; i < amount; i++){
        struct node* current = nodeArray + i;
        printf("%d,", current->number);
        if((i + 1) % 15 == 0){
            printf("\n");
        }
    }
    printf("\n");

    free(nodeArray);
}

int cmpfunc(const void * a, const void * b) {
    struct node* firstNode = (struct node*)a;
    struct node* secondNode = (struct node*)b;

    return (firstNode->number - secondNode->number);
}

void quicksort(int amount){
    struct node* nodeArray = randomizedArray(amount);

    printf("-----------------------\n");
    printf("Array for quicksort: \n");
    for(int i = 0; i < amount; i++){
        struct node* current = nodeArray + i;
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
    double cpu_time_used;

    start = clock();

    qsort(nodeArray, amount, sizeof(struct node), cmpfunc);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time used by quicksort: %f seconds\n", cpu_time_used);
    printf("---------------------\n");


    for(int i = 0; i < amount; i++){
        struct node* current = nodeArray + i;
        printf("%d,", current->number);
        if((i + 1) % 15 == 0){
            printf("\n");
        }
    }

    free(nodeArray);
}

void mergesort(int amount){
    struct node* nodeArray = randomizedArray(amount);

    printf("-----------------------\n");
    printf("Array for quicksort: \n");
    for(int i = 0; i < amount; i++){
        struct node* current = nodeArray + i;
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
    double cpu_time_used;

    start = clock();

    // Sorting...
    

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time used by quicksort: %f seconds\n", cpu_time_used);
    printf("---------------------\n");


    for(int i = 0; i < amount; i++){
        struct node* current = nodeArray + i;
        printf("%d,", current->number);
        if((i + 1) % 15 == 0){
            printf("\n");
        }
    }

    free(nodeArray);
}

int main() {
    int amount = 1000;
    bubblesort(amount);
    quicksort(amount);
    /* for(int i = 0; i < amount; i++){

    } */
    return 0;
}
