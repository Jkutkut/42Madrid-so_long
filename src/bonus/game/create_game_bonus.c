/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:34:44 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/04 09:44:34 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

/**
 * @brief Create a game object form the given map.
 * 
 * @param map Map to create the game from.
 * @return t_game* Game object.
 */
t_game	*create_game(t_map *map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = map;
	game->coins = count_coins(map);
	game->p_index = 0;
	game->e_index = 0;
	get_player(game);
	get_enemies(game);
	game->mlx = mlx_init(map->width * 64, map->height * 64, "so_long", true);
	if (!game->mlx)
		freeend(1, ERROR_MLX_INIT, game);
	load_imgs(game);
	// load_controls(game);
	return (game);
}
