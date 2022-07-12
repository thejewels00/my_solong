#ifndef SO_LONG_H
#define SO_LONG_H

#include "unistd.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct t_data
{
    char    **map;
}   t_data;

void    error_management(char *av, t_data *all);
void    map_name(char *av);
void    read_map(char *av, t_data *all);
#endif