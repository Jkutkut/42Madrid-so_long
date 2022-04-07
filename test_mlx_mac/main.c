#include <mlx.h>

int main(void)
{
	void * mlx = mlx_init();
	void * win = mlx_new_window(mlx, 512, 512, "so_long");

	int w, h;
	void * img = mlx_xpm_file_to_image(mlx, "../res/cat/cat01_nobg.xpm", &w, &h);

	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
}