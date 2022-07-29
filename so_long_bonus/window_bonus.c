/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:44:17 by jchennak          #+#    #+#             */
/*   Updated: 2022/07/29 13:43:25 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	change_position(char *direction, char *current_pos, t_data *all)
{
	if (*direction != '1' && *direction != 'E')
	{
		if (*direction == 'C')
			all->collect--;
		*direction = *current_pos;
		*current_pos = '0';
		all->steps++;
	}
	if (all->collect == 0)
	{
		if (*direction == 'E')
			exit_win();
	}
}

void	move_part_1(int keycode, t_data *all)
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
}

int	move(int keycode, t_data *all)
{
	char	*stp;

	move_part_1(keycode, all);
	if (all->collect == 0)
		all->exit_1 = all->exit_2;
	mlx_clear_window(all->mlx_id, all->win_id);
	design_map(all);
	stp = ft_itoa(all->steps);
	mlx_string_put(all->mlx_id, all->win_id, 15, 14, 0xFFFFFF, stp);
	free(stp);
	return (0);
}

int	exit_win(void)
{
	write(1, "Winner\n", 8);
	exit (0);
}

void	ft_sleep(int i, int j)
{
	while (i > 0)
	{
		j = i;
		while (j > 0)
			j--;
		i--;
	}
}
