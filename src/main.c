/*
Author: Andrea Fernandes
Date: June 19
Purpose: Test the hash api
    
University of Guelph, 2017.
CIS*2520 (DE) S16
*/

// test main.c

#include<stdio.h>
#include"HashTableAPI.h"
#include"TestFunctions.h"

int main(void){
    // create a table with 4 hashKeys
    HTable * hTable;
    HTable = createTable(4, hashFunction, destroyData, printData);
    return 0;
}
