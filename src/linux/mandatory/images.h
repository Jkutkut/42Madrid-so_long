/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:34:24 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/31 15:40:06 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGES_H
# define IMAGES_H

# define PLAYER_SRC "./res/cat/cat01.xpm"

# ifndef COIN_SRC
#  define COIN_SRC "./res/env/C/key01.xpm"
# endif

# ifndef EXIT_CLOSED_SRC
#  define EXIT_CLOSED_SRC "./res/env/E/trapdoor02.xpm"
# endif

# ifndef EXIT_OPEN_SRC
#  define EXIT_OPEN_SRC "./res/env/E/stairs01.xpm"
# endif

# define EXIT_O 0
# define EXIT_C 1

# define ENV_SRCS 10
# define ENV_FLOOR 0
# define ENV_L_T 1
# define ENV_L_L 2
# define ENV_L_R 3
# define ENV_L_B 4
# define ENV_C_TL 5
# define ENV_C_TR 6
# define ENV_C_BL 7
# define ENV_C_BR 8
# define ENV_WALL 9

# define ENV_FLOOR_SRC "./res/env/0/floor.xpm"
# define ENV_L_T_SRC "./res/env/1/wall_line_top.xpm"
# define ENV_L_L_SRC "./res/env/1/wall_line_left.xpm"
# define ENV_L_R_SRC "./res/env/1/wall_line_right.xpm"
# define ENV_L_B_SRC "./res/env/1/wall_line_bot.xpm"
# define ENV_C_TL_SRC "./res/env/1/wall_corner_top_left.xpm"
# define ENV_C_TR_SRC "./res/env/1/wall_corner_top_right.xpm"
# define ENV_C_BL_SRC "./res/env/1/wall_corner_bot_left.xpm"
# define ENV_C_BR_SRC "./res/env/1/wall_corner_bot_right.xpm"
# define ENV_WALL_SRC "./res/env/1/wall.xpm"

#endif