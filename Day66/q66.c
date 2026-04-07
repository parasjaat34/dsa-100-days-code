
#include <stdio.h>
#include <stdlib.h>

int dfs(int v, int *vis, int *rec, int **adj, int n) {
    vis[v] = 1;
    rec[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!vis[i] && dfs(i, vis, rec, adj, n)) return 1;
            else if (rec[i]) return 1;
        }
    }

    rec[v] = 0;
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
    }

    int *vis = (int *)calloc(n, sizeof(int));
    int *rec = (int *)calloc(n, sizeof(int));

    int cycle = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(i, vis, rec, adj, n)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle) printf("YES\n");
    else printf("NO\n");

    return 0;
}

