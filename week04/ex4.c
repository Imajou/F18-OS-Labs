#include <unistd.h>
#include <printf.h>
#include <stdlib.h>
#include <memory.h>
#include <pthread.h>

#define BUFFER_SIZE 64

int checkBackground(char *input) {
    for (int i = 0; i < BUFFER_SIZE; ++i) {
        if (input[i] == '\n' || input[i] == '\0') return 0;
        if (input[i] == '&' && (input[i + 1] == '\n' || input[i + 1] == '\0')) {
            input[i] = '\n';
            input[i + 1] = '\0';
            return 1;
        }
    }
    return 0;
}

void fork_it(char *input) {
    pid_t pid = fork();
    switch (pid) {
        case 0:
            system(input);
            printf("Finished executing: %s\n", input);
            printf("glebash-0.2$ ");
            exit(0);
        default:
            return;
    }
}

int main(int argc, char *argv[]) {

    printf("Welcome to GleBASH v0.2!\nEnter \"exit\" to finish the process.\nUse \"&\" at the end of the command to run it in separate process.\n");

    while (1) {
        printf("glebash-0.2$ ");
        char input[BUFFER_SIZE] = "";
        fgets(input, BUFFER_SIZE, stdin);
        if (!strcmp(input, "exit\n")) return 0;
        if (checkBackground(input))fork_it(input);
        else system(input);
    }
}

