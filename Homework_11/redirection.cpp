#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        perror("inappropriate number of arguments.");
        return 1;
    }

    int pipefd[2];
    if(pipe(pipefd) < 0)
    {
        perror("pipe");
        return 1;
    }

    pid_t pid1 = fork();
    pid_t pid2 = fork();
    if(pid1 < 0 || pid2 < 0)
    {
        perror("fork");
        return 1;
    }

    close(pipefd[0]);
    close(pipefd[1]);

    if(pid1 == 0)
    {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        char* program1_argv[1];
        program1_argv[0] = NULL;
        if (execvp(argv[1], program1_argv) < 0)
        {
            perror("Program execution failed.");
            return 1;
        }
    }
    if(pid2 == 0)
    {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        char* program2_argv[1];
        program2_argv[0] = NULL;
        if (execvp(argv[2], program2_argv) < 0)
        {
            perror("Program execution failed.");
            return 1;
        }
    }

    int status;
    wait(&status);
    return status;
}