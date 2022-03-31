/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:34:44 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/29 22:20:14 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/**
 * @brief Counts the number of enemies in the map.
 * 
 * @param game Game structure.
 * @return int Number of enemies.
 */
static int	count_enemy(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->map[i][j] == 'F')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

/**
 * @brief Create a enemy object.
 * 
 * @param game Game structure.
 * @param x Horizontal position.
 * @param y Vertical position.
 * @return t_enemy* Enemy object.
 */
static t_enemy	*create_enemy(t_game *game, int x, int y)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (!enemy)
		end(1, ERROR_MALLOC);
	enemy->x = x;
	enemy->y = y;
	game->map->map[y][x] = '0';
	return (enemy);
}

/**
 * @brief Get the enemies form the map.
 * 
 * @param game Game to get the enemies form.
 */
static void	get_enemies(t_game *game)
{
	int	x;
	int	y;
	int	index;

	game->enemies = malloc(sizeof(t_enemy *) * (count_enemy(game) + 1));
	if (!game->enemies)
		end(1, ERROR_MALLOC);
	y = 0;
	index = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'F')
				game->enemies[index++] = create_enemy(game, x, y);
			x++;
		}
		y++;
	}
	game->enemies[index] = NULL;
}

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
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			map->width * 64, map->height * 64, "so_long");
	load_imgs(game);
	load_controls(game);
	return (game);
}
