/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:35:23 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/11 11:16:37 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui_bonus.h"

/**
 * @brief Function colled when the player makes a move. Updates the number
 * of moves on the stdout.
 * 
 * @param game Game playing.
 */
void	update_moves(t_game *game)
{
	static int	moves = 0;
	int			m;
	int			i;
	char		moves_str[12];

	ft_memmove(moves_str, "Moves:     ", 12);
	m = ++moves;
	i = 11;
	while (m != 0)
	{
		moves_str[i--] = m % 10 + '0';
		m /= 10;
	}
	if (game->moves)
		mlx_delete_image(game->mlx, game->moves);
	game->moves = mlx_put_string(game->mlx, moves_str, 10, 20);
}
