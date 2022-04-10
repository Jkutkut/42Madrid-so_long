/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:11:58 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/10 16:25:05 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control_bonus.h"

/**
 * @brief If the given enemy is on the same cell as another enemy
 * 
 * @param game Game to check.
 * @param enemy Enemy to keep in mind
 * @param x Horizontal position of the enemy.
 * @param y Vertical position of the enemy.
 * @return int 1 if the enemy is on the same cell as another enemy, else 0.
 */
static int	enemy_collision(t_game *game, t_enemy *enemy, int x, int y)
{
	int	i;

	i = 0;
	while (game->enemies[i])
	{
		if (game->enemies[i]->x == x && game->enemies[i]->y == y)
			if (game->enemies[i] != enemy)
				return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Attemps to move the given enemy.
 * 
 * @param enemy Enemy to move.
 * @param dx Horizontal increment.
 * @param dy Vertical increment.
 * @param game Game structure.
 * @return int 1 if the enemy can move to the given position, 0 otherwise.
 */
static int	move_enemy(t_enemy *enemy, int dx, int dy, t_game *game)
{
	int	new_x;
	int	new_y;

	if (dx != 0 && dy != 0)
	{
		if (rand() % 2 == 0)
			dx = 0;
		else
			dy = 0;
	}
	new_x = enemy->x + dx;
	new_y = enemy->y + dy;
	if (new_x == 0 || new_x == game->map->width - 1)
		return (0);
	if (new_y == 0 || new_y == game->map->height - 1)
		return (0);
	if (game->map->map[new_y][new_x] == '1')
		return (0);
	if (enemy_collision(game, enemy, new_x, new_y))
		return (0);
	enemy->x += dx;
	enemy->y += dy;
	return (1);
}

/**
 * @brief Updates the position of enemies.
 * 
 * @param game Game structure.
 */
static void	update_enemies(t_game *game)
{
	int	i;
	int	dx;
	int	dy;

	i = 0;
	while (game->enemies[i])
	{
		show_cell(game->enemies[i]->x, game->enemies[i]->y, game);
		while (1)
		{
			dx = rand() % 3 - 1;
			dy = rand() % 3 - 1;
			if (move_enemy(game->enemies[i], dx, dy, game))
				break ;
		}
		i++;
	}
}

/**
 * @brief Attempt to move the player to a given position.
 * 
 * @param dx Horizontal increment.
 * @param dy Vertical increment.
 * @param game Game structure.
 */
void	move_player(int dx, int dy, t_game *game)
{
	static int	move_cooldown = 0;

	if (move_cooldown-- <= 0 && can_move_there(dx, dy, game))
	{
		game->player.x += dx;
		game->player.y += dy;
		update_moves(game);
		game->imgplayer[game->p_index]->instances[0].x += dx * 64;
		game->imgplayer[game->p_index]->instances[0].y += dy * 64;
		move_cooldown = 5;
	}
}
