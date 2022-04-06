/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:21:27 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/06 15:37:31 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *source, size_t n);

void	*ft_realloc(void *p, size_t newSize)
{
	void *new_p;

	if (!p)
		return malloc(newSize);
	new_p = malloc(newSize);
	if (new_p)
		ft_memmove(new_p, p, newSize);
	free(p);
	return(new_p);
}