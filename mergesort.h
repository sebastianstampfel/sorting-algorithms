/** \file
 * \brief Adds functionalitiy for mergesort.
 */

#ifndef GDI_ALGORITHMEN_MERGESORT_H
#define GDI_ALGORITHMEN_MERGESORT_H
#include "main.h"

/**
 * \brief Splits list in middle
 *
 * Function splits the supplied list in middle and calls this function
 * recursively on the lower and upper halves.
 *
 * @param list Pointer to chunk of memory of list
 * @param low_index Lower end of list
 * @param high_index Highest index in list
 */
void mergesortStruct(node *list, int low_index, int high_index);

/**
 * \brief Actual sorting and combination of sorted halves
 *
 * Compares elements through the list and sorts them. After sorting,
 * merges everything back into \c list.
 *
 * @param list (Part of) the list to be sorted
 * @param low_1 Start of the first half
 * @param high_1 End of the first half
 * @param low_2 Start of second half
 * @param high_2 End of second half
 */
void mergeStruct(node *list, int low_1, int high_1, int low_2, int high_2);

/**
 * \brief Functionality for mergesort
 *
 * Generates a list of struct nodes, filled with random data.
 * Runs this list through mergesort while timing the runtime.
 * Prints the unsorted and sorted list to stdout. After sorting,
 * the total runtime is calculated and also printed to stdout.
 *
 * @param amount Amount of elements to be used with the list.
 * @param timeInSeconds Pointer to some double variable; total time taken in seconds
 */
void mergesortTimed(int amount, double *timeInSeconds);

#endif //GDI_ALGORITHMEN_MERGESORT_H
