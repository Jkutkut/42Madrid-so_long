/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:52:34 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/20 18:39:40 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	check_leaks(void)
// {
// 	system("leaks -q so_long");
// }
// atexit(check_leaks);

int	main(int argc, char	*argv[])
{
	t_map	*map;
	t_game	*game;

	if (argc != 2)
		end(1, "Invalid number of arguments");
	map = create_map(load_map(argv[1]));
	check_update_map(map);
	print_map(map);
	game = create_game(map);
	show_level(game);
	mlx_loop(game->mlx);
	return (0);
}
