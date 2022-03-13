/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:34:44 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/13 01:12:42 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

#define P_ANI 8
#define E_ANI 4

static t_img	*load_xpm(t_game *game, char *path)
{
	int	i;

	return mlx_xpm_file_to_image(game->mlx, path, &i, &i);
}

static void	load_player(t_game *game)
{
	char	path[] = "./res/cat/cat00.xpm";
	int		i;

	game->imgplayer = malloc(sizeof(t_player *) * (P_ANI + 1));
	if (game->imgplayer == NULL)
		end(2, "Error: malloc failed");
	i = 1;
	while (i <= P_ANI)
	{
		path[13] = i / 10 + '0';
		path[14] = i % 10 + '0';
		game->imgplayer[i - 1] = load_xpm(game, path);
		if (game->imgplayer[i - 1] == NULL)
			end(2, "Error: mlx_xpm_file_to_image failed");
		i++;
	}
	game->imgplayer[i - 1] = NULL;
}

static void	load_enemy(t_game *game)
{
	char	path[] = "./res/enemy/enemy00.xpm";
	int		i;

	game->imgenemy = malloc(sizeof(t_player *) * (E_ANI + 1));
	if (game->imgenemy == NULL)
		end(2, "Error: malloc failed");
	i = 1;
	while (i <= E_ANI)
	{
		path[17] = i / 10 + '0';
		path[18] = i % 10 + '0';
		game->imgenemy[i - 1] = load_xpm(game, path);
		if (game->imgenemy[i - 1] == NULL)
			end(2, "Error: mlx_xpm_file_to_image failed");
		i++;
	}
	game->imgenemy[i - 1] = NULL;
}

t_game	*create_game(t_map *map)
{
	t_game	*game;

	if (!(game = (t_game *)malloc(sizeof(t_game))))
		return (NULL);
	printf("Creating map\n");
	game->map = map;
	printf("Creating mlx\n");
	game->mlx = mlx_init();
	printf("Creating window\n");
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "so_long");
	printf("Loading player\n");
	load_player(game);
	printf("Loading enemy\n");
	load_enemy(game);
	return (game);
}