#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv)
{
    if(argc == 1)
    {
        perror("There is no arguments");
        return 1;
    }
    if(argc > 2)
    {
        perror("There is too much arguments");
        return 1;
    }
    int file = open(argv[1], O_RDONLY, 0644);
    if(file < 0)
    {
        perror("can't open the file");
        return 1;
    }

    char buffer[1024];
    ssize_t bytes;
    while((bytes = read(file, buffer, 1024)) != 0)
    {
        write(1, buffer, bytes);
    }
    buffer[0] = '\n';
    write(1, buffer, 1);
    close(file);
    return 0;
}