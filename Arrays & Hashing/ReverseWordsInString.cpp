#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverseWords(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc(len + 1);
    int end = len - 1, start, pos = 0;

    while (end >= 0) {
        // Skip trailing spaces
        while (end >= 0 && s[end] == ' ') end--;

        if (end < 0) break;

        // Find the start of the word
        start = end;
        while (start >= 0 && s[start] != ' ') start--;

        // Copy the word into the result
        for (int i = start + 1; i <= end; i++) {
            result[pos++] = s[i];
        }

        // Add a space after the word
        result[pos++] = ' ';

        // Move to the next word
        end = start - 1;
    }

    // Remove trailing space and null-terminate
    if (pos > 0) result[pos - 1] = '\0';
    else result[0] = '\0';

    return result;
}

int main() {
    char s[] = "  the sky is blue  ";
    char* reversed = reverseWords(s);
    printf("Reversed: \"%s\"\n", reversed);
    free(reversed);
    return 0;
}
