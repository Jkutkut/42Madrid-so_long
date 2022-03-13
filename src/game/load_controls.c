/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:09:48 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/13 16:15:27 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	load_controls(t_game *game)
{
	mlx_hook(game->win, 2, 1L<<0, close, game);
}