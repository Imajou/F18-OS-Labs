#include <unistd.h>
#include <printf.h>
#include <stdlib.h>
#include <memory.h>

#define BUFFER_SIZE 64

int main(int argc, char *argv[]) {
    while (1) {
        printf(" glebash-0.1$ ");
        char input[BUFFER_SIZE] = "";
        fgets(input, BUFFER_SIZE, stdin);
        if (!strcmp(input, "exit\n")) return 0;
        system(input);
    }
}