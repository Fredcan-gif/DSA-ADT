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

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int x) {
    if (q->rear == MAX-1) return;
    if (q->front == -1) q->front = 0;
    q->data[++q->rear] = x;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) return -1;
    int val = q->data[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return val;
}

void bfs(Graph G, vertex V, int mark[]) {
    Queue q;
    initQueue(&q);

    printf("%d ", V);
    mark[V] = VISITED;
    enqueue(&q, V);

    while (!isEmpty(&q)) {
        int U = dequeue(&q);

        for (ptr p = G[U]; p != NULL; p = p->link) {
            int W = p->elem;

            if (mark[W] == UNVISITED) {
                printf("%d ", W);
                mark[W] = VISITED;
                enqueue(&q, W);
            }
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
    
    printf("BFS starting at 0: ");
    bfs(G, 0, mark);
    printf("\n");
    
    for (int i = 0; i < MAX; i++)
    mark[i] = UNVISITED;
    
    printf("BFS starting at 2: ");
    bfs(G, 2, mark);
    printf("\n");
    
    for (int i = 0; i < MAX; i++)
    mark[i] = UNVISITED;
    
    printf("BFS starting at 5: ");
    bfs(G, 5, mark);
    printf("\n");

    return 0;
}
