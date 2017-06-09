/*
 Author: Andrea Fernandes
 Date: June 17th 2017 
 Purpose: testFunctions to use with testing.c and the hash table API
 University of Guelph, 2017.
 CIS*2520 (DE) S17
*/

#include<stdio.h>
#include"HashTableAPI.h"

int hashFunction(size_t tableSize, int key){
    return key;
}

void destroyData(void *data){
//    free(data);
}

void *printData(void *toBePrinted){
    int *data;
    data = (int*)toBePrinted;
    printf("data : %d\n", *data);
    return 0;
}
