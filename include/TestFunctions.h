/**
 *@file TestFunctions.h
 * @author Andrea Fernandes 0808213 aferna06@uoguelph.ca
 * @date June 2017
 * @brief File containing the function definitions used in the hash table struct
 */

#ifndef _TEST_FUNCTION_
#define _TEST_FUNCTION_

#include <stdio.h>
#include <stdlib.h>

/**Function to point the hash table to the appropriate functions. Allocates memory to the struct and table based on the size given.
*@return the index of where the data fits in the has array
*@param size size of the table array
*@param key is used to determine what the index of the data will be
**/
int hashFunction(size_t tableSize, int key);

/**Function to distroy the data stored within the node
*@return void
*@param data data to be distroyed
**/
void destroyData(void *data);

/**Function that defines how to print the data stored within the node
*@return void
*@param toBePrinted the data that will be printed
**/
void printData(void *toBePrinted);


#endif
