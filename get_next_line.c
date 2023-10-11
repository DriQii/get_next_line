
#include "get_next_line.h"

# define BUFFER_SIZE 6

static char rest[BUFFER_SIZE + 1];

int check_buff(char *buff, size_t size)
{
    while(size != 0)
    {
        if (buff[size] == '\n')
            return (1);
        size--;
    }
    if (buff[size] == '\n')
            return (1);
    return (0);
}


t_list *alloc_next_line(int fd)
{
    t_line line;
    t_list  *startline;
    t_index index;
    char *temp;
    

    index.i = 0;
    index.j = 0;
    line.list = NULL;
    temp = (char *)malloc(sizeof(char) * BUFFER_SIZE  + 1);
    ft_strlcpy(temp, rest, BUFFER_SIZE + 1);
    line.buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE  + 1);
    if (rest[0])
    {
        //printf("rest = %s\n", rest);
        while (temp[index.i] != '\n' && index.i < BUFFER_SIZE)
            index.i++;
        if (index.i == BUFFER_SIZE)
            index.i = 0;
        line.list = ft_lstnew(&temp[index.i + 1]);
        line.buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
        startline = line.list;
    }
    while(read(fd, line.buffer, BUFFER_SIZE))
    {
        if (!line.list && !rest[0])
        {
            line.list = ft_lstnew(line.buffer);
            line.buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
            startline = line.list;
        }
        else if(!check_buff(line.buffer, BUFFER_SIZE))
        {
            
            line.list->next = ft_lstnew(line.buffer);
            line.list = line.list->next;
            line.buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
        }
        else
        {
            index.i = 0;
            while (line.buffer[index.i] != '\n' && index.i < BUFFER_SIZE)
                index.i++;
            index.i++;
            if (index.i >= BUFFER_SIZE)
                index.i = 0;
            while (index.i < BUFFER_SIZE)
            {
                rest[index.j++] = line.buffer[index.i++];
                //index.i++;
                printf("c = %c\n", rest[index.j]);
            }
            rest[index.i] = '\0';
            break;
        }
    }
    printf("startline = %s\n", startline->content);
    return (startline);
}

char *write_next_line(t_list *line)
{
    printf("write first content =%s\n", line->content);
    int         len;
    int         cursor;
    t_index     index;
    char        *str;


    cursor = 0;
    index.j = 0;
    index.k = ft_lstsize(line);
    len = index.k * BUFFER_SIZE + 1;
    str = malloc(sizeof(char) * len + 1);
    while (line)
    {
        index.i = 0;
        while(index.i < BUFFER_SIZE && line->content[index.i] != '\n' && line->content[index.i] != '\0')
        {   
            str[index.i + cursor] = line->content[index.i];
            index.i++;
        }
        cursor += index.i;
        line = line->next;
    }
    str[index.i + cursor] = '\0';
    return (str);
}
char *get_next_line(int fd)
{
    t_list *lstline;
    char *line;

    lstline = alloc_next_line(fd);
    line = write_next_line(lstline);
    return(line);
}

int main(int argc, char **argv)
{
    char    tab[1];
    int fd = open(argv[1], O_RDONLY);
    t_line line;

    line.str = get_next_line(fd);
    printf("line = %s\n", line.str);
    line.str = get_next_line(fd);
    printf("line = %s\n", line.str);
    line.str = get_next_line(fd);
    printf("line = %s\n", line.str);
    line.str = get_next_line(fd);
    printf("%s\n", line.str);
    line.str = get_next_line(fd);
    printf("%s\n", line.str);
    close(fd);
    //printf("%s\n", rest);
}
