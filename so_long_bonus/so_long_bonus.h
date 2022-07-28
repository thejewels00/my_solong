/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:54:57 by jchennak          #+#    #+#             */
/*   Updated: 2022/07/28 22:54:57 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "unistd.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct t_data
{
	char	**map;
	char	*wall;
	char	*floor;
	char	*plr;
	char	*coin;
	char	*exit_1;
	char	*exit_2;
	char	*left_dino;
	char	*ennemy;
	char	*tmp_img;
	void	*mlx_id;
	void	*win_id;
	int		x;
	int		y;
	int		i_x;
	int		i_y;
	int		collect;
	int		player;
	int		exit;
	int		i_plr;
	int		j_plr;
}	t_data;

void	error_management(char *av, t_data *all);
void	map_name(char *av);
void	read_map(char *av, t_data *all);
void	check_form(t_data *all);
void	check_perimeter(t_data all);
void	check_c_p_e(t_data *all);
void	ft_check_el(char *str, t_data *all);
void	window_design(t_data *all);
void	init_images(t_data *all);
void	design_map(t_data *all);
void	join_bg(t_data *all);
void	err(char *str);
char	*fill_map(int fd);
void	dsign_img(t_data *all, int i, int j);
void	change_position(char *direction, char *current_pos, t_data *all);
int		exit_win(void);

#endif