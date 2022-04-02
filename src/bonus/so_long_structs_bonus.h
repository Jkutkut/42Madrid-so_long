/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:39:01 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/02 11:45:25 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_BONUS_H
# define SO_LONG_STRUCTS_BONUS_H

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
	t_enemy		**enemies;
	int			e_index;
	int			coins;
	mlx_image_t	**imgplayer;
	mlx_image_t	**imgenemy;
	mlx_image_t	*imgcoin;
	mlx_image_t	**imgexit;
	mlx_image_t	**imgenv;
	void		*mlx;
	void		*win;
}				t_game;

#endif