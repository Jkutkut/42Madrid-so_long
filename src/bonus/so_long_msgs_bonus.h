/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_msgs_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:04:45 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/02 12:39:09 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MSGS_BONUS_H
# define SO_LONG_MSGS_BONUS_H

# define ERROR_INVALID_ARGS "Invalid number of arguments.\n"
# define ERROR_MALLOC "Malloc failed\n"
# define ERROR_MLX_INIT "Mlx init failed\n"

# define ERROR_LOADING_IMG_DETAIL "Error loading image: "
# define ERROR_LOADING_IMG "Error loading image.\n"

# define ERROR_NO_MAP "No map file specified.\n"
# define ERROR_MAP_NULL "Invalid map:\n  Map is null.\n"
# define ERROR_MAP_NOTFOUND "Map file not found.\n"
# define ERROR_MAP_EXTENSION "File should be a .ber file\n"
# define ERROR_MAP_BIG "The map is too big :S.\n"

# define ERROR_MULTIPLE_PLAYERS "Too many players.\n"
# define ERROR_MAP_EMPTY "Invalid map.\n  Map empty.\n"
# define ERROR_MAP_WIDTH "Invalid map:\n  Map width is not constant.\n"
# define ERROR_MAP_BORDER "Invalid map:\n  The map must have border.\n"
# define ERROR_MAP_CEP "Invalid map:\n  The map must contain CEP.\n"
# define ERROR_MAP_INVALID_CHAR "Invalid map:\n  Invalid charactes in map.\n"

# define MSG_ENDGAME "\n\nThanks for playing UwU.\n"
# define MSG_WIN "\n\nYou win!\n"
# define MSG_LOSE "\n\nYou lose!\n"

#endif