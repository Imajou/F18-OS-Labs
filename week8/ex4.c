#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <printf.h>
#include <sys/resource.h>

int main(int argc, char const *argv[])
{
    struct rusage *usage = (struct rusage *)malloc(sizeof(struct rusage));
    long bytes = 1024 * 1024 * 10;
    int *ptr[10];

    for (int i = 0; i < 10; ++i)
    {
        ptr[i] = (int *)malloc(bytes);
        memset(ptr[i], 0, bytes);
        getrusage(RUSAGE_SELF, usage);
        printf("%li\n", usage->ru_maxrss);
        sleep(1);
    }
    
    return 0;
}
