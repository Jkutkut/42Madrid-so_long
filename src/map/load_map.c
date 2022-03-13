/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:28:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/13 20:17:26 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/**
 * @brief Reads the map file and returns a 2D array of chars. If file is
 * invalid, exits the program.
 * 
 * @param filename 
 * @return char** 
 */
char	**load_map(char *filename)
{
	int		fd;
	int		r;
	char	line[BUFFER_SIZE];
	char	*m;
	char	**map;

	check_map_filename(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		end(1, "Map file not found\n");
	m = NULL;
	while (1)
	{
		r = read(fd, &line, BUFFER_SIZE);
		if (r == 0)
			break ;
		ft_strextend(&m, line);
	}
	if (m == NULL)
		end(1, "Map file is empty\n");
	close(fd);
	map = ft_split(m, '\n');
	free(m);
	return (map);
}
