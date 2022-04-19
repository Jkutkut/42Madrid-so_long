/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cooldown_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:07:23 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 20:10:28 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control_bonus.h"

/**
 * @brief Handles time to wait between 'frames'.
 * 
 * @param reset if reset != 0, reset the time.
 * @return int If the time is up, 1. Else, 0.
 */
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
