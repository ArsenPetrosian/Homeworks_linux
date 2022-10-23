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
    bool cond = true;
    if(argc == 3)
    {
        if(strcmp(argv[1],"-l") == 0)
        {
            cond = false;
            int line_count = 0;
            int file = open(argv[2], O_RDONLY, 0644);
            char buffer[1];
            ssize_t bytes;
            while((bytes = read(file, buffer, 1)) != 0)
            {
                if(buffer[0] == '\n')
                    ++line_count;
            }
            std::cout << "There is " << line_count << " lines in the file.\n";
            close(file);
        }
        else if(strcmp(argv[1],"-w") == 0)
        {
            cond = false;
            int word_count = 0;
            int file = open(argv[2], O_RDONLY, 0644);
            char buffer[1];
            ssize_t bytes;
            while((bytes = read(file, buffer, 1)) != 0)
            {
                if(buffer[0] == ' ' || buffer[0] == '\t' || buffer[0] == '\n' || buffer[0] == '\r')
                    ++word_count;
            }
            --word_count;
            std::cout << "There is " << word_count << " words in the file.\n";
            close(file);
        }
        else if(strcmp(argv[1],"-c") == 0)
        {
            cond = false;
            int character_count = 0;
            int file = open(argv[2], O_RDONLY, 0644);
            char buffer[1];
            ssize_t bytes;
            while((bytes = read(file, buffer, 1)) != 0)
            {
                if(buffer[0] != ' ' && buffer[0] != '\n' && buffer[0] != '\t')
                    ++character_count;
            }
            --character_count;
            std::cout << "There is " << character_count << " characters in the file.\n";
            close(file);
        }
    }
    if(cond)
    {
        int line_count = 0, word_count = 0, character_count = 0;
        char buffer[1];
        int i = argc - 1;
        while(--i > 0)
        {
            int j = strlen(argv[i]);
            while(j > 0)
            {
                if(argv[i][j] == '\n')
                    ++line_count;
                if(argv[i][j] == ' ' || argv[i][j] == '\t' || argv[i][j] == '\n')
                    ++word_count;
                if(argv[i][j] != ' ' && argv[i][j] != '\n' && argv[i][j] != '\t')
                    ++character_count;
                    --j;
            }
        }
        std::cout << "There is " << line_count << " lines.\n";
        std::cout << "There is " << word_count << " words.\n";
        std::cout << "There is " << character_count << " characters.\n";
    }
    return 0;
}