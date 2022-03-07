/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:28:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/07 12:05:22 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	**load_map(char *filename)
{
	int		fd;
	int		r;
	char	line[BUFFER_SIZE];
	char	*old_map;
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
		old_map = m;
		m = ft_strjoin(m, line);
		free(old_map);
	}
	if (m == NULL)
		end(1, "Map file is empty\n");
	printf("----\n%s\n", m);
	close(fd);
	old_map = m;
	map = ft_split(old_map, '\n');
	free(old_map);
	return (map);
}