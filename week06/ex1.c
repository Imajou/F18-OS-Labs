#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 128

int main(int argc, char const *argv[])
{
    int fd[2];
    char *first = "Hello, world!";
    char *second = (char *)malloc(BUFFER_SIZE * sizeof(char));

    printf("First string: \"%s\"\n", first);
    printf("Second string: \"%s\"\n", second);


    printf("\nCreating pipe...\n");
    if (pipe(fd) == -1)
        return (1);
    printf("Transferring...\n\n");

    write(fd[1], first, BUFFER_SIZE);
    close(fd[1]);
    read(fd[0], second, BUFFER_SIZE);
    close(fd[0]);

    printf("First string: \"%s\"\n", first);
    printf("Second string: \"%s\"\n", second);

    return 0;
}
