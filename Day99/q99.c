#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

int compare(const void *a, const void *b) {
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;
    return c2->position - c1->position;
}

int main() {
    int n;
    scanf("%d", &n);

    int target;
    scanf("%d", &target);

    Car cars[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &cars[i].position);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &cars[i].speed);
    }

    qsort(cars, n, sizeof(Car), compare);

    float stack[n];
    int top = -1;

    for(int i = 0; i < n; i++) {
        float time = (float)(target - cars[i].position) / cars[i].speed;

        if(top == -1 || time > stack[top]) {
            stack[++top] = time;
        }
    }

    printf("%d", top + 1);

    return 0;
}