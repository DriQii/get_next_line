
#include "get_next_line.h"

# define BUFFER_SIZE 4

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
    
    line.buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
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
            break;
    }
        return (startline);
}

char *write_next_line(t_list *line)
{
    int len;
    int cursor;
    int i;
    char    *str;

    cursor = 0;
    len = ft_lstsize(line) * BUFFER_SIZE + 1;
    str = malloc(sizeof(char) * len + 1);
    while (line->next)
    {
        i = 0;
        while(i < BUFFER_SIZE)
        {
            str[i + cursor] = line->content[i];
            i++;
        }
        cursor += i;
        line = line->next;
    }
    str[i + cursor] = '\0';
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
    printf("%s", line.str);
    close(fd);
}