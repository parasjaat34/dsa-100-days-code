#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int v;
    int dist;
} Node;

void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(Node *heap, int i) {
    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(Node *heap, int size, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && heap[l].dist < heap[smallest].dist)
        smallest = l;
    if (r < size && heap[r].dist < heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void push(Node *heap, int *size, int v, int dist) {
    heap[*size].v = v;
    heap[*size].dist = dist;
    heapifyUp(heap, *size);
    (*size)++;
}

Node pop(Node *heap, int *size) {
    Node root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return root;
}

int main() {
    int n, m, src;
    scanf("%d %d", &n, &m);

    int **adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adj[i] = (int *)calloc(n, sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    scanf("%d", &src);
    src--;

    int *dist = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;

    Node *heap = (Node *)malloc(n * n * sizeof(Node));
    int size = 0;

    dist[src] = 0;
    push(heap, &size, src, 0);

    while (size > 0) {
        Node curr = pop(heap, &size);
        int u = curr.v;

        if (curr.dist > dist[u]) continue;

        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                if (dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    push(heap, &size, v, dist[v]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }

    return 0;
}