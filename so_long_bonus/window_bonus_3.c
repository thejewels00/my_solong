/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:36:24 by jchennak          #+#    #+#             */
/*   Updated: 2022/07/29 19:59:58 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	window_design(t_data *all)
{
	all->steps = 0;
	all->mlx_id = mlx_init();
	all->win_id = mlx_new_window(all->mlx_id, 50 * all->x,
			50 * all->y, "so_long");
	init_images(all);
	design_map(all);
	mlx_key_hook(all->win_id, move, all);
	mlx_hook(all->win_id, 17, 1L << 5, exit_win, &all);
	mlx_loop_hook(all->mlx_id, animation, all);
	mlx_loop(all->mlx_id);
}

void	init_images(t_data *all)
{
	int	a;
	int	b;

	all->coin = mlx_xpm_file_to_image(all->mlx_id, "./img/coin.xpm", &a, &b);
	all->wall = mlx_xpm_file_to_image(all->mlx_id, "./img/wall.xpm", &a, &b);
	all->floor = mlx_xpm_file_to_image(all->mlx_id, "./img/floor.xpm", &a, &b);
	all->exit_1 = mlx_xpm_file_to_image(all->mlx_id, "./img/door.xpm", &a, &b);
	all->exit_2 = mlx_xpm_file_to_image(all->mlx_id,
			"./img/open_door.xpm", &a, &b);
	all->left_dino = mlx_xpm_file_to_image(all->mlx_id,
			"./img/left_dino.xpm", &a, &b);
	all->plr = mlx_xpm_file_to_image(all->mlx_id, "./img/dino.xpm", &a, &b);
	all->tmp_img = mlx_xpm_file_to_image(all->mlx_id, "./img/dino.xpm", &a, &b);
	all->j0 = mlx_xpm_file_to_image(all->mlx_id, "./animation/0.xpm", &a, &b);
	all->j1 = mlx_xpm_file_to_image(all->mlx_id, "./animation/5.xpm", &a, &b);
	all->j2 = mlx_xpm_file_to_image(all->mlx_id, "./animation/6.xpm", &a, &b);
	all->j3 = mlx_xpm_file_to_image(all->mlx_id, "./animation/7.xpm", &a, &b);
	all->j4 = mlx_xpm_file_to_image(all->mlx_id, "./animation/8.xpm", &a, &b);
	all->j5 = mlx_xpm_file_to_image(all->mlx_id, "./animation/9.xpm", &a, &b);
	all->j6 = mlx_xpm_file_to_image(all->mlx_id, "./animation/10.xpm", &a, &b);
}

void	picture(t_data *all)
{
	static int	tmp;

	tmp++;
	tmp %= 7;
	if (tmp == 0)
		all->coin = all->j0;
	else if (tmp == 1)
		all->coin = all->j1;
	else if (tmp == 2)
		all->coin = all->j2;
	else if (tmp == 3)
		all->coin = all->j3;
	else if (tmp == 4)
		all->coin = all->j4;
	else if (tmp == 5)
		all->coin = all->j5;
	else if (tmp == 6)
		all->coin = all->j6;
}

int	animation(t_data *all)
{
	char	*stp;

	picture(all);
	ft_sleep(10000, 900);
	mlx_clear_window(all->mlx_id, all->win_id);
	design_map(all);
	stp = ft_itoa(all->steps);
	mlx_string_put(all->mlx_id, all->win_id, 15, 14, 0xFFFFFF, stp);
	free(stp);
	return (0);
}
