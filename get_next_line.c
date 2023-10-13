
#include "get_next_line.h"


int ft_chektab(char *buffer)
{
    int i;

    i = 0;
    while(i < BUFFER_SIZE)
    {
        
        if(buffer[i] == '\n')
            return(i);
        i++;
    }
    return(-1);
}

void write_rest(char **rest, int fd, char *buffer)
{
    int i;
    int j;
    int k;

    k = 0;
    j = 0;
    i = 0;
    while (buffer[i] != '\n' && buffer[i])
        i++;
    if (buffer[i])
        i++;
    if (rest[fd])
        free(rest[fd]);
    rest[fd] = malloc(sizeof(char) * (BUFFER_SIZE - i + 1));
    j = i;
    while(k - i < BUFFER_SIZE)
        rest[fd][k++] = buffer[j++];
}
char *ft_trim_line(char *str)
{
    int i;
    char *newstr;

    i = 0;
    while (str[i] != '\n' && str[i])
        i++;
    newstr = (char *)malloc(sizeof(char) * (i + 1));
    if(!newstr)
            return (NULL);
    ft_memcpy(newstr, str, i + 1);
    free(str);
    return (newstr);
}

char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE];
    static char *rest[BUFFER_SIZE];
    size_t cursor;
    char *str;
    char *tempstr;

    if (fd < 0)
        return(NULL);
    tempstr = NULL;
    str = NULL;
    cursor = 0;
    if (rest[fd])
    {
        str = malloc(sizeof(char) * ft_strlen(rest[fd]));
        if(!str)
            return (NULL);
        ft_memcpy(str, rest[fd], ft_strlen(rest[fd]));
        cursor += ft_strlen(rest[fd]);
    }
    while(read(fd, buffer, BUFFER_SIZE))
    {
        str = ft_realloc(str, BUFFER_SIZE + cursor);
        if(!str)
            return (NULL);
        ft_memcpy(str + cursor, buffer, BUFFER_SIZE);
        cursor += BUFFER_SIZE;
        if(ft_chektab(buffer) != -1)
            break;
    }
    str = ft_trim_line(str);
    write_rest(rest, fd, buffer);
    return(str);
}

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);

    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
}