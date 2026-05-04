#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

int *countSmaller;

void merge(Pair arr[], Pair temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while(i <= mid && j <= right) {
        if(arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            countSmaller[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while(i <= mid) {
        countSmaller[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while(j <= right) {
        temp[k++] = arr[j++];
    }

    for(i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(Pair arr[], Pair temp[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);

        merge(arr, temp, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    Pair arr[n];
    Pair temp[n];

    countSmaller = (int *)calloc(n, sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    mergeSort(arr, temp, 0, n - 1);

    for(int i = 0; i < n; i++) {
        printf("%d ", countSmaller[i]);
    }

    return 0;
}