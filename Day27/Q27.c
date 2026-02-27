
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
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *ptr1 = head1, *ptr2 = head2;
    int diff = len1 - len2;
    if (diff > 0) {
        while (diff--) ptr1 = ptr1->next;
    } else {
        diff = -diff;
        while (diff--) ptr2 = ptr2->next;
    }
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insertEnd(head1, value);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = insertEnd(head2, value);
    }
    struct Node *temp1 = head1;
    struct Node *intersectNode = NULL;
    while (temp1 != NULL) {
        struct Node *temp2 = head2;
        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                intersectNode = temp1;
                temp2->next = temp1->next;
                break;
            }
            temp2 = temp2->next;
        }
        if (intersectNode != NULL) break;
        temp1 = temp1->next;
    }

    struct Node* result = findIntersection(head1, head2);
    if (result != NULL) {
        printf("%d", result->data);
    } else {
        printf("No Intersection");
    }

    return 0;
}