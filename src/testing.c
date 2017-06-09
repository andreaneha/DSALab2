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

void printTable(HTable *hTable){
    Node **nodes;
    nodes = hTable->table;
    for(int i = 0 ; i < 4 ; i++){
        Node *tempNode;
        tempNode = nodes[i];
        while(tempNode != NULL){
            hTable->printData(tempNode->data);
            tempNode = tempNode->next;
            if(tempNode == NULL){
                printf("next node = null\n");
            }
            else {
                printf("nextNode not Null\n");
            }
        }
    }
}

int main(void){
    // create a table with 4 hashKeys
    HTable * hTable;
    hTable = createTable(4, hashFunction, destroyData, printData);
    // create some nodes
    int *data1;
    int num1;
    num1=1;
    data1 = &num1;
    insertData(hTable, 0, data1);
    insertData(hTable, 1, data1);
    insertData(hTable, 2, data1);
    insertData(hTable, 3, data1);
    int *data2;
    int *data3;
    int num2;
    int num3;
    num2 = 2;
    num3 = 3;
    data2 = &num2;
    data3 = &num3;
    insertData(hTable, 1, data2);
    insertData(hTable, 1, data3);
    // print data;
    printTable(hTable);
    printf("test removeData\n");
    removeData(hTable, 1);
    printTable(hTable);
    printf("test removeData 2\n");
    removeData(hTable, 2);
    printTable(hTable);
    printf("look up data in table and print it\n");
    hTable->printData(lookupData(hTable, 0));

    destroyTable(hTable);

    return 0;
}
