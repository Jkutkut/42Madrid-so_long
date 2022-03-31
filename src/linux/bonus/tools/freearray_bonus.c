/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freearray_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:54:46 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/31 15:15:22 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools_bonus.h"

/**
 * @brief Frees the given array.
 * 
 * @param array Array to free.
 */
void	freearray(char **array)
{
	int		i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
