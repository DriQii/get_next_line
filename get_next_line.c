
#include "get_next_line.h"

int get_next_line(int fd)
{
    char    *str;
    char    tab[1];
    int     count;
    
    count = 0;
    while(read(fd, tab, 1))
    {
        //printf("A\n");
        count++;
    }
    while(read(fd, tab, 1))
    {
        printf("A\n");
        count++;
    }
    
    return (count);
}

int main(int argc, char **argv)
{
    char    tab[1];
    int fd = open(argv[1], O_RDONLY);

    printf("%d", get_next_line(fd));
    close(fd);
}