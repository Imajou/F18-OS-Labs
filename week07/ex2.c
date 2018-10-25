#include <stdlib.h>
#include <printf.h>

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);

    int *array = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; ++i)
    {
        array[i] = i;
    }

    for (int i = 0; i < N; ++i)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    free(array);

    return 0;
}
