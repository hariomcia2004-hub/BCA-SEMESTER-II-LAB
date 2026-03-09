#include <stdio.h>

int main() {
    int arr[5]; 
    int index;
    int *ptr = arr; 

   
    printf("Enter 5 elements of the array:\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d: ", i);
       
        scanf("%d", (ptr + i));
    }

   
    printf("\nEnter the index of the element to retrieve (0-4): ");
    scanf("%d", &index);

  
    if (index >= 0 && index < 5) {
       
        printf("The element at index %d is: %d\n", index, *(ptr + index));
    } else {
        printf("Invalid index entered. Please enter an index between 0 and 4.\n");
    }

    return 0;
}

