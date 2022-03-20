/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:34:44 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/20 21:01:31 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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

static t_enemy	*create_enemy(t_game *game, int x, int y)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (!enemy)
		end(1, "Error: malloc failed");
	enemy->x = x;
	enemy->y = y;
	game->map->map[y][x] = '0';
	return (enemy);
}

static void	get_enemies(t_game *game)
{
	int	x;
	int	y;
	int	index;

	printf("Enemies\n");
	game->enemies = malloc(sizeof(t_enemy *) * (count_enemy(game) + 1));
	if (!game->enemies)
		end(1, "Error: malloc failed\n");
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

t_game	*create_game(t_map *map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = map;
	game->coins = count_coins(map);
	get_player(game);
	get_enemies(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			map->width * 64, map->height * 64, "so_long");
	load_imgs(game);
	load_controls(game);
	return (game);
}
