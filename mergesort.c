#include "mergesort.h"

void mergesortStruct(node *list, int low_index, int high_index){
    int mid;
    // Stops recursion if low = high,
    // meaning only one element left (or something else went wrong)
    if(low_index < high_index){
        mid = (low_index+high_index)/2;
        mergesortStruct(list, low_index, mid);                // Left
        mergesortStruct(list, mid+1, high_index);   // Right
        mergeStruct(list, low_index, mid, mid+1, high_index);
    }
}

void mergeStruct(node *list, int low_1, int high_1, int low_2, int high_2){

    node *temp = malloc(sizeof(node)*26000);
    int firstListStart,secondListStart,k;
    firstListStart = low_1;
    secondListStart = low_2;
    k = 0;

    // While end of both lists has not been reached
    while(firstListStart <= high_1 && secondListStart <= high_2){
        if((list + firstListStart)->number < (list + secondListStart)->number){
            (temp+k)->number = (list + firstListStart)->number;
            k++;
            firstListStart++;
        } else {
            (temp+k)->number = (list + secondListStart)->number;
            k++;
            secondListStart++;
        }
    }

    while(firstListStart <= high_1){
        (temp + k)->number = (list + firstListStart)->number;
        k++;
        firstListStart++;
    }

    while(secondListStart <= high_2){
        (temp + k)->number = (list + secondListStart)->number;
        k++;
        secondListStart++;
    }

    // All elements from temp back to list passed as param
    for(firstListStart = low_1, secondListStart = 0; firstListStart <= high_2; firstListStart++, secondListStart++){
        (list + firstListStart)->number = (temp + secondListStart)->number;
    }
    free(temp);
}

void mergesortTimed(int amount, double *timeInSeconds){
    node* nodeArray = randomizedArray(amount);

    printf("-----------------------\n");
    printf("Array for mergesort: \n");
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
    printf("Mergesorting...\n");

    clock_t start, end;

    start = clock();

    // Sorting...
    mergesortStruct(nodeArray, 0, amount-1);


    end = clock();
    *timeInSeconds = ((double) (end - start)) / CLOCKS_PER_SEC;

    for(int i = 0; i < amount; i++){
        node* current = nodeArray + i;
        printf("%d,", current->number);
        if((i + 1) % 15 == 0){
            printf("\n");   // Linebreak every 15 numbers
        } else if(i == amount - 1){
            printf("\n");   // Linebreak after last number
        }
    }

    free(nodeArray);
}