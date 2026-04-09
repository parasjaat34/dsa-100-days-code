#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adj[i] = (int *)calloc(n, sizeof(int));
    }

    int *indegree = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u][v] = 1;
        indegree[v]++;
    }

    int *queue = (int *)malloc(n * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u + 1);
        count++;

        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    return 0;
}