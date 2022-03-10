/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:56:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/10 11:14:33 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

#include <stdlib.h>

void	freearray(char **array);
void	end(int endtype, char *msg);
void	ft_strextend(char **s1, char *s2);

#endif
