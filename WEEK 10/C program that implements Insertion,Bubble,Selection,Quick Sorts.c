#include <stdio.h>
#include <string.h>

void swapChars(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void swapInts(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSortInt(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSortChar(char arr[], int n) {
    int i,j;
	for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swapChars(&arr[j], &arr[j + 1]);
        }
    }
}

void selectionSortInt(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swapInts(&arr[min_idx], &arr[i]);
    }
}

int partition(char arr[], int low, int high) {
    int j;
	char pivot = arr[high];
    int i = (low - 1);
    for ( j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swapChars(&arr[i], &arr[j]);
        }
    }
    swapChars(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortChar(char arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortChar(arr, low, pi - 1);
        quickSortChar(arr, pi + 1, high);
    }
}

int main() {
    int choice, n, i;
    int intArr[100];
    char charArr[100];

    printf("--- Sorting Algorithm Tester ---\n");
    printf("1. Insertion Sort (Integers)\n");
    printf("2. Bubble Sort (Characters)\n");
    printf("3. Selection Sort (Integers)\n");
    printf("4. Quick Sort (Characters)\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter number of elements: ");
            scanf("%d", &n);
            printf("Enter %d integers: ", n);
            for(i=0; i<n; i++) scanf("%d", &intArr[i]);
            insertionSortInt(intArr, n);
            printf("Sorted: ");
            for(i=0; i<n; i++) printf("%d ", intArr[i]);
            break;

        case 2:
            printf("Enter string to bubble sort: ");
            scanf("%s", charArr);
            bubbleSortChar(charArr, strlen(charArr));
            printf("Sorted String: %s", charArr);
            break;

        case 3:
            printf("Enter number of elements: ");
            scanf("%d", &n);
            printf("Enter %d integers: ", n);
            for(i=0; i<n; i++) scanf("%d", &intArr[i]);
            selectionSortInt(intArr, n);
            printf("Sorted: ");
            for(i=0; i<n; i++) printf("%d ", intArr[i]);
            break;

        case 4:
            printf("Enter string to quick sort: ");
            scanf("%s", charArr);
            quickSortChar(charArr, 0, strlen(charArr) - 1);
            printf("Sorted String: %s", charArr);
            break;

        default:
            printf("Invalid choice!");
    }
    printf("\n");
    return 0;
}
