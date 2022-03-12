/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:56:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/12 19:07:13 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

#include "../map/map.h"
#include "../libft/libft.h"

#include <stdlib.h>

void	end(int endtype, char *msg);
void	freearray(char **array);
void	freemap(t_map *m);
void	ft_strextend(char **s1, char *s2);
void	print_map(t_map *m);

#endif
