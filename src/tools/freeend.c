/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:14:13 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/13 17:45:20 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static void	free_img_arr(t_img **img, int len, t_game *game)
{
	int i;

	i = 0;
	if (!img)
		return ;
	while (i < len)
	{
		if (!img[i])
			break;
		mlx_destroy_image(game->mlx, img[i]);
		i++;
	}
	free(img);
}

void	freeend(int endtype, char *msg, t_game *game)
{
	// freemap(game->map);
	// free_img_arr(game->imgplayer, P_ANI, game);
	// free_img_arr(game->imgenemy, E_ANI, game);
	// free_img_arr(game->imgexit, 2, game);
	// free_img_arr(game->imgenv, ENV_SRCS, game);
	// TODO
	free(game);
	end(endtype, msg);
}