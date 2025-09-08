#include <stdio.h>
#define SIZE 20

int hashSet[SIZE];

void init(){
    for(int i = 0; i < SIZE; i++){
        hashSet[i] = -1;
    }
}

int f(int x){
    return (x % 18) + 2;
}

void add(int x){
    int index = f(x);

    if(hashSet[index] == -1)    hashSet[index] = x;
    else if(hashSet[index] == x)    return;
    else{
        for(int i = 0; i < SIZE; i++){
            int probe = (index + i) % SIZE;
            if(hashSet[probe] == -1){
                hashSet[probe] = x;
                return;
            }
            else if(hashSet[probe] == x)    return;
        }
        printf("Set is full.");
    }
}

int contains(int x) {
    // for (int i = 0; i < SIZE; i++) {
    //     if (hashSet[i] == x) return 1;
    // }

    int idx = f(x);
    for (int i = 0; i < SIZE; i++) {
        int probe = (idx + i) % SIZE;

        if (hashSet[probe] == -1)   return 0;
        if (hashSet[probe] == x)    return 1;
    }
    return 0;
}

void display() {
    printf("Set elements: ");
    for (int i = 0; i < SIZE; i++) {
        if (hashSet[i] != -1) {
            printf("%d ", hashSet[i]);
        }
    }
}

void main(){
    int a[SIZE];
    init();
    
    printf("Enter Elements: \n");

    for(int i = 0; i < 15; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < 15; i++){
        add(a[i]);
    }

    display();
}