#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node dummy; 
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    
    if (head1) tail->next = head1;
    if (head2) tail->next = head2;

    return dummy.next;
}


void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, i, value;
    struct Node *head1 = NULL, *head2 = NULL, *temp = NULL, *newNode = NULL;

   
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);
        if (!head1) {
            head1 = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &value);
        newNode = createNode(value);
        if (!head2) {
            head2 = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

   
    struct Node* mergedHead = mergeLists(head1, head2);
    printList(mergedHead);

    return 0;
}