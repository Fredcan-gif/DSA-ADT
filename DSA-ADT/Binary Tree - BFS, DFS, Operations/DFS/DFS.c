#include <stdio.h>
#include <stdlib.h>

#define MAX 9
#define VISITED -1
#define UNVISITED 100

typedef int vertex;

typedef struct node {
    int elem;
    struct node* link;
} Node, *ptr;

typedef ptr Graph[MAX];

void dfs(Graph G, vertex V, int mark[]) {
    mark[V] = VISITED;
    printf("%d ", V);

    for (ptr p = G[V]; p != NULL; p = p->link) {
        int W = p->elem;
        if (mark[W] == UNVISITED) {
            dfs(G, W, mark);
        }
    }
}

int main() {
    Graph G = {NULL};
    int mark[MAX];

    for (int i = 0; i < MAX; i++)
        mark[i] = UNVISITED;

    ptr newNode;

    newNode = malloc(sizeof(Node));
    newNode->elem = 1;
    newNode->link = G[0];
    G[0] = newNode;

    newNode = malloc(sizeof(Node));
    newNode->elem = 7;
    newNode->link = G[2];
    G[2] = newNode;

    newNode = malloc(sizeof(Node));
    newNode->elem = 4;
    newNode->link = G[2];
    G[2] = newNode;

    newNode = malloc(sizeof(Node));
    newNode->elem = 5;
    newNode->link = G[0];
    G[0] = newNode;

    newNode = malloc(sizeof(Node));
    newNode->elem = 2;
    newNode->link = G[0];
    G[0] = newNode;

    newNode = malloc(sizeof(Node));
    newNode->elem = 7;
    newNode->link = G[5];
    G[5] = newNode;

    for (int i = 0; i < MAX; i++)
        mark[i] = UNVISITED;

    printf("DFS starting at 0: ");
    dfs(G, 0, mark);
    printf("\n");

    for (int i = 0; i < MAX; i++)
        mark[i] = UNVISITED;

    printf("DFS starting at 2: ");
    dfs(G, 2, mark);
    printf("\n");

    for (int i = 0; i < MAX; i++)
        mark[i] = UNVISITED;

    printf("DFS starting at 5: ");
    dfs(G, 5, mark);
    printf("\n");

    return 0;
}
