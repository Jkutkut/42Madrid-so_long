/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:34:44 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/19 18:47:55 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	get_player(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->map[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
				game->map->map[i][j] = '0';
				i = game->map->height;
				j = game->map->width;
			}
			j++;
		}
		i++;
	}
}

t_game	*create_game(t_map *map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	printf("Creating map\n");
	game->map = map;
	game->coins = getcoins(map);
	get_player(game);
	printf("Creating mlx\n");
	game->mlx = mlx_init();
	printf("Creating window\n");
	game->win = mlx_new_window(game->mlx,
			map->width * 64, map->height * 64, "so_long");
	load_imgs(game);
	show_level(game);
	load_controls(game);
	return (game);
}
