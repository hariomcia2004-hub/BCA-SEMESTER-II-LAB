#include <stdio.h>
#include <string.h>

void removeWord(char *str, const char *word) {
    int i, j, k, len, wordLen;
    len = strlen(str);
    wordLen = strlen(word);

    for (i = 0; i <= len - wordLen; i++) {
        // Check if the current segment matches the word
        int match = 1;
        for (j = 0; j < wordLen; j++) {
            if (str[i + j] != word[j]) {
                match = 0;
                break;
            }
        }

        // If match found, shift remaining string left to overwrite word
        if (match) {
            // SPACING RULE: If removing word at start or multiple times, 
            // we remove the word and one trailing space if it exists.
            int shiftLen = wordLen;
            if (str[i + wordLen] == ' ') {
                shiftLen++; // Remove space after the word
            } else if (i > 0 && str[i - 1] == ' ') {
                // If it's at the end, try to remove the preceding space
                i--; 
                shiftLen++;
            }

            for (k = i; k < len - shiftLen; k++) {
                str[k] = str[k + shiftLen];
            }
            str[len - shiftLen] = '\0';
            len -= shiftLen;
            i--; // Re-check the current index for consecutive matches
        }
    }
}

int main() {
    char str[100], word[50];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline

    printf("Enter word to remove: ");
    scanf("%s", word);

    removeWord(str, word);

    printf("Result: '%s'\n", str);
    return 0;
}

