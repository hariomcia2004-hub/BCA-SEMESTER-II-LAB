#include <stdio.h>
#include <string.h>

// Custom reverse function as strrev is non-standard in many modern compilers
void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char s1[100], s2[100], buffer[100];

   
    // b. Copying (Test: Non-empty to empty; copy empty)
    printf("Enter string to copy: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = 0;
    strcpy(buffer, s2);
    printf("Buffer after copying '%s': '%s'\n\n", s2, buffer);

    // c. Addition/Concatenation (Test: "Hello"+"World"; Empty cases)
    char first[100];
    char second[100];
    printf("Enter String 1 :");
    scanf("%s",&first);
    printf("Enter String 2 to concatenate with String 1 :");
    scanf("%s",&second);
    strcat(first, second);
    printf("Concatenation (string1+string2): %s\n", first);
    fflush(stdin);

    // d. Reverse 
    printf("Enter string to reverse: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    reverse_string(buffer);
    printf("Reversed string: %s\n", buffer);

    return 0;
}

