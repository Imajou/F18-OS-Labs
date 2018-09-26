#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define LINE_OUT "I'm alive\n"

int createFork()
{
    printf("Forking process...\n");
    return fork();
}

int main()
{

    int pid = createFork();

    switch (pid)
    {
    case -1:
        return (1);

    case 0:
    {
        while (1)
        {
            printf(LINE_OUT);
            sleep(1);
        }
    }

    default:
    {
        sleep(10);
        kill(pid, SIGKILL);
        break;
    }
    }

    return 0;
}
