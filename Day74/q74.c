#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][50];
    int count[n];

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
        count[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (count[i] == 0) continue;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) == 0) {
                count[i]++;
                count[j] = 0;
            }
        }
    }

    int max = 0;
    char winner[50];

    for (int i = 0; i < n; i++) {
        if (count[i] > max) {
            max = count[i];
            strcpy(winner, names[i]);
        } 
        else if (count[i] == max && strcmp(names[i], winner) < 0) {
            strcpy(winner, names[i]);
        }
    }

    printf("%s %d", winner, max);

    return 0;
}