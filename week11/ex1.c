
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

    int file = open("ex1.txt", O_RDWR, (mode_t)0600);
    if (file == -1)
    {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    struct stat filestat = {};
    off_t filesize = filestat.st_size;
    
    char *filemap = mmap(0, (size_t) filesize, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
    if (filemap == MAP_FAILED)
    {
        close(file);
        perror("Error mmapping the file");
        exit(EXIT_FAILURE);
    }

    char *string = "This is a nice day\n\0";
    for (off_t i = 0; i < 20; ++i) {
        filemap[i] = string[i];
    }

    msync(filemap, 20, MS_SYNC);
    munmap(filemap, filestat.st_size);
    close(file);

    return 0;

}
