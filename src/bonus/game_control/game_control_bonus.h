/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:16:03 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/10 23:09:15 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CONTROL_BONUS_H
# define GAME_CONTROL_BONUS_H

# include "../so_long_bonus.h"

int		can_move_there(int x, int y, t_game *game);
void	collect_coin(t_game *game);
int		enemy_collision(t_game *game, t_enemy *enemy, int x, int y);
void	game_tick(t_game *game);
void	load_controls(t_game *game);
void	move_enemy(int index, int dx, int dy, t_game *game);
void	move_player(int dx, int dy, t_game *game);
void	tick(t_game *game);
int		try_move_enemy(int index, int dx, int dy, t_game *game);
void	update_enemies(t_game *game);

#endif
