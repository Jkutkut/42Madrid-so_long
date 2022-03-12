/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:04:05 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/12 13:20:26 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
}  				t_map;

#include "../libft/libft.h"
#include "../tools/tools.h"
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

void	check_map_filename(char *filename);
void	check_update_map(t_map *m);
t_map	*create_map(char **m);
int		endswith(char *str, char *end);
char	**load_map(char *filename);

#endif