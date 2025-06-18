#ifndef HASH_TABLE_FUNCTIONS_H
#define HASH_TABLE_FUNCTIONS_H

typedef struct HashNode HashNode;
typedef struct HashTable HashTable;

unsigned int hashFunction(int key);
HashTable* createHashTable();
void insertItems(HashTable* ht, int keys[], int values[], int n);
void insertItem(HashTable* ht, int key, int value);
void insertItemLinearProbing(HashTable* ht, int key, int value);
HashNode* findNthItem(HashTable* ht, int n);
HashNode* findItem(HashTable* ht, int key);
void removeItem(HashTable* ht, int key);
void removeAllItems(HashTable* ht);
void printHashTable(HashTable* ht);


#endif