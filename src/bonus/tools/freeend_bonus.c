/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeend_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:14:13 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/12 10:06:17 by jre-gonz         ###   ########.fr       */
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
	while (i < len && img[i])
	{
		mlx_delete_image(game->mlx, img[i++]);
	}
}

/**
 * @brief Frees the given array of enemies vectors.
 * 
 * @param pos Array of t_enemy elements.
 */
static void	free_enemy_pos(t_enemy **pos)
{
	int	i;

	if (!pos)
		return ;
	i = 0;
	while (pos[i])
		free(pos[i++]);
	free(pos);
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
		free_enemy_pos(game->enemies);
		free_img_arr(game->imgplayer, P_ANI, game);
		free_img_arr(game->imgenemy, E_ANI, game);
		mlx_delete_image(game->mlx, game->imgcoin);
		free_img_arr(game->imgexit, 2, game);
		free_img_arr(game->imgenv, ENV_SRCS, game);
		mlx_terminate(game->mlx);
		if (game->moves)
			mlx_delete_image(game->mlx, game->moves);
		free(game);
	}
	end(endtype, msg);
}
