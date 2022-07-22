# include "so_long.h"

void	window_design(t_data *all)
{
	all->mlx_id = mlx_init();
	all->win_id = mlx_new_window(all->mlx_id, 50 * all->x, 50 * all->y, "so_long");
	
	init_images(all);
	join_bg(all);
	design_map(all);
	mlx_loop(all->mlx_id);
}

void	init_images(t_data *all)
{
	int a;
	int b;

	all->plr = mlx_xpm_file_to_image(all->mlx_id, "./img/dino.xpm", &a, &b);
	all->coin = mlx_xpm_file_to_image(all->mlx_id, "./img/coin.xpm", &a, &b);
	all->wall = mlx_xpm_file_to_image(all->mlx_id, "./img/wall.xpm", &a, &b);
	all->floor = mlx_xpm_file_to_image(all->mlx_id, "./img/floor.xpm", &a, &b);
	all->exit_1 = mlx_xpm_file_to_image(all->mlx_id, "./img/door.xpm", &a, &b);
}

void	design_map(t_data *all)
{
	int i;
	int j;

	j = 0;
	while (all->map[j])
	{
		i = 0;
		while(all->map[j][i])
		{
			if (all->map[j][i] == '1')
				mlx_put_image_to_window(all->mlx_id, all->win_id, all->wall, i * 50, j * 50);
			if (all->map[j][i] == '0')
				mlx_put_image_to_window(all->mlx_id, all->win_id, all->floor , i * 50, j * 50);
			if (all->map[j][i] == 'C')
				mlx_put_image_to_window(all->mlx_id, all->win_id, all->coin, i * 50, j * 50);
			if (all->map[j][i] == 'E')
				mlx_put_image_to_window(all->mlx_id, all->win_id, all->exit_1, i * 50, j * 50);
			if (all->map[j][i] == 'P')
				mlx_put_image_to_window(all->mlx_id, all->win_id, all->plr, i * 50, j * 50);
		i++;
		}
		j++;
	}
}

void	join_bg(t_data *all)
{
	int i;
	int j;

	j = 0;
	while(all->map[j])
	{
		i = 0;
		while(all->map[j][i])
		{
			mlx_put_image_to_window(all->mlx_id, all->win_id, all->floor, i * 50, j * 50);
			i++;
		}	
		j++;
	}
}