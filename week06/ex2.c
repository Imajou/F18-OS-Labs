#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 128
#define LINE_OUT "Hello, world!"

int fd[2];

int createPipe()
{
    printf("Creating pipe...\n");
    if (pipe(fd) == -1)
        return 1;
    return 0;
}

int createFork()
{
    printf("Forking process...\n");
    return fork();
}

int main()
{
    if (createPipe() != 0)
        return 1;

    int pid = createFork();

    switch (pid)
    {
    case -1:
        return (1);

    case 0:
    {
        char l_buffer[BUFFER_SIZE];
        close(fd[1]);
        read(fd[0], l_buffer, BUFFER_SIZE);
        close(fd[0]);
        printf("Read from pipe: %s\n", l_buffer);
        break;
    }

    default:
    {
        close(fd[0]);
        printf("Sending line...\n");
        write(fd[1], LINE_OUT, BUFFER_SIZE);
        close(fd[1]);
        break;
    }
    }

    return 0;
}
