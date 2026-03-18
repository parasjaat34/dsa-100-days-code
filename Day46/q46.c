#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Queue {
    struct Node* arr[1000];
    int front, rear;
};

void enqueue(struct Queue* q, struct Node* n) {
    q->arr[++q->rear] = n;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

struct Node* createNode(int x) {
    if (x == -1) return NULL;
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (n == 0) return 0;

    struct Node* root = createNode(arr[0]);

    struct Queue q;
    q.front = 0;
    q.rear = -1;

    if (root) enqueue(&q, root);

    int i = 1;

    while (i < n && q.front <= q.rear) {
        struct Node* curr = dequeue(&q);

        if (i < n) {
            curr->left = createNode(arr[i++]);
            if (curr->left) enqueue(&q, curr->left);
        }

        if (i < n) {
            curr->right = createNode(arr[i++]);
            if (curr->right) enqueue(&q, curr->right);
        }
    }

    struct Queue q2;
    q2.front = 0;
    q2.rear = -1;

    if (root) enqueue(&q2, root);

    while (q2.front <= q2.rear) {
        struct Node* curr = dequeue(&q2);
        printf("%d ", curr->data);
        if (curr->left) enqueue(&q2, curr->left);
        if (curr->right) enqueue(&q2, curr->right);
    }

    return 0;
}