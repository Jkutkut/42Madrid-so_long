/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 23:31:18 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/05 23:35:37 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end(int endtype, char *msg)
{
	if (endtype == 1)
	{
		ft_putstr_fd("Error: \n", 2);
		ft_putstr_fd(msg, 2);
	}
	else
		ft_putstr_fd(msg, 1);
	exit(0);
}