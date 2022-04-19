/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:04:05 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 19:10:04 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include "../so_long_bonus.h"

# define REQUIRED_ELEMENTS "CEP"

# define ALL_ELEMENTS "10CEPF"

# define BUFFER_SIZE 1024

void	check_map_filename(char *filename);
void	check_unique_player(t_map *m);
void	check_update_map(t_map *m);
void	check_valid_line(char *line);
int		count_coins(t_map *map);
t_map	*create_map(char **m);
int		endswith(char *str, char *end);
char	**load_map(char *filename);
int		map_contains(t_map *m, char *str);

#endif
