#include <stdio.h>
#include <stdlib.h>

#define SIZE 10    // size of hash table
#define EMPTY -1   // marker for empty slot
#define DELETED -2 // marker for deleted slot

int hashTable[SIZE];

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert function (with linear probing)
void insert(int key) {
    int index = hash(key);
    int i = 0;
    while (i < SIZE) {
        int newIndex = (index + i) % SIZE;
        if (hashTable[newIndex] == EMPTY || hashTable[newIndex] == DELETED) {
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        } else if (hashTable[newIndex] == key) {
            printf("Key %d already exists at index %d\n", key, newIndex);
            return;
        }
        i++;
    }
    printf("Hash table is full! Cannot insert %d\n", key);
}

// Search function
void search(int key) {
    int index = hash(key);
    int i = 0;
    while (i < SIZE) {
        int newIndex = (index + i) % SIZE;
        if (hashTable[newIndex] == key) {
            printf("Key %d found at index %d\n", key, newIndex);
            return;
        } else if (hashTable[newIndex] == EMPTY) {
            printf("Key %d not found in hash table.\n", key);
            return;
        }
        i++;
    }
    printf("Key %d not found in hash table.\n", key);
}

// Delete function
void deleteKey(int key) {
    int index = hash(key);
    int i = 0;
    while (i < SIZE) {
        int newIndex = (index + i) % SIZE;
        if (hashTable[newIndex] == key) {
            hashTable[newIndex] = DELETED;
            printf("Key %d deleted from index %d\n", key, newIndex);
            return;
        } else if (hashTable[newIndex] == EMPTY) {
            printf("Key %d not found in hash table.\n", key);
            return;
        }
        i++;
    }
    printf("Key %d not found in hash table.\n", key);
}

// Display hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("Index %d: [EMPTY]\n", i);
        else if (hashTable[i] == DELETED)
            printf("Index %d: [DELETED]\n", i);
        else
            printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    int choice, key;
    // Initialize hash table
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = EMPTY;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
