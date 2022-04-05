/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:26:44 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/05 07:40:47 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui_bonus.h"

/**
 * @brief Show the given img on the given game.
 * Place it on the img index (x, y)
 * 
 * @param img Image to show
 * @param x Index on the horizontal axis.
 * @param y Index on the vertical axis.
 * @param game Game to show the img on.
 */
void	show_img(mlx_image_t *img, int x, int y, t_game *game)
{
	mlx_image_to_window(game->mlx, img, x * 64, y * 64);
}
