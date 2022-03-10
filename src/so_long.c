/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:52:34 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/10 13:55:02 by jre-gonz         ###   ########.fr       */
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
	
	int i = 0;
	while (map->map[i])
		printf("-%s-\n", map->map[i++]);
	if (map->map != NULL)
		freearray(map->map);
	free(map);
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
// 	t_img	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
// 	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0077);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }