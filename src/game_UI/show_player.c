/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:36:45 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/19 18:37:05 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui.h"

void	show_player(t_game *game)
{
	show_img(game->imgplayer[0], game->player.x, game->player.y, game);
}