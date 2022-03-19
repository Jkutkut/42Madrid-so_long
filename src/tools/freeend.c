/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:14:13 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/19 19:05:52 by jre-gonz         ###   ########.fr       */
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
	printf("map\n");
	freemap(game->map);
	printf("Player\n");
	free_img_arr(game->imgplayer, P_ANI, game);
	printf("enemy\n");
	free_img_arr(game->imgenemy, E_ANI, game);
	printf("coin, exits and env\n");
	mlx_destroy_image(game->mlx, game->imgcoin);
	free_img_arr(game->imgexit, 2, game);
	free_img_arr(game->imgenv, ENV_SRCS, game);
	printf("destroying window\n");
	mlx_destroy_window(game->mlx, game->win);
	printf("destroying display\n");
	mlx_destroy_display(game->mlx);
	// TODO
	printf("destroying game\n");
	free(game);
	end(endtype, msg);
}