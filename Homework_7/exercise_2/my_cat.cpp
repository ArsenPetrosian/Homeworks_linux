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
    if(argc > 2)
    {
        std::cout << "There is too much arguments.\n";
        return 1;
    }
    int file = open(argv[1], O_RDONLY, 0644);
    char buffer[1];
    ssize_t bytes;
    while((bytes = read(file, buffer, 1)) != 0)
            write(1, buffer, 1);
    buffer[0] = '\n';
    write(1, buffer, 1);
    close(file);
    return 0;
}