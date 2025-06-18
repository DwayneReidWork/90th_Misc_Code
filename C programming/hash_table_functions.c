#include "hash_table_functions.h"
#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

typedef struct HashNode 
{
    // void* pointer allows storage of any data
    void* key;
    void* value; // be careful recalling though!
    struct HashNode* next;
} HashNode;

typedef struct HashTable 
{
    HashNode* table[TABLE_SIZE];
} HashTable;


unsigned int hashFunction(int key) 
{
    return key % TABLE_SIZE;
}

HashTable* createHashTable() 
{
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        // Set each bucket entry to NULL
        ht->table[i] = NULL;
    }
    return ht;
}

void insertItems(HashTable* ht, int keys[], int values[], int n) 
{
    //keys = {x, X, 13, 15, 17} + 21, + 1->1,
    //values = {a, b, c, d, e} + f, + g
    // n = 5
    for (int i = 0; i < n; i++) 
    {
        unsigned int index = hashFunction(keys[i]);
        /*
        i = 1
        index = 1
        index   address(key,value,next)
        0       NULL
        1       NULL
        2       NULL
        3       0x7(0x8->13,0x9->c,NULL)
        4       NULL
        5       0x10(0x11->15,0x12->d,NULL)
        6       NULL
        7       0x13(0x14->17,0x15->e,NULL)
        8       NULL
        9       NULL

        newNode = 0x4
            ->key   0x5->11
            ->value 0x6->b
            ->next  NULL
        temp = 0x1->next != NULL => while temp->next has an address, store it at temp
        temp->next == NULL, 0x1->next
        */
        // Create a new node
        HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
        newNode->key = malloc(sizeof(int));
        *((int*)newNode->key) = keys[i];
        newNode->value = malloc(sizeof(int));
        *((int*)newNode->value) = values[i];
        newNode->next = NULL;

        // Insert into hash table using chaining
        if (!ht->table[index]) 
        {
            ht->table[index] = newNode;
        } 
        else 
        {
            HashNode* temp = ht->table[index];
            while (temp->next) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void insertItem(HashTable* ht, int key, int value) 
{
    unsigned int index = hashFunction(key);

    // Create a new node
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = malloc(sizeof(int));
    *((int*)newNode->key) = key;
    newNode->value = malloc(sizeof(int));
    *((int*)newNode->value) = value;
    newNode->next = NULL;

    // Insert into hash table
    if (!ht->table[index]) 
    {
        ht->table[index] = newNode;
    } else {
        HashNode* temp = ht->table[index];
        while (temp->next) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Key %d with value %d inserted successfully.\n", key, value);
}

void insertItemLinearProbing(HashTable* ht, int key, int value) 
{
    unsigned int index = hashFunction(key);

    // Use linear probing to find the next free value
    while (ht->table[index] != NULL) 
    {
        index = (index + 1) % TABLE_SIZE;
    }

    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = malloc(sizeof(int));
    *((int*)newNode->key) = key;
    newNode->value = malloc(sizeof(int));
    *((int*)newNode->value) = value;
    newNode->next = NULL;

    ht->table[index] = newNode;
    printf("Key %d with value %d inserted at index %d using linear probing.\n", key, value, index);
}

HashNode* findNthItem(HashTable* ht, int n) 
{
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        HashNode* temp = ht->table[i];
        while (temp) 
        {
            // Note the pre-increment
            if (++count == n) 
            {
                return temp; // Return the nth item
            }
            temp = temp->next;
        }
    }
    return NULL; // nth item not found
}

HashNode* findItem(HashTable* ht, int key) 
{
    // key = 13
    unsigned int index = hashFunction(key); // 13 becomes 3

    HashNode* temp = ht->table[index]; // goes to index 3
    while (temp) 
    {
        if (*((int*)temp->key) == key) 
        {
            return temp; // Key found
        }
        temp = temp->next;
    }
    return NULL; // Key not found
}

void removeItem(HashTable* ht, int key) 
{
    // remove key 11
    unsigned int index = hashFunction(key);

    HashNode* temp = ht->table[index]; //temp become 0x1
    HashNode* prev = NULL;

    // Traverse linked list at this index
    while (temp) //0x1 != NULL, so executes; temp changed to 0x4 (!= NULL)
    {
        if (*((int*)temp->key) == key) //0x1->key !=11, but 0x4->key is!
        {
            // Remove the node
            if (prev) // at this point prev = 0x1
            {
                prev->next = temp->next; //prev->next(0x4) becomes temp->next(0x16)
            } else 
            {
                ht->table[index] = temp->next; // Head node removed
            }
            free(temp->key);
            free(temp->value);
            free(temp);
            printf("Key %d removed successfully.\n", key);
            return;
        }
        prev = temp; //prev becomes temp (0x1)
        temp = temp->next; //temp becomes ->next(0x4)
    }
    printf("Key %d not found in the table.\n", key);
}

void removeAllItems(HashTable* ht) 
{
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        HashNode* temp = ht->table[i];
        while (temp) {
            HashNode* toDelete = temp;
            temp = temp->next;

            free(toDelete->key);
            free(toDelete->value);
            free(toDelete);
        }
        ht->table[i] = NULL;
    }
    printf("All items have been removed from the hash table.\n");
}

void printHashTable(HashTable* ht) 
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Index %d: ", i);
        HashNode* temp = ht->table[i];
        while (temp) 
        {
            printf("(%d, %d) -> ", *((int*)temp->key), *((int*)temp->value));
            temp = temp->next;
        }
        printf("NULL\n");
    }
}