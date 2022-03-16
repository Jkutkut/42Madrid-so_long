/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:34:44 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/16 22:15:14 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_game	*create_game(t_map *map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	printf("Creating map\n");
	game->map = map;
	game->coins = getcoins(map);
	printf("Creating mlx\n");
	game->mlx = mlx_init();
	printf("Creating window\n");
	game->win = mlx_new_window(game->mlx,
			map->width * 64, map->height * 64, "so_long");
	load_imgs(game);
	load_level(game);
	load_controls(game);
	return (game);
}
