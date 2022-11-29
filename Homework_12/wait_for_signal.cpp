#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <string>

int signal_id(char* argument)
{
    if(strcmp(argument, "SIGHUP") == 0)
        return 1;
    if(strcmp(argument, "SIGINT") == 0)
        return 2;
    if(strcmp(argument, "SIGQUIT") == 0)
        return 3;
    if(strcmp(argument, "SIGILL") == 0)
        return 4;
    if(strcmp(argument, "SIGABRT") == 0)
        return 6;
    if(strcmp(argument, "SIGFPE") == 0)
        return 8;
    if(strcmp(argument, "SIGKILL") == 0)
        return 9;
    if(strcmp(argument, "SIGSEGV") == 0)
        return 11;
    if(strcmp(argument, "SIGPIPE") == 0)
        return 13;
    if(strcmp(argument, "SIGALRM") == 0)
        return 14;
    if(strcmp(argument, "SIGTERM") == 0)
        return 15;
    if(strcmp(argument, "SIGUSR1") == 0)
        return 30;
    if(strcmp(argument, "SIGUSR2") == 0)
        return 31;
    if(strcmp(argument, "SIGCHLD") == 0)
        return 18;
    if(strcmp(argument, "SIGCONT") == 0)
        return 25;
    if(strcmp(argument, "SIGSTOP") == 0)
        return 23;
    if(strcmp(argument, "SIGTSTP") == 0)
        return 24;
    if(strcmp(argument, "SIGTTIN") == 0)
        return 26;
    if(strcmp(argument, "SIGTTOU") == 0)
        return 27;
    return 0;
}

const char* signal_output(int signo)
{
    std::string number = std::to_string(signo);
    const char* result = number.c_str();
    return result;
}

void handle_sig(int signo, siginfo_t *info, void *context)
{
    write(STDOUT_FILENO, "Received signal with id: ", 25);
    const char* result = signal_output(signo);
    write(STDOUT_FILENO, result, strlen(result));
    write(STDOUT_FILENO, "\n", 1);
}

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        perror("inappropriate number of arguments.");
        return 1;
    }

    int received_signal;
    received_signal = signal_id(argv[1]);

    if(received_signal == 0)
        write(STDOUT_FILENO, "The signal doesn't exist.\n", 27);
    else
    {
        struct sigaction act = { 0 };
        act.sa_sigaction = &handle_sig;
        if(sigaction(received_signal, &act, NULL) != 0)
        {
            perror("Error occured while trying to do sigaction.");
            return 1;
        }
    }
    int seconds = std::atoi(argv[2]);
    sleep(seconds);
    return 0;
}