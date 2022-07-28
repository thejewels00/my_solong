/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:44:17 by jchennak          #+#    #+#             */
/*   Updated: 2022/07/28 11:33:54 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_position(char *direction, char *current_pos, t_data *all)
{
	static int	i;

	if (*direction != '1' && *direction != 'E')
	{
		if (*direction == 'C')
			all->collect--;
		*direction = *current_pos;
		*current_pos = '0';
		i++;
		ft_putnbr_fd (i, 1);
		write(1, "\n", 1);
	}
	if (all->collect == 0)
	{
		if (*direction == 'E')
			exit_win();
	}
}

int	move(int keycode, t_data *all)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 13 || keycode == 126)
		change_position(&all->map[all->j_plr - 1][all->i_plr],
			&all->map[all->j_plr][all->i_plr], all);
	else if (keycode == 1 || keycode == 125)
		change_position(&all->map[all->j_plr + 1][all->i_plr],
			&all->map[all->j_plr][all->i_plr], all);
	else if (keycode == 0 || keycode == 123)
	{
		all->tmp_img = all->left_dino;
		change_position(&all->map[all->j_plr][all->i_plr - 1],
			&all->map[all->j_plr][all->i_plr], all);
	}
	else if (keycode == 2 || keycode == 124)
	{
		all->tmp_img = all->plr;
		change_position(&all->map[all->j_plr][all->i_plr + 1],
			&all->map[all->j_plr][all->i_plr], all);
	}
	if (all->collect == 0)
		all->exit_1 = all->exit_2;
	mlx_clear_window(all->mlx_id, all->win_id);
	design_map(all);
	return (0);
}

int	exit_win(void)
{
	write(1, "Winner", 7);
	exit(0);
}

void	window_design(t_data *all)
{
	all->mlx_id = mlx_init();
	all->win_id = mlx_new_window(all->mlx_id, 50 * all->x,
			50 * all->y, "so_long");
	init_images(all);
	design_map(all);
	mlx_key_hook(all->win_id, move, all);
	mlx_hook(all->win_id, 17, 1L << 5, exit_win, &all);
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
}
