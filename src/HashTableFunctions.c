/*
 Author: Andrea Fernandes 0808213 aferna06@uoguelph.ca
 Date: June 17th 2017 
 Purpose: Function definitions for the function prototypes in the hashTableAPI.h file
 University of Guelph, 2017.
 CIS*2520 (DE) S17
*/

#include<stdio.h>
#include"HashTableAPI.h"
#include"TestFunctions.h"

HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, int key),void (*destroyData)(void *data),void (*printData)(void *toBePrinted)){
    HTable *hashTable;
    Node **table;
	int i;
    hashTable = malloc(sizeof(HTable));
    hashTable->size = size;
    hashTable->hashFunction = hashFunction;
    hashTable->printData = printData;
    hashTable->destroyData = destroyData;
    table = malloc(size* sizeof(Node *));
    for(i=0; i<size; i++){
        table[i] = malloc(sizeof(Node));
        table[i] = NULL;
    }
    table[size] = NULL;
    hashTable->table = &table[0];
    return hashTable;
}

Node *createNode(int key, void *data){
    Node *newNode;
    newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void destroyTable(HTable *hashTable){
    if (hashTable != NULL){
        int index;
        index =  hashTable->hashFunction(hashTable->size, key);
        if(hashTable->table[index] != NULL){
            Node *currentNode;
            Node *prev;
            currentNode = hashTable->table[index];
            prev = NULL;
            while(currentNode != NULL){
                //while (currentNode -> key != key){
                //    prev = currentNode;
                //    currentNode = currentNode -> next;
                    if (currentNode ==NULL){
                        printf("could not find key!\n");
                    }
                    if(currentNode->key == key){
                        if(prev==NULL){
                            hashTable->table[index] = currentNode->next;
                            hashTable->destroyData(currentNode->data);
                            free(currentNode);
                            currentNode = hashTable->table[index];
                            continue;
                        }
                        else{
                            prev->next = currentNode->next;
                            free(currentNode);
                            currentNode = prev->next;
                            continue;
                        }
                    }
                    prev = currentNode;
                    currentNode = currentNode -> next;
           }
        }
    }

}

void insertData( HTable * hashTable, int key, void *data){
    if (hashTable != NULL){
        int hashIndex;
        Node * newNode;
        Node *currentNode;
        newNode = createNode(key, data);
        hashIndex = hashTable->hashFunction(hashTable->size, key);
        if(hashTable->table[hashIndex] != NULL){
            currentNode = hashTable->table[hashIndex];
            while (currentNode->next != NULL){
                currentNode = currentNode->next; 
            }
                currentNode->next = newNode;
        }
        else{
            hashTable->table[hashIndex] = newNode;
        }
    }
}

void removeData (HTable *hashTable, int key){
    if (hashTable != NULL){
        int index;
        index =  hashTable->hashFunction(hashTable->size, key);
        if(hashTable->table[index] != NULL){
            Node *currentNode;
            Node *prev;
            currentNode = hashTable->table[index];
            prev = NULL;
            while(currentNode != NULL){
                //while (currentNode -> key != key){
                //    prev = currentNode;
                //    currentNode = currentNode -> next;
                    if (currentNode ==NULL){
                        printf("could not find key!\n");
                    }
                    if(currentNode->key == key){
                        if(prev==NULL){
                            hashTable->table[index] = currentNode->next;
                            hashTable->destroyData(currentNode->data);
                            free(currentNode);
                            currentNode = hashTable->table[index];
                            continue;
                        }
                        else{
                            prev->next = currentNode->next;
                            free(currentNode);
                            currentNode = prev->next;
                            continue;
                        }
                    }
                    prev = currentNode;
                    currentNode = currentNode -> next;
           }
        }
    }
}

void *lookupData(HTable *hashTable, int key){
    if (hashTable != NULL){
      int index;
      index = hashTable->hashFunction(hashTable->size, key);
      
      if (hashTable->table[index] == NULL){ //assume this
          return NULL;
      }
      Node *tempNode;
      tempNode = hashTable->table[index];
      while(tempNode != NULL){
        if (tempNode->key == key){
            return tempNode->data;
        }
        tempNode = tempNode->next;
      }
    }
    return NULL;
}
