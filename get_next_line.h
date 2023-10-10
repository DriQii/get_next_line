#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
    const char *content;
    struct s_list *next;
}   t_list;

typedef struct s_line
{
    t_list *list;
    char *buffer;
    char *str;
} t_line;

t_list	*ft_lstnew(void *content);
char *get_next_line(int fd);
int	ft_lstsize(t_list *lst);

#endif