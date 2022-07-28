/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:54:41 by jchennak          #+#    #+#             */
/*   Updated: 2022/07/28 22:54:41 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	err(char *str)
{
	perror(str);
	exit(0);
}

void	error_management(char *av, t_data *all)
{
	map_name(av);
	read_map(av, all);
	check_form(all);
	check_perimeter(*all);
	check_c_p_e(all);
}

void	map_name(char *av)
{
	char	*ext;

	ext = ft_substr(av, ft_strlen(av) - 4, ft_strlen(av) - 1);
	if (ft_strncmp(ext, ".ber", 4) != 0)
	{
		free(ext);
		exit(write(1, "ERROR : Extension map should be like MAP.ber\n", 46));
	}
	free(ext);
}

void	check_perimeter(t_data all)
{
	int	i;

	i = 0;
	while (all.map[0][i] && all.map[all.y - 1][i])
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

void	check_form(t_data *all)
{
	int	x;
	int	y;

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
