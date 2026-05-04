#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 10

struct Node {
    float data;
    struct Node* next;
};

void insert(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    while(temp->next != NULL && temp->next->data < value) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void bucketSort(float arr[], int n) {
    struct Node* buckets[BUCKETS];

    for(int i = 0; i < BUCKETS; i++) {
        buckets[i] = NULL;
    }

    for(int i = 0; i < n; i++) {
        int index = arr[i] * BUCKETS;
        insert(&buckets[index], arr[i]);
    }

    int k = 0;

    for(int i = 0; i < BUCKETS; i++) {
        struct Node* temp = buckets[i];

        while(temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    for(int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}