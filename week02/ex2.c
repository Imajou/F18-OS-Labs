#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define SIZE_CHAR sizeof(char)
#define STR_MAX_LEN 50

char *reverse(char *string) {
    char *stringReversed = malloc(strlen(string) * SIZE_CHAR);
    for (int i = (int) strlen(string) - 2, j = 0; i >= 0; --i, ++j) {
        stringReversed[j] = string[i];
    }
    stringReversed[strlen(string) - 1] = '\0';
    return stringReversed;
}

int main() {
    char string[STR_MAX_LEN];
    fgets(string, STR_MAX_LEN, stdin);

    printf("%s", reverse(string));

    return 0;
}