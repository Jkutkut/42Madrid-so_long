/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:09:48 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/13 16:48:54 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

#define KEY_ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_UP 65362
#define KEY_DOWN 65364

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		printf("ESQ\n");
	else if (keycode == KEY_W || keycode == KEY_UP)
		printf("UP\n");
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		printf("LEFT\n");
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		printf("DOWN\n");
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		printf("RIGHT\n");
	else
		printf("Unknown key %d\n", keycode);
	return (0);
}

// int	key_release(int keycode, t_game *game)
// {
// 	if (keycode == KEY_ESC)
// 		printf("ESQ\n");
// 	else if (keycode == KEY_W || keycode == KEY_UP)
// 		printf("UP\n");
// 	else if (keycode == KEY_A || keycode == KEY_LEFT)
// 		printf("LEFT\n");
// 	else if (keycode == KEY_S || keycode == KEY_DOWN)
// 		printf("DOWN\n");
// 	else if (keycode == KEY_D || keycode == KEY_RIGHT)
// 		printf("RIGHT\n");
// 	else
// 		printf("Unknown key %d\n", keycode);
// 	return (0);
// }

int	destroy(int keycode, t_game *game)
{
	printf("Destroy\n");
}

void	load_controls(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	// mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 1L << 17, destroy, game);
}