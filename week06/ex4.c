#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

// SIGKILL cannot be caught or ignored, so this will not be ever executed
void sigkillHandler(int signum)
{
    printf("You killed me!\n");
    exit(0);
}

// SIGSTOP cannot be caught or ignored, so this will not be ever executed
void sigstopHandler(int signum)
{
    printf("You paused me!\n");
    exit(0);
}

// SIGUSR /can/ be caught or ignored, so this will be executed when signal will be sent
void sigusrHandler(int signum)
{
    printf("Don't know this signal yet!\n");
    exit(0);
}

int main(int argc, char const *argv[])
{
    printf("Catching SIGINT...\n");
    signal(SIGKILL, sigkillHandler);
    signal(SIGSTOP, sigstopHandler);
    signal(SIGUSR1, sigusrHandler);
    while (1);
}
