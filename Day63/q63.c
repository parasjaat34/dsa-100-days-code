#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* create(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->v = v;
    n->next = NULL;
    return n;
}

void dfs(int s, Node* adj[], int visited[]) {
    visited[s] = 1;
    printf("%d ", s);
    Node* temp = adj[s];
    while (temp) {
        if (!visited[temp->v])
            dfs(temp->v, adj, visited);
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);
            Node* node = create(v);
            node->next = adj[i];
            adj[i] = node;
        }
    }

    int s;
    scanf("%d", &s);

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(s, adj, visited);

    return 0;
}