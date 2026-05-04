#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

int compare(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;
    return m1->start - m2->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Meeting arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Meeting), compare);

    int rooms[n];
    int size = 0;

    for(int i = 0; i < n; i++) {
        int placed = 0;

        for(int j = 0; j < size; j++) {
            if(rooms[j] <= arr[i].start) {
                rooms[j] = arr[i].end;
                placed = 1;
                break;
            }
        }

        if(!placed) {
            rooms[size++] = arr[i].end;
        }
    }

    printf("%d", size);

    return 0;
}