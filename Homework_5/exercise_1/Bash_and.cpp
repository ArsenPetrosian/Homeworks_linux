#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <stdlib.h>

int main(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        pid_t pid = fork();
        if (pid < 0)
            return 1;

        int status;
        if (argc > 1)
        {
            wait(&status);
            if(status != 0)
                break;
        }

        if (pid == 0)
        {
            char* child_args[] = {argv[i], NULL};
            execvp(argv[i], child_args);
        }
    }
    return 0;
}
