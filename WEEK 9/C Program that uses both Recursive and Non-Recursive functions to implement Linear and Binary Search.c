#include <stdio.h>

int linearSearchNonRecursive(int arr[], int n, int key) {
    int i;
	for ( i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int linearSearchRecursive(int arr[], int n, int key, int index) {
    if (index >= n) return -1;
    if (arr[index] == key) return index;
    return linearSearchRecursive(arr, n, key, index + 1);
}

int binarySearchNonRecursive(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) return mid;
    if (arr[mid] < key) return binarySearchRecursive(arr, mid + 1, high, key);
    return binarySearchRecursive(arr, low, mid - 1, key);
}

int main() {
    int n,i, key, choice, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d integers (sorted for Binary Search): ", n);
    for ( i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    printf("\nChoose Search Method:\n1. Linear (Non-Recursive)\n2. Linear (Recursive)\n3. Binary (Non-Recursive)\n4. Binary (Recursive)\nChoice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: result = linearSearchNonRecursive(arr, n, key); break;
        case 2: result = linearSearchRecursive(arr, n, key, 0); break;
        case 3: result = binarySearchNonRecursive(arr, 0, n - 1, key); break;
        case 4: result = binarySearchRecursive(arr, 0, n - 1, key); break;
        default: printf("Invalid choice!\n"); return 0;
    }

    if (result != -1) printf("Element found at index: %d\n", result);
    else printf("Element not found.\n");

    return 0;
}
