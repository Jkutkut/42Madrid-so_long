/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:52:34 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 18:09:57 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// static void	check_leaks(void)
// {
// 	system("leaks -q so_long");
// }
// atexit(&check_leaks);

/**
 * @brief A game where the 
 * 
 * @param m Matrix of chars.
 * @return t_map* 
 */
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
