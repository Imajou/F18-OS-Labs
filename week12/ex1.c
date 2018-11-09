#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 20

int main()
{
    char buffer[BUFFER_SIZE];

    int file_read = open("/dev/random", O_RDONLY);
    read(file_read, buffer, BUFFER_SIZE);

    FILE *file_write = fopen("ex1.txt", "w");

    for (int i = 0; i < BUFFER_SIZE; ++i)
    {
        fprintf(file_write, "%d", buffer[i]);
    }
    fprintf(file_write, "\n");
    fclose(file_write);

    return 0;
    
}
