/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:25:51 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 19:14:05 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui_bonus.h"

/**
 * @brief Load the given image into the game.
 * 
 * @param game Game to load the image into.
 * @param path Path of the img file.
 * @return mlx_image_t* Object containing the image.
 */
static mlx_image_t	*load_png(t_game *game, char *path)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_putstr_fd(ERROR_LOADING_IMG_DETAIL, 2);
		ft_putendl_fd(path, 2);
		freeend(1, ERROR_LOADING_IMG, game);
	}
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (!img)
	{
		ft_putstr_fd(ERROR_LOADING_IMG_DETAIL, 2);
		ft_putendl_fd(path, 2);
		freeend(1, ERROR_LOADING_IMG, game);
	}
	return (img);
}

/**
 * @brief Load all player and enemy sprites.
 * 
 * @param game Game to load the images into.
 */
static void	load_players(t_game *game)
{
	char	path[24];
	int		i;

	ft_memcpy(path, PLAYER_SRC_BASE, ft_strlen(PLAYER_SRC_BASE) + 1);
	i = 0;
	while (++i <= P_ANI)
	{
		path[ft_strlen(PLAYER_SRC_BASE) - ft_strlen(IMG_IND)] = i % 10 + '0';
		game->imgplayer[i - 1] = load_png(game, path);
	}
	ft_memcpy(path, ENEMY_SRC_BASE, ft_strlen(ENEMY_SRC_BASE) + 1);
	i = 0;
	while (++i <= E_ANI)
	{
		path[ft_strlen(ENEMY_SRC_BASE) - ft_strlen(IMG_IND)] = i % 10 + '0';
		game->imgenemy[i - 1] = load_png(game, path);
	}
}

/**
 * @brief Load the sprites representing the exit.
 * 
 * @param game
 */
static void	load_exit(t_game *game)
{
	game->imgexit[EXIT_O] = load_png(game, EXIT_OPEN_SRC);
	game->imgexit[EXIT_C] = load_png(game, EXIT_CLOSED_SRC);
}

/**
 * @brief Load all sprites related to enviroment.
 * This is elements like walls and floors.
 * 
 * @param game 
 */
static void	load_env(t_game *game)
{
	game->imgenv[ENV_FLOOR] = load_png(game, ENV_FLOOR_SRC);
	game->imgenv[ENV_L_T] = load_png(game, ENV_L_T_SRC);
	game->imgenv[ENV_L_L] = load_png(game, ENV_L_L_SRC);
	game->imgenv[ENV_L_R] = load_png(game, ENV_L_R_SRC);
	game->imgenv[ENV_L_B] = load_png(game, ENV_L_B_SRC);
	game->imgenv[ENV_C_TL] = load_png(game, ENV_C_TL_SRC);
	game->imgenv[ENV_C_TR] = load_png(game, ENV_C_TR_SRC);
	game->imgenv[ENV_C_BL] = load_png(game, ENV_C_BL_SRC);
	game->imgenv[ENV_C_BR] = load_png(game, ENV_C_BR_SRC);
	game->imgenv[ENV_WALL] = load_png(game, ENV_WALL_SRC);
}

/**
 * @brief Load all the required images into the game.
 * 
 * @param game Game to load the images into.
 */
void	load_imgs(t_game *game)
{
	load_players(game);
	game->imgcoin = load_png(game, COIN_SRC);
	load_env(game);
	load_exit(game);
}
