#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct HashEntry {
    char* key;
    int value;
    int isOccupied;
} HashEntry;

HashEntry hashTable[TABLE_SIZE] = {0};

unsigned int hashFunction(char* key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key;
        key++;
    }
    return hash % TABLE_SIZE;
}

void insert(char* key, int value) {
    unsigned int index = hashFunction(key);
    while (hashTable[index].isOccupied) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index].key = strdup(key);
    hashTable[index].value = value;
    hashTable[index].isOccupied = 1;
}

int search(char* key) {
    unsigned int index = hashFunction(key);
    unsigned int start = index;
    while (hashTable[index].isOccupied) {
        if (strcmp(hashTable[index].key, key) == 0) {
            return hashTable[index].value;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start) break;
    }
    return -1; // Not found
}

void printHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].isOccupied) {
            printf("Index %d: (%s, %d)\n", i, hashTable[i].key, hashTable[i].value);
        } else {
            printf("Index %d: NULL\n", i);
        }
    }
}

int main() {
    insert("apple", 10);
    insert("banana", 20);
    insert("orange", 30);

    printf("Hash Table:\n");
    printHashTable();

    printf("Value for 'apple': %d\n", search("apple"));

    return 0;
}

// void resizeHashTable(HashTable* ht) {
//     int oldSize = TABLE_SIZE;
//     Node* oldTable[TABLE_SIZE];
//     memcpy(oldTable, ht->table, sizeof(ht->table));

//     int newSize = oldSize * 2;
//     ht->table = calloc(newSize, sizeof(Node*));

//     for (int i = 0; i < oldSize; i++) {
//         Node* temp = oldTable[i];
//         while (temp) {
//             insert(ht, temp->key, temp->value);
//             temp = temp->next;
//         }
//     }
// }