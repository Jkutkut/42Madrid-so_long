/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeend_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:14:13 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/12 09:24:04 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools_bonus.h"

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
	// while (i < len && img[i])
	// {
	// 	mlx_destroy_image(game->mlx, img[i++]);
	// }
	free(img);
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
	freemap(game->map);
	if (game)
	{
		// free_img_arr(game->imgplayer, P_ANI, game);
		// free_img_arr(game->imgenemy, E_ANI, game);
		// mlx_destroy_image(game->mlx, game->imgcoin);
		// free_img_arr(game->imgexit, 2, game);
		// free_img_arr(game->imgenv, ENV_SRCS, game);
		// mlx_destroy_window(game->mlx, game->win);
		// mlx_destroy_display(game->mlx);
		mlx_terminate(game->mlx);
		free(game);
	}
	end(endtype, msg);
}
