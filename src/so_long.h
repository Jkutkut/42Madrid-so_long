/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:15:32 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/07 15:07:13 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// C libraries
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include <stdio.h>
#include <stdlib.h>

// Custom libraries
#include "libft/libft.h"
#include "map/map.h"
#include "tools/tools.h"

#define WIDTH 720
#define HEIGHT 480

typedef struct s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef struct s_player
{
	t_coord			pos;
	// sprite
}				t_player;

typedef t_player t_stair;
typedef t_player t_key;

typedef struct s_game
{
	char		*map;
	t_coord		*size;
	t_coord		*dim;
	t_player	*player;
	t_stair		**stairs;
	t_key		**keys;
}				t_game;


// Funtions



#endif