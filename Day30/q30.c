#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head, int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;

    return head;
}

void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    int first = 1;

    while (temp != NULL) {
        if (!first && temp->coeff >= 0) printf(" + ");
        else if (temp->coeff < 0) printf(" - ");

        int absCoeff = temp->coeff >= 0 ? temp->coeff : -temp->coeff;

        if (temp->exp == 0) printf("%d", absCoeff);
        else if (temp->exp == 1) {
            if (absCoeff != 1) printf("%d", absCoeff);
            printf("x");
        } else {
            if (absCoeff != 1) printf("%d", absCoeff);
            printf("x^%d", temp->exp);
        }

        temp = temp->next;
        first = 0;
    }
    printf("\n");
}

int main() {
    int n, coeff, exp;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        head = insertEnd(head, coeff, exp);
    }

    printPolynomial(head);

    return 0;
}