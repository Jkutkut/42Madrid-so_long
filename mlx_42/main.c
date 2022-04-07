//#include "MLX42/MLX42.h"
#include "../src/mlx/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 500
#define HEIGHT 256

mlx_image_t	*g_img;

int32_t i1;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		g_img->instances[i1].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		g_img->instances[i1].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		g_img->instances[i1].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		g_img->instances[i1].x += 5;
}

#include "so_long_images.h"
#include "so_long_structs.h"

int32_t	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);

	t_game game;

	game.mlx = mlx;
	char src[100] = "../res/cat/cat00.png";
	mlx_texture_t *t;
	for (int i = 0; i < 8; i++) {
		src[15] = '0' + i + 1;
		t = mlx_load_png(src);
		game.imgplayer[i] = mlx_texture_to_image(mlx, t);
		mlx_delete_texture(t);
	}

	strcat(src, "../res/enemy/enemy00.png");
	for (int i = 0; i < 8; i++) {
		src[19] = '0' + i + 1;
		t = mlx_load_png(src);
		game.imgplayer[i] = mlx_texture_to_image(mlx, t);
		mlx_delete_texture(t);
	}
	
	for (int i = 0; i < 8; i++) {
		mlx_image_to_window(mlx, game.imgplayer[i], i * 64, 0);
	}

	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}
