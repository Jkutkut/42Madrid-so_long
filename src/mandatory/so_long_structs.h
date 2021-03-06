/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:39:01 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/20 09:53:55 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H

# include "./so_long.h"

typedef struct s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
}				t_map;

typedef t_coord	t_player;
typedef t_coord	t_enemy;

typedef struct s_game
{
	t_map		*map;
	t_player	player;
	int			p_index;
	int			coins;
	mlx_image_t	*imgplayer;
	mlx_image_t	*imgcoin;
	mlx_image_t	*imgexit[2];
	mlx_image_t	*imgenv[ENV_SRCS];
	void		*mlx;
}				t_game;

#endif