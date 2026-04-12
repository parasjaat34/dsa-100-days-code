#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

int hash(int key, int m) {
    return key % m;
}

int main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    int *table = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) table[i] = EMPTY;

    char op[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            int h = hash(key, m);
            for (int j = 0; j < m; j++) {
                int idx = (h + j * j) % m;
                if (table[idx] == EMPTY) {
                    table[idx] = key;
                    break;
                }
            }
        }

        else if (strcmp(op, "SEARCH") == 0) {
            int h = hash(key, m);
            int found = 0;

            for (int j = 0; j < m; j++) {
                int idx = (h + j * j) % m;

                if (table[idx] == EMPTY) break;

                if (table[idx] == key) {
                    found = 1;
                    break;
                }
            }

            if (found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    return 0;
}