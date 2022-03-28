/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:11:58 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/28 13:15:21 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control.h"

int	move_enemy(t_enemy *enemy, int dx, int dy, t_game *game)
{
	int	new_x;
	int	new_y;
	int	i;

	if (dx != 0 && dy != 0)
	{
		if (rand() % 2 == 0)
			dx = 0;
		else
			dy = 0;
	}
	new_x = enemy->x + dx;
	new_y = enemy->y + dy;
	if (new_x == 0 || new_x == game->map->width - 1 ||
		new_y == 0 || new_y == game->map->height - 1)
		return (0);
	if (game->map->map[new_y][new_x] == '1')
		return (0);
	i = 0;
	while (game->enemies[i])
	{
		if (game->enemies[i]->x == new_x && game->enemies[i]->y == new_y &&
			game->enemies[i] != enemy)
			return (0);
		i++;
	}
	enemy->x += dx;
	enemy->y += dy;
	return (1);
}

void	update_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (game->enemies[i])
	{
		show_cell(game->enemies[i]->x, game->enemies[i]->y, game);
		while (1)
			if(move_enemy(game->enemies[i],
				(rand() % 3) - 1, (rand() % 3) - 1, game))
				break ;
		i++;
	}
}

void	move_player(int dx, int dy, t_game *game)
{
	int	i;

	if (can_move_there(dx, dy, game))
	{
		show_cell(game->player.x, game->player.y, game);
		game->player.x += dx;
		game->player.y += dy;
		update_moves(game);
		if (game->map->map[game->player.y][game->player.x] == 'C')
			collect_coin(game);
		if (game->map->map[game->player.y][game->player.x] == 'E')
			if (game->coins == 0)
				freeend(0, MSG_WIN, game);
	}
	update_enemies(game);
	show_enemies(game);
	show_player(game);
	i = -1;
	while (game->enemies[++i])
		if (game->enemies[i]->x == game->player.x &&
			game->enemies[i]->y == game->player.y)
			freeend(0, MSG_LOSE, game);
}