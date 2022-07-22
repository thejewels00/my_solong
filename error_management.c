#include "so_long.h"

void    error_management(char *av, t_data *all)
{
    //map name 
	map_name(av);
	read_map(av, all); //lecture de map // leaks kinin hna :)
    check_form(all); // verification de la forme de mon map :)
    check_perimeter(*all);
    check_c_p_e(all);
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


    fd = open(av, O_RDONLY);
	if (fd == -1)
		exit(write (2, "yo bro what the hell did you give me to open", 44));
    mp = "";
    str = get_next_line(fd);
	if (!str)
		exit(write(2, "EROOR : empty MAP \n", 19));
    while(str)
    {
        mp = ft_strjoin(mp, str);
        free(str);// take care //
        str = get_next_line(fd);
    }
    (*all).map = ft_split(mp, '\n');
    free(mp);// take care //
}

void check_form(t_data *all)
{
    int x;
    int y;

    x = ft_strlen(all->map[0]);
    y = 0;
    while (all->map[y])
    {
        if ((size_t)x != ft_strlen(all->map[y]))
            exit(write(1, "ERROR : check your map form\n", 28));
        y++;
    }
    (*all).x = x;
	all->i_x = x - 1;
    (*all).y = y;
	all->i_y = y -1;
}

void check_perimeter(t_data all)
{
    int i;

    i = 0;
    while(all.map[0][i] && all.map[all.y - 1][i])
    {
        if (all.map[0][i] != '1' || all.map[all.y - 1][0] != '1')
            exit(write(2, "ERROR : Border \n", 17));
        i++;
    }
    i = 1;
    while (all.map[i] && i < all.y - 1)
    {
        if (all.map[i][0] != '1' || all.map[i][all.x - 1] != '1')
            exit(write(2, "ERROR : Border \n", 17));
        i++;
    }
}