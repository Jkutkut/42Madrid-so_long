/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:35:23 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/20 18:53:51 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui.h"

void	update_moves(t_game *game)
{
	static int	moves = 0;
	int			m;
	int			i;
	char		moves_str[] = "Moves:     ";

	m = ++moves;
	i = 11;
	while (m != 0)
	{
		moves_str[i--] = m % 10 + '0';
		m /= 10;
	}
	show_img(game->imgenv[ENV_C_TL], 0, 0, game);
	show_cell(1, 0, game);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, moves_str);
}
