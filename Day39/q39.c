#include <stdio.h>
#include <string.h>
#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i) {
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int x) {
    if (size == MAX) return;
    heap[size] = x;
    heapifyUp(size);
    size++;
}

int extractMin() {
    if (size <= 0) return -1;
    if (size == 1) return heap[--size];

    int root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

int peek() {
    if (size == 0) return -1;
    return heap[0];
}

int main() {
    int N, x;
    char op[20];

    scanf("%d", &N);

    while (N--) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        }
        else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}