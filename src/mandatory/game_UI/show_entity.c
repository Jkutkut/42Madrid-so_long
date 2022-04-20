/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:36:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/20 10:40:22 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui.h"

/**
 * @brief Shows the given entity in the given position.
 * 
 * @param entity The entity to show.
 * @param x The x position.
 * @param y The y position.
 * @param game The game.
 */
void	show_entity(mlx_image_t *entity, int x, int y, t_game *game)
{
	int	index;

	index = mlx_image_to_window(game->mlx, entity, x * 64, y * 64);
	entity->instances[index].z = 2;
}
