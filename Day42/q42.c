#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Stack {
    struct Node* top;
};

void enqueue(struct Queue* q, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL)
        return -1;
    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return val;
}

void push(struct Stack* s, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = s->top;
    s->top = temp;
}

int pop(struct Stack* s) {
    if (s->top == NULL)
        return -1;
    struct Node* temp = s->top;
    int val = temp->data;
    s->top = s->top->next;
    free(temp);
    return val;
}

int main() {
    int n, x;
    scanf("%d", &n);
    struct Queue q;
    struct Stack s;
    q.front = q.rear = NULL;
    s.top = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    while (q.front != NULL)
        push(&s, dequeue(&q));

    while (s.top != NULL)
        enqueue(&q, pop(&s));

    struct Node* temp = q.front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}