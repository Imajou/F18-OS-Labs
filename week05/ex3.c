#include <pthread/pthread.h>
#include <stdlib.h>
#include <printf.h>

#define SIZE 100

int buffer[SIZE] = {0};

static int count = 0;
int s_consumer = 0;
int s_producer = 0;

int incvalue = 0;

void *producer()
{
    while (1)
    {
        while (s_producer);
        if (count == SIZE)
        {
            printf("Producer is being put to sleep\n");
            s_producer = 1;
            continue;
        }
        ++incvalue;
        printf("Producing %d\n", incvalue);
        buffer[count++] = incvalue;
        if (s_consumer)
            s_consumer = 0;
    }
    pthread_exit(NULL);
}

void *consumer()
{
    while (1)
    {
        while (s_consumer);
        if (count == 0)
        {
            printf("Consumer is being put to sleep\n");
            s_consumer = 1;
            continue;
        }
        printf("Consume %d\n", buffer[--count]);
        if (s_producer)
            s_producer = 0;
    }
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t id_cons, id_prod;
    pthread_create(&id_prod, NULL, producer, NULL);
    pthread_create(&id_cons, NULL, consumer, NULL);

    pthread_join(id_prod, NULL);
    pthread_join(id_cons, NULL);
    return 0;
}
