/**\file
 * \brief Main file for gdi-algorithms
 *
 * Implements bubblesort, mergesort and quicksort. Runtime of these
 * algorithms is measured in seconds and displayed.
 * Also, binary search is implemented for the second task.
 */
#ifndef GDI_ALGORITHMEN_MAIN_H
#define GDI_ALGORITHMEN_MAIN_H
#define MAX_NUMBER 32767
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ncurses.h>
#include <menu.h>

struct node {
    int number;
    char text[20];
} typedef node;

/**
 * \brief Generates an array (list) of struct node.
 *
 * Generates an array (list) of struct node, fills it with random data
 * and returns a pointer to the start (first element) of the array.
 *
 * @param elementCount Amount of elements to be used
 * @return Pointer to list
 */
node* randomizedArray(int elementCount);
void printInMiddle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
void itemSelectionHandler(char *name);


#endif //GDI_ALGORITHMEN_MAIN_H
