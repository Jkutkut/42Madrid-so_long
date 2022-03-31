/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:26:15 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/31 19:57:29 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_UI_BONUS_H
# define GAME_UI_BONUS_H

# include "../so_long_bonus.h"

void	load_imgs(t_game *game);
void	show_border(t_game *game);
void	show_cell(int x, int y, t_game *game);
void	show_exits(t_game *game);
void	show_img(t_img *img, int x, int y, t_game *game);
void	show_level(t_game *game);
void	show_enemies(t_game *game);
void	show_player(t_game *game);
void	show_entity(t_img *entity, int x, int y, t_game *game);
void	show_wall(t_game *game, int x, int y);
void	update_moves(t_game *game);

#endif
