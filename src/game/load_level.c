/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:50:38 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/16 22:02:19 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/**
 * @brief Show the given img on the given game.
 * Place it on the img index (x, y)
 * 
 * @param img Image to show
 * @param x Index on the horizontal axis.
 * @param y Index on the vertical axis.
 * @param game Game to show the img on.
 */
void	showimg(t_img *img, int x, int y, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 64, y * 64);
}

/**
 * @brief Detects the correct sprite to show on the given wall.
 * If the cell down is a wall, it will show the full-wall sprite.
 * 
 * @param game Game to show the sprite on.
 * @param x Horizontal index of the cell.
 * @param y Vertical index of the cell.
 */
void	show_line_top(t_game *game, int x, int y)
{
	if (game->map->height > y + 1 && game->map->map[y + 1][x] == '1')
		showimg(game->imgenv[ENV_WALL], x, y, game);
	else
		showimg(game->imgenv[ENV_L_T], x, y, game);
}

/**
 * @brief Show on screen the border of the given game.
 * 
 * @param game 
 */
void	show_border(t_game *game)
{
	int	i;

	i = 1;
	while (i < game->map->height - 1)
	{
		showimg(game->imgenv[ENV_L_L], 0, i, game);
		showimg(game->imgenv[ENV_L_R], game->map->width - 1, i, game);
		i++;
	}
	i = 1;
	while (i < game->map->width - 1)
	{
		show_line_top(game, i, 0);
		showimg(game->imgenv[ENV_L_B], i, game->map->height - 1, game);
		i++;
	}
	showimg(game->imgenv[ENV_C_TL], 0, 0, game);
	showimg(game->imgenv[ENV_C_TR], game->map->width - 1, 0, game);
	showimg(game->imgenv[ENV_C_BL], 0, game->map->height - 1, game);
	showimg(game->imgenv[ENV_C_BR], game->map->width - 1,
		game->map->height - 1, game);
}

/**
 * @brief Show on screen the given game.
 * 
 * @param game 
 */
void	load_level(t_game *game)
{
	int	i;
	int	j;

	show_border(game);
	i = 1;
	while (i < game->map->height - 1)
	{
		j = 1;
		while (j < game->map->width - 1)
		{
			if (game->map->map[i][j] == '0')
				showimg(game->imgenv[ENV_FLOOR], j, i, game);
			else if (game->map->map[i][j] == '1')
				show_line_top(game, j, i);
			else if (game->map->map[i][j] == 'E')
				showimg(game->imgexit[EXIT_C], j, i, game);
			else if (game->map->map[i][j] == 'C')
				showimg(game->imgcoin, j, i, game);
			else if (game->map->map[i][j] == 'P')
				showimg(game->imgplayer[0], j, i, game);
			j++;
		}
		i++;
	}
}
