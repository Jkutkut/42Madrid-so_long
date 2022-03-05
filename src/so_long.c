// #include <mlx.h>
#include "../minilibx-linux/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	if (mlx_win == 0)
		return (0);
	mlx_loop(mlx);
	return (0);
}