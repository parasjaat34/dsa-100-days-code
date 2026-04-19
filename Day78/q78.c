#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **g = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        g[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) g[i][j] = 0;
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

    int *key = (int *)malloc(n * sizeof(int));
    int *vis = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        vis[i] = 0;
    }

    key[0] = 0;
    int total = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        int min = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (!vis[j] && key[j] < min) {
                min = key[j];
                u = j;
            }
        }

        vis[u] = 1;
        total += key[u];

        for (int v = 0; v < n; v++) {
            if (g[u][v] && !vis[v] && g[u][v] < key[v]) {
                key[v] = g[u][v];
            }
        }
    }

    printf("%d", total);

    return 0;
}