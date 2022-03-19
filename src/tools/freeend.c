/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:14:13 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/19 20:01:02 by jre-gonz         ###   ########.fr       */
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
		free(img[i]);
		i++;
	}
	free(img);
}

void	freeend(int endtype, char *msg, t_game *game)
{
	freemap(game->map);
	free_img_arr(game->imgplayer, P_ANI, game);
	free_img_arr(game->imgenemy, E_ANI, game);
	mlx_destroy_image(game->mlx, game->imgcoin);
	free_img_arr(game->imgexit, 2, game);
	free_img_arr(game->imgenv, ENV_SRCS, game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	// free(game->mlx);
	printf("destroying game\n");
	free(game);
	end(endtype, msg);
}