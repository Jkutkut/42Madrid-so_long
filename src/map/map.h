/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:04:05 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/20 19:56:24 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include <unistd.h>

# include "../so_long.h"

# ifndef BONUS
#  define REQUIRED_ELEMENTS "CEP"
#  define BONUS 0
# else
#  define REQUIRED_ELEMENTS "CEPF"
# endif

# define BUFFER_SIZE 1024

void	check_map_filename(char *filename);
void	check_update_map(t_map *m);
void	check_valid_line(char *line);
int		count_coins(t_map *map);
t_map	*create_map(char **m);
int		endswith(char *str, char *end);
char	**load_map(char *filename);
int		map_contains(t_map *m, char c);

#endif
