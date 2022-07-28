/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:31:52 by jchennak          #+#    #+#             */
/*   Updated: 2022/07/28 11:31:52 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_c_p_e(t_data *all)
{
	int		i;

	all->collect = 0;
	all->player = 0;
	all->exit = 0;
	i = 1;
	while (all->map[i] && i < all->y)
	{
		ft_check_el(all->map[i], all);
		i++;
	}
	if ((*all).collect < 1)
		exit (write (2, "MAP ERROR : 0 COLLECTER\n", 25));
	else if ((*all).player != 1)
		exit(write(2, "MAP ERROR : WE need one player\n", 32));
	else if ((*all).exit < 1)
		exit(write(2, "MAP ERROR : 0 exit\n", 20));
}

void	ft_check_el(char *str, t_data *all)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == 'C')
			all->collect++;
		if (str[j] == 'E')
			all->exit++;
		if (str[j] == 'P')
			all->player++;
		if (str[j] != 'C' && str[j] != 'P' && str[j] != '1'
			&& str[j] != '0' && str[j] != 'E')
			exit(write(2, "ERROR : what is this ?\n", 24));
		j++;
	}
}

void	read_map(char *av, t_data *all)
{
	char	*mp;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		err("OPEN");
	mp = fill_map(fd);
	if (mp[0] == '\n' || mp[ft_strlen(mp) - 1] == '\n')
	{
		free(mp);
		exit(write(2, "EROOR : NEW LINE !! in end or start of file :D \n", 46));
	}
	(*all).map = ft_split(mp, '\n');
	free(mp);
}

char	*fill_map(int fd)
{
	char	*str;
	char	*mp;
	char	*tmp;

	str = get_next_line(fd);
	if (!str)
		exit(write(2, "ERR0R : empty MAP\n", 19));
	mp = ft_strdup("");
	while (str != NULL)
	{
		tmp = mp;
		mp = ft_strjoin(mp, str);
		free(tmp);
		free(str);
		str = get_next_line(fd);
		if (str && str[0] == '\n')
		{
			free(str);
			free(mp);
			exit(write(2, "EROOR : empty line\n", 20));
		}
	}
	return (mp);
}
