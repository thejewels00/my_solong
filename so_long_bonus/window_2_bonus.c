/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:33:41 by jchennak          #+#    #+#             */
/*   Updated: 2022/07/28 22:58:23 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	design_map(t_data *all)
{
	int		i;
	int		j;

	j = 0;
	while (all->map[j])
	{
		i = 0;
		while (all->map[j][i])
		{
			dsign_img(all, i, j);
			i++;
		}
		j++;
	}
}

void	dsign_img(t_data *all, int i, int j)
{
	if (all->map[j][i] == '1')
		mlx_put_image_to_window(all->mlx_id, all->win_id,
			all->wall, i * 50, j * 50);
	if (all->map[j][i] == '0')
		mlx_put_image_to_window(all->mlx_id, all->win_id,
			all->floor, i * 50, j * 50);
	if (all->map[j][i] == 'C')
		mlx_put_image_to_window(all->mlx_id, all->win_id,
			all->coin, i * 50, j * 50);
	if (all->map[j][i] == 'E')
		mlx_put_image_to_window(all->mlx_id, all->win_id,
			all->exit_1, i * 50, j * 50);
	if (all->map[j][i] == 'P')
	{
		mlx_put_image_to_window(all->mlx_id, all->win_id,
			all->tmp_img, i * 50, j * 50);
		all->j_plr = j;
		all->i_plr = i;
	}
}
