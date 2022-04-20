/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:26:15 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/20 10:48:57 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_UI_H
# define GAME_UI_H

# include "../so_long.h"

void	load_imgs(t_game *game);
void	show_border(t_game *game);
void	show_cell(int x, int y, t_game *game);
void	show_entity(mlx_image_t *entity, int x, int y, t_game *game);
void	show_exits(t_game *game);
void	show_img(mlx_image_t *img, int x, int y, t_game *game);
void	show_level(t_game *game);
void	show_player(t_game *game);
void	show_wall(t_game *game, int x, int y);
void	update_moves(void);

#endif
