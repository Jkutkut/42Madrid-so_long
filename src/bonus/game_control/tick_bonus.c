/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:17:12 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/10 22:20:19 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control_bonus.h"

void	tick(t_game *game)
{
	static int	t = 0;
	mlx_image_t	*p;
	int			i;
	int			e;

	if (t++ == 7)
	{
		p = game->imgplayer[game->p_index];
		game->p_index = (game->p_index + 1) % P_ANI;
		game->e_index = (game->e_index + 1) % E_ANI;
		p->instances[0].z = 0;
		game->imgplayer[game->p_index]->instances[0].z = 2;
		i = E_ANI;
		while (i--)
		{
			e = 0;
			while (game->enemies[e])
				game->imgenemy[i]->instances[e++].z = 0;
		}
		while (e-- > 0)
			game->imgenemy[game->e_index]->instances[e].z = 2;
		t = 0;
	}
}