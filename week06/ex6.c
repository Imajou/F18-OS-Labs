#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int createFork()
{
    printf("Forking process...\n");
    return fork();
}

int main()
{

    int pid1, pid2;
    int fd[2];

    pipe(fd);

    switch (pid1 = createFork())
    {
    case -1:
        return (1);
    case 0:
    {
        // Child 1
        int strbuff;
        close(fd[1]);
        printf("[Child1] Waiting for pid2\n");

        read(fd[0], &strbuff, sizeof(int));
        printf("[Child1] Pid2 from pipe: %d Now sleeping...\n", strbuff);
        sleep(4);
        printf("[Child1] SIGSTOP to child2\n");
        kill(strbuff, SIGSTOP);
        exit(0);
    }
    }

    switch (pid2 = createFork())
    {
    case -1:
        return (1);
    case 0:
    {
        // Child 2
        printf("[Child2] Running...\n");
        while (1);
    }
    }

    if(pid1 != 0 && pid2 != 0) {
        // Parent
        close(fd[0]);
        printf("[Parent] Sending pid2 to child1...\n");
        write(fd[1], &pid2, sizeof(int));

        printf("[Parent] Waiting for status...\n");
        waitpid(pid2, NULL, WUNTRACED);
        printf("[Parent] Status SIGSTOP\n");
    }

    return 0;
}
