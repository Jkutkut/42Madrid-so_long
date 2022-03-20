/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:16:03 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/20 11:56:48 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CONTROL_H
# define GAME_CONTROL_H

#include "../so_long.h"

#define KEY_ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_UP 65362
#define KEY_DOWN 65364

int		can_move_there(int x, int y, t_game *game);
int		close_game_key(int keycode, t_game *game);
int	close_game(t_game *game);
int		key_press(int keycode, t_game *game);
void	load_controls(t_game *game);
void	move_player(int dx, int dy, t_game *game);

#endif