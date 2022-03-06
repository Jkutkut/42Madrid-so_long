/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:28:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/06 12:42:45 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	**load_map(char *filename)
{
	int		fd;
	int		r;
	char	*line;
	int		**map;
	valid_map_filename(filename);
	fd = open(filename, "r");
	if (fd == -1)
		end(1, "Map file not found\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		free(line);
	}
}