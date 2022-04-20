/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:16:03 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/20 10:07:33 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CONTROL_H
# define GAME_CONTROL_H

# include "../so_long.h"

int		can_move_there(int x, int y, t_game *game);
void	collect_coin(t_game *game);
void	game_tick(void *g);
void	load_controls(t_game *game);
int		move_cooldown(int reset);
void	move_player(int dx, int dy, t_game *game);

#endif
