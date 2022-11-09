#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv)
{
    if(argc == 1)
    {
        perror("very few arguments");
        return 1;
    }
    int input_file = open(argv[1], O_RDONLY, 0666);
    if(input_file < 0)
    {
        perror("can't open the file");
        return 1;
    }

    int flags = O_WRONLY | O_CREAT | O_TRUNC;
    int output_file = open("output_file", flags, 0666);
    if(output_file < 0)
    {
        perror("can't open the file");
        return 1;
    }

    char buffer[1024];
    ssize_t bytes;
    while((bytes = read(input_file, buffer, 1024)) != 0)
    {
        for(int i = 0; i < bytes; ++i)
        {
            if(buffer[i] >= '0' && buffer[i] <= '9')
                buffer[i] = 'X';
        }
        write(output_file, buffer, bytes);
        lseek(output_file, 0, SEEK_END);
    }
    return 0;
}
