/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:25:51 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/13 15:07:08 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static t_img	*load_xpm(t_game *game, char *path)
{
	int		i;
	t_img	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, &i, &i);
	if (img == NULL)
	{
		ft_putstr_fd("Error loading image: ", 2);
		ft_putendl_fd(path, 2);
		end(1, "Error loading image");
	}
	return (img);
}

static void	load_players(t_game *game)
{
	char	*path;
	int		i;

	path = ft_strdup("./res/cat/cat00.xpm");
	game->imgplayer = malloc(sizeof(t_player *) * (P_ANI));
	if (game->imgplayer == NULL)
		end(2, "Error: malloc failed");
	i = 0;
	while (++i <= P_ANI)
	{
		path[14] = i % 10 + '0';
		game->imgplayer[i - 1] = load_xpm(game, path);
	}
	free(path);
	path = ft_strdup("./res/enemy/enemy00.xpm");
	game->imgenemy = malloc(sizeof(t_player *) * (E_ANI));
	if (game->imgenemy == NULL)
		end(2, "Error: malloc failed");
	i = 0;
	while (++i <= E_ANI)
	{
		path[18] = i % 10 + '0';
		game->imgenemy[i - 1] = load_xpm(game, path);
	}
	free(path);
}

static void	load_exit(t_game *game)
{
	game->imgexit = malloc(sizeof(t_img *) * (2));
	if (game->imgexit == NULL)
		end(2, "Error: malloc failed");
	game->imgexit[EXIT_O] = load_xpm(game, EXIT_OPEN_SRC);
	game->imgexit[EXIT_C] = load_xpm(game, EXIT_CLOSED_SRC);
}

static void	load_env(t_game *game)
{
	game->imgenv = malloc(sizeof(t_player *) * (ENV_SRCS));
	if (game->imgenv == NULL)
		end(2, "Error: malloc failed");
	game->imgenv[ENV_FLOOR] = load_xpm(game, ENV_FLOOR_SRC);
	game->imgenv[ENV_L_T] = load_xpm(game, ENV_L_T_SRC);
	game->imgenv[ENV_L_L] = load_xpm(game, ENV_L_L_SRC);
	game->imgenv[ENV_L_R] = load_xpm(game, ENV_L_R_SRC);
	game->imgenv[ENV_L_B] = load_xpm(game, ENV_L_B_SRC);
	game->imgenv[ENV_C_TL] = load_xpm(game, ENV_C_TL_SRC);
	game->imgenv[ENV_C_TR] = load_xpm(game, ENV_C_TR_SRC);
	game->imgenv[ENV_C_BL] = load_xpm(game, ENV_C_BL_SRC);
	game->imgenv[ENV_C_BR] = load_xpm(game, ENV_C_BR_SRC);
	game->imgenv[ENV_WALL] = load_xpm(game, ENV_WALL_SRC);
}

void	load_imgs(t_game *game)
{
	printf("Loading player and enemies\n");
	load_players(game);
	printf("Loading coin\n");
	game->imgcoin = load_xpm(game, COIN_SRC);
	printf("Loading exit\n");
	load_exit(game);
	printf("Loading wall and floor\n");
	load_env(game);
}
