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
    int     x;
    int     y;
    int     collect;
    int     player;
    int     exit;
}   t_data;

void    error_management(char *av, t_data *all);
void    map_name(char *av);
void    read_map(char *av, t_data *all);
void    check_form(t_data *all);
void    check_perimeter(t_data all);
void    check_c_p_e(t_data *all);
void    ft_check_el(char *str, t_data *all);
#endif