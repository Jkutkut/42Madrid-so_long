/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:34:44 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/13 13:49:01 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_game	*create_game(t_map *map)
{
	t_game	*game;

	if (!(game = (t_game *)malloc(sizeof(t_game))))
		return (NULL);
	printf("Creating map\n");
	game->map = map;
	printf("Creating mlx\n");
	game->mlx = mlx_init();
	printf("Creating window\n");
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "so_long");
	load_imgs(game);
	load_level(game);
	return (game);
}