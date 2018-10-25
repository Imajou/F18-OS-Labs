#include <stdio.h>

void *swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main() {
    int a, b;
    scanf("%i", &a);
    scanf("%i", &b);

    swap(&a, &b);

    return 0;
}