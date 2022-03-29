/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:52:34 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/29 16:29:02 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	check_leaks(void)
// {
// 	system("leaks -q so_long");
// }
// atexit(check_leaks);

int	update_game(t_game *game)
{
	static int	i = 0;
	if (i++ == 10000)
	{
		game->p_index = (game->p_index + 1) % P_ANI;
		game->e_index = (game->e_index + 1) % E_ANI;
		show_enemies(game);
		show_player(game);
		i = 0;
	}
	return (0);
}

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
	mlx_loop_hook(game->mlx, &update_game, game);
	mlx_loop(game->mlx);
	return (0);
}