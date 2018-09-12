#include <unistd.h>
#include <printf.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    switch(fork()) {
        case 0:
            printf("Hello from child - [%d - %s]\n", getpid(), argv[1]);
            exit(0);
        default:
            printf("Hello from parent - [%d - %s]\n", getpid(), argv[1]);
    }
    return 0;
}