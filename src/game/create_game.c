/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:34:44 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/12 13:44:44 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_game	*create_game(t_map *map)
{
	t_game	*game;

	if (!(game = (t_game *)malloc(sizeof(t_game))))
		return (NULL);
	game->map = map;
	game->player = NULL;
	game->stairs = NULL;
	game->keys = NULL;
	return (game);
}