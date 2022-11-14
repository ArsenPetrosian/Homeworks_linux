#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        perror("very few arguments");
        return 1;
    }

    int pipefd_send[2];
    if (pipe(pipefd_send) < 0)
    {
        perror("pipe");
        return 1;
    }
    int pipefd_get[2];
    if (pipe(pipefd_get) < 0)
    {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        close(pipefd_send[1]);
        close(pipefd_get[0]);
        char read_char[1];
        ssize_t bytes;
        bool add = false;
        bool sub = false;
        bool mul = false;
        std::string left_str;
        std::string right_str;
        int left{}, right{};
        while ((bytes = read(pipefd_send[0], read_char, 1)) > 0)
        {
            left_str.clear();
            right_str.clear();
            int res{};

            if (strcmp(read_char, "+") == 0)
                add = true;
            else if (strcmp(read_char, "-") == 0)
                sub = true;
            else if (strcmp(read_char, "x") == 0)
                mul = true;
            
            while ((bytes = read(pipefd_send[0], read_char, 1)) > 0)
            {
                if (strcmp(read_char, "l") == 0)
                {
                    left = left_str[0] - '0';
                    for (int j = 1; j < left_str.size(); ++j)
                        left = left * 10 + left_str[j] - '0';
                    break;
                }
                else
                    left_str.push_back(read_char[0]);
            }
            while ((bytes = read(pipefd_send[0], read_char, 1)) > 0)
            {
                if (strcmp(read_char, "r") == 0)
                {
                    right = right_str[0] - '0';
                    for (int j = 1; j < right_str.size(); ++j)
                        right = right * 10 + right_str[j] - '0';
                    break;
                }
                else
                    right_str.push_back(read_char[0]);
            }

            if(add)
            {
                res = left + right;
                add = false;
            }
            else if(sub)
            {
                res = left - right;
                sub = false;
            }
            else if(mul)
            {
                res = left * right;
                mul = false;
            }
            else
                res = left / right;
            
            left_str.clear();
            left_str = std::to_string(res);
            const char* result = left_str.c_str();
            write(pipefd_get[1], result, strlen(result));
            write(pipefd_get[1], "e", 1);
        }
        close(pipefd_send[0]);
        close(pipefd_get[1]);
    }
    if (pid > 0)
    {
        close(pipefd_send[0]);
        close(pipefd_get[1]);
        int i = 1;
        while (i <= argc - 1)
        {
            write(pipefd_send[1], argv[i], 1);

            write(pipefd_send[1], argv[i + 1], strlen(argv[i + 1]));
            write(pipefd_send[1], "l", 1);

            write(pipefd_send[1], argv[i + 2], strlen(argv[i + 2]));
            write(pipefd_send[1], "r", 1);
            i += 3;
        }
        close(pipefd_send[1]);
        wait(NULL);
        char write_buffer[1];
        ssize_t bytes;
        int res{};
        while ((bytes = read(pipefd_get[0], write_buffer, 1)) > 0)
        {
            if(strcmp(write_buffer, "e") == 0)
            {
                std::string str;
                str = std::to_string(res);
                const char* result = str.c_str();
                res = 0;
                write(1, result, strlen(result));
                write(1, "\n", 1);
            }
            else
                res = res * 10 + write_buffer[0] - '0';
        }
        close(pipefd_get[0]);
    }
    return 0;
}