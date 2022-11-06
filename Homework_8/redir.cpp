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
            bool out_a = false;
            bool err_a = false;
            int program_argc{};

            if(strcmp(argv[argc - 2], "-a") == 0)
            {
                err_file = open(argv[argc - 1], flags, 0666);
                err_a = true;
                if(strcmp(argv[argc - 4], "-a") == 0)
                {
                    out_a = true;
                        program_argc = argc - 5 - 2;
                }
                else
                    program_argc = argc - 4 - 2;
            }
            else
            {
                err_file = open(argv[argc - 1], flags | O_TRUNC, 0666);
                if(strcmp(argv[argc - 3], "-a") == 0)
                {
                    out_a = true;
                    program_argc = argc - 4 - 2;
                }
                else
                    program_argc = argc - 3 - 2;
            }

            if(err_a)
            {
                lseek(err_file, 0, SEEK_END);
                if(out_a)
                {
                    out_file = open(argv[argc - 3], flags, 0666);
                    lseek(out_file, 0, SEEK_END);
                }
                else
                    out_file = open(argv[argc - 3], flags | O_TRUNC, 0666);
            }
            else
            {
               if(out_a)
                {
                    out_file = open(argv[argc - 2], flags, 0666);
                    lseek(out_file, 0, SEEK_END);
                }
                else
                    out_file = open(argv[argc - 2], flags | O_TRUNC, 0666); 
            }
            if (out_file < 0 || err_file < 0)
            {
                perror("Error occured while trying to open the file.");
                return 1;
            }

            char* program_argv[program_argc + 1];
            for(int i = 0; i < program_argc; ++i)
                program_argv[i] = argv[i + 2];
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
            if(strcmp(argv[argc - 2], "-a") == 0)
            {
                err_file = open(argv[argc - 1], flags, 0666);
                lseek(err_file, 0, SEEK_END);
                if(strcmp(argv[argc - 4], "-a") == 0)
                {
                    out_file = open(argv[argc - 3], flags, 0666);
                    lseek(out_file, 0, SEEK_END);
                }
                else
                    out_file = open(argv[argc - 3], flags | O_TRUNC, 0666);
            }
            else
            {
                err_file = open(argv[argc - 1], flags | O_TRUNC, 0666);
                if(strcmp(argv[argc - 3], "-a") == 0)
                {
                    out_file = open(argv[argc - 2], flags, 0666);
                    lseek(out_file, 0, SEEK_END);
                }
                else
                    out_file = open(argv[argc - 2], flags | O_TRUNC, 0666);
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