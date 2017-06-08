/**
 *@file TestFinctions.h
 * @author Andrea Fernandes
 * @date June 2017
 * @brief File containing the function definitions used in the hash table struct
*/

#ifndef _HASH_API_
#define _HASH_API_

#include <stdio.h>
#include <stdlib.h>

int hashFunction(size_t tableSize, int key);
void destroyData(void *data);
void printData(void *toBePrinted);



#endif