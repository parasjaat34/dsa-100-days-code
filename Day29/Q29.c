#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}


struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) return head;

    int n = getLength(head);
    k = k % n; 
    if (k == 0) return head;

    
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head;

    
    int steps = n - k;
    struct Node* temp = head;
    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    
    head = temp->next;
    temp->next = NULL;

    return head;
}


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, value, k;
    struct Node* head = NULL;

    
    scanf("%d", &n);

    
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    
    scanf("%d", &k);

    
    head = rotateRight(head, k);

    
    printList(head);

    return 0;
}