#include "so_long.h"

void check_c_p_e(t_data *all)
{
    int i;

    all->collect = 0;// abort error
    all->player = 0;
    all->exit = 0;
    i = 1;
    while (all->map[i] && i < all->y)
    {
        ft_check_el(all->map[i], all);
        i++;
    }
    if ((*all).collect < 1)
        exit(write(2 ,"MAP ERROR : 0 COLLECTER\n", 25));
    else if ((*all).player != 1)
        exit(write(2, "MAP ERROR : WE need one player\n", 32));
    else if ((*all).exit < 1)
        exit(write(2, "MAP ERROR : 0 exit\n", 20));
}

void ft_check_el(char *str, t_data *all)
{
    int j;

    j = 0;
    while (str[j])
    {
        if (str[j] == 'C')
            all->collect++;  ;
        if (str[j] == 'E')
            all->exit++;
        if (str[j] == 'P')
            all->player++;
        j++;
    }
    printf("collection : %d\n", all->collect);
    printf("player : %d\n", all->player);
    printf("exit : %d\n", all->exit);
}