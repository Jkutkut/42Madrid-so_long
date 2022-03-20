/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:36:45 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/20 11:30:38 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui.h"

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

unsigned int	mlx_rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	show_player(t_game *game)
{
	unsigned int color;
	int x;
	int y;

	show_cell(game->player.x, game->player.y, game);
	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			color = mlx_get_pixel(game->imgplayer[0], x, y);
			if (color != mlx_rgb_to_int(61, 37, 59)) // 3D253B
				mlx_pixel_put(game->mlx, game->win,
					x + game->player.x * 64,
					y + game->player.y * 64, color);
			x++;
		}
		y++;
	}
}