#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

int pop() {
    if (top == NULL) return -1;
    struct node *temp = top;
    int value = temp->data;
    top = temp->next;
    free(temp);
    return value;
}

int main() {
    char exp[100];
    int i = 0;
    int op1, op2, result;

    fgets(exp, sizeof(exp), stdin);

    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            op2 = pop();
            op1 = pop();

            switch (exp[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }
            push(result);
        }
        i++;
    }

    printf("%d", pop());
    return 0;
}