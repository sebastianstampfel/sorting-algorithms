//
// Created by sebastian-stampfel on 1/14/20.
//

#include <errno.h>
#include "binary-search.h"
#include "quicksort.h"

void binarysearch(int amount){
    node *nodeArray = malloc(sizeof(node)*amount);

    for(int i = 0; i < amount; i++){
        node *current = nodeArray + i;
        current->number = rand() % MAX_NUMBER;
        char randomizedString[6] = "";
        for(int i = 0; i < 5; i++){
            if((rand() % 200) % 2 == 0){
                // Random capital, latin letter (ASCII 65 - 90)
                randomizedString[i] = (char) (rand() % (90 - 65 + 1)) + 65; // Random number between 65 and 90
            } else {
                // Random lower case, latin letter (ASCII 97 - 122)
                randomizedString[i] = (char) (rand() % (122 - 97 + 1)) + 97; // Random number between 97 and 122
            }
        }
        strcpy(current->text, randomizedString);
        current->text[6] = '\0';
    }

    // bsearch requires a sorted list
    qsort(nodeArray, amount, sizeof(node), cmpfunc);
    printf("The list is made up of the following items:\n");
    for(int i = 0; i < amount; i++){
        node *current = nodeArray + i;
        printf("Number: %d, Text: %s\n", current->number, current->text);
    }

    node searchKey;
    char userInputSearchCriteria[30];
    char *conversionPointer;
    int conversionErrors = 0;

    printf("Enter a number to search for, please:\n");
    scanf("%s", userInputSearchCriteria);
    errno = 0;
    long int tmp = strtol(userInputSearchCriteria, &conversionPointer, 10);
    if(conversionPointer == userInputSearchCriteria){
        fprintf(stderr, "Invalid input!\n");
        conversionErrors++;
    } else if(*conversionPointer != '\0'){
        fprintf(stderr, "Invalid input!\n");
        conversionErrors++;
    } else {
        if(errno){
            fprintf(stderr, "Invalid input!\n");
            conversionErrors++;
        } else if(tmp > MAX_NUMBER){
            fprintf(stderr, "Invalid input - number too large!\n");
            conversionErrors++;
        } else {
            searchKey.number = (int) tmp;
        }
    }

    if(conversionErrors == 0){
        node *searchResult = (node*) bsearch(&searchKey, nodeArray, amount, sizeof(node), cmpfunc);
        if(searchResult != NULL){
            printf("Found - Number: %d, Text: %s\n", searchResult->number, searchResult->text);
        } else {
            fprintf(stderr, "Nothing found.\n");
        }
    }

    free(nodeArray);
}
