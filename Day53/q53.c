#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Queue {
    struct Node* node[1000];
    int hd[1000];
    int front, rear;
};

void enqueue(struct Queue* q, struct Node* n, int h) {
    q->node[++q->rear] = n;
    q->hd[q->rear] = h;
}

void dequeue(struct Queue* q, struct Node** n, int* h) {
    *n = q->node[q->front];
    *h = q->hd[q->front++];
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

    enqueue(&q, root, 0);

    int i = 1;

    while (i < n && q.front <= q.rear) {
        struct Node* curr;
        int h;
        dequeue(&q, &curr, &h);

        if (i < n) {
            curr->left = createNode(arr[i++]);
            if (curr->left) enqueue(&q, curr->left, h - 1);
        }

        if (i < n) {
            curr->right = createNode(arr[i++]);
            if (curr->right) enqueue(&q, curr->right, h + 1);
        }
    }

    return root;
}

struct MapNode {
    int hd;
    int val;
    struct MapNode* next;
};

struct MapNode* insert(struct MapNode* head, int hd, int val) {
    struct MapNode* n = (struct MapNode*)malloc(sizeof(struct MapNode));
    n->hd = hd;
    n->val = val;
    n->next = NULL;

    if (!head || hd < head->hd) {
        n->next = head;
        return n;
    }

    struct MapNode* temp = head;
    while (temp->next && temp->next->hd <= hd)
        temp = temp->next;

    n->next = temp->next;
    temp->next = n;

    return head;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Queue q;
    q.front = 0;
    q.rear = -1;

    enqueue(&q, root, 0);

    struct MapNode* head = NULL;

    int minHD = 0, maxHD = 0;

    while (q.front <= q.rear) {
        struct Node* curr;
        int hd;
        dequeue(&q, &curr, &hd);

        head = insert(head, hd, curr->data);

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (curr->left) enqueue(&q, curr->left, hd - 1);
        if (curr->right) enqueue(&q, curr->right, hd + 1);
    }

    for (int i = minHD; i <= maxHD; i++) {
        struct MapNode* temp = head;
        while (temp) {
            if (temp->hd == i)
                printf("%d ", temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}