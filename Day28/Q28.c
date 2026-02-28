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
        newNode->next = newNode; 
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != head) { 
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}


void printCircularList(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n, value;
    struct Node* head = NULL;

  
    scanf("%d", &n);

    
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    
    printCircularList(head);

    return 0;
}