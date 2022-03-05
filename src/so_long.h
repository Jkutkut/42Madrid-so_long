/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:15:32 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/05 23:53:50 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include <stdio.h>

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

typedef struct game
{
	int		**map;
	int		width;
	int		height;
	t_player	player;
};


// Funtions

void	end(int endtype, char *msg);


#endif