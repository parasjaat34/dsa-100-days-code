#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int key;
    int value;
} HashNode;


int hash(int key, int size) {
    return (abs(key)) % size;
}

int countZeroSumSubarrays(int arr[], int n) {
    int sum = 0;
    int count = 0;

    int hashSize = 1000;
    HashNode hashMap[hashSize];

    
    for (int i = 0; i < hashSize; i++) {
        hashMap[i].key = 0;
        hashMap[i].value = 0;
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        
        if (sum == 0)
            count++;

        int index = hash(sum, hashSize);

        
        while (hashMap[index].value != 0 && hashMap[index].key != sum) {
            index = (index + 1) % hashSize;
        }

        
        if (hashMap[index].key == sum) {
            count += hashMap[index].value;
            hashMap[index].value++;
        } else {
            hashMap[index].key = sum;
            hashMap[index].value = 1;
        }
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = countZeroSumSubarrays(arr, n);
    printf("%d\n", result);

    return 0;
}