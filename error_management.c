#include "so_long.h"

void    error_management(char *av, t_data *all)
{
    //map name 
    (void)*all;
    map_name(av);
    read_map(av, all);
}

void    map_name(char *av)
{
    char    *ext;

    ext = ft_substr(av, ft_strlen(av) - 4, ft_strlen(av) - 1);
    if (ft_strncmp(ext, ".ber", 4)!= 0)
    {
        free(ext);
        exit(write(1, "ERROR : Extension map should be like MAP.ber\n", 46));
    }
    free(ext);
}

void read_map(char *av, t_data *all)
{
    int     fd;
    char    *str;
    char    *mp;

    (void)*all;
    fd = open(av, O_RDONLY);
    mp = "";
    str = get_next_line(fd);
    while(str)
    {
        mp = ft_strjoin(mp, str);
        str = get_next_line(fd);
    }
    free(str);// take care
    (*all).map = ft_split(mp, '\n');
    free(mp);// take care
}