#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 50

struct Node{
    int info;
    struct Node* link;
};

void addEdge(struct Node **adjList, int src, int dest){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = dest;
    newNode->link = NULL;
    newNode->link = adjList[src];
    adjList[src] = newNode;
    
    //Undirected graph
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = src;
    newNode->link = NULL;
    newNode->link = adjList[dest];
    adjList[dest] = newNode;
}

void printGraph(struct Node **adjList, int V){
    for(int i = 0; i < V; i++){

        struct Node *save = adjList[i];
        printf("Vertex %d: ", i);

        while(save){
            printf("%d -> ", save->info);
            save = save->link;
        }
        printf("\n");
    }
}

void dfsUtil(struct Node **adjList, int V, int visited[]){
    visited[V] = 1;
    printf("%d ", V);

    struct Node *temp = adjList[V];
    while(temp){
        if(!visited[temp->info]){
            dfsUtil(adjList, temp->info, visited);
        }
        temp = temp->link;
    }
}

void dfs(struct Node **adjList, int v, int start){
    int visited[MAX_VERTEX] = {0};
    printf("DFS starting from vertex %d : ", start);
    dfsUtil(adjList, start, visited);
}

void bfs(struct Node **adjList, int start, int V){
    int visited[MAX_VERTEX] = {0};
    int queue[MAX_VERTEX];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS starting from vertex %d : ", start);

    while(front < rear){
        int v = queue[front++];
        printf("%d ", v);

        struct Node *temp = adjList[v];
        while(temp){
            if(!visited[temp->info]){
                visited[temp->info] = 1;
                queue[rear++] = temp->info;
            }
            temp = temp->link;
        }
    }
}

void main(){
    int V = 5;
    struct Node *adjList[MAX_VERTEX] = {NULL};
    
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);
    
    printGraph(adjList, V);

    dfs(adjList, V, 0);
    bfs(adjList, 0, V);
}