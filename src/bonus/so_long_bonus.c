/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:52:34 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/12 09:49:07 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_leaks()
{
	system("leaks -q so_long");
}

int	main(int argc, char	*argv[])
{
	t_map	*map;
	t_game	*game;

	atexit(&check_leaks);
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
