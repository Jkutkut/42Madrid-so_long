/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:37:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/19 19:07:10 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control.h"

int	close_game(int keycode, t_game *game)
{
	(void)keycode;
	freeend(0, "Thanks for playing UwU.", game);
	return (0);
}