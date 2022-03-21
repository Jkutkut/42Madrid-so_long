/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:36:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/21 17:11:57 by jre-gonz         ###   ########.fr       */
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
	show_entity(game->imgplayer[game->p_index], game->player.x, game->player.y, game);
}

void	show_entity(t_img *entity, int x, int y, t_game *game)
{
	unsigned int	color;
	unsigned int	ignore_color;
	int				dx;
	int				dy;

	ignore_color = mlx_rgb_to_int(61, 37, 59);
	show_cell(x, y, game);
	dy = 0;
	while (dy < 64)
	{
		dx = 0;
		while (dx < 64)
		{
			color = mlx_get_pixel(entity, dx, dy);
			if (color != ignore_color)
				mlx_pixel_put(game->mlx, game->win,
					dx + x * 64,
					dy + y * 64, color);
			dx++;
		}
		dy++;
	}
}