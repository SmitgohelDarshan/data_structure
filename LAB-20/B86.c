#include <stdio.h>
#include <string.h>
#define SIZE 20

struct hash {
    int key;
    char value[50];   
};

struct hash Hash[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        Hash[i].key = -1;
        strcpy(Hash[i].value, "");
    }
}

int f(int key) {
    return key % SIZE;
}

void add(int key, char value[]) {
    int index = f(key);

    for (int i = 0; i < SIZE; i++) {
        int probe = (index + i) % SIZE;

        if (Hash[probe].key == -1) {
            Hash[probe].key = key;
            strcpy(Hash[probe].value, value);
            return;
        }

        if (Hash[probe].key == key) {  
            strcpy(Hash[probe].value, value);
            return;
        }
    }

    printf("Dictionary is full.\n");
}

char* get(int key) {
    int index = f(key);

    for (int i = 0; i < SIZE; i++) {
        int probe = (index + i) % SIZE;

        if (Hash[probe].key == key) {
            return Hash[probe].value;
        }

        if (Hash[probe].key == -1) {
            break;
        }
    }

    return NULL;  
}

void delete(int key) {
    int index = f(key);

    for (int i = 0; i < SIZE; i++) {
        int probe = (index + i) % SIZE;

        if (Hash[probe].key == key) {
            Hash[probe].key = -1;
            strcpy(Hash[probe].value, "");
            printf("Key %d deleted.\n", key);
            return;
        }
        if (Hash[probe].key == -1) {  
            break;
        }
    }

    printf("Key %d not found.\n", key);
}

void display() {
    printf("\nDictionary:\n");
    for (int i = 0; i < SIZE; i++) {
        if (Hash[i].key != -1) {
            printf("Index %d -> Key: %d, Value: %s\n", i, Hash[i].key, Hash[i].value);
        }
    }
}

void main() {
    init();

    add(1, "Apple");
    add(21, "Banana");
    add(41, "Cherry");   
    add(2, "Mango");

    display();

    printf("\nSearching key 21 -> %s\n", get(21));
    printf("Searching key 3 -> %s\n", get(3) ? get(3) : "Not Found");

    delete(21);
    display();
}