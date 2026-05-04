#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > maxPages) {
            return 0;
        }

        if(pages + arr[i] > maxPages) {
            students++;
            pages = arr[i];

            if(students > m) {
                return 0;
            }
        } else {
            pages += arr[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    int sum = 0, max = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    int low = max, high = sum, ans = sum;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}