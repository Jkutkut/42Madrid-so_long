/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:39:01 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/16 22:13:39 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H

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
}  				t_map;

typedef t_coord t_player;

typedef t_player t_stair;
typedef t_player t_key;

typedef struct s_game
{
	t_map		*map;
	t_player	*player;
	int			coins;
	t_img		**imgplayer;
	t_img		**imgenemy;
	t_img		*imgcoin;
	t_img		**imgexit;
	t_img		**imgenv;
	void		*mlx;
	void		*win;
}				t_game;

#endif