/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:35:23 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/20 10:47:36 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui.h"

/**
 * @brief Function colled when the player makes a move. Updates the number
 * of moves on the stdout.
 */
void	update_moves(void)
{
	static int	moves = 0;
	int			m;
	int			i;
	char		moves_str[12];

	ft_memmove(moves_str, "\rMoves:     ", 13);
	m = ++moves;
	i = 11;
	while (m != 0)
	{
		moves_str[i--] = m % 10 + '0';
		m /= 10;
	}
	ft_putstr_fd(moves_str, 1);
}
