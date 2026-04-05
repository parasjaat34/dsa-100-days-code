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

    int queue[n];
    int front = 0, rear = 0;

    visited[s] = 1;
    queue[rear++] = s;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        Node* temp = adj[u];
        while (temp) {
            if (!visited[temp->v]) {
                visited[temp->v] = 1;
                queue[rear++] = temp->v;
            }
            temp = temp->next;
        }
    }

    return 0;
}