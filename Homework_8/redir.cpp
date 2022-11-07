#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    if (argc < 4)
        return 1;

    pid_t pid = fork();
    if (pid < 0)
        return 1;
    
    if (pid == 0)
    {    
        int flags = O_WRONLY | O_CREAT;
        int err_file{};
        int out_file{};
        if(strcmp(argv[2], "-args") == 0)
        {
            int program_argc{};
            int i = 3;
            while(strcmp(argv[i], "-out") != 0)
            {
                ++program_argc;
                ++i;
            }
            if(strcmp(argv[i + 1], "-a") == 0)
            {
                out_file = open(argv[i + 2], flags, 0666);
                lseek(out_file, 0, SEEK_END);
                if(strcmp(argv[i + 4], "-a") == 0)
                {
                    err_file = open(argv[i + 5], flags, 0666);
                    lseek(err_file, 0, SEEK_END);
                }
                else
                    err_file = open(argv[i + 4], flags |  O_TRUNC, 0666);
            }
            else
            {
                out_file = open(argv[i + 1], flags | O_TRUNC, 0666);
                if(strcmp(argv[i + 3], "-a") == 0)
                {
                    err_file = open(argv[i + 4], flags, 0666);
                    lseek(err_file, 0, SEEK_END);
                }
                else
                    err_file = open(argv[i + 3], flags | O_TRUNC, 0666);
            }
            if (out_file < 0 || err_file < 0)
            {
                perror("Error occured while trying to open the file.");
                return 1;
            }
            
            char* program_argv[program_argc + 1];
            for(int j = 0; j < program_argc; ++j)
                program_argv[j] = argv[j + 3];
            program_argv[program_argc] = NULL;
            
            dup2 (out_file, STDOUT_FILENO);
            close(out_file);
            dup2 (err_file, STDERR_FILENO);
            close(err_file);

            if (execvp(argv[1], program_argv) < 0)
            {
                perror("Program execution failed.");
                return 1;
            }
        }
        else
        {
            if(strcmp(argv[3], "-a") == 0)
            {
                out_file = open(argv[4], flags, 0666);
                lseek(out_file, 0, SEEK_END);
                if(strcmp(argv[6], "-a") == 0)
                {
                    err_file = open(argv[7], flags, 0666);
                    lseek(err_file, 0, SEEK_END);
                }
                else
                    err_file = open(argv[6], flags | O_TRUNC, 0666);
            }
            else
            {
                out_file = open(argv[3], flags | O_TRUNC, 0666);
                if(strcmp(argv[5], "-a") == 0)
                {
                    err_file = open(argv[6], flags, 0666);
                    lseek(err_file, 0, SEEK_END);
                }
                else
                    err_file = open(argv[5], flags | O_TRUNC, 0666);
            }
            if (out_file < 0 || err_file < 0)
            {
                perror("Error occured while trying to open the file.");
                return 1;
            }
            
            char* program_argv[1];
            program_argv[0] = NULL;
            dup2 (out_file, STDOUT_FILENO);
            close(out_file);
            dup2 (err_file, STDERR_FILENO);
            close(err_file);
            
            if (execvp(argv[1], program_argv) < 0)
            {
                perror("Program execution failed.");
                return 1;
            }
        }
    }
    int status{};
    if(pid > 0)
        wait(&status);
    return status;
}