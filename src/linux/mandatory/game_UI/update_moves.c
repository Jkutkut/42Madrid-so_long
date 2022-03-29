/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:35:23 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/29 20:11:35 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui.h"

/**
 * @brief Function colled when the player makes a move. Updates the number
 * of moves on the stdout.
 * 
 * @param game Game playing.
 */
void	update_moves(t_game *game)
{
	static int	moves = 0;

	if (moves++ > 0)
		ft_putchar_fd('\r', 1);
	(void) game->coins;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(moves, 1);
	fflush(stdout);
}
