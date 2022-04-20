/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:15:32 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/20 08:54:45 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// MLX
# include "../mlx/include/MLX42/MLX42.h"

# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

// Game constants
# define GAME_NAME "so_long Mandatory"
# define MAX_WIDTH 42
# define MAX_HEIGHT 20

// Libft
# include "../libft/libft.h"

// Declare and structures
# include "so_long_images.h"
# include "so_long_structs.h"
# include "so_long_msgs.h"

// Code
# include "game/game.h"
# include "game_control/game_control.h"
# include "game_UI/game_ui.h"
# include "map/map.h"
# include "tools/tools.h"

#endif
