#include <stdio.h>
#include <stdlib.h>

void dfs(int v, int **adj, int n, int *vis, int *stack, int *top) {
    vis[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !vis[i]) {
            dfs(i, adj, n, vis, stack, top);
        }
    }

    stack[(*top)++] = v;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adj[i] = (int *)calloc(n, sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u][v] = 1;
    }

    int *vis = (int *)calloc(n, sizeof(int));
    int *stack = (int *)malloc(n * sizeof(int));
    int top = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, n, vis, stack, &top);
        }
    }

    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i] + 1);
    }

    return 0;
}