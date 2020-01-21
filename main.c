#include "bubblesort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "binary-search.h"
#include "main.h"


node* randomizedArray(int elementCount){
    node* array = malloc(sizeof(node) * elementCount);

    for(int i = 0; i < elementCount; i++){
        node* current = array + i;
        current->number = rand() % 32767;
    }

    return array;
}

int main() {
    char userInput = '\0';
    printf("GDI - Sorting algorithms and bsearch\n");
    printf("Sebastian Stampfel, 2019\n");

    printf("\nStart sorting? (y/n) ");
    userInput = (char) getchar();
    getchar(); // Consumes '\n' from before

    if(userInput == 'y'){
        double timeBubblesort1000 = 0;
        double timeBubblesort5000 = 0;
        double timeBubblesort10000 = 0;
        double timeBubblesort25000 = 0;

        double timeQuicksort1000 = 0;
        double timeQuicksort5000 = 0;
        double timeQuicksort10000 = 0;
        double timeQuicksort25000 = 0;

        double timeMergesort1000 = 0;
        double timeMergesort5000 = 0;
        double timeMergesort10000 = 0;
        double timeMergesort25000 = 0;

        bubblesort(1000, &timeBubblesort1000);
        bubblesort(5000, &timeBubblesort5000);
        bubblesort(10000, &timeBubblesort10000);
        bubblesort(25000, &timeBubblesort25000);

        quicksort(1000, &timeQuicksort1000);
        quicksort(5000, &timeQuicksort5000);
        quicksort(10000, &timeQuicksort10000);
        quicksort(25000, &timeQuicksort25000);

        mergesortTimed(1000, &timeMergesort1000);
        mergesortTimed(5000, &timeMergesort5000);
        mergesortTimed(10000, &timeMergesort10000);
        mergesortTimed(25000, &timeMergesort25000);

        printf("╔══════════════════════════════════════╗\n");
        printf("║             TIMING RESULTS           ║\n");
        printf("╠══════════════════════════════════════╣\n");
        printf("║Times for Bubblesort:                 ║\n");
        printf("║1000 Elements: %f seconds       ║\n"
                       "║5000 Elements: %f seconds       ║\n"
                       "║10000 Elements: %f seconds      ║\n"
                       "║25000 Elements: %f seconds      ║\n"
                       "╠══════════════════════════════════════╣\n",
                       timeBubblesort1000, timeBubblesort5000, timeBubblesort10000, timeBubblesort25000);
        printf("║Times for Quicksort:                  ║\n");
        printf("║1000 Elements: %f seconds       ║\n"
               "║5000 Elements: %f seconds       ║\n"
               "║10000 Elements: %f seconds      ║\n"
               "║25000 Elements: %f seconds      ║\n"
               "╠══════════════════════════════════════╣\n",
               timeQuicksort1000, timeQuicksort5000, timeQuicksort10000, timeQuicksort25000);
        printf("║Times for Mergesort:                  ║\n");
        printf("║1000 Elements: %f seconds       ║\n"
               "║5000 Elements: %f seconds       ║\n"
               "║10000 Elements: %f seconds      ║\n"
               "║25000 Elements: %f seconds      ║\n",
               timeMergesort1000, timeMergesort5000, timeMergesort10000, timeMergesort25000);
        printf("╚══════════════════════════════════════╝\n");
    }

    printf("\nContinue with binary search? (y/n) ");
    userInput = (char) getchar();
    getchar(); // Consumes '\n' from before
    if(userInput != 'y'){
        return 0;
    }
    binarysearch(500);

    return 0;
}
