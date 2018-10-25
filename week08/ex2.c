#include <stdlib.h>
#include <unistd.h>
#include <memory.h>

int main(int argc, char const *argv[])
{
    long bytes = 1024 * 1024 * 10;
    int *ptr[10];
    for (int i = 0; i < 10; ++i)
    {
        ptr[i] = (int *)malloc(bytes);
        memset(ptr[i], 0, bytes);
        sleep(1);
    }
    return 0;
}
