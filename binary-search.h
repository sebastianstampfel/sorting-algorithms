/** \file
 * \brief Adds functionality for task 2 - binary search.
 *
 * Generates a randomized list of nodes and prompts the user to input
 * a number to search for. Prints found number.
 */

#ifndef GDI_ALGORITHMEN_BINARY_SEARCH_H
#define GDI_ALGORITHMEN_BINARY_SEARCH_H
#include "main.h"

/**
 * \brief Function for the whole binary search operation.
 *
 * Generates a list of n nodes (n = \c amount), and fills the nodes
 * with random data. Sorts the list in ascending order using qsort()
 * afterwards. User will be prompted to enter a number to search for.
 * If the search criteria is met by one element, this element
 * will be printed to stdout.
 *
 * \param amount Amount of nodes for the randomized list
 */
void binarysearch(int amount);

#endif //GDI_ALGORITHMEN_BINARY_SEARCH_H
