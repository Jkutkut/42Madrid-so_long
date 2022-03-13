/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:50:38 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/13 15:19:45 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	showimg(t_img *img, int x, int y, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 64, y * 64);
}

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
		if (game->map->map[1][i] == '1')
			showimg(game->imgenv[ENV_WALL], i, 0, game);
		else
			showimg(game->imgenv[ENV_L_T], i, 0, game);
		showimg(game->imgenv[ENV_L_B], i, game->map->height - 1, game);
		i++;
	}
	showimg(game->imgenv[ENV_C_TL], 0, 0, game);
	showimg(game->imgenv[ENV_C_TR], game->map->width - 1, 0, game);
	showimg(game->imgenv[ENV_C_BL], 0, game->map->height - 1, game);
	showimg(game->imgenv[ENV_C_BR], game->map->width - 1, game->map->height - 1, game);
}

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
				showimg(game->imgenv[ENV_WALL], j, i, game);
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