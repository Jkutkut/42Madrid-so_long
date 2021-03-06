/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:14:13 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/20 10:53:42 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

/**
 * @brief Frees the memory allocated in the given img array.
 * 
 * @param img Image array to free.
 * @param len Length of the array.
 * @param game Game where imgs come from.
 */
static void	free_img_arr(mlx_image_t **img, int len, t_game *game)
{
	int	i;

	if (!img)
		return ;
	i = 0;
	while (i < len && img[i])
	{
		mlx_delete_image(game->mlx, img[i++]);
	}
}

/**
 * @brief Frees all the allocated memory for the game and ends the execution.
 * 
 * @param endtype Type of ending (see end function).
 * @param msg Message to send to end function.
 * @param game Game to free.
 */
void	freeend(int endtype, char *msg, t_game *game)
{
	if (game)
	{
		freemap(game->map);
		mlx_delete_image(game->mlx, game->imgplayer);
		mlx_delete_image(game->mlx, game->imgcoin);
		free_img_arr(game->imgexit, 2, game);
		free_img_arr(game->imgenv, ENV_SRCS, game);
		mlx_terminate(game->mlx);
		free(game);
	}
	end(endtype, msg);
}
