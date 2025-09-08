//Hashmap
#include <stdio.h>
#define SIZE 20

struct hash{
    int key;
    int value;
};

struct hash Hash[SIZE];

void init(){
    for(int i = 0; i < SIZE; i++){
        Hash[i].key = -1;
        Hash[i].value = -1;
    }
}
int f(int key){
    return key % SIZE;
}

void add(int key, int value){
    int index = f(key);

    for (int i = 0; i < SIZE; i++) {
        int probe = (index + i) % SIZE;

        if (Hash[probe].key == -1) {   
            Hash[probe].key = key;
            Hash[probe].value = value;
            return;
        }

        if (Hash[probe].key == key) {  
            Hash[probe].value = value;
            return;
        }
    }
    printf("Hash Table is full.\n");
}

void display() {
    printf("Set elements: \n");
    for (int i = 0; i < SIZE; i++) {
        if (Hash[i].key != -1) {
            printf("Index : %d key: %d value: %d\n", i, Hash[i].key, Hash[i].value);
        }
    }
}

void main(){
    init();
    add(1, 100);
    add(21, 200);  
    add(41, 300);

    display();
}