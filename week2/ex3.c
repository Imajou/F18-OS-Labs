#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define SIZE_CHAR sizeof(char)

char *createTriangle(int n) {
    const int MAX_WIDTH = 2 * n - 1;
    char *triangle = malloc(((n + 1) * MAX_WIDTH + 1) * SIZE_CHAR);

    int index = 0;
    for (int depth = 1; depth <= n; ++depth) {
        const int CURRENT_WIDTH = 2 * depth - 1;
        for (int spaceWidth = 0; spaceWidth < (MAX_WIDTH - CURRENT_WIDTH) / 2; ++spaceWidth) {
            triangle[index] = ' ';
            ++index;
        }
        for (int stars = 0; stars < CURRENT_WIDTH; ++stars) {
            triangle[index] = '*';
            ++index;
        }
        for (int spaces = 0; spaces < (MAX_WIDTH - CURRENT_WIDTH) / 2; ++spaces) {
            triangle[index] = ' ';
            ++index;
        }
        triangle[index] = '\n';
        ++index;
    }

    triangle[index] = '\0';

    return triangle;

}

int main(int argc, char *argv[]) {

    printf("%s", createTriangle(atoi(argv[1])));

    return 0;
}