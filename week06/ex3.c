#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void sigintHandler(int signum)
{
    printf("You hit Ctrl-C, what a nasty one!\n");
    exit(0);
}

int main(int argc, char const *argv[])
{
    printf("Catching SIGINT...\n");
    signal(SIGINT, sigintHandler);
    while(1);
}
