/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:34:44 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/28 17:44:24 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_game	*create_game(t_map *map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = map;
	game->coins = count_coins(map);
	game->p_index = 0;
	get_player(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			map->width * 64, map->height * 64, GAME_NAME);
	load_imgs(game);
	load_controls(game);
	return (game);
}
