/** \file
 * \brief Adds functionalitiy for quicksort.
 */

#ifndef GDI_ALGORITHMEN_QUICKSORT_H
#define GDI_ALGORITHMEN_QUICKSORT_H
#include "main.h"

/**
 * \brief Compare function for qsort.
 *
 * This function supports node-elements. Compares the \c number member of
 * \c struct node.
 *
 * @param a Value a
 * @param b Value b
 * @return <0 - element \c a goes before element \c b
 *          0 - elements are equal
 *         >0 - element \c a goes after element \c b
 */
int cmpfunc(const void * a, const void * b);
/**
 * \brief Functionality for quicksort
 *
 * Generates a list of struct nodes, filled with random data.
 * Runs this list through quicksort while timing the runtime.
 * Prints the unsorted and sorted list to stdout. After sorting,
 * the total runtime is calculated and also printed to stdout.
 *
 * @param amount Amount of elements to be used with the list.
 * @param timeInSeconds Pointer to some double variable; total time taken in seconds
 */
void quicksort(int amount, double *timeInSeconds);

#endif //GDI_ALGORITHMEN_QUICKSORT_H
