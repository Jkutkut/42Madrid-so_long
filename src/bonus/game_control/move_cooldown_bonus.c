/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cooldown_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:07:23 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/11 12:20:23 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control_bonus.h"

int	move_cooldown(int reset)
{
	static unsigned int	cooldown = 0;

	if (reset)
		cooldown = 0;
	else if (cooldown == 0)
	{
		cooldown = 9;
		return (1);
	}
	else
		cooldown--;
	return (0);
}