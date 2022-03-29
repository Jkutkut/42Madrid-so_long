/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:15:32 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/29 19:38:09 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define LINUX 1 // TODO debug

// C libraries
#  include "../mlx/mlx.h"
#  include "../mlx/mlx_int.h"
#  define GAME_NAME "so_long Linux"
#  define MAX_WIDTH 29
#  define MAX_HEIGHT 16

# include <stdio.h>
# include <stdlib.h>

// Declare and structures
# include "images.h"
# include "so_long_structs.h"
# include "so_long_msgs.h"

# include "libft/libft.h"
# include "game/game.h"
# include "game_control/game_control.h"
# include "game_UI/game_ui.h"
# include "map/map.h"
# include "tools/tools.h"

#endif