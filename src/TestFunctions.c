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
