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

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* root = createNode(arr[0]);

    struct Queue q;
    q.front = 0;
    q.rear = -1;

    enqueue(&q, root);

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

    return root;
}

void zigzag(struct Node* root) {
    if (!root) return;

    struct Queue q;
    q.front = 0;
    q.rear = -1;

    enqueue(&q, root);

    int leftToRight = 1;

    while (q.front <= q.rear) {
        int size = q.rear - q.front + 1;
        int level[1000];
        int idx = 0;

        for (int i = 0; i < size; i++) {
            struct Node* curr = dequeue(&q);
            level[idx++] = curr->data;

            if (curr->left) enqueue(&q, curr->left);
            if (curr->right) enqueue(&q, curr->right);
        }

        if (!leftToRight) {
            for (int i = 0; i < idx / 2; i++) {
                int temp = level[i];
                level[i] = level[idx - i - 1];
                level[idx - i - 1] = temp;
            }
        }

        for (int i = 0; i < idx; i++)
            printf("%d ", level[i]);

        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    zigzag(root);

    return 0;
}