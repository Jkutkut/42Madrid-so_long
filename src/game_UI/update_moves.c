/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:35:23 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/20 18:50:32 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui.h"

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
