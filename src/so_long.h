/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:15:32 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/28 13:07:42 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define LINUX 1 // TODO debug

// C libraries
# ifdef LINUX
#  include "../mlx/mlx.h"
#  include "../mlx/mlx_int.h"
# else
#  include "../mlx_mac/mlx.h"
# endif

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