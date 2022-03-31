/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:17:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/31 14:54:46 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control_bonus.h"

/**
 * @brief Handles the key press event.
 * 
 * @param keycode Key code of the key pressed.
 * @param game Game structure.
 * @return int Value to return for the mlx function.
 */
int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(0, -1, game);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(-1, 0, game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(0, 1, game);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(1, 0, game);
	return (0);
}
