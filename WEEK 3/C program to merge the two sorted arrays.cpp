#include <stdio.h>

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Traverse both arrays and add the smaller element to the merged array
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // If elements are remaining in the first array, append them
    while (i < size1) {
        merged[k++] = arr1[i++];
    }

    // If elements are remaining in the second array, append them
    while (j < size2) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int arr1[50], arr2[50], merged[100]; // Declare arrays with sufficient maximum size
    int n1, n2, i;

    // Input for the first array
    printf("Enter number of elements in the first array (max 50): ");
    scanf("%d", &n1);
    printf("Enter sorted elements of the first array: \n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    // Input for the second array
    printf("Enter number of elements in the second array (max 50): ");
    scanf("%d", &n2);
    printf("Enter sorted elements of the second array: \n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Merge the arrays
    mergeSortedArrays(arr1, n1, arr2, n2, merged);

    // Print the merged sorted array
    printf("Merged sorted array: ");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}

