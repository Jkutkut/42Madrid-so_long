/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:52:34 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/10 17:31:25 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char	*argv[])
{
	t_map	*map;
	t_game	*game;

	if (argc != 2)
		end(1, ERROR_INVALID_ARGS);
	map = create_map(load_map(argv[1]));
	game = create_game(map);
	load_imgs(game);
	load_controls(game);
	show_level(game);
	mlx_loop(game->mlx);
	return (0);
}
