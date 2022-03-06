/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:15:32 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/06 11:17:09 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// C libraries
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include <stdio.h>

// Custom libraries
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

#define WIDTH 720
#define HEIGHT 480

typedef struct s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef struct s_rect
{
	t_coord			pos;
	t_coord			size;
}				t_rect;

typedef struct s_player
{
	t_coord			pos;
}				t_player;

typedef struct s_game
{
	int		**map;
	int		width;
	int		height;
	t_player	player;
}				t_game;


// Funtions

void	end(int endtype, char *msg);


#endif