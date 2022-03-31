/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_entity_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:36:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/31 20:28:32 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui_bonus.h"

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

unsigned int	mlx_rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

/**
 * @brief Shows the given entity in the given position.
 * 
 * @param entity The entity to show.
 * @param x The x position.
 * @param y The y position.
 * @param game The game.
 */
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
