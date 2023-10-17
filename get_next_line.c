
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

void write_rest(char rest[4096][BUFFER_SIZE], int fd, char *buffer)
{
    int i;
    int j;
    int k;

    k = 0;
    j = 0;
    i = 0;
    while (buffer[i] != '\n')
        i++;
    if (buffer[i])
        i++;
    j = i;
    while(k + i < BUFFER_SIZE + 1)
    {
        rest[fd][k] = buffer[j];
        j++;
        k++;
    }
    rest[fd][k] = '\0';
}
char *ft_trim_line(char *str)
{
    int i;
    char *newstr;

    i = 0;
    if (!str)
        return (NULL);
        //printf("str = %s\n", str);
    while (str[i] != '\n' && str[i])
        i++;
    //printf("i = %d\n", i);
    newstr = (char *)malloc(sizeof(char) * (i + 2));
    if(!newstr)
            return (NULL);
    ft_memcpy(newstr, str, i + 2);
    if(newstr[i + 1])
        newstr[i + 1] = '\0';
    if (str)
        free(str);
    return (newstr);
}
char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE];
    static char rest[4096][BUFFER_SIZE];
    size_t cursor;
    char *str;
    int i;

    i = 1;
    if (fd < 0 || !fd)
        return(NULL);
    
    str = NULL;
    cursor = 0;
    if (rest[fd][0] != '\0')
    { 
        str = malloc(sizeof(char) * (ft_strlen(rest[fd])));
        if(!str)
            return (NULL);
        
        ft_memcpy(str, rest[fd], ft_strlen(rest[fd]));
        cursor += ft_strlen(rest[fd]);
        
    }
    if(ft_chektab(rest[fd]) != -1)
    {
        
        str = ft_trim_line(str);
        write_rest(rest, fd, rest[fd]);
        return (str);
    }
    while(i != 0)
    {
        ft_memset(buffer, '\0', BUFFER_SIZE);
        i = read(fd, buffer, BUFFER_SIZE);
        if (i <= 0)
            return (ft_trim_line(str));
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
    char    *str = get_next_line(fd);
    printf("%s", str);
    free(str);
    /*str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd);
    printf("%s", str);
    free(str);*/
}