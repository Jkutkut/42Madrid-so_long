/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:35:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/31 16:30:10 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../so_long_bonus.h"

int		count_enemy(t_game *game);
t_enemy	*create_enemy(t_game *game, int x, int y);
t_game	*create_game(t_map *map);
void	get_enemies(t_game *game);
void	get_player(t_game *game);

#endif
