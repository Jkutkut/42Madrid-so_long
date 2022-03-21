/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:04:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/21 17:12:15 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui.h"

void	show_enemy(t_game *game, int x, int y)
{
	show_entity(game->imgenemy[game->e_index], x, y, game);
}

void	show_enemies(t_game *game)
{
	int	i;

	i = -1;
	while (game->enemies[++i])
		show_enemy(game, game->enemies[i]->x, game->enemies[i]->y);
}