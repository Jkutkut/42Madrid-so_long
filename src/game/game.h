/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:35:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/13 00:58:24 by jre-gonz         ###   ########.fr       */
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

#include "../../mlx/mlx.h"
#include "../../mlx/mlx_int.h"
#include "../map/map.h"

typedef struct s_player
{
	t_coord			pos;
}				t_player;

typedef t_player t_stair;
typedef t_player t_key;

typedef struct s_game
{
	t_map		*map;
	t_player	*player;
	t_img		**imgplayer;
	t_img		**imgenemy;
	t_img		**imgcoin;
	t_img		**imgexit;
	t_img		**imgwall;
	t_img		**imgfloor;
	void		*mlx;
	void		*win;
}				t_game;

t_game	*create_game(t_map *map);

#endif