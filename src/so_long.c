/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:52:34 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/13 01:05:45 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	check_leaks(void)
// {
// 	system("leaks -q so_long");
// }

int	main(int argc, char	*argv[])
{
	
	if (argc != 2)
		end(1, "Invalid number of arguments");
	// atexit(check_leaks);
	t_map *map = create_map(load_map(argv[1]));
	check_update_map(map);
	print_map(map);
	
	t_game *game = create_game(map);
	
	int i = -1;
	while (++i < 8)
		mlx_put_image_to_window(game->mlx, game->win, game->imgplayer[i], 64 * i, 0);

	mlx_loop(game->mlx);
	
	freemap(map);
	return (0);
}





// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;


// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "so_long");
	
// 	img.img = mlx_new_image(mlx, WIDTH / 2, HEIGHT / 2);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
// 	for (int i = 0; i < WIDTH / 2; i++)
// 		for (int j = 0; j < HEIGHT / 2; j++)
// 			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

// 	int w, h;
// 	void	*image = mlx_xpm_file_to_image(mlx_win, "res/Cat Sprite Sheet.png", &w, &h);
// 	if (image != NULL)
// 		mlx_put_image_to_window(mlx, mlx_win, image, 0, 0);
// 	else
// 		printf("Error: Could not load image\n");
// 	printf("%d %d\n", w, h);

	// mlx_loop(mlx);
// }