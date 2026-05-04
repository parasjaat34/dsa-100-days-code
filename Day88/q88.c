#include <stdio.h>
#include <stdlib.h>

int canPlace(int arr[], int n, int k, int dist) {
    int count = 1;
    int last = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] - last >= dist) {
            count++;
            last = arr[i];
        }
        if(count >= k) {
            return 1;
        }
    }
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int low = 1;
    int high = arr[n - 1] - arr[0];
    int ans = 0;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(canPlace(arr, n, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d", ans);

    return 0;
}