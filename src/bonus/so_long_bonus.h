/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:15:32 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 19:09:49 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// MLX
# include "../mlx/include/MLX42/MLX42.h"

# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

// Game constants
# define GAME_NAME "so_long Bonus"
# define MAX_WIDTH 42
# define MAX_HEIGHT 20

// Libft
# include "../libft/libft.h"

// Declare and structures
# include "so_long_images_bonus.h"
# include "so_long_structs_bonus.h"
# include "so_long_msgs_bonus.h"

// Code
# include "game/game_bonus.h"
# include "game_control/game_control_bonus.h"
# include "game_UI/game_ui_bonus.h"
# include "map/map_bonus.h"
# include "tools/tools_bonus.h"

#endif
