#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <stdlib.h>

int main(int argc, char **argv)
{
    pid_t pid = fork();
    int result = 0;
    
    if(argc > 1 && strcmp(argv[1], "-w") == 0)
    	wait(NULL);
    
    if(pid < 0)
    	return 1;
    
    if(pid == 0)
    {
    	for(int i = 1; i < argc; ++i)
        	result += atoi(argv[i]);
        result /= argc - 1;
        std::cout << result;
        return 0;
    }
    return 0;
}
