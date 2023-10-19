
#include "get_next_line.h"

int ft_check_end_line(char *buffer)
{
    int i;

    i = 0;
    while (buffer[i] != '\n' && buffer[i])
        i++;
    if (!buffer[i])
        return(-1);
    return(i);
}

void ft_write_rest(char rest[1024][BUFFER_SIZE + 1], char *buffer, int fd)
{
    int i;
    int j;
    char *temp;

    j = 0;
    i = 0;
    temp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
    if (!temp)
        return;
    ft_memcpy(temp, buffer, BUFFER_SIZE);
    ft_memset(rest[fd], 0, BUFFER_SIZE + 1);
    while(temp[i] != '\n' && temp[i])
        i++;
    if(temp[i] == '\n')
        i++;
    while(temp[i])
    {
        rest[fd][j++] = temp[i];
        i++;
    }
    free(temp);
}
char *ft_cut_line(char *str)
{
    int i;
    char *newstr;

    //printf("str = %s", str);
    if(!str)
        return(NULL);
    i = 0;
    while (str[i] != '\n' && str[i])
        i++;
    if(str[i] == '\n')
        i++;
    newstr = ft_calloc(sizeof(char), i + 1);
    if(!newstr)
        return(NULL);
    ft_memcpy(newstr, str, i);
    free(str);
    return(newstr);
}

char *get_next_line(int fd)
{
    static char rest[1024][BUFFER_SIZE + 1];
    char        *str;
    char        buffer[BUFFER_SIZE + 1];
    int         oread;

    oread = 1;
    str = NULL;
    ft_memset(buffer, 0, BUFFER_SIZE + 1);
    if(rest[fd][0])
        {
            //printf("rest = %s", rest[fd]);
            str = ft_strdup(rest[fd]);
            ft_write_rest(rest, rest[fd], fd);
            if (ft_check_end_line(str) != -1)
                    return (ft_cut_line(str));  
        }
    while(ft_check_end_line(buffer) == -1)
    {   
        ft_memset(buffer, 0, BUFFER_SIZE + 1);
        oread = read(fd, buffer, BUFFER_SIZE);
        if(oread <= 0)
        {
            if(str)
                return(ft_cut_line(str));
            return(NULL);
        }
        if(!str)
            str = ft_strdup(buffer);
        else
            {str = ft_strjoin(str, buffer);}
    }
    ft_write_rest(rest, buffer, fd);
    return (ft_cut_line(str));
}
/*
int main(int argc, char **argv)
{
    (void)argc;
    int fd = open(argv[1], O_RDONLY);
    char    *str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd);
    printf("%s", str);
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd);
    printf("%s", str);
    free(str); 
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
  
}*/