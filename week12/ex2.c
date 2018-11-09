#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 200

int main(int argc, char *argv[])
{

    char buffer[BUFFER_SIZE];

    FILE *file_write;
    char *mode = "w";

    for (int i = 1; i < argc; i++)
        if (strcmp(argv[i], "-a") == 0)
        {
            mode = "a";
            break;
        }

    read(STDIN_FILENO, buffer, BUFFER_SIZE);

    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "-a") == 0)
            continue;
        file_write = fopen(argv[i], mode);
        fprintf(file_write, "%s", buffer);
        fclose(file_write);
    }

    fwrite(buffer, 1, BUFFER_SIZE, stdout);

    return 0;

}
