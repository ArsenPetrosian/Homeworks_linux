#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv)
{
    if(argc == 1)
    {
        std::cout << "There is no arguments.\n";
        return 1;
    }
    char buffer[1];
    ssize_t bytes;
    while((bytes = read(0, buffer, 1)) != 0)
    {
        if(buffer[0] >= '0' && buffer[0] <= '9')
            buffer[0] = 'X';
        write(1, buffer, 1);
    }
    return 0;
}