#include <mlx.h>
#include <stdio.h>
	typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;



int	key_hook(int keycode, t_vars *vars)
{
	printf("key_hook = %d!\n", keycode);
	return (0);
}

int main()
{


	void *mlx_id;
	void *win_id;
	void *img;
	int width;
	int height;
	t_vars vars;
	

	mlx_id = mlx_init();
	win_id = mlx_new_window(mlx_id, 500, 500, "jawaher");
	img = mlx_xpm_file_to_image(mlx_id, "./dragonball.xpm",&width, &height);
	mlx_put_image_to_window(mlx_id, win_id, img, 100, 100);
	mlx_key_hook(win_id, key_hook, &vars);
	mlx_loop(mlx_id);
	return (0);
}