#include <stdio.h>

int main() {
    int arr[100]; 
    int n, i;
    int *ptr;     

    printf("Enter the number of elements (max 100): ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]); 
    }

   
    ptr = arr; 

    printf("\nTraversing the array using pointers:\n");
    for (i = 0; i < n; i++) {
       
        printf("Element %d: %d\n", i, *(ptr + i));
    }

    return 0;
}

