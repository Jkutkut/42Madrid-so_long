/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:52:34 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/05 08:00:47 by jre-gonz         ###   ########.fr       */
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
	check_update_map(map);
	print_map(map);
	game = create_game(map);
	show_level(game);
	mlx_loop(game->mlx);
	return (0);
}
