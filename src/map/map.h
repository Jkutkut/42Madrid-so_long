/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:04:05 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/20 21:28:44 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include <unistd.h>

# include "../so_long.h"

#  define REQUIRED_ELEMENTS "CEP"

# ifndef BONUS
#  define BONUS 0
#  define ALL_ELEMENTS "10CEPF"
# else
#  define ALL_ELEMENTS "10CEP"
# endif

# define BUFFER_SIZE 1024

void	check_map_filename(char *filename);
void	check_unique_player(t_map *m);
void	check_update_map(t_map *m);
void	check_valid_line(char *line);
int		count_coins(t_map *map);
t_map	*create_map(char **m);
int		endswith(char *str, char *end);
char	**load_map(char *filename);
int		map_contains(t_map *m, char c);

#endif
