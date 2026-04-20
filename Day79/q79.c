#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int v, dist;
} Node;

void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

void heapUp(Node *h, int i) {
    while (i > 0 && h[(i - 1) / 2].dist > h[i].dist) {
        swap(&h[i], &h[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapDown(Node *h, int n, int i) {
    int s = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && h[l].dist < h[s].dist) s = l;
    if (r < n && h[r].dist < h[s].dist) s = r;

    if (s != i) {
        swap(&h[i], &h[s]);
        heapDown(h, n, s);
    }
}

void push(Node *h, int *n, int v, int d) {
    h[*n].v = v;
    h[*n].dist = d;
    heapUp(h, *n);
    (*n)++;
}

Node pop(Node *h, int *n) {
    Node t = h[0];
    h[0] = h[*n - 1];
    (*n)--;
    heapDown(h, *n, 0);
    return t;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **g = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        g[i] = (int *)calloc(n, sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        if (g[u][v] == 0 || w < g[u][v]) {
            g[u][v] = w;
            g[v][u] = w;
        }
    }

    int src;
    scanf("%d", &src);
    src--;

    int *dist = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    Node *heap = (Node *)malloc(n * n * sizeof(Node));
    int size = 0;

    push(heap, &size, src, 0);

    while (size > 0) {
        Node cur = pop(heap, &size);
        int u = cur.v;

        if (cur.dist > dist[u]) continue;

        for (int v = 0; v < n; v++) {
            if (g[u][v]) {
                if (dist[u] + g[u][v] < dist[v]) {
                    dist[v] = dist[u] + g[u][v];
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