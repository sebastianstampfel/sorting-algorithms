/**\file
 * \brief Adds functionality for bubblesort
 */

#ifndef GDI_ALGORITHMEN_BUBBLESORT_H
#define GDI_ALGORITHMEN_BUBBLESORT_H
#include "main.h"

/**
 * \brief Impelements bubblesort
 *
 * Generates a list of struct nodes, filled with random data.
 * Runs this list through bubblesort while timing the runtime.
 * Prints the unsorted and sorted list to stdout. After sorting,
 * the total runtime is calculated and also printed to stdout.
 *
 * @param amount Amount of node elements for the list
 * @param timeInSeconds Total time taken for sorting in seconds.
 */
void bubblesort(int amount, double *timeInSeconds);

#endif //GDI_ALGORITHMEN_BUBBLESORT_H
