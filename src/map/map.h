/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:04:05 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/13 18:44:51 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include <fcntl.h>
#include <unistd.h>

#include "../so_long.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

void	check_map_filename(char *filename);
void	check_update_map(t_map *m);
t_map	*create_map(char **m);
int		endswith(char *str, char *end);
char	**load_map(char *filename);

#endif