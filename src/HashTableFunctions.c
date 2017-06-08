#include<stdio.h>
#include"HashTableAPI.h"

HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, int key),void (*destroyData)(void *data),void (*printData)(void *toBePrinted)){
    Htable *hashTable;
    Node **table;
    hashTable = malloc(sizeof(Htable));
    hashtable->size = size;
    hashtable->hashFunction = hashFunction;
    hashtable->printData = printData;
    hashtable->destroyData = destroyData;
    table = malloc(size* sizeof(Node *));
    for(int i=0; i<size; i++){
        table[i] = malloc(sizeof(node));
        table[i] = NULL;
    }
    table[size] = NULL;
    return hashTable;
}

Node *createNode(int key, void *data){
    Node *newNode;
    newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->data = data;
    struct Node *next -> NULL;
    return Node;
}

void destroyTable(HTable *hashTable){
    size_t size= hashTable-> size;
    //first distroy each node in the table array
    for(int i; i<size ; i++){
        Node * currentNode;
        //Distroy all collisions with this key
        Node * currentCollisionNode;
        currentNode = hashTable->table[i];
        currentCollisionNode = currentNode->next;
        while(currentCollisionNode != NULL){ //check for collisions
            Node* tempNode;
            tempNode = currentCollisionNode->next;
            hashTable->destroyData(currentCollisionNode->data);
            currentCollisionNode = tempNode;
        }
        //destroy the first data piece with the key
        hashTable->destroyData(currentNode->data);
    } //finish distroying table
    //now destroy the Htable itself
    free(HashTable);
    }

void insertData( HTable * hashTable, int key, void *data){
    if (hashTable != NULL){
        int hashIndex;
        Node * newNode;
        newNode = createNode(key, data);
        hashIndex = hashTable->hashFunction(hashTable->size, key);
        if(hashTable->table[hashIndex] != NULL){
            currentNode = table[hashIndex];
            currentCollisionNode = currentNode->next;
            while (currentCollisionNode != NULL){
                currentCollisionNode = currentCollisionNode->next; 
            }
                currentCollisionNode = newNode;
        }
        else{
            hashTable[hashIndex] = newNode;
        }
    }
}

void removeData (HTable *hashTable, int key){
    if (hashTable != NULL){
        int index 
        index =  hashFunction(hashTable->size, key);
        if(hashTable->table[index] != NULL){
            Node *currentNode;
            Node *prev;
            node = table[index];
            prev = NULL;
            while (currentNode -> key != key){
                prev = currentNode;
                currentNode = currentNode -> next;
                if (currentNode ==NULL){
                    printf("could not find key!\n");
                    }
            }
            if(currentNode->key == key){
                if(prev==NULL){
                    hashTable->table[index] = currentNode->nextNode;
                    free(currentNode);
                }
                else{
                    prev->next = currentNode->next;
                    free(currentNode);
                }
            }
        }
    }
}

void *lookupData(HTable *hashTable, int key){
    if (hashTable != NULL){
      int index;
      index = hashFunction(hashTable->size, key);
      
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
      return null;
    }
}






