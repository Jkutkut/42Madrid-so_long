/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:35:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/12 13:45:06 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

// Width and height of the window

#ifndef WIDTH
# define WIDTH 720
#endif

#ifndef HEIGHT
# define HEIGHT 480
#endif

#ifndef MAP_H
#include "../map/map.h"
#endif

typedef struct s_player
{
	t_coord			pos;
	// sprite
}				t_player;

typedef t_player t_stair;
typedef t_player t_key;


typedef struct s_game
{
	t_map		*map;
	t_player	*player;
	t_stair		**stairs;
	t_key		**keys;
}				t_game;

t_game	*create_game(t_map *map);

#endif