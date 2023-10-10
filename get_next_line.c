
#include "get_next_line.h"

# define BUFFER_SIZE 25

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
static char rest[BUFFER_SIZE + 1];

t_list *alloc_next_line(int fd)
{
    t_line line;
    t_list  *startline;
    int i;

    i = 0;
    line.buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE  + 1);
    if (rest)
    {
        printf("rest = %s\n", rest);
        while (rest[i] != '\n' && i < BUFFER_SIZE)
            i++;
        if (i == BUFFER_SIZE)
            i = 0;
        line.list = ft_lstnew(&rest[i]);
        line.buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
        startline = line.list;
    }
    line.list = NULL;
    while(read(fd, line.buffer, BUFFER_SIZE))
    {
        if (!line.list)
        {
            line.list = ft_lstnew(line.buffer);
            line.buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
            startline = line.list;
        }
        else
        {
            line.list->next = ft_lstnew(line.buffer);
            line.list = line.list->next;
        }
        if(!check_buff(line.buffer, BUFFER_SIZE))
        {
            line.list->next = ft_lstnew(line.buffer);
            line.buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
        }
        else
        {
            i = 0;
            while (i < BUFFER_SIZE)
            {
                rest[i] = line.buffer[i];
                i++;
            }
            rest[i] = '\0';


            break;
        }
    }

    return (startline);
}

char *write_next_line(t_list *line)
{
    int         len;
    int         cursor;
    t_index     index;
    char        *str;


    cursor = 0;
    index.j = 0;
    len = ft_lstsize(line) * BUFFER_SIZE + 1;
    str = malloc(sizeof(char) * len + 1);
    while (line)
    {
        index.i = 0;
        while(index.i < BUFFER_SIZE && line->content[index.i - 1] != '\n')
        {
            str[index.i + cursor] = line->content[index.i];
            if(line->content[index.i - 1] == '\n')
                break;
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
    printf("%s\n", line.str);
    line.str = get_next_line(fd);
    printf("%s\n", line.str);
    line.str = get_next_line(fd);
    printf("%s\n", line.str);
    close(fd);
    //printf("%s\n", rest);
}
