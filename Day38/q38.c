#include <stdio.h>
#include <string.h>
#define MAX 100

int dq[MAX];
int front = -1, rear = -1, count = 0;

int isEmpty() { return count == 0; }
int isFull() { return count == MAX; }

void push_front(int x) {
    if (isFull()) return;
    if (isEmpty()) front = rear = 0;
    else front = (front - 1 + MAX) % MAX;
    dq[front] = x;
    count++;
}

void push_back(int x) {
    if (isFull()) return;
    if (isEmpty()) front = rear = 0;
    else rear = (rear + 1) % MAX;
    dq[rear] = x;
    count++;
}

void pop_front() {
    if (isEmpty()) return;
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
    count--;
}

void pop_back() {
    if (isEmpty()) return;
    if (front == rear) front = rear = -1;
    else rear = (rear - 1 + MAX) % MAX;
    count--;
}

int getFront() { return isEmpty() ? -1 : dq[front]; }
int getBack() { return isEmpty() ? -1 : dq[rear]; }
int size() { return count; }

void display() {
    if (isEmpty()) return;
    int i = front;
    for (int c = 0; c < count; c++) {
        printf("%d ", dq[i]);
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    while (n--) {
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        }
        else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        }
        else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        }
        else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        }
        else if (strcmp(op, "front") == 0) {
            printf("%d\n", getFront());
        }
        else if (strcmp(op, "back") == 0) {
            printf("%d\n", getBack());
        }
        else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        }
        else if (strcmp(op, "display") == 0) {
            display();
            printf("\n");
        }
    }
    return 0;
}