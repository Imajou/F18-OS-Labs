#include <pthread/pthread.h>
#include <stdlib.h>
#include <printf.h>

#define N 100

void *thread(void *vargp)
{
    printf("Thread number %d ", *(int *)vargp);
    printf("Here come dat boi, oh shit waddup!\n");
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t *ids = (pthread_t *)malloc(N * sizeof(pthread_t));

    for (int i = 0; i < N; ++i)
    {
        int *num = (int *)malloc(sizeof(int));
        *num = i + 1;
        printf("Creating thread %d\n", i);
        pthread_create(&ids[i], NULL, thread, (void *)num);
    }

    for (int i = 0; i < N; ++i)
    {
        pthread_join(ids[i], NULL);
    }
    
    return 0;
}
