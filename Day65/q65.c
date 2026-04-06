#include <stdio.h>
#include <stdlib.h>

int dfs(int v, int parent, int *visited, int **adj, int n) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (dfs(i, v, visited, adj, n)) return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
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
        adj[v][u] = 1;
    }

    int *visited = (int *)calloc(n, sizeof(int));
    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, n)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle) printf("YES\n");
    else printf("NO\n");

    return 0;
}