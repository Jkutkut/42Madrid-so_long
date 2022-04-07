//#include "MLX42/MLX42.h"
#include "../src/mlx/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 512
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

static mlx_image_t	*load_png(t_game *game, char *path)
{
	int				i;
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (img);
}

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

	memmove(src, "../res/enemy/enemy00.png", 25);
	for (int i = 0; i < 4; i++) {
		src[19] = '0' + i + 1;
		printf("%s", src);
		fflush(stdout);
		t = mlx_load_png(src);
		game.imgenemy[i] = mlx_texture_to_image(mlx, t);
		mlx_delete_texture(t);
	}

	t = mlx_load_png("../res/env/C/key01.png");
	game.imgcoin = mlx_texture_to_image(mlx, t);
	mlx_delete_texture(t);

	game.imgenv[ENV_FLOOR] = load_png(&game, ENV_FLOOR_SRC);
	game.imgenv[ENV_L_T] = load_png(&game, ENV_L_T_SRC);
	game.imgenv[ENV_L_L] = load_png(&game, ENV_L_L_SRC);
	game.imgenv[ENV_L_R] = load_png(&game, ENV_L_R_SRC);
	game.imgenv[ENV_L_B] = load_png(&game, ENV_L_B_SRC);
	game.imgenv[ENV_C_TL] = load_png(&game, ENV_C_TL_SRC);
	game.imgenv[ENV_C_TR] = load_png(&game, ENV_C_TR_SRC);
	game.imgenv[ENV_C_BL] = load_png(&game, ENV_C_BL_SRC);
	game.imgenv[ENV_C_BR] = load_png(&game, ENV_C_BR_SRC);
	game.imgenv[ENV_WALL] = load_png(&game, ENV_WALL_SRC);
	

	game.imgexit[0] = load_png(&game, EXIT_OPEN_SRC);
	game.imgexit[1] = load_png(&game, EXIT_CLOSED_SRC);


	// SHOW
	t_map map;
	map.height = 3;
	map.width = 6;
	map.map = malloc(8 * 3);
	map.map[0] = strdup("111111");
	map.map[1] = strdup("100001");
	map.map[2] = strdup("111111");

	printf("\n\n\n");
	for (int i = 0; i < map.height; i++) {
		for (int j = 0; j < map.width; j++) {
			if (map.map[i][j] == '1')
			{
				printf("1");
				mlx_image_to_window(mlx, game.imgenv[1], j * 64, i * 64);
				// mlx_image_to_window(mlx, game.imgenv[ENV_FLOOR], j * 64, i * 64);
			}
			else if (map.map[i][j] == '0')
			{
				printf("0");
				// mlx_image_to_window(mlx, game.imgenv[ENV_L_T], j * 64, i * 64);
				mlx_image_to_window(mlx, game.imgenv[0], j * 64, i * 64);
			}
		}
		printf("\n");
	}

	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}
